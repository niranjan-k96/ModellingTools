// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

struct FSlateDynamicImageBrush;
class SMultiLineEditableTextBox;
class SWrapBox;

/**
 * The Modelling Assistant panel. Walks the user through the steps (add reference images, describe the model, press Go),
 * shows the AI's progress, then a review screen with "send changes" and "Done, export FBX".
 * It only reads and changes the shared job state, so it can be closed and reopened at any time.
 */
class SModellingAssistant : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SModellingAssistant) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

private:
	TSharedRef<SWidget> BuildStepHeader(int32 Number, const FText& Title);
	TSharedRef<SWidget> BuildSetupSection();
	TSharedRef<SWidget> BuildWaitingSection();
	TSharedRef<SWidget> BuildProgressSection();
	TSharedRef<SWidget> BuildReviewSection();
	TSharedRef<SWidget> BuildResultSection();

	EActiveTimerReturnType OnRefreshTimer(double CurrentTime, float DeltaTime);
	void RefreshReferences();
	void RefreshThumbnail();
	/** Rebuilds the small pictures of the reference images shown in step 1. */
	void RebuildReferenceThumbnails();
	FText GetStatusText() const;

	TArray<FString> ReferenceNames;
	FString ThumbnailFile;
	TSharedPtr<FSlateDynamicImageBrush> ThumbnailBrush;
	TSharedPtr<SMultiLineEditableTextBox> ChangesBox;
	TSharedPtr<SWrapBox> ReferenceThumbBox;
	TMap<FString, TSharedPtr<FSlateDynamicImageBrush>> ReferenceThumbs;
	TArray<FString> ThumbnailedNames;
	FText MessageText;
};

