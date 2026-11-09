// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingMaterialsToolset.h"

#ifdef MODELLINGTOOLSET_ModellingMaterialsToolset_generated_h
#error "ModellingMaterialsToolset.generated.h already included, missing '#pragma once' in ModellingMaterialsToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingMaterialsToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingSelection;

// ********** Begin Class UModellingMaterialsToolset ***********************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execListMaterialSlots); \
	DECLARE_FUNCTION(execAssignMaterial); \
	DECLARE_FUNCTION(execPaintFaces); \
	DECLARE_FUNCTION(execPaintPart); \
	DECLARE_FUNCTION(execCreateColorMaterial); \
	DECLARE_FUNCTION(execGetReferencePalette);


struct Z_Construct_UClass_UModellingMaterialsToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingMaterialsToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingMaterialsToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingMaterialsToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingMaterialsToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingMaterialsToolset) \
	DECLARE_SERIALIZER(UModellingMaterialsToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingMaterialsToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingMaterialsToolset(UModellingMaterialsToolset&&) = delete; \
	UModellingMaterialsToolset(const UModellingMaterialsToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingMaterialsToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingMaterialsToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingMaterialsToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingMaterialsToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_17_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingMaterialsToolset;

// ********** End Class UModellingMaterialsToolset *************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingMaterialsToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
