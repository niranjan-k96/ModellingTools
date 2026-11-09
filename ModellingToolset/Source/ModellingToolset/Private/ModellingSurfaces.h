// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UTexture2D;

namespace ModellingToolset
{
	/** One surface from a library folder (a Fab or Megascans download): its textures and what it looks like. */
	struct FSurfaceEntry
	{
		/** Readable name, e.g. "Brick Wall Worn". */
		FString Name;
		/** Folder key, e.g. "Brick_Wall_Worn_sexkaitb". */
		FString Key;
		FString Folder;
		FString Category;
		FString AlbedoPath, NormalPath, PackedPath, HeightPath, InstancePath;
		/** Average colour of the colour texture, sRGB. */
		FColor AverageColour = FColor(128, 128, 128);
		bool bHasAverageColour = false;
		TArray<FString> Words;
	};

	/** Scans the configured library folders. Average colours are computed once and cached on disk. */
	TArray<FSurfaceEntry> BuildSurfaceCatalogue(bool bComputeColours = true);

	/** Finds one entry by name or key (case-insensitive, spaces and underscores interchangeable). */
	const FSurfaceEntry* FindSurface(const TArray<FSurfaceEntry>& Catalogue, const FString& NameOrKey);

	/** A ranked candidate. */
	struct FSurfaceMatch
	{
		const FSurfaceEntry* Entry = nullptr;
		double Score = 0.0;        // 0..1
		double WordScore = 0.0;    // 0..1, how well the description matches the surface's name and category
		double ColourScore = 0.0;  // 0..1, how close the average colour is to the target (0.5 when no target)
		FString Why;
	};

	/**
	 * Ranks surfaces for a description ("worn red brick wall") and an optional target colour.
	 * Words count more than colour, because a tint can shift colour but cannot turn wood into brick.
	 */
	TArray<FSurfaceMatch> RankSurfaces(const TArray<FSurfaceEntry>& Catalogue, const FString& Description, const FString& TargetHex, int32 MaxResults);

	/** True when the best match is good enough to use instead of a flat colour. */
	bool IsUsableMatch(const FSurfaceMatch& Match);

	/** The tint that makes a surface's average colour match a target colour (linear, per channel, clamped). */
	FLinearColor TintToMatch(const FColor& AverageSRGB, const FColor& TargetSRGB);

	/** Average colour of a texture's source pixels, sRGB. Returns false if the source cannot be read. */
	bool ComputeTextureAverageColour(UTexture2D* Texture, FColor& OutColour);

	/** Guesses a category from a name: brick, wood, metal, stone, concrete, plaster, glass, tile, roof, fabric, ground, water, paint, plastic, snow, grass, marble, other. */
	FString GuessSurfaceCategory(const FString& Name);
}
