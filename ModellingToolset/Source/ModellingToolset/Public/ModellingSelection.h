// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "ModellingSelection.generated.h"

/**
 * Describes which faces (triangles) of a mesh an edit applies to.
 * All positions and directions are in the ACTOR'S LOCAL SPACE, in cm.
 *
 * Mode values:
 *   "all"       every face.
 *   "normal"    faces whose normal is within Scalar degrees of the direction A. Example: A=(0,0,1), Scalar=10 selects the top faces.
 *   "box"       faces fully inside the axis-aligned box with corners A and B.
 *   "sphere"    faces fully inside the sphere centred at A with radius Scalar.
 *   "polygroup" faces in polygroup PolygroupId (see GetPolygroups).
 */
USTRUCT(BlueprintType, MinimalAPI)
struct FModellingSelection
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Selection")
	FString Mode = TEXT("all");

	/** Direction for "normal", centre for "sphere", first box corner for "box". */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Selection")
	FVector A = FVector::ZeroVector;

	/** Second box corner for "box". */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Selection")
	FVector B = FVector::ZeroVector;

	/** Angle tolerance in degrees for "normal" (default 10), radius in cm for "sphere". */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Selection")
	float Scalar = 10.f;

	/** Polygroup id for "polygroup". */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Selection")
	int32 PolygroupId = 0;
};
