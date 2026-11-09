// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModellingSelection.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingMaterialsToolset.generated.h"

/**
 * Colours and materials. Read the real colours from a reference image, turn them into reusable material instances,
 * and put them on a whole part or on selected faces (a red roof on a white tower).
 * Colours are written as hex text like "#C03A2B". Materials are saved under /Game/ModellingToolset/Materials/.
 * Material instances are made from one shared base material that has Color, Roughness, Metallic and Emissive controls.
 */
UCLASS(MinimalAPI)
class UModellingMaterialsToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Finds the main colours in a reference image, so you can match them instead of guessing. Returns JSON: the dominant colours as hex with the
	 * percentage of the picture each covers (largest first), plus the average colour. Use a region to sample one part of the picture, for example just the roof.
	 * @param Name              Reference file name from ListReferences.
	 * @param ColorCount        How many colours to return (2 to 8).
	 * @param bIgnoreBackground Ignore the plain background (estimated from the picture edges) so only the object is analysed.
	 * @param RegionX           Left edge of the region, 0 to 1 (0 = left of the picture).
	 * @param RegionY           Top edge of the region, 0 to 1 (0 = top).
	 * @param RegionWidth       Width of the region, 0 to 1. 1 means the full width.
	 * @param RegionHeight      Height of the region, 0 to 1. 1 means the full height. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString GetReferencePalette(const FString& Name, int32 ColorCount = 5, bool bIgnoreBackground = true, float RegionX = 0.f, float RegionY = 0.f, float RegionWidth = 1.f, float RegionHeight = 1.f);

	/** Creates (or updates) a reusable material of one colour and returns its asset path.
	 * @param MaterialName     Short name, e.g. "RedRoof". The asset becomes MI_<name>.
	 * @param Hex              Colour like "#C03A2B" (sRGB, as read from a picture).
	 * @param Roughness        0 = mirror smooth, 1 = fully matte.
	 * @param Metallic         0 = plastic, stone or wood, 1 = bare metal.
	 * @param EmissiveStrength 0 for none; above 0 makes it glow in its own colour (lamps, windows at night). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString CreateColorMaterial(const FString& MaterialName, const FString& Hex, float Roughness = 0.6f, float Metallic = 0.f, float EmissiveStrength = 0.f);

	/** Paints a whole part one colour. Creates the material if needed and puts it on every face (slot 0).
	 * @param Name         Actor label.
	 * @param Hex          Colour like "#FFFFFF".
	 * @param Roughness    0 smooth to 1 matte.
	 * @param Metallic     0 to 1.
	 * @param MaterialName Optional name for the material. Empty uses the part name and colour. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString PaintPart(const FString& Name, const FString& Hex, float Roughness = 0.6f, float Metallic = 0.f, const FString& MaterialName = TEXT(""));

	/** Paints only the selected faces, adding a new material slot for the colour. Use it for details like a red roof, a dark door or window glass.
	 * @param Name         Actor label.
	 * @param Selection    Which faces. Example: top faces {"Mode":"normal","A":{"X":0,"Y":0,"Z":1},"Scalar":10}.
	 * @param Hex          Colour like "#C03A2B".
	 * @param Roughness    0 smooth to 1 matte.
	 * @param Metallic     0 to 1.
	 * @param MaterialName Optional name for the material. Empty uses the part name and colour. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString PaintFaces(const FString& Name, const FModellingSelection& Selection, const FString& Hex, float Roughness = 0.6f, float Metallic = 0.f, const FString& MaterialName = TEXT(""));

	/** Puts an existing material (yours or the engine's) in a slot of a part.
	 * @param Name          Actor label.
	 * @param SlotIndex     Material slot number, 0 or higher (see ListMaterialSlots).
	 * @param MaterialPath  Asset path, e.g. "/Game/Materials/M_Brick" or "/Engine/BasicShapes/BasicShapeMaterial". */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString AssignMaterial(const FString& Name, int32 SlotIndex, const FString& MaterialPath);

	/** Lists a part's material slots as JSON: slot number, material asset path and how many faces use it. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Materials")
	static MODELLINGTOOLSET_API FString ListMaterialSlots(const FString& Name);

	/** The shared parent material (Color, Roughness, Metallic, Emissive controls). Created on first use. Not an AI tool. */
	static MODELLINGTOOLSET_API class UMaterial* GetBaseMaterial(FString& OutError);

	/**
	 * The master material for textures. bWorldAligned = textures laid on by world position (never stretches, no UVs needed);
	 * otherwise textures follow the part's UV map, one tile per 100 cm of UV space (see AutoUV). Created on first use. Not an AI tool.
	 * Parameters: AlbedoTexture, NormalTexture, RoughnessTexture, MetallicTexture, TileCm, Tint, Roughness, Metallic,
	 * and the switches UseNormalTexture, UseRoughnessTexture, UseMetallicTexture.
	 */
	static MODELLINGTOOLSET_API class UMaterial* GetTexturedMasterMaterial(bool bWorldAligned, FString& OutError);

	/** Describes one set of texture images for a surface. Only Albedo is required. */
	struct FTextureSet
	{
		FString Name;
		class UTexture2D* Albedo = nullptr;
		class UTexture2D* Normal = nullptr;
		class UTexture2D* Roughness = nullptr;
		class UTexture2D* Metallic = nullptr;
		/** Packed map: red = occlusion, green = roughness, blue = metallic (the Megascans "ORM" convention). Used instead of Roughness/Metallic when set. */
		class UTexture2D* PackedORM = nullptr;
	};

	/** How a textured surface should look. */
	struct FSurfaceLook
	{
		float TileCm = 100.f;
		bool bWorldAligned = true;
		FLinearColor Tint = FLinearColor::White;
		/** Remaps the roughness texture into this range (packed maps only). 0..1 keeps it as authored. */
		float RoughnessMin = 0.f;
		float RoughnessMax = 1.f;
		/** -1 keeps the texture; 0..1 forces a value. */
		float RoughnessOverride = -1.f;
		float MetallicOverride = -1.f;
		/** Optional instance name; otherwise derived from the set, mode, tile and tint. */
		FString InstanceName;
	};

	/** Makes (or updates) a saved material instance of the textured master for a texture set. Not an AI tool. */
	static MODELLINGTOOLSET_API class UMaterialInstanceConstant* GetOrCreateTexturedInstance(
		const FTextureSet& Set, float TileCm, bool bWorldAligned, const FLinearColor& Tint, float RoughnessOverride, float MetallicOverride, FString& OutError);

	/** Same, with the full set of look controls. Not an AI tool. */
	static MODELLINGTOOLSET_API class UMaterialInstanceConstant* GetOrCreateTexturedInstance(const FTextureSet& Set, const FSurfaceLook& Look, FString& OutError);

	/** The plugin's own glass master (translucent, with Color, Opacity, Roughness and IOR controls). Created on first use. Not an AI tool. */
	static MODELLINGTOOLSET_API class UMaterial* GetGlassMaterial(FString& OutError);
};
