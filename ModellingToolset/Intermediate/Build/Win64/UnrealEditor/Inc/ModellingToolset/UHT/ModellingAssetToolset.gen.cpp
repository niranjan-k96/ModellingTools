// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingAssetToolset.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingAssetToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingAssetToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingAssetToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingAssetToolset Function ImportStaticMesh *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingAssetToolset_ImportStaticMesh_Statics
struct UHT_STATICS
{
	struct ModellingAssetToolset_eventImportStaticMesh_Parms
	{
		FString AssetPath;
		FString Name;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Asset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Loads an existing StaticMesh asset into a new editable model actor, so saved or imported meshes can be modified further.\n\x09 * Materials from the asset are applied to the actor.\n\x09 * @param AssetPath  Content path of the StaticMesh, e.g. \"/Game/Models/Lighthouse\" or \"/Engine/BasicShapes/Cube\".\n\x09 * @param Name       Label for the new actor.\n\x09 * @return JSON description of the new actor. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Loads an existing StaticMesh asset into a new editable model actor, so saved or imported meshes can be modified further.\nMaterials from the asset are applied to the actor.\n@param AssetPath  Content path of the StaticMesh, e.g. \"/Game/Models/Lighthouse\" or \"/Engine/BasicShapes/Cube\".\n@param Name       Label for the new actor.\n@return JSON description of the new actor." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ImportStaticMesh constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ImportStaticMesh constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ImportStaticMesh Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventImportStaticMesh_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventImportStaticMesh_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventImportStaticMesh_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ImportStaticMesh Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingAssetToolset, nullptr, "ImportStaticMesh", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingAssetToolset_eventImportStaticMesh_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingAssetToolset_eventImportStaticMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingAssetToolset_ImportStaticMesh(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingAssetToolset::execImportStaticMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingAssetToolset::ImportStaticMesh(Z_Param_AssetPath,Z_Param_Name);
	P_NATIVE_END;
}
// ********** End Class UModellingAssetToolset Function ImportStaticMesh ***************************

// ********** Begin Class UModellingAssetToolset Function SaveToStaticMesh *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingAssetToolset_SaveToStaticMesh_Statics
struct UHT_STATICS
{
	struct ModellingAssetToolset_eventSaveToStaticMesh_Parms
	{
		FString Name;
		FString AssetPath;
		bool bOverwrite;
		FString Collision;
		bool bEnableNanite;
		bool bPlaceInLevel;
		bool bDeleteSourceActor;
		bool bSaveToDisk;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Asset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Saves a model actor's geometry as a StaticMesh asset. The asset pivot is the actor's origin, so call SetPivot first if\n\x09 * the model should sit on a different point (for example \"base\" for something that stands on the ground).\n\x09 * Materials assigned to the actor are copied to the asset's slots.\n\x09 *\n\x09 * @param Name                  Actor label of the model to save.\n\x09 * @param AssetPath             Content path, e.g. \"/Game/Models/Lighthouse\". The last segment is the asset name.\n\x09 * @param bOverwrite            Replace the asset if it already exists. If false and it exists, the call fails.\n\x09 * @param Collision             \"none\", \"auto\" (best-fit simple shapes), \"box\", \"convex\" (single convex hull) or \"complex\" (use the render mesh as collision).\n\x09 * @param bEnableNanite         Enable Nanite on the asset. Best for high-triangle models; leave off for simple props.\n\x09 * @param bPlaceInLevel         Also place a StaticMeshActor using the asset at the model's transform.\n\x09 * @param bDeleteSourceActor    With bPlaceInLevel, delete the dynamic mesh actor afterwards so the level shows only the saved asset.\n\x09 * @param bSaveToDisk           Write the .uasset to disk. If false, the asset exists only in memory until saved from the editor.\n\x09 * @return JSON: asset_path, whether it was created or overwritten, triangle count, collision and Nanite settings, placed actor name. */" },
#endif
		{ "CPP_Default_bDeleteSourceActor", "false" },
		{ "CPP_Default_bEnableNanite", "false" },
		{ "CPP_Default_bOverwrite", "false" },
		{ "CPP_Default_bPlaceInLevel", "false" },
		{ "CPP_Default_bSaveToDisk", "true" },
		{ "CPP_Default_Collision", "auto" },
		{ "ModuleRelativePath", "Public/ModellingAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Saves a model actor's geometry as a StaticMesh asset. The asset pivot is the actor's origin, so call SetPivot first if\nthe model should sit on a different point (for example \"base\" for something that stands on the ground).\nMaterials assigned to the actor are copied to the asset's slots.\n\n@param Name                  Actor label of the model to save.\n@param AssetPath             Content path, e.g. \"/Game/Models/Lighthouse\". The last segment is the asset name.\n@param bOverwrite            Replace the asset if it already exists. If false and it exists, the call fails.\n@param Collision             \"none\", \"auto\" (best-fit simple shapes), \"box\", \"convex\" (single convex hull) or \"complex\" (use the render mesh as collision).\n@param bEnableNanite         Enable Nanite on the asset. Best for high-triangle models; leave off for simple props.\n@param bPlaceInLevel         Also place a StaticMeshActor using the asset at the model's transform.\n@param bDeleteSourceActor    With bPlaceInLevel, delete the dynamic mesh actor afterwards so the level shows only the saved asset.\n@param bSaveToDisk           Write the .uasset to disk. If false, the asset exists only in memory until saved from the editor.\n@return JSON: asset_path, whether it was created or overwritten, triangle count, collision and Nanite settings, placed actor name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetPath_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collision_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveToStaticMesh constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetPath;
	static void NewProp_bOverwrite_SetBit(void* Obj)
	{
		((ModellingAssetToolset_eventSaveToStaticMesh_Parms*)Obj)->bOverwrite = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverwrite;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Collision;
	static void NewProp_bEnableNanite_SetBit(void* Obj)
	{
		((ModellingAssetToolset_eventSaveToStaticMesh_Parms*)Obj)->bEnableNanite = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableNanite;
	static void NewProp_bPlaceInLevel_SetBit(void* Obj)
	{
		((ModellingAssetToolset_eventSaveToStaticMesh_Parms*)Obj)->bPlaceInLevel = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlaceInLevel;
	static void NewProp_bDeleteSourceActor_SetBit(void* Obj)
	{
		((ModellingAssetToolset_eventSaveToStaticMesh_Parms*)Obj)->bDeleteSourceActor = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDeleteSourceActor;
	static void NewProp_bSaveToDisk_SetBit(void* Obj)
	{
		((ModellingAssetToolset_eventSaveToStaticMesh_Parms*)Obj)->bSaveToDisk = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveToDisk;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveToStaticMesh constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveToStaticMesh Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventSaveToStaticMesh_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_AssetPath = { "AssetPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventSaveToStaticMesh_Parms, AssetPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetPath_MetaData), NewProp_AssetPath_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bOverwrite = { "bOverwrite", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingAssetToolset_eventSaveToStaticMesh_Parms), &UHT_STATICS::NewProp_bOverwrite_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Collision = { "Collision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventSaveToStaticMesh_Parms, Collision), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collision_MetaData), NewProp_Collision_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bEnableNanite = { "bEnableNanite", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingAssetToolset_eventSaveToStaticMesh_Parms), &UHT_STATICS::NewProp_bEnableNanite_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bPlaceInLevel = { "bPlaceInLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingAssetToolset_eventSaveToStaticMesh_Parms), &UHT_STATICS::NewProp_bPlaceInLevel_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bDeleteSourceActor = { "bDeleteSourceActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingAssetToolset_eventSaveToStaticMesh_Parms), &UHT_STATICS::NewProp_bDeleteSourceActor_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_bSaveToDisk = { "bSaveToDisk", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ModellingAssetToolset_eventSaveToStaticMesh_Parms), &UHT_STATICS::NewProp_bSaveToDisk_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingAssetToolset_eventSaveToStaticMesh_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_AssetPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bOverwrite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Collision,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bEnableNanite,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bPlaceInLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bDeleteSourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_bSaveToDisk,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function SaveToStaticMesh Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingAssetToolset, nullptr, "SaveToStaticMesh", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingAssetToolset_eventSaveToStaticMesh_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingAssetToolset_eventSaveToStaticMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingAssetToolset_SaveToStaticMesh(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingAssetToolset::execSaveToStaticMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FStrProperty,Z_Param_AssetPath);
	P_GET_UBOOL(Z_Param_bOverwrite);
	P_GET_PROPERTY(FStrProperty,Z_Param_Collision);
	P_GET_UBOOL(Z_Param_bEnableNanite);
	P_GET_UBOOL(Z_Param_bPlaceInLevel);
	P_GET_UBOOL(Z_Param_bDeleteSourceActor);
	P_GET_UBOOL(Z_Param_bSaveToDisk);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingAssetToolset::SaveToStaticMesh(Z_Param_Name,Z_Param_AssetPath,Z_Param_bOverwrite,Z_Param_Collision,Z_Param_bEnableNanite,Z_Param_bPlaceInLevel,Z_Param_bDeleteSourceActor,Z_Param_bSaveToDisk);
	P_NATIVE_END;
}
// ********** End Class UModellingAssetToolset Function SaveToStaticMesh ***************************

// ********** Begin Class UModellingAssetToolset ***************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingAssetToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Turns models into real, reusable assets. Dynamic mesh actors live only in the level; saving them to a\n * StaticMesh asset makes the model persistent, instanceable, and usable in Blueprints, packaged builds and other levels.\n * Asset paths must be under /Game/.\n */" },
#endif
		{ "IncludePath", "ModellingAssetToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingAssetToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Turns models into real, reusable assets. Dynamic mesh actors live only in the level; saving them to a\nStaticMesh asset makes the model persistent, instanceable, and usable in Blueprints, packaged builds and other levels.\nAsset paths must be under /Game/." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingAssetToolset constinit property declarations *******************
// ********** End Class UModellingAssetToolset constinit property declarations *********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ImportStaticMesh"), .Pointer = &UModellingAssetToolset::execImportStaticMesh },
		{ .NameUTF8 = UTF8TEXT("SaveToStaticMesh"), .Pointer = &UModellingAssetToolset::execSaveToStaticMesh },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingAssetToolset_ImportStaticMesh, "ImportStaticMesh" }, // 375f3f327184a73b921f0f5c8fb803bd4dae841f
		{ &Z_Construct_UFunction_UModellingAssetToolset_SaveToStaticMesh, "SaveToStaticMesh" }, // 78e225c6b1f9d61dca6272f58e3ee6aa8dd110e0
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingAssetToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingAssetToolset,
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
static void UModellingAssetToolset_StaticRegisterNativesUModellingAssetToolset()
{
	UClass* Class = UModellingAssetToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingAssetToolset;
UClass* Z_Construct_UClass_UModellingAssetToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingAssetToolset;
		if (!Z_Registration_Info_UClass_UModellingAssetToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingAssetToolset"),
				Z_Registration_Info_UClass_UModellingAssetToolset.InnerSingleton,
				UModellingAssetToolset_StaticRegisterNativesUModellingAssetToolset,
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
		return Z_Registration_Info_UClass_UModellingAssetToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingAssetToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingAssetToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingAssetToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingAssetToolset::UModellingAssetToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingAssetToolset);
UModellingAssetToolset::~UModellingAssetToolset() {}
// ********** End Class UModellingAssetToolset *****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingAssetToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingAssetToolset, TEXT("UModellingAssetToolset"), &Z_Registration_Info_UClass_UModellingAssetToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingAssetToolset), 3695109726U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingAssetToolset_h__Script_ModellingToolset_8c2992c813c209117cfb3c94fb0e6e7b34028b36{
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
