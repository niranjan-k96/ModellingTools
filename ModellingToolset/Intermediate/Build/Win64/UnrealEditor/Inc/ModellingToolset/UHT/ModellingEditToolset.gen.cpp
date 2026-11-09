// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingEditToolset.h"
#include "ModellingSelection.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingEditToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingEditToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingSelection(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingEditToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingEditToolset Function ArrayCopies *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_ArrayCopies_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventArrayCopies_Parms
	{
		FString Name;
		int32 Copies;
		FVector Offset;
		FRotator Rotation;
		FVector Scale;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Adds repeated copies of the actor's existing geometry. Each copy is the previous one moved by the step transform, so a\n\x09 * Rotation makes a radial array (rotation is around the actor origin) and an Offset makes a linear array.\n\x09 * @param Name      Actor label.\n\x09 * @param Copies    Number of copies to add (1 to 200).\n\x09 * @param Offset    Translation per step, local cm.\n\x09 * @param Rotation  Rotation per step, degrees, around the actor origin.\n\x09 * @param Scale     Scale per step. (1,1,1) keeps the size. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds repeated copies of the actor's existing geometry. Each copy is the previous one moved by the step transform, so a\nRotation makes a radial array (rotation is around the actor origin) and an Offset makes a linear array.\n@param Name      Actor label.\n@param Copies    Number of copies to add (1 to 200).\n@param Offset    Translation per step, local cm.\n@param Rotation  Rotation per step, degrees, around the actor origin.\n@param Scale     Scale per step. (1,1,1) keeps the size." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ArrayCopies constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Copies;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ArrayCopies constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ArrayCopies Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Copies = { "Copies", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, Copies), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventArrayCopies_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Copies,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ArrayCopies Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "ArrayCopies", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventArrayCopies_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventArrayCopies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_ArrayCopies(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execArrayCopies)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_Copies);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Offset);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::ArrayCopies(Z_Param_Name,Z_Param_Copies,Z_Param_Out_Offset,Z_Param_Out_Rotation,Z_Param_Out_Scale);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function ArrayCopies *********************************

// ********** Begin Class UModellingEditToolset Function BevelEdges ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_BevelEdges_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventBevelEdges_Parms
	{
		FString Name;
		float Distance;
		int32 Subdivisions;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bevels every edge between polygroups (for a box, all 12 edges).\n\x09 * @param Name          Actor label.\n\x09 * @param Distance      Bevel width in cm. Keep it well below half the smallest dimension.\n\x09 * @param Subdivisions  0 gives a flat chamfer, higher values give a rounded edge. */" },
#endif
		{ "CPP_Default_Subdivisions", "0" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bevels every edge between polygroups (for a box, all 12 edges).\n@param Name          Actor label.\n@param Distance      Bevel width in cm. Keep it well below half the smallest dimension.\n@param Subdivisions  0 gives a flat chamfer, higher values give a rounded edge." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BevelEdges constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Subdivisions;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BevelEdges constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BevelEdges Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBevelEdges_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBevelEdges_Parms, Distance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Subdivisions = { "Subdivisions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBevelEdges_Parms, Subdivisions), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBevelEdges_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Subdivisions,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BevelEdges Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "BevelEdges", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventBevelEdges_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventBevelEdges_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_BevelEdges(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execBevelEdges)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
	P_GET_PROPERTY(FIntProperty,Z_Param_Subdivisions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::BevelEdges(Z_Param_Name,Z_Param_Distance,Z_Param_Subdivisions);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function BevelEdges **********************************

// ********** Begin Class UModellingEditToolset Function BooleanOp *********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_BooleanOp_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventBooleanOp_Parms
	{
		FString Name;
		FString ToolName;
		FString Operation;
		bool bDeleteTool;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Boolean operation between two actors, using each actor's world transform. Make a cutter actor from primitives, then subtract it.\n\x09 * @param Name         Target actor label; it receives the result.\n\x09 * @param ToolName     Actor label of the tool shape.\n\x09 * @param Operation    \"union\", \"subtract\" or \"intersect\".\n\x09 * @param bDeleteTool  Delete the tool actor afterwards. */" },
#endif
		{ "CPP_Default_bDeleteTool", "true" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Boolean operation between two actors, using each actor's world transform. Make a cutter actor from primitives, then subtract it.\n@param Name         Target actor label; it receives the result.\n@param ToolName     Actor label of the tool shape.\n@param Operation    \"union\", \"subtract\" or \"intersect\".\n@param bDeleteTool  Delete the tool actor afterwards." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ToolName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Operation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BooleanOp constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ToolName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Operation;
	static void NewProp_bDeleteTool_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventBooleanOp_Parms*)Obj)->bDeleteTool = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDeleteTool;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BooleanOp constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BooleanOp Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBooleanOp_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ToolName = { "ToolName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBooleanOp_Parms, ToolName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ToolName_MetaData), NewProp_ToolName_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Operation = { "Operation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBooleanOp_Parms, Operation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Operation_MetaData), NewProp_Operation_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDeleteTool = { "bDeleteTool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventBooleanOp_Parms), &UHT_STATICS::NewProp_bDeleteTool_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventBooleanOp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ToolName,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Operation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDeleteTool,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function BooleanOp Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "BooleanOp", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventBooleanOp_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventBooleanOp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_BooleanOp(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execBooleanOp)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_ToolName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Operation);
	P_GET_UBOOL(Z_Param_bDeleteTool);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::BooleanOp(Z_Param_Name,Z_Param_ToolName,Z_Param_Operation,Z_Param_bDeleteTool);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function BooleanOp ***********************************

// ********** Begin Class UModellingEditToolset Function CombineActors *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_CombineActors_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventCombineActors_Parms
	{
		FString Name;
		FString SourceNames;
		bool bDeleteSources;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Merges other actors into this one so they become a single mesh, preserving their world positions.\n\x09 * @param Name             Target actor label.\n\x09 * @param SourceNames      Comma-separated labels of actors to merge in.\n\x09 * @param bDeleteSources   Delete the source actors afterwards. */" },
#endif
		{ "CPP_Default_bDeleteSources", "true" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Merges other actors into this one so they become a single mesh, preserving their world positions.\n@param Name             Target actor label.\n@param SourceNames      Comma-separated labels of actors to merge in.\n@param bDeleteSources   Delete the source actors afterwards." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceNames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CombineActors constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceNames;
	static void NewProp_bDeleteSources_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventCombineActors_Parms*)Obj)->bDeleteSources = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDeleteSources;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CombineActors constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CombineActors Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCombineActors_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SourceNames = { "SourceNames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCombineActors_Parms, SourceNames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceNames_MetaData), NewProp_SourceNames_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDeleteSources = { "bDeleteSources", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventCombineActors_Parms), &UHT_STATICS::NewProp_bDeleteSources_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCombineActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SourceNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDeleteSources,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CombineActors Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "CombineActors", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventCombineActors_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventCombineActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_CombineActors(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execCombineActors)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_SourceNames);
	P_GET_UBOOL(Z_Param_bDeleteSources);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::CombineActors(Z_Param_Name,Z_Param_SourceNames,Z_Param_bDeleteSources);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function CombineActors *******************************

// ********** Begin Class UModellingEditToolset Function CutWithPlane ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_CutWithPlane_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventCutWithPlane_Parms
	{
		FString Name;
		FVector PlaneOrigin;
		FVector PlaneNormal;
		bool bFlipSide;
		bool bFillHole;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cuts the mesh with a plane and removes one side. The PlaneNormal points toward the side you KEEP (same rule as MirrorMesh).\n\x09 * Example: PlaneNormal (0,0,1) at Z=0 keeps everything above the plane and removes everything below.\n\x09 * @param Name         Actor label.\n\x09 * @param PlaneOrigin  A point on the plane, local cm.\n\x09 * @param PlaneNormal  Points toward the side to keep.\n\x09 * @param bFlipSide    Keep the opposite side instead.\n\x09 * @param bFillHole    Cap the cut with a flat face. */" },
#endif
		{ "CPP_Default_bFillHole", "true" },
		{ "CPP_Default_bFlipSide", "false" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cuts the mesh with a plane and removes one side. The PlaneNormal points toward the side you KEEP (same rule as MirrorMesh).\nExample: PlaneNormal (0,0,1) at Z=0 keeps everything above the plane and removes everything below.\n@param Name         Actor label.\n@param PlaneOrigin  A point on the plane, local cm.\n@param PlaneNormal  Points toward the side to keep.\n@param bFlipSide    Keep the opposite side instead.\n@param bFillHole    Cap the cut with a flat face." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneOrigin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneNormal_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CutWithPlane constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneNormal;
	static void NewProp_bFlipSide_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventCutWithPlane_Parms*)Obj)->bFlipSide = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFlipSide;
	static void NewProp_bFillHole_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventCutWithPlane_Parms*)Obj)->bFillHole = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFillHole;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CutWithPlane constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CutWithPlane Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCutWithPlane_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaneOrigin = { "PlaneOrigin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCutWithPlane_Parms, PlaneOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneOrigin_MetaData), NewProp_PlaneOrigin_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaneNormal = { "PlaneNormal", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCutWithPlane_Parms, PlaneNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneNormal_MetaData), NewProp_PlaneNormal_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFlipSide = { "bFlipSide", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventCutWithPlane_Parms), &UHT_STATICS::NewProp_bFlipSide_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bFillHole = { "bFillHole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventCutWithPlane_Parms), &UHT_STATICS::NewProp_bFillHole_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventCutWithPlane_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaneOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaneNormal,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFlipSide,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bFillHole,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CutWithPlane Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "CutWithPlane", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventCutWithPlane_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventCutWithPlane_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_CutWithPlane(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execCutWithPlane)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneOrigin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneNormal);
	P_GET_UBOOL(Z_Param_bFlipSide);
	P_GET_UBOOL(Z_Param_bFillHole);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::CutWithPlane(Z_Param_Name,Z_Param_Out_PlaneOrigin,Z_Param_Out_PlaneNormal,Z_Param_bFlipSide,Z_Param_bFillHole);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function CutWithPlane ********************************

// ********** Begin Class UModellingEditToolset Function DeleteFaces *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_DeleteFaces_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventDeleteFaces_Parms
	{
		FString Name;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deletes the selected faces, leaving holes. Use FillHoles to close them.\n\x09 * @param Name       Actor label.\n\x09 * @param Selection  Which faces. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deletes the selected faces, leaving holes. Use FillHoles to close them.\n@param Name       Actor label.\n@param Selection  Which faces." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteFaces constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteFaces constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteFaces Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventDeleteFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventDeleteFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventDeleteFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DeleteFaces Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "DeleteFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventDeleteFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventDeleteFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_DeleteFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execDeleteFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::DeleteFaces(Z_Param_Name,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function DeleteFaces *********************************

// ********** Begin Class UModellingEditToolset Function ExtrudeFaces ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_ExtrudeFaces_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventExtrudeFaces_Parms
	{
		FString Name;
		float Distance;
		FModellingSelection Selection;
		FVector Direction;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Extrudes the selected faces.\n\x09 * @param Name       Actor label.\n\x09 * @param Distance   Extrusion distance in cm (positive moves outward along the direction).\n\x09 * @param Selection  Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} extrudes the top faces.\n\x09 * @param Direction  World-independent local direction. Leave (0,0,0) to extrude along the average face normal. */" },
#endif
		{ "CPP_Default_Direction", "" },
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extrudes the selected faces.\n@param Name       Actor label.\n@param Distance   Extrusion distance in cm (positive moves outward along the direction).\n@param Selection  Which faces. Example: {\"Mode\":\"normal\",\"A\":{\"X\":0,\"Y\":0,\"Z\":1},\"Scalar\":10} extrudes the top faces.\n@param Direction  World-independent local direction. Leave (0,0,0) to extrude along the average face normal." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ExtrudeFaces constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExtrudeFaces constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExtrudeFaces Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventExtrudeFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventExtrudeFaces_Parms, Distance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventExtrudeFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventExtrudeFaces_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventExtrudeFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Direction,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ExtrudeFaces Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "ExtrudeFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventExtrudeFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventExtrudeFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_ExtrudeFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execExtrudeFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Direction);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::ExtrudeFaces(Z_Param_Name,Z_Param_Distance,Z_Param_Out_Selection,Z_Param_Out_Direction);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function ExtrudeFaces ********************************

// ********** Begin Class UModellingEditToolset Function GetPolygroups *****************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_GetPolygroups_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventGetPolygroups_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists the polygroups of an actor (the faces of a primitive are separate groups) with triangle count, centre, size and average normal.\n\x09 * Use the ids with selection mode \"polygroup\". At most 200 groups are returned.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists the polygroups of an actor (the faces of a primitive are separate groups) with triangle count, centre, size and average normal.\nUse the ids with selection mode \"polygroup\". At most 200 groups are returned.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPolygroups constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPolygroups constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPolygroups Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventGetPolygroups_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventGetPolygroups_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetPolygroups Property Definitions **************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "GetPolygroups", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventGetPolygroups_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventGetPolygroups_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_GetPolygroups(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execGetPolygroups)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::GetPolygroups(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function GetPolygroups *******************************

// ********** Begin Class UModellingEditToolset Function InsetFaces ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_InsetFaces_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventInsetFaces_Parms
	{
		FString Name;
		float Distance;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Insets the selected faces (shrinks each region inward, leaving a border). Often followed by ExtrudeFaces to make recesses or raised panels.\n\x09 * @param Name       Actor label.\n\x09 * @param Distance   Inset distance in cm, greater than 0.\n\x09 * @param Selection  Which faces. */" },
#endif
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Insets the selected faces (shrinks each region inward, leaving a border). Often followed by ExtrudeFaces to make recesses or raised panels.\n@param Name       Actor label.\n@param Distance   Inset distance in cm, greater than 0.\n@param Selection  Which faces." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function InsetFaces constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function InsetFaces constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function InsetFaces Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventInsetFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventInsetFaces_Parms, Distance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventInsetFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventInsetFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function InsetFaces Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "InsetFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventInsetFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventInsetFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_InsetFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execInsetFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::InsetFaces(Z_Param_Name,Z_Param_Distance,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function InsetFaces **********************************

// ********** Begin Class UModellingEditToolset Function MirrorMesh ********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_MirrorMesh_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventMirrorMesh_Parms
	{
		FString Name;
		FVector PlaneOrigin;
		FVector PlaneNormal;
		bool bCutAtPlane;
		bool bWeldSeam;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Mirrors the mesh across a plane. Ideal for symmetric models: build one half, then mirror it to make the whole.\n\x09 * The PlaneNormal points toward the half you BUILT (the half that is kept and copied). Example: you built the right half of a car on +Y,\n\x09 * so use PlaneNormal (0,1,0) and the left half is created on -Y.\n\x09 * @param Name           Actor label.\n\x09 * @param PlaneOrigin    A point on the mirror plane, local space cm.\n\x09 * @param PlaneNormal    Points toward the side you built. (1,0,0) mirrors across a YZ plane, copying the +X half to -X.\n\x09 * @param bCutAtPlane    Cut away geometry that crosses the plane before mirroring (keeps only the normal side).\n\x09 * @param bWeldSeam      Weld the vertices along the plane so the halves join. */" },
#endif
		{ "CPP_Default_bCutAtPlane", "true" },
		{ "CPP_Default_bWeldSeam", "true" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mirrors the mesh across a plane. Ideal for symmetric models: build one half, then mirror it to make the whole.\nThe PlaneNormal points toward the half you BUILT (the half that is kept and copied). Example: you built the right half of a car on +Y,\nso use PlaneNormal (0,1,0) and the left half is created on -Y.\n@param Name           Actor label.\n@param PlaneOrigin    A point on the mirror plane, local space cm.\n@param PlaneNormal    Points toward the side you built. (1,0,0) mirrors across a YZ plane, copying the +X half to -X.\n@param bCutAtPlane    Cut away geometry that crosses the plane before mirroring (keeps only the normal side).\n@param bWeldSeam      Weld the vertices along the plane so the halves join." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneOrigin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneNormal_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MirrorMesh constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneOrigin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneNormal;
	static void NewProp_bCutAtPlane_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventMirrorMesh_Parms*)Obj)->bCutAtPlane = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCutAtPlane;
	static void NewProp_bWeldSeam_SetBit(void* Obj)
	{
		((ModellingEditToolset_eventMirrorMesh_Parms*)Obj)->bWeldSeam = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWeldSeam;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MirrorMesh constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MirrorMesh Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventMirrorMesh_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaneOrigin = { "PlaneOrigin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventMirrorMesh_Parms, PlaneOrigin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneOrigin_MetaData), NewProp_PlaneOrigin_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_PlaneNormal = { "PlaneNormal", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventMirrorMesh_Parms, PlaneNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneNormal_MetaData), NewProp_PlaneNormal_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bCutAtPlane = { "bCutAtPlane", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventMirrorMesh_Parms), &UHT_STATICS::NewProp_bCutAtPlane_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bWeldSeam = { "bWeldSeam", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingEditToolset_eventMirrorMesh_Parms), &UHT_STATICS::NewProp_bWeldSeam_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventMirrorMesh_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaneOrigin,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_PlaneNormal,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bCutAtPlane,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bWeldSeam,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function MirrorMesh Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "MirrorMesh", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventMirrorMesh_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventMirrorMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_MirrorMesh(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execMirrorMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneOrigin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneNormal);
	P_GET_UBOOL(Z_Param_bCutAtPlane);
	P_GET_UBOOL(Z_Param_bWeldSeam);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::MirrorMesh(Z_Param_Name,Z_Param_Out_PlaneOrigin,Z_Param_Out_PlaneNormal,Z_Param_bCutAtPlane,Z_Param_bWeldSeam);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function MirrorMesh **********************************

// ********** Begin Class UModellingEditToolset Function OffsetFaces *******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_OffsetFaces_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventOffsetFaces_Parms
	{
		FString Name;
		float Distance;
		FModellingSelection Selection;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Moves the selected faces along their normals by a parallel offset, keeping them attached to the rest of the mesh.\n\x09 * @param Name       Actor label.\n\x09 * @param Distance   Offset in cm (negative moves inward).\n\x09 * @param Selection  Which faces. */" },
#endif
		{ "CPP_Default_Selection", "()" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moves the selected faces along their normals by a parallel offset, keeping them attached to the rest of the mesh.\n@param Name       Actor label.\n@param Distance   Offset in cm (negative moves inward).\n@param Selection  Which faces." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Selection_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OffsetFaces constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Selection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OffsetFaces constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OffsetFaces Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventOffsetFaces_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventOffsetFaces_Parms, Distance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Selection = { "Selection", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventOffsetFaces_Parms, Selection), Z_Construct_UScriptStruct_FModellingSelection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Selection_MetaData), NewProp_Selection_MetaData) }; // 1045dc4ff40935f88a7738ed3901fe325eb4f579
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventOffsetFaces_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Selection,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function OffsetFaces Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "OffsetFaces", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventOffsetFaces_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventOffsetFaces_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_OffsetFaces(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execOffsetFaces)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
	P_GET_STRUCT_REF(FModellingSelection,Z_Param_Out_Selection);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::OffsetFaces(Z_Param_Name,Z_Param_Distance,Z_Param_Out_Selection);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function OffsetFaces *********************************

// ********** Begin Class UModellingEditToolset Function SetPivot **********************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_SetPivot_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventSetPivot_Parms
	{
		FString Name;
		FString Pivot;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Moves the actor's pivot to a point on the mesh bounds without moving the geometry in the world.\n\x09 * @param Name   Actor label.\n\x09 * @param Pivot  \"center\" (bounds centre), \"base\" (bottom centre) or \"top\" (top centre). */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Moves the actor's pivot to a point on the mesh bounds without moving the geometry in the world.\n@param Name   Actor label.\n@param Pivot  \"center\" (bounds centre), \"base\" (bottom centre) or \"top\" (top centre)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pivot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPivot constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Pivot;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPivot constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPivot Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventSetPivot_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Pivot = { "Pivot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventSetPivot_Parms, Pivot), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pivot_MetaData), NewProp_Pivot_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventSetPivot_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Pivot,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetPivot Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "SetPivot", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventSetPivot_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventSetPivot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_SetPivot(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execSetPivot)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Pivot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::SetPivot(Z_Param_Name,Z_Param_Pivot);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function SetPivot ************************************

// ********** Begin Class UModellingEditToolset Function TransformGeometry *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingEditToolset_TransformGeometry_Statics
struct UHT_STATICS
{
	struct ModellingEditToolset_eventTransformGeometry_Parms
	{
		FString Name;
		FVector Translation;
		FRotator Rotation;
		FVector Scale;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Edit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Bakes a transform into the vertices (the actor transform is unchanged). Use it to offset, rotate or scale the geometry inside the actor.\n\x09 * @param Name         Actor label.\n\x09 * @param Translation  Local translation, cm.\n\x09 * @param Rotation     Rotation in degrees about the actor origin.\n\x09 * @param Scale        Scale about the actor origin. (1,1,1) keeps the size. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bakes a transform into the vertices (the actor transform is unchanged). Use it to offset, rotate or scale the geometry inside the actor.\n@param Name         Actor label.\n@param Translation  Local translation, cm.\n@param Rotation     Rotation in degrees about the actor origin.\n@param Scale        Scale about the actor origin. (1,1,1) keeps the size." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Translation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function TransformGeometry constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Translation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TransformGeometry constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TransformGeometry Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventTransformGeometry_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Translation = { "Translation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventTransformGeometry_Parms, Translation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Translation_MetaData), NewProp_Translation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventTransformGeometry_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventTransformGeometry_Parms, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingEditToolset_eventTransformGeometry_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Translation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function TransformGeometry Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingEditToolset, nullptr, "TransformGeometry", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingEditToolset_eventTransformGeometry_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingEditToolset_eventTransformGeometry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingEditToolset_TransformGeometry(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingEditToolset::execTransformGeometry)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Translation);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingEditToolset::TransformGeometry(Z_Param_Name,Z_Param_Out_Translation,Z_Param_Out_Rotation,Z_Param_Out_Scale);
	P_NATIVE_END;
}
// ********** End Class UModellingEditToolset Function TransformGeometry ***************************

// ********** Begin Class UModellingEditToolset ****************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingEditToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Mesh editing: face operations, booleans, mirroring, arrays, merging, pivots. Built on Geometry Script.\n * Every tool works on an actor created by this toolset, records undo, and returns the actor's updated JSON summary.\n * Positions and directions are in the actor's LOCAL space (cm) unless a tool says otherwise.\n *\n * Tip: call SaveCheckpoint before risky edits (booleans) so RestoreCheckpoint can undo them, and CaptureViews afterwards to check the result.\n */" },
#endif
		{ "IncludePath", "ModellingEditToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingEditToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Mesh editing: face operations, booleans, mirroring, arrays, merging, pivots. Built on Geometry Script.\nEvery tool works on an actor created by this toolset, records undo, and returns the actor's updated JSON summary.\nPositions and directions are in the actor's LOCAL space (cm) unless a tool says otherwise.\n\nTip: call SaveCheckpoint before risky edits (booleans) so RestoreCheckpoint can undo them, and CaptureViews afterwards to check the result." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingEditToolset constinit property declarations ********************
// ********** End Class UModellingEditToolset constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ArrayCopies"), .Pointer = &UModellingEditToolset::execArrayCopies },
		{ .NameUTF8 = UTF8TEXT("BevelEdges"), .Pointer = &UModellingEditToolset::execBevelEdges },
		{ .NameUTF8 = UTF8TEXT("BooleanOp"), .Pointer = &UModellingEditToolset::execBooleanOp },
		{ .NameUTF8 = UTF8TEXT("CombineActors"), .Pointer = &UModellingEditToolset::execCombineActors },
		{ .NameUTF8 = UTF8TEXT("CutWithPlane"), .Pointer = &UModellingEditToolset::execCutWithPlane },
		{ .NameUTF8 = UTF8TEXT("DeleteFaces"), .Pointer = &UModellingEditToolset::execDeleteFaces },
		{ .NameUTF8 = UTF8TEXT("ExtrudeFaces"), .Pointer = &UModellingEditToolset::execExtrudeFaces },
		{ .NameUTF8 = UTF8TEXT("GetPolygroups"), .Pointer = &UModellingEditToolset::execGetPolygroups },
		{ .NameUTF8 = UTF8TEXT("InsetFaces"), .Pointer = &UModellingEditToolset::execInsetFaces },
		{ .NameUTF8 = UTF8TEXT("MirrorMesh"), .Pointer = &UModellingEditToolset::execMirrorMesh },
		{ .NameUTF8 = UTF8TEXT("OffsetFaces"), .Pointer = &UModellingEditToolset::execOffsetFaces },
		{ .NameUTF8 = UTF8TEXT("SetPivot"), .Pointer = &UModellingEditToolset::execSetPivot },
		{ .NameUTF8 = UTF8TEXT("TransformGeometry"), .Pointer = &UModellingEditToolset::execTransformGeometry },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingEditToolset_ArrayCopies, "ArrayCopies" }, // 6791b327563e3b50dc534d2b66d6e032cc076f5e
		{ &Z_Construct_UFunction_UModellingEditToolset_BevelEdges, "BevelEdges" }, // 26f47156809b904837e2c83ab2a708421cc4f5b7
		{ &Z_Construct_UFunction_UModellingEditToolset_BooleanOp, "BooleanOp" }, // 34231c6ba79507f052505149919af1a9781967f4
		{ &Z_Construct_UFunction_UModellingEditToolset_CombineActors, "CombineActors" }, // 3b75fcc7b89b4d4e6221740cecc5a2d97981ee08
		{ &Z_Construct_UFunction_UModellingEditToolset_CutWithPlane, "CutWithPlane" }, // 728a89b23c538f6fb64ac0b0362aac541a9e2a63
		{ &Z_Construct_UFunction_UModellingEditToolset_DeleteFaces, "DeleteFaces" }, // 3d38a671dc7c953e5229af44d8e0db81fa7d1901
		{ &Z_Construct_UFunction_UModellingEditToolset_ExtrudeFaces, "ExtrudeFaces" }, // f669feec2bf898dd887c05c335d68a5670e8aaf6
		{ &Z_Construct_UFunction_UModellingEditToolset_GetPolygroups, "GetPolygroups" }, // 0319a1cfd3c93d71ea4ce3451a23564d63b5e8b2
		{ &Z_Construct_UFunction_UModellingEditToolset_InsetFaces, "InsetFaces" }, // 69363a2d0125579edecc9a07338f2bf2b7689d29
		{ &Z_Construct_UFunction_UModellingEditToolset_MirrorMesh, "MirrorMesh" }, // f37743160f5a42365c91fe8361b9fb86a6371369
		{ &Z_Construct_UFunction_UModellingEditToolset_OffsetFaces, "OffsetFaces" }, // ac62748fa69afff8022e6dc3ae6b67123ea31de4
		{ &Z_Construct_UFunction_UModellingEditToolset_SetPivot, "SetPivot" }, // d1cb30edf2cd7c9fda9ac367d580b63ef2c41de4
		{ &Z_Construct_UFunction_UModellingEditToolset_TransformGeometry, "TransformGeometry" }, // b8dbf7a6407d2642514a8db83835948596224b53
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingEditToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingEditToolset,
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
static void UModellingEditToolset_StaticRegisterNativesUModellingEditToolset()
{
	UClass* Class = UModellingEditToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingEditToolset;
UClass* Z_Construct_UClass_UModellingEditToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingEditToolset;
		if (!Z_Registration_Info_UClass_UModellingEditToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingEditToolset"),
				Z_Registration_Info_UClass_UModellingEditToolset.InnerSingleton,
				UModellingEditToolset_StaticRegisterNativesUModellingEditToolset,
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
		return Z_Registration_Info_UClass_UModellingEditToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingEditToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingEditToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingEditToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingEditToolset::UModellingEditToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingEditToolset);
UModellingEditToolset::~UModellingEditToolset() {}
// ********** End Class UModellingEditToolset ******************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingEditToolset, TEXT("UModellingEditToolset"), &Z_Registration_Info_UClass_UModellingEditToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingEditToolset), 953481915U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h__Script_ModellingToolset_6e7100fc9c6c82b911df532972e8b88166fb32f2{
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
