// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingVisionToolset.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingVisionToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingComparison(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingVisionToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingVisionToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FModellingCapture *************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FModellingCapture_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FModellingCapture>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModellingCapture); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Result of CaptureViews. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result of CaptureViews." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Contact sheet: all requested views tiled left-to-right, top-to-bottom in the order given by Summary.views_in_sheet_order. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Contact sheet: all requested views tiled left-to-right, top-to-bottom in the order given by Summary.views_in_sheet_order." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Summary_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** JSON: step number, session folder, saved file paths, view order, framed bounds. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "JSON: step number, session folder, saved file paths, view order, framed bounds." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModellingCapture constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Summary;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModellingCapture constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModellingCapture>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FModellingCapture Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingCapture, Image), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) }; // 7da671e557717bf7df314aac298bc871a740b4f5
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Summary = { "Summary", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingCapture, Summary), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Summary_MetaData), NewProp_Summary_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Summary,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FModellingCapture Property Definitions ******************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
	nullptr,
	&NewStructOps,
	"ModellingCapture",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FModellingCapture>(),
	alignof(FModellingCapture),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModellingCapture;
UScriptStruct* Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FModellingCapture.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FModellingCapture.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModellingCapture, (UObject*)Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase::Outer), TEXT("ModellingCapture"));
		}
		return Z_Registration_Info_UScriptStruct_FModellingCapture.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FModellingCapture.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModellingCapture.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModellingCapture.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FModellingCapture ***************************************************

// ********** Begin ScriptStruct FModellingComparison **********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FModellingComparison_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FModellingComparison>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModellingComparison); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Result of CompareToReference. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result of CompareToReference." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Three pictures side by side: the reference, the model, and an overlap map (grey = both, red = model only, blue = reference only). */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Three pictures side by side: the reference, the model, and an overlap map (grey = both, red = model only, blue = reference only)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Summary_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** JSON: overlap_score (0 to 1), verdict, proportion error, and plain-language \"where_it_differs\" hints. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "JSON: overlap_score (0 to 1), verdict, proportion error, and plain-language \"where_it_differs\" hints." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModellingComparison constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Summary;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModellingComparison constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModellingComparison>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FModellingComparison Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingComparison, Image), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) }; // 7da671e557717bf7df314aac298bc871a740b4f5
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Summary = { "Summary", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingComparison, Summary), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Summary_MetaData), NewProp_Summary_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Summary,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FModellingComparison Property Definitions ***************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
	nullptr,
	&NewStructOps,
	"ModellingComparison",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FModellingComparison>(),
	alignof(FModellingComparison),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModellingComparison;
UScriptStruct* Z_Construct_UScriptStruct_FModellingComparison(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FModellingComparison.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FModellingComparison.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModellingComparison, (UObject*)Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase::Outer), TEXT("ModellingComparison"));
		}
		return Z_Registration_Info_UScriptStruct_FModellingComparison.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FModellingComparison.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModellingComparison.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModellingComparison.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FModellingComparison ************************************************

