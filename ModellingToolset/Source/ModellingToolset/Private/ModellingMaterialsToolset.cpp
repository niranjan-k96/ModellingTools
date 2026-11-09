// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingMaterialsToolset.h"

#include "ModellingToolsetUtils.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "Components/DynamicMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMesh/DynamicMeshAttributeSet.h"
#include "DynamicMeshActor.h"
#include "Engine/Texture2D.h"
#include "Factories/MaterialFactoryNew.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "FileHelpers.h"
#include "HAL/FileManager.h"
#include "IAssetTools.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionComponentMask.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionLinearInterpolate.h"
#include "Materials/MaterialExpressionConstant3Vector.h"
#include "Materials/MaterialExpressionDivide.h"
#include "Materials/MaterialExpressionMaterialFunctionCall.h"
#include "Materials/MaterialExpressionMultiply.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionStaticSwitchParameter.h"
#include "Materials/MaterialExpressionTextureCoordinate.h"
#include "Materials/MaterialExpressionTextureObjectParameter.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionVertexNormalWS.h"
#include "Materials/MaterialFunction.h"
#include "Materials/MaterialInstanceConstant.h"
#include "MaterialEditingLibrary.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"
#include "UObject/Package.h"

using namespace ModellingToolset;

namespace
{
	const TCHAR* MaterialFolder = TEXT("/Game/ModellingToolset/Materials");
	const TCHAR* BaseMaterialName = TEXT("M_ModellingBase");

	bool ParseHex(const FString& In, FColor& Out, FString& Error)
	{
		FString Hex = In.TrimStartAndEnd();
		Hex.RemoveFromStart(TEXT("#"));
		if (Hex.Len() != 6 && Hex.Len() != 8)
		{
			Error = TEXT("Colour must be hex like #C03A2B (6 digits).");
			return false;
		}
		for (const TCHAR C : Hex)
		{
			if (!FChar::IsHexDigit(C))
			{
				Error = TEXT("Colour must be hex like #C03A2B (digits 0-9 and letters A-F only).");
				return false;
			}
		}
		Out = FColor::FromHex(Hex);
		Out.A = 255;
		return true;
	}

	FString ToHex(const FVector& Rgb255)
	{
		return FString::Printf(TEXT("#%02X%02X%02X"),
			FMath::Clamp(FMath::RoundToInt(Rgb255.X), 0, 255), FMath::Clamp(FMath::RoundToInt(Rgb255.Y), 0, 255), FMath::Clamp(FMath::RoundToInt(Rgb255.Z), 0, 255));
	}

	UObject* FindAsset(const FString& ObjectPath)
	{
		if (UObject* Loaded = FindObject<UObject>(nullptr, *ObjectPath))
		{
			return Loaded;
		}
		const FAssetData Existing = FAssetRegistryModule::GetRegistry().GetAssetByObjectPath(FSoftObjectPath(ObjectPath));
		return Existing.IsValid() ? Existing.GetAsset() : nullptr;
	}

	bool SaveAsset(UObject* Asset)
	{
		return Asset && UEditorLoadingAndSavingUtils::SavePackages({ Asset->GetOutermost() }, /*bOnlyDirty=*/false);
	}

	FString ObjectPathIn(const TCHAR* Folder, const FString& AssetName)
	{
		return FString::Printf(TEXT("%s/%s.%s"), Folder, *AssetName, *AssetName);
	}

	// ---- Small helper textures the master materials use as defaults --------------------------------------------

	/** A 4x4 single-colour texture asset. Used so every texture parameter has a valid default of the right kind. */
	UTexture2D* GetOrCreateSolidTexture(const FString& AssetName, FColor Colour, bool bNormalMap, FString& Error)
	{
		const FString ObjectPath = ObjectPathIn(MaterialFolder, AssetName);
		if (UTexture2D* Existing = Cast<UTexture2D>(FindAsset(ObjectPath)))
		{
			return Existing;
		}

		UPackage* Package = CreatePackage(*(FString(MaterialFolder) / AssetName));
		UTexture2D* Texture = NewObject<UTexture2D>(Package, FName(*AssetName), RF_Public | RF_Standalone);
		if (!Texture)
		{
			Error = TEXT("Could not create a helper texture.");
			return nullptr;
		}
		TArray<uint8> Pixels;
		Pixels.SetNumUninitialized(4 * 4 * 4);
		for (int32 i = 0; i < 16; ++i)
		{
			Pixels[i * 4 + 0] = Colour.B; Pixels[i * 4 + 1] = Colour.G; Pixels[i * 4 + 2] = Colour.R; Pixels[i * 4 + 3] = 255;
		}
		Texture->Source.Init(4, 4, 1, 1, TSF_BGRA8, Pixels.GetData());
		Texture->SRGB = false;
		Texture->CompressionSettings = bNormalMap ? TC_Normalmap : TC_Default;
		Texture->MipGenSettings = TMGS_NoMipmaps;
		Texture->LODGroup = bNormalMap ? TEXTUREGROUP_WorldNormalMap : TEXTUREGROUP_World;
		Texture->UpdateResource();
		Texture->PostEditChange();
		Texture->MarkPackageDirty();
		FAssetRegistryModule::AssetCreated(Texture);
		SaveAsset(Texture);
		return Texture;
	}

	// ---- Base colour material ----------------------------------------------------------------------------------

