// Copyright Epic Games, Inc. All Rights Reserved.

#include "SModellingAssistant.h"

#include "ModellingJob.h"
#include "ModellingToolsetUtils.h"

#include "Brushes/SlateDynamicImageBrush.h"
#include "HAL/PlatformApplicationMisc.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"
#include "Styling/AppStyle.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "ModellingAssistant"

using namespace ModellingToolset;

namespace
{
	EVisibility VisibleIf(bool bVisible) { return bVisible ? EVisibility::Visible : EVisibility::Collapsed; }

	bool IsIn(EJobStatus Status, std::initializer_list<EJobStatus> Set)
	{
		for (const EJobStatus S : Set) { if (S == Status) { return true; } }
		return false;
	}

	/** Wrapped paragraph of normal text. */
	TSharedRef<SWidget> Paragraph(const FText& Text)
	{
		return SNew(STextBlock).Text(Text).AutoWrapText(true).Font(FAppStyle::GetFontStyle("NormalFont"));
	}

	TSharedRef<SWidget> Spacer(float Height = 8.f)
	{
		return SNew(SBox).HeightOverride(Height);
	}

	/** Read-only box that still lets the user select and copy the text (paths, messages). */
	TSharedRef<SWidget> ReadOnlyLine(TAttribute<FText> Text)
	{
		return SNew(SEditableTextBox).Text(Text).IsReadOnly(true);
	}
}

void SModellingAssistant::Construct(const FArguments& InArgs)
{
	RefreshReferences();

	ChildSlot
	[
		SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(16.f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot()
			[
				SNew(SVerticalBox)

				// Title and live status.
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Title", "Modelling Assistant"))
					.Font(FCoreStyle::GetDefaultFontStyle("Bold", 20))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 4, 0, 12)
				[
					SNew(STextBlock)
					.Text_Raw(this, &SModellingAssistant::GetStatusText)
					.ColorAndOpacity(FLinearColor(0.45f, 0.75f, 1.f))
					.Font(FAppStyle::GetFontStyle("BoldFont"))
				]

				+ SVerticalBox::Slot().AutoHeight() [ BuildSetupSection() ]
				+ SVerticalBox::Slot().AutoHeight() [ BuildWaitingSection() ]
				+ SVerticalBox::Slot().AutoHeight() [ BuildReviewSection() ]
				+ SVerticalBox::Slot().AutoHeight() [ BuildResultSection() ]
				+ SVerticalBox::Slot().AutoHeight() [ BuildProgressSection() ]
			]
		]
	];

	RegisterActiveTimer(1.0f, FWidgetActiveTimerDelegate::CreateSP(this, &SModellingAssistant::OnRefreshTimer));
}

EActiveTimerReturnType SModellingAssistant::OnRefreshTimer(double CurrentTime, float DeltaTime)
{
	RefreshReferences();
	if (ReferenceNames != ThumbnailedNames)
	{
		RebuildReferenceThumbnails();
	}
	RefreshThumbnail();
	return EActiveTimerReturnType::Continue;
}

void SModellingAssistant::RefreshReferences()
{
	ReferenceNames = ListReferenceImageNames();
}

void SModellingAssistant::RefreshThumbnail()
{
	const FString& Latest = GetJob().LastSheetFile;
	if (Latest.IsEmpty() || Latest == ThumbnailFile)
	{
		return;
	}

	TArray<FColor> Pixels;
	FIntPoint Size, Original;
	FString Error;
	if (!LoadImageFile(Latest, 640, Pixels, Size, Original, Error))
	{
		return;
	}

	TArray<uint8> Bytes;
	Bytes.SetNumUninitialized(Pixels.Num() * 4);
	FMemory::Memcpy(Bytes.GetData(), Pixels.GetData(), Bytes.Num());

	// A unique resource name per load so Slate never reuses an older texture.
	const FName ResourceName(*FString::Printf(TEXT("ModellingReview_%s_%lld"), *FPaths::GetBaseFilename(Latest), FDateTime::Now().GetTicks()));
	ThumbnailBrush = FSlateDynamicImageBrush::CreateWithImageData(ResourceName, FVector2f(Size.X, Size.Y), Bytes);
	ThumbnailFile = Latest;
}

