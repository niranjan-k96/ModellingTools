// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingSurfaceToolset.h"
#include "ModellingSelection.h"
#include "ModellingVisionToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingSurfaceToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSurfaceToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSurfaceToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingSurfaceToolset Function ApplyGlass *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_ApplyGlass_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventApplyGlass_Parms
	{
		FString Name;
		FModellingSelection Selection;
		FString TintHex;
		float Opacity;
		float Roughness;
		float IOR;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Makes selected faces (or the whole part) glass: windows, lantern rooms, bottles. Uses the Megascans glass material when the project\n\x09 * has it, otherwise the plugin's own glass.\n\x09 * @param Name       Actor label.\n\x09 * @param Selection  Which faces. Mode \"all\" (default) makes the whole part glass.\n\x09 * @param TintHex    Glass colour, e.g. \"#DDEEFF\" for a faint blue. \"#FFFFFF\" is clear.\n\x09 * @param Opacity    0 = fully see-through, 1 = solid. Window glass is about 0.1 to 0.3.\n\x09 * @param Roughness  0 = polished, 1 = frosted.\n\x09 * @param IOR        Bending of light through the glass. 1.52 is normal glass, 1.0 is none. */" },
#endif
		{ "CPP_Default_IOR", "1.520000" },
		{ "CPP_Default_Opacity", "0.150000" },
		{ "CPP_Default_Roughness", "0.050000" },
		{ "CPP_Default_Selection", "()" },
		{ "CPP_Default_TintHex", "#FFFFFF" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Makes selected faces (or the whole part) glass: windows, lantern rooms, bottles. Uses the Megascans glass material when the project\nhas it, otherwise the plugin's own glass.\n@param Name       Actor label.\n@param Selection  Which faces. Mode \"all\" (default) makes the whole part glass.\n@param TintHex    Glass colour, e.g. \"#DDEEFF\" for a faint blue. \"#FFFFFF\" is clear.\n@param Opacity    0 = fully see-through, 1 = solid. Window glass is about 0.1 to 0.3.\n@param Roughness  0 = polished, 1 = frosted.\n@param IOR        Bending of light through the glass. 1.52 is normal glass, 1.0 is none." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TintHex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplyGlass constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TintHex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Opacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Roughness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IOR;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplyGlass constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplyGlass Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TintHex = { "TintHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, TintHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TintHex_MetaData), NewProp_TintHex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Opacity = { "Opacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, Opacity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Roughness = { "Roughness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, Roughness), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_IOR = { "IOR", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, IOR), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplyGlass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TintHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Opacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Roughness,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_IOR,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplyGlass Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "ApplyGlass", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventApplyGlass_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventApplyGlass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_ApplyGlass(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execApplyGlass)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_GET_PROPERTY(FStrProperty,Z_Param_TintHex);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Opacity);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Roughness);
	P_GET_PROPERTY(FFloatProperty,Z_Param_IOR);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSurfaceToolset::ApplyGlass(Z_Param_Name,Z_Param_Out_Selection,Z_Param_TintHex,Z_Param_Opacity,Z_Param_Roughness,Z_Param_IOR);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function ApplyGlass *******************************

// ********** Begin Class UModellingSurfaceToolset Function ApplySurfaceFaces **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfaceFaces_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventApplySurfaceFaces_Parms
	{
		FString Name;
		FModellingSelection Selection;
		FString Surface;
		FString TargetHex;
		FString Finish;
		float TileCm;
		bool bWorldAligned;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts a library surface on the selected faces only (roof tiles on the top, stone on the base).\n\x09 * @param Name           Actor label.\n\x09 * @param Selection      Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} for the top.\n\x09 * @param Surface        Surface name.\n\x09 * @param TargetHex      Colour to match, or empty.\n\x09 * @param Finish         \"auto\", \"matte\", \"satin\" or \"glossy\".\n\x09 * @param TileCm         Real size of one tile in cm. 0 uses the project default.\n\x09 * @param bWorldAligned  True: by world position. False: follows the UV map. */" },
#endif
		{ "CPP_Default_bWorldAligned", "true" },
		{ "CPP_Default_Finish", "auto" },
		{ "CPP_Default_TargetHex", "" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts a library surface on the selected faces only (roof tiles on the top, stone on the base).\n@param Name           Actor label.\n@param Selection      Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} for the top.\n@param Surface        Surface name.\n@param TargetHex      Colour to match, or empty.\n@param Finish         \"auto\", \"matte\", \"satin\" or \"glossy\".\n@param TileCm         Real size of one tile in cm. 0 uses the project default.\n@param bWorldAligned  True: by world position. False: follows the UV map." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Surface_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetHex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Finish_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplySurfaceFaces constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Surface;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetHex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Finish;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static void NewProp_bWorldAligned_SetBit(void* Obj)
	{
		((ModellingSurfaceToolset_eventApplySurfaceFaces_Parms*)Obj)->bWorldAligned = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWorldAligned;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplySurfaceFaces constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplySurfaceFaces Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Surface = { "Surface", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, Surface), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Surface_MetaData), NewProp_Surface_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetHex = { "TargetHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, TargetHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetHex_MetaData), NewProp_TargetHex_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Finish = { "Finish", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, Finish), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Finish_MetaData), NewProp_Finish_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWorldAligned = { "bWorldAligned", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms), &UHT_STATICS::NewProp_bWorldAligned_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfaceFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Surface,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Finish,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWorldAligned,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplySurfaceFaces Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "ApplySurfaceFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventApplySurfaceFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventApplySurfaceFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfaceFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execApplySurfaceFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_GET_PROPERTY(FStrProperty,Z_Param_Surface);
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetHex);
	P_GET_PROPERTY(FStrProperty,Z_Param_Finish);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_GET_UBOOL(Z_Param_bWorldAligned);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSurfaceToolset::ApplySurfaceFaces(Z_Param_Name,Z_Param_Out_Selection,Z_Param_Surface,Z_Param_TargetHex,Z_Param_Finish,Z_Param_TileCm,Z_Param_bWorldAligned);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function ApplySurfaceFaces ************************

// ********** Begin Class UModellingSurfaceToolset Function ApplySurfacePart ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfacePart_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventApplySurfacePart_Parms
	{
		FString Name;
		FString Surface;
		FString TargetHex;
		FString Finish;
		float TileCm;
		bool bWorldAligned;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Puts a library surface on a whole part, tinted so its average colour matches TargetHex and with the requested finish.\n\x09 * @param Name           Actor label.\n\x09 * @param Surface        Surface name from ListSurfaces or FindClosestSurface.\n\x09 * @param TargetHex      Colour to match (from the reference), or empty to keep the surface's own colour.\n\x09 * @param Finish         \"auto\", \"matte\", \"satin\" or \"glossy\".\n\x09 * @param TileCm         Real size of one tile in cm. 0 uses the project default.\n\x09 * @param bWorldAligned  True (default): laid on by world position, never stretches. False: follows the UV map (run AutoUV first). */" },
#endif
		{ "CPP_Default_bWorldAligned", "true" },
		{ "CPP_Default_Finish", "auto" },
		{ "CPP_Default_TargetHex", "" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Puts a library surface on a whole part, tinted so its average colour matches TargetHex and with the requested finish.\n@param Name           Actor label.\n@param Surface        Surface name from ListSurfaces or FindClosestSurface.\n@param TargetHex      Colour to match (from the reference), or empty to keep the surface's own colour.\n@param Finish         \"auto\", \"matte\", \"satin\" or \"glossy\".\n@param TileCm         Real size of one tile in cm. 0 uses the project default.\n@param bWorldAligned  True (default): laid on by world position, never stretches. False: follows the UV map (run AutoUV first)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Surface_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetHex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Finish_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ApplySurfacePart constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Surface;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetHex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Finish;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static void NewProp_bWorldAligned_SetBit(void* Obj)
	{
		((ModellingSurfaceToolset_eventApplySurfacePart_Parms*)Obj)->bWorldAligned = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWorldAligned;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ApplySurfacePart constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ApplySurfacePart Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Surface = { "Surface", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, Surface), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Surface_MetaData), NewProp_Surface_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetHex = { "TargetHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, TargetHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetHex_MetaData), NewProp_TargetHex_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Finish = { "Finish", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, Finish), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Finish_MetaData), NewProp_Finish_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWorldAligned = { "bWorldAligned", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingSurfaceToolset_eventApplySurfacePart_Parms), &UHT_STATICS::NewProp_bWorldAligned_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventApplySurfacePart_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Surface,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Finish,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWorldAligned,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ApplySurfacePart Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "ApplySurfacePart", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventApplySurfacePart_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventApplySurfacePart_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfacePart(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execApplySurfacePart)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Surface);
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetHex);
	P_GET_PROPERTY(FStrProperty,Z_Param_Finish);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_GET_UBOOL(Z_Param_bWorldAligned);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSurfaceToolset::ApplySurfacePart(Z_Param_Name,Z_Param_Surface,Z_Param_TargetHex,Z_Param_Finish,Z_Param_TileCm,Z_Param_bWorldAligned);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function ApplySurfacePart *************************

// ********** Begin Class UModellingSurfaceToolset Function FindClosestSurface *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_FindClosestSurface_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventFindClosestSurface_Parms
	{
		FString Description;
		FString TargetHex;
		int32 MaxResults;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Ranks the library surfaces for what you need. Words matter most (a tint can change colour but cannot turn wood into brick).\n\x09 * Returns JSON: ranked candidates with a score, why they matched, the tint that would make each match the target colour,\n\x09 * and \"use_flat_color\": true when nothing in the library is suitable.\n\x09 * @param Description  What the surface is, in plain words from the reference: \"worn red brick wall\", \"white plaster\", \"terracotta roof tiles\".\n\x09 * @param TargetHex    The colour it should end up, from GetReferencePalette, e.g. \"#B04A3A\". Empty to ignore colour.\n\x09 * @param MaxResults   How many candidates to return (1 to 10). */" },
#endif
		{ "CPP_Default_MaxResults", "5" },
		{ "CPP_Default_TargetHex", "" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ranks the library surfaces for what you need. Words matter most (a tint can change colour but cannot turn wood into brick).\nReturns JSON: ranked candidates with a score, why they matched, the tint that would make each match the target colour,\nand \"use_flat_color\": true when nothing in the library is suitable.\n@param Description  What the surface is, in plain words from the reference: \"worn red brick wall\", \"white plaster\", \"terracotta roof tiles\".\n@param TargetHex    The colour it should end up, from GetReferencePalette, e.g. \"#B04A3A\". Empty to ignore colour.\n@param MaxResults   How many candidates to return (1 to 10)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetHex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindClosestSurface constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetHex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxResults;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindClosestSurface constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindClosestSurface Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventFindClosestSurface_Parms, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetHex = { "TargetHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventFindClosestSurface_Parms, TargetHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetHex_MetaData), NewProp_TargetHex_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxResults = { "MaxResults", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventFindClosestSurface_Parms, MaxResults), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventFindClosestSurface_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxResults,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FindClosestSurface Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "FindClosestSurface", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventFindClosestSurface_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventFindClosestSurface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_FindClosestSurface(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execFindClosestSurface)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Description);
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetHex);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxResults);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSurfaceToolset::FindClosestSurface(Z_Param_Description,Z_Param_TargetHex,Z_Param_MaxResults);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function FindClosestSurface ***********************

