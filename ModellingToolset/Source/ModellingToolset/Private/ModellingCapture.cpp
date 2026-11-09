// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingCapture.h"

#include "ModellingJob.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingToolsetSettings.h"
#include "ModellingToolsetUtils.h"

#include "Components/DirectionalLightComponent.h"
#include "ContentStreaming.h"
#include "Engine/Texture.h"
#include "Components/DynamicMeshComponent.h"
#include "Components/LightComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "DynamicMeshActor.h"
#include "Engine/DirectionalLight.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "EngineUtils.h"
#include "HAL/FileManager.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "Math/RotationMatrix.h"
#include "Misc/DateTime.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "RenderingThread.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "ShaderCompiler.h"
#include "TextureCompiler.h"
#include "TextureResource.h"
#include "UObject/StrongObjectPtr.h"
#include "UObject/UObjectIterator.h"

namespace ModellingToolset
{
	namespace
	{
		FString GSessionId;
		int32 GStep = 0;

		struct FViewDef
		{
			FVector Direction;   // from the subject towards the camera
			bool bAxisAligned;   // axis views are orthographic by default
		};

		bool FindView(const FString& Name, FViewDef& Out)
		{
			static const TMap<FString, FViewDef> Views = {
				{ TEXT("iso"),      { FVector(1, 1, 0.7).GetSafeNormal(),   false } },
				{ TEXT("iso_back"), { FVector(-1, -1, 0.7).GetSafeNormal(), false } },
				{ TEXT("front"),    { FVector(1, 0, 0),                     true  } },
				{ TEXT("back"),     { FVector(-1, 0, 0),                    true  } },
				{ TEXT("right"),    { FVector(0, 1, 0),                     true  } },
				{ TEXT("left"),     { FVector(0, -1, 0),                    true  } },
				{ TEXT("top"),      { FVector(0, 0, 1),                     true  } },
				{ TEXT("bottom"),   { FVector(0, 0, -1),                    true  } },
			};
			if (const FViewDef* Found = Views.Find(Name))
			{
				Out = *Found;
				return true;
			}
			return false;
		}

		FString GetSessionDir()
		{
			if (GSessionId.IsEmpty())
			{
				GSessionId = FDateTime::Now().ToString(TEXT("%Y%m%d_%H%M%S"));
			}
			return GetProgressDir() / GSessionId;
		}

		void SplitCsv(const FString& In, TArray<FString>& Out)
		{
			In.ParseIntoArray(Out, TEXT(","), /*CullEmpty=*/true);
			for (FString& S : Out)
			{
				S.TrimStartAndEndInline();
			}
		}

		FCaptureResult Error(const FString& Message)
		{
			FCaptureResult R;
			R.Error = Message;
			return R;
		}

		FString ToCondensedJson(const TSharedRef<FJsonObject>& Object)
		{
			FString Out;
			const TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer =
				TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&Out);
			FJsonSerializer::Serialize(Object, Writer);
			return Out;
		}

		enum class ECaptureMode { Lit, Unlit, Clay, Normals, Silhouette };

