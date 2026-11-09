// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingDeformToolset.h"

#ifdef MODELLINGTOOLSET_ModellingDeformToolset_generated_h
#error "ModellingDeformToolset.generated.h already included, missing '#pragma once' in ModellingDeformToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingDeformToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingSelection;

// ********** Begin Class UModellingDeformToolset **************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSubdivide); \
	DECLARE_FUNCTION(execSmooth); \
	DECLARE_FUNCTION(execNoise); \
	DECLARE_FUNCTION(execFlare); \
	DECLARE_FUNCTION(execTwist); \
	DECLARE_FUNCTION(execBend);


struct Z_Construct_UClass_UModellingDeformToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingDeformToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingDeformToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingDeformToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingDeformToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingDeformToolset) \
	DECLARE_SERIALIZER(UModellingDeformToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingDeformToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingDeformToolset(UModellingDeformToolset&&) = delete; \
	UModellingDeformToolset(const UModellingDeformToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingDeformToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingDeformToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingDeformToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingDeformToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_17_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingDeformToolset;

// ********** End Class UModellingDeformToolset ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingDeformToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
