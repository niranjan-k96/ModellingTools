// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingTopologyToolset.h"

#ifdef MODELLINGTOOLSET_ModellingTopologyToolset_generated_h
#error "ModellingTopologyToolset.generated.h already included, missing '#pragma once' in ModellingTopologyToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingTopologyToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UModellingTopologyToolset ************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCompactMesh); \
	DECLARE_FUNCTION(execRepairDegenerate); \
	DECLARE_FUNCTION(execFlipNormals); \
	DECLARE_FUNCTION(execRecomputeNormals); \
	DECLARE_FUNCTION(execMergeOverlaps); \
	DECLARE_FUNCTION(execRemoveHiddenFaces); \
	DECLARE_FUNCTION(execWeldEdges); \
	DECLARE_FUNCTION(execRemoveSmallParts); \
	DECLARE_FUNCTION(execFillHoles); \
	DECLARE_FUNCTION(execSimplify); \
	DECLARE_FUNCTION(execUniformRemesh);


struct Z_Construct_UClass_UModellingTopologyToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTopologyToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingTopologyToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingTopologyToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingTopologyToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingTopologyToolset) \
	DECLARE_SERIALIZER(UModellingTopologyToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingTopologyToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingTopologyToolset(UModellingTopologyToolset&&) = delete; \
	UModellingTopologyToolset(const UModellingTopologyToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingTopologyToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingTopologyToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingTopologyToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingTopologyToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_15_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingTopologyToolset;

// ********** End Class UModellingTopologyToolset **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTopologyToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