// ********** Begin Class UModellingVisionToolset Function CaptureViews ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingVisionToolset_CaptureViews_Statics
struct UHT_STATICS
{
	struct ModellingVisionToolset_eventCaptureViews_Parms
	{
		FString ActorNames;
		FString Views;
		FString ViewMode;
		int32 Resolution;
		bool bIsolate;
		bool bForcePerspective;
		FString Label;
		FModellingCapture ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Vision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Captures the model from several angles and saves each image to the progress folder.\n\x09 * Call this after every meaningful modelling step and compare against the reference.\n\x09 *\n\x09 * Valid view names: iso (front-right perspective), iso_back (back-left perspective), front (camera on +X),\n\x09 * back (-X), right (+Y), left (-Y), top (+Z), bottom (-Z). Axis views are orthographic unless bForcePerspective.\n\x09 *\n\x09 * @param ActorNames         Comma-separated actor labels to frame. Empty frames all actors created by this toolset.\n\x09 * @param Views              Comma-separated view names. Empty uses \"iso,front,right,top\".\n\x09 * @param ViewMode           \"lit\" (default, fixed studio lighting), \"clay\" (neutral grey with shading, best for judging form), \"unlit\" (flat material colour, no shading), or \"normals\" (surface direction as colour, shows bumps and creases).\n\x09 * @param Resolution         Pixel size of one square tile. 0 uses the project setting.\n\x09 * @param bIsolate           If true, render only the framed actors and hide the rest of the level.\n\x09 * @param bForcePerspective  If true, axis views use perspective instead of orthographic.\n\x09 * @param Label              Optional short tag put in the file names and log, e.g. \"added_roof\".\n\x09 * @return Contact sheet image plus JSON summary with saved file paths. */" },
#endif
		{ "CPP_Default_bForcePerspective", "false" },
		{ "CPP_Default_bIsolate", "false" },
		{ "CPP_Default_Label", "" },
		{ "CPP_Default_Resolution", "0" },
		{ "CPP_Default_ViewMode", "lit" },
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Captures the model from several angles and saves each image to the progress folder.\nCall this after every meaningful modelling step and compare against the reference.\n\nValid view names: iso (front-right perspective), iso_back (back-left perspective), front (camera on +X),\nback (-X), right (+Y), left (-Y), top (+Z), bottom (-Z). Axis views are orthographic unless bForcePerspective.\n\n@param ActorNames         Comma-separated actor labels to frame. Empty frames all actors created by this toolset.\n@param Views              Comma-separated view names. Empty uses \"iso,front,right,top\".\n@param ViewMode           \"lit\" (default, fixed studio lighting), \"clay\" (neutral grey with shading, best for judging form), \"unlit\" (flat material colour, no shading), or \"normals\" (surface direction as colour, shows bumps and creases).\n@param Resolution         Pixel size of one square tile. 0 uses the project setting.\n@param bIsolate           If true, render only the framed actors and hide the rest of the level.\n@param bForcePerspective  If true, axis views use perspective instead of orthographic.\n@param Label              Optional short tag put in the file names and log, e.g. \"added_roof\".\n@return Contact sheet image plus JSON summary with saved file paths." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorNames_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Views_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewMode_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CaptureViews constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorNames;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Views;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ViewMode;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Resolution;
	static void NewProp_bIsolate_SetBit(void* Obj)
	{
		((ModellingVisionToolset_eventCaptureViews_Parms*)Obj)->bIsolate = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsolate;
	static void NewProp_bForcePerspective_SetBit(void* Obj)
	{
		((ModellingVisionToolset_eventCaptureViews_Parms*)Obj)->bForcePerspective = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bForcePerspective;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CaptureViews constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CaptureViews Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ActorNames = { "ActorNames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, ActorNames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorNames_MetaData), NewProp_ActorNames_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Views = { "Views", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, Views), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Views_MetaData), NewProp_Views_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ViewMode = { "ViewMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, ViewMode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewMode_MetaData), NewProp_ViewMode_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Resolution = { "Resolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, Resolution), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bIsolate = { "bIsolate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingVisionToolset_eventCaptureViews_Parms), &UHT_STATICS::NewProp_bIsolate_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bForcePerspective = { "bForcePerspective", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingVisionToolset_eventCaptureViews_Parms), &UHT_STATICS::NewProp_bForcePerspective_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCaptureViews_Parms, ReturnValue), Z_Construct_UScriptStruct_FModellingCapture, METADATA_PARAMS(0, nullptr) }; // c715ef10e38f8c626852ead30acc4e35c7895ea0
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Views,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ViewMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Resolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bIsolate,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bForcePerspective,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CaptureViews Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingVisionToolset, nullptr, "CaptureViews", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingVisionToolset_eventCaptureViews_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingVisionToolset_eventCaptureViews_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingVisionToolset_CaptureViews(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingVisionToolset::execCaptureViews)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorNames);
	P_GET_PROPERTY(FStrProperty,Z_Param_Views);
	P_GET_PROPERTY(FStrProperty,Z_Param_ViewMode);
	P_GET_PROPERTY(FIntProperty,Z_Param_Resolution);
	P_GET_UBOOL(Z_Param_bIsolate);
	P_GET_UBOOL(Z_Param_bForcePerspective);
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModellingCapture*)Z_Param__Result=UModellingVisionToolset::CaptureViews(Z_Param_ActorNames,Z_Param_Views,Z_Param_ViewMode,Z_Param_Resolution,Z_Param_bIsolate,Z_Param_bForcePerspective,Z_Param_Label);
	P_NATIVE_END;
}
// ********** End Class UModellingVisionToolset Function CaptureViews ******************************

