// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingSceneToolset.h"

#include "ModellingToolsetUtils.h"

#include "DynamicMeshActor.h"
#include "EngineUtils.h"
#include "ScopedTransaction.h"
#include "Serialization/JsonSerializer.h"

#define LOCTEXT_NAMESPACE "ModellingSceneToolset"

using namespace ModellingToolset;

FString UModellingSceneToolset::GetWorkspaceInfo()
{
	EnsureWorkspaceFolders();
	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("references_folder"), GetReferencesDir());
	Out->SetStringField(TEXT("progress_folder"), GetProgressDir());
	Out->SetStringField(TEXT("units"), TEXT("centimetres; rotation in degrees; +X forward, +Y right, +Z up"));
	return ToJsonString(Out);
}

FString UModellingSceneToolset::CreateMeshActor(const FString& Name, const FVector& Location, const FRotator& Rotation)
{
	const FScopedTransaction Transaction(LOCTEXT("CreateMeshActor", "Modelling: Create Mesh Actor"));
	ADynamicMeshActor* Actor = ModellingToolset::CreateMeshActor(Name, Location, Rotation);
	return Actor ? ToJsonString(DescribeActor(Actor)) : FString();
}

FString UModellingSceneToolset::ListMeshActors()
{
	UWorld* World = GetEditorWorld();
	if (!World)
	{
		Fail(TEXT("No editor world is available."));
		return FString();
	}

	TArray<TSharedPtr<FJsonValue>> Items;
	for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
	{
		TSharedRef<FJsonObject> Item = DescribeActor(*It);
		Item->SetBoolField(TEXT("created_by_modelling_toolset"), It->Tags.Contains(ActorTag));
		Items.Add(MakeShared<FJsonValueObject>(Item));
	}
	return ToJsonString(Items);
}

FString UModellingSceneToolset::GetMeshInfo(const FString& Name)
{
	ADynamicMeshActor* Actor = FindMeshActor(Name);
	if (!Actor)
	{
		Fail(FString::Printf(TEXT("No mesh actor named '%s'. Use ListMeshActors to see available names."), *Name));
		return FString();
	}
	return ToJsonString(DescribeActor(Actor));
}

FString UModellingSceneToolset::SetActorTransform(const FString& Name, const FVector& Location, const FRotator& Rotation, const FVector& Scale)
{
	const FScopedTransaction Transaction(LOCTEXT("SetActorTransform", "Modelling: Set Actor Transform"));
	ADynamicMeshActor* Actor = FindModelActor(Name);
	if (!Actor)
	{
		return FString();
	}
	Actor->Modify();
	Actor->SetActorTransform(FTransform(Rotation, Location, Scale));
	return ToJsonString(DescribeActor(Actor));
}

bool UModellingSceneToolset::DeleteActor(const FString& Name)
{
	const FScopedTransaction Transaction(LOCTEXT("DeleteActor", "Modelling: Delete Actor"));
	ADynamicMeshActor* Actor = FindModelActor(Name);
	return Actor && Actor->GetWorld()->EditorDestroyActor(Actor, /*bShouldModifyLevel=*/true);
}

int32 UModellingSceneToolset::DeleteAllModelActors()
{
	UWorld* World = GetEditorWorld();
	if (!World)
	{
		Fail(TEXT("No editor world is available."));
		return 0;
	}

	TArray<AActor*> ToDelete;
	for (TActorIterator<ADynamicMeshActor> It(World); It; ++It)
	{
		if (It->Tags.Contains(ActorTag))
		{
			ToDelete.Add(*It);
		}
	}

	const FScopedTransaction Transaction(LOCTEXT("DeleteAll", "Modelling: Delete All Model Actors"));
	int32 Count = 0;
	for (AActor* Actor : ToDelete)
	{
		if (World->EditorDestroyActor(Actor, /*bShouldModifyLevel=*/true))
		{
			++Count;
		}
	}
	return Count;
}

bool UModellingSceneToolset::SaveCheckpoint(const FString& Name, const FString& Label)
{
	ADynamicMeshActor* Actor = FindModelActor(Name);
	if (!Actor)
	{
		return false;
	}
	if (Label.TrimStartAndEnd().IsEmpty())
	{
		Fail(TEXT("Label must not be empty."));
		return false;
	}
	return ModellingToolset::SaveCheckpoint(Actor, Label);
}

FString UModellingSceneToolset::RestoreCheckpoint(const FString& Name, const FString& Label)
{
	const FScopedTransaction Transaction(LOCTEXT("RestoreCheckpoint", "Modelling: Restore Checkpoint"));
	ADynamicMeshActor* Actor = FindModelActor(Name);
	if (!Actor)
	{
		return FString();
	}
	if (UDynamicMesh* Mesh = GetDynamicMesh(Actor))
	{
		Actor->Modify();
		Mesh->SetFlags(RF_Transactional);
		Mesh->Modify();
	}
	if (!ModellingToolset::RestoreCheckpoint(Actor, Label))
	{
		Fail(FString::Printf(TEXT("No checkpoint '%s' for '%s'. Use ListCheckpoints."), *Label, *Name));
		return FString();
	}
	return ToJsonString(DescribeActor(Actor));
}

FString UModellingSceneToolset::RevertLastEdit(const FString& Name)
{
	const FScopedTransaction Transaction(LOCTEXT("RevertLastEdit", "Modelling: Revert Last Edit"));
	ADynamicMeshActor* Actor = FindModelActor(Name);
	if (!Actor)
	{
		return FString();
	}
	if (UDynamicMesh* Mesh = GetDynamicMesh(Actor))
	{
		Actor->Modify();
		Mesh->SetFlags(RF_Transactional);
		Mesh->Modify();
	}
	if (!RestoreLastEdit(Actor))
	{
		Fail(FString::Printf(TEXT("'%s' has no earlier edit to revert."), *Name));
		return FString();
	}
	return ToJsonString(DescribeActor(Actor));
}

FString UModellingSceneToolset::ListCheckpoints(const FString& Name)
{
	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FString& Entry : ModellingToolset::ListCheckpoints(Name))
	{
		Items.Add(MakeShared<FJsonValueString>(Entry));
	}
	return ToJsonString(Items);
}

#undef LOCTEXT_NAMESPACE
