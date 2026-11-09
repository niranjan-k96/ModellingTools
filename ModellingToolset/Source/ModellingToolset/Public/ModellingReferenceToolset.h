// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"
#include "ToolsetRegistry/ToolsetImage.h"

#include "ModellingReferenceToolset.generated.h"

/** A reference image plus any notes the user wrote for it. */
USTRUCT(BlueprintType, MinimalAPI)
struct FModellingReference
{
	GENERATED_BODY()

	/** The image, downscaled to fit MaxDimension. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FToolsetImage Image;

	/** File name inside the references folder. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FString Name;

	/** Contents of a same-name .txt or .md file next to the image (scale, intent, materials). Empty if none. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FString Notes;

	/** Original pixel size before downscaling. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	int32 OriginalWidth = 0;

	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	int32 OriginalHeight = 0;
};

/**
 * Reference-image workflow. The user drops images (png, jpg, bmp) into the references folder, optionally
 * with a same-name .txt/.md note, and the AI reads them here to recreate the subject in 3D.
 */
UCLASS(MinimalAPI)
class UModellingReferenceToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Lists reference images the user has placed in the references folder, as a JSON array with sizes and whether a notes file exists.
	 * Check this at the start of a task: if images are present, model from them. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Reference")
	static MODELLINGTOOLSET_API FString ListReferences();

	/** Reads one reference image and its notes.
	 * @param Name          File name from ListReferences (no folders).
	 * @param MaxDimension  Longest side in pixels after downscaling (keeps the image cheap to view). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Reference")
	static MODELLINGTOOLSET_API FModellingReference GetReference(const FString& Name, int32 MaxDimension = 1024);
};
