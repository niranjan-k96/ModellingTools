// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingAssetToolset.h"

#include "ModellingExport.h"
#include "ModellingToolsetUtils.h"

#include "Components/DynamicMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMeshActor.h"
#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "GeometryScript/MeshAssetFunctions.h"
#include "Misc/PackageName.h"
#include "ScopedTransaction.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"

#define LOCTEXT_NAMESPACE "ModellingAssetToolset"

using namespace ModellingToolset;

FString UModellingAssetToolset::SaveToStaticMesh(
	const FString& Name, const FString& AssetPath, bool bOverwrite, const FString& Collision,
	bool bEnableNanite, bool bPlaceInLevel, bool bDeleteSourceActor, bool bSaveToDisk)
{
	ADynamicMeshActor* Actor = FindModelActor(Name);
	UDynamicMesh* Mesh = GetDynamicMesh(Actor);
	if (!Mesh)
	{
		return FString();
	}

	int32 Triangles = 0;
	Mesh->ProcessMesh([&Triangles](const UE::Geometry::FDynamicMesh3& M) { Triangles = M.TriangleCount(); });
	if (Triangles == 0)
	{
		Fail(TEXT("The actor has no geometry to save."));
		return FString();
	}

	FString PackageName, AssetName, Error;
	if (!ParseGameAssetPath(AssetPath, PackageName, AssetName, Error))
	{
		Fail(Error);
		return FString();
	}

	FStaticMeshAssetOptions Options;
	Options.CollisionMode = Collision;
	Options.bEnableNanite = bEnableNanite;
	Options.bOverwrite = bOverwrite;
	Options.bSaveToDisk = bSaveToDisk;
	if (UDynamicMeshComponent* Component = Actor->GetDynamicMeshComponent())
	{
		for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
		{
			Options.Materials.Add(Component->GetMaterial(i));
		}
	}

	const FStaticMeshAssetResult Asset = WriteStaticMeshAsset(Mesh, PackageName, AssetName, Options);
	if (!Asset.StaticMesh)
	{
		Fail(Asset.Error);
		return FString();
	}
	if (bSaveToDisk && !Asset.bSaved)
	{
		Fail(Asset.Error);
	}

	// Optionally place a StaticMeshActor in the level.
	FString PlacedActorName;
	if (bPlaceInLevel)
	{
		if (UWorld* World = GetEditorWorld())
		{
			const FScopedTransaction Transaction(LOCTEXT("PlaceStaticMesh", "Modelling: Place Static Mesh"));
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			if (AStaticMeshActor* Placed = World->SpawnActor<AStaticMeshActor>(Actor->GetActorLocation(), Actor->GetActorRotation(), SpawnParams))
			{
				Placed->SetActorScale3D(Actor->GetActorScale3D());
				Placed->GetStaticMeshComponent()->SetStaticMesh(Asset.StaticMesh);
				FActorLabelUtilities::SetActorLabelUnique(Placed, AssetName);
				PlacedActorName = Placed->GetActorLabel();

				if (bDeleteSourceActor)
				{
					World->EditorDestroyActor(Actor, /*bShouldModifyLevel=*/true);
				}
			}
		}
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("asset_path"), PackageName + TEXT(".") + AssetName);
	Out->SetStringField(TEXT("status"), Asset.bCreated ? TEXT("created") : TEXT("overwritten"));
	Out->SetNumberField(TEXT("triangles"), Triangles);
	Out->SetStringField(TEXT("collision"), Collision.IsEmpty() ? FString(TEXT("none")) : Collision.ToLower());
	Out->SetBoolField(TEXT("nanite"), bEnableNanite);
	Out->SetBoolField(TEXT("saved_to_disk"), Asset.bSaved);
	Out->SetStringField(TEXT("placed_actor"), PlacedActorName);
	return ToJsonString(Out);
}

FString UModellingAssetToolset::ImportStaticMesh(const FString& AssetPath, const FString& Name)
{
	FString Path = AssetPath.TrimStartAndEnd();
	if ((!Path.StartsWith(TEXT("/Game/")) && !Path.StartsWith(TEXT("/Engine/"))) || Path.Contains(TEXT("..")))
	{
		Fail(TEXT("AssetPath must start with /Game/ or /Engine/ and must not contain '..'."));
		return FString();
	}
	if (!Path.Contains(TEXT(".")))
	{
		Path += TEXT(".") + FPackageName::GetShortName(Path);
	}

	UStaticMesh* StaticMesh = LoadObject<UStaticMesh>(nullptr, *Path);
	if (!StaticMesh)
	{
		Fail(FString::Printf(TEXT("No StaticMesh found at '%s'."), *Path));
		return FString();
	}

	const FScopedTransaction Transaction(LOCTEXT("ImportStaticMesh", "Modelling: Import Static Mesh"));
	ADynamicMeshActor* Actor = CreateMeshActor(Name.IsEmpty() ? StaticMesh->GetName() : Name, FVector::ZeroVector, FRotator::ZeroRotator);
	UDynamicMesh* Mesh = GetDynamicMesh(Actor);
	if (!Mesh)
	{
		return FString();
	}

	EGeometryScriptOutcomePins Outcome = EGeometryScriptOutcomePins::Failure;
	UGeometryScriptLibrary_StaticMeshFunctions::CopyMeshFromStaticMeshV2(
		StaticMesh, Mesh, FGeometryScriptCopyMeshFromAssetOptions(), FGeometryScriptMeshReadLOD(), Outcome, /*bUseSectionMaterials=*/true);
	if (Outcome != EGeometryScriptOutcomePins::Success)
	{
		Fail(TEXT("Could not read the StaticMesh geometry. The mesh may have no source or render data."));
		Actor->GetWorld()->EditorDestroyActor(Actor, /*bShouldModifyLevel=*/true);
		return FString();
	}

	if (UDynamicMeshComponent* Component = Actor->GetDynamicMeshComponent())
	{
		for (int32 i = 0; i < StaticMesh->GetStaticMaterials().Num(); ++i)
		{
			Component->SetMaterial(i, StaticMesh->GetMaterial(i));
		}
	}
	return ToJsonString(DescribeActor(Actor));
}

#undef LOCTEXT_NAMESPACE
