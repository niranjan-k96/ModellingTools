// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingToolsetUtils.h"

#include "ModellingSelection.h"
#include "ModellingToolsetSettings.h"

#include "Components/DynamicMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMesh/DynamicMeshAttributeSet.h"
#include "DynamicMeshActor.h"
#include "Materials/Material.h"
#include "Materials/MaterialInterface.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "EngineUtils.h"
#include "GeometryScript/GeometryScriptTypes.h"
#include "GeometryScript/MeshMaterialFunctions.h"
#include "GeometryScript/MeshSelectionFunctions.h"
#include "HAL/FileManager.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "UDynamicMesh.h"

namespace ModellingToolset
{
	const FName ActorTag(TEXT("ModellingToolset"));

	namespace
	{
		/** One snapshot per actor: its mesh as it was before the latest edit. */
		TMap<FString, TSharedPtr<UE::Geometry::FDynamicMesh3>> GLastEditSnapshots;
	}

	UWorld* GetEditorWorld()
	{
		return GEditor ? GEditor->GetEditorWorldContext().World() : nullptr;
	}

	// ---- Folders -------------------------------------------------------------------------------

	static FString ResolveFolder(const FString& Setting)
	{
		FString Folder = Setting;
		if (FPaths::IsRelative(Folder))
		{
			Folder = FPaths::ProjectDir() / Folder;
		}
		Folder = FPaths::ConvertRelativePathToFull(Folder);
		FPaths::NormalizeDirectoryName(Folder);
		FPaths::CollapseRelativeDirectories(Folder);
		return Folder;
	}

	FString GetReferencesDir()
	{
		return ResolveFolder(GetDefault<UModellingToolsetSettings>()->ReferencesFolder);
	}

	FString GetProgressDir()
	{
		return ResolveFolder(GetDefault<UModellingToolsetSettings>()->ProgressFolder);
	}

	FString GetExportsDir()
	{
		return ResolveFolder(GetDefault<UModellingToolsetSettings>()->ExportsFolder);
	}

	FString GetTexturesDir()
	{
		return ResolveFolder(GetDefault<UModellingToolsetSettings>()->TexturesFolder);
	}

	void EnsureWorkspaceFolders()
	{
		IFileManager::Get().MakeDirectory(*GetReferencesDir(), /*Tree=*/true);
		IFileManager::Get().MakeDirectory(*GetProgressDir(), /*Tree=*/true);
		IFileManager::Get().MakeDirectory(*GetExportsDir(), /*Tree=*/true);
		IFileManager::Get().MakeDirectory(*GetTexturesDir(), /*Tree=*/true);
	}

	TArray<FString> ListReferenceImageNames()
	{
		TArray<FString> Files, Images;
		IFileManager::Get().FindFiles(Files, *(GetReferencesDir() / TEXT("*.*")), /*Files=*/true, /*Directories=*/false);
		Files.Sort();
		for (const FString& File : Files)
		{
			const FString Ext = FPaths::GetExtension(File).ToLower();
			if (Ext == TEXT("png") || Ext == TEXT("jpg") || Ext == TEXT("jpeg") || Ext == TEXT("bmp"))
			{
				Images.Add(File);
			}
		}
		return Images;
	}

	FReferenceMeta ReadReferenceMeta(const FString& ImageFileName)
	{
		FReferenceMeta Meta;
		const FString Full = GetReferencesDir() / ImageFileName;

		for (const TCHAR* Ext : { TEXT("txt"), TEXT("md") })
		{
			const FString NotesPath = FPaths::ChangeExtension(Full, Ext);
			FString Text;
			if (IFileManager::Get().FileExists(*NotesPath) && FFileHelper::LoadFileToString(Text, *NotesPath))
			{
				Meta.Notes = Text;
				break;
			}
		}

		auto NormaliseView = [](FString V) -> FString
		{
			V = V.TrimStartAndEnd().ToLower();
			if (V == TEXT("side")) { return TEXT("right"); }
			for (const TCHAR* Known : { TEXT("front"), TEXT("back"), TEXT("left"), TEXT("right"), TEXT("top"), TEXT("bottom") })
			{
				if (V == Known) { return V; }
			}
			return FString();
		};

		TArray<FString> Lines;
		Meta.Notes.ParseIntoArrayLines(Lines);
		for (const FString& Line : Lines)
		{
			FString Key, Value;
			if (!Line.Split(TEXT(":"), &Key, &Value))
			{
				continue;
			}
			Key = Key.TrimStartAndEnd().ToLower();
			Value = Value.TrimStartAndEnd();
			if (Key == TEXT("view")) { Meta.View = NormaliseView(Value); }
			else if (Key == TEXT("height_cm") || Key == TEXT("height")) { Meta.HeightCm = FCString::Atod(*Value); }
			else if (Key == TEXT("width_cm") || Key == TEXT("width")) { Meta.WidthCm = FCString::Atod(*Value); }
			else if (Key == TEXT("depth_cm") || Key == TEXT("depth")) { Meta.DepthCm = FCString::Atod(*Value); }
		}

		if (Meta.View.IsEmpty())
		{
			const FString Base = FPaths::GetBaseFilename(ImageFileName).ToLower();
			for (const TCHAR* Word : { TEXT("front"), TEXT("back"), TEXT("left"), TEXT("right"), TEXT("side"), TEXT("top"), TEXT("bottom") })
			{
				if (Base.Contains(Word))
				{
					Meta.View = NormaliseView(Word);
					break;
				}
			}
		}
		return Meta;
	}

