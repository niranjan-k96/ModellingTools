// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingReferenceToolset.h"

#ifdef MODELLINGTOOLSET_ModellingReferenceToolset_generated_h
#error "ModellingReferenceToolset.generated.h already included, missing '#pragma once' in ModellingReferenceToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingReferenceToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingReference;

// ********** Begin ScriptStruct FModellingReference ***********************************************
struct Z_Construct_UScriptStruct_FModellingReference_Statics;
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingReference(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_15_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModellingReference_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FModellingReference(ETypeConstructPhase::Inner); }


struct FModellingReference;
// ********** End ScriptStruct FModellingReference *************************************************

// ********** Begin Class UModellingReferenceToolset ***********************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetReference); \
	DECLARE_FUNCTION(execListReferences);


struct Z_Construct_UClass_UModellingReferenceToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingReferenceToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingReferenceToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingReferenceToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingReferenceToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingReferenceToolset) \
	DECLARE_SERIALIZER(UModellingReferenceToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingReferenceToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingReferenceToolset(UModellingReferenceToolset&&) = delete; \
	UModellingReferenceToolset(const UModellingReferenceToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingReferenceToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingReferenceToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingReferenceToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingReferenceToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_41_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingReferenceToolset;

// ********** End Class UModellingReferenceToolset *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
