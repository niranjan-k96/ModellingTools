// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingAssetToolset.generated.h"

/**
 * Turns models into real, reusable assets. Dynamic mesh actors live only in the level; saving them to a
 * StaticMesh asset makes the model persistent, instanceable, and usable in Blueprints, packaged builds and other levels.
 * Asset paths must be under /Game/.
 */
UCLASS(MinimalAPI)
class UModellingAssetToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Saves a model actor's geometry as a StaticMesh asset. The asset pivot is the actor's origin, so call SetPivot first if
	 * the model should sit on a different point (for example "base" for something that stands on the ground).
	 * Materials assigned to the actor are copied to the asset's slots.
	 *
	 * @param Name                  Actor label of the model to save.
	 * @param AssetPath             Content path, e.g. "/Game/Models/Lighthouse". The last segment is the asset name.
	 * @param bOverwrite            Replace the asset if it already exists. If false and it exists, the call fails.
	 * @param Collision             "none", "auto" (best-fit simple shapes), "box", "convex" (single convex hull) or "complex" (use the render mesh as collision).
	 * @param bEnableNanite         Enable Nanite on the asset. Best for high-triangle models; leave off for simple props.
	 * @param bPlaceInLevel         Also place a StaticMeshActor using the asset at the model's transform.
	 * @param bDeleteSourceActor    With bPlaceInLevel, delete the dynamic mesh actor afterwards so the level shows only the saved asset.
	 * @param bSaveToDisk           Write the .uasset to disk. If false, the asset exists only in memory until saved from the editor.
	 * @return JSON: asset_path, whether it was created or overwritten, triangle count, collision and Nanite settings, placed actor name. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Asset")
	static MODELLINGTOOLSET_API FString SaveToStaticMesh(
		const FString& Name,
		const FString& AssetPath,
		bool bOverwrite = false,
		const FString& Collision = TEXT("auto"),
		bool bEnableNanite = false,
		bool bPlaceInLevel = false,
		bool bDeleteSourceActor = false,
		bool bSaveToDisk = true);

	/** Loads an existing StaticMesh asset into a new editable model actor, so saved or imported meshes can be modified further.
	 * Materials from the asset are applied to the actor.
	 * @param AssetPath  Content path of the StaticMesh, e.g. "/Game/Models/Lighthouse" or "/Engine/BasicShapes/Cube".
	 * @param Name       Label for the new actor.
	 * @return JSON description of the new actor. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Asset")
	static MODELLINGTOOLSET_API FString ImportStaticMesh(const FString& AssetPath, const FString& Name);
};
