// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingSceneToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingSceneToolset() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSceneToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSceneToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingSceneToolset Function CreateMeshActor **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_CreateMeshActor_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventCreateMeshActor_Parms
	{
		FString Name;
		FVector Location;
		FRotator Rotation;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Creates an empty dynamic-mesh actor to hold a model part.\n\x09 * @param Name      Label for the actor. A numeric suffix is added if the name is taken, so read the returned \"actor\" field for the real name.\n\x09 * @param Location  World location in cm.\n\x09 * @param Rotation  World rotation in degrees (pitch, yaw, roll).\n\x09 * @return JSON description of the new actor. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates an empty dynamic-mesh actor to hold a model part.\n@param Name      Label for the actor. A numeric suffix is added if the name is taken, so read the returned \"actor\" field for the real name.\n@param Location  World location in cm.\n@param Rotation  World rotation in degrees (pitch, yaw, roll).\n@return JSON description of the new actor." },
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

// ********** Begin Function CreateMeshActor constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateMeshActor constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateMeshActor Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventCreateMeshActor_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventCreateMeshActor_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventCreateMeshActor_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventCreateMeshActor_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function CreateMeshActor Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "CreateMeshActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventCreateMeshActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventCreateMeshActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_CreateMeshActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execCreateMeshActor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::CreateMeshActor(Z_Param_Name,Z_Param_Out_Location,Z_Param_Out_Rotation);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function CreateMeshActor ****************************

