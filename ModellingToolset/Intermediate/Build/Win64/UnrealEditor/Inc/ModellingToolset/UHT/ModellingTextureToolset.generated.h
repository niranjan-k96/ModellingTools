// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingTextureToolset.h"

#ifdef MODELLINGTOOLSET_ModellingTextureToolset_generated_h
#error "ModellingTextureToolset.generated.h already included, missing '#pragma once' in ModellingTextureToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingTextureToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingCapture;
struct FModellingSelection;

// ********** Begin Class UModellingTextureToolset *************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execCheckTextureStretch); \
	DECLARE_FUNCTION(execAutoUV); \
	DECLARE_FUNCTION(execPreviewMaterial); \
	DECLARE_FUNCTION(execApplyLibraryMaterial); \
	DECLARE_FUNCTION(execListLibraryMaterials); \
	DECLARE_FUNCTION(execApplyTextureFaces); \
	DECLARE_FUNCTION(execApplyTexturePart); \
	DECLARE_FUNCTION(execImportTextureSets); \
	DECLARE_FUNCTION(execListTextureSets);


struct Z_Construct_UClass_UModellingTextureToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingTextureToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingTextureToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingTextureToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingTextureToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingTextureToolset) \
	DECLARE_SERIALIZER(UModellingTextureToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingTextureToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingTextureToolset(UModellingTextureToolset&&) = delete; \
	UModellingTextureToolset(const UModellingTextureToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingTextureToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingTextureToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingTextureToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingTextureToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_23_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingTextureToolset;

// ********** End Class UModellingTextureToolset ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingTextureToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