		/** Blocks until every material on the captured parts has its shaders ready, so none renders as the checker fallback. */
		void EnsureMaterialsReady(const TArray<AActor*>& Targets, UMaterialInterface* Extra)
		{
			TArray<UMaterialInterface*> Materials;
			if (Extra) { Materials.Add(Extra); }
			for (AActor* Actor : Targets)
			{
				ADynamicMeshActor* MeshActor = Cast<ADynamicMeshActor>(Actor);
				UDynamicMeshComponent* Component = MeshActor ? MeshActor->GetDynamicMeshComponent() : nullptr;
				if (!Component) { continue; }
				for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
				{
					if (UMaterialInterface* M = Component->GetMaterial(i)) { Materials.AddUnique(M); }
				}
			}
			TArray<UTexture*> Textures;
			for (UMaterialInterface* M : Materials)
			{
				M->EnsureIsComplete();
				TArray<UTexture*> Used;
				M->GetUsedTextures(Used);
				for (UTexture* T : Used) { if (T) { Textures.AddUnique(T); } }
			}
			// Newly loaded textures build their GPU data in the background and show a tiny placeholder until then.
			if (!Textures.IsEmpty())
			{
				FTextureCompilingManager::Get().FinishCompilation(Textures);
			}
			if (GShaderCompilingManager)
			{
				GShaderCompilingManager->FinishAllCompilation();
				GShaderCompilingManager->ProcessAsyncResults(/*bLimitExecutionTime=*/false, /*bBlockOnGlobalShaderCompletion=*/true);
			}
			// Large textures stream in over several frames; a one-shot capture would otherwise see them blurred to a flat colour.
			for (UTexture* T : Textures)
			{
				T->SetForceMipLevelsToBeResident(30.f);
			}
			IStreamingManager::Get().StreamAllResources(0.f);
			for (UTexture* T : Textures)
			{
				T->WaitForStreaming();
			}
			FlushRenderingCommands();
		}

		/**
		 * Temporarily hides every light in the level and lights the model with a fixed three-light rig, so a capture looks
		 * the same in any level and the exposure can be fixed. Everything is restored when this goes out of scope.
		 */
		struct FCaptureLighting
		{
			UWorld* World = nullptr;
			TArray<TPair<TWeakObjectPtr<ULightComponent>, bool>> Hidden;
			TArray<ADirectionalLight*> Rig;

			void Apply(UWorld* InWorld, const FActorSpawnParameters& SpawnParams)
			{
				World = InWorld;
				for (TObjectIterator<ULightComponent> It; It; ++It)
				{
					ULightComponent* Light = *It;
					if (Light->GetWorld() == World && Light->IsRegistered() && Light->GetVisibleFlag())
					{
						Hidden.Add({ Light, true });
						Light->SetVisibility(false);
					}
				}
				// Four lights, given as the direction the light travels, so every standard view (front +X, right +Y, top +Z,
				// and the backs) gets some light. Key: from the front-right and above, with shadows. Intensities in lux, matched to the exposure.
				struct FLightSetup { FVector Travel; float Intensity; bool bShadows; };
				const FLightSetup Setup[] = {
					{ FVector(-0.50, -0.50, -0.70), 8.f, true },   // key: lights the +X, +Y and top faces, casts shadows
					{ FVector(-0.90, 0.30, -0.30), 5.f, false },   // lights +X and -Y faces
					{ FVector(0.30, -0.90, -0.30), 5.f, false },   // lights -X and +Y faces
					{ FVector(0.80, 0.50, -0.40), 4.f, false },    // lights the -X and -Y faces (the backs)
					{ FVector(0.00, 0.00, 1.00), 3.f, false } };   // from below, for the bottom view
				for (const FLightSetup& S : Setup)
				{
					const FRotator Rotation = FRotationMatrix::MakeFromX(S.Travel.GetSafeNormal()).Rotator();
					if (ADirectionalLight* Light = World->SpawnActor<ADirectionalLight>(FVector::ZeroVector, Rotation, SpawnParams))
					{
						if (ULightComponent* Component = Light->GetLightComponent())
						{
							Component->SetMobility(EComponentMobility::Movable);
							Component->SetIntensity(S.Intensity);
							Component->SetCastShadows(S.bShadows);
						}
						Rig.Add(Light);
					}
				}
			}

			~FCaptureLighting()
			{
				for (ADirectionalLight* Light : Rig)
				{
					if (World) { World->DestroyActor(Light); }
				}
				for (const TPair<TWeakObjectPtr<ULightComponent>, bool>& Pair : Hidden)
				{
					if (Pair.Key.IsValid()) { Pair.Key->SetVisibility(Pair.Value); }
				}
			}
		};

