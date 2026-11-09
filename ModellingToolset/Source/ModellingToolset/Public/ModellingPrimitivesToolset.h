// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingPrimitivesToolset.generated.h"

/**
 * Appends primitive shapes to a mesh actor using Geometry Script.
 * The actor must already exist (CreateMeshActor), unless bCreateIfMissing is true, which creates it at the origin.
 * Primitives are centred on Location, which is in the actor's LOCAL space (cm). Rotation is local, in degrees.
 * Combine several primitives in one actor to build a single mesh, or use separate actors per part.
 */
UCLASS(MinimalAPI)
class UModellingPrimitivesToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Adds a box.
	 * @param Name               Target actor label.
	 * @param Size               Full size in cm along X, Y, Z.
	 * @param Location           Box centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddBox(const FString& Name, const FVector& Size, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing = false);

	/** Adds a UV-sphere.
	 * @param Name               Target actor label.
	 * @param Radius             Radius in cm.
	 * @param Location           Sphere centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param Segments           Longitudinal segments (3 to 128). Latitude segments are Segments/2.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddSphere(const FString& Name, float Radius, const FVector& Location, const FRotator& Rotation, int32 Segments = 24, bool bCreateIfMissing = false);

	/** Adds a cylinder whose axis is local Z.
	 * @param Name               Target actor label.
	 * @param Radius             Radius in cm.
	 * @param Height             Height in cm.
	 * @param Location           Cylinder centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param Segments           Radial segments (3 to 128).
	 * @param bCapped            Whether the end caps are closed.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddCylinder(const FString& Name, float Radius, float Height, const FVector& Location, const FRotator& Rotation, int32 Segments = 24, bool bCapped = true, bool bCreateIfMissing = false);

	/** Adds a cone or truncated cone (frustum) whose axis is local Z.
	 * @param Name               Target actor label.
	 * @param BaseRadius         Radius at the bottom, cm.
	 * @param TopRadius          Radius at the top, cm. 0 gives a sharp cone.
	 * @param Height             Height in cm.
	 * @param Location           Centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param Segments           Radial segments (3 to 128).
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddCone(const FString& Name, float BaseRadius, float TopRadius, float Height, const FVector& Location, const FRotator& Rotation, int32 Segments = 24, bool bCreateIfMissing = false);

	/** Adds a capsule whose axis is local Z.
	 * @param Name               Target actor label.
	 * @param Radius             Radius in cm.
	 * @param LineLength         Length of the straight section in cm (total height is LineLength + 2*Radius).
	 * @param Location           Centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddCapsule(const FString& Name, float Radius, float LineLength, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing = false);

	/** Adds a torus lying in the local XY plane.
	 * @param Name               Target actor label.
	 * @param MajorRadius        Distance from the torus centre to the tube centre, cm.
	 * @param MinorRadius        Tube radius, cm.
	 * @param Location           Centre in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param MajorSteps         Segments around the ring (3 to 128).
	 * @param MinorSteps         Segments around the tube (3 to 64).
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddTorus(const FString& Name, float MajorRadius, float MinorRadius, const FVector& Location, const FRotator& Rotation, int32 MajorSteps = 32, int32 MinorSteps = 12, bool bCreateIfMissing = false);

	/** Spins an outline around the vertical axis to make round objects: vases, bottles, towers, domes, columns, bowls, lamp shades.
	 * Give the profile as (radius, height) points from bottom to top, describing the shape of one side. Example vase: [(0,0),(30,0),(40,40),(25,90),(15,110),(18,120)].
	 * @param Name               Target actor label.
	 * @param Profile            Points as X = distance from the axis (cm, 0 or more), Y = height (cm). At least 2 points.
	 * @param Location           Position in actor-local space, cm. The profile's height 0 sits at Location.
	 * @param Rotation           Local rotation in degrees.
	 * @param Degrees            How far to spin: 360 is a full turn, less leaves a wedge.
	 * @param Steps              Segments around the turn (3 to 128).
	 * @param bCapped            Close the ends when the profile does not reach the axis.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddRevolve(const FString& Name, const TArray<FVector2D>& Profile, const FVector& Location, const FRotator& Rotation, float Degrees = 360.f, int32 Steps = 32, bool bCapped = true, bool bCreateIfMissing = false);

	/** Pulls a flat outline straight up into a solid: floor plans, walls with odd shapes, L-shaped buildings, gears, signs.
	 * @param Name               Target actor label.
	 * @param Outline            Corner points of the shape as X, Y in cm, in order around the edge (at least 3). Either direction works.
	 * @param Height             How tall to make it, cm.
	 * @param Location           Centre of the solid in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddExtrudedPolygon(const FString& Name, const TArray<FVector2D>& Outline, float Height, const FVector& Location, const FRotator& Rotation, bool bCreateIfMissing = false);

	/** Adds a straight staircase. It climbs along +X and rises along +Z.
	 * @param Name               Target actor label.
	 * @param NumSteps           Number of steps (1 to 100).
	 * @param StepWidth          Width of the staircase across Y, cm.
	 * @param StepHeight         Rise of each step, cm.
	 * @param StepDepth          Run of each step, cm.
	 * @param Location           Position of the bottom front of the stairs, actor-local cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param bFloating          Floating steps with no solid underside.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddStairs(const FString& Name, int32 NumSteps, float StepWidth, float StepHeight, float StepDepth, const FVector& Location, const FRotator& Rotation, bool bFloating = false, bool bCreateIfMissing = false);

	/** Adds a curved (spiral-style) staircase.
	 * @param Name               Target actor label.
	 * @param NumSteps           Number of steps (1 to 100).
	 * @param StepWidth          Width of the stairs, cm.
	 * @param StepHeight         Rise of each step, cm.
	 * @param InnerRadius        Radius of the inside edge, cm.
	 * @param CurveAngle         Total turn in degrees (90 is a quarter turn, 360 a full spiral).
	 * @param Location           Position of the bottom of the stairs, actor-local cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param bFloating          Floating steps with no solid underside.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddCurvedStairs(const FString& Name, int32 NumSteps, float StepWidth, float StepHeight, float InnerRadius, float CurveAngle, const FVector& Location, const FRotator& Rotation, bool bFloating = false, bool bCreateIfMissing = false);

	/** Adds an arch with an opening: doorways, windows, bridges, gates. The arch stands in the XZ plane (width along X, height along Z, thickness along Y).
	 * @param Name               Target actor label.
	 * @param OuterWidth         Full outside width, cm.
	 * @param TotalHeight        Full height from the ground to the top of the curve, cm.
	 * @param Depth              Thickness of the wall, along Y, cm.
	 * @param BandWidth          Thickness of the arch band on each side and over the top, cm (less than half of OuterWidth).
	 * @param Location           Centre of the arch's bounding box in actor-local space, cm.
	 * @param Rotation           Local rotation in degrees.
	 * @param Segments           Smoothness of the curve (4 to 64).
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddArch(const FString& Name, float OuterWidth, float TotalHeight, float Depth, float BandWidth, const FVector& Location, const FRotator& Rotation, int32 Segments = 16, bool bCreateIfMissing = false);

	/** Drags a cross-section along a path to make pipes, railings, cables, beams, rails and ropes.
	 * @param Name               Target actor label.
	 * @param Profile            Cross-section corner points as X, Y in cm (at least 3). A circle needs about 8 or more points.
	 * @param Path               Points the section travels through, actor-local cm (at least 2).
	 * @param bLoop              Connect the last path point back to the first (rings, frames).
	 * @param bCapped            Close the two ends.
	 * @param bCreateIfMissing   Create the actor if it does not exist. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Primitives")
	static MODELLINGTOOLSET_API FString AddSweep(const FString& Name, const TArray<FVector2D>& Profile, const TArray<FVector>& Path, bool bLoop = false, bool bCapped = true, bool bCreateIfMissing = false);
};