void SModellingAssistant::RebuildReferenceThumbnails()
{
	ThumbnailedNames = ReferenceNames;

	// Load a small picture for each reference once; drop pictures whose file is gone.
	for (auto It = ReferenceThumbs.CreateIterator(); It; ++It)
	{
		if (!ReferenceNames.Contains(It.Key())) { It.RemoveCurrent(); }
	}
	for (const FString& Name : ReferenceNames)
	{
		if (ReferenceThumbs.Contains(Name)) { continue; }
		TArray<FColor> Pixels;
		FIntPoint Size, Original;
		FString Error;
		if (!LoadImageFile(GetReferencesDir() / Name, 96, Pixels, Size, Original, Error)) { continue; }
		TArray<uint8> Bytes;
		Bytes.SetNumUninitialized(Pixels.Num() * 4);
		FMemory::Memcpy(Bytes.GetData(), Pixels.GetData(), Bytes.Num());
		const FName ResourceName(*FString::Printf(TEXT("ModellingRef_%s_%lld"), *FPaths::GetBaseFilename(Name), FDateTime::Now().GetTicks()));
		ReferenceThumbs.Add(Name, FSlateDynamicImageBrush::CreateWithImageData(ResourceName, FVector2f(Size.X, Size.Y), Bytes));
	}

	if (!ReferenceThumbBox.IsValid())
	{
		return;
	}
	ReferenceThumbBox->ClearChildren();
	for (const FString& Name : ReferenceNames)
	{
		const TSharedPtr<FSlateDynamicImageBrush>* Brush = ReferenceThumbs.Find(Name);
		if (!Brush || !Brush->IsValid()) { continue; }
		ReferenceThumbBox->AddSlot().Padding(0, 0, 8, 8)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBorder).Padding(2.f)
				[
					SNew(SImage).Image(Brush->Get())
				]
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Center)
			[
				SNew(SBox).MaxDesiredWidth(100.f)
				[
					SNew(STextBlock).Text(FText::FromString(Name)).ToolTipText(FText::FromString(Name)).Font(FAppStyle::GetFontStyle("SmallFont")).ColorAndOpacity(FLinearColor(0.6f, 0.6f, 0.6f))
				]
			]
		];
	}
}

FText SModellingAssistant::GetStatusText() const
{
	switch (GetJob().Status)
	{
	case EJobStatus::Idle:             return LOCTEXT("StatusIdle", "Get ready: follow steps 1 to 3 below.");
	case EJobStatus::ReadyForAI:       return LOCTEXT("StatusReady", "Go pressed. Waiting for your AI assistant to start.");
	case EJobStatus::Working:          return LOCTEXT("StatusWorking", "The AI assistant is modelling.");
	case EJobStatus::ReviewPending:    return LOCTEXT("StatusReview", "Your turn: please review the model below.");
	case EJobStatus::ChangesRequested: return LOCTEXT("StatusChanges", "Your changes were sent. Waiting for the AI to update the model.");
	case EJobStatus::Exporting:        return LOCTEXT("StatusExporting", "Exporting your model...");
	case EJobStatus::Done:             return LOCTEXT("StatusDone", "Finished. Your model was exported.");
	case EJobStatus::Failed:           return LOCTEXT("StatusFailed", "The export did not work. See below.");
	}
	return FText::GetEmpty();
}

TSharedRef<SWidget> SModellingAssistant::BuildStepHeader(int32 Number, const FText& Title)
{
	return SNew(SHorizontalBox)
		+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, 10, 0)
		[
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("Brushes.Primary"))
			.Padding(FMargin(9, 3))
			[
				SNew(STextBlock).Text(FText::AsNumber(Number)).Font(FAppStyle::GetFontStyle("BoldFont"))
			]
		]
		+ SHorizontalBox::Slot().FillWidth(1.f).VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(Title).Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
		];
}