	bool IsPathUnder(const FString& Path, const FString& Root)
	{
		FString P = FPaths::ConvertRelativePathToFull(Path);
		FString R = FPaths::ConvertRelativePathToFull(Root);
		FPaths::NormalizeFilename(P);
		FPaths::NormalizeDirectoryName(R);
		FPaths::CollapseRelativeDirectories(P);
		FPaths::CollapseRelativeDirectories(R);
		return P.StartsWith(R + TEXT("/"), ESearchCase::IgnoreCase);
	}

	FString SanitizeFileName(const FString& In)
	{
		FString Out;
		for (const TCHAR C : In)
		{
			Out.AppendChar(FChar::IsAlnum(C) || C == TEXT('_') || C == TEXT('-') ? C : TEXT('_'));
		}
		return Out.IsEmpty() ? FString(TEXT("untitled")) : Out;
	}

	// ---- Actors --------------------------------------------------------------------------------

	ADynamicMeshActor* FindMeshActor(const FString& Name)
	{
		UWorld* World = GetEditorWorld();
		if (!World || Name.IsEmpty())
		{
			return nullptr;
		}
		for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
		{
			if (It->GetActorLabel() == Name || It->GetName() == Name)
			{
				return *It;
			}
		}
		return nullptr;
	}

	ADynamicMeshActor* FindModelActor(const FString& Name)
	{
		ADynamicMeshActor* Actor = FindMeshActor(Name);
		if (!Actor)
		{
			Fail(FString::Printf(TEXT("No model actor named '%s'. Use ListMeshActors to see names, or CreateMeshActor."), *Name));
			return nullptr;
		}
		if (!Actor->Tags.Contains(ActorTag))
		{
			Fail(FString::Printf(TEXT("Actor '%s' was not created by the Modelling Toolset, so it will not be modified."), *Name));
			return nullptr;
		}
		return Actor;
	}

	ADynamicMeshActor* CreateMeshActor(const FString& Name, const FVector& Location, const FRotator& Rotation)
	{
		UWorld* World = GetEditorWorld();
		if (!World)
		{
			Fail(TEXT("No editor world is available."));
			return nullptr;
		}

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ADynamicMeshActor* Actor = World->SpawnActor<ADynamicMeshActor>(Location, Rotation, Params);
		if (!Actor)
		{
			Fail(TEXT("Failed to spawn a dynamic mesh actor."));
			return nullptr;
		}

		// SetActorLabel alone does not enforce uniqueness, so use the unique variant: "Name", "Name1", "Name2", ...
		FActorLabelUtilities::SetActorLabelUnique(Actor, Name.IsEmpty() ? FString(TEXT("ModelPart")) : Name);
		Actor->Tags.AddUnique(ActorTag);
		return Actor;
	}

	UDynamicMesh* GetDynamicMesh(ADynamicMeshActor* Actor)
	{
		UDynamicMeshComponent* Component = Actor ? Actor->GetDynamicMeshComponent() : nullptr;
		return Component ? Component->GetDynamicMesh() : nullptr;
	}

	// ---- Results -------------------------------------------------------------------------------

	namespace
	{
		FErrorCapture* GErrorCapture = nullptr;
	}

	FErrorCapture::FErrorCapture()
	{
		Previous = GErrorCapture;
		GErrorCapture = this;
	}

	FErrorCapture::~FErrorCapture()
	{
		GErrorCapture = Previous;
	}

	void Fail(const FString& Message)
	{
		if (GErrorCapture)
		{
			if (GErrorCapture->Message.IsEmpty())
			{
				GErrorCapture->Message = Message;
			}
			return;
		}
		UKismetSystemLibrary::RaiseScriptError(Message);
	}

