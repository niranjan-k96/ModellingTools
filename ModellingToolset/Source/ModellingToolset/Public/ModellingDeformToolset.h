// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModellingSelection.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingDeformToolset.generated.h"

/**
 * Shape deformation: bend, twist, flare, noise, smoothing, subdivision. Built on Geometry Script.
 * Warps need enough triangles to look smooth: call Subdivide first on low-poly primitives.
 * Axis arguments are the long axis of the object being deformed, in the actor's local space.
 * Always verify the result with CaptureViews, since the warp direction depends on the axis you pass.
 */
UCLASS(MinimalAPI)
class UModellingDeformToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Bends the mesh along an axis, like bending a tree or a pipe.
	 * @param Name           Actor label.
	 * @param AngleDegrees   Bend angle in degrees. Positive curves the ends toward BendDirection, negative curves them away.
	 * @param Extent         Distance from Origin along the axis over which the bend happens, cm.
	 * @param Axis           Long axis of the object, local space. (0,0,1) for a vertical object.
	 * @param Origin         Point on the axis where the bend is centred, local cm.
	 * @param BendDirection  The direction the ends curve toward, local space. (1,0,0) bends toward +X. Must not be parallel to Axis. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Bend(const FString& Name, float AngleDegrees, float Extent, const FVector& Axis = FVector(0, 0, 1), const FVector& Origin = FVector::ZeroVector, const FVector& BendDirection = FVector(1, 0, 0));

	/** Twists the mesh around an axis.
	 * @param Name          Actor label.
	 * @param AngleDegrees  Twist angle in degrees at the end of the Extent.
	 * @param Extent        Distance from Origin along the axis over which the twist builds up, cm.
	 * @param Axis          Axis to twist around, local space.
	 * @param Origin        Centre of the twist, local cm. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Twist(const FString& Name, float AngleDegrees, float Extent, const FVector& Axis = FVector(0, 0, 1), const FVector& Origin = FVector::ZeroVector);

	/** Flares (widens) or pinches the mesh along an axis. Use for tapering towers, bottles and horns.
	 * For a vertical object (Axis (0,0,1)): FlareX changes the width along X and FlareY the width along Y.
	 * @param Name       Actor label.
	 * @param FlareX     Percent change of width along X at the far ends of Extent. Negative pinches.
	 * @param FlareY     Percent change of width along Y.
	 * @param Extent     Distance from Origin along the axis over which the flare builds up, cm.
	 * @param Axis       Long axis, local space.
	 * @param Origin     Where the flare starts, local cm. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Flare(const FString& Name, float FlareX, float FlareY, float Extent, const FVector& Axis = FVector(0, 0, 1), const FVector& Origin = FVector::ZeroVector);

	/** Displaces vertices along their normals with Perlin noise: rocks, terrain, rough surfaces. Subdivide first.
	 * @param Name        Actor label.
	 * @param Magnitude   Maximum displacement in cm.
	 * @param Frequency   Noise frequency; larger means finer detail.
	 * @param Seed        Random seed for repeatable results.
	 * @param Selection   Which faces to affect. Defaults to all. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Noise(const FString& Name, float Magnitude, float Frequency, int32 Seed = 0, const FModellingSelection& Selection = FModellingSelection());

	/** Smooths the surface by relaxing vertices.
	 * @param Name        Actor label.
	 * @param Iterations  Number of smoothing passes (1 to 100).
	 * @param Alpha       Strength per pass, 0 to 1.
	 * @param Selection   Which faces to affect. Defaults to all. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Smooth(const FString& Name, int32 Iterations = 10, float Alpha = 0.2f, const FModellingSelection& Selection = FModellingSelection());

	/** Uniformly subdivides every triangle, multiplying the triangle count by (Level+1)^2. Use before bending, twisting or adding noise.
	 * @param Name   Actor label.
	 * @param Level  Subdivision level (1 to 6). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Deform")
	static MODELLINGTOOLSET_API FString Subdivide(const FString& Name, int32 Level = 2);
};
