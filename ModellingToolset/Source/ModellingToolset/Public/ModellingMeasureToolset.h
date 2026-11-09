// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingMeasureToolset.generated.h"

/**
 * Measuring tools, so real sizes in the notes ("the door is 2 metres tall") can be checked instead of eyeballed.
 * All values are world-space centimetres.
 */
UCLASS(MinimalAPI)
class UModellingMeasureToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Overall size of the whole model (or of chosen parts): width (X), depth (Y), height (Z), the lowest and highest points, and the centre.
	 * @param ActorNames  Comma-separated actor labels. Empty measures every actor the toolset created. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Measure")
	static MODELLINGTOOLSET_API FString MeasureModel(const FString& ActorNames = TEXT(""));

	/** Distance between two parts. Returns the shortest gap between their surfaces (0 if they touch or overlap), the distance between their centres,
	 * and the two closest points. Good for checking that parts connect or that spacing is right.
	 * @param NameA  First actor label.
	 * @param NameB  Second actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Measure")
	static MODELLINGTOOLSET_API FString MeasureDistance(const FString& NameA, const FString& NameB);

	/** Shoots a ray through the model and reports the first surface it hits: which part, where, the distance and the surface direction.
	 * Use it to measure heights and openings, for example shoot straight down from above a doorway and read the hit point's Z, or shoot sideways through a window.
	 * @param Origin       Ray start in world space.
	 * @param Direction    Ray direction (it is normalised for you).
	 * @param MaxDistance  How far to look, cm.
	 * @param ActorNames   Comma-separated actor labels to test. Empty tests every actor the toolset created. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Measure")
	static MODELLINGTOOLSET_API FString Raycast(const FVector& Origin, const FVector& Direction, float MaxDistance = 100000.f, const FString& ActorNames = TEXT(""));
};