TSharedRef<SWidget> SModellingAssistant::BuildSetupSection()
{
	FJobState& Job = GetJob();

	return SNew(SBox)
		.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::Idle); })
		[
			SNew(SVerticalBox)

			// STEP 1: reference images
			+ SVerticalBox::Slot().AutoHeight() [ BuildStepHeader(1, LOCTEXT("Step1", "Add your reference images")) ]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
			[
				Paragraph(LOCTEXT("Step1Text",
					"Copy photos or drawings of what you want to build into the folder below. Add several angles if you have them (front, side, back). "
					"To explain a picture, add a text file with the same name, for example Photo1.png and Photo1.txt. "
					"This step is optional, but the result is much better with pictures."))
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				ReadOnlyLine(TAttribute<FText>::CreateLambda([]() { return FText::FromString(GetReferencesDir()); }))
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 8, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("OpenRefs", "Open folder"))
					.ToolTipText(LOCTEXT("OpenRefsTip", "Open the references folder in your file explorer."))
					.OnClicked_Lambda([]()
					{
						EnsureWorkspaceFolders();
						FPlatformProcess::ExploreFolder(*GetReferencesDir());
						return FReply::Handled();
					})
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("Refresh", "Refresh list"))
					.OnClicked_Lambda([this]() { RefreshReferences(); return FReply::Handled(); })
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text_Lambda([this]()
				{
					if (ReferenceNames.IsEmpty())
					{
						return LOCTEXT("NoRefs", "No images found yet.");
					}
					return FText::Format(LOCTEXT("SomeRefs", "{0} image(s) found: {1}"),
						FText::AsNumber(ReferenceNames.Num()), FText::FromString(FString::Join(ReferenceNames, TEXT(", "))));
				})
				.ColorAndOpacity_Lambda([this]()
				{
					return ReferenceNames.IsEmpty() ? FSlateColor(FLinearColor(1.f, 0.8f, 0.3f)) : FSlateColor(FLinearColor(0.5f, 0.9f, 0.5f));
				})
			]

			+ SVerticalBox::Slot().AutoHeight().Padding(0, 10, 0, 0)
			[
				SAssignNew(ReferenceThumbBox, SWrapBox).PreferredSize(520.f)
			]

			+ SVerticalBox::Slot().AutoHeight().Padding(0, 14, 0, 14) [ SNew(SSeparator) ]

			// STEP 2: describe
			+ SVerticalBox::Slot().AutoHeight() [ BuildStepHeader(2, LOCTEXT("Step2", "Describe what to build")) ]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
			[
				Paragraph(LOCTEXT("Step2Text",
					"Tell the AI what you want. Mention the size, style and anything the pictures do not show."))
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBox).MinDesiredHeight(110.f)
				[
					SNew(SMultiLineEditableTextBox)
					.Text(FText::FromString(Job.DraftInstructions))
					.HintText(LOCTEXT("Step2Hint", "Example: A small lighthouse, about 12 metres tall, white with a red top. Match the front picture."))
					.AutoWrapText(true)
					.OnTextChanged_Lambda([](const FText& NewText) { GetJob().DraftInstructions = NewText.ToString(); })
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, 8, 0)
				[
					SNew(STextBlock).Text(LOCTEXT("NameLabel", "Name of the model:"))
				]
				+ SHorizontalBox::Slot().FillWidth(1.f)
				[
					SNew(SEditableTextBox)
					.Text(FText::FromString(Job.DraftName))
					.HintText(LOCTEXT("NameHint", "MyModel"))
					.OnTextChanged_Lambda([](const FText& NewText) { GetJob().DraftName = NewText.ToString(); })
				]
			]

			+ SVerticalBox::Slot().AutoHeight().Padding(0, 14, 0, 14) [ SNew(SSeparator) ]

			// STEP 3: Go
			+ SVerticalBox::Slot().AutoHeight() [ BuildStepHeader(3, LOCTEXT("Step3", "Press Go")) ]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
			[
				Paragraph(LOCTEXT("Step3Text",
					"When steps 1 and 2 are done, press Go. A message will appear. Paste it into your AI assistant and it will start modelling."))
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SBox).WidthOverride(160.f).HeightOverride(40.f)
				[
					SNew(SButton)
					.ButtonStyle(&FAppStyle::Get().GetWidgetStyle<FButtonStyle>("PrimaryButton"))
					.HAlign(HAlign_Center).VAlign(VAlign_Center)
					.IsEnabled_Lambda([]() { return !GetJob().DraftInstructions.TrimStartAndEnd().IsEmpty(); })
					.OnClicked_Lambda([this]()
					{
						FString Error;
						FJobState& J = GetJob();
						if (StartJob(J.DraftInstructions, J.DraftName, Error))
						{
							MessageText = FText::GetEmpty();
							FPlatformApplicationMisc::ClipboardCopy(*GetStartMessage());
						}
						else
						{
							MessageText = FText::FromString(Error);
						}
						return FReply::Handled();
					})
					[
						SNew(STextBlock).Text(LOCTEXT("Go", "Go")).Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
					]
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Visibility_Lambda([this]() { return VisibleIf(ReferenceNames.IsEmpty()); })
				.ColorAndOpacity(FLinearColor(1.f, 0.8f, 0.3f))
				.Text(LOCTEXT("NoRefsWarning", "No reference images found. The AI will use only your text."))
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Visibility_Lambda([this]() { return VisibleIf(!MessageText.IsEmpty()); })
				.ColorAndOpacity(FLinearColor(1.f, 0.4f, 0.3f))
				.Text_Lambda([this]() { return MessageText; })
			]
		];
}

