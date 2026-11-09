// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingVisionToolset.h"

#ifdef MODELLINGTOOLSET_ModellingVisionToolset_generated_h
#error "ModellingVisionToolset.generated.h already included, missing '#pragma once' in ModellingVisionToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingVisionToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingCapture;
struct FModellingComparison;
struct FToolsetImage;

// ********** Begin ScriptStruct FModellingCapture *************************************************
struct Z_Construct_UScriptStruct_FModellingCapture_Statics;
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_15_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModellingCapture_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FModellingCapture(ETypeConstructPhase::Inner); }


struct FModellingCapture;
// ********** End ScriptStruct FModellingCapture ***************************************************

// ********** Begin ScriptStruct FModellingComparison **********************************************
struct Z_Construct_UScriptStruct_FModellingComparison_Statics;
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingComparison(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_30_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FModellingComparison_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FModellingComparison(ETypeConstructPhase::Inner); }


struct FModellingComparison;
// ********** End ScriptStruct FModellingComparison ************************************************

// ********** Begin Class UModellingVisionToolset **************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetProgressImage); \
	DECLARE_FUNCTION(execListProgressImages); \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execCompareToReference); \
	DECLARE_FUNCTION(execCaptureViews);


struct Z_Construct_UClass_UModellingVisionToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingVisionToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingVisionToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingVisionToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingVisionToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingVisionToolset) \
	DECLARE_SERIALIZER(UModellingVisionToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingVisionToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingVisionToolset(UModellingVisionToolset&&) = delete; \
	UModellingVisionToolset(const UModellingVisionToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingVisionToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingVisionToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingVisionToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingVisionToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_51_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h_54_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingVisionToolset;

// ********** End Class UModellingVisionToolset ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingVisionToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
