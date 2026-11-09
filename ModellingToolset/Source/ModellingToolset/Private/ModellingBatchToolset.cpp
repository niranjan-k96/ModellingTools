// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingBatchToolset.h"

#include "ModellingToolsetUtils.h"

#include "ModellingAssetToolset.h"
#include "ModellingDeformToolset.h"
#include "ModellingEditToolset.h"
#include "ModellingJobToolset.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingMeasureToolset.h"
#include "ModellingPrimitivesToolset.h"
#include "ModellingReferenceToolset.h"
#include "ModellingSceneToolset.h"
#include "ModellingTopologyToolset.h"

#include "JsonObjectConverter.h"
#include "Serialization/JsonSerializer.h"
#include "UObject/UnrealType.h"

using namespace ModellingToolset;

namespace
{
	constexpr int32 MaxSteps = 200;

	/** Tools that are never run from a batch. */
	bool IsBlocked(const FName& Name)
	{
		static const TSet<FName> Blocked = {
			TEXT("RunBatch"), TEXT("WaitForUserDecision"), TEXT("CaptureViews"), TEXT("CompareToReference"),
			TEXT("GetProgressImage"), TEXT("GetReference") };
		return Blocked.Contains(Name);
	}

	/** Finds one of this plugin's AI-callable tools by name. */
	UFunction* FindTool(const FString& ToolName, UObject*& OutObject)
	{
		static const TArray<UClass*> Classes = {
			UModellingSceneToolset::StaticClass(), UModellingPrimitivesToolset::StaticClass(), UModellingEditToolset::StaticClass(),
			UModellingDeformToolset::StaticClass(), UModellingTopologyToolset::StaticClass(), UModellingMaterialsToolset::StaticClass(),
			UModellingMeasureToolset::StaticClass(), UModellingAssetToolset::StaticClass(), UModellingReferenceToolset::StaticClass(),
			UModellingJobToolset::StaticClass() };
		for (UClass* Class : Classes)
		{
			if (UFunction* Function = Class->FindFunctionByName(FName(*ToolName), EIncludeSuperFlag::ExcludeSuper))
			{
				if (Function->HasMetaData(TEXT("AICallable")) && !IsBlocked(Function->GetFName()))
				{
					OutObject = Class->GetDefaultObject();
					return Function;
				}
			}
		}
		return nullptr;
	}

	/** Fills in the C++ default for every argument the caller left out. */
	void ApplyDefaults(UFunction* Function, uint8* Params, const TSharedPtr<FJsonObject>& Args)
	{
		for (TFieldIterator<FProperty> It(Function); It; ++It)
		{
			FProperty* Property = *It;
			if (!Property->HasAnyPropertyFlags(CPF_Parm) || Property->HasAnyPropertyFlags(CPF_ReturnParm | CPF_OutParm))
			{
				continue;
			}
			if (Args.IsValid() && Args->HasField(Property->GetName()))
			{
				continue;
			}
			const FString Default = Function->GetMetaData(*(TEXT("CPP_Default_") + Property->GetName()));
			if (!Default.IsEmpty())
			{
				Property->ImportText_Direct(*Default, Property->ContainerPtrToValuePtr<void>(Params), nullptr, PPF_None);
			}
		}
	}

	/** Result value as text, for the tools a batch supports. Returns false for other return types. */
	bool ReadResult(UFunction* Function, uint8* Params, FString& OutText)
	{
		FProperty* Return = Function->GetReturnProperty();
		if (!Return)
		{
			OutText = TEXT("ok");
			return true;
		}
		const void* Value = Return->ContainerPtrToValuePtr<void>(Params);
		if (const FStrProperty* Str = CastField<FStrProperty>(Return)) { OutText = Str->GetPropertyValue(Value); return true; }
		if (const FBoolProperty* Bool = CastField<FBoolProperty>(Return)) { OutText = Bool->GetPropertyValue(Value) ? TEXT("true") : TEXT("false"); return true; }
		if (const FIntProperty* Int = CastField<FIntProperty>(Return)) { OutText = FString::FromInt(Int->GetPropertyValue(Value)); return true; }
		return false;
	}
}

