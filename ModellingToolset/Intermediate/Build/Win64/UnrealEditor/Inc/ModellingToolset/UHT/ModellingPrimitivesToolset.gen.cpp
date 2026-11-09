// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingPrimitivesToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingPrimitivesToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingPrimitivesToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingPrimitivesToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingPrimitivesToolset Function AddArch *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddArch_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddArch_Parms
	{
		FString Name;
		float OuterWidth;
		float TotalHeight;
		float Depth;
		float BandWidth;
		FVector Location;
		FRotator Rotation;
		int32 Segments;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds an arch with an opening: doorways, windows, bridges, gates. The arch stands in the XZ plane (width along X, height along Z, thickness along Y).\n\x09 * @param Name               Target actor label.\n\x09 * @param OuterWidth         Full outside width, cm.\n\x09 * @param TotalHeight        Full height from the ground to the top of the curve, cm.\n\x09 * @param Depth              Thickness of the wall, along Y, cm.\n\x09 * @param BandWidth          Thickness of the arch band on each side and over the top, cm (less than half of OuterWidth).\n\x09 * @param Location           Centre of the arch's bounding box in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param Segments           Smoothness of the curve (4 to 64).\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_Segments", "16" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds an arch with an opening: doorways, windows, bridges, gates. The arch stands in the XZ plane (width along X, height along Z, thickness along Y).\n@param Name               Target actor label.\n@param OuterWidth         Full outside width, cm.\n@param TotalHeight        Full height from the ground to the top of the curve, cm.\n@param Depth              Thickness of the wall, along Y, cm.\n@param BandWidth          Thickness of the arch band on each side and over the top, cm (less than half of OuterWidth).\n@param Location           Centre of the arch's bounding box in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param Segments           Smoothness of the curve (4 to 64).\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddArch constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OuterWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BandWidth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Segments;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddArch_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddArch constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddArch Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_OuterWidth = { "OuterWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, OuterWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TotalHeight = { "TotalHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, TotalHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, Depth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BandWidth = { "BandWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, BandWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Segments = { "Segments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, Segments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddArch_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddArch_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OuterWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TotalHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Depth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BandWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Segments,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddArch Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddArch", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddArch_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddArch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddArch(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddArch)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_OuterWidth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TotalHeight);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Depth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BandWidth);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FIntProperty,Z_Param_Segments);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddArch(Z_Param_Name,Z_Param_OuterWidth,Z_Param_TotalHeight,Z_Param_Depth,Z_Param_BandWidth,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Segments,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddArch *******************************

// ********** Begin Class UModellingPrimitivesToolset Function AddBox ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddBox_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddBox_Parms
	{
		FString Name;
		FVector Size;
		FVector Location;
		FRotator Rotation;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a box.\n\x09 * @param Name               Target actor label.\n\x09 * @param Size               Full size in cm along X, Y, Z.\n\x09 * @param Location           Box centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a box.\n@param Name               Target actor label.\n@param Size               Full size in cm along X, Y, Z.\n@param Location           Box centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddBox constinit property declarations ********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddBox_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddBox constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddBox Property Definitions *******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddBox_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddBox_Parms, Size), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddBox_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddBox_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddBox_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddBox_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Size,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddBox Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddBox", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddBox_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddBox_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddBox(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddBox)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Size);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddBox(Z_Param_Name,Z_Param_Out_Size,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddBox ********************************

// ********** Begin Class UModellingPrimitivesToolset Function AddCapsule **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddCapsule_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddCapsule_Parms
	{
		FString Name;
		float Radius;
		float LineLength;
		FVector Location;
		FRotator Rotation;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a capsule whose axis is local Z.\n\x09 * @param Name               Target actor label.\n\x09 * @param Radius             Radius in cm.\n\x09 * @param LineLength         Length of the straight section in cm (total height is LineLength + 2*Radius).\n\x09 * @param Location           Centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a capsule whose axis is local Z.\n@param Name               Target actor label.\n@param Radius             Radius in cm.\n@param LineLength         Length of the straight section in cm (total height is LineLength + 2*Radius).\n@param Location           Centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCapsule constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineLength;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCapsule_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCapsule constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCapsule Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_LineLength = { "LineLength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, LineLength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCapsule_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCapsule_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LineLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddCapsule Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddCapsule", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddCapsule_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddCapsule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddCapsule(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddCapsule)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_LineLength);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddCapsule(Z_Param_Name,Z_Param_Radius,Z_Param_LineLength,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddCapsule ****************************

// ********** Begin Class UModellingPrimitivesToolset Function AddCone *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddCone_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddCone_Parms
	{
		FString Name;
		float BaseRadius;
		float TopRadius;
		float Height;
		FVector Location;
		FRotator Rotation;
		int32 Segments;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a cone or truncated cone (frustum) whose axis is local Z.\n\x09 * @param Name               Target actor label.\n\x09 * @param BaseRadius         Radius at the bottom, cm.\n\x09 * @param TopRadius          Radius at the top, cm. 0 gives a sharp cone.\n\x09 * @param Height             Height in cm.\n\x09 * @param Location           Centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param Segments           Radial segments (3 to 128).\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_Segments", "24" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a cone or truncated cone (frustum) whose axis is local Z.\n@param Name               Target actor label.\n@param BaseRadius         Radius at the bottom, cm.\n@param TopRadius          Radius at the top, cm. 0 gives a sharp cone.\n@param Height             Height in cm.\n@param Location           Centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param Segments           Radial segments (3 to 128).\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCone constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TopRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Segments;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCone_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCone constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCone Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_BaseRadius = { "BaseRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, BaseRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TopRadius = { "TopRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, TopRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Segments = { "Segments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, Segments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCone_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCone_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BaseRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TopRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Segments,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddCone Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddCone", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddCone_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddCone_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddCone(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddCone)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_BaseRadius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TopRadius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Height);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FIntProperty,Z_Param_Segments);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddCone(Z_Param_Name,Z_Param_BaseRadius,Z_Param_TopRadius,Z_Param_Height,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Segments,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddCone *******************************

// ********** Begin Class UModellingPrimitivesToolset Function AddCurvedStairs *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddCurvedStairs_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddCurvedStairs_Parms
	{
		FString Name;
		int32 NumSteps;
		float StepWidth;
		float StepHeight;
		float InnerRadius;
		float CurveAngle;
		FVector Location;
		FRotator Rotation;
		bool bFloating;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a curved (spiral-style) staircase.\n\x09 * @param Name               Target actor label.\n\x09 * @param NumSteps           Number of steps (1 to 100).\n\x09 * @param StepWidth          Width of the stairs, cm.\n\x09 * @param StepHeight         Rise of each step, cm.\n\x09 * @param InnerRadius        Radius of the inside edge, cm.\n\x09 * @param CurveAngle         Total turn in degrees (90 is a quarter turn, 360 a full spiral).\n\x09 * @param Location           Position of the bottom of the stairs, actor-local cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param bFloating          Floating steps with no solid underside.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_bFloating", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a curved (spiral-style) staircase.\n@param Name               Target actor label.\n@param NumSteps           Number of steps (1 to 100).\n@param StepWidth          Width of the stairs, cm.\n@param StepHeight         Rise of each step, cm.\n@param InnerRadius        Radius of the inside edge, cm.\n@param CurveAngle         Total turn in degrees (90 is a quarter turn, 360 a full spiral).\n@param Location           Position of the bottom of the stairs, actor-local cm.\n@param Rotation           Local rotation in degrees.\n@param bFloating          Floating steps with no solid underside.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCurvedStairs constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumSteps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StepWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StepHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InnerRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurveAngle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bFloating_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCurvedStairs_Parms*)Obj)->bFloating = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFloating;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCurvedStairs_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCurvedStairs constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCurvedStairs Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumSteps = { "NumSteps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, NumSteps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StepWidth = { "StepWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, StepWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StepHeight = { "StepHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, StepHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_InnerRadius = { "InnerRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, InnerRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CurveAngle = { "CurveAngle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, CurveAngle), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFloating = { "bFloating", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms), &UHT_STATICS::NewProp_bFloating_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCurvedStairs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_InnerRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CurveAngle,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFloating,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddCurvedStairs Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddCurvedStairs", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddCurvedStairs_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddCurvedStairs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddCurvedStairs(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddCurvedStairs)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_NumSteps);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StepWidth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StepHeight);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InnerRadius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurveAngle);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_UBOOL(Z_Param_bFloating);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddCurvedStairs(Z_Param_Name,Z_Param_NumSteps,Z_Param_StepWidth,Z_Param_StepHeight,Z_Param_InnerRadius,Z_Param_CurveAngle,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_bFloating,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddCurvedStairs ***********************

// ********** Begin Class UModellingPrimitivesToolset Function AddCylinder *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddCylinder_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddCylinder_Parms
	{
		FString Name;
		float Radius;
		float Height;
		FVector Location;
		FRotator Rotation;
		int32 Segments;
		bool bCapped;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a cylinder whose axis is local Z.\n\x09 * @param Name               Target actor label.\n\x09 * @param Radius             Radius in cm.\n\x09 * @param Height             Height in cm.\n\x09 * @param Location           Cylinder centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param Segments           Radial segments (3 to 128).\n\x09 * @param bCapped            Whether the end caps are closed.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCapped", "true" },
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_Segments", "24" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a cylinder whose axis is local Z.\n@param Name               Target actor label.\n@param Radius             Radius in cm.\n@param Height             Height in cm.\n@param Location           Cylinder centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param Segments           Radial segments (3 to 128).\n@param bCapped            Whether the end caps are closed.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddCylinder constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Segments;
	static void NewProp_bCapped_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCylinder_Parms*)Obj)->bCapped = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCapped;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddCylinder_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddCylinder constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddCylinder Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Segments = { "Segments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, Segments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCapped = { "bCapped", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCylinder_Parms), &UHT_STATICS::NewProp_bCapped_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddCylinder_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddCylinder_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Segments,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCapped,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddCylinder Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddCylinder", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddCylinder_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddCylinder_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddCylinder(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddCylinder)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Height);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FIntProperty,Z_Param_Segments);
	P_GET_UBOOL(Z_Param_bCapped);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddCylinder(Z_Param_Name,Z_Param_Radius,Z_Param_Height,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Segments,Z_Param_bCapped,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddCylinder ***************************

// ********** Begin Class UModellingPrimitivesToolset Function AddExtrudedPolygon ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddExtrudedPolygon_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms
	{
		FString Name;
		TArray<FVector2D> Outline;
		float Height;
		FVector Location;
		FRotator Rotation;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Pulls a flat outline straight up into a solid: floor plans, walls with odd shapes, L-shaped buildings, gears, signs.\n\x09 * @param Name               Target actor label.\n\x09 * @param Outline            Corner points of the shape as X, Y in cm, in order around the edge (at least 3). Either direction works.\n\x09 * @param Height             How tall to make it, cm.\n\x09 * @param Location           Centre of the solid in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pulls a flat outline straight up into a solid: floor plans, walls with odd shapes, L-shaped buildings, gears, signs.\n@param Name               Target actor label.\n@param Outline            Corner points of the shape as X, Y in cm, in order around the edge (at least 3). Either direction works.\n@param Height             How tall to make it, cm.\n@param Location           Centre of the solid in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Outline_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddExtrudedPolygon constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Outline_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Outline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddExtrudedPolygon constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddExtrudedPolygon Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Outline_Inner = { "Outline", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Outline = { "Outline", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, Outline), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Outline_MetaData), NewProp_Outline_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, Height), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Outline_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Outline,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Height,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddExtrudedPolygon Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddExtrudedPolygon", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddExtrudedPolygon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddExtrudedPolygon(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddExtrudedPolygon)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_TARRAY_REF(FVector2D,Z_Param_Out_Outline);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Height);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddExtrudedPolygon(Z_Param_Name,Z_Param_Out_Outline,Z_Param_Height,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddExtrudedPolygon ********************

// ********** Begin Class UModellingPrimitivesToolset Function AddRevolve **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddRevolve_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddRevolve_Parms
	{
		FString Name;
		TArray<FVector2D> Profile;
		FVector Location;
		FRotator Rotation;
		float Degrees;
		int32 Steps;
		bool bCapped;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spins an outline around the vertical axis to make round objects: vases, bottles, towers, domes, columns, bowls, lamp shades.\n\x09 * Give the profile as (radius, height) points from bottom to top, describing the shape of one side. Example vase: [(0,0),(30,0),(40,40),(25,90),(15,110),(18,120)].\n\x09 * @param Name               Target actor label.\n\x09 * @param Profile            Points as X = distance from the axis (cm, 0 or more), Y = height (cm). At least 2 points.\n\x09 * @param Location           Position in actor-local space, cm. The profile's height 0 sits at Location.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param Degrees            How far to spin: 360 is a full turn, less leaves a wedge.\n\x09 * @param Steps              Segments around the turn (3 to 128).\n\x09 * @param bCapped            Close the ends when the profile does not reach the axis.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCapped", "true" },
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_Degrees", "360.000000" },
		{ "CPP_Default_Steps", "32" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spins an outline around the vertical axis to make round objects: vases, bottles, towers, domes, columns, bowls, lamp shades.\nGive the profile as (radius, height) points from bottom to top, describing the shape of one side. Example vase: [(0,0),(30,0),(40,40),(25,90),(15,110),(18,120)].\n@param Name               Target actor label.\n@param Profile            Points as X = distance from the axis (cm, 0 or more), Y = height (cm). At least 2 points.\n@param Location           Position in actor-local space, cm. The profile's height 0 sits at Location.\n@param Rotation           Local rotation in degrees.\n@param Degrees            How far to spin: 360 is a full turn, less leaves a wedge.\n@param Steps              Segments around the turn (3 to 128).\n@param bCapped            Close the ends when the profile does not reach the axis.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddRevolve constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Degrees;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Steps;
	static void NewProp_bCapped_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddRevolve_Parms*)Obj)->bCapped = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCapped;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddRevolve_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddRevolve constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddRevolve Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Profile_Inner = { "Profile", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Profile), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Degrees = { "Degrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Degrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Steps = { "Steps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, Steps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCapped = { "bCapped", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddRevolve_Parms), &UHT_STATICS::NewProp_bCapped_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddRevolve_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddRevolve_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Profile_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Profile,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Degrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Steps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCapped,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddRevolve Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddRevolve", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddRevolve_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddRevolve_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddRevolve(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddRevolve)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_TARRAY_REF(FVector2D,Z_Param_Out_Profile);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Degrees);
	P_GET_PROPERTY(FIntProperty,Z_Param_Steps);
	P_GET_UBOOL(Z_Param_bCapped);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddRevolve(Z_Param_Name,Z_Param_Out_Profile,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Degrees,Z_Param_Steps,Z_Param_bCapped,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddRevolve ****************************

// ********** Begin Class UModellingPrimitivesToolset Function AddSphere ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddSphere_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddSphere_Parms
	{
		FString Name;
		float Radius;
		FVector Location;
		FRotator Rotation;
		int32 Segments;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a UV-sphere.\n\x09 * @param Name               Target actor label.\n\x09 * @param Radius             Radius in cm.\n\x09 * @param Location           Sphere centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param Segments           Longitudinal segments (3 to 128). Latitude segments are Segments/2.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_Segments", "24" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a UV-sphere.\n@param Name               Target actor label.\n@param Radius             Radius in cm.\n@param Location           Sphere centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param Segments           Longitudinal segments (3 to 128). Latitude segments are Segments/2.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddSphere constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Segments;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddSphere_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddSphere constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddSphere Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, Radius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Segments = { "Segments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, Segments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddSphere_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSphere_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Segments,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddSphere Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddSphere", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddSphere_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddSphere_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddSphere(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddSphere)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radius);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FIntProperty,Z_Param_Segments);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddSphere(Z_Param_Name,Z_Param_Radius,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Segments,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddSphere *****************************

// ********** Begin Class UModellingPrimitivesToolset Function AddStairs ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddStairs_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddStairs_Parms
	{
		FString Name;
		int32 NumSteps;
		float StepWidth;
		float StepHeight;
		float StepDepth;
		FVector Location;
		FRotator Rotation;
		bool bFloating;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a straight staircase. It climbs along +X and rises along +Z.\n\x09 * @param Name               Target actor label.\n\x09 * @param NumSteps           Number of steps (1 to 100).\n\x09 * @param StepWidth          Width of the staircase across Y, cm.\n\x09 * @param StepHeight         Rise of each step, cm.\n\x09 * @param StepDepth          Run of each step, cm.\n\x09 * @param Location           Position of the bottom front of the stairs, actor-local cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param bFloating          Floating steps with no solid underside.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_bFloating", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a straight staircase. It climbs along +X and rises along +Z.\n@param Name               Target actor label.\n@param NumSteps           Number of steps (1 to 100).\n@param StepWidth          Width of the staircase across Y, cm.\n@param StepHeight         Rise of each step, cm.\n@param StepDepth          Run of each step, cm.\n@param Location           Position of the bottom front of the stairs, actor-local cm.\n@param Rotation           Local rotation in degrees.\n@param bFloating          Floating steps with no solid underside.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddStairs constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumSteps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StepWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StepHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StepDepth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static void NewProp_bFloating_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddStairs_Parms*)Obj)->bFloating = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFloating;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddStairs_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddStairs constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddStairs Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_NumSteps = { "NumSteps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, NumSteps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StepWidth = { "StepWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, StepWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StepHeight = { "StepHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, StepHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_StepDepth = { "StepDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, StepDepth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFloating = { "bFloating", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddStairs_Parms), &UHT_STATICS::NewProp_bFloating_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddStairs_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddStairs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_NumSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_StepDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFloating,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddStairs Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddStairs", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddStairs_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddStairs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddStairs(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddStairs)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_NumSteps);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StepWidth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StepHeight);
	P_GET_PROPERTY(FFloatProperty,Z_Param_StepDepth);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_UBOOL(Z_Param_bFloating);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddStairs(Z_Param_Name,Z_Param_NumSteps,Z_Param_StepWidth,Z_Param_StepHeight,Z_Param_StepDepth,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_bFloating,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddStairs *****************************

// ********** Begin Class UModellingPrimitivesToolset Function AddSweep ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddSweep_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddSweep_Parms
	{
		FString Name;
		TArray<FVector2D> Profile;
		TArray<FVector> Path;
		bool bLoop;
		bool bCapped;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Drags a cross-section along a path to make pipes, railings, cables, beams, rails and ropes.\n\x09 * @param Name               Target actor label.\n\x09 * @param Profile            Cross-section corner points as X, Y in cm (at least 3). A circle needs about 8 or more points.\n\x09 * @param Path               Points the section travels through, actor-local cm (at least 2).\n\x09 * @param bLoop              Connect the last path point back to the first (rings, frames).\n\x09 * @param bCapped            Close the two ends.\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCapped", "true" },
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_bLoop", "false" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Drags a cross-section along a path to make pipes, railings, cables, beams, rails and ropes.\n@param Name               Target actor label.\n@param Profile            Cross-section corner points as X, Y in cm (at least 3). A circle needs about 8 or more points.\n@param Path               Points the section travels through, actor-local cm (at least 2).\n@param bLoop              Connect the last path point back to the first (rings, frames).\n@param bCapped            Close the two ends.\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Profile_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddSweep constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Profile;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Path_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Path;
	static void NewProp_bLoop_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddSweep_Parms*)Obj)->bLoop = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoop;
	static void NewProp_bCapped_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddSweep_Parms*)Obj)->bCapped = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCapped;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddSweep_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddSweep constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddSweep Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSweep_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Profile_Inner = { "Profile", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSweep_Parms, Profile), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Profile_MetaData), NewProp_Profile_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Path_Inner = { "Path", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSweep_Parms, Path), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bLoop = { "bLoop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddSweep_Parms), &UHT_STATICS::NewProp_bLoop_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCapped = { "bCapped", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddSweep_Parms), &UHT_STATICS::NewProp_bCapped_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddSweep_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddSweep_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Profile_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Profile,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Path_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bLoop,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCapped,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddSweep Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddSweep", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddSweep_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddSweep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddSweep(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddSweep)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_TARRAY_REF(FVector2D,Z_Param_Out_Profile);
	P_GET_TARRAY_REF(FVector,Z_Param_Out_Path);
	P_GET_UBOOL(Z_Param_bLoop);
	P_GET_UBOOL(Z_Param_bCapped);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddSweep(Z_Param_Name,Z_Param_Out_Profile,Z_Param_Out_Path,Z_Param_bLoop,Z_Param_bCapped,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddSweep ******************************

// ********** Begin Class UModellingPrimitivesToolset Function AddTorus ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingPrimitivesToolset_AddTorus_Statics
struct UHT_STATICS
{
	struct ModellingPrimitivesToolset_eventAddTorus_Parms
	{
		FString Name;
		float MajorRadius;
		float MinorRadius;
		FVector Location;
		FRotator Rotation;
		int32 MajorSteps;
		int32 MinorSteps;
		bool bCreateIfMissing;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Primitives" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds a torus lying in the local XY plane.\n\x09 * @param Name               Target actor label.\n\x09 * @param MajorRadius        Distance from the torus centre to the tube centre, cm.\n\x09 * @param MinorRadius        Tube radius, cm.\n\x09 * @param Location           Centre in actor-local space, cm.\n\x09 * @param Rotation           Local rotation in degrees.\n\x09 * @param MajorSteps         Segments around the ring (3 to 128).\n\x09 * @param MinorSteps         Segments around the tube (3 to 64).\n\x09 * @param bCreateIfMissing   Create the actor if it does not exist. */" },
#endif
		{ "CPP_Default_bCreateIfMissing", "false" },
		{ "CPP_Default_MajorSteps", "32" },
		{ "CPP_Default_MinorSteps", "12" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a torus lying in the local XY plane.\n@param Name               Target actor label.\n@param MajorRadius        Distance from the torus centre to the tube centre, cm.\n@param MinorRadius        Tube radius, cm.\n@param Location           Centre in actor-local space, cm.\n@param Rotation           Local rotation in degrees.\n@param MajorSteps         Segments around the ring (3 to 128).\n@param MinorSteps         Segments around the tube (3 to 64).\n@param bCreateIfMissing   Create the actor if it does not exist." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddTorus constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MajorRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinorRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MajorSteps;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinorSteps;
	static void NewProp_bCreateIfMissing_SetBit(void* Obj)
	{
		((ModellingPrimitivesToolset_eventAddTorus_Parms*)Obj)->bCreateIfMissing = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateIfMissing;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTorus constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTorus Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MajorRadius = { "MajorRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, MajorRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MinorRadius = { "MinorRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, MinorRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MajorSteps = { "MajorSteps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, MajorSteps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinorSteps = { "MinorSteps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, MinorSteps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCreateIfMissing = { "bCreateIfMissing", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingPrimitivesToolset_eventAddTorus_Parms), &UHT_STATICS::NewProp_bCreateIfMissing_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingPrimitivesToolset_eventAddTorus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MajorRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinorRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MajorSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinorSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCreateIfMissing,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AddTorus Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingPrimitivesToolset, nullptr, "AddTorus", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingPrimitivesToolset_eventAddTorus_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingPrimitivesToolset_eventAddTorus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingPrimitivesToolset_AddTorus(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingPrimitivesToolset::execAddTorus)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MajorRadius);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MinorRadius);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_PROPERTY(FIntProperty,Z_Param_MajorSteps);
	P_GET_PROPERTY(FIntProperty,Z_Param_MinorSteps);
	P_GET_UBOOL(Z_Param_bCreateIfMissing);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingPrimitivesToolset::AddTorus(Z_Param_Name,Z_Param_MajorRadius,Z_Param_MinorRadius,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_MajorSteps,Z_Param_MinorSteps,Z_Param_bCreateIfMissing);
	P_NATIVE_END;
}
// ********** End Class UModellingPrimitivesToolset Function AddTorus ******************************

// ********** Begin Class UModellingPrimitivesToolset **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingPrimitivesToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Appends primitive shapes to a mesh actor using Geometry Script.\n * The actor must already exist (CreateMeshActor), unless bCreateIfMissing is true, which creates it at the origin.\n * Primitives are centred on Location, which is in the actor's LOCAL space (cm). Rotation is local, in degrees.\n * Combine several primitives in one actor to build a single mesh, or use separate actors per part.\n */" },
#endif
		{ "IncludePath", "ModellingPrimitivesToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingPrimitivesToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Appends primitive shapes to a mesh actor using Geometry Script.\nThe actor must already exist (CreateMeshActor), unless bCreateIfMissing is true, which creates it at the origin.\nPrimitives are centred on Location, which is in the actor's LOCAL space (cm). Rotation is local, in degrees.\nCombine several primitives in one actor to build a single mesh, or use separate actors per part." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingPrimitivesToolset constinit property declarations **************
// ********** End Class UModellingPrimitivesToolset constinit property declarations ****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddArch"), .Pointer = &UModellingPrimitivesToolset::execAddArch },
		{ .NameUTF8 = UTF8TEXT("AddBox"), .Pointer = &UModellingPrimitivesToolset::execAddBox },
		{ .NameUTF8 = UTF8TEXT("AddCapsule"), .Pointer = &UModellingPrimitivesToolset::execAddCapsule },
		{ .NameUTF8 = UTF8TEXT("AddCone"), .Pointer = &UModellingPrimitivesToolset::execAddCone },
		{ .NameUTF8 = UTF8TEXT("AddCurvedStairs"), .Pointer = &UModellingPrimitivesToolset::execAddCurvedStairs },
		{ .NameUTF8 = UTF8TEXT("AddCylinder"), .Pointer = &UModellingPrimitivesToolset::execAddCylinder },
		{ .NameUTF8 = UTF8TEXT("AddExtrudedPolygon"), .Pointer = &UModellingPrimitivesToolset::execAddExtrudedPolygon },
		{ .NameUTF8 = UTF8TEXT("AddRevolve"), .Pointer = &UModellingPrimitivesToolset::execAddRevolve },
		{ .NameUTF8 = UTF8TEXT("AddSphere"), .Pointer = &UModellingPrimitivesToolset::execAddSphere },
		{ .NameUTF8 = UTF8TEXT("AddStairs"), .Pointer = &UModellingPrimitivesToolset::execAddStairs },
		{ .NameUTF8 = UTF8TEXT("AddSweep"), .Pointer = &UModellingPrimitivesToolset::execAddSweep },
		{ .NameUTF8 = UTF8TEXT("AddTorus"), .Pointer = &UModellingPrimitivesToolset::execAddTorus },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddArch, "AddArch" }, // 634a5bf3e11a72d39fc1991129d41a0532dbdede
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddBox, "AddBox" }, // b844fb86895f3cf0821ff79fddada11b0b1cbc6a
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddCapsule, "AddCapsule" }, // d41efe03620d9295b4bf54733c5a64b6281480cc
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddCone, "AddCone" }, // 44f639205a435b9749a39b60c92ba3a95aca3937
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddCurvedStairs, "AddCurvedStairs" }, // d4f872b7be2d74d3d2f56014696d9dd512f002ad
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddCylinder, "AddCylinder" }, // a6680c6b96d704a4e210eae9994c02eb11cd9e93
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddExtrudedPolygon, "AddExtrudedPolygon" }, // 9de6e8992042b6b3e9f8b58c8a040d554589de46
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddRevolve, "AddRevolve" }, // 1792d616845e062c72548eaf21d280ddcc02149e
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddSphere, "AddSphere" }, // 293fc6b794a3e9cd7ed213be538eb7fa2334d289
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddStairs, "AddStairs" }, // 218d578e39dbf6e1a1c306de6d8051fd6c5fc3e8
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddSweep, "AddSweep" }, // 101a10485b0e21b70a2bbadee9e0030d7c9fecff
		{ &Z_Construct_UFunction_UModellingPrimitivesToolset_AddTorus, "AddTorus" }, // 09fb61a4edfb749434233c7e3eee7951acbbc719
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingPrimitivesToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingPrimitivesToolset,
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
static void UModellingPrimitivesToolset_StaticRegisterNativesUModellingPrimitivesToolset()
{
	UClass* Class = UModellingPrimitivesToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingPrimitivesToolset;
UClass* Z_Construct_UClass_UModellingPrimitivesToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingPrimitivesToolset;
		if (!Z_Registration_Info_UClass_UModellingPrimitivesToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingPrimitivesToolset"),
				Z_Registration_Info_UClass_UModellingPrimitivesToolset.InnerSingleton,
				UModellingPrimitivesToolset_StaticRegisterNativesUModellingPrimitivesToolset,
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
		return Z_Registration_Info_UClass_UModellingPrimitivesToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingPrimitivesToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingPrimitivesToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingPrimitivesToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingPrimitivesToolset::UModellingPrimitivesToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingPrimitivesToolset);
UModellingPrimitivesToolset::~UModellingPrimitivesToolset() {}
// ********** End Class UModellingPrimitivesToolset ************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingPrimitivesToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingPrimitivesToolset, TEXT("UModellingPrimitivesToolset"), &Z_Registration_Info_UClass_UModellingPrimitivesToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingPrimitivesToolset), 53779733U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingPrimitivesToolset_h__Script_ModellingToolset_2c707eed7200f4af857593a3f147c2ca3140e57c{
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
