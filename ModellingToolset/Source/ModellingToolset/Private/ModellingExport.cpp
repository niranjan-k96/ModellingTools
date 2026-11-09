// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingExport.h"

#include "ModellingTextureToolset.h"
#include "ModellingToolsetUtils.h"

#include "AssetExportTask.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/DynamicMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMesh/DynamicMeshAttributeSet.h"
#include "DynamicMeshActor.h"
#include "Engine/StaticMesh.h"
#include "EngineUtils.h"
#include "Exporters/Exporter.h"
#include "FileHelpers.h"
#include "GeometryScript/CollisionFunctions.h"
#include "GeometryScript/MeshAssetFunctions.h"
#include "GeometryScript/MeshBasicEditFunctions.h"
#include "GeometryScript/MeshTransformFunctions.h"
#include "HAL/FileManager.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "PhysicsEngine/BodySetup.h"
#include "UDynamicMesh.h"
#include "UObject/Package.h"
#include "UObject/StrongObjectPtr.h"

namespace ModellingToolset
{
	bool ParseGameAssetPath(const FString& In, FString& OutPackage, FString& OutAsset, FString& OutError)
	{
		FString Path = In.TrimStartAndEnd();
		int32 DotIndex;
		if (Path.FindChar(TEXT('.'), DotIndex))
		{
			Path.LeftInline(DotIndex);
		}
		if (!Path.StartsWith(TEXT("/Game/")) || Path.Contains(TEXT("..")))
		{
			OutError = TEXT("AssetPath must start with /Game/ and must not contain '..', e.g. /Game/Models/Lighthouse.");
			return false;
		}
		FText Reason;
		if (!FPackageName::IsValidLongPackageName(Path, /*bIncludeReadOnlyRoots=*/false, &Reason))
		{
			OutError = FString::Printf(TEXT("Invalid AssetPath: %s"), *Reason.ToString());
			return false;
		}
		OutPackage = Path;
		OutAsset = FPackageName::GetShortName(Path);
		return !OutAsset.IsEmpty();
	}

	namespace
	{
		bool ResolveCollisionMethod(const FString& Mode, bool& bNone, bool& bComplex, EGeometryScriptCollisionGenerationMethod& Method)
		{
			const FString M = Mode.ToLower();
			bNone = (M == TEXT("none") || M.IsEmpty());
			bComplex = (M == TEXT("complex"));
			if (bNone || bComplex) { return true; }
			if (M == TEXT("auto")) { Method = EGeometryScriptCollisionGenerationMethod::MinVolumeShapes; return true; }
			if (M == TEXT("box")) { Method = EGeometryScriptCollisionGenerationMethod::AlignedBoxes; return true; }
			if (M == TEXT("convex")) { Method = EGeometryScriptCollisionGenerationMethod::ConvexHulls; return true; }
			return false;
		}
	}

