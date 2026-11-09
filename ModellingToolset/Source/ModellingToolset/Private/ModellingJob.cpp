// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingJob.h"

#include "ModellingExport.h"
#include "ModellingToolsetUtils.h"

#include "Misc/DateTime.h"
#include "Serialization/JsonSerializer.h"

namespace ModellingToolset
{
	namespace
	{
		constexpr int32 MaxLogLines = 200;

		TSharedRef<FJsonObject> BaseJson()
		{
			TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
			Out->SetStringField(TEXT("status"), StatusToString(GetJob().Status));
			return Out;
		}

		FString CleanName(const FString& In)
		{
			FString Name = SanitizeFileName(In.TrimStartAndEnd());
			return Name.IsEmpty() ? FString(TEXT("MyModel")) : Name;
		}
	}

	FJobState& GetJob()
	{
		static FJobState State;
		return State;
	}

	const TCHAR* StatusToString(EJobStatus Status)
	{
		switch (Status)
		{
		case EJobStatus::Idle:             return TEXT("not_started");
		case EJobStatus::ReadyForAI:       return TEXT("ready");
		case EJobStatus::Working:          return TEXT("working");
		case EJobStatus::ReviewPending:    return TEXT("review_pending");
		case EJobStatus::ChangesRequested: return TEXT("changes_requested");
		case EJobStatus::Exporting:        return TEXT("exporting");
		case EJobStatus::Done:             return TEXT("done");
		case EJobStatus::Failed:           return TEXT("export_failed");
		}
		return TEXT("unknown");
	}

	FString GetStartMessage()
	{
		return TEXT("Start the Modelling Toolset job. Call GetModellingJob first, look at every reference image, then follow the modelling workflow skill step by step.");
	}

	void AddLog(const FString& Message)
	{
		FJobState& Job = GetJob();
		Job.Log.Add(FString::Printf(TEXT("[%s] %s"), *FDateTime::Now().ToString(TEXT("%H:%M:%S")), *Message));
		while (Job.Log.Num() > MaxLogLines)
		{
			Job.Log.RemoveAt(0);
		}
	}

	bool StartJob(const FString& Instructions, const FString& Name, FString& OutError)
	{
		FJobState& Job = GetJob();
		if (Job.Status != EJobStatus::Idle && Job.Status != EJobStatus::Done && Job.Status != EJobStatus::Failed)
		{
			OutError = TEXT("A job is already running. Finish it or press Cancel first.");
			return false;
		}
		if (Instructions.TrimStartAndEnd().IsEmpty())
		{
			OutError = TEXT("Please describe what you want to build in step 2.");
			return false;
		}

		Job.Instructions = Instructions.TrimStartAndEnd();
		Job.OutputName = CleanName(Name);
		Job.Log.Reset();
		Job.ReviewSummary.Reset();
		Job.ChangeRequest.Reset();
		Job.Revision = 0;
		Job.AssetPath.Reset();
		Job.FbxPath.Reset();
		Job.Error.Reset();
		Job.LastSheetFile.Reset();
		Job.bCancelled = false;
		Job.Status = EJobStatus::ReadyForAI;
		AddLog(TEXT("Job started. Waiting for the AI assistant."));
		return true;
	}

	void ResetJob(bool bCancelledByUser)
	{
		FJobState& Job = GetJob();
		Job.bCancelled = bCancelledByUser && Job.Status != EJobStatus::Idle && Job.Status != EJobStatus::Done;
		Job.Status = EJobStatus::Idle;
		Job.Log.Reset();
		Job.ReviewSummary.Reset();
		Job.ChangeRequest.Reset();
		Job.Revision = 0;
		Job.AssetPath.Reset();
		Job.FbxPath.Reset();
		Job.Error.Reset();
		Job.LastSheetFile.Reset();
	}

	bool SubmitChanges(const FString& ChangeText, FString& OutError)
	{
		FJobState& Job = GetJob();
		if (Job.Status != EJobStatus::ReviewPending)
		{
			OutError = TEXT("Changes can only be sent while a review is waiting.");
			return false;
		}
		if (ChangeText.TrimStartAndEnd().IsEmpty())
		{
			OutError = TEXT("Please write what you would like changed.");
			return false;
		}
		Job.ChangeRequest = ChangeText.TrimStartAndEnd();
		Job.Status = EJobStatus::ChangesRequested;
		AddLog(TEXT("You asked for changes: ") + Job.ChangeRequest);
		return true;
	}

	bool FinishAndExport(FString& OutError)
	{
		FJobState& Job = GetJob();
		if (Job.Status != EJobStatus::ReviewPending && Job.Status != EJobStatus::Failed)
		{
			OutError = TEXT("The model can only be exported while a review is waiting.");
			return false;
		}

		Job.Status = EJobStatus::Exporting;
		AddLog(TEXT("Exporting the model as FBX..."));

		const FExportResult Result = ExportModelToFbx(Job.OutputName);
		if (Result.bOk)
		{
			Job.AssetPath = Result.AssetPath;
			Job.FbxPath = Result.FbxPath;
			Job.Error.Reset();
			Job.Status = EJobStatus::Done;
			AddLog(TEXT("Exported: ") + Result.FbxPath + TEXT(" (texture layout ") + Result.UVNote + TEXT(")"));
			return true;
		}

		Job.AssetPath = Result.AssetPath;
		Job.Error = Result.Error;
		Job.Status = EJobStatus::Failed;
		AddLog(TEXT("Export failed: ") + Result.Error);
		OutError = Result.Error;
		return false;
	}

	bool BeginWorking()
	{
		FJobState& Job = GetJob();
		if (Job.Status == EJobStatus::ReadyForAI)
		{
			Job.Status = EJobStatus::Working;
			AddLog(TEXT("The AI assistant started working."));
			return true;
		}
		return Job.Status == EJobStatus::Working;
	}

