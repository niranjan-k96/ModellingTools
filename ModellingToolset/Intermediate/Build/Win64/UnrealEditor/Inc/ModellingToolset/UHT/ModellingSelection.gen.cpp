// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingSelection.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingSelection() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FModellingSelection ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FModellingSelection_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FModellingSelection>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModellingSelection); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Describes which faces (triangles) of a mesh an edit applies to.\n * All positions and directions are in the ACTOR'S LOCAL SPACE, in cm.\n *\n * Mode values:\n *   \"all\"       every face.\n *   \"normal\"    faces whose normal is within Scalar degrees of the direction A. Example: A=(0,0,1), Scalar=10 selects the top faces.\n *   \"box\"       faces fully inside the axis-aligned box with corners A and B.\n *   \"sphere\"    faces fully inside the sphere centred at A with radius Scalar.\n *   \"polygroup\" faces in polygroup PolygroupId (see GetPolygroups).\n */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Describes which faces (triangles) of a mesh an edit applies to.\nAll positions and directions are in the ACTOR'S LOCAL SPACE, in cm.\n\nMode values:\n  \"all\"       every face.\n  \"normal\"    faces whose normal is within Scalar degrees of the direction A. Example: A=(0,0,1), Scalar=10 selects the top faces.\n  \"box\"       faces fully inside the axis-aligned box with corners A and B.\n  \"sphere\"    faces fully inside the sphere centred at A with radius Scalar.\n  \"polygroup\" faces in polygroup PolygroupId (see GetPolygroups)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "Selection" },
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[] = {
		{ "Category", "Selection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Direction for \"normal\", centre for \"sphere\", first box corner for \"box\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Direction for \"normal\", centre for \"sphere\", first box corner for \"box\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[] = {
		{ "Category", "Selection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Second box corner for \"box\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Second box corner for \"box\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scalar_MetaData[] = {
		{ "Category", "Selection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Angle tolerance in degrees for \"normal\" (default 10), radius in cm for \"sphere\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Angle tolerance in degrees for \"normal\" (default 10), radius in cm for \"sphere\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PolygroupId_MetaData[] = {
		{ "Category", "Selection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Polygroup id for \"polygroup\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSelection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Polygroup id for \"polygroup\"." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModellingSelection constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_A;
	static const UECodeGen_Private::FStructPropertyParams NewProp_B;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scalar;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PolygroupId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModellingSelection constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModellingSelection>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FModellingSelection Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingSelection, Mode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingSelection, A), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_A_MetaData), NewProp_A_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingSelection, B), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_B_MetaData), NewProp_B_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Scalar = { "Scalar", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingSelection, Scalar), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scalar_MetaData), NewProp_Scalar_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_PolygroupId = { "PolygroupId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingSelection, PolygroupId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PolygroupId_MetaData), NewProp_PolygroupId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_A,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_B,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scalar,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PolygroupId,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FModellingSelection Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
	nullptr,
	&NewStructOps,
	"ModellingSelection",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FModellingSelection>(),
	alignof(FModellingSelection),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModellingSelection;
UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FModellingSelection.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FModellingSelection.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModellingSelection, (UObject*)Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase::Outer), TEXT("ModellingSelection"));
		}
		return Z_Registration_Info_UScriptStruct_FModellingSelection.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FModellingSelection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModellingSelection.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModellingSelection.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FModellingSelection *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSelection_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FModellingSelection, Z_Construct_UScriptStruct_FModellingSelection_Statics::NewStructOps, TEXT("ModellingSelection"),&Z_Registration_Info_UScriptStruct_FModellingSelection, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModellingSelection), 273013839U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSelection_h__Script_ModellingToolset_f7e00abf30d24982af95a9481bc7b85eb84792c3{
	TEXT("/Script/ModellingToolset"),
	nullptr, 0,
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
