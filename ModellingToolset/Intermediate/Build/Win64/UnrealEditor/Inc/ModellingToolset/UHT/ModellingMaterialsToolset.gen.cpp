// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingSelection.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingMaterialsToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingMaterialsToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingMaterialsToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingMaterialsToolset Function AssignMaterial ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_AssignMaterial_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventAssignMaterial_Parms
	{
		FString Name;
		int32 SlotIndex;
		FString MaterialPath;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts an existing material (yours or the engine's) in a slot of a part.\n\x09 * @param Name          Actor label.\n\x09 * @param SlotIndex     Material slot number, 0 or higher (see ListMaterialSlots).\n\x09 * @param MaterialPath  Asset path, e.g. \"/Game/Materials/M_Brick\" or \"/Engine/BasicShapes/BasicShapeMaterial\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts an existing material (yours or the engine's) in a slot of a part.\n@param Name          Actor label.\n@param SlotIndex     Material slot number, 0 or higher (see ListMaterialSlots).\n@param MaterialPath  Asset path, e.g. \"/Game/Materials/M_Brick\" or \"/Engine/BasicShapes/BasicShapeMaterial\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AssignMaterial constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AssignMaterial constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AssignMaterial Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventAssignMaterial_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventAssignMaterial_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialPath = { "MaterialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventAssignMaterial_Parms, MaterialPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialPath_MetaData), NewProp_MaterialPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventAssignMaterial_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AssignMaterial Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "AssignMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventAssignMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventAssignMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_AssignMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execAssignMaterial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::AssignMaterial(Z_Param_Name,Z_Param_SlotIndex,Z_Param_MaterialPath);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function AssignMaterial *************************

// ********** Begin Class UModellingMaterialsToolset Function CreateColorMaterial ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_CreateColorMaterial_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventCreateColorMaterial_Parms
	{
		FString MaterialName;
		FString Hex;
		float Roughness;
		float Metallic;
		float EmissiveStrength;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Creates (or updates) a reusable material of one colour and returns its asset path.\n\x09 * @param MaterialName     Short name, e.g. \"RedRoof\". The asset becomes MI_<name>.\n\x09 * @param Hex              Colour like \"#C03A2B\" (sRGB, as read from a picture).\n\x09 * @param Roughness        0 = mirror smooth, 1 = fully matte.\n\x09 * @param Metallic         0 = plastic, stone or wood, 1 = bare metal.\n\x09 * @param EmissiveStrength 0 for none; above 0 makes it glow in its own colour (lamps, windows at night). */" },
