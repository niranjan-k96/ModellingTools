// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingDeformToolset.h"
#include "ModellingSelection.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingDeformToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingDeformToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingDeformToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingDeformToolset Function Bend ************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Bend_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventBend_Parms
	{
		FString Name;
		float AngleDegrees;
		float Extent;
		FVector Axis;
		FVector Origin;
		FVector BendDirection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bends the mesh along an axis, like bending a tree or a pipe.\n\x09 * @param Name           Actor label.\n\x09 * @param AngleDegrees   Bend angle in degrees. Positive curves the ends toward BendDirection, negative curves them away.\n\x09 * @param Extent         Distance from Origin along the axis over which the bend happens, cm.\n\x09 * @param Axis           Long axis of the object, local space. (0,0,1) for a vertical object.\n\x09 * @param Origin         Point on the axis where the bend is centred, local cm.\n\x09 * @param BendDirection  The direction the ends curve toward, local space. (1,0,0) bends toward +X. Must not be parallel to Axis. */" },
#endif
		{ "CPP_Default_Axis", "0.000000,0.000000,1.000000" },
		{ "CPP_Default_BendDirection", "1.000000,0.000000,0.000000" },
		{ "CPP_Default_Origin", "" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bends the mesh along an axis, like bending a tree or a pipe.\n@param Name           Actor label.\n@param AngleDegrees   Bend angle in degrees. Positive curves the ends toward BendDirection, negative curves them away.\n@param Extent         Distance from Origin along the axis over which the bend happens, cm.\n@param Axis           Long axis of the object, local space. (0,0,1) for a vertical object.\n@param Origin         Point on the axis where the bend is centred, local cm.\n@param BendDirection  The direction the ends curve toward, local space. (1,0,0) bends toward +X. Must not be parallel to Axis." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Axis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BendDirection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Bend constinit property declarations **********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngleDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Extent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BendDirection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Bend constinit property declarations ************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Bend Property Definitions *********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AngleDegrees = { "AngleDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, AngleDegrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, Extent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Axis_MetaData), NewProp_Axis_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_BendDirection = { "BendDirection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, BendDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BendDirection_MetaData), NewProp_BendDirection_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventBend_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AngleDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Extent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Axis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BendDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Bend Property Definitions ***********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Bend", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventBend_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventBend_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Bend(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execBend)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AngleDegrees);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Extent);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Axis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_BendDirection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Bend(Z_Param_Name,Z_Param_AngleDegrees,Z_Param_Extent,Z_Param_Out_Axis,Z_Param_Out_Origin,Z_Param_Out_BendDirection);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Bend **************************************