	UMaterial* GetOrCreateBaseMaterial(FString& Error)
	{
		const FString ObjectPath = ObjectPathIn(MaterialFolder, BaseMaterialName);
		if (UMaterial* Existing = Cast<UMaterial>(FindAsset(ObjectPath)))
		{
			return Existing;
		}

		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
		UMaterialFactoryNew* Factory = NewObject<UMaterialFactoryNew>();
		UMaterial* Material = Cast<UMaterial>(AssetTools.CreateAsset(BaseMaterialName, MaterialFolder, UMaterial::StaticClass(), Factory));
		if (!Material)
		{
			Error = TEXT("Could not create the base material.");
			return nullptr;
		}

		auto AddVector = [&](const TCHAR* Name, const FLinearColor& Default, int32 Y, EMaterialProperty Property)
		{
			UMaterialExpressionVectorParameter* E = Cast<UMaterialExpressionVectorParameter>(
				UMaterialEditingLibrary::CreateMaterialExpression(Material, UMaterialExpressionVectorParameter::StaticClass(), -400, Y));
			E->ParameterName = Name;
			E->DefaultValue = Default;
			UMaterialEditingLibrary::ConnectMaterialProperty(E, FString(), Property);
		};
		auto AddScalar = [&](const TCHAR* Name, float Default, int32 Y, EMaterialProperty Property)
		{
			UMaterialExpressionScalarParameter* E = Cast<UMaterialExpressionScalarParameter>(
				UMaterialEditingLibrary::CreateMaterialExpression(Material, UMaterialExpressionScalarParameter::StaticClass(), -400, Y));
			E->ParameterName = Name;
			E->DefaultValue = Default;
			UMaterialEditingLibrary::ConnectMaterialProperty(E, FString(), Property);
		};
		AddVector(TEXT("Color"), FLinearColor(0.5f, 0.5f, 0.5f), 0, MP_BaseColor);
		AddScalar(TEXT("Roughness"), 0.6f, 200, MP_Roughness);
		AddScalar(TEXT("Metallic"), 0.f, 350, MP_Metallic);
		AddVector(TEXT("Emissive"), FLinearColor::Black, 500, MP_EmissiveColor);

		UMaterialEditingLibrary::RecompileMaterial(Material);
		Material->MarkPackageDirty();
		SaveAsset(Material);
		return Material;
	}

	// ---- Textured master materials -----------------------------------------------------------------------------

	/** Node-building helpers for the textured masters. */
	struct FMaterialBuilder
	{
		UMaterial* Material = nullptr;
		int32 NextY = 0;

		template <typename T>
		T* Node(int32 X)
		{
			T* E = Cast<T>(UMaterialEditingLibrary::CreateMaterialExpression(Material, T::StaticClass(), X, NextY));
			NextY += 160;
			return E;
		}

		UMaterialExpressionScalarParameter* Scalar(const TCHAR* Name, float Default)
		{
			UMaterialExpressionScalarParameter* E = Node<UMaterialExpressionScalarParameter>(-1200);
			E->ParameterName = Name;
			E->DefaultValue = Default;
			return E;
		}

		UMaterialExpressionVectorParameter* Vector(const TCHAR* Name, const FLinearColor& Default)
		{
			UMaterialExpressionVectorParameter* E = Node<UMaterialExpressionVectorParameter>(-1200);
			E->ParameterName = Name;
			E->DefaultValue = Default;
			return E;
		}

		UMaterialExpressionStaticSwitchParameter* Switch(const TCHAR* Name, UMaterialExpression* WhenTrue, UMaterialExpression* WhenFalse, int32 TrueOutput = 0)
		{
			UMaterialExpressionStaticSwitchParameter* E = Node<UMaterialExpressionStaticSwitchParameter>(-300);
			E->ParameterName = Name;
			E->DefaultValue = false;
			E->A.Connect(TrueOutput, WhenTrue);
			E->B.Connect(0, WhenFalse);
			return E;
		}

		UMaterialExpressionComponentMask* RedOf(UMaterialExpression* From, int32 Output = 0) { return ChannelOf(From, Output, 0); }

		/** Picks one channel (0 = red, 1 = green, 2 = blue) of a colour output. */
		UMaterialExpressionComponentMask* ChannelOf(UMaterialExpression* From, int32 Output, int32 Channel)
		{
			UMaterialExpressionComponentMask* E = Node<UMaterialExpressionComponentMask>(-500);
			E->R = Channel == 0; E->G = Channel == 1; E->B = Channel == 2; E->A = false;
			E->Input.Connect(Output, From);
			return E;
		}

		UMaterialExpressionLinearInterpolate* Lerp(UMaterialExpression* A, UMaterialExpression* B, UMaterialExpression* Alpha, int32 AlphaOutput = 0)
		{
			UMaterialExpressionLinearInterpolate* E = Node<UMaterialExpressionLinearInterpolate>(-400);
			E->A.Connect(0, A);
			E->B.Connect(0, B);
			E->Alpha.Connect(AlphaOutput, Alpha);
			return E;
		}

		UMaterialExpressionConstant* Constant(float Value)
		{
			UMaterialExpressionConstant* E = Node<UMaterialExpressionConstant>(-500);
			E->R = Value;
			return E;
		}

		UMaterialExpressionMultiply* Multiply(UMaterialExpression* A, int32 AOutput, UMaterialExpression* B)
		{
			UMaterialExpressionMultiply* E = Node<UMaterialExpressionMultiply>(-500);
			E->A.Connect(AOutput, A);
			E->B.Connect(0, B);
			return E;
		}

