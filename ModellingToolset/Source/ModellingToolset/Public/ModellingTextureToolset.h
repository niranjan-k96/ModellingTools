// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModellingSelection.h"
#include "ModellingVisionToolset.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingTextureToolset.generated.h"

/**
 * Real surfaces instead of flat colours: texture images the user drops in a folder, and ready-made materials from a library folder.
 *
 * Textures folder: the user adds images named by set and type, e.g. Brick_albedo.png (required), Brick_normal.png,
 * Brick_roughness.png, Brick_metallic.png. An optional Brick.txt can hold "tile_cm: 60" (real size of one tile) and a description.
 * They are imported automatically and applied through the plugin's master material.
 *
 * World-aligned mode (the default) lays the texture on by real-world position, so it never stretches and tiles the same on every
 * part, whatever was cut, bent or merged. It needs no UV map. For a model that will be exported, run AutoUV before Done so the
 * FBX carries a proper texture layout as well.
 */
UCLASS(MinimalAPI)
class UModellingTextureToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Lists the texture sets found in the textures folder as JSON: name, which maps exist (normal, roughness, metallic), tile size in cm,
	 * notes, and whether it is imported yet. Also tells you the folder path and the naming rule, so you can ask the user for a missing texture. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ListTextureSets();

	/** Imports (or re-imports) every image in the textures folder as texture assets. Normally not needed: ApplyTexture imports what it uses.
	 * @param bReimport  Re-import sets that were imported before, for example after the user replaced an image. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ImportTextureSets(bool bReimport = false);

	/** Puts a texture set on a whole part.
	 * @param Name           Actor label.
	 * @param SetName        Texture set name from ListTextureSets, e.g. "Brick".
	 * @param TileCm         Real size of one texture tile in cm. 0 uses the set's tile_cm, or the project default.
	 * @param bWorldAligned  True (default): texture by world position, never stretches, no UVs needed. False: follow the part's UV map (run AutoUV first).
	 * @param TintHex        Optional colour multiplied into the texture, e.g. "#D8C8B0" to warm it. Empty for none.
	 * @param Roughness      0 to 1 to force a value, or -1 to use the set's roughness texture (or 0.6 if it has none).
	 * @param Metallic       0 to 1 to force a value, or -1 to use the set's metallic texture (or 0 if it has none). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ApplyTexturePart(const FString& Name, const FString& SetName, float TileCm = 0.f, bool bWorldAligned = true, const FString& TintHex = TEXT(""), float Roughness = -1.f, float Metallic = -1.f);

	/** Puts a texture set on the selected faces only, e.g. roof tiles on the top faces.
	 * @param Name           Actor label.
	 * @param Selection      Which faces. Example: {"Mode":"normal","A":{"X":0,"Y":0,"Z":1},"Scalar":10} for the top.
	 * @param SetName        Texture set name from ListTextureSets.
	 * @param TileCm         Real size of one tile in cm. 0 uses the set's tile_cm or the project default.
	 * @param bWorldAligned  True: by world position (never stretches). False: follow the UV map.
	 * @param TintHex        Optional tint colour. Empty for none.
	 * @param Roughness      0 to 1 to force, or -1 for the texture or default.
	 * @param Metallic       0 to 1 to force, or -1 for the texture or default. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ApplyTextureFaces(const FString& Name, const FModellingSelection& Selection, const FString& SetName, float TileCm = 0.f, bool bWorldAligned = true, const FString& TintHex = TEXT(""), float Roughness = -1.f, float Metallic = -1.f);

	/** Lists ready-made materials in the material library folder (see settings) as JSON: name, asset path, a guessed category from the name
	 * (brick, wood, metal, stone, glass, ...), and the name of a tiling parameter if the material exposes one.
	 * @param Filter  Optional word to match in the name, e.g. "brick". Empty lists everything (up to 300). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ListLibraryMaterials(const FString& Filter = TEXT(""));

	/** Puts a ready-made material on a whole part or on selected faces. Library materials follow the part's UV map and their own tiling,
	 * so run AutoUV on the part first to keep them from stretching.
	 * @param Name          Actor label.
	 * @param MaterialPath  Asset path from ListLibraryMaterials.
	 * @param Selection     Which faces. Mode "all" (default) covers the whole part. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString ApplyLibraryMaterial(const FString& Name, const FString& MaterialPath, const FModellingSelection& Selection = FModellingSelection());

	/** Renders a sphere and a cube with a texture set or a library material, so you can choose by look. Returns a picture and the saved file path.
	 * Give either SetName or MaterialPath.
	 * @param SetName       Texture set name, or empty.
	 * @param MaterialPath  Library material asset path, or empty.
	 * @param TileCm        Tile size for a texture set. 0 uses the set's own. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FModellingCapture PreviewMaterial(const FString& SetName = TEXT(""), const FString& MaterialPath = TEXT(""), float TileCm = 0.f);

	/** Generates a texture layout (UV map) for a part so textures do not stretch: one UV unit per 100 cm of surface, the same on every part.
	 * Needed for library materials, for UV-mode textures, and before export. Run it after the shape is finished, since edits change the surface.
	 * @param Name       Actor label.
	 * @param Method     "box" (default; best for walls, furniture, buildings), "cylinder" (round things: towers, pipes, bottles),
	 *                   or "unwrap" (automatic, for curved or organic shapes; pattern direction may vary between patches).
	 * @param Selection  Which faces to lay out. Default all. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString AutoUV(const FString& Name, const FString& Method = TEXT("box"), const FModellingSelection& Selection = FModellingSelection());

	/** Measures how much a part's texture layout stretches or squashes textures. Returns a verdict, the share of faces that are over-stretched,
	 * faces missing a layout, and the worst spots (local-space centres) so you can re-run AutoUV with another method on them.
	 * @param Name  Actor label. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Textures")
	static MODELLINGTOOLSET_API FString CheckTextureStretch(const FString& Name);

	/** Measures a mesh's UV layout: share of surface area with the wrong tile size or distortion, and faces with no layout. Not an AI tool. */
	static MODELLINGTOOLSET_API void MeasureUVQuality(class UDynamicMesh* Mesh, double& OutWrongTilePercent, double& OutStretchedPercent, int32& OutFacesWithoutLayout, int32& OutFaces);

	/** Lays world-scale box-projected UVs (one unit per 100 cm) onto every face of a mesh. Not an AI tool. */
	static MODELLINGTOOLSET_API void ApplyBoxUVs(class UDynamicMesh* Mesh);

	/** Renders a sphere and a cube with a material into OutCapture. Not an AI tool. */
	static MODELLINGTOOLSET_API bool RenderMaterialPreview(class UMaterialInterface* Material, const FString& Label, FModellingCapture& OutCapture, FString& OutError);
};