	bool RequestReview(const FString& Summary, FString& OutError)
	{
		FJobState& Job = GetJob();
		if (Job.Status != EJobStatus::Working)
		{
			OutError = FString::Printf(TEXT("A review can only be requested while the job is 'working' (it is '%s')."), StatusToString(Job.Status));
			return false;
		}
		Job.ReviewSummary = Summary.TrimStartAndEnd();
		Job.Status = EJobStatus::ReviewPending;
		AddLog(TEXT("The AI finished a version and is waiting for your review."));
		return true;
	}

	FString PendingDecisionJson()
	{
		TSharedRef<FJsonObject> Out = BaseJson();
		Out->SetStringField(TEXT("decision"), TEXT("pending"));
		Out->SetStringField(TEXT("instruction"), TEXT("The user has not decided yet. Call WaitForUserDecision again. Do not export or say you are finished."));
		return ToJsonString(Out);
	}

	bool TryConsumeDecision(FString& OutJson)
	{
		FJobState& Job = GetJob();
		TSharedRef<FJsonObject> Out = BaseJson();

		if (Job.Status == EJobStatus::Idle && Job.bCancelled)
		{
			Out->SetStringField(TEXT("decision"), TEXT("cancelled"));
			Out->SetStringField(TEXT("instruction"), TEXT("The user cancelled the job. Stop immediately. Do not continue modelling and do not call more job tools. Tell the user you stopped."));
			OutJson = ToJsonString(Out);
			return true;
		}

		switch (Job.Status)
		{
		case EJobStatus::ReviewPending:
		case EJobStatus::Exporting:
			return false;

		case EJobStatus::ChangesRequested:
			++Job.Revision;
			Out->SetStringField(TEXT("decision"), TEXT("changes"));
			Out->SetStringField(TEXT("changes"), Job.ChangeRequest);
			Out->SetNumberField(TEXT("revision"), Job.Revision);
			Out->SetStringField(TEXT("instruction"), TEXT("Apply these changes, check your work with CaptureViews, then call RequestReview again followed by WaitForUserDecision."));
			Job.Status = EJobStatus::Working;
			AddLog(FString::Printf(TEXT("The AI is applying your changes (version %d)."), Job.Revision + 1));
			break;

		case EJobStatus::Done:
			Out->SetStringField(TEXT("decision"), TEXT("done"));
			Out->SetStringField(TEXT("fbx_path"), Job.FbxPath);
			Out->SetStringField(TEXT("asset_path"), Job.AssetPath);
			Out->SetStringField(TEXT("instruction"), TEXT("The user approved the model and it was exported. Tell the user where the FBX file is, then stop."));
			break;

		case EJobStatus::Failed:
			Out->SetStringField(TEXT("decision"), TEXT("export_failed"));
			Out->SetStringField(TEXT("error"), Job.Error);
			Out->SetStringField(TEXT("instruction"), TEXT("The export failed. Tell the user the error. The user can retry from the panel. Call WaitForUserDecision again if they retry."));
			break;

		default:
			Out->SetStringField(TEXT("decision"), TEXT("not_in_review"));
			Out->SetStringField(TEXT("instruction"), TEXT("There is no review in progress. If the model is ready, call RequestReview first, then WaitForUserDecision."));
			break;
		}

		OutJson = ToJsonString(Out);
		return true;
	}

	FString JobJson()
	{
		FJobState& Job = GetJob();
		TSharedRef<FJsonObject> Out = BaseJson();

		TArray<TSharedPtr<FJsonValue>> References;
		for (const FString& Name : ListReferenceImageNames())
		{
			References.Add(MakeShared<FJsonValueString>(Name));
		}
		Out->SetArrayField(TEXT("references"), References);
		Out->SetStringField(TEXT("references_folder"), GetReferencesDir());
		Out->SetStringField(TEXT("instructions"), Job.Instructions);
		Out->SetStringField(TEXT("output_name"), Job.OutputName);
		Out->SetNumberField(TEXT("revision"), Job.Revision);

		FString Next;
		if (Job.Status == EJobStatus::Idle && Job.bCancelled)
		{
			Out->SetBoolField(TEXT("cancelled"), true);
			Out->SetStringField(TEXT("next_step"), TEXT("The user cancelled the job. Stop immediately and tell the user you stopped. Do not continue modelling."));
			return ToJsonString(Out);
		}
		switch (Job.Status)
		{
		case EJobStatus::Idle:
			Next = TEXT("The user has not pressed Go yet. Do NOT start modelling. Tell the user to follow the steps in the Modelling Assistant panel (toolbar button) and press Go, then ask them to tell you when to start.");
			break;
		case EJobStatus::ReadyForAI:
		case EJobStatus::Working:
			Next = References.IsEmpty()
				? TEXT("No reference images were provided: model from the instructions only. Follow the modelling workflow skill.")
				: TEXT("FIRST call GetReference for EVERY image in 'references' and study each one with its notes. Do not create any geometry before that. Then follow the modelling workflow skill.");
			break;
		case EJobStatus::ReviewPending:
			Next = TEXT("A review is already waiting for the user. Call WaitForUserDecision.");
			break;
		case EJobStatus::ChangesRequested:
			Next = TEXT("The user asked for changes. Call WaitForUserDecision to receive them.");
			break;
		case EJobStatus::Done:
			Next = TEXT("The job is finished. The model was exported to the FBX file in 'fbx_path'.");
			Out->SetStringField(TEXT("fbx_path"), Job.FbxPath);
			break;
		default:
			Next = TEXT("Wait for the user.");
			break;
		}
		Out->SetStringField(TEXT("next_step"), Next);
		return ToJsonString(Out);
	}
}