	FString ToJsonString(const TSharedRef<FJsonObject>& Object)
	{
		FString Out;
		const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Out);
		FJsonSerializer::Serialize(Object, Writer);
		return Out;
	}

	FString ToJsonString(const TArray<TSharedPtr<FJsonValue>>& Array)
	{
		FString Out;
		const TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Out);
		FJsonSerializer::Serialize(Array, Writer);
		return Out;
	}

	static TSharedRef<FJsonObject> VectorToJson(const FVector& V)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetNumberField(TEXT("x"), V.X);
		O->SetNumberField(TEXT("y"), V.Y);
		O->SetNumberField(TEXT("z"), V.Z);
		return O;
	}

	static TSharedRef<FJsonObject> RotatorToJson(const FRotator& R)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetNumberField(TEXT("pitch"), R.Pitch);
		O->SetNumberField(TEXT("yaw"), R.Yaw);
		O->SetNumberField(TEXT("roll"), R.Roll);
		return O;
	}

	TSharedRef<FJsonObject> DescribeActor(ADynamicMeshActor* Actor)
	{
		TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
		if (!Actor)
		{
			return Out;
		}

		Out->SetStringField(TEXT("actor"), Actor->GetActorLabel());
		Out->SetObjectField(TEXT("location_cm"), VectorToJson(Actor->GetActorLocation()));
		Out->SetObjectField(TEXT("rotation_deg"), RotatorToJson(Actor->GetActorRotation()));
		Out->SetObjectField(TEXT("scale"), VectorToJson(Actor->GetActorScale3D()));

		if (UDynamicMesh* Mesh = GetDynamicMesh(Actor))
		{
			Mesh->ProcessMesh([&Out](const UE::Geometry::FDynamicMesh3& M)
			{
				Out->SetNumberField(TEXT("triangles"), M.TriangleCount());
				Out->SetNumberField(TEXT("vertices"), M.VertexCount());
			});
		}

		FVector Origin, Extent;
		Actor->GetActorBounds(/*bOnlyCollidingComponents=*/false, Origin, Extent);
		Out->SetObjectField(TEXT("world_bounds_center_cm"), VectorToJson(Origin));
		Out->SetObjectField(TEXT("world_size_cm"), VectorToJson(Extent * 2.0));

		// Health checks, so problems are reported with the result instead of being discovered from a dark picture.
		const FMeshDiagnostics D = DiagnoseMesh(Actor);
		TArray<TSharedPtr<FJsonValue>> Warnings;
		if (D.bInsideOut)
		{
			Warnings.Add(MakeShared<FJsonValueString>(TEXT("The faces point inward, so the part will look dark or see-through. Call FlipNormals.")));
		}
		if (D.OpenBoundaryEdges > 0)
		{
			Warnings.Add(MakeShared<FJsonValueString>(FString::Printf(TEXT("The surface has %d open edges (holes or an unclosed shape). FillHoles closes them if they are unintended."), D.OpenBoundaryEdges)));
		}
		if (D.FacesWithMissingMaterial > 0)
		{
			Warnings.Add(MakeShared<FJsonValueString>(FString::Printf(TEXT("%d faces point at an empty material slot and would render with the checker fallback. PaintPart or PaintFaces fixes them."), D.FacesWithMissingMaterial)));
		}
		if (!Warnings.IsEmpty())
		{
			Out->SetArrayField(TEXT("warnings"), Warnings);
		}
		return Out;
	}

	// ---- Editing -------------------------------------------------------------------------------

	FEditScope::FEditScope(const FString& Name, const TCHAR* Description, bool bCreateIfMissing)
		: Transaction(FText::FromString(FString::Printf(TEXT("Modelling: %s"), Description)))
	{
		if (ADynamicMeshActor* Existing = FindMeshActor(Name))
		{
			if (!Existing->Tags.Contains(ActorTag))
			{
				Fail(FString::Printf(TEXT("Actor '%s' was not created by the Modelling Toolset, so it will not be modified."), *Name));
				return;
			}
			Actor = Existing;
		}
		else if (bCreateIfMissing)
		{
			Actor = CreateMeshActor(Name, FVector::ZeroVector, FRotator::ZeroRotator);
		}
		else
		{
			Fail(FString::Printf(TEXT("No model actor named '%s'. Create it with CreateMeshActor, or pass bCreateIfMissing=true."), *Name));
			return;
		}

		if (!Actor)
		{
			return;
		}
		Mesh = GetDynamicMesh(Actor);
		if (!Mesh)
		{
			Fail(TEXT("The actor has no dynamic mesh component."));
			return;
		}

		// Record the geometry for undo: Modify() on the actor alone does not capture the mesh object.
		Actor->Modify();
		if (UDynamicMeshComponent* Component = Actor->GetDynamicMeshComponent())
		{
			Component->Modify();
		}
		Mesh->SetFlags(RF_Transactional);
		Mesh->Modify();

		// Keep one snapshot of the state before this edit, for RevertLastEdit and for the empty-result safety check.
		TSharedPtr<UE::Geometry::FDynamicMesh3> Snapshot = MakeShared<UE::Geometry::FDynamicMesh3>();
		Mesh->ProcessMesh([this, &Snapshot](const UE::Geometry::FDynamicMesh3& M)
		{
			*Snapshot = M;
			TrianglesBefore = M.TriangleCount();
		});
		GLastEditSnapshots.Add(Actor->GetActorLabel(), Snapshot);
	}

	FString FEditScope::Result()
	{
		int32 TrianglesAfter = 0;
		Mesh->ProcessMesh([&TrianglesAfter](const UE::Geometry::FDynamicMesh3& M) { TrianglesAfter = M.TriangleCount(); });
		if (TrianglesBefore > 0 && TrianglesAfter == 0)
		{
			RestoreLastEdit(Actor);
			Fail(TEXT("That operation removed the whole mesh, so it was undone. Check the plane direction, selection or settings and try again."));
			return FString();
		}
		// Cuts and merges can leave faces pointing at a slot with no material; those would render with the fallback checker.
		NormaliseMaterialIDs(Actor);
		return ToJsonString(DescribeActor(Actor));
	}

	// ---- Materials -----------------------------------------------------------------------------

	TArray<UMaterialInterface*> GetMaterialSlots(ADynamicMeshActor* Actor)
	{
		TArray<UMaterialInterface*> Slots;
		if (UDynamicMeshComponent* Component = Actor ? Actor->GetDynamicMeshComponent() : nullptr)
		{
			// An unpainted component reports the engine's grey checker as its material. That is "no material" for our purposes,
			// so it is never copied onto cut faces or exported as a real colour.
			const UMaterialInterface* Checker = UMaterial::GetDefaultMaterial(MD_Surface);
			for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
			{
				UMaterialInterface* M = Component->GetMaterial(i);
				Slots.Add(M == Checker ? nullptr : M);
			}
		}
		return Slots;
	}

	bool ComputeOrientation(const UE::Geometry::FDynamicMesh3& M, bool& bOutClosed, double& OutSignedVolume, double& OutRadialScore)
	{
		bOutClosed = M.TriangleCount() > 0;
		for (const int32 Eid : M.EdgeIndicesItr())
		{
			if (M.IsBoundaryEdge(Eid)) { bOutClosed = false; break; }
		}
		OutSignedVolume = 0.0;
		OutRadialScore = 0.0;
		for (const int32 Tid : M.TriangleIndicesItr())
		{
			FVector3d A, B, C;
			M.GetTriVertices(Tid, A, B, C);
			OutSignedVolume += A.Dot(B.Cross(C)) / 6.0;
			// Does this face point away from the vertical axis through the origin? (Used for open surfaces such as a partial revolve.)
			const FVector3d Centroid = (A + B + C) / 3.0;
			const FVector3d Radial(Centroid.X, Centroid.Y, 0.0);
			const FVector3d Normal = (B - A).Cross(C - A); // area-weighted
			if (!Radial.IsNearlyZero())
			{
				OutRadialScore += Normal.Dot(Radial.GetSafeNormal());
			}
		}
		return M.TriangleCount() > 0;
	}

	bool IsInsideOut(const UE::Geometry::FDynamicMesh3& M)
	{
		bool bClosed = false;
		double Volume = 0.0, Radial = 0.0;
		if (!ComputeOrientation(M, bClosed, Volume, Radial))
		{
			return false;
		}
		return bClosed ? Volume < 0.0 : Radial < 0.0;
	}

	bool EnsureFacesPointOutward(UDynamicMesh* Mesh)
	{
		bool bFlipped = false;
		if (!Mesh)
		{
			return false;
		}
		Mesh->EditMesh([&bFlipped](UE::Geometry::FDynamicMesh3& M)
		{
			if (IsInsideOut(M))
			{
				M.ReverseOrientation(/*bFlipNormals=*/true);
				bFlipped = true;
			}
		}, EDynamicMeshChangeType::GeneralEdit, EDynamicMeshAttributeChangeFlags::Unknown);
		return bFlipped;
	}

	namespace
	{
		/** Sets the material of one slot, growing the slot list if needed. */
		void SetSlot(UDynamicMeshComponent* Component, int32 Slot, UMaterialInterface* Material)
		{
			TArray<UMaterialInterface*> Slots;
			for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
			{
				Slots.Add(Component->GetMaterial(i));
			}
			while (Slots.Num() <= Slot)
			{
				Slots.Add(nullptr);
			}
			Slots[Slot] = Material;
			Component->ConfigureMaterialSet(Slots);
		}
	}

	void ApplyMaterialToWholePart(ADynamicMeshActor* Actor, UDynamicMesh* Mesh, UMaterialInterface* Material)
	{
		UDynamicMeshComponent* Component = Actor ? Actor->GetDynamicMeshComponent() : nullptr;
		if (!Component || !Mesh || !Material)
		{
			return;
		}
		UGeometryScriptLibrary_MeshMaterialFunctions::EnableMaterialIDs(Mesh);
		FGeometryScriptMeshSelection AllFaces;
		UGeometryScriptLibrary_MeshSelectionFunctions::CreateSelectAllMeshSelection(Mesh, AllFaces, EGeometryScriptMeshSelectionType::Triangles);
		UGeometryScriptLibrary_MeshMaterialFunctions::SetMaterialIDForMeshSelection(Mesh, AllFaces, 0, false);
		TArray<UMaterialInterface*> OnlySlot{ Material };
		Component->ConfigureMaterialSet(OnlySlot);
	}

	int32 ApplyMaterialToSelection(ADynamicMeshActor* Actor, UDynamicMesh* Mesh, const FGeometryScriptMeshSelection& Selection, UMaterialInterface* Material)
	{
		UDynamicMeshComponent* Component = Actor ? Actor->GetDynamicMeshComponent() : nullptr;
		if (!Component || !Mesh || !Material)
		{
			return INDEX_NONE;
		}
		UGeometryScriptLibrary_MeshMaterialFunctions::EnableMaterialIDs(Mesh);

		int32 Slot = INDEX_NONE;
		for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
		{
			if (Component->GetMaterial(i) == Material) { Slot = i; break; }
		}
		if (Slot == INDEX_NONE)
		{
			bool bHasIds = false;
			const int32 MaxId = UGeometryScriptLibrary_MeshMaterialFunctions::GetMaxMaterialID(Mesh, bHasIds);
			Slot = FMath::Max(Component->GetNumMaterials(), MaxId + 1);
			SetSlot(Component, Slot, Material);
		}
		UGeometryScriptLibrary_MeshMaterialFunctions::SetMaterialIDForMeshSelection(Mesh, Selection, Slot, false);
		return Slot;
	}

	int32 NormaliseMaterialIDs(ADynamicMeshActor* Actor)
	{
		UDynamicMesh* Mesh = GetDynamicMesh(Actor);
		if (!Mesh)
		{
			return 0;
		}
		const TArray<UMaterialInterface*> Slots = GetMaterialSlots(Actor);
		int32 FirstUsable = 0;
		for (int32 i = 0; i < Slots.Num(); ++i)
		{
			if (Slots[i]) { FirstUsable = i; break; }
		}
		auto IsUsable = [&Slots](int32 Id) { return Slots.IsValidIndex(Id) && Slots[Id] != nullptr; };

		// Nothing to fix when the part has no materials at all: every face uses the default look anyway.
		bool bAnyMaterial = false;
		for (UMaterialInterface* M : Slots) { bAnyMaterial |= (M != nullptr); }
		if (!bAnyMaterial)
		{
			return 0;
		}

		int32 Changed = 0;
		Mesh->EditMesh([&](UE::Geometry::FDynamicMesh3& M)
		{
			if (!M.HasAttributes() || !M.Attributes()->HasMaterialID())
			{
				return;
			}
			UE::Geometry::FDynamicMeshMaterialAttribute* Ids = M.Attributes()->GetMaterialID();
			for (const int32 Tid : M.TriangleIndicesItr())
			{
				const int32 Id = Ids->GetValue(Tid);
				if (!IsUsable(Id))
				{
					Ids->SetValue(Tid, FirstUsable);
					++Changed;
				}
			}
		}, EDynamicMeshChangeType::GeneralEdit, EDynamicMeshAttributeChangeFlags::Unknown);
		return Changed;
	}

	TStrongObjectPtr<UDynamicMesh> CopyMeshForMerge(ADynamicMeshActor* Target, ADynamicMeshActor* Source)
	{
		TStrongObjectPtr<UDynamicMesh> Copy(NewObject<UDynamicMesh>(GetTransientPackage()));
		UDynamicMesh* SourceMesh = GetDynamicMesh(Source);
		if (!SourceMesh)
		{
			return Copy;
		}
		SourceMesh->ProcessMesh([&Copy](const UE::Geometry::FDynamicMesh3& M) { Copy->SetMesh(M); });

		TArray<UMaterialInterface*> TargetSlots = GetMaterialSlots(Target);
		const TArray<UMaterialInterface*> SourceSlots = GetMaterialSlots(Source);
		bool bSourceHasMaterial = false;
		for (UMaterialInterface* M : SourceSlots) { bSourceHasMaterial |= (M != nullptr); }

		int32 Offset = 0;
		int32 FallbackId = 0;
		for (int32 i = 0; i < TargetSlots.Num(); ++i)
		{
			if (TargetSlots[i]) { FallbackId = i; break; }
		}
		if (bSourceHasMaterial)
		{
			// Keep the source's look: its slots go after the target's, and its faces are renumbered to match.
			Offset = TargetSlots.Num();
			TargetSlots.Append(SourceSlots);
			if (UDynamicMeshComponent* TargetComponent = Target->GetDynamicMeshComponent())
			{
				TargetComponent->ConfigureMaterialSet(TargetSlots);
			}
		}

		Copy->EditMesh([&](UE::Geometry::FDynamicMesh3& M)
		{
			if (!M.HasAttributes()) { M.EnableAttributes(); }
			if (!M.Attributes()->HasMaterialID()) { M.Attributes()->EnableMaterialID(); }
			UE::Geometry::FDynamicMeshMaterialAttribute* Ids = M.Attributes()->GetMaterialID();
			for (const int32 Tid : M.TriangleIndicesItr())
			{
				if (bSourceHasMaterial)
				{
					const int32 Id = Ids->GetValue(Tid);
					Ids->SetValue(Tid, SourceSlots.IsValidIndex(Id) && SourceSlots[Id] ? Id + Offset : FallbackId);
				}
				else
				{
					Ids->SetValue(Tid, FallbackId); // an unpainted cutter or part takes the target's base colour
				}
			}
		}, EDynamicMeshChangeType::GeneralEdit, EDynamicMeshAttributeChangeFlags::Unknown);
		return Copy;
	}

	// ---- Diagnostics ---------------------------------------------------------------------------

	FMeshDiagnostics DiagnoseMesh(ADynamicMeshActor* Actor)
	{
		FMeshDiagnostics D;
		UDynamicMesh* Mesh = GetDynamicMesh(Actor);
		if (!Mesh)
		{
			return D;
		}
		const TArray<UMaterialInterface*> Slots = GetMaterialSlots(Actor);
		D.MaterialSlots = Slots.Num();
		bool bAnyMaterial = false;
		for (UMaterialInterface* M : Slots) { bAnyMaterial |= (M != nullptr); }

		Mesh->ProcessMesh([&](const UE::Geometry::FDynamicMesh3& M)
		{
			D.Triangles = M.TriangleCount();
			for (const int32 Eid : M.EdgeIndicesItr())
			{
				if (M.IsBoundaryEdge(Eid)) { ++D.OpenBoundaryEdges; }
			}
			bool bClosed = false;
			double Radial = 0.0;
			ComputeOrientation(M, bClosed, D.SignedVolume, Radial);
			D.bInsideOut = bClosed && D.Triangles > 0 && D.SignedVolume < 0.0;

			if (bAnyMaterial && M.HasAttributes() && M.Attributes()->HasMaterialID())
			{
				const UE::Geometry::FDynamicMeshMaterialAttribute* Ids = M.Attributes()->GetMaterialID();
				for (const int32 Tid : M.TriangleIndicesItr())
				{
					const int32 Id = Ids->GetValue(Tid);
					if (!Slots.IsValidIndex(Id) || !Slots[Id]) { ++D.FacesWithMissingMaterial; }
				}
			}
		});
		return D;
	}

	bool RestoreLastEdit(ADynamicMeshActor* Actor)
	{
		UDynamicMesh* Mesh = GetDynamicMesh(Actor);
		const TSharedPtr<UE::Geometry::FDynamicMesh3>* Found = Actor ? GLastEditSnapshots.Find(Actor->GetActorLabel()) : nullptr;
		if (!Mesh || !Found || !Found->IsValid())
		{
			return false;
		}
		Mesh->SetMesh(**Found);
		return true;
	}

	bool BuildSelection(UDynamicMesh* Mesh, const FModellingSelection& Selection, FGeometryScriptMeshSelection& OutSelection)
	{
		using Lib = UGeometryScriptLibrary_MeshSelectionFunctions;
		const FString Mode = Selection.Mode.ToLower();
		const EGeometryScriptMeshSelectionType Type = EGeometryScriptMeshSelectionType::Triangles;

		if (Mode == TEXT("all") || Mode.IsEmpty())
		{
			Lib::CreateSelectAllMeshSelection(Mesh, OutSelection, Type);
		}
		else if (Mode == TEXT("normal"))
		{
			if (Selection.A.IsNearlyZero())
			{
				Fail(TEXT("Selection mode 'normal' needs a direction in A, e.g. (0,0,1) for upward-facing faces."));
				return false;
			}
			Lib::SelectMeshElementsByNormalAngle(Mesh, OutSelection, Selection.A.GetSafeNormal(), FMath::Max(Selection.Scalar, 0.1f), Type, false, 3);
		}
		else if (Mode == TEXT("box"))
		{
			const FBox Box(Selection.A.ComponentMin(Selection.B), Selection.A.ComponentMax(Selection.B));
			Lib::SelectMeshElementsInBox(Mesh, OutSelection, Box, Type, false, 3);
		}
		else if (Mode == TEXT("sphere"))
		{
			if (Selection.Scalar <= 0.f)
			{
				Fail(TEXT("Selection mode 'sphere' needs a positive radius in Scalar."));
				return false;
			}
			Lib::SelectMeshElementsInSphere(Mesh, OutSelection, Selection.A, Selection.Scalar, Type, false, 3);
		}
		else if (Mode == TEXT("polygroup"))
		{
			Lib::SelectMeshElementsByPolygroup(Mesh, FGeometryScriptGroupLayer(), Selection.PolygroupId, OutSelection, Type);
		}
		else
		{
			Fail(FString::Printf(TEXT("Unknown selection mode '%s'. Use all, normal, box, sphere or polygroup."), *Selection.Mode));
			return false;
		}

		EGeometryScriptMeshSelectionType OutType;
		int32 NumSelected = 0;
		Lib::GetMeshSelectionInfo(OutSelection, OutType, NumSelected);
		if (NumSelected <= 0)
		{
			Fail(FString::Printf(TEXT("Selection '%s' matched no faces. Check the values (local space, cm) or use GetPolygroups."), *Selection.Mode));
			return false;
		}
		return true;
	}

	// ---- Checkpoints ---------------------------------------------------------------------------

	namespace
	{
		struct FCheckpoint
		{
			FString ActorName;
			FString Label;
			UE::Geometry::FDynamicMesh3 Mesh;
		};
		TArray<TSharedPtr<FCheckpoint>> GCheckpoints;
	}

	bool SaveCheckpoint(ADynamicMeshActor* Actor, const FString& Label)
	{
		UDynamicMesh* Mesh = GetDynamicMesh(Actor);
		if (!Mesh)
		{
			return false;
		}

		// Replace an existing checkpoint with the same actor and label.
		GCheckpoints.RemoveAll([&](const TSharedPtr<FCheckpoint>& C)
		{
			return C->ActorName == Actor->GetActorLabel() && C->Label == Label;
		});

		TSharedPtr<FCheckpoint> Checkpoint = MakeShared<FCheckpoint>();
		Checkpoint->ActorName = Actor->GetActorLabel();
		Checkpoint->Label = Label;
		Mesh->ProcessMesh([&Checkpoint](const UE::Geometry::FDynamicMesh3& M) { Checkpoint->Mesh = M; });
		GCheckpoints.Add(Checkpoint);

		const int32 Max = GetDefault<UModellingToolsetSettings>()->MaxCheckpoints;
		while (GCheckpoints.Num() > Max)
		{
			GCheckpoints.RemoveAt(0);
		}
		return true;
	}

	bool RestoreCheckpoint(ADynamicMeshActor* Actor, const FString& Label)
	{
		UDynamicMesh* Mesh = GetDynamicMesh(Actor);
		if (!Mesh)
		{
			return false;
		}
		for (const TSharedPtr<FCheckpoint>& C : GCheckpoints)
		{
			if (C->ActorName == Actor->GetActorLabel() && C->Label == Label)
			{
				Mesh->SetMesh(C->Mesh);
				return true;
			}
		}
		return false;
	}

	TArray<FString> ListCheckpoints(const FString& ActorName)
	{
		TArray<FString> Out;
		for (const TSharedPtr<FCheckpoint>& C : GCheckpoints)
		{
			if (ActorName.IsEmpty() || C->ActorName == ActorName)
			{
				Out.Add(FString::Printf(TEXT("%s/%s"), *C->ActorName, *C->Label));
			}
		}
		return Out;
	}

	// ---- Images --------------------------------------------------------------------------------

	void ResizeImage(const TArray<FColor>& Src, FIntPoint SrcSize, FIntPoint DstSize, TArray<FColor>& Dst)
	{
		Dst.SetNumUninitialized(DstSize.X * DstSize.Y);
		for (int32 Y = 0; Y < DstSize.Y; ++Y)
		{
			const float SY = (Y + 0.5f) * SrcSize.Y / DstSize.Y - 0.5f;
			const int32 Y0 = FMath::Clamp(FMath::FloorToInt(SY), 0, SrcSize.Y - 1);
			const int32 Y1 = FMath::Min(Y0 + 1, SrcSize.Y - 1);
			const float FY = SY - Y0;
			for (int32 X = 0; X < DstSize.X; ++X)
			{
				const float SX = (X + 0.5f) * SrcSize.X / DstSize.X - 0.5f;
				const int32 X0 = FMath::Clamp(FMath::FloorToInt(SX), 0, SrcSize.X - 1);
				const int32 X1 = FMath::Min(X0 + 1, SrcSize.X - 1);
				const float FX = SX - X0;

				auto Sample = [&](int32 PX, int32 PY) { return FLinearColor(Src[PY * SrcSize.X + PX]); };
				const FLinearColor Top = FMath::Lerp(Sample(X0, Y0), Sample(X1, Y0), FX);
				const FLinearColor Bottom = FMath::Lerp(Sample(X0, Y1), Sample(X1, Y1), FX);
				// FLinearColor(FColor) decodes sRGB, so encode back to sRGB; blending in linear space is also gamma-correct.
				Dst[Y * DstSize.X + X] = FMath::Lerp(Top, Bottom, FY).ToFColor(/*bSRGB=*/true);
			}
		}
	}

	bool LoadImageFile(const FString& Path, int32 MaxDimension, TArray<FColor>& OutPixels, FIntPoint& OutSize, FIntPoint& OutOriginalSize, FString& OutError)
	{
		const FString Ext = FPaths::GetExtension(Path).ToLower();
		EImageFormat Format = EImageFormat::Invalid;
		if (Ext == TEXT("png")) { Format = EImageFormat::PNG; }
		else if (Ext == TEXT("jpg") || Ext == TEXT("jpeg")) { Format = EImageFormat::JPEG; }
		else if (Ext == TEXT("bmp")) { Format = EImageFormat::BMP; }
		if (Format == EImageFormat::Invalid)
		{
			OutError = TEXT("Unsupported format. Use png, jpg, jpeg or bmp.");
			return false;
		}

		TArray<uint8> Bytes;
		if (!FFileHelper::LoadFileToArray(Bytes, *Path))
		{
			OutError = TEXT("Could not read the file.");
			return false;
		}

		IImageWrapperModule& Module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
		const TSharedPtr<IImageWrapper> Wrapper = Module.CreateImageWrapper(Format);
		TArray64<uint8> Raw;
		if (!Wrapper.IsValid() || !Wrapper->SetCompressed(Bytes.GetData(), Bytes.Num()) || !Wrapper->GetRaw(ERGBFormat::BGRA, 8, Raw))
		{
			OutError = TEXT("Could not decode the image.");
			return false;
		}

		const int32 W = Wrapper->GetWidth();
		const int32 H = Wrapper->GetHeight();
		if (W <= 0 || H <= 0 || Raw.Num() != static_cast<int64>(W) * H * 4)
		{
			OutError = TEXT("The image has invalid dimensions.");
			return false;
		}

		TArray<FColor> Pixels;
		Pixels.SetNumUninitialized(W * H);
		FMemory::Memcpy(Pixels.GetData(), Raw.GetData(), Raw.Num());
		for (FColor& P : Pixels)
		{
			P.A = 255;
		}

		OutOriginalSize = FIntPoint(W, H);
		const int32 Limit = FMath::Clamp(MaxDimension, 128, 4096);
		if (FMath::Max(W, H) > Limit)
		{
			const float Scale = static_cast<float>(Limit) / FMath::Max(W, H);
			OutSize = FIntPoint(FMath::Max(1, FMath::RoundToInt(W * Scale)), FMath::Max(1, FMath::RoundToInt(H * Scale)));
			ResizeImage(Pixels, OutOriginalSize, OutSize, OutPixels);
		}
		else
		{
			OutSize = OutOriginalSize;
			OutPixels = MoveTemp(Pixels);
		}
		return true;
	}

	bool SavePng(const FString& Path, const TArray<FColor>& Pixels, FIntPoint Size)
	{
		IImageWrapperModule& Module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
		const TSharedPtr<IImageWrapper> Wrapper = Module.CreateImageWrapper(EImageFormat::PNG);
		if (!Wrapper.IsValid() || !Wrapper->SetRaw(Pixels.GetData(), Pixels.Num() * sizeof(FColor), Size.X, Size.Y, ERGBFormat::BGRA, 8))
		{
			return false;
		}
		const TArray64<uint8>& Data = Wrapper->GetCompressed();
		TUniquePtr<FArchive> Writer(IFileManager::Get().CreateFileWriter(*Path));
		if (!Writer)
		{
			return false;
		}
		Writer->Serialize(const_cast<uint8*>(Data.GetData()), Data.Num());
		return true;
	}
}