		/** A call to one of the engine's world-aligned texture functions, with the texture and tile size connected. */
		UMaterialExpressionMaterialFunctionCall* WorldAligned(bool bNormal, UMaterialExpression* TextureObject, UMaterialExpression* TileCm, int32& OutXYZOutput, FString& Error)
		{
			const TCHAR* Path = bNormal
				? TEXT("/Engine/Functions/Engine_MaterialFunctions01/Texturing/WorldAlignedNormal.WorldAlignedNormal")
				: TEXT("/Engine/Functions/Engine_MaterialFunctions01/Texturing/WorldAlignedTexture.WorldAlignedTexture");
			UMaterialFunction* Function = LoadObject<UMaterialFunction>(nullptr, Path);
			if (!Function)
			{
				Error = FString::Printf(TEXT("The engine material function %s was not found."), Path);
				return nullptr;
			}
			UMaterialExpressionMaterialFunctionCall* Call = Node<UMaterialExpressionMaterialFunctionCall>(-800);
			Call->SetMaterialFunction(Function);

			bool bTexture = false, bSize = false;
			for (FFunctionExpressionInput& In : Call->FunctionInputs)
			{
				const FString Name = In.Input.InputName.ToString();
				if (Name.Contains(TEXT("TextureObject"))) { In.Input.Connect(0, TextureObject); bTexture = true; }
				else if (Name.Contains(TEXT("TextureSize"))) { In.Input.Connect(0, TileCm); bSize = true; }
			}
			OutXYZOutput = INDEX_NONE;
			for (int32 i = 0; i < Call->FunctionOutputs.Num(); ++i)
			{
				if (Call->FunctionOutputs[i].Output.OutputName.ToString().Contains(TEXT("XYZ"))) { OutXYZOutput = i; break; }
			}
			if (!bTexture || !bSize || OutXYZOutput == INDEX_NONE)
			{
				Error = FString::Printf(TEXT("The engine material function %s does not have the expected inputs and outputs."), Path);
				return nullptr;
			}
			return Call;
		}
	};

