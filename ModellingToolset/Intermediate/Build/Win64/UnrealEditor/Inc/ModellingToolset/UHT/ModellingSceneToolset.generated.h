// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingSceneToolset.h"

#ifdef MODELLINGTOOLSET_ModellingSceneToolset_generated_h
#error "ModellingSceneToolset.generated.h already included, missing '#pragma once' in ModellingSceneToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingSceneToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UModellingSceneToolset ***************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execListCheckpoints); \
	DECLARE_FUNCTION(execRevertLastEdit); \
	DECLARE_FUNCTION(execRestoreCheckpoint); \
	DECLARE_FUNCTION(execSaveCheckpoint); \
	DECLARE_FUNCTION(execDeleteAllModelActors); \
	DECLARE_FUNCTION(execDeleteActor); \
	DECLARE_FUNCTION(execSetActorTransform); \
	DECLARE_FUNCTION(execGetMeshInfo); \
	DECLARE_FUNCTION(execListMeshActors); \
	DECLARE_FUNCTION(execCreateMeshActor); \
	DECLARE_FUNCTION(execGetWorkspaceInfo);


struct Z_Construct_UClass_UModellingSceneToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSceneToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingSceneToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingSceneToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingSceneToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingSceneToolset) \
	DECLARE_SERIALIZER(UModellingSceneToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingSceneToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingSceneToolset(UModellingSceneToolset&&) = delete; \
	UModellingSceneToolset(const UModellingSceneToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingSceneToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingSceneToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingSceneToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingSceneToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_16_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingSceneToolset;

// ********** End Class UModellingSceneToolset *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSceneToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