// ********** Begin Class UModellingDeformToolset Function Flare ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Flare_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventFlare_Parms
	{
		FString Name;
		float FlareX;
		float FlareY;
		float Extent;
		FVector Axis;
		FVector Origin;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Flares (widens) or pinches the mesh along an axis. Use for tapering towers, bottles and horns.\n\x09 * For a vertical object (Axis (0,0,1)): FlareX changes the width along X and FlareY the width along Y.\n\x09 * @param Name       Actor label.\n\x09 * @param FlareX     Percent change of width along X at the far ends of Extent. Negative pinches.\n\x09 * @param FlareY     Percent change of width along Y.\n\x09 * @param Extent     Distance from Origin along the axis over which the flare builds up, cm.\n\x09 * @param Axis       Long axis, local space.\n\x09 * @param Origin     Where the flare starts, local cm. */" },
#endif
		{ "CPP_Default_Axis", "0.000000,0.000000,1.000000" },
		{ "CPP_Default_Origin", "" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Flares (widens) or pinches the mesh along an axis. Use for tapering towers, bottles and horns.\nFor a vertical object (Axis (0,0,1)): FlareX changes the width along X and FlareY the width along Y.\n@param Name       Actor label.\n@param FlareX     Percent change of width along X at the far ends of Extent. Negative pinches.\n@param FlareY     Percent change of width along Y.\n@param Extent     Distance from Origin along the axis over which the flare builds up, cm.\n@param Axis       Long axis, local space.\n@param Origin     Where the flare starts, local cm." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Axis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Flare constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlareX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FlareY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Extent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Flare constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Flare Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FlareX = { "FlareX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, FlareX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_FlareY = { "FlareY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, FlareY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, Extent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Axis_MetaData), NewProp_Axis_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventFlare_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FlareX,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_FlareY,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Extent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Axis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Flare Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Flare", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventFlare_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventFlare_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Flare(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execFlare)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_FlareX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_FlareY);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Extent);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Axis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Flare(Z_Param_Name,Z_Param_FlareX,Z_Param_FlareY,Z_Param_Extent,Z_Param_Out_Axis,Z_Param_Out_Origin);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Flare *************************************

// ********** Begin Class UModellingDeformToolset Function Noise ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Noise_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventNoise_Parms
	{
		FString Name;
		float Magnitude;
		float Frequency;
		int32 Seed;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Displaces vertices along their normals with Perlin noise: rocks, terrain, rough surfaces. Subdivide first.\n\x09 * @param Name        Actor label.\n\x09 * @param Magnitude   Maximum displacement in cm.\n\x09 * @param Frequency   Noise frequency; larger means finer detail.\n\x09 * @param Seed        Random seed for repeatable results.\n\x09 * @param Selection   Which faces to affect. Defaults to all. */" },
#endif
		{ "CPP_Default_Seed", "0" },
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Displaces vertices along their normals with Perlin noise: rocks, terrain, rough surfaces. Subdivide first.\n@param Name        Actor label.\n@param Magnitude   Maximum displacement in cm.\n@param Frequency   Noise frequency; larger means finer detail.\n@param Seed        Random seed for repeatable results.\n@param Selection   Which faces to affect. Defaults to all." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Noise constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Magnitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Seed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Noise constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Noise Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Magnitude = { "Magnitude", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, Magnitude), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, Frequency), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, Seed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventNoise_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Magnitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Frequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Seed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Noise Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Noise", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventNoise_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventNoise_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Noise(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execNoise)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Magnitude);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Frequency);
	P_GET_PROPERTY(FIntProperty,Z_Param_Seed);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Noise(Z_Param_Name,Z_Param_Magnitude,Z_Param_Frequency,Z_Param_Seed,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Noise *************************************

// ********** Begin Class UModellingDeformToolset Function Smooth **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Smooth_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventSmooth_Parms
	{
		FString Name;
		int32 Iterations;
		float Alpha;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Smooths the surface by relaxing vertices.\n\x09 * @param Name        Actor label.\n\x09 * @param Iterations  Number of smoothing passes (1 to 100).\n\x09 * @param Alpha       Strength per pass, 0 to 1.\n\x09 * @param Selection   Which faces to affect. Defaults to all. */" },
#endif
		{ "CPP_Default_Alpha", "0.200000" },
		{ "CPP_Default_Iterations", "10" },
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Smooths the surface by relaxing vertices.\n@param Name        Actor label.\n@param Iterations  Number of smoothing passes (1 to 100).\n@param Alpha       Strength per pass, 0 to 1.\n@param Selection   Which faces to affect. Defaults to all." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Smooth constinit property declarations ********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Iterations;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Smooth constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Smooth Property Definitions *******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSmooth_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Iterations = { "Iterations", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSmooth_Parms, Iterations), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSmooth_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSmooth_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSmooth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Iterations,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Alpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Smooth Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Smooth", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventSmooth_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventSmooth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Smooth(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execSmooth)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_Iterations);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Smooth(Z_Param_Name,Z_Param_Iterations,Z_Param_Alpha,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Smooth ************************************

// ********** Begin Class UModellingDeformToolset Function Subdivide *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Subdivide_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventSubdivide_Parms
	{
		FString Name;
		int32 Level;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Uniformly subdivides every triangle, multiplying the triangle count by (Level+1)^2. Use before bending, twisting or adding noise.\n\x09 * @param Name   Actor label.\n\x09 * @param Level  Subdivision level (1 to 6). */" },
#endif
		{ "CPP_Default_Level", "2" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Uniformly subdivides every triangle, multiplying the triangle count by (Level+1)^2. Use before bending, twisting or adding noise.\n@param Name   Actor label.\n@param Level  Subdivision level (1 to 6)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Subdivide constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Subdivide constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Subdivide Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSubdivide_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSubdivide_Parms, Level), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventSubdivide_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Subdivide Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Subdivide", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventSubdivide_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventSubdivide_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Subdivide(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execSubdivide)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_Level);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Subdivide(Z_Param_Name,Z_Param_Level);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Subdivide *********************************

// ********** Begin Class UModellingDeformToolset Function Twist ***********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingDeformToolset_Twist_Statics
struct UHT_STATICS
{
	struct ModellingDeformToolset_eventTwist_Parms
	{
		FString Name;
		float AngleDegrees;
		float Extent;
		FVector Axis;
		FVector Origin;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Deform" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Twists the mesh around an axis.\n\x09 * @param Name          Actor label.\n\x09 * @param AngleDegrees  Twist angle in degrees at the end of the Extent.\n\x09 * @param Extent        Distance from Origin along the axis over which the twist builds up, cm.\n\x09 * @param Axis          Axis to twist around, local space.\n\x09 * @param Origin        Centre of the twist, local cm. */" },
#endif
		{ "CPP_Default_Axis", "0.000000,0.000000,1.000000" },
		{ "CPP_Default_Origin", "" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Twists the mesh around an axis.\n@param Name          Actor label.\n@param AngleDegrees  Twist angle in degrees at the end of the Extent.\n@param Extent        Distance from Origin along the axis over which the twist builds up, cm.\n@param Axis          Axis to twist around, local space.\n@param Origin        Centre of the twist, local cm." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Axis_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Twist constinit property declarations *********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngleDegrees;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Extent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Axis;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Twist constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Twist Property Definitions ********************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_AngleDegrees = { "AngleDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, AngleDegrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Extent = { "Extent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, Extent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Axis = { "Axis", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, Axis), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Axis_MetaData), NewProp_Axis_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingDeformToolset_eventTwist_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AngleDegrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Extent,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Axis,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Twist Property Definitions **********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingDeformToolset, nullptr, "Twist", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingDeformToolset_eventTwist_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingDeformToolset_eventTwist_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingDeformToolset_Twist(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingDeformToolset::execTwist)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_AngleDegrees);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Extent);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Axis);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingDeformToolset::Twist(Z_Param_Name,Z_Param_AngleDegrees,Z_Param_Extent,Z_Param_Out_Axis,Z_Param_Out_Origin);
	P_NATIVE_END;
}
// ********** End Class UModellingDeformToolset Function Twist *************************************

// ********** Begin Class UModellingDeformToolset **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingDeformToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Shape deformation: bend, twist, flare, noise, smoothing, subdivision. Built on Geometry Script.\n * Warps need enough triangles to look smooth: call Subdivide first on low-poly primitives.\n * Axis arguments are the long axis of the object being deformed, in the actor's local space.\n * Always verify the result with CaptureViews, since the warp direction depends on the axis you pass.\n */" },
#endif
		{ "IncludePath", "ModellingDeformToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingDeformToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shape deformation: bend, twist, flare, noise, smoothing, subdivision. Built on Geometry Script.\nWarps need enough triangles to look smooth: call Subdivide first on low-poly primitives.\nAxis arguments are the long axis of the object being deformed, in the actor's local space.\nAlways verify the result with CaptureViews, since the warp direction depends on the axis you pass." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingDeformToolset constinit property declarations ******************
// ********** End Class UModellingDeformToolset constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Bend"), .Pointer = &UModellingDeformToolset::execBend },
		{ .NameUTF8 = UTF8TEXT("Flare"), .Pointer = &UModellingDeformToolset::execFlare },
		{ .NameUTF8 = UTF8TEXT("Noise"), .Pointer = &UModellingDeformToolset::execNoise },
		{ .NameUTF8 = UTF8TEXT("Smooth"), .Pointer = &UModellingDeformToolset::execSmooth },
		{ .NameUTF8 = UTF8TEXT("Subdivide"), .Pointer = &UModellingDeformToolset::execSubdivide },
		{ .NameUTF8 = UTF8TEXT("Twist"), .Pointer = &UModellingDeformToolset::execTwist },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingDeformToolset_Bend, "Bend" }, // a798bd01eff4878b41940e2dc1d5349f97042ae5
		{ &Z_Construct_UFunction_UModellingDeformToolset_Flare, "Flare" }, // 2e0d1e0c8843dfdda4d65da66d041eef0ddc7a06
		{ &Z_Construct_UFunction_UModellingDeformToolset_Noise, "Noise" }, // 35c994b31481ac89042318201ccbbb1d496c171a
		{ &Z_Construct_UFunction_UModellingDeformToolset_Smooth, "Smooth" }, // 93a4a4fca56c3bd377af8c9dee074bdc036e7bd9
		{ &Z_Construct_UFunction_UModellingDeformToolset_Subdivide, "Subdivide" }, // 6545e8d9cfda0abff507715af59221f1ec223468
		{ &Z_Construct_UFunction_UModellingDeformToolset_Twist, "Twist" }, // f79f79a905ffe70b1deb0c0ac636abac7e6b0975
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingDeformToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingDeformToolset,
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
static void UModellingDeformToolset_StaticRegisterNativesUModellingDeformToolset()
{
	UClass* Class = UModellingDeformToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingDeformToolset;
UClass* Z_Construct_UClass_UModellingDeformToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingDeformToolset;
		if (!Z_Registration_Info_UClass_UModellingDeformToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingDeformToolset"),
				Z_Registration_Info_UClass_UModellingDeformToolset.InnerSingleton,
				UModellingDeformToolset_StaticRegisterNativesUModellingDeformToolset,
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
		return Z_Registration_Info_UClass_UModellingDeformToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingDeformToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingDeformToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingDeformToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingDeformToolset::UModellingDeformToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingDeformToolset);
UModellingDeformToolset::~UModellingDeformToolset() {}
// ********** End Class UModellingDeformToolset ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingDeformToolset, TEXT("UModellingDeformToolset"), &Z_Registration_Info_UClass_UModellingDeformToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingDeformToolset), 3792648798U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h__Script_ModellingToolset_3b412704a6d243e3f7b439efbe219457a69f3de5{
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
