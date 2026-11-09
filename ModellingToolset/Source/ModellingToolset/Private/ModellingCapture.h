// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

namespace ModellingToolset
{
	struct FCaptureRequest
	{
		FString ActorNames;            // comma separated; empty = all actors created by this plugin
		TArray<AActor*> ExplicitTargets; // when set, these are captured and ActorNames is ignored (used for previews)
		FString Views;                 // comma separated; empty = "iso,front,right,top"
		FString ViewMode = TEXT("lit");// lit | unlit | clay | wireframe
		int32 Resolution = 0;          // tile size in px; 0 = project setting
		bool bIsolate = false;
		bool bForcePerspective = false;
		FString Label;
		/** If false, the review panel's picture is not replaced by this capture (used by comparisons). */
		bool bSetReviewImage = true;
	};

	struct FCaptureResult
	{
		bool bOk = false;
		FString Error;
		TArray<FColor> Sheet;          // contact sheet as returned to the AI (already size-capped)
		FIntPoint SheetSize = FIntPoint::ZeroValue;
		FString SummaryJson;
	};

	/** Renders the requested views off-screen, saves them to the progress folder and builds the contact sheet. Game thread only. */
	FCaptureResult CaptureViews(const FCaptureRequest& Request);

	/** Starts a fresh progress sub-folder and resets the step counter. Returns the absolute folder path. */
	FString StartCaptureSession(const FString& Name);
}
