// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingJobToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingJobToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolCallAsyncResultString(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingJobToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingJobToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingJobToolset Function GetModellingJob ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingJobToolset_GetModellingJob_Statics
struct UHT_STATICS
{
	struct ModellingJobToolset_eventGetModellingJob_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Job" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** ALWAYS CALL THIS FIRST. Returns the user's request as JSON: status, instructions, the list of reference images, the references folder and the next step.\n\x09 * If the status is \"not_started\" the user has not pressed Go in the Modelling Assistant panel: do NOT start modelling, tell the user what to do instead.\n\x09 * If there are reference images, view every one with GetReference before creating any geometry. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ALWAYS CALL THIS FIRST. Returns the user's request as JSON: status, instructions, the list of reference images, the references folder and the next step.\nIf the status is \"not_started\" the user has not pressed Go in the Modelling Assistant panel: do NOT start modelling, tell the user what to do instead.\nIf there are reference images, view every one with GetReference before creating any geometry." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetModellingJob constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetModellingJob constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetModellingJob Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventGetModellingJob_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetModellingJob Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingJobToolset, nullptr, "GetModellingJob", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingJobToolset_eventGetModellingJob_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingJobToolset_eventGetModellingJob_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingJobToolset_GetModellingJob(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingJobToolset::execGetModellingJob)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingJobToolset::GetModellingJob();
	P_NATIVE_END;
}
// ********** End Class UModellingJobToolset Function GetModellingJob ******************************

// ********** Begin Class UModellingJobToolset Function GetUserDecision ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingJobToolset_GetUserDecision_Statics
struct UHT_STATICS
{
	struct ModellingJobToolset_eventGetUserDecision_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Job" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Same as WaitForUserDecision but returns immediately with the current decision (\"pending\" if none). Use it only if waiting is not possible. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Same as WaitForUserDecision but returns immediately with the current decision (\"pending\" if none). Use it only if waiting is not possible." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetUserDecision constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetUserDecision constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetUserDecision Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventGetUserDecision_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetUserDecision Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingJobToolset, nullptr, "GetUserDecision", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingJobToolset_eventGetUserDecision_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingJobToolset_eventGetUserDecision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingJobToolset_GetUserDecision(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingJobToolset::execGetUserDecision)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingJobToolset::GetUserDecision();
	P_NATIVE_END;
}
// ********** End Class UModellingJobToolset Function GetUserDecision ******************************

// ********** Begin Class UModellingJobToolset Function ReportProgress *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingJobToolset_ReportProgress_Statics
struct UHT_STATICS
{
	struct ModellingJobToolset_eventReportProgress_Parms
	{
		FString Message;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Job" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shows a short progress line in the user's panel. Call after each stage, e.g. \"Blocked out the main shapes\" or \"Added windows\".\n\x09 * @param Message  One short plain-language sentence. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows a short progress line in the user's panel. Call after each stage, e.g. \"Blocked out the main shapes\" or \"Added windows\".\n@param Message  One short plain-language sentence." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReportProgress constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReportProgress constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReportProgress Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventReportProgress_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventReportProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ReportProgress Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingJobToolset, nullptr, "ReportProgress", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingJobToolset_eventReportProgress_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingJobToolset_eventReportProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingJobToolset_ReportProgress(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingJobToolset::execReportProgress)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingJobToolset::ReportProgress(Z_Param_Message);
	P_NATIVE_END;
}
// ********** End Class UModellingJobToolset Function ReportProgress *******************************

// ********** Begin Class UModellingJobToolset Function RequestReview ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingJobToolset_RequestReview_Statics
struct UHT_STATICS
{
	struct ModellingJobToolset_eventRequestReview_Parms
	{
		FString Summary;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Job" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Tells the user a version of the model is ready and opens the review screen in their panel (latest screenshot, a box for changes, and a Done button).\n\x09 * Call this only after a final CaptureViews check against the references. Then call WaitForUserDecision.\n\x09 * @param Summary  A short plain-language description of what was built and anything that is approximate or missing. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tells the user a version of the model is ready and opens the review screen in their panel (latest screenshot, a box for changes, and a Done button).\nCall this only after a final CaptureViews check against the references. Then call WaitForUserDecision.\n@param Summary  A short plain-language description of what was built and anything that is approximate or missing." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Summary_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RequestReview constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Summary;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RequestReview constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RequestReview Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Summary = { "Summary", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventRequestReview_Parms, Summary), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Summary_MetaData), NewProp_Summary_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventRequestReview_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Summary,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RequestReview Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingJobToolset, nullptr, "RequestReview", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingJobToolset_eventRequestReview_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingJobToolset_eventRequestReview_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingJobToolset_RequestReview(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingJobToolset::execRequestReview)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Summary);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingJobToolset::RequestReview(Z_Param_Summary);
	P_NATIVE_END;
}
// ********** End Class UModellingJobToolset Function RequestReview ********************************

