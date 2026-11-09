// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingTextureToolset.h"
#include "ModellingSelection.h"
#include "ModellingVisionToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingTextureToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTextureToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTextureToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingTextureToolset Function ApplyLibraryMaterial *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ApplyLibraryMaterial_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventApplyLibraryMaterial_Parms
	{
		FString Name;
		FString MaterialPath;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts a ready-made material on a whole part or on selected faces. Library materials follow the part's UV map and their own tiling,\n\x09 * so run AutoUV on the part first to keep them from stretching.\n\x09 * @param Name          Actor label.\n\x09 * @param MaterialPath  Asset path from ListLibraryMaterials.\n\x09 * @param Selection     Which faces. Mode \"all\" (default) covers the whole part. */" },
#endif
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts a ready-made material on a whole part or on selected faces. Library materials follow the part's UV map and their own tiling,\nso run AutoUV on the part first to keep them from stretching.\n@param Name          Actor label.\n@param MaterialPath  Asset path from ListLibraryMaterials.\n@param Selection     Which faces. Mode \"all\" (default) covers the whole part." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyLibraryMaterial constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyLibraryMaterial constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyLibraryMaterial Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyLibraryMaterial_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialPath = { "MaterialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyLibraryMaterial_Parms, MaterialPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialPath_MetaData), NewProp_MaterialPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyLibraryMaterial_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyLibraryMaterial_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyLibraryMaterial Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ApplyLibraryMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventApplyLibraryMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventApplyLibraryMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ApplyLibraryMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execApplyLibraryMaterial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialPath);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ApplyLibraryMaterial(Z_Param_Name,Z_Param_MaterialPath,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ApplyLibraryMaterial *********************

// ********** Begin Class UModellingTextureToolset Function ApplyTextureFaces **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ApplyTextureFaces_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventApplyTextureFaces_Parms
	{
		FString Name;
		FModellingSelection Selection;
		FString SetName;
		float TileCm;
		bool bWorldAligned;
		FString TintHex;
		float Roughness;
		float Metallic;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts a texture set on the selected faces only, e.g. roof tiles on the top faces.\n\x09 * @param Name           Actor label.\n\x09 * @param Selection      Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} for the top.\n\x09 * @param SetName        Texture set name from ListTextureSets.\n\x09 * @param TileCm         Real size of one tile in cm. 0 uses the set's tile_cm or the project default.\n\x09 * @param bWorldAligned  True: by world position (never stretches). False: follow the UV map.\n\x09 * @param TintHex        Optional tint colour. Empty for none.\n\x09 * @param Roughness      0 to 1 to force, or -1 for the texture or default.\n\x09 * @param Metallic       0 to 1 to force, or -1 for the texture or default. */" },
#endif
		{ "CPP_Default_bWorldAligned", "true" },
		{ "CPP_Default_Metallic", "-1.000000" },
		{ "CPP_Default_Roughness", "-1.000000" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "CPP_Default_TintHex", "" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts a texture set on the selected faces only, e.g. roof tiles on the top faces.\n@param Name           Actor label.\n@param Selection      Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} for the top.\n@param SetName        Texture set name from ListTextureSets.\n@param TileCm         Real size of one tile in cm. 0 uses the set's tile_cm or the project default.\n@param bWorldAligned  True: by world position (never stretches). False: follow the UV map.\n@param TintHex        Optional tint colour. Empty for none.\n@param Roughness      0 to 1 to force, or -1 for the texture or default.\n@param Metallic       0 to 1 to force, or -1 for the texture or default." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintHex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyTextureFaces constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static void NewProp_bWorldAligned_SetBit(void* Obj)
	{
		((ModellingTextureToolset_eventApplyTextureFaces_Parms*)Obj)->bWorldAligned = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWorldAligned;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TintHex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyTextureFaces constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyTextureFaces Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SetName = { "SetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, SetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetName_MetaData), NewProp_SetName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWorldAligned = { "bWorldAligned", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingTextureToolset_eventApplyTextureFaces_Parms), &UHT_STATICS::NewProp_bWorldAligned_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TintHex = { "TintHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, TintHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintHex_MetaData), NewProp_TintHex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, Metallic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTextureFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWorldAligned,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TintHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyTextureFaces Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ApplyTextureFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventApplyTextureFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventApplyTextureFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ApplyTextureFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execApplyTextureFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_GET_PROPERTY(FStrProperty,Z_Param_SetName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_GET_UBOOL(Z_Param_bWorldAligned);
	P_GET_PROPERTY(FStrProperty,Z_Param_TintHex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Metallic);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ApplyTextureFaces(Z_Param_Name,Z_Param_Out_Selection,Z_Param_SetName,Z_Param_TileCm,Z_Param_bWorldAligned,Z_Param_TintHex,Z_Param_Roughness,Z_Param_Metallic);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ApplyTextureFaces ************************

// ********** Begin Class UModellingTextureToolset Function ApplyTexturePart ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ApplyTexturePart_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventApplyTexturePart_Parms
	{
		FString Name;
		FString SetName;
		float TileCm;
		bool bWorldAligned;
		FString TintHex;
		float Roughness;
		float Metallic;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts a texture set on a whole part.\n\x09 * @param Name           Actor label.\n\x09 * @param SetName        Texture set name from ListTextureSets, e.g. \"Brick\".\n\x09 * @param TileCm         Real size of one texture tile in cm. 0 uses the set's tile_cm, or the project default.\n\x09 * @param bWorldAligned  True (default): texture by world position, never stretches, no UVs needed. False: follow the part's UV map (run AutoUV first).\n\x09 * @param TintHex        Optional colour multiplied into the texture, e.g. \"#D8C8B0\" to warm it. Empty for none.\n\x09 * @param Roughness      0 to 1 to force a value, or -1 to use the set's roughness texture (or 0.6 if it has none).\n\x09 * @param Metallic       0 to 1 to force a value, or -1 to use the set's metallic texture (or 0 if it has none). */" },
#endif
		{ "CPP_Default_bWorldAligned", "true" },
		{ "CPP_Default_Metallic", "-1.000000" },
		{ "CPP_Default_Roughness", "-1.000000" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "CPP_Default_TintHex", "" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts a texture set on a whole part.\n@param Name           Actor label.\n@param SetName        Texture set name from ListTextureSets, e.g. \"Brick\".\n@param TileCm         Real size of one texture tile in cm. 0 uses the set's tile_cm, or the project default.\n@param bWorldAligned  True (default): texture by world position, never stretches, no UVs needed. False: follow the part's UV map (run AutoUV first).\n@param TintHex        Optional colour multiplied into the texture, e.g. \"#D8C8B0\" to warm it. Empty for none.\n@param Roughness      0 to 1 to force a value, or -1 to use the set's roughness texture (or 0.6 if it has none).\n@param Metallic       0 to 1 to force a value, or -1 to use the set's metallic texture (or 0 if it has none)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintHex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyTexturePart constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static void NewProp_bWorldAligned_SetBit(void* Obj)
	{
		((ModellingTextureToolset_eventApplyTexturePart_Parms*)Obj)->bWorldAligned = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWorldAligned;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TintHex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Metallic;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyTexturePart constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyTexturePart Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SetName = { "SetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, SetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetName_MetaData), NewProp_SetName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWorldAligned = { "bWorldAligned", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingTextureToolset_eventApplyTexturePart_Parms), &UHT_STATICS::NewProp_bWorldAligned_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TintHex = { "TintHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, TintHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintHex_MetaData), NewProp_TintHex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Metallic = { "Metallic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, Metallic), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventApplyTexturePart_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWorldAligned,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TintHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Metallic,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyTexturePart Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ApplyTexturePart", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventApplyTexturePart_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventApplyTexturePart_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ApplyTexturePart(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execApplyTexturePart)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_SetName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_GET_UBOOL(Z_Param_bWorldAligned);
	P_GET_PROPERTY(FStrProperty,Z_Param_TintHex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Metallic);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ApplyTexturePart(Z_Param_Name,Z_Param_SetName,Z_Param_TileCm,Z_Param_bWorldAligned,Z_Param_TintHex,Z_Param_Roughness,Z_Param_Metallic);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ApplyTexturePart *************************

// ********** Begin Class UModellingTextureToolset Function AutoUV *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_AutoUV_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventAutoUV_Parms
	{
		FString Name;
		FString Method;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Generates a texture layout (UV map) for a part so textures do not stretch: one UV unit per 100 cm of surface, the same on every part.\n\x09 * Needed for library materials, for UV-mode textures, and before export. Run it after the shape is finished, since edits change the surface.\n\x09 * @param Name       Actor label.\n\x09 * @param Method     \"box\" (default; best for walls, furniture, buildings), \"cylinder\" (round things: towers, pipes, bottles),\n\x09 *                   or \"unwrap\" (automatic, for curved or organic shapes; pattern direction may vary between patches).\n\x09 * @param Selection  Which faces to lay out. Default all. */" },
#endif
		{ "CPP_Default_Method", "box" },
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generates a texture layout (UV map) for a part so textures do not stretch: one UV unit per 100 cm of surface, the same on every part.\nNeeded for library materials, for UV-mode textures, and before export. Run it after the shape is finished, since edits change the surface.\n@param Name       Actor label.\n@param Method     \"box\" (default; best for walls, furniture, buildings), \"cylinder\" (round things: towers, pipes, bottles),\n                 or \"unwrap\" (automatic, for curved or organic shapes; pattern direction may vary between patches).\n@param Selection  Which faces to lay out. Default all." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Method_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AutoUV constinit property declarations ********************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Method;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AutoUV constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AutoUV Property Definitions *******************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventAutoUV_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Method = { "Method", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventAutoUV_Parms, Method), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Method_MetaData), NewProp_Method_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventAutoUV_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventAutoUV_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Method,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function AutoUV Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "AutoUV", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventAutoUV_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventAutoUV_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_AutoUV(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execAutoUV)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Method);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::AutoUV(Z_Param_Name,Z_Param_Method,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function AutoUV ***********************************

// ********** Begin Class UModellingTextureToolset Function CheckTextureStretch ********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_CheckTextureStretch_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventCheckTextureStretch_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Measures how much a part's texture layout stretches or squashes textures. Returns a verdict, the share of faces that are over-stretched,\n\x09 * faces missing a layout, and the worst spots (local-space centres) so you can re-run AutoUV with another method on them.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Measures how much a part's texture layout stretches or squashes textures. Returns a verdict, the share of faces that are over-stretched,\nfaces missing a layout, and the worst spots (local-space centres) so you can re-run AutoUV with another method on them.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CheckTextureStretch constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckTextureStretch constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckTextureStretch Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventCheckTextureStretch_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventCheckTextureStretch_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CheckTextureStretch Property Definitions ********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "CheckTextureStretch", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventCheckTextureStretch_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventCheckTextureStretch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_CheckTextureStretch(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execCheckTextureStretch)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::CheckTextureStretch(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function CheckTextureStretch **********************

// ********** Begin Class UModellingTextureToolset Function ImportTextureSets **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ImportTextureSets_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventImportTextureSets_Parms
	{
		bool bReimport;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Imports (or re-imports) every image in the textures folder as texture assets. Normally not needed: ApplyTexture imports what it uses.\n\x09 * @param bReimport  Re-import sets that were imported before, for example after the user replaced an image. */" },
#endif
		{ "CPP_Default_bReimport", "false" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Imports (or re-imports) every image in the textures folder as texture assets. Normally not needed: ApplyTexture imports what it uses.\n@param bReimport  Re-import sets that were imported before, for example after the user replaced an image." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ImportTextureSets constinit property declarations *********************
	static void NewProp_bReimport_SetBit(void* Obj)
	{
		((ModellingTextureToolset_eventImportTextureSets_Parms*)Obj)->bReimport = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bReimport;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ImportTextureSets constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ImportTextureSets Property Definitions ********************************
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bReimport = { "bReimport", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingTextureToolset_eventImportTextureSets_Parms), &UHT_STATICS::NewProp_bReimport_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventImportTextureSets_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bReimport,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ImportTextureSets Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ImportTextureSets", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventImportTextureSets_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventImportTextureSets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ImportTextureSets(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execImportTextureSets)
{
	P_GET_UBOOL(Z_Param_bReimport);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ImportTextureSets(Z_Param_bReimport);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ImportTextureSets ************************

// ********** Begin Class UModellingTextureToolset Function ListLibraryMaterials *******************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ListLibraryMaterials_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventListLibraryMaterials_Parms
	{
		FString Filter;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists ready-made materials in the material library folder (see settings) as JSON: name, asset path, a guessed category from the name\n\x09 * (brick, wood, metal, stone, glass, ...), and the name of a tiling parameter if the material exposes one.\n\x09 * @param Filter  Optional word to match in the name, e.g. \"brick\". Empty lists everything (up to 300). */" },
#endif
		{ "CPP_Default_Filter", "" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists ready-made materials in the material library folder (see settings) as JSON: name, asset path, a guessed category from the name\n(brick, wood, metal, stone, glass, ...), and the name of a tiling parameter if the material exposes one.\n@param Filter  Optional word to match in the name, e.g. \"brick\". Empty lists everything (up to 300)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListLibraryMaterials constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListLibraryMaterials constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListLibraryMaterials Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventListLibraryMaterials_Parms, Filter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventListLibraryMaterials_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListLibraryMaterials Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ListLibraryMaterials", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventListLibraryMaterials_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventListLibraryMaterials_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ListLibraryMaterials(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execListLibraryMaterials)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ListLibraryMaterials(Z_Param_Filter);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ListLibraryMaterials *********************

// ********** Begin Class UModellingTextureToolset Function ListTextureSets ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_ListTextureSets_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventListTextureSets_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists the texture sets found in the textures folder as JSON: name, which maps exist (normal, roughness, metallic), tile size in cm,\n\x09 * notes, and whether it is imported yet. Also tells you the folder path and the naming rule, so you can ask the user for a missing texture. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the texture sets found in the textures folder as JSON: name, which maps exist (normal, roughness, metallic), tile size in cm,\nnotes, and whether it is imported yet. Also tells you the folder path and the naming rule, so you can ask the user for a missing texture." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListTextureSets constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListTextureSets constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListTextureSets Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventListTextureSets_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListTextureSets Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "ListTextureSets", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventListTextureSets_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventListTextureSets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_ListTextureSets(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execListTextureSets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTextureToolset::ListTextureSets();
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function ListTextureSets **************************

// ********** Begin Class UModellingTextureToolset Function PreviewMaterial ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTextureToolset_PreviewMaterial_Statics
struct UHT_STATICS
{
	struct ModellingTextureToolset_eventPreviewMaterial_Parms
	{
		FString SetName;
		FString MaterialPath;
		float TileCm;
		FModellingCapture ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Textures" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Renders a sphere and a cube with a texture set or a library material, so you can choose by look. Returns a picture and the saved file path.\n\x09 * Give either SetName or MaterialPath.\n\x09 * @param SetName       Texture set name, or empty.\n\x09 * @param MaterialPath  Library material asset path, or empty.\n\x09 * @param TileCm        Tile size for a texture set. 0 uses the set's own. */" },
#endif
		{ "CPP_Default_MaterialPath", "" },
		{ "CPP_Default_SetName", "" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renders a sphere and a cube with a texture set or a library material, so you can choose by look. Returns a picture and the saved file path.\nGive either SetName or MaterialPath.\n@param SetName       Texture set name, or empty.\n@param MaterialPath  Library material asset path, or empty.\n@param TileCm        Tile size for a texture set. 0 uses the set's own." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SetName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PreviewMaterial constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_SetName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialPath;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PreviewMaterial constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PreviewMaterial Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SetName = { "SetName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventPreviewMaterial_Parms, SetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SetName_MetaData), NewProp_SetName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialPath = { "MaterialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventPreviewMaterial_Parms, MaterialPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialPath_MetaData), NewProp_MaterialPath_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventPreviewMaterial_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTextureToolset_eventPreviewMaterial_Parms, ReturnValue), Z_Construct_UScriptStruct_FModellingCapture, METADATA_PARAMS(0, nullptr) }; // c715ef10e38f8c626852ead30acc4e35c7895ea0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function PreviewMaterial Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTextureToolset, nullptr, "PreviewMaterial", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTextureToolset_eventPreviewMaterial_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTextureToolset_eventPreviewMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTextureToolset_PreviewMaterial(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTextureToolset::execPreviewMaterial)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SetName);
	P_GET_PROPERTY(FStrProperty,Z_Param_MaterialPath);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModellingCapture*)Z_Param__Result=UModellingTextureToolset::PreviewMaterial(Z_Param_SetName,Z_Param_MaterialPath,Z_Param_TileCm);
	P_NATIVE_END;
}
// ********** End Class UModellingTextureToolset Function PreviewMaterial **************************

// ********** Begin Class UModellingTextureToolset *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingTextureToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Real surfaces instead of flat colours: texture images the user drops in a folder, and ready-made materials from a library folder.\n *\n * Textures folder: the user adds images named by set and type, e.g. Brick_albedo.png (required), Brick_normal.png,\n * Brick_roughness.png, Brick_metallic.png. An optional Brick.txt can hold \"tile_cm: 60\" (real size of one tile) and a description.\n * They are imported automatically and applied through the plugin's master material.\n *\n * World-aligned mode (the default) lays the texture on by real-world position, so it never stretches and tiles the same on every\n * part, whatever was cut, bent or merged. It needs no UV map. For a model that will be exported, run AutoUV before Done so the\n * FBX carries a proper texture layout as well.\n */" },
#endif
		{ "IncludePath", "ModellingTextureToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingTextureToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Real surfaces instead of flat colours: texture images the user drops in a folder, and ready-made materials from a library folder.\n\nTextures folder: the user adds images named by set and type, e.g. Brick_albedo.png (required), Brick_normal.png,\nBrick_roughness.png, Brick_metallic.png. An optional Brick.txt can hold \"tile_cm: 60\" (real size of one tile) and a description.\nThey are imported automatically and applied through the plugin's master material.\n\nWorld-aligned mode (the default) lays the texture on by real-world position, so it never stretches and tiles the same on every\npart, whatever was cut, bent or merged. It needs no UV map. For a model that will be exported, run AutoUV before Done so the\nFBX carries a proper texture layout as well." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingTextureToolset constinit property declarations *****************
// ********** End Class UModellingTextureToolset constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyLibraryMaterial"), .Pointer = &UModellingTextureToolset::execApplyLibraryMaterial },
		{ .NameUTF8 = UTF8TEXT("ApplyTextureFaces"), .Pointer = &UModellingTextureToolset::execApplyTextureFaces },
		{ .NameUTF8 = UTF8TEXT("ApplyTexturePart"), .Pointer = &UModellingTextureToolset::execApplyTexturePart },
		{ .NameUTF8 = UTF8TEXT("AutoUV"), .Pointer = &UModellingTextureToolset::execAutoUV },
		{ .NameUTF8 = UTF8TEXT("CheckTextureStretch"), .Pointer = &UModellingTextureToolset::execCheckTextureStretch },
		{ .NameUTF8 = UTF8TEXT("ImportTextureSets"), .Pointer = &UModellingTextureToolset::execImportTextureSets },
		{ .NameUTF8 = UTF8TEXT("ListLibraryMaterials"), .Pointer = &UModellingTextureToolset::execListLibraryMaterials },
		{ .NameUTF8 = UTF8TEXT("ListTextureSets"), .Pointer = &UModellingTextureToolset::execListTextureSets },
		{ .NameUTF8 = UTF8TEXT("PreviewMaterial"), .Pointer = &UModellingTextureToolset::execPreviewMaterial },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingTextureToolset_ApplyLibraryMaterial, "ApplyLibraryMaterial" }, // fea6dd63842b121c9ae979cdda74d3992c84493f
		{ &Z_Construct_UFunction_UModellingTextureToolset_ApplyTextureFaces, "ApplyTextureFaces" }, // 6a2e4f22bf228249672e2f426c3ec5d1eb3103bd
		{ &Z_Construct_UFunction_UModellingTextureToolset_ApplyTexturePart, "ApplyTexturePart" }, // 89ef0051e140053e526936bcbd990bfd9ff8cdc8
		{ &Z_Construct_UFunction_UModellingTextureToolset_AutoUV, "AutoUV" }, // f17b38551bbd76e085f9746254683a09b0a6096f
		{ &Z_Construct_UFunction_UModellingTextureToolset_CheckTextureStretch, "CheckTextureStretch" }, // 586b7292cca8c042eab23b65e2629b1aeffbc111
		{ &Z_Construct_UFunction_UModellingTextureToolset_ImportTextureSets, "ImportTextureSets" }, // b811973179c4fab3c02801a62029a18ca9472e6b
		{ &Z_Construct_UFunction_UModellingTextureToolset_ListLibraryMaterials, "ListLibraryMaterials" }, // 7501111abeb6333c5239a3cd8221fb0a5425a981
		{ &Z_Construct_UFunction_UModellingTextureToolset_ListTextureSets, "ListTextureSets" }, // 00ce8161ecc953602d13162a96bd6c2cafa9426f
		{ &Z_Construct_UFunction_UModellingTextureToolset_PreviewMaterial, "PreviewMaterial" }, // a9f6ef5a2f4d891cadaaf69aa247340f95b4e448
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingTextureToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingTextureToolset,
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
static void UModellingTextureToolset_StaticRegisterNativesUModellingTextureToolset()
{
	UClass* Class = UModellingTextureToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingTextureToolset;
UClass* Z_Construct_UClass_UModellingTextureToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingTextureToolset;
		if (!Z_Registration_Info_UClass_UModellingTextureToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingTextureToolset"),
				Z_Registration_Info_UClass_UModellingTextureToolset.InnerSingleton,
				UModellingTextureToolset_StaticRegisterNativesUModellingTextureToolset,
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
		return Z_Registration_Info_UClass_UModellingTextureToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingTextureToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingTextureToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingTextureToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingTextureToolset::UModellingTextureToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingTextureToolset);
UModellingTextureToolset::~UModellingTextureToolset() {}
// ********** End Class UModellingTextureToolset ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingTextureToolset, TEXT("UModellingTextureToolset"), &Z_Registration_Info_UClass_UModellingTextureToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingTextureToolset), 4201133548U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h__Script_ModellingToolset_8bbc86e7a5a629241587bcb770f86438a0003db5{
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
