// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingSkill.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingSkill() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UAgentSkill(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingWorkflowSkill(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingWorkflowSkill(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class UModellingWorkflowSkill **************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingWorkflowSkill_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Agent skill that teaches the AI the Modelling Toolset workflow: read the job, study every reference image FIRST,\n * model step by step while checking screenshots, then ask the user to review. The user either requests changes or\n * presses Done, which exports the FBX. Discovered automatically through the Agent Skill toolset (ListSkills / GetSkills).\n */" },
#endif
		{ "IncludePath", "ModellingSkill.h" },
		{ "ModuleRelativePath", "Public/ModellingSkill.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Agent skill that teaches the AI the Modelling Toolset workflow: read the job, study every reference image FIRST,\nmodel step by step while checking screenshots, then ask the user to review. The user either requests changes or\npresses Done, which exports the FBX. Discovered automatically through the Agent Skill toolset (ListSkills / GetSkills)." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingWorkflowSkill constinit property declarations ******************
// ********** End Class UModellingWorkflowSkill constinit property declarations ********************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingWorkflowSkill>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UAgentSkill,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingWorkflowSkill,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingWorkflowSkill;
UClass* Z_Construct_UClass_UModellingWorkflowSkill(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingWorkflowSkill;
		if (!Z_Registration_Info_UClass_UModellingWorkflowSkill.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingWorkflowSkill"),
				Z_Registration_Info_UClass_UModellingWorkflowSkill.InnerSingleton,
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
		return Z_Registration_Info_UClass_UModellingWorkflowSkill.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingWorkflowSkill.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingWorkflowSkill.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingWorkflowSkill.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingWorkflowSkill);
UModellingWorkflowSkill::~UModellingWorkflowSkill() {}
// ********** End Class UModellingWorkflowSkill ****************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSkill_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingWorkflowSkill, TEXT("UModellingWorkflowSkill"), &Z_Registration_Info_UClass_UModellingWorkflowSkill, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingWorkflowSkill), 4210058610U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSkill_h__Script_ModellingToolset_ef26141a68b878b8dad328a8a1db27bb18954d54{
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
