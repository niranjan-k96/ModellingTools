// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModellingSelection.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingEditToolset.generated.h"

/**
 * Mesh editing: face operations, booleans, mirroring, arrays, merging, pivots. Built on Geometry Script.
 * Every tool works on an actor created by this toolset, records undo, and returns the actor's updated JSON summary.
 * Positions and directions are in the actor's LOCAL space (cm) unless a tool says otherwise.
 *
 * Tip: call SaveCheckpoint before risky edits (booleans) so RestoreCheckpoint can undo them, and CaptureViews afterwards to check the result.
 */
UCLASS(MinimalAPI)
class UModellingEditToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Lists the polygroups of an actor (the faces of a primitive are separate groups) with triangle count, centre, size and average normal.
	 * Use the ids with selection mode "polygroup". At most 200 groups are returned.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString GetPolygroups(const FString& Name);

	/** Extrudes the selected faces.
	 * @param Name       Actor label.
	 * @param Distance   Extrusion distance in cm (positive moves outward along the direction).
	 * @param Selection  Which faces. Example: {"Mode":"normal","A":{"X":0,"Y":0,"Z":1},"Scalar":10} extrudes the top faces.
	 * @param Direction  World-independent local direction. Leave (0,0,0) to extrude along the average face normal. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString ExtrudeFaces(const FString& Name, float Distance, const FModellingSelection& Selection = FModellingSelection(), const FVector& Direction = FVector::ZeroVector);

	/** Insets the selected faces (shrinks each region inward, leaving a border). Often followed by ExtrudeFaces to make recesses or raised panels.
	 * @param Name       Actor label.
	 * @param Distance   Inset distance in cm, greater than 0.
	 * @param Selection  Which faces. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString InsetFaces(const FString& Name, float Distance, const FModellingSelection& Selection = FModellingSelection());

	/** Moves the selected faces along their normals by a parallel offset, keeping them attached to the rest of the mesh.
	 * @param Name       Actor label.
	 * @param Distance   Offset in cm (negative moves inward).
	 * @param Selection  Which faces. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString OffsetFaces(const FString& Name, float Distance, const FModellingSelection& Selection = FModellingSelection());

	/** Bevels every edge between polygroups (for a box, all 12 edges).
	 * @param Name          Actor label.
	 * @param Distance      Bevel width in cm. Keep it well below half the smallest dimension.
	 * @param Subdivisions  0 gives a flat chamfer, higher values give a rounded edge. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString BevelEdges(const FString& Name, float Distance, int32 Subdivisions = 0);

	/** Deletes the selected faces, leaving holes. Use FillHoles to close them.
	 * @param Name       Actor label.
	 * @param Selection  Which faces. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString DeleteFaces(const FString& Name, const FModellingSelection& Selection);

	/** Mirrors the mesh across a plane. Ideal for symmetric models: build one half, then mirror it to make the whole.
	 * The PlaneNormal points toward the half you BUILT (the half that is kept and copied). Example: you built the right half of a car on +Y,
	 * so use PlaneNormal (0,1,0) and the left half is created on -Y.
	 * @param Name           Actor label.
	 * @param PlaneOrigin    A point on the mirror plane, local space cm.
	 * @param PlaneNormal    Points toward the side you built. (1,0,0) mirrors across a YZ plane, copying the +X half to -X.
	 * @param bCutAtPlane    Cut away geometry that crosses the plane before mirroring (keeps only the normal side).
	 * @param bWeldSeam      Weld the vertices along the plane so the halves join. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString MirrorMesh(const FString& Name, const FVector& PlaneOrigin, const FVector& PlaneNormal, bool bCutAtPlane = true, bool bWeldSeam = true);

	/** Adds repeated copies of the actor's existing geometry. Each copy is the previous one moved by the step transform, so a
	 * Rotation makes a radial array (rotation is around the actor origin) and an Offset makes a linear array.
	 * @param Name      Actor label.
	 * @param Copies    Number of copies to add (1 to 200).
	 * @param Offset    Translation per step, local cm.
	 * @param Rotation  Rotation per step, degrees, around the actor origin.
	 * @param Scale     Scale per step. (1,1,1) keeps the size. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString ArrayCopies(const FString& Name, int32 Copies, const FVector& Offset, const FRotator& Rotation, const FVector& Scale);

	/** Boolean operation between two actors, using each actor's world transform. Make a cutter actor from primitives, then subtract it.
	 * @param Name         Target actor label; it receives the result.
	 * @param ToolName     Actor label of the tool shape.
	 * @param Operation    "union", "subtract" or "intersect".
	 * @param bDeleteTool  Delete the tool actor afterwards. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString BooleanOp(const FString& Name, const FString& ToolName, const FString& Operation, bool bDeleteTool = true);

	/** Cuts the mesh with a plane and removes one side. The PlaneNormal points toward the side you KEEP (same rule as MirrorMesh).
	 * Example: PlaneNormal (0,0,1) at Z=0 keeps everything above the plane and removes everything below.
	 * @param Name         Actor label.
	 * @param PlaneOrigin  A point on the plane, local cm.
	 * @param PlaneNormal  Points toward the side to keep.
	 * @param bFlipSide    Keep the opposite side instead.
	 * @param bFillHole    Cap the cut with a flat face. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString CutWithPlane(const FString& Name, const FVector& PlaneOrigin, const FVector& PlaneNormal, bool bFlipSide = false, bool bFillHole = true);

	/** Merges other actors into this one so they become a single mesh, preserving their world positions.
	 * @param Name             Target actor label.
	 * @param SourceNames      Comma-separated labels of actors to merge in.
	 * @param bDeleteSources   Delete the source actors afterwards. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString CombineActors(const FString& Name, const FString& SourceNames, bool bDeleteSources = true);

	/** Bakes a transform into the vertices (the actor transform is unchanged). Use it to offset, rotate or scale the geometry inside the actor.
	 * @param Name         Actor label.
	 * @param Translation  Local translation, cm.
	 * @param Rotation     Rotation in degrees about the actor origin.
	 * @param Scale        Scale about the actor origin. (1,1,1) keeps the size. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString TransformGeometry(const FString& Name, const FVector& Translation, const FRotator& Rotation, const FVector& Scale);

	/** Moves the actor's pivot to a point on the mesh bounds without moving the geometry in the world.
	 * @param Name   Actor label.
	 * @param Pivot  "center" (bounds centre), "base" (bottom centre) or "top" (top centre). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Edit")
	static MODELLINGTOOLSET_API FString SetPivot(const FString& Name, const FString& Pivot);
};