FString UModellingBatchToolset::RunBatch(const FString& StepsJson, bool bContinueOnError)
{
	TArray<TSharedPtr<FJsonValue>> Steps;
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(StepsJson), Steps))
	{
		Fail(TEXT("StepsJson is not a valid JSON array. Expected [{\"tool\":\"AddBox\",\"args\":{...}}, ...]."));
		return FString();
	}
	if (Steps.IsEmpty() || Steps.Num() > MaxSteps)
	{
		Fail(FString::Printf(TEXT("Give between 1 and %d steps."), MaxSteps));
		return FString();
	}

	TArray<TSharedPtr<FJsonValue>> Results;
	int32 Completed = 0;
	int32 FailedAt = 0;
	FString FirstError;

	for (int32 i = 0; i < Steps.Num(); ++i)
	{
		TSharedRef<FJsonObject> Entry = MakeShared<FJsonObject>();
		Entry->SetNumberField(TEXT("step"), i + 1);

		FString Error;
		const TSharedPtr<FJsonObject>* StepObject = nullptr;
		FString ToolName;
		if (!Steps[i]->TryGetObject(StepObject) || !(*StepObject)->TryGetStringField(TEXT("tool"), ToolName) || ToolName.IsEmpty())
		{
			Error = TEXT("Each step must be an object with a \"tool\" name.");
		}
		else
		{
			Entry->SetStringField(TEXT("tool"), ToolName);
			UObject* Object = nullptr;
			UFunction* Function = FindTool(ToolName, Object);
			if (!Function)
			{
				Error = FString::Printf(TEXT("'%s' is not a tool a batch can run (unknown, or it returns a picture or waits)."), *ToolName);
			}
			else
			{
				const TSharedPtr<FJsonObject>* ArgsObject = nullptr;
				TSharedPtr<FJsonObject> Args;
				if ((*StepObject)->TryGetObjectField(TEXT("args"), ArgsObject)) { Args = *ArgsObject; }

				uint8* Params = static_cast<uint8*>(FMemory_Alloca(Function->ParmsSize));
				FMemory::Memzero(Params, Function->ParmsSize);
				Function->InitializeStruct(Params);

				bool bArgsOk = true;
				if (Args.IsValid() && !FJsonObjectConverter::JsonObjectToUStruct(Args.ToSharedRef(), Function, Params, 0, 0))
				{
					bArgsOk = false;
					Error = FString::Printf(TEXT("The arguments for '%s' could not be read. Check the argument names and value types."), *ToolName);
				}
				if (bArgsOk)
				{
					ApplyDefaults(Function, Params, Args);

					FString Text;
					{
						// The tool reports its own errors here instead of aborting the whole batch.
						FErrorCapture Capture;
						Object->ProcessEvent(Function, Params);
						Error = Capture.Message;
					}
					if (Error.IsEmpty())
					{
						if (ReadResult(Function, Params, Text))
						{
							// Tools return JSON text; embed it as JSON so the answer stays easy to read.
							TSharedPtr<FJsonValue> Parsed;
							if (Text.StartsWith(TEXT("{")) || Text.StartsWith(TEXT("[")))
							{
								if (FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Text), Parsed) && Parsed.IsValid())
								{
									Entry->SetField(TEXT("result"), Parsed);
								}
							}
							if (!Entry->HasField(TEXT("result"))) { Entry->SetStringField(TEXT("result"), Text); }
						}
						else
						{
							Error = FString::Printf(TEXT("'%s' returns something a batch cannot show."), *ToolName);
						}
					}
				}
				Function->DestroyStruct(Params);
			}
		}

		if (Error.IsEmpty())
		{
			Entry->SetBoolField(TEXT("ok"), true);
			++Completed;
		}
		else
		{
			Entry->SetBoolField(TEXT("ok"), false);
			Entry->SetStringField(TEXT("error"), Error);
			if (FailedAt == 0) { FailedAt = i + 1; FirstError = Error; }
		}
		Results.Add(MakeShared<FJsonValueObject>(Entry));

		if (!Error.IsEmpty() && !bContinueOnError)
		{
			break;
		}
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetNumberField(TEXT("steps_requested"), Steps.Num());
	Out->SetNumberField(TEXT("steps_completed"), Completed);
	Out->SetNumberField(TEXT("steps_run"), Results.Num());
	if (FailedAt > 0)
	{
		Out->SetNumberField(TEXT("failed_at_step"), FailedAt);
		Out->SetStringField(TEXT("first_error"), FirstError);
		Out->SetStringField(TEXT("note"), bContinueOnError ? TEXT("Some steps failed; the rest were still run.") : TEXT("The batch stopped at the failed step. Earlier steps were applied. Fix the step and run the remaining ones."));
	}
	Out->SetArrayField(TEXT("results"), Results);
	return ToJsonString(Out);
}