// ********** Begin Class UModellingVisionToolset Function CompareToReference **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingVisionToolset_CompareToReference_Statics
struct UHT_STATICS
{
	struct ModellingVisionToolset_eventCompareToReference_Parms
	{
		FString ReferenceName;
		FString View;
		FString ActorNames;
		FModellingComparison ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Vision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Checks how closely the model matches a reference picture. Renders the model from the same straight-on view and compares the two silhouettes.\n\x09 * Returns an overlap score (1 = identical outline), a verdict, the proportion error, and plain hints such as \"between 25% and 37% of the way down\n\x09 * the model is 22% narrower than the reference\", plus a side-by-side picture. Use it after blocking out and again before asking for review.\n\x09 * Works best when the reference has a plain background. Add \"view: front\" to the reference's notes (or put \"front\" in its file name) to label it.\n\x09 * Same capture is available as the direct tool \"modelling_compare_to_reference\", which returns a real image.\n\x09 * @param ReferenceName  File name from ListReferences.\n\x09 * @param View           front, back, left, right, top or bottom. Empty uses the reference's label, or front.\n\x09 * @param ActorNames     Comma-separated actor labels to compare. Empty uses every actor the toolset created. */" },
#endif
		{ "CPP_Default_ActorNames", "" },
		{ "CPP_Default_View", "" },
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks how closely the model matches a reference picture. Renders the model from the same straight-on view and compares the two silhouettes.\nReturns an overlap score (1 = identical outline), a verdict, the proportion error, and plain hints such as \"between 25% and 37% of the way down\nthe model is 22% narrower than the reference\", plus a side-by-side picture. Use it after blocking out and again before asking for review.\nWorks best when the reference has a plain background. Add \"view: front\" to the reference's notes (or put \"front\" in its file name) to label it.\nSame capture is available as the direct tool \"modelling_compare_to_reference\", which returns a real image.\n@param ReferenceName  File name from ListReferences.\n@param View           front, back, left, right, top or bottom. Empty uses the reference's label, or front.\n@param ActorNames     Comma-separated actor labels to compare. Empty uses every actor the toolset created." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReferenceName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_View_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompareToReference constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReferenceName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_View;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActorNames;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompareToReference constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompareToReference Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReferenceName = { "ReferenceName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCompareToReference_Parms, ReferenceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReferenceName_MetaData), NewProp_ReferenceName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_View = { "View", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCompareToReference_Parms, View), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_View_MetaData), NewProp_View_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ActorNames = { "ActorNames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCompareToReference_Parms, ActorNames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorNames_MetaData), NewProp_ActorNames_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventCompareToReference_Parms, ReturnValue), Z_Construct_UScriptStruct_FModellingComparison, METADATA_PARAMS(0, nullptr) }; // 9d7fb4756240bfc3c82c12cb1c04c9272cc014a6
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReferenceName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_View,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ActorNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CompareToReference Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingVisionToolset, nullptr, "CompareToReference", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingVisionToolset_eventCompareToReference_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingVisionToolset_eventCompareToReference_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingVisionToolset_CompareToReference(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingVisionToolset::execCompareToReference)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ReferenceName);
	P_GET_PROPERTY(FStrProperty,Z_Param_View);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActorNames);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModellingComparison*)Z_Param__Result=UModellingVisionToolset::CompareToReference(Z_Param_ReferenceName,Z_Param_View,Z_Param_ActorNames);
	P_NATIVE_END;
}
// ********** End Class UModellingVisionToolset Function CompareToReference ************************

