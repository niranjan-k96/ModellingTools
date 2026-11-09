// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeModellingToolset_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ModellingToolset;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase)
	{
		if (!Z_Registration_Info_UPackage__Script_ModellingToolset.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ModellingToolset",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0xB5E74CDC,
			0x763FF264,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ModellingToolset.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ModellingToolset.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ModellingToolset(Z_Construct_UPackage__Script_ModellingToolset, TEXT("/Script/ModellingToolset"), Z_Registration_Info_UPackage__Script_ModellingToolset, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB5E74CDC, 0x763FF264));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
