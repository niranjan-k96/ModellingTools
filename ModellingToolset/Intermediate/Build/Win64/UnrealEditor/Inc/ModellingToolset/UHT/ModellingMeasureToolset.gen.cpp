// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingMeasureToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingMeasureToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingMeasureToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingMeasureToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingMeasureToolset Function MeasureDistance ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMeasureToolset_MeasureDistance_Statics
struct UHT_STATICS
{
	struct ModellingMeasureToolset_eventMeasureDistance_Parms
	{
		FString NameA;
		FString NameB;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Measure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance between two parts. Returns the shortest gap between their surfaces (0 if they touch or overlap), the distance between their centres,\n\x09 * and the two closest points. Good for checking that parts connect or that spacing is right.\n\x09 * @param NameA  First actor label.\n\x09 * @param NameB  Second actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingMeasureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance between two parts. Returns the shortest gap between their surfaces (0 if they touch or overlap), the distance between their centres,\nand the two closest points. Good for checking that parts connect or that spacing is right.\n@param NameA  First actor label.\n@param NameB  Second actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameA_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameB_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MeasureDistance constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_NameA;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NameB;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MeasureDistance constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MeasureDistance Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_NameA = { "NameA", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventMeasureDistance_Parms, NameA), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameA_MetaData), NewProp_NameA_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_NameB = { "NameB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventMeasureDistance_Parms, NameB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameB_MetaData), NewProp_NameB_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventMeasureDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NameA,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NameB,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MeasureDistance Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMeasureToolset, nullptr, "MeasureDistance", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMeasureToolset_eventMeasureDistance_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMeasureToolset_eventMeasureDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMeasureToolset_MeasureDistance(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMeasureToolset::execMeasureDistance)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_NameA);
	P_GET_PROPERTY(FStrProperty,Z_Param_NameB);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMeasureToolset::MeasureDistance(Z_Param_NameA,Z_Param_NameB);
	P_NATIVE_END;
}
// ********** End Class UModellingMeasureToolset Function MeasureDistance **************************

// ********** Begin Class UModellingMeasureToolset Function MeasureModel ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMeasureToolset_MeasureModel_Statics
struct UHT_STATICS
{
	struct ModellingMeasureToolset_eventMeasureModel_Parms
	{
		FString ActorNames;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Measure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Overall size of the whole model (or of chosen parts): width (X), depth (Y), height (Z), the lowest and highest points, and the centre.\n\x09 * @param ActorNames  Comma-separated actor labels. Empty measures every actor the toolset created. */" },
#endif
		{ "CPP_Default_ActorNames", "" },
		{ "ModuleRelativePath", "Public/ModellingMeasureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overall size of the whole model (or of chosen parts): width (X), depth (Y), height (Z), the lowest and highest points, and the centre.\n@param ActorNames  Comma-separated actor labels. Empty measures every actor the toolset created." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MeasureModel constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MeasureModel constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MeasureModel Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ActorNames = { "ActorNames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventMeasureModel_Parms, ActorNames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorNames_MetaData), NewProp_ActorNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventMeasureModel_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MeasureModel Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMeasureToolset, nullptr, "MeasureModel", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMeasureToolset_eventMeasureModel_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMeasureToolset_eventMeasureModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMeasureToolset_MeasureModel(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMeasureToolset::execMeasureModel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMeasureToolset::MeasureModel(Z_Param_ActorNames);
	P_NATIVE_END;
}
// ********** End Class UModellingMeasureToolset Function MeasureModel *****************************

// ********** Begin Class UModellingMeasureToolset Function Raycast ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMeasureToolset_Raycast_Statics
struct UHT_STATICS
{
	struct ModellingMeasureToolset_eventRaycast_Parms
	{
		FVector Origin;
		FVector Direction;
		float MaxDistance;
		FString ActorNames;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Measure" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shoots a ray through the model and reports the first surface it hits: which part, where, the distance and the surface direction.\n\x09 * Use it to measure heights and openings, for example shoot straight down from above a doorway and read the hit point's Z, or shoot sideways through a window.\n\x09 * @param Origin       Ray start in world space.\n\x09 * @param Direction    Ray direction (it is normalised for you).\n\x09 * @param MaxDistance  How far to look, cm.\n\x09 * @param ActorNames   Comma-separated actor labels to test. Empty tests every actor the toolset created. */" },
#endif
		{ "CPP_Default_ActorNames", "" },
		{ "CPP_Default_MaxDistance", "100000.000000" },
		{ "ModuleRelativePath", "Public/ModellingMeasureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shoots a ray through the model and reports the first surface it hits: which part, where, the distance and the surface direction.\nUse it to measure heights and openings, for example shoot straight down from above a doorway and read the hit point's Z, or shoot sideways through a window.\n@param Origin       Ray start in world space.\n@param Direction    Ray direction (it is normalised for you).\n@param MaxDistance  How far to look, cm.\n@param ActorNames   Comma-separated actor labels to test. Empty tests every actor the toolset created." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Raycast constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistance;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Raycast constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Raycast Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventRaycast_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventRaycast_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxDistance = { "MaxDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventRaycast_Parms, MaxDistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ActorNames = { "ActorNames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventRaycast_Parms, ActorNames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorNames_MetaData), NewProp_ActorNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMeasureToolset_eventRaycast_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Direction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Raycast Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMeasureToolset, nullptr, "Raycast", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMeasureToolset_eventRaycast_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMeasureToolset_eventRaycast_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMeasureToolset_Raycast(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMeasureToolset::execRaycast)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Direction);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxDistance);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMeasureToolset::Raycast(Z_Param_Out_Origin,Z_Param_Out_Direction,Z_Param_MaxDistance,Z_Param_ActorNames);
	P_NATIVE_END;
}
// ********** End Class UModellingMeasureToolset Function Raycast **********************************

// ********** Begin Class UModellingMeasureToolset *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingMeasureToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Measuring tools, so real sizes in the notes (\"the door is 2 metres tall\") can be checked instead of eyeballed.\n * All values are world-space centimetres.\n */" },
#endif
		{ "IncludePath", "ModellingMeasureToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingMeasureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Measuring tools, so real sizes in the notes (\"the door is 2 metres tall\") can be checked instead of eyeballed.\nAll values are world-space centimetres." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingMeasureToolset constinit property declarations *****************
// ********** End Class UModellingMeasureToolset constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("MeasureDistance"), .Pointer = &UModellingMeasureToolset::execMeasureDistance },
		{ .NameUTF8 = UTF8TEXT("MeasureModel"), .Pointer = &UModellingMeasureToolset::execMeasureModel },
		{ .NameUTF8 = UTF8TEXT("Raycast"), .Pointer = &UModellingMeasureToolset::execRaycast },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingMeasureToolset_MeasureDistance, "MeasureDistance" }, // 92047aa06e05c76007387c3e0bbc1e2b96ff791d
		{ &Z_Construct_UFunction_UModellingMeasureToolset_MeasureModel, "MeasureModel" }, // 4015ea3294f9dadd38bc9056f63a820e401f39a1
		{ &Z_Construct_UFunction_UModellingMeasureToolset_Raycast, "Raycast" }, // f8f2c5f9c1a1f5f02656daa206ba3a284a28bbed
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingMeasureToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingMeasureToolset,
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
static void UModellingMeasureToolset_StaticRegisterNativesUModellingMeasureToolset()
{
	UClass* Class = UModellingMeasureToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingMeasureToolset;
UClass* Z_Construct_UClass_UModellingMeasureToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingMeasureToolset;
		if (!Z_Registration_Info_UClass_UModellingMeasureToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingMeasureToolset"),
				Z_Registration_Info_UClass_UModellingMeasureToolset.InnerSingleton,
				UModellingMeasureToolset_StaticRegisterNativesUModellingMeasureToolset,
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
		return Z_Registration_Info_UClass_UModellingMeasureToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingMeasureToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingMeasureToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingMeasureToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingMeasureToolset::UModellingMeasureToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingMeasureToolset);
UModellingMeasureToolset::~UModellingMeasureToolset() {}
// ********** End Class UModellingMeasureToolset ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMeasureToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingMeasureToolset, TEXT("UModellingMeasureToolset"), &Z_Registration_Info_UClass_UModellingMeasureToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingMeasureToolset), 1210217862U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMeasureToolset_h__Script_ModellingToolset_4660d03f8053a50c98b8f647e68ea929e44f7fab{
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
