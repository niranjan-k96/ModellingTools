// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingJobToolset.h"

#include "ModellingJob.h"
#include "ModellingToolsetUtils.h"

#include "Containers/Ticker.h"
#include "HAL/PlatformTime.h"

using namespace ModellingToolset;

namespace
{
	/**
	 * Completes an async tool result when the user decides, or after a timeout. It polls on the game thread, so the
	 * editor and the Slate panel stay fully responsive while the AI waits.
	 */
	struct FDecisionWaiter : TSharedFromThis<FDecisionWaiter>
	{
		UToolCallAsyncResultString* Result = nullptr;
		double Deadline = 0.0;
		FTSTicker::FDelegateHandle Handle;

		void Start()
		{
			Result->AddToRoot(); // keep alive until completed
			Handle = FTSTicker::GetCoreTicker().AddTicker(
				FTickerDelegate::CreateLambda([This = AsShared()](float) { return This->Tick(); }), 0.2f);
		}

		bool Tick()
		{
			FString Json;
			if (TryConsumeDecision(Json))
			{
				Complete(Json);
				return false;
			}
			if (FPlatformTime::Seconds() >= Deadline)
			{
				Complete(PendingDecisionJson());
				return false;
			}
			return true;
		}

		void Complete(const FString& Json)
		{
			Result->SetValue(Json);
			Result->RemoveFromRoot();
		}
	};
}

FString UModellingJobToolset::GetModellingJob()
{
	EnsureWorkspaceFolders();
	BeginWorking(); // moves "ready" to "working" the first time the AI asks
	return JobJson();
}

FString UModellingJobToolset::ReportProgress(const FString& Message)
{
	if (Message.TrimStartAndEnd().IsEmpty())
	{
		Fail(TEXT("Message must not be empty."));
		return FString();
	}
	if (GetJob().Status == EJobStatus::Idle && GetJob().bCancelled)
	{
		Fail(TEXT("The user cancelled this job. Stop immediately and tell the user you stopped."));
		return FString();
	}
	AddLog(Message.TrimStartAndEnd());
	return TEXT("ok");
}

FString UModellingJobToolset::RequestReview(const FString& Summary)
{
	FString Error;
	if (GetJob().Status == EJobStatus::Idle && GetJob().bCancelled)
	{
		Fail(TEXT("The user cancelled this job. Stop immediately and tell the user you stopped."));
		return FString();
	}
	if (!ModellingToolset::RequestReview(Summary, Error))
	{
		Fail(Error);
		return FString();
	}
	return TEXT("The review screen is now showing in the user's Modelling Assistant panel. Call WaitForUserDecision now. Do not say you are finished.");
}

UToolCallAsyncResultString* UModellingJobToolset::WaitForUserDecision(int32 TimeoutSeconds)
{
	TSharedRef<FDecisionWaiter> Waiter = MakeShared<FDecisionWaiter>();
	Waiter->Result = NewObject<UToolCallAsyncResultString>();
	Waiter->Deadline = FPlatformTime::Seconds() + FMath::Clamp(TimeoutSeconds, 5, 55);
	Waiter->Start();
	return Waiter->Result;
}

FString UModellingJobToolset::GetUserDecision()
{
	FString Json;
	return TryConsumeDecision(Json) ? Json : PendingDecisionJson();
}