	UMaterial* BuildTexturedMaster(bool bWorldAligned, FString& Error)
	{
		const FString AssetName = bWorldAligned ? TEXT("M_ModellingWorldAligned_v2") : TEXT("M_ModellingTextured_v2");
		if (UMaterial* Existing = Cast<UMaterial>(FindAsset(ObjectPathIn(MaterialFolder, AssetName))))
		{
			return Existing;
		}

		UTexture2D* DefaultWhite = GetOrCreateSolidTexture(TEXT("T_ModellingWhite"), FColor::White, false, Error);
		UTexture2D* DefaultNormal = GetOrCreateSolidTexture(TEXT("T_ModellingFlatNormal"), FColor(128, 128, 255), true, Error);
		UTexture* DefaultColour = LoadObject<UTexture>(nullptr, TEXT("/Engine/EngineResources/DefaultTexture.DefaultTexture"));
		if (!DefaultWhite || !DefaultNormal)
		{
			return nullptr;
		}
		if (!DefaultColour) { DefaultColour = DefaultWhite; }

		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
		UMaterialFactoryNew* Factory = NewObject<UMaterialFactoryNew>();
		UMaterial* Material = Cast<UMaterial>(AssetTools.CreateAsset(AssetName, MaterialFolder, UMaterial::StaticClass(), Factory));
		if (!Material)
		{
			Error = TEXT("Could not create the textured master material.");
			return nullptr;
		}
		// World-aligned normals come out in world space, not tangent space.
		Material->bTangentSpaceNormal = !bWorldAligned;

		FMaterialBuilder B;
		B.Material = Material;
		UMaterialExpressionScalarParameter* TileCm = B.Scalar(TEXT("TileCm"), 100.f);
		UMaterialExpressionVectorParameter* Tint = B.Vector(TEXT("Tint"), FLinearColor::White);
		UMaterialExpressionScalarParameter* RoughnessValue = B.Scalar(TEXT("Roughness"), 0.6f);
		UMaterialExpressionScalarParameter* MetallicValue = B.Scalar(TEXT("Metallic"), 0.f);
		UMaterialExpressionScalarParameter* RoughnessMin = B.Scalar(TEXT("RoughnessMin"), 0.f);
		UMaterialExpressionScalarParameter* RoughnessMax = B.Scalar(TEXT("RoughnessMax"), 1.f);
		UMaterialExpression* PackedOut = nullptr; int32 PackedIdx = 0;

		UMaterialExpression* AlbedoOut = nullptr; int32 AlbedoIdx = 0;
		UMaterialExpression* NormalOut = nullptr; int32 NormalIdx = 0;
		UMaterialExpression* RoughOut = nullptr; int32 RoughIdx = 0;
		UMaterialExpression* MetalOut = nullptr; int32 MetalIdx = 0;

		if (bWorldAligned)
		{
			auto TextureObject = [&](const TCHAR* Name, UTexture* Default, EMaterialSamplerType Sampler)
			{
				UMaterialExpressionTextureObjectParameter* E = B.Node<UMaterialExpressionTextureObjectParameter>(-1200);
				E->ParameterName = Name;
				E->Texture = Default;
				E->SamplerType = Sampler;
				return E;
			};
			AlbedoOut = B.WorldAligned(false, TextureObject(TEXT("AlbedoTexture"), DefaultColour, SAMPLERTYPE_Color), TileCm, AlbedoIdx, Error);
			NormalOut = B.WorldAligned(true, TextureObject(TEXT("NormalTexture"), DefaultNormal, SAMPLERTYPE_Normal), TileCm, NormalIdx, Error);
			RoughOut = B.WorldAligned(false, TextureObject(TEXT("RoughnessTexture"), DefaultWhite, SAMPLERTYPE_LinearColor), TileCm, RoughIdx, Error);
			MetalOut = B.WorldAligned(false, TextureObject(TEXT("MetallicTexture"), DefaultWhite, SAMPLERTYPE_LinearColor), TileCm, MetalIdx, Error);
			PackedOut = B.WorldAligned(false, TextureObject(TEXT("ORMTexture"), DefaultWhite, SAMPLERTYPE_LinearColor), TileCm, PackedIdx, Error);
		}
		else
		{
			// UVs: AutoUV lays one UV unit per 100 cm, so tiling = 100 / TileCm.
			UMaterialExpressionTextureCoordinate* TexCoord = B.Node<UMaterialExpressionTextureCoordinate>(-1200);
			UMaterialExpressionScalarParameter* UvUnit = B.Scalar(TEXT("UVUnitCm"), 100.f);
			UMaterialExpressionDivide* Tiling = B.Node<UMaterialExpressionDivide>(-900);
			Tiling->A.Connect(0, UvUnit);
			Tiling->B.Connect(0, TileCm);
			UMaterialExpressionMultiply* UVs = B.Node<UMaterialExpressionMultiply>(-900);
			UVs->A.Connect(0, TexCoord);
			UVs->B.Connect(0, Tiling);

			auto Sample = [&](const TCHAR* Name, UTexture* Default, EMaterialSamplerType Sampler)
			{
				UMaterialExpressionTextureSampleParameter2D* E = B.Node<UMaterialExpressionTextureSampleParameter2D>(-800);
				E->ParameterName = Name;
				E->Texture = Default;
				E->SamplerType = Sampler;
				E->Coordinates.Connect(0, UVs);
				return E;
			};
			AlbedoOut = Sample(TEXT("AlbedoTexture"), DefaultColour, SAMPLERTYPE_Color);
			NormalOut = Sample(TEXT("NormalTexture"), DefaultNormal, SAMPLERTYPE_Normal);
			RoughOut = Sample(TEXT("RoughnessTexture"), DefaultWhite, SAMPLERTYPE_LinearColor);
			MetalOut = Sample(TEXT("MetallicTexture"), DefaultWhite, SAMPLERTYPE_LinearColor);
			PackedOut = Sample(TEXT("ORMTexture"), DefaultWhite, SAMPLERTYPE_LinearColor);
		}
		if (!AlbedoOut || !NormalOut || !RoughOut || !MetalOut || !PackedOut)
		{
			Material->MarkAsGarbage();
			return nullptr;
		}

		// Base colour = texture * tint.
		UMaterialExpressionMultiply* Tinted = B.Multiply(AlbedoOut, AlbedoIdx, Tint);

		// Normal: the texture when enabled, otherwise the plain surface normal.
		UMaterialExpression* FlatNormal = nullptr;
		if (bWorldAligned)
		{
			FlatNormal = B.Node<UMaterialExpressionVertexNormalWS>(-500);
		}
		else
		{
			UMaterialExpressionConstant3Vector* Up = B.Node<UMaterialExpressionConstant3Vector>(-500);
			Up->Constant = FLinearColor(0.f, 0.f, 1.f);
			FlatNormal = Up;
		}
		UMaterialExpressionStaticSwitchParameter* NormalSwitch = B.Switch(TEXT("UseNormalTexture"), NormalOut, FlatNormal, NormalIdx);
		UMaterialExpressionStaticSwitchParameter* RoughSwitch = B.Switch(TEXT("UseRoughnessTexture"), B.RedOf(RoughOut, RoughIdx), RoughnessValue);
		UMaterialExpressionStaticSwitchParameter* MetalSwitch = B.Switch(TEXT("UseMetallicTexture"), B.RedOf(MetalOut, MetalIdx), MetallicValue);

		// Packed occlusion/roughness/metallic map (Megascans ORM): roughness is remapped into [RoughnessMin, RoughnessMax].
		UMaterialExpressionLinearInterpolate* PackedRough = B.Lerp(RoughnessMin, RoughnessMax, B.ChannelOf(PackedOut, PackedIdx, 1));
		UMaterialExpressionStaticSwitchParameter* PackedRoughSwitch = B.Switch(TEXT("UsePackedORM"), PackedRough, RoughSwitch);
		UMaterialExpressionStaticSwitchParameter* PackedMetalSwitch = B.Switch(TEXT("UsePackedORM"), B.ChannelOf(PackedOut, PackedIdx, 2), MetalSwitch);
		UMaterialExpressionStaticSwitchParameter* PackedAOSwitch = B.Switch(TEXT("UsePackedORM"), B.ChannelOf(PackedOut, PackedIdx, 0), B.Constant(1.f));

		UMaterialEditingLibrary::ConnectMaterialProperty(Tinted, FString(), MP_BaseColor);
		UMaterialEditingLibrary::ConnectMaterialProperty(NormalSwitch, FString(), MP_Normal);
		UMaterialEditingLibrary::ConnectMaterialProperty(PackedRoughSwitch, FString(), MP_Roughness);
		UMaterialEditingLibrary::ConnectMaterialProperty(PackedMetalSwitch, FString(), MP_Metallic);
		UMaterialEditingLibrary::ConnectMaterialProperty(PackedAOSwitch, FString(), MP_AmbientOcclusion);

		UMaterialEditingLibrary::RecompileMaterial(Material);
		Material->MarkPackageDirty();
		SaveAsset(Material);
		return Material;
	}