// ********** Begin Class UModellingJobToolset Function WaitForUserDecision ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingJobToolset_WaitForUserDecision_Statics
struct UHT_STATICS
{
	struct ModellingJobToolset_eventWaitForUserDecision_Parms
	{
		int32 TimeoutSeconds;
		UToolCallAsyncResultString* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Job" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Waits for the user to press \"Send changes\" or \"Done\" in the panel. Returns JSON with \"decision\":\n\x09 *   \"changes\"  - apply the text in \"changes\", then RequestReview again.\n\x09 *   \"done\"     - the user approved it and the plugin exported the FBX; tell the user the \"fbx_path\" and stop.\n\x09 *   \"export_failed\" - tell the user the error.\n\x09 *   \"pending\"  - the user has not decided yet; call this tool again (keep waiting).\n\x09 * Do not export or declare the job finished yourself.\n\x09 * @param TimeoutSeconds  How long to wait before returning \"pending\" (5 to 55). */" },
#endif
		{ "CPP_Default_TimeoutSeconds", "45" },
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Waits for the user to press \"Send changes\" or \"Done\" in the panel. Returns JSON with \"decision\":\n \"changes\"  - apply the text in \"changes\", then RequestReview again.\n \"done\"     - the user approved it and the plugin exported the FBX; tell the user the \"fbx_path\" and stop.\n \"export_failed\" - tell the user the error.\n \"pending\"  - the user has not decided yet; call this tool again (keep waiting).\nDo not export or declare the job finished yourself.\n@param TimeoutSeconds  How long to wait before returning \"pending\" (5 to 55)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function WaitForUserDecision constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_TimeoutSeconds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WaitForUserDecision constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WaitForUserDecision Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_TimeoutSeconds = { "TimeoutSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventWaitForUserDecision_Parms, TimeoutSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingJobToolset_eventWaitForUserDecision_Parms, ReturnValue), Z_Construct_UClass_UToolCallAsyncResultString, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TimeoutSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function WaitForUserDecision Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingJobToolset, nullptr, "WaitForUserDecision", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingJobToolset_eventWaitForUserDecision_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingJobToolset_eventWaitForUserDecision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingJobToolset_WaitForUserDecision(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingJobToolset::execWaitForUserDecision)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TimeoutSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UToolCallAsyncResultString**)Z_Param__Result=UModellingJobToolset::WaitForUserDecision(Z_Param_TimeoutSeconds);
	P_NATIVE_END;
}
// ********** End Class UModellingJobToolset Function WaitForUserDecision **************************

// ********** Begin Class UModellingJobToolset *****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingJobToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * The link between the user's Modelling Assistant panel and the AI.\n * The user fills in the panel (reference images and a description) and presses Go. The AI then:\n *   1. calls GetModellingJob to read the request,\n *   2. studies the reference images, models, and reports progress,\n *   3. calls RequestReview when a version is ready,\n *   4. calls WaitForUserDecision and either applies the user's changes or finishes when the user presses Done\n *      (the plugin itself then exports the FBX).\n */" },
#endif
		{ "IncludePath", "ModellingJobToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingJobToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The link between the user's Modelling Assistant panel and the AI.\nThe user fills in the panel (reference images and a description) and presses Go. The AI then:\n  1. calls GetModellingJob to read the request,\n  2. studies the reference images, models, and reports progress,\n  3. calls RequestReview when a version is ready,\n  4. calls WaitForUserDecision and either applies the user's changes or finishes when the user presses Done\n     (the plugin itself then exports the FBX)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingJobToolset constinit property declarations *********************
// ********** End Class UModellingJobToolset constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetModellingJob"), .Pointer = &UModellingJobToolset::execGetModellingJob },
		{ .NameUTF8 = UTF8TEXT("GetUserDecision"), .Pointer = &UModellingJobToolset::execGetUserDecision },
		{ .NameUTF8 = UTF8TEXT("ReportProgress"), .Pointer = &UModellingJobToolset::execReportProgress },
		{ .NameUTF8 = UTF8TEXT("RequestReview"), .Pointer = &UModellingJobToolset::execRequestReview },
		{ .NameUTF8 = UTF8TEXT("WaitForUserDecision"), .Pointer = &UModellingJobToolset::execWaitForUserDecision },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingJobToolset_GetModellingJob, "GetModellingJob" }, // 81de24358633e9bd5f30592d4f21995f3883712e
		{ &Z_Construct_UFunction_UModellingJobToolset_GetUserDecision, "GetUserDecision" }, // 343e340e3882181c0ed4d95e591e3183528e10aa
		{ &Z_Construct_UFunction_UModellingJobToolset_ReportProgress, "ReportProgress" }, // 8266efebaa286515f86867074d901b786e9c6ee1
		{ &Z_Construct_UFunction_UModellingJobToolset_RequestReview, "RequestReview" }, // fd4a5931bf01a9f25f5f92a491a103bafe99cd12
		{ &Z_Construct_UFunction_UModellingJobToolset_WaitForUserDecision, "WaitForUserDecision" }, // 0d64e62b438aaacf06b6c97251eb71ba9730f81c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingJobToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingJobToolset,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UModellingJobToolset_StaticRegisterNativesUModellingJobToolset()
{
	UClass* Class = UModellingJobToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingJobToolset;
UClass* Z_Construct_UClass_UModellingJobToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingJobToolset;
		if (!Z_Registration_Info_UClass_UModellingJobToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingJobToolset"),
				Z_Registration_Info_UClass_UModellingJobToolset.InnerSingleton,
				UModellingJobToolset_StaticRegisterNativesUModellingJobToolset,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_UModellingJobToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingJobToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingJobToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingJobToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingJobToolset::UModellingJobToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingJobToolset);
UModellingJobToolset::~UModellingJobToolset() {}
// ********** End Class UModellingJobToolset *******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingJobToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingJobToolset, TEXT("UModellingJobToolset"), &Z_Registration_Info_UClass_UModellingJobToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingJobToolset), 1301927233U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingJobToolset_h__Script_ModellingToolset_17bb70440c718be3479db2bb8ac5a09cf8ed72a2{
	TEXT("/Script/ModellingToolset"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
