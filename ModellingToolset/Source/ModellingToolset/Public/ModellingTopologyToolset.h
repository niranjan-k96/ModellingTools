// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingTopologyToolset.generated.h"

/**
 * Mesh topology and repair: remeshing, simplification, hole filling, welding, cleanup and normals.
 * Run these after booleans and deformations to get a clean, game-ready mesh.
 * Every tool works on an actor created by this toolset and returns its updated JSON summary.
 */
UCLASS(MinimalAPI)
class UModellingTopologyToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Rebuilds the mesh with evenly sized triangles. Good after booleans or heavy deformation. Destroys polygroup structure and UV seams.
	 * @param Name                 Actor label.
	 * @param TargetTriangleCount  Approximate triangle count to aim for (100 to 500000). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString UniformRemesh(const FString& Name, int32 TargetTriangleCount);

	/** Reduces the triangle count while preserving the shape.
	 * @param Name                 Actor label.
	 * @param TargetTriangleCount  Triangle count to reduce to (minimum 4). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString Simplify(const FString& Name, int32 TargetTriangleCount);

	/** Closes open boundaries (holes) in the mesh. Returns the actor summary plus how many holes were filled or failed.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString FillHoles(const FString& Name);

	/** Removes disconnected fragments smaller than a triangle count.
	 * @param Name              Actor label.
	 * @param MinTriangleCount  Components with fewer triangles are removed. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString RemoveSmallParts(const FString& Name, int32 MinTriangleCount = 10);

	/** Welds coincident open edges, joining parts that touch.
	 * @param Name       Actor label.
	 * @param Tolerance  Maximum gap to weld, cm. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString WeldEdges(const FString& Name, float Tolerance = 0.01f);

	/** Removes interior and occluded faces that can never be seen, for example after combining overlapping parts.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString RemoveHiddenFaces(const FString& Name);

	/** Unions overlapping shells inside one mesh into a single clean surface. Use after CombineActors when parts intersect.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString MergeOverlaps(const FString& Name);

	/** Recomputes vertex normals from the geometry. Fixes odd shading after edits.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString RecomputeNormals(const FString& Name);

	/** Flips every face, turning the mesh inside out. Use when a model looks dark or see-through from the outside.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString FlipNormals(const FString& Name);

	/** Repairs or removes degenerate (zero-area) triangles.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString RepairDegenerate(const FString& Name);

	/** Removes unused vertices and compacts the mesh storage.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Topology")
	static MODELLINGTOOLSET_API FString CompactMesh(const FString& Name);
};
