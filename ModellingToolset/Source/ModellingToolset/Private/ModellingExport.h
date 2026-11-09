// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UDynamicMesh;
class UMaterialInterface;
class UStaticMesh;

namespace ModellingToolset
{
	/** Accepts "/Game/Dir/Name" or "/Game/Dir/Name.Name". Only /Game/ is allowed for writes. */
	bool ParseGameAssetPath(const FString& In, FString& OutPackage, FString& OutAsset, FString& OutError);

	struct FStaticMeshAssetOptions
	{
		/** none, auto, box, convex or complex. */
		FString CollisionMode = TEXT("auto");
		bool bEnableNanite = false;
		bool bOverwrite = false;
		bool bSaveToDisk = true;
		/** If any entry is non-null, the asset's material slots are replaced with these. */
		TArray<UMaterialInterface*> Materials;
	};

	struct FStaticMeshAssetResult
	{
		UStaticMesh* StaticMesh = nullptr;
		bool bCreated = false;
		bool bSaved = false;
		/** Set when StaticMesh is null (hard failure) or when saving to disk failed (soft failure). */
		FString Error;
	};

	/** Creates or overwrites a StaticMesh asset from a dynamic mesh. Does not raise tool errors; read Result.Error. */
	FStaticMeshAssetResult WriteStaticMeshAsset(UDynamicMesh* Mesh, const FString& PackageName, const FString& AssetName, const FStaticMeshAssetOptions& Options);

	struct FExportResult
	{
		bool bOk = false;
		FString Error;
		FString AssetPath;
		FString FbxPath;
		int32 Triangles = 0;
		/** How the texture layout in the file was obtained. */
		FString UVNote;
	};

	/**
	 * Exports everything the toolset built as one FBX file.
	 * All model actors are merged (keeping their relative positions), moved so the model stands on the ground
	 * at the origin, saved as a StaticMesh asset under /Game/ModellingToolset/Exports/, and exported to the exports folder.
	 */
	FExportResult ExportModelToFbx(const FString& OutputName);
}