	UMaterialInstanceConstant* GetOrCreateInstance(const FString& Name, const FColor& Color, float Roughness, float Metallic, float EmissiveStrength, FString& Error)
	{
		UMaterial* Base = GetOrCreateBaseMaterial(Error);
		if (!Base)
		{
			return nullptr;
		}

		const FString AssetName = TEXT("MI_") + SanitizeFileName(Name);
		UMaterialInstanceConstant* Instance = Cast<UMaterialInstanceConstant>(FindAsset(ObjectPathIn(MaterialFolder, AssetName)));
		if (!Instance)
		{
			IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
			UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
			Factory->InitialParent = Base;
			Instance = Cast<UMaterialInstanceConstant>(AssetTools.CreateAsset(AssetName, MaterialFolder, UMaterialInstanceConstant::StaticClass(), Factory));
			if (!Instance)
			{
				Error = TEXT("Could not create the material instance.");
				return nullptr;
			}
		}

		const FLinearColor Linear = FLinearColor::FromSRGBColor(Color);
		UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("Color"), Linear);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Roughness"), FMath::Clamp(Roughness, 0.f, 1.f));
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Metallic"), FMath::Clamp(Metallic, 0.f, 1.f));
		const FLinearColor Emissive = Linear * FMath::Max(EmissiveStrength, 0.f);
		UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("Emissive"), Emissive);
		UMaterialEditingLibrary::UpdateMaterialInstance(Instance);
		Instance->MarkPackageDirty();
		SaveAsset(Instance);
		return Instance;
	}

	FString AssetPathOf(const UObject* Asset)
	{
		return Asset ? Asset->GetPathName() : FString();
	}

	/** Triangle count per material ID. */
	TMap<int32, int32> CountByMaterialId(UDynamicMesh* Mesh)
	{
		TMap<int32, int32> Counts;
		Mesh->ProcessMesh([&Counts](const UE::Geometry::FDynamicMesh3& M)
		{
			const bool bHasIds = M.HasAttributes() && M.Attributes()->HasMaterialID();
			for (const int32 Tid : M.TriangleIndicesItr())
			{
				Counts.FindOrAdd(bHasIds ? M.Attributes()->GetMaterialID()->GetValue(Tid) : 0)++;
			}
		});
		return Counts;
	}

	FString DefaultMaterialName(const FString& Actor, const FColor& Color)
	{
		return FString::Printf(TEXT("%s_%02X%02X%02X"), *Actor, Color.R, Color.G, Color.B);
	}
}

UMaterial* UModellingMaterialsToolset::GetBaseMaterial(FString& OutError)
{
	return GetOrCreateBaseMaterial(OutError);
}

UMaterial* UModellingMaterialsToolset::GetTexturedMasterMaterial(bool bWorldAligned, FString& OutError)
{
	return BuildTexturedMaster(bWorldAligned, OutError);
}

UMaterialInstanceConstant* UModellingMaterialsToolset::GetOrCreateTexturedInstance(
	const FTextureSet& Set, float TileCm, bool bWorldAligned, const FLinearColor& Tint, float RoughnessOverride, float MetallicOverride, FString& OutError)
{
	FSurfaceLook Look;
	Look.TileCm = TileCm;
	Look.bWorldAligned = bWorldAligned;
	Look.Tint = Tint;
	Look.RoughnessOverride = RoughnessOverride;
	Look.MetallicOverride = MetallicOverride;
	return GetOrCreateTexturedInstance(Set, Look, OutError);
}

