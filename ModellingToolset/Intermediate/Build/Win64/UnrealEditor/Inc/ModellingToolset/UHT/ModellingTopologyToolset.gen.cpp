// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingTopologyToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingTopologyToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTopologyToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTopologyToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingTopologyToolset Function CompactMesh ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_CompactMesh_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventCompactMesh_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Removes unused vertices and compacts the mesh storage.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes unused vertices and compacts the mesh storage.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CompactMesh constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CompactMesh constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CompactMesh Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventCompactMesh_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventCompactMesh_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CompactMesh Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "CompactMesh", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventCompactMesh_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventCompactMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_CompactMesh(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execCompactMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::CompactMesh(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function CompactMesh *****************************

// ********** Begin Class UModellingTopologyToolset Function FillHoles *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_FillHoles_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventFillHoles_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Closes open boundaries (holes) in the mesh. Returns the actor summary plus how many holes were filled or failed.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Closes open boundaries (holes) in the mesh. Returns the actor summary plus how many holes were filled or failed.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FillHoles constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FillHoles constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FillHoles Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventFillHoles_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventFillHoles_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FillHoles Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "FillHoles", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventFillHoles_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventFillHoles_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_FillHoles(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execFillHoles)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::FillHoles(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function FillHoles *******************************

// ********** Begin Class UModellingTopologyToolset Function FlipNormals ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_FlipNormals_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventFlipNormals_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Flips every face, turning the mesh inside out. Use when a model looks dark or see-through from the outside.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Flips every face, turning the mesh inside out. Use when a model looks dark or see-through from the outside.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FlipNormals constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FlipNormals constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FlipNormals Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventFlipNormals_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventFlipNormals_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function FlipNormals Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "FlipNormals", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventFlipNormals_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventFlipNormals_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_FlipNormals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execFlipNormals)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::FlipNormals(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function FlipNormals *****************************

// ********** Begin Class UModellingTopologyToolset Function MergeOverlaps *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_MergeOverlaps_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventMergeOverlaps_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unions overlapping shells inside one mesh into a single clean surface. Use after CombineActors when parts intersect.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unions overlapping shells inside one mesh into a single clean surface. Use after CombineActors when parts intersect.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MergeOverlaps constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MergeOverlaps constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MergeOverlaps Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventMergeOverlaps_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventMergeOverlaps_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MergeOverlaps Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "MergeOverlaps", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventMergeOverlaps_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventMergeOverlaps_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_MergeOverlaps(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execMergeOverlaps)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::MergeOverlaps(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function MergeOverlaps ***************************

// ********** Begin Class UModellingTopologyToolset Function RecomputeNormals **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_RecomputeNormals_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventRecomputeNormals_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Recomputes vertex normals from the geometry. Fixes odd shading after edits.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Recomputes vertex normals from the geometry. Fixes odd shading after edits.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RecomputeNormals constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RecomputeNormals constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RecomputeNormals Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRecomputeNormals_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRecomputeNormals_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RecomputeNormals Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "RecomputeNormals", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventRecomputeNormals_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventRecomputeNormals_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_RecomputeNormals(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execRecomputeNormals)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::RecomputeNormals(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function RecomputeNormals ************************

// ********** Begin Class UModellingTopologyToolset Function RemoveHiddenFaces *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_RemoveHiddenFaces_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventRemoveHiddenFaces_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Removes interior and occluded faces that can never be seen, for example after combining overlapping parts.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes interior and occluded faces that can never be seen, for example after combining overlapping parts.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveHiddenFaces constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveHiddenFaces constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveHiddenFaces Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRemoveHiddenFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRemoveHiddenFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RemoveHiddenFaces Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "RemoveHiddenFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventRemoveHiddenFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventRemoveHiddenFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_RemoveHiddenFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execRemoveHiddenFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::RemoveHiddenFaces(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function RemoveHiddenFaces ***********************

