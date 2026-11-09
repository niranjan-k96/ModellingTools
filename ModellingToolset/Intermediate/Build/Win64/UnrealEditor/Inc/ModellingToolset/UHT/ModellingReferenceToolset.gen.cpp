// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ModellingReferenceToolset.h"
#include "ToolsetRegistry/ToolsetImage.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeModellingReferenceToolset() {}

// ********** Begin Cross Module References ********************************************************
TOOLSETREGISTRY_API UClass* Z_Construct_UClass_UToolsetDefinition(ETypeConstructPhase);
TOOLSETREGISTRY_API UScriptStruct* Z_Construct_UScriptStruct_FToolsetImage(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FModellingReference(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingReferenceToolset(ETypeConstructPhase);
MODELLINGTOOLSET_API UClass* Z_Construct_UClass_UModellingReferenceToolset(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FModellingReference ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FModellingReference_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FModellingReference>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FModellingReference); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A reference image plus any notes the user wrote for it. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A reference image plus any notes the user wrote for it." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The image, downscaled to fit MaxDimension. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The image, downscaled to fit MaxDimension." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** File name inside the references folder. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "File name inside the references folder." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Notes_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Contents of a same-name .txt or .md file next to the image (scale, intent, materials). Empty if none. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Contents of a same-name .txt or .md file next to the image (scale, intent, materials). Empty if none." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalWidth_MetaData[] = {
		{ "Category", "ModellingToolset" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Original pixel size before downscaling. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Original pixel size before downscaling." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OriginalHeight_MetaData[] = {
		{ "Category", "ModellingToolset" },
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FModellingReference constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Notes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OriginalWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OriginalHeight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FModellingReference constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FModellingReference>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS

// ********** Begin ScriptStruct FModellingReference Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingReference, Image), Z_Construct_UScriptStruct_FToolsetImage, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) }; // 7da671e557717bf7df314aac298bc871a740b4f5
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingReference, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Notes = { "Notes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingReference, Notes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Notes_MetaData), NewProp_Notes_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OriginalWidth = { "OriginalWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingReference, OriginalWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalWidth_MetaData), NewProp_OriginalWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_OriginalHeight = { "OriginalHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(FModellingReference, OriginalHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OriginalHeight_MetaData), NewProp_OriginalHeight_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Notes,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OriginalWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_OriginalHeight,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End ScriptStruct FModellingReference Property Definitions ****************************
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
	nullptr,
	&NewStructOps,
	"ModellingReference",
	UHT_STATICS::PropPointers,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	DataSizeOf<FModellingReference>(),
	alignof(FModellingReference),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FModellingReference;
UScriptStruct* Z_Construct_UScriptStruct_FModellingReference(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FModellingReference.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FModellingReference.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FModellingReference, (UObject*)Z_Construct_UPackage__Script_ModellingToolset(ETypeConstructPhase::Outer), TEXT("ModellingReference"));
		}
		return Z_Registration_Info_UScriptStruct_FModellingReference.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FModellingReference.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FModellingReference.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FModellingReference.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FModellingReference *************************************************

// ********** Begin Class UModellingReferenceToolset Function GetReference *************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingReferenceToolset_GetReference_Statics
struct UHT_STATICS
{
	struct ModellingReferenceToolset_eventGetReference_Parms
	{
		FString Name;
		int32 MaxDimension;
		FModellingReference ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Reference" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reads one reference image and its notes.\n\x09 * @param Name          File name from ListReferences (no folders).\n\x09 * @param MaxDimension  Longest side in pixels after downscaling (keeps the image cheap to view). */" },
#endif
		{ "CPP_Default_MaxDimension", "1024" },
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reads one reference image and its notes.\n@param Name          File name from ListReferences (no folders).\n@param MaxDimension  Longest side in pixels after downscaling (keeps the image cheap to view)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetReference constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDimension;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetReference constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetReference Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingReferenceToolset_eventGetReference_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_MaxDimension = { "MaxDimension", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingReferenceToolset_eventGetReference_Parms, MaxDimension), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingReferenceToolset_eventGetReference_Parms, ReturnValue), Z_Construct_UScriptStruct_FModellingReference, METADATA_PARAMS(0, nullptr) }; // 140260566e153286a8becdc29e06c86555d71b71
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxDimension,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function GetReference Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingReferenceToolset, nullptr, "GetReference", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingReferenceToolset_eventGetReference_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingReferenceToolset_eventGetReference_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingReferenceToolset_GetReference(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingReferenceToolset::execGetReference)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Name);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxDimension);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FModellingReference*)Z_Param__Result=UModellingReferenceToolset::GetReference(Z_Param_Name,Z_Param_MaxDimension);
	P_NATIVE_END;
}
// ********** End Class UModellingReferenceToolset Function GetReference ***************************