UMaterialInstanceConstant* UModellingMaterialsToolset::GetOrCreateTexturedInstance(const FTextureSet& Set, const FSurfaceLook& Look, FString& OutError)
{
	const float TileCm = Look.TileCm;
	const bool bWorldAligned = Look.bWorldAligned;
	const FLinearColor& Tint = Look.Tint;
	const float RoughnessOverride = Look.RoughnessOverride;
	const float MetallicOverride = Look.MetallicOverride;
	if (!Set.Albedo)
	{
		OutError = TEXT("A texture set needs at least an albedo (colour) texture.");
		return nullptr;
	}
	UMaterial* Master = BuildTexturedMaster(bWorldAligned, OutError);
	if (!Master)
	{
		return nullptr;
	}

	// One instance per set, mode, tile size and look, so changing one does not alter parts painted earlier.
	FString AssetName = Look.InstanceName;
	if (AssetName.IsEmpty())
	{
		const FColor TintKey = Tint.ToFColor(true);
		const bool bPlainLook = TintKey == FColor::White && Look.RoughnessMin <= 0.f && Look.RoughnessMax >= 1.f && RoughnessOverride < 0.f && MetallicOverride < 0.f;
		AssetName = FString::Printf(TEXT("MI_Tex_%s_%s_%d"), *SanitizeFileName(Set.Name), bWorldAligned ? TEXT("World") : TEXT("UV"), FMath::RoundToInt(TileCm));
		if (!bPlainLook)
		{
			AssetName += FString::Printf(TEXT("_%02X%02X%02X_R%d%d"), TintKey.R, TintKey.G, TintKey.B, FMath::RoundToInt(Look.RoughnessMin * 10.f), FMath::RoundToInt(Look.RoughnessMax * 10.f));
		}
	}
	UMaterialInstanceConstant* Instance = Cast<UMaterialInstanceConstant>(FindAsset(ObjectPathIn(MaterialFolder, AssetName)));
	if (!Instance)
	{
		IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
		UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
		Factory->InitialParent = Master;
		Instance = Cast<UMaterialInstanceConstant>(AssetTools.CreateAsset(AssetName, MaterialFolder, UMaterialInstanceConstant::StaticClass(), Factory));
		if (!Instance)
		{
			OutError = TEXT("Could not create the textured material instance.");
			return nullptr;
		}
	}

	UMaterialEditingLibrary::SetMaterialInstanceTextureParameterValue(Instance, TEXT("AlbedoTexture"), Set.Albedo);
	if (Set.Normal) { UMaterialEditingLibrary::SetMaterialInstanceTextureParameterValue(Instance, TEXT("NormalTexture"), Set.Normal); }
	if (Set.Roughness) { UMaterialEditingLibrary::SetMaterialInstanceTextureParameterValue(Instance, TEXT("RoughnessTexture"), Set.Roughness); }
	if (Set.Metallic) { UMaterialEditingLibrary::SetMaterialInstanceTextureParameterValue(Instance, TEXT("MetallicTexture"), Set.Metallic); }
	if (Set.PackedORM) { UMaterialEditingLibrary::SetMaterialInstanceTextureParameterValue(Instance, TEXT("ORMTexture"), Set.PackedORM); }
	UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("RoughnessMin"), FMath::Clamp(Look.RoughnessMin, 0.f, 1.f));
	UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("RoughnessMax"), FMath::Clamp(Look.RoughnessMax, 0.f, 1.f));
	UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("UsePackedORM"), Set.PackedORM != nullptr && RoughnessOverride < 0.f && MetallicOverride < 0.f, EMaterialParameterAssociation::GlobalParameter, false);
	UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("TileCm"), FMath::Max(TileCm, 1.f));
	UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("Tint"), Tint);
	if (RoughnessOverride >= 0.f) { UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Roughness"), FMath::Clamp(RoughnessOverride, 0.f, 1.f)); }
	if (MetallicOverride >= 0.f) { UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Metallic"), FMath::Clamp(MetallicOverride, 0.f, 1.f)); }
	UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("UseNormalTexture"), Set.Normal != nullptr, EMaterialParameterAssociation::GlobalParameter, false);
	UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("UseRoughnessTexture"), Set.Roughness != nullptr && RoughnessOverride < 0.f, EMaterialParameterAssociation::GlobalParameter, false);
	UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("UseMetallicTexture"), Set.Metallic != nullptr && MetallicOverride < 0.f, EMaterialParameterAssociation::GlobalParameter, false);
	UMaterialEditingLibrary::UpdateMaterialInstance(Instance);
	Instance->MarkPackageDirty();
	SaveAsset(Instance);
	return Instance;
}

UMaterial* UModellingMaterialsToolset::GetGlassMaterial(FString& OutError)
{
	const TCHAR* AssetName = TEXT("M_ModellingGlass_v2");
	if (UMaterial* Existing = Cast<UMaterial>(FindAsset(ObjectPathIn(MaterialFolder, AssetName))))
	{
		return Existing;
	}
	IAssetTools& AssetTools = FAssetToolsModule::GetModule().Get();
	UMaterialFactoryNew* Factory = NewObject<UMaterialFactoryNew>();
	UMaterial* Material = Cast<UMaterial>(AssetTools.CreateAsset(AssetName, MaterialFolder, UMaterial::StaticClass(), Factory));
	if (!Material)
	{
		OutError = TEXT("Could not create the glass material.");
		return nullptr;
	}
	// A simple tinted transparent sheet. Unlit, so it renders the same in the editor and in the plugin's off-screen captures
	// (lit translucency depends on scene lighting data that captures do not have, and came out black).
	Material->BlendMode = BLEND_Translucent;
	Material->SetShadingModel(MSM_Unlit);
	Material->TwoSided = true;

	FMaterialBuilder B;
	B.Material = Material;
	UMaterialExpressionVectorParameter* Color = B.Vector(TEXT("Color"), FLinearColor::White);
	UMaterialExpressionScalarParameter* Opacity = B.Scalar(TEXT("Opacity"), 0.15f);
	UMaterialExpressionScalarParameter* Brightness = B.Scalar(TEXT("Brightness"), 0.9f);
	B.Scalar(TEXT("Roughness"), 0.05f); // kept so instances share one parameter set with the Megascans glass path
	B.Scalar(TEXT("IOR"), 1.52f);
	UMaterialExpressionMultiply* Glow = B.Multiply(Color, 0, Brightness);
	UMaterialEditingLibrary::ConnectMaterialProperty(Glow, FString(), MP_EmissiveColor);
	UMaterialEditingLibrary::ConnectMaterialProperty(Opacity, FString(), MP_Opacity);
	UMaterialEditingLibrary::RecompileMaterial(Material);
	Material->MarkPackageDirty();
	SaveAsset(Material);
	return Material;
}

