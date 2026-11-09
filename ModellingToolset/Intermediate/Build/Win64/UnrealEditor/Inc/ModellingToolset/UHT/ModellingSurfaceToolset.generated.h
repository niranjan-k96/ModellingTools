// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ModellingSurfaceToolset.h"

#ifdef MODELLINGTOOLSET_ModellingSurfaceToolset_generated_h
#error "ModellingSurfaceToolset.generated.h already included, missing '#pragma once' in ModellingSurfaceToolset.h"
#endif
#define MODELLINGTOOLSET_ModellingSurfaceToolset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FModellingCapture;
struct FModellingSelection;

// ********** Begin Class UModellingSurfaceToolset *************************************************
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execApplyGlass); \
	DECLARE_FUNCTION(execApplySurfaceFaces); \
	DECLARE_FUNCTION(execApplySurfacePart); \
	DECLARE_FUNCTION(execPreviewSurface); \
	DECLARE_FUNCTION(execFindClosestSurface); \
	DECLARE_FUNCTION(execListSurfaces);


struct Z_Construct_UClass_UModellingSurfaceToolset_Statics;
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingSurfaceToolset(ETypeConstructPhase);

#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_UModellingSurfaceToolset_Statics; \
	friend MODELLINGTOOLSET_API UClass* ::Z_Construct_UClass_UModellingSurfaceToolset(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(UModellingSurfaceToolset, UToolsetDefinition, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ModellingToolset"), Z_Construct_UClass_UModellingSurfaceToolset) \
	DECLARE_SERIALIZER(UModellingSurfaceToolset)


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MODELLINGTOOLSET_API UModellingSurfaceToolset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UModellingSurfaceToolset(UModellingSurfaceToolset&&) = delete; \
	UModellingSurfaceToolset(const UModellingSurfaceToolset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MODELLINGTOOLSET_API, UModellingSurfaceToolset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UModellingSurfaceToolset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UModellingSurfaceToolset) \
	MODELLINGTOOLSET_API virtual ~UModellingSurfaceToolset();


#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_20_PROLOG
#define FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_INCLASS_NO_PURE_DECLS \
	FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UModellingSurfaceToolset;

// ********** End Class UModellingSurfaceToolset ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingSurfaceToolset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