// ********** Begin Class UModellingVisionToolset Function GetProgressImage ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingVisionToolset_GetProgressImage_Statics
struct UHT_STATICS
{
	struct ModellingVisionToolset_eventGetProgressImage_Parms
	{
		FString RelativePath;
		int32 MaxDimension;
		FToolsetImage ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Vision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Re-opens an earlier progress image so it can be compared with the current state.\n\x09 * @param RelativePath  Path relative to the progress folder, as listed by ListProgressImages.\n\x09 * @param MaxDimension  Longest side in pixels after downscaling. */" },
#endif
		{ "CPP_Default_MaxDimension", "1024" },
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Re-opens an earlier progress image so it can be compared with the current state.\n@param RelativePath  Path relative to the progress folder, as listed by ListProgressImages.\n@param MaxDimension  Longest side in pixels after downscaling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RelativePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetProgressImage constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_RelativePath;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDimension;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProgressImage constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProgressImage Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_RelativePath = { "RelativePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventGetProgressImage_Parms, RelativePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RelativePath_MetaData), NewProp_RelativePath_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxDimension = { "MaxDimension", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventGetProgressImage_Parms, MaxDimension), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventGetProgressImage_Parms, ReturnValue), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(0, nullptr) }; // 7da671e557717bf7df314aac298bc871a740b4f5
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_RelativePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDimension,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetProgressImage Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingVisionToolset, nullptr, "GetProgressImage", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingVisionToolset_eventGetProgressImage_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingVisionToolset_eventGetProgressImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingVisionToolset_GetProgressImage(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingVisionToolset::execGetProgressImage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_RelativePath);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxDimension);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FToolsetImage*)Z_Param__Result=UModellingVisionToolset::GetProgressImage(Z_Param_RelativePath,Z_Param_MaxDimension);
	P_NATIVE_END;
}
// ********** End Class UModellingVisionToolset Function GetProgressImage **************************