FString UModellingMaterialsToolset::GetReferencePalette(const FString& Name, int32 ColorCount, bool bIgnoreBackground, float RegionX, float RegionY, float RegionWidth, float RegionHeight)
{
	const FString Dir = GetReferencesDir();
	if (Name.IsEmpty() || Name != FPaths::GetCleanFilename(Name) || !IsPathUnder(Dir / Name, Dir) || !IFileManager::Get().FileExists(*(Dir / Name)))
	{
		Fail(FString::Printf(TEXT("Reference '%s' not found. Use ListReferences."), *Name));
		return FString();
	}

	TArray<FColor> Pixels;
	FIntPoint Size, Original;
	FString Error;
	if (!LoadImageFile(Dir / Name, 192, Pixels, Size, Original, Error))
	{
		Fail(Error);
		return FString();
	}

	// Region of interest, in pixels.
	const float X0 = FMath::Clamp(RegionX, 0.f, 1.f), Y0 = FMath::Clamp(RegionY, 0.f, 1.f);
	const float X1 = FMath::Clamp(RegionX + RegionWidth, 0.f, 1.f), Y1 = FMath::Clamp(RegionY + RegionHeight, 0.f, 1.f);
	const int32 PX0 = FMath::FloorToInt(X0 * Size.X), PX1 = FMath::Max(PX0 + 1, FMath::CeilToInt(X1 * Size.X));
	const int32 PY0 = FMath::FloorToInt(Y0 * Size.Y), PY1 = FMath::Max(PY0 + 1, FMath::CeilToInt(Y1 * Size.Y));

	// Background estimate: the average of the picture's border pixels.
	FVector Background = FVector::ZeroVector;
	int32 BorderCount = 0;
	for (int32 X = 0; X < Size.X; ++X)
	{
		for (const int32 Y : { 0, Size.Y - 1 })
		{
			const FColor C = Pixels[Y * Size.X + X]; Background += FVector(C.R, C.G, C.B); ++BorderCount;
		}
	}
	for (int32 Y = 1; Y < Size.Y - 1; ++Y)
	{
		for (const int32 X : { 0, Size.X - 1 })
		{
			const FColor C = Pixels[Y * Size.X + X]; Background += FVector(C.R, C.G, C.B); ++BorderCount;
		}
	}
	Background /= FMath::Max(BorderCount, 1);

	TArray<FVector> Samples;
	FVector Sum = FVector::ZeroVector;
	for (int32 Y = PY0; Y < FMath::Min(PY1, Size.Y); ++Y)
	{
		for (int32 X = PX0; X < FMath::Min(PX1, Size.X); ++X)
		{
			const FColor C = Pixels[Y * Size.X + X];
			const FVector V(C.R, C.G, C.B);
			if (bIgnoreBackground && FVector::Dist(V, Background) < 28.0)
			{
				continue;
			}
			Samples.Add(V);
			Sum += V;
		}
	}
	if (Samples.Num() < 8)
	{
		Fail(TEXT("Not enough picture left to analyse. Try bIgnoreBackground=false or a larger region."));
		return FString();
	}

	// Deterministic k-means: start from the mean, then repeatedly add the sample farthest from all centres.
	const int32 K = FMath::Clamp(ColorCount, 2, 8);
	TArray<FVector> Centers;
	Centers.Add(Sum / Samples.Num());
	while (Centers.Num() < K)
	{
		double BestDist = -1.0; FVector Best = Samples[0];
		for (const FVector& S : Samples)
		{
			double Nearest = TNumericLimits<double>::Max();
			for (const FVector& C : Centers) { Nearest = FMath::Min(Nearest, FVector::DistSquared(S, C)); }
			if (Nearest > BestDist) { BestDist = Nearest; Best = S; }
		}
		Centers.Add(Best);
	}
	TArray<int32> Counts;
	for (int32 Iter = 0; Iter < 14; ++Iter)
	{
		TArray<FVector> NewSum; NewSum.Init(FVector::ZeroVector, K);
		Counts.Init(0, K);
		for (const FVector& S : Samples)
		{
			int32 Best = 0; double BestDist = TNumericLimits<double>::Max();
			for (int32 c = 0; c < K; ++c) { const double D = FVector::DistSquared(S, Centers[c]); if (D < BestDist) { BestDist = D; Best = c; } }
			NewSum[Best] += S; ++Counts[Best];
		}
		for (int32 c = 0; c < K; ++c) { if (Counts[c] > 0) { Centers[c] = NewSum[c] / Counts[c]; } }
	}

	TArray<int32> Order; for (int32 c = 0; c < K; ++c) { Order.Add(c); }
	Order.Sort([&Counts](int32 A, int32 B) { return Counts[A] > Counts[B]; });

	TArray<TSharedPtr<FJsonValue>> Colors;
	for (const int32 c : Order)
	{
		const double Percent = 100.0 * Counts[c] / Samples.Num();
		if (Percent < 1.0) { continue; }
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetStringField(TEXT("hex"), ToHex(Centers[c]));
		Item->SetNumberField(TEXT("percent"), FMath::RoundToDouble(Percent * 10.0) / 10.0);
		Colors.Add(MakeShared<FJsonValueObject>(Item));
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("reference"), Name);
	Out->SetArrayField(TEXT("colors"), Colors);
	Out->SetStringField(TEXT("average"), ToHex(Sum / Samples.Num()));
	Out->SetStringField(TEXT("background_estimate"), ToHex(Background));
	Out->SetBoolField(TEXT("background_ignored"), bIgnoreBackground);
	Out->SetNumberField(TEXT("pixels_analysed"), Samples.Num());
	return ToJsonString(Out);
}

