// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingEditToolset.h"

#ifdef MODELLINGTOOLSET_ModellingEditToolset_generated_h
#error "ModellingEditToolset.generated.h already included, missing '#pragma once' in ModellingEditToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingEditToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingSelection;

// ********** Begin Class UModellingEditToolset ****************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetPivot); \
	DECLARE_FUNCTION(execTransformGeometry); \
	DECLARE_FUNCTION(execCombineActors); \
	DECLARE_FUNCTION(execCutWithPlane); \
	DECLARE_FUNCTION(execBooleanOp); \
	DECLARE_FUNCTION(execArrayCopies); \
	DECLARE_FUNCTION(execMirrorMesh); \
	DECLARE_FUNCTION(execDeleteFaces); \
	DECLARE_FUNCTION(execBevelEdges); \
	DECLARE_FUNCTION(execOffsetFaces); \
	DECLARE_FUNCTION(execInsetFaces); \
	DECLARE_FUNCTION(execExtrudeFaces); \
	DECLARE_FUNCTION(execGetPolygroups);


struct Z_Construct_UClass_UModellingEditToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingEditToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingEditToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingEditToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingEditToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingEditToolset) \
	DECLARE_SERIALIZER(UModellingEditToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingEditToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingEditToolset(UModellingEditToolset&&) = delete; \
	UModellingEditToolset(const UModellingEditToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingEditToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingEditToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingEditToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingEditToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_18_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingEditToolset;

// ********** End Class UModellingEditToolset ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingEditToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
