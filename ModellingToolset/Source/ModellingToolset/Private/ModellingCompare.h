// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

namespace ModellingToolset
{
	/** A black and white picture: 1 where the object is, 0 where the background is. */
	struct FMask
	{
		int32 Width = 0;
		int32 Height = 0;
		TArray<uint8> Data;

		bool IsInside(int32 X, int32 Y) const { return X >= 0 && Y >= 0 && X < Width && Y < Height; }
		uint8 Get(int32 X, int32 Y) const { return Data[Y * Width + X]; }
	};

	struct FCompareResult
	{
		bool bOk = false;
		FString Error;
		/** Side by side: reference, model, and an overlap map (grey = both, red = model only, blue = reference only). */
		TArray<FColor> Image;
		FIntPoint ImageSize = FIntPoint::ZeroValue;
		FString SummaryJson;
	};

	// ---- Building blocks (public so they can be tested without rendering) ----

	/** Object-versus-background mask. The background colour is estimated from the picture's border pixels. */
	FMask MakeMask(const TArray<FColor>& Pixels, FIntPoint Size, double Threshold, double* OutBorderSpread = nullptr);

	/**
	 * Drops pixels that look like a floor shadow (a slightly darker, uncoloured patch of a light background) from the mask.
	 * Returns how many were dropped. Does nothing on dark or strongly coloured backgrounds.
	 */
	int32 RemoveFloorShadow(FMask& Mask, const TArray<FColor>& Pixels, FIntPoint Size);

	/** Removes disconnected specks smaller than MinFraction of the object's area. */
	void RemoveSmallComponents(FMask& Mask, double MinFraction);

	/** Tight bounds of the object. False if the mask is empty. */
	bool MaskBounds(const FMask& Mask, FIntRect& OutBounds);

	/** Crops to Bounds and resamples (nearest) to a Size x Size square, so shape can be compared regardless of scale or position. */
	FMask NormaliseMask(const FMask& Mask, const FIntRect& Bounds, int32 Size);

	/** Fraction of the union that is also in the intersection. */
	double IntersectionOverUnion(const FMask& A, const FMask& B);

	struct FProfileDifference
	{
		/** Percent of the object's height (or width) from the top (or left) where the band starts and ends. */
		int32 FromPercent = 0;
		int32 ToPercent = 0;
		/** Model minus reference, as a percent of the object's full width (or height). Negative = model is smaller there. */
		double DifferencePercent = 0.0;
	};

	/** Compares how wide the two shapes are in horizontal bands from top to bottom. Returns bands that differ by more than Threshold (0..1). */
	TArray<FProfileDifference> CompareWidthBands(const FMask& Reference, const FMask& Model, int32 Bands, double Threshold);
	/** Same, but how tall the shapes are in vertical bands from left to right. */
	TArray<FProfileDifference> CompareHeightBands(const FMask& Reference, const FMask& Model, int32 Bands, double Threshold);

	/**
	 * Renders the model from an axis view and compares its silhouette with a reference picture.
	 * @param ReferenceName  File in the references folder.
	 * @param View           front, back, left, right, top or bottom. Empty uses the reference's label, or front.
	 * @param ActorNames     Comma separated actors to compare; empty uses every actor the toolset created.
	 */
	FCompareResult CompareToReference(const FString& ReferenceName, const FString& View, const FString& ActorNames);
}