FString UModellingMaterialsToolset::CreateColorMaterial(const FString& MaterialName, const FString& Hex, float Roughness, float Metallic, float EmissiveStrength)
{
	FColor Color; FString Error;
	if (!ParseHex(Hex, Color, Error))
	{
		Fail(Error);
		return FString();
	}
	if (MaterialName.TrimStartAndEnd().IsEmpty())
	{
		Fail(TEXT("MaterialName must not be empty."));
		return FString();
	}
	UMaterialInstanceConstant* Instance = GetOrCreateInstance(MaterialName, Color, Roughness, Metallic, EmissiveStrength, Error);
	if (!Instance)
	{
		Fail(Error);
		return FString();
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("material"), AssetPathOf(Instance));
	Out->SetStringField(TEXT("hex"), ToHex(FVector(Color.R, Color.G, Color.B)));
	Out->SetNumberField(TEXT("roughness"), Roughness);
	Out->SetNumberField(TEXT("metallic"), Metallic);
	return ToJsonString(Out);
}

FString UModellingMaterialsToolset::PaintPart(const FString& Name, const FString& Hex, float Roughness, float Metallic, const FString& MaterialName)
{
	FColor Color; FString Error;
	if (!ParseHex(Hex, Color, Error))
	{
		Fail(Error);
		return FString();
	}
	FEditScope Scope(Name, TEXT("Paint Part"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	UMaterialInstanceConstant* Instance = GetOrCreateInstance(MaterialName.IsEmpty() ? DefaultMaterialName(Name, Color) : MaterialName, Color, Roughness, Metallic, 0.f, Error);
	if (!Instance)
	{
		Fail(Error);
		return FString();
	}
	ApplyMaterialToWholePart(Scope.Actor, Scope.Mesh, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), AssetPathOf(Instance));
	return ToJsonString(Out);
}

FString UModellingMaterialsToolset::PaintFaces(const FString& Name, const FModellingSelection& Selection, const FString& Hex, float Roughness, float Metallic, const FString& MaterialName)
{
	FColor Color; FString Error;
	if (!ParseHex(Hex, Color, Error))
	{
		Fail(Error);
		return FString();
	}
	FEditScope Scope(Name, TEXT("Paint Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}
	UMaterialInstanceConstant* Instance = GetOrCreateInstance(MaterialName.IsEmpty() ? DefaultMaterialName(Name, Color) : MaterialName, Color, Roughness, Metallic, 0.f, Error);
	if (!Instance)
	{
		Fail(Error);
		return FString();
	}
	const int32 Slot = ApplyMaterialToSelection(Scope.Actor, Scope.Mesh, Selected, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), AssetPathOf(Instance));
	Out->SetNumberField(TEXT("slot"), Slot);
	return ToJsonString(Out);
}

FString UModellingMaterialsToolset::AssignMaterial(const FString& Name, int32 SlotIndex, const FString& MaterialPath)
{
	if (SlotIndex < 0 || SlotIndex > 63)
	{
		Fail(TEXT("SlotIndex must be between 0 and 63."));
		return FString();
	}
	FString Path = MaterialPath.TrimStartAndEnd();
	if ((!Path.StartsWith(TEXT("/Game/")) && !Path.StartsWith(TEXT("/Engine/"))) || Path.Contains(TEXT("..")))
	{
		Fail(TEXT("MaterialPath must start with /Game/ or /Engine/."));
		return FString();
	}
	if (!Path.Contains(TEXT(".")))
	{
		Path += TEXT(".") + FPackageName::GetShortName(Path);
	}
	UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, *Path);
	if (!Material)
	{
		Fail(FString::Printf(TEXT("No material found at '%s'."), *Path));
		return FString();
	}

	FEditScope Scope(Name, TEXT("Assign Material"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	if (UDynamicMeshComponent* Component = Scope.Actor->GetDynamicMeshComponent())
	{
		TArray<UMaterialInterface*> Slots;
		for (int32 i = 0; i < Component->GetNumMaterials(); ++i) { Slots.Add(Component->GetMaterial(i)); }
		while (Slots.Num() <= SlotIndex) { Slots.Add(nullptr); }
		Slots[SlotIndex] = Material;
		Component->ConfigureMaterialSet(Slots);
	}
	return Scope.Result();
}

FString UModellingMaterialsToolset::ListMaterialSlots(const FString& Name)
{
	ADynamicMeshActor* Actor = FindMeshActor(Name);
	UDynamicMesh* Mesh = GetDynamicMesh(Actor);
	UDynamicMeshComponent* Component = Actor ? Actor->GetDynamicMeshComponent() : nullptr;
	if (!Mesh || !Component)
	{
		Fail(FString::Printf(TEXT("No mesh actor named '%s'."), *Name));
		return FString();
	}

	const TMap<int32, int32> Counts = CountByMaterialId(Mesh);
	int32 SlotCount = Component->GetNumMaterials();
	for (const TPair<int32, int32>& Pair : Counts) { SlotCount = FMath::Max(SlotCount, Pair.Key + 1); }

	TArray<TSharedPtr<FJsonValue>> Slots;
	for (int32 i = 0; i < SlotCount; ++i)
	{
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetNumberField(TEXT("slot"), i);
		const UMaterialInterface* Material = i < Component->GetNumMaterials() ? Component->GetMaterial(i) : nullptr;
		Item->SetStringField(TEXT("material"), Material ? Material->GetPathName() : FString(TEXT("(default)")));
		Item->SetNumberField(TEXT("faces"), Counts.Contains(i) ? Counts[i] : 0);
		Slots.Add(MakeShared<FJsonValueObject>(Item));
	}
	return ToJsonString(Slots);
}