		/**
		 * Lit translucent materials (window glass) render black or vanish inside an off-screen capture, because they depend on
		 * scene lighting data the capture does not have. For the picture only, each translucent slot is swapped for the plugin's
		 * unlit glass with the same colour and opacity, then put back.
		 */
		struct FGlassOverride
		{
			TArray<TPair<UDynamicMeshComponent*, TArray<UMaterialInterface*>>> Saved;
			TArray<TStrongObjectPtr<UMaterialInstanceDynamic>> Keep;

			void Apply(const TArray<AActor*>& Targets)
			{
				for (AActor* Actor : Targets)
				{
					ADynamicMeshActor* MeshActor = Cast<ADynamicMeshActor>(Actor);
					UDynamicMeshComponent* Component = MeshActor ? MeshActor->GetDynamicMeshComponent() : nullptr;
					if (!Component) { continue; }
					TArray<UMaterialInterface*> Original, Replaced;
					bool bAny = false;
					for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
					{
						UMaterialInterface* M = Component->GetMaterial(i);
						Original.Add(M);
						UMaterialInterface* Use = M;
						if (M && IsTranslucentBlendMode(M->GetBlendMode()) && !M->GetMaterial()->GetName().StartsWith(TEXT("M_ModellingGlass")))
						{
							FString Error;
							if (UMaterial* Own = UModellingMaterialsToolset::GetGlassMaterial(Error))
							{
								UMaterialInstanceDynamic* Mid = UMaterialInstanceDynamic::Create(Own, GetTransientPackage());
								FLinearColor Colour = FLinearColor::White;
								float Opacity = 0.15f;
								if (!M->GetVectorParameterValue(FHashedMaterialParameterInfo(TEXT("Glass Color")), Colour)) { M->GetVectorParameterValue(FHashedMaterialParameterInfo(TEXT("Color")), Colour); }
								if (!M->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("Base Opacity")), Opacity)) { M->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("Opacity")), Opacity); }
								Mid->SetVectorParameterValue(TEXT("Color"), Colour);
								Mid->SetScalarParameterValue(TEXT("Opacity"), FMath::Clamp(Opacity, 0.05f, 1.f));
								Keep.Add(TStrongObjectPtr<UMaterialInstanceDynamic>(Mid));
								Use = Mid;
								bAny = true;
							}
						}
						Replaced.Add(Use);
					}
					if (bAny)
					{
						Saved.Add({ Component, Original });
						Component->ConfigureMaterialSet(Replaced);
					}
				}
			}

			~FGlassOverride()
			{
				for (TPair<UDynamicMeshComponent*, TArray<UMaterialInterface*>>& Pair : Saved)
				{
					if (IsValid(Pair.Key)) { Pair.Key->ConfigureMaterialSet(Pair.Value); }
				}
			}
		};

		/** Swaps every slot of the captured parts for one plain material (grey clay, or pure white for silhouettes), and puts the originals back afterwards. */
		struct FClayOverride
		{
			TArray<TPair<UDynamicMeshComponent*, TArray<UMaterialInterface*>>> Saved;
			TStrongObjectPtr<UMaterialInstanceDynamic> Clay;

			bool Apply(const TArray<AActor*>& Targets, const FLinearColor& Colour, FString& OutError)
			{
				UMaterial* Base = UModellingMaterialsToolset::GetBaseMaterial(OutError);
				if (!Base)
				{
					return false;
				}
				Clay.Reset(UMaterialInstanceDynamic::Create(Base, GetTransientPackage()));
				Clay->SetVectorParameterValue(TEXT("Color"), Colour);
				Clay->SetScalarParameterValue(TEXT("Roughness"), 0.85f);
				Clay->SetScalarParameterValue(TEXT("Metallic"), 0.f);
				for (AActor* Actor : Targets)
				{
					ADynamicMeshActor* MeshActor = Cast<ADynamicMeshActor>(Actor);
					UDynamicMeshComponent* Component = MeshActor ? MeshActor->GetDynamicMeshComponent() : nullptr;
					if (!Component) { continue; }
					TArray<UMaterialInterface*> Original;
					for (int32 i = 0; i < Component->GetNumMaterials(); ++i) { Original.Add(Component->GetMaterial(i)); }
					Saved.Add({ Component, Original });
					TArray<UMaterialInterface*> All;
					All.Init(Clay.Get(), FMath::Max(1, Original.Num()));
					Component->ConfigureMaterialSet(All);
				}
				return true;
			}

			~FClayOverride()
			{
				for (TPair<UDynamicMeshComponent*, TArray<UMaterialInterface*>>& Pair : Saved)
				{
					if (IsValid(Pair.Key)) { Pair.Key->ConfigureMaterialSet(Pair.Value); }
				}
			}
		};
	}

	FString StartCaptureSession(const FString& Name)
	{
		EnsureWorkspaceFolders();
		GSessionId = FDateTime::Now().ToString(TEXT("%Y%m%d_%H%M%S"));
		if (!Name.TrimStartAndEnd().IsEmpty())
		{
			GSessionId += TEXT("_") + SanitizeFileName(Name);
		}
		GStep = 0;
		const FString Dir = GetProgressDir() / GSessionId;
		IFileManager::Get().MakeDirectory(*Dir, /*Tree=*/true);
		return Dir;
	}

	FCaptureResult CaptureViews(const FCaptureRequest& Request)
	{
		const UModellingToolsetSettings* Settings = GetDefault<UModellingToolsetSettings>();

		UWorld* World = GetEditorWorld();
		if (!World)
		{
			return Error(TEXT("No editor world is available."));
		}
		if (!FApp::CanEverRender())
		{
			return Error(TEXT("This editor cannot render pictures (it is running without graphics)."));
		}

		// 1. Resolve what to frame.
		TArray<AActor*> Targets;
		if (!Request.ExplicitTargets.IsEmpty())
		{
			Targets = Request.ExplicitTargets;
		}
		else if (Request.ActorNames.TrimStartAndEnd().IsEmpty())
		{
			for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
			{
				if (It->Tags.Contains(ActorTag))
				{
					Targets.Add(*It);
				}
			}
		}
		else
		{
			TArray<FString> Names;
			SplitCsv(Request.ActorNames, Names);
			for (const FString& N : Names)
			{
				ADynamicMeshActor* Actor = FindMeshActor(N);
				if (!Actor)
				{
					return Error(FString::Printf(TEXT("No mesh actor named '%s'."), *N));
				}
				Targets.Add(Actor);
			}
		}
		if (Targets.IsEmpty())
		{
			return Error(TEXT("Nothing to capture: no model actors exist yet. Create geometry first."));
		}

		FBox Bounds(ForceInit);
		for (AActor* Actor : Targets)
		{
			Bounds += Actor->GetComponentsBoundingBox(/*bNonColliding=*/true);
		}
		if (!Bounds.IsValid || Bounds.GetSize().IsNearlyZero())
		{
			return Error(TEXT("The actors have no geometry yet, so there is nothing to frame."));
		}
		const FVector Center = Bounds.GetCenter();
		const double Radius = FMath::Max(Bounds.GetExtent().Size(), 1.0);

		// 2. Resolve views and options.
		TArray<FString> ViewNames;
		SplitCsv(Request.Views.IsEmpty() ? TEXT("iso,front,right,top") : Request.Views, ViewNames);
		if (ViewNames.IsEmpty() || ViewNames.Num() > 12)
		{
			return Error(TEXT("Provide between 1 and 12 view names."));
		}
		TArray<FViewDef> ViewDefs;
		for (FString& V : ViewNames)
		{
			V = V.ToLower();
			FViewDef Def;
			if (!FindView(V, Def))
			{
				return Error(FString::Printf(TEXT("Unknown view '%s'. Valid: iso, iso_back, front, back, right, left, top, bottom."), *V));
			}
			ViewDefs.Add(Def);
		}

		const FString Mode = Request.ViewMode.IsEmpty() ? FString(TEXT("lit")) : Request.ViewMode.ToLower();
		ECaptureMode CaptureMode = ECaptureMode::Lit;
		if (Mode == TEXT("unlit")) { CaptureMode = ECaptureMode::Unlit; }
		else if (Mode == TEXT("clay")) { CaptureMode = ECaptureMode::Clay; }
		else if (Mode == TEXT("normals")) { CaptureMode = ECaptureMode::Normals; }
		else if (Mode == TEXT("silhouette")) { CaptureMode = ECaptureMode::Silhouette; }
		else if (Mode != TEXT("lit"))
		{
			return Error(TEXT("ViewMode must be 'lit', 'unlit', 'clay' or 'normals'."));
		}

		const int32 Res = FMath::Clamp(Request.Resolution > 0 ? Request.Resolution : Settings->DefaultCaptureResolution, 128, 2048);

		// 4. Off-screen capture rig. Everything spawned here is transient and removed on exit.
		TStrongObjectPtr<UTextureRenderTarget2D> RenderTarget(NewObject<UTextureRenderTarget2D>(GetTransientPackage()));
		RenderTarget->RenderTargetFormat = RTF_RGBA8;
		RenderTarget->ClearColor = FLinearColor(0.10f, 0.10f, 0.12f, 1.f);
		RenderTarget->bAutoGenerateMips = false;
		RenderTarget->InitAutoFormat(Res, Res);
		RenderTarget->UpdateResourceImmediate(true);

		FActorSpawnParameters SpawnParams;
		SpawnParams.ObjectFlags = RF_Transient;
		SpawnParams.bTemporaryEditorActor = true;

		ASceneCapture2D* CaptureActor = World->SpawnActor<ASceneCapture2D>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		USceneCaptureComponent2D* Capture = CaptureActor ? CaptureActor->GetCaptureComponent2D() : nullptr;
		if (!Capture)
		{
			if (CaptureActor) { World->DestroyActor(CaptureActor); }
			return Error(TEXT("Could not create the scene capture."));
		}
		ON_SCOPE_EXIT
		{
			World->DestroyActor(CaptureActor);
		};

		// Our own lights and a fixed exposure, so pictures are consistent between steps and between levels.
		FCaptureLighting Lighting;
		Lighting.Apply(World, SpawnParams);

		FGlassOverride GlassOverride;
		if (CaptureMode == ECaptureMode::Lit || CaptureMode == ECaptureMode::Unlit)
		{
			GlassOverride.Apply(Targets);
		}

		FClayOverride ClayOverride;
		if (CaptureMode == ECaptureMode::Clay || CaptureMode == ECaptureMode::Silhouette)
		{
			FString ClayError;
			const FLinearColor Colour = CaptureMode == ECaptureMode::Clay ? FLinearColor(0.42f, 0.42f, 0.42f) : FLinearColor::White;
			if (!ClayOverride.Apply(Targets, Colour, ClayError))
			{
				return Error(ClayError);
			}
		}

		// 3. Make sure every material is compiled, or parts render as the checker fallback (or black) in the first pictures.
		EnsureMaterialsReady(Targets, ClayOverride.Clay.Get());

		Capture->bCaptureEveryFrame = false;
		Capture->bCaptureOnMovement = false;
		Capture->TextureTarget = RenderTarget.Get();
		Capture->FOVAngle = 45.f;
		Capture->bAlwaysPersistRenderingState = true;
		switch (CaptureMode)
		{
		case ECaptureMode::Unlit:      Capture->CaptureSource = SCS_BaseColor; break;   // the material colour, no lighting at all
		case ECaptureMode::Silhouette: Capture->CaptureSource = SCS_BaseColor; break;   // white parts on black, for outline comparison
		case ECaptureMode::Normals:    Capture->CaptureSource = SCS_Normal; break;      // surface direction as colour
		default:                    Capture->CaptureSource = SCS_FinalColorLDR; break;
		}

		// Manual exposure: a fixed EV, no auto-adaptation, no bloom or blur. Tuned so a light colour under the key light reads light.
		FPostProcessSettings& PP = Capture->PostProcessSettings;
		Capture->PostProcessBlendWeight = 1.f;
		PP.bOverride_AutoExposureMethod = true;
		PP.AutoExposureMethod = AEM_Manual;
		PP.bOverride_AutoExposureApplyPhysicalCameraExposure = true;
		PP.AutoExposureApplyPhysicalCameraExposure = false;
		PP.bOverride_AutoExposureBias = true;
		PP.AutoExposureBias = Settings->CaptureExposure;
		PP.bOverride_BloomIntensity = true;
		PP.BloomIntensity = 0.f;
		PP.bOverride_MotionBlurAmount = true;
		PP.MotionBlurAmount = 0.f;
		PP.bOverride_VignetteIntensity = true;
		PP.VignetteIntensity = 0.f;
		PP.bOverride_LocalExposureHighlightContrastScale = true;
		PP.LocalExposureHighlightContrastScale = 1.f;
		PP.bOverride_LocalExposureShadowContrastScale = true;
		PP.LocalExposureShadowContrastScale = 1.f;

		if (Request.bIsolate)
		{
			Capture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
			for (AActor* Actor : Targets)
			{
				Capture->ShowOnlyActorComponents(Actor);
			}
		}

		const double PerspectiveDistance = Radius / FMath::Sin(FMath::DegreesToRadians(Capture->FOVAngle * 0.5)) * 1.1;
		const double OrthoDistance = Radius * 3.0;

		// 5. Render each view.
		TArray<TArray<FColor>> Tiles;
		for (const FViewDef& Def : ViewDefs)
		{
			const bool bOrtho = Def.bAxisAligned && !Request.bForcePerspective;
			Capture->ProjectionType = bOrtho ? ECameraProjectionMode::Orthographic : ECameraProjectionMode::Perspective;
			Capture->OrthoWidth = static_cast<float>(Radius * 2.0 * 1.15);

			const double Distance = bOrtho ? OrthoDistance : PerspectiveDistance;
			CaptureActor->SetActorLocationAndRotation(Center + Def.Direction * Distance, (-Def.Direction).Rotation());
			Capture->CaptureScene();
			FlushRenderingCommands();

			FTextureRenderTargetResource* Resource = RenderTarget->GameThread_GetRenderTargetResource();
			TArray<FColor> Pixels;
			if (!Resource || !Resource->ReadPixels(Pixels) || Pixels.Num() != Res * Res)
			{
				return Error(TEXT("Failed to read back the captured image."));
			}
			for (FColor& P : Pixels)
			{
				if (CaptureMode == ECaptureMode::Unlit)
				{
					// The base-colour capture is linear; convert so the picture's colours match the hex values that were painted.
					P = FLinearColor(P.R / 255.f, P.G / 255.f, P.B / 255.f).ToFColor(/*bSRGB=*/true);
				}
				P.A = 255;
			}
			Tiles.Add(MoveTemp(Pixels));
		}

		// 6. Save the individual views at full tile size.
		++GStep;
		EnsureWorkspaceFolders();
		const FString SessionDir = GetSessionDir();
		IFileManager::Get().MakeDirectory(*SessionDir, /*Tree=*/true);
		const FString Tag = Request.Label.IsEmpty() ? FString() : TEXT("_") + SanitizeFileName(Request.Label);

		TArray<TSharedPtr<FJsonValue>> SavedFiles;
		for (int32 i = 0; i < Tiles.Num(); ++i)
		{
			const FString File = SessionDir / FString::Printf(TEXT("step_%03d%s_%s.png"), GStep, *Tag, *ViewNames[i]);
			if (SavePng(File, Tiles[i], FIntPoint(Res, Res)))
			{
				SavedFiles.Add(MakeShared<FJsonValueString>(File));
			}
		}

		// 7. Tile into a contact sheet, capped so the returned payload stays small.
		const int32 Cols = FMath::CeilToInt(FMath::Sqrt(static_cast<float>(Tiles.Num())));
		const int32 Rows = FMath::DivideAndRoundUp(Tiles.Num(), Cols);
		const FIntPoint FullSheetSize(Cols * Res, Rows * Res);
		TArray<FColor> FullSheet;
		FullSheet.Init(FColor(26, 26, 31, 255), FullSheetSize.X * FullSheetSize.Y);
		for (int32 i = 0; i < Tiles.Num(); ++i)
		{
			const int32 OriginX = (i % Cols) * Res;
			const int32 OriginY = (i / Cols) * Res;
			for (int32 Y = 0; Y < Res; ++Y)
			{
				FMemory::Memcpy(&FullSheet[(OriginY + Y) * FullSheetSize.X + OriginX], &Tiles[i][Y * Res], Res * sizeof(FColor));
			}
		}

		FCaptureResult Result;
		const int32 MaxDim = Settings->MaxReturnedImageDimension;
		if (FMath::Max(FullSheetSize.X, FullSheetSize.Y) > MaxDim)
		{
			const float Scale = static_cast<float>(MaxDim) / FMath::Max(FullSheetSize.X, FullSheetSize.Y);
			Result.SheetSize = FIntPoint(FMath::Max(1, FMath::RoundToInt(FullSheetSize.X * Scale)), FMath::Max(1, FMath::RoundToInt(FullSheetSize.Y * Scale)));
			ResizeImage(FullSheet, FullSheetSize, Result.SheetSize, Result.Sheet);
		}
		else
		{
			Result.SheetSize = FullSheetSize;
			Result.Sheet = MoveTemp(FullSheet);
		}

		const FString SheetFile = SessionDir / FString::Printf(TEXT("step_%03d%s_sheet.png"), GStep, *Tag);
		if (SavePng(SheetFile, Result.Sheet, Result.SheetSize))
		{
			SavedFiles.Add(MakeShared<FJsonValueString>(SheetFile));
			if (Request.bSetReviewImage)
			{
				GetJob().LastSheetFile = SheetFile; // shown in the review panel
			}
		}

		// 8. Summary, plus an append-only one-line-per-step log.
		TArray<TSharedPtr<FJsonValue>> ViewList;
		for (const FString& V : ViewNames)
		{
			ViewList.Add(MakeShared<FJsonValueString>(V));
		}
		TSharedRef<FJsonObject> Summary = MakeShared<FJsonObject>();
		Summary->SetNumberField(TEXT("step"), GStep);
		Summary->SetStringField(TEXT("session_folder"), SessionDir);
		Summary->SetStringField(TEXT("label"), Request.Label);
		Summary->SetStringField(TEXT("view_mode"), Mode);
		Summary->SetArrayField(TEXT("views_in_sheet_order"), ViewList);
		Summary->SetNumberField(TEXT("tile_px"), Res);
		Summary->SetNumberField(TEXT("sheet_columns"), Cols);
		Summary->SetNumberField(TEXT("returned_width"), Result.SheetSize.X);
		Summary->SetNumberField(TEXT("returned_height"), Result.SheetSize.Y);
		Summary->SetNumberField(TEXT("framed_radius_cm"), Radius);
		Summary->SetArrayField(TEXT("saved_files"), SavedFiles);
		Result.SummaryJson = ToCondensedJson(Summary);

		FFileHelper::SaveStringToFile(
			Result.SummaryJson + LINE_TERMINATOR,
			*(SessionDir / TEXT("log.jsonl")),
			FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM,
			&IFileManager::Get(),
			FILEWRITE_Append);

		Result.bOk = true;
		return Result;
	}
}