// ********** Begin Class UModellingSceneToolset Function DeleteActor ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_DeleteActor_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventDeleteActor_Parms
	{
		FString Name;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deletes one actor created by this toolset.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deletes one actor created by this toolset.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteActor constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ModellingSceneToolset_eventDeleteActor_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteActor constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteActor Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventDeleteActor_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingSceneToolset_eventDeleteActor_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DeleteActor Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "DeleteActor", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventDeleteActor_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventDeleteActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_DeleteActor(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execDeleteActor)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UModellingSceneToolset::DeleteActor(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function DeleteActor ********************************

// ********** Begin Class UModellingSceneToolset Function DeleteAllModelActors *********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_DeleteAllModelActors_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventDeleteAllModelActors_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Deletes every actor this toolset created (those tagged \"ModellingToolset\"). Other level content is untouched.\n\x09 * @return Number of actors deleted. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Deletes every actor this toolset created (those tagged \"ModellingToolset\"). Other level content is untouched.\n@return Number of actors deleted." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteAllModelActors constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteAllModelActors constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteAllModelActors Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventDeleteAllModelActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function DeleteAllModelActors Property Definitions *******************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "DeleteAllModelActors", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventDeleteAllModelActors_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventDeleteAllModelActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_DeleteAllModelActors(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execDeleteAllModelActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UModellingSceneToolset::DeleteAllModelActors();
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function DeleteAllModelActors ***********************

// ********** Begin Class UModellingSceneToolset Function GetMeshInfo ******************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_GetMeshInfo_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventGetMeshInfo_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns triangle/vertex counts, location, scale and world-space size of one actor, so dimensions can be verified.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns triangle/vertex counts, location, scale and world-space size of one actor, so dimensions can be verified.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetMeshInfo constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMeshInfo constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMeshInfo Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventGetMeshInfo_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventGetMeshInfo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetMeshInfo Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "GetMeshInfo", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventGetMeshInfo_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventGetMeshInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_GetMeshInfo(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execGetMeshInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::GetMeshInfo(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function GetMeshInfo ********************************

// ********** Begin Class UModellingSceneToolset Function GetWorkspaceInfo *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_GetWorkspaceInfo_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventGetWorkspaceInfo_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the folders used by this plugin as JSON: the references folder (where the user\n\x09 * drops reference images) and the progress folder (where screenshots are saved).\n\x09 * Call this first to learn where things live. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the folders used by this plugin as JSON: the references folder (where the user\ndrops reference images) and the progress folder (where screenshots are saved).\nCall this first to learn where things live." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorkspaceInfo constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorkspaceInfo constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorkspaceInfo Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventGetWorkspaceInfo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetWorkspaceInfo Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "GetWorkspaceInfo", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventGetWorkspaceInfo_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventGetWorkspaceInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_GetWorkspaceInfo(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execGetWorkspaceInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::GetWorkspaceInfo();
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function GetWorkspaceInfo ***************************

// ********** Begin Class UModellingSceneToolset Function ListCheckpoints **************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_ListCheckpoints_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventListCheckpoints_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists saved checkpoints as a JSON array of \"actor/label\" strings.\n\x09 * @param Name  Actor label to filter by. Empty lists all. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists saved checkpoints as a JSON array of \"actor/label\" strings.\n@param Name  Actor label to filter by. Empty lists all." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ListCheckpoints constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListCheckpoints constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListCheckpoints Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventListCheckpoints_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventListCheckpoints_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListCheckpoints Property Definitions ************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "ListCheckpoints", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventListCheckpoints_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventListCheckpoints_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_ListCheckpoints(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execListCheckpoints)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::ListCheckpoints(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function ListCheckpoints ****************************

// ********** Begin Class UModellingSceneToolset Function ListMeshActors ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_ListMeshActors_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventListMeshActors_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists every dynamic-mesh actor in the level as a JSON array with triangle counts and world bounds. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists every dynamic-mesh actor in the level as a JSON array with triangle counts and world bounds." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListMeshActors constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListMeshActors constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListMeshActors Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventListMeshActors_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListMeshActors Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "ListMeshActors", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventListMeshActors_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventListMeshActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_ListMeshActors(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execListMeshActors)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::ListMeshActors();
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function ListMeshActors *****************************

// ********** Begin Class UModellingSceneToolset Function RestoreCheckpoint ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_RestoreCheckpoint_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventRestoreCheckpoint_Parms
	{
		FString Name;
		FString Label;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Restores an actor's geometry to a saved checkpoint. The actor transform is not changed.\n\x09 * @param Name   Actor label.\n\x09 * @param Label  Checkpoint name used in SaveCheckpoint. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Restores an actor's geometry to a saved checkpoint. The actor transform is not changed.\n@param Name   Actor label.\n@param Label  Checkpoint name used in SaveCheckpoint." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreCheckpoint constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreCheckpoint constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreCheckpoint Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventRestoreCheckpoint_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventRestoreCheckpoint_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventRestoreCheckpoint_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RestoreCheckpoint Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "RestoreCheckpoint", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventRestoreCheckpoint_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventRestoreCheckpoint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_RestoreCheckpoint(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execRestoreCheckpoint)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::RestoreCheckpoint(Z_Param_Name,Z_Param_Label);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function RestoreCheckpoint **************************

// ********** Begin Class UModellingSceneToolset Function RevertLastEdit ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_RevertLastEdit_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventRevertLastEdit_Parms
	{
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Undoes only the most recent edit made to a part (extrude, boolean, mirror, bend and so on), without needing a checkpoint.\n\x09 * One level only: call it right after an edit that looks wrong. Edits that remove the whole mesh are undone automatically.\n\x09 * @param Name  Actor label. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Undoes only the most recent edit made to a part (extrude, boolean, mirror, bend and so on), without needing a checkpoint.\nOne level only: call it right after an edit that looks wrong. Edits that remove the whole mesh are undone automatically.\n@param Name  Actor label." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RevertLastEdit constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RevertLastEdit constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RevertLastEdit Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventRevertLastEdit_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventRevertLastEdit_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function RevertLastEdit Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "RevertLastEdit", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventRevertLastEdit_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventRevertLastEdit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_RevertLastEdit(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execRevertLastEdit)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::RevertLastEdit(Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function RevertLastEdit *****************************

// ********** Begin Class UModellingSceneToolset Function SaveCheckpoint ***************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_SaveCheckpoint_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventSaveCheckpoint_Parms
	{
		FString Name;
		FString Label;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Saves a snapshot of an actor's geometry in memory so a risky edit (boolean, remesh, simplify) can be rolled back.\n\x09 * Saving with an existing label replaces that checkpoint. The oldest checkpoints are dropped past the project limit.\n\x09 * @param Name   Actor label.\n\x09 * @param Label  Checkpoint name, e.g. \"before_boolean\". */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Saves a snapshot of an actor's geometry in memory so a risky edit (boolean, remesh, simplify) can be rolled back.\nSaving with an existing label replaces that checkpoint. The oldest checkpoints are dropped past the project limit.\n@param Name   Actor label.\n@param Label  Checkpoint name, e.g. \"before_boolean\"." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveCheckpoint constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static void NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ModellingSceneToolset_eventSaveCheckpoint_Parms*)Obj)->ReturnValue = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveCheckpoint constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveCheckpoint Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSaveCheckpoint_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSaveCheckpoint_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingSceneToolset_eventSaveCheckpoint_Parms), &UHT_STATICS::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SaveCheckpoint Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "SaveCheckpoint", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventSaveCheckpoint_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventSaveCheckpoint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_SaveCheckpoint(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execSaveCheckpoint)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UModellingSceneToolset::SaveCheckpoint(Z_Param_Name,Z_Param_Label);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function SaveCheckpoint *****************************

// ********** Begin Class UModellingSceneToolset Function SetActorTransform ************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingSceneToolset_SetActorTransform_Statics
struct UHT_STATICS
{
	struct ModellingSceneToolset_eventSetActorTransform_Parms
	{
		FString Name;
		FVector Location;
		FRotator Rotation;
		FVector Scale;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sets the world transform of an actor created by this toolset.\n\x09 * @param Name      Actor label.\n\x09 * @param Location  World location in cm.\n\x09 * @param Rotation  World rotation in degrees.\n\x09 * @param Scale     World scale. (1,1,1) is unscaled. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the world transform of an actor created by this toolset.\n@param Name      Actor label.\n@param Location  World location in cm.\n@param Rotation  World rotation in degrees.\n@param Scale     World scale. (1,1,1) is unscaled." },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetActorTransform constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetActorTransform constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetActorTransform Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSetActorTransform_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSetActorTransform_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Location_MetaData), NewProp_Location_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSetActorTransform_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rotation_MetaData), NewProp_Rotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSetActorTransform_Parms, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingSceneToolset_eventSetActorTransform_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SetActorTransform Property Definitions **********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingSceneToolset, nullptr, "SetActorTransform", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingSceneToolset_eventSetActorTransform_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingSceneToolset_eventSetActorTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingSceneToolset_SetActorTransform(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingSceneToolset::execSetActorTransform)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingSceneToolset::SetActorTransform(Z_Param_Name,Z_Param_Out_Location,Z_Param_Out_Rotation,Z_Param_Out_Scale);
	P_NATIVE_END;
}
// ********** End Class UModellingSceneToolset Function SetActorTransform **************************

// ********** Begin Class UModellingSceneToolset ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingSceneToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Scene management for procedural models: create, list, transform, inspect, checkpoint and delete\n * dynamic-mesh actors. All distances are in centimetres, rotations in degrees.\n * Every model part is an ADynamicMeshActor identified by its actor label.\n * Only actors created by this toolset can be modified or deleted.\n */" },
#endif
		{ "IncludePath", "ModellingSceneToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingSceneToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scene management for procedural models: create, list, transform, inspect, checkpoint and delete\ndynamic-mesh actors. All distances are in centimetres, rotations in degrees.\nEvery model part is an ADynamicMeshActor identified by its actor label.\nOnly actors created by this toolset can be modified or deleted." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingSceneToolset constinit property declarations *******************
// ********** End Class UModellingSceneToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("CreateMeshActor"), .Pointer = &UModellingSceneToolset::execCreateMeshActor },
		{ .NameUTF8 = UTF8TEXT("DeleteActor"), .Pointer = &UModellingSceneToolset::execDeleteActor },
		{ .NameUTF8 = UTF8TEXT("DeleteAllModelActors"), .Pointer = &UModellingSceneToolset::execDeleteAllModelActors },
		{ .NameUTF8 = UTF8TEXT("GetMeshInfo"), .Pointer = &UModellingSceneToolset::execGetMeshInfo },
		{ .NameUTF8 = UTF8TEXT("GetWorkspaceInfo"), .Pointer = &UModellingSceneToolset::execGetWorkspaceInfo },
		{ .NameUTF8 = UTF8TEXT("ListCheckpoints"), .Pointer = &UModellingSceneToolset::execListCheckpoints },
		{ .NameUTF8 = UTF8TEXT("ListMeshActors"), .Pointer = &UModellingSceneToolset::execListMeshActors },
		{ .NameUTF8 = UTF8TEXT("RestoreCheckpoint"), .Pointer = &UModellingSceneToolset::execRestoreCheckpoint },
		{ .NameUTF8 = UTF8TEXT("RevertLastEdit"), .Pointer = &UModellingSceneToolset::execRevertLastEdit },
		{ .NameUTF8 = UTF8TEXT("SaveCheckpoint"), .Pointer = &UModellingSceneToolset::execSaveCheckpoint },
		{ .NameUTF8 = UTF8TEXT("SetActorTransform"), .Pointer = &UModellingSceneToolset::execSetActorTransform },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingSceneToolset_CreateMeshActor, "CreateMeshActor" }, // 2636e8ea52b7a8aae26af55ed96c3dadab351396
		{ &Z_Construct_UFunction_UModellingSceneToolset_DeleteActor, "DeleteActor" }, // 4c0baf41bbb4a19c9132ead3554b0ddc5a1f97e1
		{ &Z_Construct_UFunction_UModellingSceneToolset_DeleteAllModelActors, "DeleteAllModelActors" }, // 71030c3a501e88346bf8154600ab520b1b9ba8b6
		{ &Z_Construct_UFunction_UModellingSceneToolset_GetMeshInfo, "GetMeshInfo" }, // ae755c1d18bd733588bb852530453caf8d537f9d
		{ &Z_Construct_UFunction_UModellingSceneToolset_GetWorkspaceInfo, "GetWorkspaceInfo" }, // ab6e57504ac44b89d0b669a4c05688fc3981a711
		{ &Z_Construct_UFunction_UModellingSceneToolset_ListCheckpoints, "ListCheckpoints" }, // 459ce065ecc4838e714139d9b25a7559b456717e
		{ &Z_Construct_UFunction_UModellingSceneToolset_ListMeshActors, "ListMeshActors" }, // 6077996abf0fd4cd50425d8a81718f9cad8dcc1f
		{ &Z_Construct_UFunction_UModellingSceneToolset_RestoreCheckpoint, "RestoreCheckpoint" }, // bde3718fd742de67b1fc21c620d54cb20dc8ee24
		{ &Z_Construct_UFunction_UModellingSceneToolset_RevertLastEdit, "RevertLastEdit" }, // 5d222640077e455d4f4c04c707ace4975c458a9b
		{ &Z_Construct_UFunction_UModellingSceneToolset_SaveCheckpoint, "SaveCheckpoint" }, // 5082b618837fa49cfc170ffafba79e3488e6ad7c
		{ &Z_Construct_UFunction_UModellingSceneToolset_SetActorTransform, "SetActorTransform" }, // b1682c2f942e38366e1e51ad9044a6c808672618
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingSceneToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingSceneToolset,
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
static void UModellingSceneToolset_StaticRegisterNativesUModellingSceneToolset()
{
	UClass* Class = UModellingSceneToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingSceneToolset;
UClass* Z_Construct_UClass_UModellingSceneToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingSceneToolset;
		if (!Z_Registration_Info_UClass_UModellingSceneToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingSceneToolset"),
				Z_Registration_Info_UClass_UModellingSceneToolset.InnerSingleton,
				UModellingSceneToolset_StaticRegisterNativesUModellingSceneToolset,
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
		return Z_Registration_Info_UClass_UModellingSceneToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingSceneToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingSceneToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingSceneToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingSceneToolset::UModellingSceneToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingSceneToolset);
UModellingSceneToolset::~UModellingSceneToolset() {}
// ********** End Class UModellingSceneToolset *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingSceneToolset, TEXT("UModellingSceneToolset"), &Z_Registration_Info_UClass_UModellingSceneToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingSceneToolset), 3058957855U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h__Script_ModellingToolset_d6ce5588b085c2cad6085c7eb2f3a8f5acdfd03e{
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
