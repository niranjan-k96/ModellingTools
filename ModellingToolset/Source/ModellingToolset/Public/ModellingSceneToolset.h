// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingSceneToolset.generated.h"

/**
 * Scene management for procedural models: create, list, transform, inspect, checkpoint and delete
 * dynamic-mesh actors. All distances are in centimetres, rotations in degrees.
 * Every model part is an ADynamicMeshActor identified by its actor label.
 * Only actors created by this toolset can be modified or deleted.
 */
UCLASS(MinimalAPI)
class UModellingSceneToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Returns the folders used by this plugin as JSON: the references folder (where the user
	 * drops reference images) and the progress folder (where screenshots are saved).
	 * Call this first to learn where things live. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString GetWorkspaceInfo();

	/** Creates an empty dynamic-mesh actor to hold a model part.
	 * @param Name      Label for the actor. A numeric suffix is added if the name is taken, so read the returned "actor" field for the real name.
	 * @param Location  World location in cm.
	 * @param Rotation  World rotation in degrees (pitch, yaw, roll).
	 * @return JSON description of the new actor. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString CreateMeshActor(const FString& Name, const FVector& Location, const FRotator& Rotation);

	/** Lists every dynamic-mesh actor in the level as a JSON array with triangle counts and world bounds. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString ListMeshActors();

	/** Returns triangle/vertex counts, location, scale and world-space size of one actor, so dimensions can be verified.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString GetMeshInfo(const FString& Name);

	/** Sets the world transform of an actor created by this toolset.
	 * @param Name      Actor label.
	 * @param Location  World location in cm.
	 * @param Rotation  World rotation in degrees.
	 * @param Scale     World scale. (1,1,1) is unscaled. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString SetActorTransform(const FString& Name, const FVector& Location, const FRotator& Rotation, const FVector& Scale);

	/** Deletes one actor created by this toolset.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API bool DeleteActor(const FString& Name);

	/** Deletes every actor this toolset created (those tagged "ModellingToolset"). Other level content is untouched.
	 * @return Number of actors deleted. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API int32 DeleteAllModelActors();

	/** Saves a snapshot of an actor's geometry in memory so a risky edit (boolean, remesh, simplify) can be rolled back.
	 * Saving with an existing label replaces that checkpoint. The oldest checkpoints are dropped past the project limit.
	 * @param Name   Actor label.
	 * @param Label  Checkpoint name, e.g. "before_boolean". */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API bool SaveCheckpoint(const FString& Name, const FString& Label);

	/** Restores an actor's geometry to a saved checkpoint. The actor transform is not changed.
	 * @param Name   Actor label.
	 * @param Label  Checkpoint name used in SaveCheckpoint. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString RestoreCheckpoint(const FString& Name, const FString& Label);

	/** Undoes only the most recent edit made to a part (extrude, boolean, mirror, bend and so on), without needing a checkpoint.
	 * One level only: call it right after an edit that looks wrong. Edits that remove the whole mesh are undone automatically.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString RevertLastEdit(const FString& Name);

	/** Lists saved checkpoints as a JSON array of "actor/label" strings.
	 * @param Name  Actor label to filter by. Empty lists all. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Scene")
	static MODELLINGTOOLSET_API FString ListCheckpoints(const FString& Name);
};
