// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/ToolsetDefinition.h"

#include "ModellingBatchToolset.generated.h"

/**
 * Runs many Modelling tools in one call. Blocking out a model takes dozens of small steps (add a box, add a cylinder, paint it);
 * a batch does them all at once, so it is much faster and uses far fewer calls.
 */
UCLASS(MinimalAPI)
class UModellingBatchToolset : public UToolsetDefinition
{
	GENERATED_BODY()

public:
	/** Runs a list of Modelling tools in order, in one call.
	 *
	 * StepsJson is a JSON array. Each step names a tool and gives its arguments exactly as you would when calling it on its own:
	 *   [
	 *     {"tool":"CreateMeshActor","args":{"Name":"Tower","Location":{"X":0,"Y":0,"Z":0},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
	 *     {"tool":"AddCylinder","args":{"Name":"Tower","Radius":60,"Height":400,"Location":{"X":0,"Y":0,"Z":200},"Rotation":{"Pitch":0,"Yaw":0,"Roll":0}}},
	 *     {"tool":"PaintPart","args":{"Name":"Tower","Hex":"#EEEEEE"}}
	 *   ]
	 * Arguments you leave out use the tool's normal defaults. Tool names and argument names are the same as the individual tools.
	 * Works for tools that return text, a yes/no or a number: scene, shapes, edits, deforms, repairs, materials, measuring and saving.
	 * It cannot run tools that return pictures or wait (CaptureViews, CompareToReference, WaitForUserDecision) or RunBatch itself.
	 * Limit: 200 steps per call.
	 *
	 * Returns JSON: how many steps completed, the step that failed (if any) with its error, and each step's result.
	 * After a failure the remaining steps are skipped unless bContinueOnError is true.
	 *
	 * @param StepsJson        The JSON array of steps.
	 * @param bContinueOnError Keep going after a step fails. */
	UFUNCTION(meta = (AICallable), Category = "ModellingToolset|Batch")
	static MODELLINGTOOLSET_API FString RunBatch(const FString& StepsJson, bool bContinueOnError = false);
};