// ********** Begin Class UModellingTopologyToolset Function RemoveSmallParts **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_RemoveSmallParts_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventRemoveSmallParts_Parms
	{
		FString Name;
		int32 MinTriangleCount;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Removes disconnected fragments smaller than a triangle count.\n\x09 * @param Name              Actor label.\n\x09 * @param MinTriangleCount  Components with fewer triangles are removed. */" },
#endif
		{ "CPP_Default_MinTriangleCount", "10" },
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes disconnected fragments smaller than a triangle count.\n@param Name              Actor label.\n@param MinTriangleCount  Components with fewer triangles are removed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveSmallParts constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinTriangleCount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveSmallParts constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveSmallParts Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRemoveSmallParts_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MinTriangleCount = { "MinTriangleCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRemoveSmallParts_Parms, MinTriangleCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRemoveSmallParts_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MinTriangleCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RemoveSmallParts Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "RemoveSmallParts", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventRemoveSmallParts_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventRemoveSmallParts_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_RemoveSmallParts(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execRemoveSmallParts)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_MinTriangleCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::RemoveSmallParts(Z_Param_Name,Z_Param_MinTriangleCount);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function RemoveSmallParts ************************

// ********** Begin Class UModellingTopologyToolset Function RepairDegenerate **********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_RepairDegenerate_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventRepairDegenerate_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Repairs or removes degenerate (zero-area) triangles.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Repairs or removes degenerate (zero-area) triangles.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RepairDegenerate constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RepairDegenerate constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RepairDegenerate Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRepairDegenerate_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventRepairDegenerate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RepairDegenerate Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "RepairDegenerate", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventRepairDegenerate_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventRepairDegenerate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_RepairDegenerate(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execRepairDegenerate)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::RepairDegenerate(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function RepairDegenerate ************************

// ********** Begin Class UModellingTopologyToolset Function Simplify ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_Simplify_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventSimplify_Parms
	{
		FString Name;
		int32 TargetTriangleCount;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reduces the triangle count while preserving the shape.\n\x09 * @param Name                 Actor label.\n\x09 * @param TargetTriangleCount  Triangle count to reduce to (minimum 4). */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reduces the triangle count while preserving the shape.\n@param Name                 Actor label.\n@param TargetTriangleCount  Triangle count to reduce to (minimum 4)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Simplify constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetTriangleCount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Simplify constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Simplify Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventSimplify_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_TargetTriangleCount = { "TargetTriangleCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventSimplify_Parms, TargetTriangleCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventSimplify_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetTriangleCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Simplify Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "Simplify", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventSimplify_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventSimplify_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_Simplify(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execSimplify)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_TargetTriangleCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::Simplify(Z_Param_Name,Z_Param_TargetTriangleCount);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function Simplify ********************************

// ********** Begin Class UModellingTopologyToolset Function UniformRemesh *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_UniformRemesh_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventUniformRemesh_Parms
	{
		FString Name;
		int32 TargetTriangleCount;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rebuilds the mesh with evenly sized triangles. Good after booleans or heavy deformation. Destroys polygroup structure and UV seams.\n\x09 * @param Name                 Actor label.\n\x09 * @param TargetTriangleCount  Approximate triangle count to aim for (100 to 500000). */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rebuilds the mesh with evenly sized triangles. Good after booleans or heavy deformation. Destroys polygroup structure and UV seams.\n@param Name                 Actor label.\n@param TargetTriangleCount  Approximate triangle count to aim for (100 to 500000)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function UniformRemesh constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetTriangleCount;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function UniformRemesh constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function UniformRemesh Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventUniformRemesh_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_TargetTriangleCount = { "TargetTriangleCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventUniformRemesh_Parms, TargetTriangleCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventUniformRemesh_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TargetTriangleCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function UniformRemesh Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "UniformRemesh", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventUniformRemesh_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventUniformRemesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_UniformRemesh(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execUniformRemesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_TargetTriangleCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::UniformRemesh(Z_Param_Name,Z_Param_TargetTriangleCount);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function UniformRemesh ***************************

// ********** Begin Class UModellingTopologyToolset Function WeldEdges *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingTopologyToolset_WeldEdges_Statics
struct UHT_STATICS
{
	struct ModellingTopologyToolset_eventWeldEdges_Parms
	{
		FString Name;
		float Tolerance;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Topology" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Welds coincident open edges, joining parts that touch.\n\x09 * @param Name       Actor label.\n\x09 * @param Tolerance  Maximum gap to weld, cm. */" },
#endif
		{ "CPP_Default_Tolerance", "0.010000" },
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Welds coincident open edges, joining parts that touch.\n@param Name       Actor label.\n@param Tolerance  Maximum gap to weld, cm." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function WeldEdges constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Tolerance;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WeldEdges constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WeldEdges Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventWeldEdges_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Tolerance = { "Tolerance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventWeldEdges_Parms, Tolerance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingTopologyToolset_eventWeldEdges_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Tolerance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function WeldEdges Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingTopologyToolset, nullptr, "WeldEdges", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingTopologyToolset_eventWeldEdges_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingTopologyToolset_eventWeldEdges_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingTopologyToolset_WeldEdges(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingTopologyToolset::execWeldEdges)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Tolerance);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingTopologyToolset::WeldEdges(Z_Param_Name,Z_Param_Tolerance);
	P_NATIVE_END;
}
// ********** End Class UModellingTopologyToolset Function WeldEdges *******************************

// ********** Begin Class UModellingTopologyToolset ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingTopologyToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Mesh topology and repair: remeshing, simplification, hole filling, welding, cleanup and normals.\n * Run these after booleans and deformations to get a clean, game-ready mesh.\n * Every tool works on an actor created by this toolset and returns its updated JSON summary.\n */" },
#endif
		{ "IncludePath", "ModellingTopologyToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingTopologyToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh topology and repair: remeshing, simplification, hole filling, welding, cleanup and normals.\nRun these after booleans and deformations to get a clean, game-ready mesh.\nEvery tool works on an actor created by this toolset and returns its updated JSON summary." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingTopologyToolset constinit property declarations ****************
// ********** End Class UModellingTopologyToolset constinit property declarations ******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CompactMesh"), .Pointer = &UModellingTopologyToolset::execCompactMesh },
		{ .NameUTF8 = UTF8TEXT("FillHoles"), .Pointer = &UModellingTopologyToolset::execFillHoles },
		{ .NameUTF8 = UTF8TEXT("FlipNormals"), .Pointer = &UModellingTopologyToolset::execFlipNormals },
		{ .NameUTF8 = UTF8TEXT("MergeOverlaps"), .Pointer = &UModellingTopologyToolset::execMergeOverlaps },
		{ .NameUTF8 = UTF8TEXT("RecomputeNormals"), .Pointer = &UModellingTopologyToolset::execRecomputeNormals },
		{ .NameUTF8 = UTF8TEXT("RemoveHiddenFaces"), .Pointer = &UModellingTopologyToolset::execRemoveHiddenFaces },
		{ .NameUTF8 = UTF8TEXT("RemoveSmallParts"), .Pointer = &UModellingTopologyToolset::execRemoveSmallParts },
		{ .NameUTF8 = UTF8TEXT("RepairDegenerate"), .Pointer = &UModellingTopologyToolset::execRepairDegenerate },
		{ .NameUTF8 = UTF8TEXT("Simplify"), .Pointer = &UModellingTopologyToolset::execSimplify },
		{ .NameUTF8 = UTF8TEXT("UniformRemesh"), .Pointer = &UModellingTopologyToolset::execUniformRemesh },
		{ .NameUTF8 = UTF8TEXT("WeldEdges"), .Pointer = &UModellingTopologyToolset::execWeldEdges },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingTopologyToolset_CompactMesh, "CompactMesh" }, // c167f50be1d47908dea4f5b2a155f14a28add0dc
		{ &Z_Construct_UFunction_UModellingTopologyToolset_FillHoles, "FillHoles" }, // 19fe78c001f6b5d94a61f702906492564628bd04
		{ &Z_Construct_UFunction_UModellingTopologyToolset_FlipNormals, "FlipNormals" }, // 22d92fd7a6662200372112c989a35bb5302f82f0
		{ &Z_Construct_UFunction_UModellingTopologyToolset_MergeOverlaps, "MergeOverlaps" }, // 4c11330de65b2b767f657fa05145c72a9746b7d8
		{ &Z_Construct_UFunction_UModellingTopologyToolset_RecomputeNormals, "RecomputeNormals" }, // 0138504cc2f27061fe7c8956a3ef023c60cf6185
		{ &Z_Construct_UFunction_UModellingTopologyToolset_RemoveHiddenFaces, "RemoveHiddenFaces" }, // 850a4e57bb3a98347a0f9c9652b008dabd11aafb
		{ &Z_Construct_UFunction_UModellingTopologyToolset_RemoveSmallParts, "RemoveSmallParts" }, // 9136a39c6712a46d62fe4b7ba4dbc040e5b9205e
		{ &Z_Construct_UFunction_UModellingTopologyToolset_RepairDegenerate, "RepairDegenerate" }, // e3f4103962bcc3a589318962415ee81799e973cd
		{ &Z_Construct_UFunction_UModellingTopologyToolset_Simplify, "Simplify" }, // d64b5693768215b89db345abce882efcf75aff05
		{ &Z_Construct_UFunction_UModellingTopologyToolset_UniformRemesh, "UniformRemesh" }, // 7a60fb315b3c86b25dca236b418f462580cd1e58
		{ &Z_Construct_UFunction_UModellingTopologyToolset_WeldEdges, "WeldEdges" }, // 856bebf7809baa0e6bff9b320171d796fb636310
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingTopologyToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingTopologyToolset,
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
static void UModellingTopologyToolset_StaticRegisterNativesUModellingTopologyToolset()
{
	UClass* Class = UModellingTopologyToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingTopologyToolset;
UClass* Z_Construct_UClass_UModellingTopologyToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingTopologyToolset;
		if (!Z_Registration_Info_UClass_UModellingTopologyToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingTopologyToolset"),
				Z_Registration_Info_UClass_UModellingTopologyToolset.InnerSingleton,
				UModellingTopologyToolset_StaticRegisterNativesUModellingTopologyToolset,
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
		return Z_Registration_Info_UClass_UModellingTopologyToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingTopologyToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingTopologyToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingTopologyToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingTopologyToolset::UModellingTopologyToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingTopologyToolset);
UModellingTopologyToolset::~UModellingTopologyToolset() {}
// ********** End Class UModellingTopologyToolset **************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingTopologyToolset, TEXT("UModellingTopologyToolset"), &Z_Registration_Info_UClass_UModellingTopologyToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingTopologyToolset), 288340377U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h__Script_ModellingToolset_2f6196bf2cd2243a0d73e4f64a29316a2051dd0b{
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