	FStaticMeshAssetResult WriteStaticMeshAsset(UDynamicMesh* Mesh, const FString& PackageName, const FString& AssetName, const FStaticMeshAssetOptions& Options)
	{
		FStaticMeshAssetResult Result;

		bool bNoCollision = false;
		bool bComplexCollision = false;
		EGeometryScriptCollisionGenerationMethod CollisionMethod = EGeometryScriptCollisionGenerationMethod::MinVolumeShapes;
		if (!ResolveCollisionMethod(Options.CollisionMode, bNoCollision, bComplexCollision, CollisionMethod))
		{
			Result.Error = TEXT("Collision must be 'none', 'auto', 'box', 'convex' or 'complex'.");
			return Result;
		}

		// Find an existing asset (registry or already loaded in memory).
		const FString ObjectPath = PackageName + TEXT(".") + AssetName;
		UStaticMesh* StaticMesh = FindObject<UStaticMesh>(nullptr, *ObjectPath);
		if (!StaticMesh)
		{
			const FAssetData Existing = FAssetRegistryModule::GetRegistry().GetAssetByObjectPath(FSoftObjectPath(ObjectPath));
			if (Existing.IsValid())
			{
				StaticMesh = Cast<UStaticMesh>(Existing.GetAsset());
				if (!StaticMesh)
				{
					Result.Error = FString::Printf(TEXT("An asset of a different type already exists at %s."), *ObjectPath);
					return Result;
				}
			}
		}

		bool bCreated = false;
		if (StaticMesh)
		{
			if (!Options.bOverwrite)
			{
				Result.Error = FString::Printf(TEXT("%s already exists. Pass bOverwrite=true to replace it, or choose another path."), *ObjectPath);
				return Result;
			}
		}
		else
		{
			UPackage* Package = CreatePackage(*PackageName);
			StaticMesh = NewObject<UStaticMesh>(Package, FName(*AssetName), RF_Public | RF_Standalone | RF_Transactional);
			bCreated = true;
		}
		if (!StaticMesh)
		{
			Result.Error = TEXT("Could not create the StaticMesh asset.");
			return Result;
		}

		FGeometryScriptCopyMeshToAssetOptions CopyOptions;
		CopyOptions.bEnableRecomputeTangents = true;
		CopyOptions.bEnableRemoveDegenerates = true;
		CopyOptions.bApplyNaniteSettings = true;
		CopyOptions.NewNaniteSettings.bEnabled = Options.bEnableNanite;

		bool bAnyMaterial = false;
		TArray<TObjectPtr<UMaterialInterface>> Materials;
		for (UMaterialInterface* Material : Options.Materials)
		{
			bAnyMaterial |= (Material != nullptr);
			Materials.Add(Material);
		}
		if (bAnyMaterial)
		{
			CopyOptions.bReplaceMaterials = true;
			CopyOptions.NewMaterials = MoveTemp(Materials);
		}

		EGeometryScriptOutcomePins Outcome = EGeometryScriptOutcomePins::Failure;
		UGeometryScriptLibrary_StaticMeshFunctions::CopyMeshToStaticMesh(Mesh, StaticMesh, CopyOptions, FGeometryScriptMeshWriteLOD(), Outcome, /*bUseSectionMaterials=*/true);
		if (Outcome != EGeometryScriptOutcomePins::Success)
		{
			Result.Error = TEXT("Copying the mesh into the StaticMesh asset failed.");
			if (bCreated)
			{
				StaticMesh->MarkAsGarbage();
			}
			return Result;
		}

		if (bComplexCollision)
		{
			StaticMesh->CreateBodySetup();
			if (UBodySetup* Body = StaticMesh->GetBodySetup())
			{
				Body->CollisionTraceFlag = CTF_UseComplexAsSimple;
				Body->InvalidatePhysicsData();
			}
		}
		else if (!bNoCollision)
		{
			FGeometryScriptCollisionFromMeshOptions CollisionOptions;
			CollisionOptions.Method = CollisionMethod;
			CollisionOptions.MaxConvexHullsPerMesh = 1;
			UGeometryScriptLibrary_CollisionFunctions::SetStaticMeshCollisionFromMesh(Mesh, StaticMesh, CollisionOptions);
		}

		StaticMesh->MarkPackageDirty();
		if (bCreated)
		{
			FAssetRegistryModule::AssetCreated(StaticMesh);
		}

		Result.StaticMesh = StaticMesh;
		Result.bCreated = bCreated;
		if (Options.bSaveToDisk)
		{
			Result.bSaved = UEditorLoadingAndSavingUtils::SavePackages({ StaticMesh->GetOutermost() }, /*bOnlyDirty=*/false);
			if (!Result.bSaved)
			{
				Result.Error = TEXT("The asset was created in memory but saving it to disk failed. Save it from the editor, or check that the file is writable.");
			}
		}
		return Result;
	}