// ********** Begin Class UModellingVisionToolset Function ListProgressImages **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingVisionToolset_ListProgressImages_Statics
struct UHT_STATICS
{
	struct ModellingVisionToolset_eventListProgressImages_Parms
	{
		int32 MaxItems;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Vision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists images saved in the progress folder as a JSON array of relative paths, newest first.\n\x09 * @param MaxItems  Maximum number of entries to return. */" },
#endif
		{ "CPP_Default_MaxItems", "30" },
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists images saved in the progress folder as a JSON array of relative paths, newest first.\n@param MaxItems  Maximum number of entries to return." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListProgressImages constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxItems;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListProgressImages constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListProgressImages Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxItems = { "MaxItems", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventListProgressImages_Parms, MaxItems), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventListProgressImages_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListProgressImages Property Definitions *********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingVisionToolset, nullptr, "ListProgressImages", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingVisionToolset_eventListProgressImages_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingVisionToolset_eventListProgressImages_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingVisionToolset_ListProgressImages(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingVisionToolset::execListProgressImages)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxItems);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingVisionToolset::ListProgressImages(Z_Param_MaxItems);
	P_NATIVE_END;
}
// ********** End Class UModellingVisionToolset Function ListProgressImages ************************

// ********** Begin Class UModellingVisionToolset Function StartSession ****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingVisionToolset_StartSession_Statics
struct UHT_STATICS
{
	struct ModellingVisionToolset_eventStartSession_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Vision" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Starts a fresh progress sub-folder and resets the step counter. Call at the start of a new task.\n\x09 * @param Name  Short name for the session, used in the folder name.\n\x09 * @return Absolute path of the new session folder. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts a fresh progress sub-folder and resets the step counter. Call at the start of a new task.\n@param Name  Short name for the session, used in the folder name.\n@return Absolute path of the new session folder." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartSession constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StartSession constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StartSession Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventStartSession_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingVisionToolset_eventStartSession_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function StartSession Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingVisionToolset, nullptr, "StartSession", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingVisionToolset_eventStartSession_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingVisionToolset_eventStartSession_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingVisionToolset_StartSession(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingVisionToolset::execStartSession)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingVisionToolset::StartSession(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingVisionToolset Function StartSession ******************************

// ********** Begin Class UModellingVisionToolset **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingVisionToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Lets the AI see what it is building. Renders the model from controlled camera angles using an\n * off-screen scene capture (independent of the editor viewport layout), saves every image to the\n * progress folder, and returns a contact sheet.\n *\n * Axis convention: +X is the model's front, +Y its right, +Z up.\n *\n * Note: the same capture is also exposed as the raw MCP tool \"modelling_capture_views\", which returns a real\n * image content block. Prefer that tool if this one's image arrives as text.\n */" },
#endif
		{ "IncludePath", "ModellingVisionToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingVisionToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lets the AI see what it is building. Renders the model from controlled camera angles using an\noff-screen scene capture (independent of the editor viewport layout), saves every image to the\nprogress folder, and returns a contact sheet.\n\nAxis convention: +X is the model's front, +Y its right, +Z up.\n\nNote: the same capture is also exposed as the raw MCP tool \"modelling_capture_views\", which returns a real\nimage content block. Prefer that tool if this one's image arrives as text." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingVisionToolset constinit property declarations ******************
// ********** End Class UModellingVisionToolset constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CaptureViews"), .Pointer = &UModellingVisionToolset::execCaptureViews },
		{ .NameUTF8 = UTF8TEXT("CompareToReference"), .Pointer = &UModellingVisionToolset::execCompareToReference },
		{ .NameUTF8 = UTF8TEXT("GetProgressImage"), .Pointer = &UModellingVisionToolset::execGetProgressImage },
		{ .NameUTF8 = UTF8TEXT("ListProgressImages"), .Pointer = &UModellingVisionToolset::execListProgressImages },
		{ .NameUTF8 = UTF8TEXT("StartSession"), .Pointer = &UModellingVisionToolset::execStartSession },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingVisionToolset_CaptureViews, "CaptureViews" }, // 302186a4f57f2c57f66fea20e3278aece6e02323
		{ &Z_Construct_UFunction_UModellingVisionToolset_CompareToReference, "CompareToReference" }, // bf0e593bd34fdf813833435e38cba8e822609d82
		{ &Z_Construct_UFunction_UModellingVisionToolset_GetProgressImage, "GetProgressImage" }, // dbd614f089c04010a2b0b5d379381445995c7d2b
		{ &Z_Construct_UFunction_UModellingVisionToolset_ListProgressImages, "ListProgressImages" }, // db67f267ade3e427a7b9c9c00bab1d04ea43d946
		{ &Z_Construct_UFunction_UModellingVisionToolset_StartSession, "StartSession" }, // 2bd020e6019faae85a29d252d73269ce22ab4576
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingVisionToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingVisionToolset,
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
static void UModellingVisionToolset_StaticRegisterNativesUModellingVisionToolset()
{
	UClass* Class = UModellingVisionToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingVisionToolset;
UClass* Z_Construct_UClass_UModellingVisionToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingVisionToolset;
		if (!Z_Registration_Info_UClass_UModellingVisionToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingVisionToolset"),
				Z_Registration_Info_UClass_UModellingVisionToolset.InnerSingleton,
				UModellingVisionToolset_StaticRegisterNativesUModellingVisionToolset,
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
		return Z_Registration_Info_UClass_UModellingVisionToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingVisionToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingVisionToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingVisionToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingVisionToolset::UModellingVisionToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingVisionToolset);
UModellingVisionToolset::~UModellingVisionToolset() {}
// ********** End Class UModellingVisionToolset ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FModellingCapture, Z_Construct_UScriptStruct_FModellingCapture_Statics::NewStructOps, TEXT("ModellingCapture"),&Z_Registration_Info_UScriptStruct_FModellingCapture, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModellingCapture), 3340103440U) },
		{ Z_Construct_UScriptStruct_FModellingComparison, Z_Construct_UScriptStruct_FModellingComparison_Statics::NewStructOps, TEXT("ModellingComparison"),&Z_Registration_Info_UScriptStruct_FModellingComparison, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModellingComparison), 2642392181U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingVisionToolset, TEXT("UModellingVisionToolset"), &Z_Registration_Info_UClass_UModellingVisionToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingVisionToolset), 2437406606U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h__Script_ModellingToolset_f547b2a19ac7074d2925cf18ead3d7f45fe2dcb3{
	TEXT("/Script/ModellingToolset"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
