// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "ModellingToolsetSettings.generated.h"

/** Project settings for the Modelling Toolset (Project Settings > Plugins > Modelling Toolset). */
UCLASS(Config = ModellingToolset, DefaultConfig, MinimalAPI)
class UModellingToolsetSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UModellingToolsetSettings();

	/** Folder the user drops reference images (and optional same-name .txt notes) into. Relative paths resolve against the project directory. */
	UPROPERTY(Config, EditAnywhere, Category = "Folders")
	FString ReferencesFolder = TEXT("ModellingToolset/References");

	/** Folder progress screenshots are written to, one sub-folder per session. Defaults to Saved/ so it stays out of source control.
	 * Relative paths resolve against the project directory. */
	UPROPERTY(Config, EditAnywhere, Category = "Folders")
	FString ProgressFolder = TEXT("Saved/ModellingToolset/Progress");

	/** Folder exported FBX files are written to. Relative paths resolve against the project directory. */
	UPROPERTY(Config, EditAnywhere, Category = "Folders")
	FString ExportsFolder = TEXT("ModellingToolset/Exports");

	/** Folder the user drops texture images into, named by set: Brick_albedo.png, Brick_normal.png, Brick_roughness.png, Brick_metallic.png. */
	UPROPERTY(Config, EditAnywhere, Category = "Folders")
	FString TexturesFolder = TEXT("ModellingToolset/Textures");

	/** Content folder holding ready-made materials the AI may use, e.g. /Game/Materials. Searched recursively. */
	UPROPERTY(Config, EditAnywhere, Category = "Materials")
	FString MaterialLibraryFolder = TEXT("/Game/Materials");

	/** Default size of one texture tile in centimetres when a texture set does not say (tile_cm in its notes file). */
	UPROPERTY(Config, EditAnywhere, Category = "Materials", meta = (ClampMin = "1", ClampMax = "10000"))
	float DefaultTileCm = 100.f;

	/** Content folders holding surface libraries (one folder per surface with _B, _N and _ORM textures), such as Fab or Megascans downloads. */
	UPROPERTY(Config, EditAnywhere, Category = "Materials")
	TArray<FString> SurfaceLibraryFolders = { TEXT("/Game/Fab/Megascans/Surfaces"), TEXT("/Game/Megascans/Surfaces") };

	/** Default real-world size of one tile for library surfaces, in centimetres. Megascans surfaces are usually 2 metres. */
	UPROPERTY(Config, EditAnywhere, Category = "Materials", meta = (ClampMin = "1", ClampMax = "10000"))
	float DefaultSurfaceTileCm = 200.f;

	/** Default size in pixels of one capture tile. */
	UPROPERTY(Config, EditAnywhere, Category = "Capture", meta = (ClampMin = "128", ClampMax = "2048"))
	int32 DefaultCaptureResolution = 512;

	/** The contact sheet returned to the AI is downscaled so neither side exceeds this. Individual view files are always saved at full tile size. */
	UPROPERTY(Config, EditAnywhere, Category = "Capture", meta = (ClampMin = "512", ClampMax = "4096"))
	int32 MaxReturnedImageDimension = 2048;

	/** Exposure for captures, in stops. Captures use their own fixed lights, so this is the only brightness control. Higher is brighter. */
	UPROPERTY(Config, EditAnywhere, Category = "Capture", meta = (ClampMin = "-5", ClampMax = "15"))
	float CaptureExposure = 1.0f;

	/** Maximum number of mesh checkpoints kept in memory. The oldest is dropped first. */
	UPROPERTY(Config, EditAnywhere, Category = "Checkpoints", meta = (ClampMin = "1", ClampMax = "100"))
	int32 MaxCheckpoints = 24;
};