// ********** Begin Class UModellingSurfaceToolset Function ListSurfaces ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_ListSurfaces_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventListSurfaces_Parms
	{
		FString Filter;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists every surface in the library folders as JSON: name, category, average colour (hex), which maps it has.\n\x09 * The first call can take a while, because the average colours are measured from the textures and then cached.\n\x09 * @param Filter  Optional word to match in the name or category. Empty lists everything. */" },
#endif
		{ "CPP_Default_Filter", "" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists every surface in the library folders as JSON: name, category, average colour (hex), which maps it has.\nThe first call can take a while, because the average colours are measured from the textures and then cached.\n@param Filter  Optional word to match in the name or category. Empty lists everything." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filter_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListSurfaces constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filter;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListSurfaces constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListSurfaces Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventListSurfaces_Parms, Filter), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filter_MetaData), NewProp_Filter_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventListSurfaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Filter,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListSurfaces Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "ListSurfaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventListSurfaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventListSurfaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_ListSurfaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execListSurfaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSurfaceToolset::ListSurfaces(Z_Param_Filter);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function ListSurfaces *****************************

// ********** Begin Class UModellingSurfaceToolset Function PreviewSurface *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSurfaceToolset_PreviewSurface_Statics
struct UHT_STATICS
{
	struct ModellingSurfaceToolset_eventPreviewSurface_Parms
	{
		FString Surface;
		FString TargetHex;
		FString Finish;
		float TileCm;
		FModellingCapture ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Surfaces" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Renders a sphere and a cube with a library surface, tweaked to a target colour and finish, so you can check the look before applying it.\n\x09 * @param Surface    Surface name from ListSurfaces or FindClosestSurface.\n\x09 * @param TargetHex  Colour to match, or empty to keep the surface's own colour.\n\x09 * @param Finish     \"auto\" keeps the surface's roughness; \"matte\", \"satin\" or \"glossy\" force a range.\n\x09 * @param TileCm     Real size of one tile in cm. 0 uses the project default (200 cm for Megascans). */" },
#endif
		{ "CPP_Default_Finish", "auto" },
		{ "CPP_Default_TargetHex", "" },
		{ "CPP_Default_TileCm", "0.000000" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Renders a sphere and a cube with a library surface, tweaked to a target colour and finish, so you can check the look before applying it.\n@param Surface    Surface name from ListSurfaces or FindClosestSurface.\n@param TargetHex  Colour to match, or empty to keep the surface's own colour.\n@param Finish     \"auto\" keeps the surface's roughness; \"matte\", \"satin\" or \"glossy\" force a range.\n@param TileCm     Real size of one tile in cm. 0 uses the project default (200 cm for Megascans)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Surface_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetHex_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Finish_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function PreviewSurface constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Surface;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetHex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Finish;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TileCm;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function PreviewSurface constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function PreviewSurface Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Surface = { "Surface", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventPreviewSurface_Parms, Surface), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Surface_MetaData), NewProp_Surface_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TargetHex = { "TargetHex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventPreviewSurface_Parms, TargetHex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetHex_MetaData), NewProp_TargetHex_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Finish = { "Finish", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventPreviewSurface_Parms, Finish), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Finish_MetaData), NewProp_Finish_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_TileCm = { "TileCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventPreviewSurface_Parms, TileCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSurfaceToolset_eventPreviewSurface_Parms, ReturnValue), Z_Construct_UScriptStruct_FModellingCapture, METADATA_PARAMS(0, nullptr) }; // c715ef10e38f8c626852ead30acc4e35c7895ea0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Surface,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetHex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Finish,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function PreviewSurface Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSurfaceToolset, nullptr, "PreviewSurface", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSurfaceToolset_eventPreviewSurface_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSurfaceToolset_eventPreviewSurface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSurfaceToolset_PreviewSurface(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSurfaceToolset::execPreviewSurface)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Surface);
	P_GET_PROPERTY(FStrProperty,Z_Param_TargetHex);
	P_GET_PROPERTY(FStrProperty,Z_Param_Finish);
	P_GET_PROPERTY(FFloatProperty,Z_Param_TileCm);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModellingCapture*)Z_Param__Result=UModellingSurfaceToolset::PreviewSurface(Z_Param_Surface,Z_Param_TargetHex,Z_Param_Finish,Z_Param_TileCm);
	P_NATIVE_END;
}
// ********** End Class UModellingSurfaceToolset Function PreviewSurface ***************************

// ********** Begin Class UModellingSurfaceToolset *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingSurfaceToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Surface library (Fab and Megascans downloads) with closeness matching, and glass.\n *\n * Every library surface is three textures (colour, normal, packed occlusion/roughness/metallic). The plugin lays them on with\n * its own master material, world-aligned by default so they never stretch, and tweaks tint and roughness to match the reference\n * before applying. Use FindClosestSurface first: it ranks the library by the words you give (brick, plaster, roof tiles) and by\n * colour, and tells you whether the best match is good enough. Only paint a flat colour when it says no usable match exists.\n */" },
#endif
		{ "IncludePath", "ModellingSurfaceToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingSurfaceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Surface library (Fab and Megascans downloads) with closeness matching, and glass.\n\nEvery library surface is three textures (colour, normal, packed occlusion/roughness/metallic). The plugin lays them on with\nits own master material, world-aligned by default so they never stretch, and tweaks tint and roughness to match the reference\nbefore applying. Use FindClosestSurface first: it ranks the library by the words you give (brick, plaster, roof tiles) and by\ncolour, and tells you whether the best match is good enough. Only paint a flat colour when it says no usable match exists." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingSurfaceToolset constinit property declarations *****************
// ********** End Class UModellingSurfaceToolset constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ApplyGlass"), .Pointer = &UModellingSurfaceToolset::execApplyGlass },
		{ .NameUTF8 = UTF8TEXT("ApplySurfaceFaces"), .Pointer = &UModellingSurfaceToolset::execApplySurfaceFaces },
		{ .NameUTF8 = UTF8TEXT("ApplySurfacePart"), .Pointer = &UModellingSurfaceToolset::execApplySurfacePart },
		{ .NameUTF8 = UTF8TEXT("FindClosestSurface"), .Pointer = &UModellingSurfaceToolset::execFindClosestSurface },
		{ .NameUTF8 = UTF8TEXT("ListSurfaces"), .Pointer = &UModellingSurfaceToolset::execListSurfaces },
		{ .NameUTF8 = UTF8TEXT("PreviewSurface"), .Pointer = &UModellingSurfaceToolset::execPreviewSurface },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_ApplyGlass, "ApplyGlass" }, // f4244aed27cd8fa6415e65cd53c425b60626bca3
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfaceFaces, "ApplySurfaceFaces" }, // 5dc2299824d4431c4542cde7b0dac83afad7c3d4
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_ApplySurfacePart, "ApplySurfacePart" }, // 8de8b722e03709e3e14df80b9f6f621565d3cf7a
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_FindClosestSurface, "FindClosestSurface" }, // 2fe70d545cf8cd4b60f1ade6d9868a54a4e63127
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_ListSurfaces, "ListSurfaces" }, // 4b4ee0a96223cc7ce2b022b40325d9fc627cd365
		{ &Z_Construct_UFunction_UModellingSurfaceToolset_PreviewSurface, "PreviewSurface" }, // a47df0f1e28c213fb3642abfa3ca1854329d20d2
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingSurfaceToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingSurfaceToolset,
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
static void UModellingSurfaceToolset_StaticRegisterNativesUModellingSurfaceToolset()
{
	UClass* Class = UModellingSurfaceToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingSurfaceToolset;
UClass* Z_Construct_UClass_UModellingSurfaceToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingSurfaceToolset;
		if (!Z_Registration_Info_UClass_UModellingSurfaceToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingSurfaceToolset"),
				Z_Registration_Info_UClass_UModellingSurfaceToolset.InnerSingleton,
				UModellingSurfaceToolset_StaticRegisterNativesUModellingSurfaceToolset,
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
		return Z_Registration_Info_UClass_UModellingSurfaceToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingSurfaceToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingSurfaceToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingSurfaceToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingSurfaceToolset::UModellingSurfaceToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingSurfaceToolset);
UModellingSurfaceToolset::~UModellingSurfaceToolset() {}
// ********** End Class UModellingSurfaceToolset ***************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingSurfaceToolset, TEXT("UModellingSurfaceToolset"), &Z_Registration_Info_UClass_UModellingSurfaceToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingSurfaceToolset), 3398534066U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h__Script_ModellingToolset_13298678e1bdb04b360e24970eb7fa03f6762d0f{
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
