// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolCallAsyncResultString.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingJobToolset.generated.h"

/**
 * The link between the user's Modelling Assistant panel and the AI.
 * The user fills in the panel (reference images and a description) and presses Go. The AI then:
 *   1. calls GetModellingJob to read the request,
 *   2. studies the reference images, models, and reports progress,
 *   3. calls RequestReview when a version is ready,
 *   4. calls WaitForUserDecision and either applies the user's changes or finishes when the user presses Done
 *      (the plugin itself then exports the FBX).
 */
UCLASS(MinimalAPI)
class UModellingJobToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** ALWAYS CALL THIS FIRST. Returns the user's request as JSON: status, instructions, the list of reference images, the references folder and the next step.
	 * If the status is "not_started" the user has not pressed Go in the Modelling Assistant panel: do NOT start modelling, tell the user what to do instead.
	 * If there are reference images, view every one with GetReference before creating any geometry. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Job")
	static MODELLINGTOOLSET_API FString GetModellingJob();

	/** Shows a short progress line in the user's panel. Call after each stage, e.g. "Blocked out the main shapes" or "Added windows".
	 * @param Message  One short plain-language sentence. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Job")
	static MODELLINGTOOLSET_API FString ReportProgress(const FString& Message);

	/** Tells the user a version of the model is ready and opens the review screen in their panel (latest screenshot, a box for changes, and a Done button).
	 * Call this only after a final CaptureViews check against the references. Then call WaitForUserDecision.
	 * @param Summary  A short plain-language description of what was built and anything that is approximate or missing. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Job")
	static MODELLINGTOOLSET_API FString RequestReview(const FString& Summary);

	/** Waits for the user to press "Send changes" or "Done" in the panel. Returns JSON with "decision":
	 *   "changes"  - apply the text in "changes", then RequestReview again.
	 *   "done"     - the user approved it and the plugin exported the FBX; tell the user the "fbx_path" and stop.
	 *   "export_failed" - tell the user the error.
	 *   "pending"  - the user has not decided yet; call this tool again (keep waiting).
	 * Do not export or declare the job finished yourself.
	 * @param TimeoutSeconds  How long to wait before returning "pending" (5 to 55). */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Job")
	static MODELLINGTOOLSET_API UToolCallAsyncResultString* WaitForUserDecision(int32 TimeoutSeconds = 45);

	/** Same as WaitForUserDecision but returns immediately with the current decision ("pending" if none). Use it only if waiting is not possible. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Job")
	static MODELLINGTOOLSET_API FString GetUserDecision();
};
