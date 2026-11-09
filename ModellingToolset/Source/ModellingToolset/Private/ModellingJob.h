// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * The modelling "job": one request from the user (reference images plus a description) that an AI works on.
 * The Modelling Assistant panel and the AI-facing Job toolset both read and change this single state.
 * Everything here runs on the game thread.
 *
 * Flow:  Idle -> ReadyForAI (user pressed Go) -> Working (AI started) -> ReviewPending (AI finished a version)
 *        -> ChangesRequested (user asked for changes) -> Working ...   or   -> Exporting -> Done / Failed (user pressed Done)
 */
namespace ModellingToolset
{
	enum class EJobStatus : uint8
	{
		Idle,
		ReadyForAI,
		Working,
		ReviewPending,
		ChangesRequested,
		Exporting,
		Done,
		Failed,
	};

	struct FJobState
	{
		EJobStatus Status = EJobStatus::Idle;

		/** Text the user is typing in the panel. Kept so closing and reopening the tab loses nothing. */
		FString DraftInstructions;
		FString DraftName = TEXT("MyModel");

		/** The running job. */
		FString Instructions;
		FString OutputName;
		TArray<FString> Log;
		FString ReviewSummary;
		FString ChangeRequest;
		int32 Revision = 0;

		/** Results of the export. */
		FString AssetPath;
		FString FbxPath;
		FString Error;

		/** Latest screenshot sheet, shown in the review panel. */
		FString LastSheetFile;

		/** True after the user cancelled a running job. Tells the AI to stop; cleared when a new job starts. */
		bool bCancelled = false;
	};

	FJobState& GetJob();

	/** Machine-readable status name used in tool results. */
	const TCHAR* StatusToString(EJobStatus Status);

	/** The one-line message the user pastes into their AI assistant after pressing Go. */
	FString GetStartMessage();

	// ---- User actions (from the panel) ----
	/** Go button. Allowed from Idle, Done or Failed. Needs a non-empty description. */
	bool StartJob(const FString& Instructions, const FString& Name, FString& OutError);
	/** Clears the job and returns to Idle. With bCancelledByUser the AI is told to stop the next time it calls a job tool. */
	void ResetJob(bool bCancelledByUser = false);
	/** "Send changes" button. Allowed while a review is pending. */
	bool SubmitChanges(const FString& ChangeText, FString& OutError);
	/** "Done" button. Exports the FBX. Allowed from ReviewPending, or from Failed to retry. */
	bool FinishAndExport(FString& OutError);

	// ---- AI actions (from the Job toolset) ----
	void AddLog(const FString& Message);
	/** Marks the job as started if the user pressed Go. Returns true if the AI may proceed. */
	bool BeginWorking();
	bool RequestReview(const FString& Summary, FString& OutError);

	/** Decision for the AI. Returns false while the user has not decided yet. Consumes a pending change request. */
	bool TryConsumeDecision(FString& OutJson);
	FString PendingDecisionJson();

	/** JSON describing the job for the AI. */
	FString JobJson();
}