#endif
		{ "CPP_Default_EmissiveStrength", "0.000000" },
		{ "CPP_Default_Metallic", "0.000000" },
		{ "CPP_Default_Roughness", "0.600000" },
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates (or updates) a reusable material of one colour and returns its asset path.\n@param MaterialName     Short name, e.g. \"RedRoof\". The asset becomes MI_<name>.\n@param Hex              Colour like \"#C03A2B\" (sRGB, as read from a picture).\n@param Roughness        0 = mirror smooth, 1 = fully matte.\n@param Metallic         0 = plastic, stone or wood, 1 = bare metal.\n@param EmissiveStrength 0 for none; above 0 makes it glow in its own colour (lamps, windows at night)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CreateColorMaterial constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Hex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EmissiveStrength;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateColorMaterial constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateColorMaterial Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialName = { "MaterialName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, MaterialName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialName_MetaData), NewProp_MaterialName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Hex = { "Hex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, Hex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hex_MetaData), NewProp_Hex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, Metallic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_EmissiveStrength = { "EmissiveStrength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, EmissiveStrength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventCreateColorMaterial_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_EmissiveStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CreateColorMaterial Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "CreateColorMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventCreateColorMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventCreateColorMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_CreateColorMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execCreateColorMaterial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Hex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Metallic);
	P_GET_PROPERTY(FFloatProperty,Z_Param_EmissiveStrength);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::CreateColorMaterial(Z_Param_MaterialName,Z_Param_Hex,Z_Param_Roughness,Z_Param_Metallic,Z_Param_EmissiveStrength);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function CreateColorMaterial ********************

// ********** Begin Class UModellingMaterialsToolset Function GetReferencePalette ******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_GetReferencePalette_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventGetReferencePalette_Parms
	{
		FString Name;
		int32 ColorCount;
		bool bIgnoreBackground;
		float RegionX;
		float RegionY;
		float RegionWidth;
		float RegionHeight;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Finds the main colours in a reference image, so you can match them instead of guessing. Returns JSON: the dominant colours as hex with the\n\x09 * percentage of the picture each covers (largest first), plus the average colour. Use a region to sample one part of the picture, for example just the roof.\n\x09 * @param Name              Reference file name from ListReferences.\n\x09 * @param ColorCount        How many colours to return (2 to 8).\n\x09 * @param bIgnoreBackground Ignore the plain background (estimated from the picture edges) so only the object is analysed.\n\x09 * @param RegionX           Left edge of the region, 0 to 1 (0 = left of the picture).\n\x09 * @param RegionY           Top edge of the region, 0 to 1 (0 = top).\n\x09 * @param RegionWidth       Width of the region, 0 to 1. 1 means the full width.\n\x09 * @param RegionHeight      Height of the region, 0 to 1. 1 means the full height. */" },
#endif
		{ "CPP_Default_bIgnoreBackground", "true" },
		{ "CPP_Default_ColorCount", "5" },
		{ "CPP_Default_RegionHeight", "1.000000" },
		{ "CPP_Default_RegionWidth", "1.000000" },
		{ "CPP_Default_RegionX", "0.000000" },
		{ "CPP_Default_RegionY", "0.000000" },
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finds the main colours in a reference image, so you can match them instead of guessing. Returns JSON: the dominant colours as hex with the\npercentage of the picture each covers (largest first), plus the average colour. Use a region to sample one part of the picture, for example just the roof.\n@param Name              Reference file name from ListReferences.\n@param ColorCount        How many colours to return (2 to 8).\n@param bIgnoreBackground Ignore the plain background (estimated from the picture edges) so only the object is analysed.\n@param RegionX           Left edge of the region, 0 to 1 (0 = left of the picture).\n@param RegionY           Top edge of the region, 0 to 1 (0 = top).\n@param RegionWidth       Width of the region, 0 to 1. 1 means the full width.\n@param RegionHeight      Height of the region, 0 to 1. 1 means the full height." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetReferencePalette constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ColorCount;
	static void NewProp_bIgnoreBackground_SetBit(void* Obj)
	{
		((ModellingMaterialsToolset_eventGetReferencePalette_Parms*)Obj)->bIgnoreBackground = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreBackground;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RegionX;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RegionY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RegionWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RegionHeight;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetReferencePalette constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetReferencePalette Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ColorCount = { "ColorCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, ColorCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIgnoreBackground = { "bIgnoreBackground", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingMaterialsToolset_eventGetReferencePalette_Parms), &UHT_STATICS::NewProp_bIgnoreBackground_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RegionX = { "RegionX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, RegionX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RegionY = { "RegionY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, RegionY), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RegionWidth = { "RegionWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, RegionWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_RegionHeight = { "RegionHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, RegionHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventGetReferencePalette_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ColorCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIgnoreBackground,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RegionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RegionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RegionWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RegionHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetReferencePalette Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "GetReferencePalette", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventGetReferencePalette_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventGetReferencePalette_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_GetReferencePalette(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execGetReferencePalette)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_ColorCount);
	P_GET_UBOOL(Z_Param_bIgnoreBackground);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RegionX);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RegionY);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RegionWidth);
	P_GET_PROPERTY(FFloatProperty,Z_Param_RegionHeight);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::GetReferencePalette(Z_Param_Name,Z_Param_ColorCount,Z_Param_bIgnoreBackground,Z_Param_RegionX,Z_Param_RegionY,Z_Param_RegionWidth,Z_Param_RegionHeight);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function GetReferencePalette ********************

// ********** Begin Class UModellingMaterialsToolset Function ListMaterialSlots ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_ListMaterialSlots_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventListMaterialSlots_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists a part's material slots as JSON: slot number, material asset path and how many faces use it. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists a part's material slots as JSON: slot number, material asset path and how many faces use it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListMaterialSlots constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListMaterialSlots constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListMaterialSlots Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventListMaterialSlots_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventListMaterialSlots_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListMaterialSlots Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "ListMaterialSlots", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventListMaterialSlots_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventListMaterialSlots_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_ListMaterialSlots(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execListMaterialSlots)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::ListMaterialSlots(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function ListMaterialSlots **********************

// ********** Begin Class UModellingMaterialsToolset Function PaintFaces ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_PaintFaces_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventPaintFaces_Parms
	{
		FString Name;
		FModellingSelection Selection;
		FString Hex;
		float Roughness;
		float Metallic;
		FString MaterialName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Paints only the selected faces, adding a new material slot for the colour. Use it for details like a red roof, a dark door or window glass.\n\x09 * @param Name         Actor label.\n\x09 * @param Selection    Which faces. Example: top faces {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10}.\n\x09 * @param Hex          Colour like \"#C03A2B\".\n\x09 * @param Roughness    0 smooth to 1 matte.\n\x09 * @param Metallic     0 to 1.\n\x09 * @param MaterialName Optional name for the material. Empty uses the part name and colour. */" },
#endif
		{ "CPP_Default_MaterialName", "" },
		{ "CPP_Default_Metallic", "0.000000" },
		{ "CPP_Default_Roughness", "0.600000" },
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Paints only the selected faces, adding a new material slot for the colour. Use it for details like a red roof, a dark door or window glass.\n@param Name         Actor label.\n@param Selection    Which faces. Example: top faces {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10}.\n@param Hex          Colour like \"#C03A2B\".\n@param Roughness    0 smooth to 1 matte.\n@param Metallic     0 to 1.\n@param MaterialName Optional name for the material. Empty uses the part name and colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PaintFaces constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Hex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PaintFaces constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PaintFaces Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Hex = { "Hex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, Hex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hex_MetaData), NewProp_Hex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, Metallic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialName = { "MaterialName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, MaterialName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialName_MetaData), NewProp_MaterialName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function PaintFaces Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "PaintFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventPaintFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventPaintFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_PaintFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execPaintFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_GET_PROPERTY(FStrProperty,Z_Param_Hex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Metallic);
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::PaintFaces(Z_Param_Name,Z_Param_Out_Selection,Z_Param_Hex,Z_Param_Roughness,Z_Param_Metallic,Z_Param_MaterialName);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function PaintFaces *****************************

// ********** Begin Class UModellingMaterialsToolset Function PaintPart ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingMaterialsToolset_PaintPart_Statics
struct UHT_STATICS
{
	struct ModellingMaterialsToolset_eventPaintPart_Parms
	{
		FString Name;
		FString Hex;
		float Roughness;
		float Metallic;
		FString MaterialName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Paints a whole part one colour. Creates the material if needed and puts it on every face (slot 0).\n\x09 * @param Name         Actor label.\n\x09 * @param Hex          Colour like \"#FFFFFF\".\n\x09 * @param Roughness    0 smooth to 1 matte.\n\x09 * @param Metallic     0 to 1.\n\x09 * @param MaterialName Optional name for the material. Empty uses the part name and colour. */" },
#endif
		{ "CPP_Default_MaterialName", "" },
		{ "CPP_Default_Metallic", "0.000000" },
		{ "CPP_Default_Roughness", "0.600000" },
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Paints a whole part one colour. Creates the material if needed and puts it on every face (slot 0).\n@param Name         Actor label.\n@param Hex          Colour like \"#FFFFFF\".\n@param Roughness    0 smooth to 1 matte.\n@param Metallic     0 to 1.\n@param MaterialName Optional name for the material. Empty uses the part name and colour." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PaintPart constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Hex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PaintPart constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PaintPart Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Hex = { "Hex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, Hex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hex_MetaData), NewProp_Hex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, Metallic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialName = { "MaterialName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, MaterialName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialName_MetaData), NewProp_MaterialName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingMaterialsToolset_eventPaintPart_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Hex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function PaintPart Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingMaterialsToolset, nullptr, "PaintPart", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingMaterialsToolset_eventPaintPart_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingMaterialsToolset_eventPaintPart_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingMaterialsToolset_PaintPart(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingMaterialsToolset::execPaintPart)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Hex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Metallic);
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingMaterialsToolset::PaintPart(Z_Param_Name,Z_Param_Hex,Z_Param_Roughness,Z_Param_Metallic,Z_Param_MaterialName);
	P_NATIVE_END;
}
// ********** End Class UModellingMaterialsToolset Function PaintPart ******************************

// ********** Begin Class UModellingMaterialsToolset ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingMaterialsToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Colours and materials. Read the real colours from a reference image, turn them into reusable material instances,\n * and put them on a whole part or on selected faces (a red roof on a white tower).\n * Colours are written as hex text like \"#C03A2B\". Materials are saved under /Game/ModellingToolset/Materials/.\n * Material instances are made from one shared base material that has Color, Roughness, Metallic and Emissive controls.\n */" },
#endif
		{ "IncludePath", "ModellingMaterialsToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingMaterialsToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Colours and materials. Read the real colours from a reference image, turn them into reusable material instances,\nand put them on a whole part or on selected faces (a red roof on a white tower).\nColours are written as hex text like \"#C03A2B\". Materials are saved under /Game/ModellingToolset/Materials/.\nMaterial instances are made from one shared base material that has Color, Roughness, Metallic and Emissive controls." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingMaterialsToolset constinit property declarations ***************
// ********** End Class UModellingMaterialsToolset constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AssignMaterial"), .Pointer = &UModellingMaterialsToolset::execAssignMaterial },
		{ .NameUTF8 = UTF8TEXT("CreateColorMaterial"), .Pointer = &UModellingMaterialsToolset::execCreateColorMaterial },
		{ .NameUTF8 = UTF8TEXT("GetReferencePalette"), .Pointer = &UModellingMaterialsToolset::execGetReferencePalette },
		{ .NameUTF8 = UTF8TEXT("ListMaterialSlots"), .Pointer = &UModellingMaterialsToolset::execListMaterialSlots },
		{ .NameUTF8 = UTF8TEXT("PaintFaces"), .Pointer = &UModellingMaterialsToolset::execPaintFaces },
		{ .NameUTF8 = UTF8TEXT("PaintPart"), .Pointer = &UModellingMaterialsToolset::execPaintPart },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_AssignMaterial, "AssignMaterial" }, // aae8f231bc37fac111bb2b2714189eb1c4658c26
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_CreateColorMaterial, "CreateColorMaterial" }, // 35126592c32e3d2a1420e209c9cd5c719049991b
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_GetReferencePalette, "GetReferencePalette" }, // f34267897517a37424cd2547ed9aad0b5e08068b
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_ListMaterialSlots, "ListMaterialSlots" }, // bb794997023d5f7338bc208abb389c674d8a669e
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_PaintFaces, "PaintFaces" }, // c719540d001a56eae16479da4fe9443559216053
		{ &Z_Construct_UFunction_UModellingMaterialsToolset_PaintPart, "PaintPart" }, // 706ca6e0f9fcb0b60fc963da49e66b1419ebbe4d
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingMaterialsToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingMaterialsToolset,
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
static void UModellingMaterialsToolset_StaticRegisterNativesUModellingMaterialsToolset()
{
	UClass* Class = UModellingMaterialsToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingMaterialsToolset;
UClass* Z_Construct_UClass_UModellingMaterialsToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingMaterialsToolset;
		if (!Z_Registration_Info_UClass_UModellingMaterialsToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingMaterialsToolset"),
				Z_Registration_Info_UClass_UModellingMaterialsToolset.InnerSingleton,
				UModellingMaterialsToolset_StaticRegisterNativesUModellingMaterialsToolset,
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
		return Z_Registration_Info_UClass_UModellingMaterialsToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingMaterialsToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingMaterialsToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingMaterialsToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingMaterialsToolset::UModellingMaterialsToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingMaterialsToolset);
UModellingMaterialsToolset::~UModellingMaterialsToolset() {}
// ********** End Class UModellingMaterialsToolset *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingMaterialsToolset, TEXT("UModellingMaterialsToolset"), &Z_Registration_Info_UClass_UModellingMaterialsToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingMaterialsToolset), 2528982703U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h__Script_ModellingToolset_3e3a087031bb8d6dc60d9170d3762dd642ab39f3{
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
