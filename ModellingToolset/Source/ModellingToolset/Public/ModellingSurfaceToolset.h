// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModellingSelection.h"
#include "ModellingVisionToolset.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingSurfaceToolset.generated.h"

/**
 * Surface library (Fab and Megascans downloads) with closeness matching, and glass.
 *
 * Every library surface is three textures (colour, normal, packed occlusion/roughness/metallic). The plugin lays them on with
 * its own master material, world-aligned by default so they never stretch, and tweaks tint and roughness to match the reference
 * before applying. Use FindClosestSurface first: it ranks the library by the words you give (brick, plaster, roof tiles) and by
 * colour, and tells you whether the best match is good enough. Only paint a flat colour when it says no usable match exists.
 */
UCLASS(MinimalAPI)
class UModellingSurfaceToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Lists every surface in the library folders as JSON: name, category, average colour (hex), which maps it has.
	 * The first call can take a while, because the average colours are measured from the textures and then cached.
	 * @param Filter  Optional word to match in the name or category. Empty lists everything. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FString ListSurfaces(const FString& Filter = TEXT(""));

	/** Ranks the library surfaces for what you need. Words matter most (a tint can change colour but cannot turn wood into brick).
	 * Returns JSON: ranked candidates with a score, why they matched, the tint that would make each match the target colour,
	 * and "use_flat_color": true when nothing in the library is suitable.
	 * @param Description  What the surface is, in plain words from the reference: "worn red brick wall", "white plaster", "terracotta roof tiles".
	 * @param TargetHex    The colour it should end up, from GetReferencePalette, e.g. "#B04A3A". Empty to ignore colour.
	 * @param MaxResults   How many candidates to return (1 to 10). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FString FindClosestSurface(const FString& Description, const FString& TargetHex = TEXT(""), int32 MaxResults = 5);

	/** Renders a sphere and a cube with a library surface, tweaked to a target colour and finish, so you can check the look before applying it.
	 * @param Surface    Surface name from ListSurfaces or FindClosestSurface.
	 * @param TargetHex  Colour to match, or empty to keep the surface's own colour.
	 * @param Finish     "auto" keeps the surface's roughness; "matte", "satin" or "glossy" force a range.
	 * @param TileCm     Real size of one tile in cm. 0 uses the project default (200 cm for Megascans). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FModellingCapture PreviewSurface(const FString& Surface, const FString& TargetHex = TEXT(""), const FString& Finish = TEXT("auto"), float TileCm = 0.f);

	/** Puts a library surface on a whole part, tinted so its average colour matches TargetHex and with the requested finish.
	 * @param Name           Actor label.
	 * @param Surface        Surface name from ListSurfaces or FindClosestSurface.
	 * @param TargetHex      Colour to match (from the reference), or empty to keep the surface's own colour.
	 * @param Finish         "auto", "matte", "satin" or "glossy".
	 * @param TileCm         Real size of one tile in cm. 0 uses the project default.
	 * @param bWorldAligned  True (default): laid on by world position, never stretches. False: follows the UV map (run AutoUV first). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FString ApplySurfacePart(const FString& Name, const FString& Surface, const FString& TargetHex = TEXT(""), const FString& Finish = TEXT("auto"), float TileCm = 0.f, bool bWorldAligned = true);

	/** Puts a library surface on the selected faces only (roof tiles on the top, stone on the base).
	 * @param Name           Actor label.
	 * @param Selection      Which faces. Example: {"Mode":"normal","A":{"X":0,"Y":0,"Z":1},"Scalar":10} for the top.
	 * @param Surface        Surface name.
	 * @param TargetHex      Colour to match, or empty.
	 * @param Finish         "auto", "matte", "satin" or "glossy".
	 * @param TileCm         Real size of one tile in cm. 0 uses the project default.
	 * @param bWorldAligned  True: by world position. False: follows the UV map. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FString ApplySurfaceFaces(const FString& Name, const FModellingSelection& Selection, const FString& Surface, const FString& TargetHex = TEXT(""), const FString& Finish = TEXT("auto"), float TileCm = 0.f, bool bWorldAligned = true);

	/** Makes selected faces (or the whole part) glass: windows, lantern rooms, bottles. Uses the Megascans glass material when the project
	 * has it, otherwise the plugin's own glass.
	 * @param Name       Actor label.
	 * @param Selection  Which faces. Mode "all" (default) makes the whole part glass.
	 * @param TintHex    Glass colour, e.g. "#DDEEFF" for a faint blue. "#FFFFFF" is clear.
	 * @param Opacity    0 = fully see-through, 1 = solid. Window glass is about 0.1 to 0.3.
	 * @param Roughness  0 = polished, 1 = frosted.
	 * @param IOR        Bending of light through the glass. 1.52 is normal glass, 1.0 is none. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Surfaces")
	static MODELLINGTOOLSET_API FString ApplyGlass(const FString& Name, const FModellingSelection& Selection = FModellingSelection(), const FString& TintHex = TEXT("#FFFFFF"), float Opacity = 0.15f, float Roughness = 0.05f, float IOR = 1.52f);
};