TSharedRef<SWidget> SModellingAssistant::BuildWaitingSection()
{
	return SNew(SBox)
		.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::ReadyForAI); })
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight() [ BuildStepHeader(3, LOCTEXT("WaitTitle", "Tell your AI assistant to start")) ]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
			[
				Paragraph(LOCTEXT("WaitText",
					"Your job is ready. Paste the message below into your AI assistant (it was also copied for you). "
					"The AI will look at your reference images first, then start modelling."))
			]
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SMultiLineEditableTextBox)
				.IsReadOnly(true)
				.AutoWrapText(true)
				.Text_Lambda([]() { return FText::FromString(GetStartMessage()); })
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 8, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("CopyMsg", "Copy message again"))
					.OnClicked_Lambda([]() { FPlatformApplicationMisc::ClipboardCopy(*GetStartMessage()); return FReply::Handled(); })
				]
				+ SHorizontalBox::Slot().AutoWidth()
				[
					SNew(SButton)
					.Text(LOCTEXT("CancelJob", "Cancel"))
					.OnClicked_Lambda([]() { ResetJob(/*bCancelledByUser=*/true); return FReply::Handled(); })
				]
			]
		];
}

TSharedRef<SWidget> SModellingAssistant::BuildProgressSection()
{
	return SNew(SBox)
		.Visibility_Lambda([]() { return VisibleIf(GetJob().Status != EJobStatus::Idle); })
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 14, 0, 14) [ SNew(SSeparator) ]
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(STextBlock).Text(LOCTEXT("ProgressTitle", "What is happening")).Font(FCoreStyle::GetDefaultFontStyle("Bold", 14))
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
			[
				SNew(SBox).HeightOverride(150.f)
				[
					SNew(SMultiLineEditableTextBox)
					.IsReadOnly(true)
					.AutoWrapText(true)
					.Text_Lambda([]() { return FText::FromString(FString::Join(GetJob().Log, TEXT("\n"))); })
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("StartOver", "Cancel this job"))
				.Visibility_Lambda([]() { return VisibleIf(IsIn(GetJob().Status, { EJobStatus::Working, EJobStatus::ReviewPending, EJobStatus::ChangesRequested })); })
				.ToolTipText(LOCTEXT("StartOverTip", "Stops the job and tells the AI to stop. The model stays in the level."))
				.OnClicked_Lambda([]() { ResetJob(/*bCancelledByUser=*/true); return FReply::Handled(); })
			]
		];
}