	FExportResult ExportModelToFbx(const FString& OutputName)
	{
		FExportResult Result;

		UWorld* World = GetEditorWorld();
		if (!World)
		{
			Result.Error = TEXT("No editor world is available.");
			return Result;
		}

		TArray<ADynamicMeshActor*> Actors;
		for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
		{
			if (It->Tags.Contains(ActorTag) && GetDynamicMesh(*It))
			{
				Actors.Add(*It);
			}
		}
		if (Actors.IsEmpty())
		{
			Result.Error = TEXT("There is no model in the level to export.");
			return Result;
		}

		// Merge every part into one mesh, keeping the parts' positions relative to each other and each part's colours:
		// every part's material slots are appended to one list and its face numbers offset to match.
		TStrongObjectPtr<UDynamicMesh> Merged(NewObject<UDynamicMesh>(GetTransientPackage()));
		TArray<UMaterialInterface*> MergedSlots;
		for (ADynamicMeshActor* Actor : Actors)
		{
			TArray<UMaterialInterface*> Slots = GetMaterialSlots(Actor);
			bool bAnyMaterial = false;
			for (UMaterialInterface* M : Slots) { bAnyMaterial |= (M != nullptr); }
			if (!bAnyMaterial)
			{
				Slots = { nullptr };
			}
			const int32 Offset = MergedSlots.Num();
			MergedSlots.Append(Slots);

			TStrongObjectPtr<UDynamicMesh> Copy(NewObject<UDynamicMesh>(GetTransientPackage()));
			GetDynamicMesh(Actor)->ProcessMesh([&Copy](const UE::Geometry::FDynamicMesh3& M) { Copy->SetMesh(M); });
			Copy->EditMesh([&](UE::Geometry::FDynamicMesh3& M)
			{
				if (!M.HasAttributes()) { M.EnableAttributes(); }
				if (!M.Attributes()->HasMaterialID()) { M.Attributes()->EnableMaterialID(); }
				UE::Geometry::FDynamicMeshMaterialAttribute* Ids = M.Attributes()->GetMaterialID();
				for (const int32 Tid : M.TriangleIndicesItr())
				{
					const int32 Id = Ids->GetValue(Tid);
					Ids->SetValue(Tid, Offset + (Slots.IsValidIndex(Id) ? Id : 0));
				}
			}, EDynamicMeshChangeType::GeneralEdit, EDynamicMeshAttributeChangeFlags::Unknown);

			UGeometryScriptLibrary_MeshBasicEditFunctions::AppendMesh(
				Merged.Get(), Copy.Get(), Actor->GetActorTransform(), /*bDeferChangeNotifications=*/false, FGeometryScriptAppendMeshOptions());
		}

		FBox Bounds(ForceInit);
		int32 Triangles = 0;
		Merged->ProcessMesh([&Bounds, &Triangles](const UE::Geometry::FDynamicMesh3& M)
		{
			Triangles = M.TriangleCount();
			if (Triangles > 0)
			{
				const UE::Geometry::FAxisAlignedBox3d B = M.GetBounds();
				Bounds = FBox(FVector(B.Min), FVector(B.Max));
			}
		});
		if (Triangles == 0 || !Bounds.IsValid)
		{
			Result.Error = TEXT("The model has no geometry yet.");
			return Result;
		}

		// Stand the model on the ground, centred on the origin.
		const FVector Center = Bounds.GetCenter();
		UGeometryScriptLibrary_MeshTransformFunctions::TranslateMesh(Merged.Get(), FVector(-Center.X, -Center.Y, -Bounds.Min.Z));

		// The FBX needs a usable texture layout. World-aligned textures do not carry one, and raw primitives have the wrong tile
		// size, so generate a world-scale layout unless the AI already laid out a good one.
		double WrongTile = 0.0, Stretched = 0.0; int32 Missing = 0, Faces = 0;
		UModellingTextureToolset::MeasureUVQuality(Merged.Get(), WrongTile, Stretched, Missing, Faces);
		if (Missing > 0 || WrongTile > 50.0 || Stretched > 50.0)
		{
			UModellingTextureToolset::ApplyBoxUVs(Merged.Get());
			Result.UVNote = TEXT("generated (box projection, one tile per 100 cm)");
		}
		else
		{
			Result.UVNote = TEXT("kept from the model");
		}

		FStaticMeshAssetOptions AssetOptions;
		AssetOptions.CollisionMode = TEXT("auto");
		AssetOptions.bOverwrite = true;
		AssetOptions.bSaveToDisk = true;
		AssetOptions.Materials = MergedSlots;

		const FString SafeName = SanitizeFileName(OutputName);
		const FString PackageName = TEXT("/Game/ModellingToolset/Exports/") + SafeName;
		const FStaticMeshAssetResult Asset = WriteStaticMeshAsset(Merged.Get(), PackageName, SafeName, AssetOptions);
		if (!Asset.StaticMesh)
		{
			Result.Error = Asset.Error;
			return Result;
		}
		Result.AssetPath = PackageName + TEXT(".") + SafeName;
		Result.Triangles = Triangles;

		// Export the asset as FBX.
		EnsureWorkspaceFolders();
		const FString FbxFile = GetExportsDir() / (SafeName + TEXT(".fbx"));
		IFileManager::Get().Delete(*FbxFile, /*RequireExists=*/false, /*EvenReadOnly=*/true);

		TStrongObjectPtr<UAssetExportTask> Task(NewObject<UAssetExportTask>());
		Task->Object = Asset.StaticMesh;
		Task->Filename = FbxFile;
		Task->bSelected = false;
		Task->bReplaceIdentical = true;
		Task->bPrompt = false;
		Task->bAutomated = true;
		Task->bUseFileArchive = false;
		Task->bWriteEmptyFiles = false;

		const bool bExported = UExporter::RunAssetExportTask(Task.Get());
		if (!bExported || !IFileManager::Get().FileExists(*FbxFile))
		{
			Result.Error = TEXT("Unreal could not write the FBX file. The model was saved as an asset instead: ") + Result.AssetPath;
			return Result;
		}

		Result.FbxPath = FbxFile;
		Result.bOk = true;
		return Result;
	}
}

