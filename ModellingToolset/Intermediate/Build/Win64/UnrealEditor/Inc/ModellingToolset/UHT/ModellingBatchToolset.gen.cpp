// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingBatchToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingBatchToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingBatchToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingBatchToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingBatchToolset Function RunBatch *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingBatchToolset_RunBatch_Statics
struct UHT_STATICS
{
	struct ModellingBatchToolset_eventRunBatch_Parms
	{
		FString StepsJson;
		bool bContinueOnError;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Batch" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Runs a list of Modelling tools in order, in one call.\n\x09 *\n\x09 * StepsJson is a JSON array. Each step names a tool and gives its arguments exactly as you would when calling it on its own:\n\x09 *   [\n\x09 *     {\"tool\":\"CreateMeshActor\",\"args\":{\"Name\":\"Tower\",\"Location\":{\"X\":0,\"Y\":0,\"Z\":0},\"Rotation\":{\"Pitch\":0,\"Yaw\":0,\"Roll\":0}}},\n\x09 *     {\"tool\":\"AddCylinder\",\"args\":{\"Name\":\"Tower\",\"Radius\":60,\"Height\":400,\"Location\":{\"X\":0,\"Y\":0,\"Z\":200},\"Rotation\":{\"Pitch\":0,\"Yaw\":0,\"Roll\":0}}},\n\x09 *     {\"tool\":\"PaintPart\",\"args\":{\"Name\":\"Tower\",\"Hex\":\"#EEEEEE\"}}\n\x09 *   ]\n\x09 * Arguments you leave out use the tool's normal defaults. Tool names and argument names are the same as the individual tools.\n\x09 * Works for tools that return text, a yes/no or a number: scene, shapes, edits, deforms, repairs, materials, measuring and saving.\n\x09 * It cannot run tools that return pictures or wait (CaptureViews, CompareToReference, WaitForUserDecision) or RunBatch itself.\n\x09 * Limit: 200 steps per call.\n\x09 *\n\x09 * Returns JSON: how many steps completed, the step that failed (if any) with its error, and each step's result.\n\x09 * After a failure the remaining steps are skipped unless bContinueOnError is true.\n\x09 *\n\x09 * @param StepsJson        The JSON array of steps.\n\x09 * @param bContinueOnError Keep going after a step fails. */" },
#endif
		{ "CPP_Default_bContinueOnError", "false" },
		{ "ModuleRelativePath", "Public/ModellingBatchToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runs a list of Modelling tools in order, in one call.\n\nStepsJson is a JSON array. Each step names a tool and gives its arguments exactly as you would when calling it on its own:\n [\n   {\"tool\":\"CreateMeshActor\",\"args\":{\"Name\":\"Tower\",\"Location\":{\"X\":0,\"Y\":0,\"Z\":0},\"Rotation\":{\"Pitch\":0,\"Yaw\":0,\"Roll\":0}}},\n   {\"tool\":\"AddCylinder\",\"args\":{\"Name\":\"Tower\",\"Radius\":60,\"Height\":400,\"Location\":{\"X\":0,\"Y\":0,\"Z\":200},\"Rotation\":{\"Pitch\":0,\"Yaw\":0,\"Roll\":0}}},\n   {\"tool\":\"PaintPart\",\"args\":{\"Name\":\"Tower\",\"Hex\":\"#EEEEEE\"}}\n ]\nArguments you leave out use the tool's normal defaults. Tool names and argument names are the same as the individual tools.\nWorks for tools that return text, a yes/no or a number: scene, shapes, edits, deforms, repairs, materials, measuring and saving.\nIt cannot run tools that return pictures or wait (CaptureViews, CompareToReference, WaitForUserDecision) or RunBatch itself.\nLimit: 200 steps per call.\n\nReturns JSON: how many steps completed, the step that failed (if any) with its error, and each step's result.\nAfter a failure the remaining steps are skipped unless bContinueOnError is true.\n\n@param StepsJson        The JSON array of steps.\n@param bContinueOnError Keep going after a step fails." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StepsJson_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RunBatch constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_StepsJson;
	static void NewProp_bContinueOnError_SetBit(void* Obj)
	{
		((ModellingBatchToolset_eventRunBatch_Parms*)Obj)->bContinueOnError = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bContinueOnError;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RunBatch constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RunBatch Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_StepsJson = { "StepsJson", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingBatchToolset_eventRunBatch_Parms, StepsJson), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StepsJson_MetaData), NewProp_StepsJson_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bContinueOnError = { "bContinueOnError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingBatchToolset_eventRunBatch_Parms), &UHT_STATICS::NewProp_bContinueOnError_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingBatchToolset_eventRunBatch_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepsJson,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bContinueOnError,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RunBatch Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingBatchToolset, nullptr, "RunBatch", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingBatchToolset_eventRunBatch_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingBatchToolset_eventRunBatch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingBatchToolset_RunBatch(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingBatchToolset::execRunBatch)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_StepsJson);
	P_GET_UBOOL(Z_Param_bContinueOnError);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingBatchToolset::RunBatch(Z_Param_StepsJson,Z_Param_bContinueOnError);
	P_NATIVE_END;
}
// ********** End Class UModellingBatchToolset Function RunBatch ***********************************

// ********** Begin Class UModellingBatchToolset ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingBatchToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Runs many Modelling tools in one call. Blocking out a model takes dozens of small steps (add a box, add a cylinder, paint it);\n * a batch does them all at once, so it is much faster and uses far fewer calls.\n */" },
#endif
		{ "IncludePath", "ModellingBatchToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingBatchToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Runs many Modelling tools in one call. Blocking out a model takes dozens of small steps (add a box, add a cylinder, paint it);\na batch does them all at once, so it is much faster and uses far fewer calls." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingBatchToolset constinit property declarations *******************
// ********** End Class UModellingBatchToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("RunBatch"), .Pointer = &UModellingBatchToolset::execRunBatch },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingBatchToolset_RunBatch, "RunBatch" }, // 928a62741380025c4f70709a1c32f68c44ecf5bf
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingBatchToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingBatchToolset,
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
static void UModellingBatchToolset_StaticRegisterNativesUModellingBatchToolset()
{
	UClass* Class = UModellingBatchToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingBatchToolset;
UClass* Z_Construct_UClass_UModellingBatchToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingBatchToolset;
		if (!Z_Registration_Info_UClass_UModellingBatchToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingBatchToolset"),
				Z_Registration_Info_UClass_UModellingBatchToolset.InnerSingleton,
				UModellingBatchToolset_StaticRegisterNativesUModellingBatchToolset,
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
		return Z_Registration_Info_UClass_UModellingBatchToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingBatchToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingBatchToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingBatchToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingBatchToolset::UModellingBatchToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingBatchToolset);
UModellingBatchToolset::~UModellingBatchToolset() {}
// ********** End Class UModellingBatchToolset *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingBatchToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingBatchToolset, TEXT("UModellingBatchToolset"), &Z_Registration_Info_UClass_UModellingBatchToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingBatchToolset), 2154646506U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingBatchToolset_h__Script_ModellingToolset_2a973c2fa52fa05d8c9ee03a1c1993c98b897ed0{
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