TSharedRef<SWidget> SModellingAssistant::BuildReviewSection()
{
	return SNew(SBox)
		.Visibility_Lambda([]() { return VisibleIf(IsIn(GetJob().Status, { EJobStatus::ReviewPending, EJobStatus::ChangesRequested })); })
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight() [ BuildStepHeader(4, LOCTEXT("ReviewTitle", "Review the model")) ]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text_Lambda([]()
				{
					const FString& Summary = GetJob().ReviewSummary;
					return FText::FromString(Summary.IsEmpty() ? FString(TEXT("The AI says the model is ready.")) : Summary);
				})
			]
			+ SVerticalBox::Slot().AutoHeight().HAlign(HAlign_Left)
			[
				SNew(SBox).MaxDesiredWidth(640.f)
				.Visibility_Lambda([this]() { return VisibleIf(ThumbnailBrush.IsValid()); })
				[
					SNew(SImage)
					.Image_Lambda([this]() -> const FSlateBrush* { return ThumbnailBrush.IsValid() ? ThumbnailBrush.Get() : FAppStyle::GetDefaultBrush(); })
				]
			]
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 4, 0, 0)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Visibility_Lambda([this]() { return VisibleIf(ThumbnailBrush.IsValid()); })
				.ColorAndOpacity(FLinearColor(0.6f, 0.6f, 0.6f))
				.Text(LOCTEXT("ThumbNote", "Latest pictures taken by the AI. The full-size images are saved in the progress folder."))
			]

			// Waiting for the AI after changes were sent.
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 10, 0, 0)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::ChangesRequested); })
				.ColorAndOpacity(FLinearColor(1.f, 0.8f, 0.3f))
				.Text(LOCTEXT("ChangesSent", "Your changes were sent. If the AI has stopped, tell it: \"Continue the modelling job.\" This screen comes back when the new version is ready."))
			]

			// Changes box and buttons, only while it is the user's turn.
			+ SVerticalBox::Slot().AutoHeight().Padding(0, 12, 0, 0)
			[
				SNew(SVerticalBox)
				.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::ReviewPending); })
				+ SVerticalBox::Slot().AutoHeight()
				[
					Paragraph(LOCTEXT("ChangesText", "Want something different? Describe the change and press \"Send changes\". Happy with it? Press \"Done\" to export the FBX."))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
				[
					SNew(SBox).MinDesiredHeight(80.f)
					[
						SAssignNew(ChangesBox, SMultiLineEditableTextBox)
						.AutoWrapText(true)
						.HintText(LOCTEXT("ChangesHint", "Example: Make the tower taller and add a door on the front."))
					]
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 8, 0)
					[
						SNew(SBox).HeightOverride(36.f)
						[
							SNew(SButton)
							.VAlign(VAlign_Center)
							.Text(LOCTEXT("SendChanges", "Send changes"))
							.OnClicked_Lambda([this]()
							{
								FString Error;
								const FString Text = ChangesBox.IsValid() ? ChangesBox->GetText().ToString() : FString();
								if (SubmitChanges(Text, Error))
								{
									MessageText = FText::GetEmpty();
									if (ChangesBox.IsValid()) { ChangesBox->SetText(FText::GetEmpty()); }
								}
								else
								{
									MessageText = FText::FromString(Error);
								}
								return FReply::Handled();
							})
						]
					]
					+ SHorizontalBox::Slot().AutoWidth()
					[
						SNew(SBox).HeightOverride(36.f)
						[
							SNew(SButton)
							.ButtonStyle(&FAppStyle::Get().GetWidgetStyle<FButtonStyle>("PrimaryButton"))
							.VAlign(VAlign_Center)
							.Text(LOCTEXT("DoneExport", "Done, export FBX"))
							.OnClicked_Lambda([this]()
							{
								FString Error;
								FinishAndExport(Error);
								MessageText = FText::FromString(Error);
								return FReply::Handled();
							})
						]
					]
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
				[
					SNew(STextBlock)
					.AutoWrapText(true)
					.Visibility_Lambda([this]() { return VisibleIf(!MessageText.IsEmpty()); })
					.ColorAndOpacity(FLinearColor(1.f, 0.4f, 0.3f))
					.Text_Lambda([this]() { return MessageText; })
				]
			]
		];
}

