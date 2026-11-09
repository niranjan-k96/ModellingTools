// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingToolsetSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingToolsetSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingToolsetSettings(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingToolsetSettings(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingToolsetSettings ************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingToolsetSettings_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Project settings for the Modelling Toolset (Project Settings > Plugins > Modelling Toolset). */" },
#endif
		{ "IncludePath", "ModellingToolsetSettings.h" },
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Project settings for the Modelling Toolset (Project Settings > Plugins > Modelling Toolset)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReferencesFolder_MetaData[] = {
		{ "Category", "Folders" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Folder the user drops reference images (and optional same-name .txt notes) into. Relative paths resolve against the project directory. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Folder the user drops reference images (and optional same-name .txt notes) into. Relative paths resolve against the project directory." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgressFolder_MetaData[] = {
		{ "Category", "Folders" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Folder progress screenshots are written to, one sub-folder per session. Defaults to Saved/ so it stays out of source control.\n\x09 * Relative paths resolve against the project directory. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Folder progress screenshots are written to, one sub-folder per session. Defaults to Saved/ so it stays out of source control.\nRelative paths resolve against the project directory." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExportsFolder_MetaData[] = {
		{ "Category", "Folders" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Folder exported FBX files are written to. Relative paths resolve against the project directory. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Folder exported FBX files are written to. Relative paths resolve against the project directory." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TexturesFolder_MetaData[] = {
		{ "Category", "Folders" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Folder the user drops texture images into, named by set: Brick_albedo.png, Brick_normal.png, Brick_roughness.png, Brick_metallic.png. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Folder the user drops texture images into, named by set: Brick_albedo.png, Brick_normal.png, Brick_roughness.png, Brick_metallic.png." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialLibraryFolder_MetaData[] = {
		{ "Category", "Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Content folder holding ready-made materials the AI may use, e.g. /Game/Materials. Searched recursively. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Content folder holding ready-made materials the AI may use, e.g. /Game/Materials. Searched recursively." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTileCm_MetaData[] = {
		{ "Category", "Materials" },
		{ "ClampMax", "10000" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default size of one texture tile in centimetres when a texture set does not say (tile_cm in its notes file). */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default size of one texture tile in centimetres when a texture set does not say (tile_cm in its notes file)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceLibraryFolders_MetaData[] = {
		{ "Category", "Materials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Content folders holding surface libraries (one folder per surface with _B, _N and _ORM textures), such as Fab or Megascans downloads. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Content folders holding surface libraries (one folder per surface with _B, _N and _ORM textures), such as Fab or Megascans downloads." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultSurfaceTileCm_MetaData[] = {
		{ "Category", "Materials" },
		{ "ClampMax", "10000" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default real-world size of one tile for library surfaces, in centimetres. Megascans surfaces are usually 2 metres. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default real-world size of one tile for library surfaces, in centimetres. Megascans surfaces are usually 2 metres." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCaptureResolution_MetaData[] = {
		{ "Category", "Capture" },
		{ "ClampMax", "2048" },
		{ "ClampMin", "128" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Default size in pixels of one capture tile. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default size in pixels of one capture tile." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxReturnedImageDimension_MetaData[] = {
		{ "Category", "Capture" },
		{ "ClampMax", "4096" },
		{ "ClampMin", "512" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The contact sheet returned to the AI is downscaled so neither side exceeds this. Individual view files are always saved at full tile size. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The contact sheet returned to the AI is downscaled so neither side exceeds this. Individual view files are always saved at full tile size." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureExposure_MetaData[] = {
		{ "Category", "Capture" },
		{ "ClampMax", "15" },
		{ "ClampMin", "-5" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Exposure for captures, in stops. Captures use their own fixed lights, so this is the only brightness control. Higher is brighter. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposure for captures, in stops. Captures use their own fixed lights, so this is the only brightness control. Higher is brighter." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxCheckpoints_MetaData[] = {
		{ "Category", "Checkpoints" },
		{ "ClampMax", "100" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of mesh checkpoints kept in memory. The oldest is dropped first. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingToolsetSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of mesh checkpoints kept in memory. The oldest is dropped first." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingToolsetSettings constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReferencesFolder;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProgressFolder;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExportsFolder;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TexturesFolder;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MaterialLibraryFolder;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultTileCm;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SurfaceLibraryFolders_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SurfaceLibraryFolders;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultSurfaceTileCm;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultCaptureResolution;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxReturnedImageDimension;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CaptureExposure;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxCheckpoints;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UModellingToolsetSettings constinit property declarations ******************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingToolsetSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class UModellingToolsetSettings Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReferencesFolder = { "ReferencesFolder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, ReferencesFolder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReferencesFolder_MetaData), NewProp_ReferencesFolder_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ProgressFolder = { "ProgressFolder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, ProgressFolder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgressFolder_MetaData), NewProp_ProgressFolder_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ExportsFolder = { "ExportsFolder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, ExportsFolder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExportsFolder_MetaData), NewProp_ExportsFolder_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_TexturesFolder = { "TexturesFolder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, TexturesFolder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TexturesFolder_MetaData), NewProp_TexturesFolder_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_MaterialLibraryFolder = { "MaterialLibraryFolder", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, MaterialLibraryFolder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialLibraryFolder_MetaData), NewProp_MaterialLibraryFolder_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefaultTileCm = { "DefaultTileCm", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, DefaultTileCm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTileCm_MetaData), NewProp_DefaultTileCm_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_SurfaceLibraryFolders_Inner = { "SurfaceLibraryFolders", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams UHT_STATICS::NewProp_SurfaceLibraryFolders = { "SurfaceLibraryFolders", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, SurfaceLibraryFolders), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceLibraryFolders_MetaData), NewProp_SurfaceLibraryFolders_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DefaultSurfaceTileCm = { "DefaultSurfaceTileCm", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, DefaultSurfaceTileCm), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultSurfaceTileCm_MetaData), NewProp_DefaultSurfaceTileCm_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_DefaultCaptureResolution = { "DefaultCaptureResolution", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, DefaultCaptureResolution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultCaptureResolution_MetaData), NewProp_DefaultCaptureResolution_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxReturnedImageDimension = { "MaxReturnedImageDimension", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, MaxReturnedImageDimension), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxReturnedImageDimension_MetaData), NewProp_MaxReturnedImageDimension_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_CaptureExposure = { "CaptureExposure", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, CaptureExposure), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureExposure_MetaData), NewProp_CaptureExposure_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxCheckpoints = { "MaxCheckpoints", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(UModellingToolsetSettings, MaxCheckpoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxCheckpoints_MetaData), NewProp_MaxCheckpoints_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReferencesFolder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ProgressFolder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ExportsFolder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_TexturesFolder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaterialLibraryFolder,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultTileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceLibraryFolders_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SurfaceLibraryFolders,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultSurfaceTileCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DefaultCaptureResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxReturnedImageDimension,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_CaptureExposure,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxCheckpoints,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class UModellingToolsetSettings Property Definitions *****************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UDeveloperSettings,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingToolsetSettings,
	"ModellingToolset",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x000800A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingToolsetSettings;
UClass* Z_Construct_UClass_UModellingToolsetSettings(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingToolsetSettings;
		if (!Z_Registration_Info_UClass_UModellingToolsetSettings.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingToolsetSettings"),
				Z_Registration_Info_UClass_UModellingToolsetSettings.InnerSingleton,
				nullptr,
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
		return Z_Registration_Info_UClass_UModellingToolsetSettings.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingToolsetSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingToolsetSettings.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingToolsetSettings.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingToolsetSettings);
UModellingToolsetSettings::~UModellingToolsetSettings() {}
// ********** End Class UModellingToolsetSettings **************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingToolsetSettings_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingToolsetSettings, TEXT("UModellingToolsetSettings"), &Z_Registration_Info_UClass_UModellingToolsetSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingToolsetSettings), 536901157U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingToolsetSettings_h__Script_ModellingToolset_d33beec1f1c30664b66c86eb55134891d06fe34a{
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
