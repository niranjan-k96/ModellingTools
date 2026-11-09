// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"
#include "ToolsetRegistry/ToolsetImage.h"

#include "ModellingVisionToolset.generated.h"

/** Result of CaptureViews. */
USTRUCT(BlueprintType, MinimalAPI)
struct FModellingCapture
{
	GENERATED_BODY()

	/** Contact sheet: all requested views tiled left-to-right, top-to-bottom in the order given by Summary.views_in_sheet_order. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FToolsetImage Image;

	/** JSON: step number, session folder, saved file paths, view order, framed bounds. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FString Summary;
};

/** Result of CompareToReference. */
USTRUCT(BlueprintType, MinimalAPI)
struct FModellingComparison
{
	GENERATED_BODY()

	/** Three pictures side by side: the reference, the model, and an overlap map (grey = both, red = model only, blue = reference only). */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FToolsetImage Image;

	/** JSON: overlap_score (0 to 1), verdict, proportion error, and plain-language "where_it_differs" hints. */
	UPROPERTY(BlueprintReadOnly, Category = "ModellingToolset")
	FString Summary;
};

/**
 * Lets the AI see what it is building. Renders the model from controlled camera angles using an
 * off-screen scene capture (independent of the editor viewport layout), saves every image to the
 * progress folder, and returns a contact sheet.
 *
 * Axis convention: +X is the model's front, +Y its right, +Z up.
 *
 * Note: the same capture is also exposed as the raw MCP tool "modelling_capture_views", which returns a real
 * image content block. Prefer that tool if this one's image arrives as text.
 */
UCLASS(MinimalAPI)
class UModellingVisionToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Captures the model from several angles and saves each image to the progress folder.
	 * Call this after every meaningful modelling step and compare against the reference.
	 *
	 * Valid view names: iso (front-right perspective), iso_back (back-left perspective), front (camera on +X),
	 * back (-X), right (+Y), left (-Y), top (+Z), bottom (-Z). Axis views are orthographic unless bForcePerspective.
	 *
	 * @param ActorNames         Comma-separated actor labels to frame. Empty frames all actors created by this toolset.
	 * @param Views              Comma-separated view names. Empty uses "iso,front,right,top".
	 * @param ViewMode           "lit" (default, fixed studio lighting), "clay" (neutral grey with shading, best for judging form), "unlit" (flat material colour, no shading), or "normals" (surface direction as colour, shows bumps and creases).
	 * @param Resolution         Pixel size of one square tile. 0 uses the project setting.
	 * @param bIsolate           If true, render only the framed actors and hide the rest of the level.
	 * @param bForcePerspective  If true, axis views use perspective instead of orthographic.
	 * @param Label              Optional short tag put in the file names and log, e.g. "added_roof".
	 * @return Contact sheet image plus JSON summary with saved file paths. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Vision")
	static MODELLINGTOOLSET_API FModellingCapture CaptureViews(
		const FString& ActorNames,
		const FString& Views,
		const FString& ViewMode = TEXT("lit"),
		int32 Resolution = 0,
		bool bIsolate = false,
		bool bForcePerspective = false,
		const FString& Label = TEXT(""));

	/** Checks how closely the model matches a reference picture. Renders the model from the same straight-on view and compares the two silhouettes.
	 * Returns an overlap score (1 = identical outline), a verdict, the proportion error, and plain hints such as "between 25% and 37% of the way down
	 * the model is 22% narrower than the reference", plus a side-by-side picture. Use it after blocking out and again before asking for review.
	 * Works best when the reference has a plain background. Add "view: front" to the reference's notes (or put "front" in its file name) to label it.
	 * Same capture is available as the direct tool "modelling_compare_to_reference", which returns a real image.
	 * @param ReferenceName  File name from ListReferences.
	 * @param View           front, back, left, right, top or bottom. Empty uses the reference's label, or front.
	 * @param ActorNames     Comma-separated actor labels to compare. Empty uses every actor the toolset created. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Vision")
	static MODELLINGTOOLSET_API FModellingComparison CompareToReference(const FString& ReferenceName, const FString& View = TEXT(""), const FString& ActorNames = TEXT(""));

	/** Starts a fresh progress sub-folder and resets the step counter. Call at the start of a new task.
	 * @param Name  Short name for the session, used in the folder name.
	 * @return Absolute path of the new session folder. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Vision")
	static MODELLINGTOOLSET_API FString StartSession(const FString& Name);

	/** Lists images saved in the progress folder as a JSON array of relative paths, newest first.
	 * @param MaxItems  Maximum number of entries to return. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Vision")
	static MODELLINGTOOLSET_API FString ListProgressImages(int32 MaxItems = 30);

	/** Re-opens an earlier progress image so it can be compared with the current state.
	 * @param RelativePath  Path relative to the progress folder, as listed by ListProgressImages.
	 * @param MaxDimension  Longest side in pixels after downscaling. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Vision")
	static MODELLINGTOOLSET_API FToolsetImage GetProgressImage(const FString& RelativePath, int32 MaxDimension = 1024);
};