// ********** Begin Class UModellingReferenceToolset Function ListReferences ***********************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_UModellingReferenceToolset_ListReferences_Statics
struct UHT_STATICS
{
	struct ModellingReferenceToolset_eventListReferences_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "AICallable", "" },
		{ "Category", "ModellingToolset|Reference" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lists reference images the user has placed in the references folder, as a JSON array with sizes and whether a notes file exists.\n\x09 * Check this at the start of a task: if images are present, model from them. */" },
#endif
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lists reference images the user has placed in the references folder, as a JSON array with sizes and whether a notes file exists.\nCheck this at the start of a task: if images are present, model from them." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ListReferences constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ListReferences constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ListReferences Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams UHT_STATICS::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, nullptr, nullptr, 1, STRUCT_OFFSET(ModellingReferenceToolset_eventListReferences_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ListReferences Property Definitions *************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_UModellingReferenceToolset, nullptr, "ListReferences", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<UHT_STATICS::ModellingReferenceToolset_eventListReferences_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(UHT_STATICS::ModellingReferenceToolset_eventListReferences_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UModellingReferenceToolset_ListReferences(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(UModellingReferenceToolset::execListReferences)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UModellingReferenceToolset::ListReferences();
	P_NATIVE_END;
}
// ********** End Class UModellingReferenceToolset Function ListReferences *************************

// ********** Begin Class UModellingReferenceToolset ***********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_UModellingReferenceToolset_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Reference-image workflow. The user drops images (png, jpg, bmp) into the references folder, optionally\n * with a same-name .txt/.md note, and the AI reads them here to recreate the subject in 3D.\n */" },
#endif
		{ "IncludePath", "ModellingReferenceToolset.h" },
		{ "ModuleRelativePath", "Public/ModellingReferenceToolset.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference-image workflow. The user drops images (png, jpg, bmp) into the references folder, optionally\nwith a same-name .txt/.md note, and the AI reads them here to recreate the subject in 3D." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UModellingReferenceToolset constinit property declarations ***************
// ********** End Class UModellingReferenceToolset constinit property declarations *****************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetReference"), .Pointer = &UModellingReferenceToolset::execGetReference },
		{ .NameUTF8 = UTF8TEXT("ListReferences"), .Pointer = &UModellingReferenceToolset::execListReferences },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UModellingReferenceToolset_GetReference, "GetReference" }, // 42f6800be2df7ae90941977f37d198f24bd1e048
		{ &Z_Construct_UFunction_UModellingReferenceToolset_ListReferences, "ListReferences" }, // b35d9accd4474de7efc93c4d370db3f434e3532f
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UModellingReferenceToolset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_UToolsetDefinition,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_ModellingToolset,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_UModellingReferenceToolset,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void UModellingReferenceToolset_StaticRegisterNativesUModellingReferenceToolset()
{
	UClass* Class = UModellingReferenceToolset::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UModellingReferenceToolset;
UClass* Z_Construct_UClass_UModellingReferenceToolset(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = UModellingReferenceToolset;
		if (!Z_Registration_Info_UClass_UModellingReferenceToolset.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("ModellingReferenceToolset"),
				Z_Registration_Info_UClass_UModellingReferenceToolset.InnerSingleton,
				UModellingReferenceToolset_StaticRegisterNativesUModellingReferenceToolset,
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
		return Z_Registration_Info_UClass_UModellingReferenceToolset.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_UModellingReferenceToolset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UModellingReferenceToolset.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_UModellingReferenceToolset.OuterSingleton;
}
#undef UHT_STATICS
UModellingReferenceToolset::UModellingReferenceToolset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UModellingReferenceToolset);
UModellingReferenceToolset::~UModellingReferenceToolset() {}
// ********** End Class UModellingReferenceToolset *************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h__Script_ModellingToolset_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FModellingReference, Z_Construct_UScriptStruct_FModellingReference_Statics::NewStructOps, TEXT("ModellingReference"),&Z_Registration_Info_UScriptStruct_FModellingReference, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FModellingReference), 335700054U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UModellingReferenceToolset, TEXT("UModellingReferenceToolset"), &Z_Registration_Info_UClass_UModellingReferenceToolset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UModellingReferenceToolset), 946320121U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_nkota_Documents_Unreal_Projects_TestProject_Plugins_ModellingToolset_Source_ModellingToolset_Public_ModellingReferenceToolset_h__Script_ModellingToolset_609f789b04da9ac38973544af5535cd1bdb8d1be{
	TEXT("/Script/ModellingToolset"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