TSharedRef<SWidget> SModellingAssistant::BuildResultSection()
{
	return SNew(SBox)
		.Visibility_Lambda([]() { return VisibleIf(IsIn(GetJob().Status, { EJobStatus::Exporting, EJobStatus::Done, EJobStatus::Failed })); })
		[
			SNew(SVerticalBox)

			// Success
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SVerticalBox)
				.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::Done); })
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(STextBlock).Text(LOCTEXT("DoneTitle", "All done!")).Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 6)
				[
					Paragraph(LOCTEXT("DoneText", "Your model was exported as an FBX file. It was also saved as an Unreal asset in the Content Browser."))
				]
				+ SVerticalBox::Slot().AutoHeight()
				[
					ReadOnlyLine(TAttribute<FText>::CreateLambda([]() { return FText::FromString(GetJob().FbxPath); }))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
				[
					SNew(STextBlock).AutoWrapText(true)
					.ColorAndOpacity(FLinearColor(0.6f, 0.6f, 0.6f))
					.Text_Lambda([]() { return FText::Format(LOCTEXT("AssetLine", "Unreal asset: {0}"), FText::FromString(GetJob().AssetPath)); })
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 8, 0)
					[
						SNew(SButton)
						.Text(LOCTEXT("ShowFbx", "Show file"))
						.OnClicked_Lambda([]() { FPlatformProcess::ExploreFolder(*GetJob().FbxPath); return FReply::Handled(); })
					]
					+ SHorizontalBox::Slot().AutoWidth()
					[
						SNew(SButton)
						.Text(LOCTEXT("NewModel", "Start a new model"))
						.OnClicked_Lambda([]() { ResetJob(); return FReply::Handled(); })
					]
				]
			]

			// Failure
			+ SVerticalBox::Slot().AutoHeight()
			[
				SNew(SVerticalBox)
				.Visibility_Lambda([]() { return VisibleIf(GetJob().Status == EJobStatus::Failed); })
				+ SVerticalBox::Slot().AutoHeight()
				[
					SNew(STextBlock).Text(LOCTEXT("FailTitle", "The export did not work")).Font(FCoreStyle::GetDefaultFontStyle("Bold", 16))
					.ColorAndOpacity(FLinearColor(1.f, 0.4f, 0.3f))
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 6, 0, 0)
				[
					SNew(STextBlock).AutoWrapText(true)
					.Text_Lambda([]() { return FText::FromString(GetJob().Error); })
				]
				+ SVerticalBox::Slot().AutoHeight().Padding(0, 8, 0, 0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().AutoWidth().Padding(0, 0, 8, 0)
					[
						SNew(SButton)
						.Text(LOCTEXT("TryAgain", "Try again"))
						.OnClicked_Lambda([]() { FString Error; FinishAndExport(Error); return FReply::Handled(); })
					]
					+ SHorizontalBox::Slot().AutoWidth()
					[
						SNew(SButton)
						.Text(LOCTEXT("StartOver2", "Start over"))
						.OnClicked_Lambda([]() { ResetJob(/*bCancelledByUser=*/true); return FReply::Handled(); })
					]
				]
			]
		];
}

#undef LOCTEXT_NAMESPACE


