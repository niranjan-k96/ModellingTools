// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingTextureToolset.h"

#include "ModellingCapture.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingToolsetSettings.h"
#include "ModellingToolsetUtils.h"

#include "AssetImportTask.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "Components/DynamicMeshComponent.h"
#include "DynamicMesh/DynamicMesh3.h"
#include "DynamicMesh/DynamicMeshAttributeSet.h"
#include "DynamicMeshActor.h"
#include "Engine/Texture2D.h"
#include "Factories/TextureFactory.h"
#include "FileHelpers.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
#include "GeometryScript/MeshSelectionFunctions.h"
#include "GeometryScript/MeshUVFunctions.h"
#include "HAL/FileManager.h"
#include "IAssetTools.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInterface.h"
#include "Misc/FileHelper.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"
#include "UObject/Package.h"

using namespace ModellingToolset;

namespace
{
	const TCHAR* TextureAssetFolder = TEXT("/Game/ModellingToolset/Textures");
	constexpr float UvUnitCm = 100.f; // AutoUV: one UV unit per 100 cm, matched by the UV master material's UVUnitCm

	enum class EMapType { Albedo, Normal, Roughness, Metallic, Unknown };

	/** Recognises the "_type" suffix of a texture file name. */
	EMapType TypeFromSuffix(const FString& Suffix)
	{
		const FString S = Suffix.ToLower();
		static const TArray<FString> AlbedoNames = { TEXT("albedo"), TEXT("basecolor"), TEXT("basecolour"), TEXT("base_color"), TEXT("color"), TEXT("colour"), TEXT("diffuse"), TEXT("diff"), TEXT("col"), TEXT("d"), TEXT("bc") };
		static const TArray<FString> NormalNames = { TEXT("normal"), TEXT("nrm"), TEXT("nor"), TEXT("norm"), TEXT("n") };
		static const TArray<FString> RoughNames = { TEXT("roughness"), TEXT("rough"), TEXT("rgh"), TEXT("r") };
		static const TArray<FString> MetalNames = { TEXT("metallic"), TEXT("metal"), TEXT("metalness"), TEXT("met"), TEXT("m") };
		if (AlbedoNames.Contains(S)) { return EMapType::Albedo; }
		if (NormalNames.Contains(S)) { return EMapType::Normal; }
		if (RoughNames.Contains(S)) { return EMapType::Roughness; }
		if (MetalNames.Contains(S)) { return EMapType::Metallic; }
		return EMapType::Unknown;
	}

	const TCHAR* TypeName(EMapType T)
	{
		switch (T)
		{
		case EMapType::Albedo: return TEXT("Albedo");
		case EMapType::Normal: return TEXT("Normal");
		case EMapType::Roughness: return TEXT("Roughness");
		case EMapType::Metallic: return TEXT("Metallic");
		default: return TEXT("Unknown");
		}
	}

	struct FSetFiles
	{
		FString Name;
		TMap<EMapType, FString> Files; // full paths
		float TileCm = 0.f;
		FString Notes;
	};

	bool IsImageFile(const FString& File)
	{
		const FString Ext = FPaths::GetExtension(File).ToLower();
		return Ext == TEXT("png") || Ext == TEXT("jpg") || Ext == TEXT("jpeg") || Ext == TEXT("tga") || Ext == TEXT("bmp");
	}

	/** Scans the textures folder and groups files into sets. */
	TArray<FSetFiles> ScanTextureSets()
	{
		EnsureWorkspaceFolders();
		const FString Dir = GetTexturesDir();
		TArray<FString> Files;
		IFileManager::Get().FindFiles(Files, *(Dir / TEXT("*.*")), /*Files=*/true, /*Directories=*/false);
		Files.Sort();

		TMap<FString, FSetFiles> Sets;
		for (const FString& File : Files)
		{
			if (!IsImageFile(File)) { continue; }
			const FString Base = FPaths::GetBaseFilename(File);
			FString SetName = Base;
			EMapType Type = EMapType::Albedo;
			int32 Underscore;
			if (Base.FindLastChar(TEXT('_'), Underscore) && Underscore > 0)
			{
				const EMapType Found = TypeFromSuffix(Base.Mid(Underscore + 1));
				if (Found != EMapType::Unknown)
				{
					Type = Found;
					SetName = Base.Left(Underscore);
				}
			}
			FSetFiles& Set = Sets.FindOrAdd(SetName.ToLower());
			Set.Name = SetName;
			if (!Set.Files.Contains(Type)) { Set.Files.Add(Type, Dir / File); }
		}

		TArray<FSetFiles> Out;
		Sets.GenerateValueArray(Out);
		for (FSetFiles& Set : Out)
		{
			for (const TCHAR* Ext : { TEXT("txt"), TEXT("md") })
			{
				FString Text;
				const FString NotesPath = Dir / (Set.Name + TEXT(".") + Ext);
				if (IFileManager::Get().FileExists(*NotesPath) && FFileHelper::LoadFileToString(Text, *NotesPath))
				{
					Set.Notes = Text;
					TArray<FString> Lines;
					Text.ParseIntoArrayLines(Lines);
					for (const FString& Line : Lines)
					{
						FString Key, Value;
						if (Line.Split(TEXT(":"), &Key, &Value) && Key.TrimStartAndEnd().ToLower().StartsWith(TEXT("tile")))
						{
							Set.TileCm = FCString::Atof(*Value.TrimStartAndEnd());
						}
					}
					break;
				}
			}
		}
		Out.Sort([](const FSetFiles& A, const FSetFiles& B) { return A.Name < B.Name; });
		return Out;
	}

	FString TextureAssetName(const FString& SetName, EMapType Type)
	{
		return FString::Printf(TEXT("T_%s_%s"), *SanitizeFileName(SetName), TypeName(Type));
	}

	UTexture2D* FindTextureAsset(const FString& SetName, EMapType Type)
	{
		const FString AssetName = TextureAssetName(SetName, Type);
		const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), TextureAssetFolder, *AssetName, *AssetName);
		if (UTexture2D* Loaded = FindObject<UTexture2D>(nullptr, *ObjectPath)) { return Loaded; }
		const FAssetData Data = FAssetRegistryModule::GetRegistry().GetAssetByObjectPath(FSoftObjectPath(ObjectPath));
		return Data.IsValid() ? Cast<UTexture2D>(Data.GetAsset()) : nullptr;
	}

	/** Imports one image as a texture asset with the right settings for its type. */
	UTexture2D* ImportTexture(const FString& FilePath, const FString& SetName, EMapType Type, bool bReimport, FString& Error)
	{
		if (!bReimport)
		{
			if (UTexture2D* Existing = FindTextureAsset(SetName, Type)) { return Existing; }
		}

		UTextureFactory* Factory = NewObject<UTextureFactory>();
		Factory->SuppressImportOverwriteDialog();
		if (Type == EMapType::Normal)
		{
			Factory->CompressionSettings = TC_Normalmap;
			Factory->LODGroup = TEXTUREGROUP_WorldNormalMap;
		}

		UAssetImportTask* Task = NewObject<UAssetImportTask>();
		Task->AddToRoot();
		Task->Filename = FilePath;
		Task->DestinationPath = TextureAssetFolder;
		Task->DestinationName = TextureAssetName(SetName, Type);
		Task->bAutomated = true;
		Task->bReplaceExisting = true;
		Task->bSave = false;
		Task->Factory = Factory;
		FAssetToolsModule::GetModule().Get().ImportAssetTasks({ Task });
		UTexture2D* Texture = Task->GetObjects().Num() > 0 ? Cast<UTexture2D>(Task->GetObjects()[0]) : nullptr;
		Task->RemoveFromRoot();
		if (!Texture)
		{
			Error = FString::Printf(TEXT("Could not import '%s'. Is it a valid image file?"), *FPaths::GetCleanFilename(FilePath));
			return nullptr;
		}

		// Colour textures are sRGB; data textures (normal, roughness, metallic) must not be colour-corrected.
		switch (Type)
		{
		case EMapType::Albedo:
			Texture->SRGB = true;
			Texture->CompressionSettings = TC_Default;
			break;
		case EMapType::Normal:
			Texture->SRGB = false;
			Texture->CompressionSettings = TC_Normalmap;
			Texture->LODGroup = TEXTUREGROUP_WorldNormalMap;
			break;
		default:
			Texture->SRGB = false;
			Texture->CompressionSettings = TC_Default;
			break;
		}
		Texture->UpdateResource();
		Texture->PostEditChange();
		Texture->MarkPackageDirty();
		UEditorLoadingAndSavingUtils::SavePackages({ Texture->GetOutermost() }, /*bOnlyDirty=*/false);
		return Texture;
	}

	bool LoadSet(const FString& SetName, bool bReimport, UModellingMaterialsToolset::FTextureSet& Out, float& OutTileCm, FString& Error)
	{
		const TArray<FSetFiles> Sets = ScanTextureSets();
		const FSetFiles* Found = Sets.FindByPredicate([&SetName](const FSetFiles& S) { return S.Name.Equals(SetName, ESearchCase::IgnoreCase); });
		if (!Found)
		{
			TArray<FString> Names;
			for (const FSetFiles& S : Sets) { Names.Add(S.Name); }
			Error = FString::Printf(TEXT("No texture set named '%s' in %s. Available: %s. Ask the user to add '%s_albedo.png' there."),
				*SetName, *GetTexturesDir(), Names.IsEmpty() ? TEXT("(none)") : *FString::Join(Names, TEXT(", ")), *SetName);
			return false;
		}
		if (!Found->Files.Contains(EMapType::Albedo))
		{
			Error = FString::Printf(TEXT("Texture set '%s' has no albedo (colour) image. Ask the user to add '%s_albedo.png'."), *Found->Name, *Found->Name);
			return false;
		}
		Out.Name = Found->Name;
		Out.Albedo = ImportTexture(Found->Files[EMapType::Albedo], Found->Name, EMapType::Albedo, bReimport, Error);
		if (!Out.Albedo) { return false; }
		if (const FString* F = Found->Files.Find(EMapType::Normal)) { Out.Normal = ImportTexture(*F, Found->Name, EMapType::Normal, bReimport, Error); }
		if (const FString* F = Found->Files.Find(EMapType::Roughness)) { Out.Roughness = ImportTexture(*F, Found->Name, EMapType::Roughness, bReimport, Error); }
		if (const FString* F = Found->Files.Find(EMapType::Metallic)) { Out.Metallic = ImportTexture(*F, Found->Name, EMapType::Metallic, bReimport, Error); }
		OutTileCm = Found->TileCm;
		return true;
	}

	bool ParseTint(const FString& Hex, FLinearColor& Out, FString& Error)
	{
		Out = FLinearColor::White;
		if (Hex.TrimStartAndEnd().IsEmpty()) { return true; }
		FString H = Hex.TrimStartAndEnd();
		H.RemoveFromStart(TEXT("#"));
		if (H.Len() != 6) { Error = TEXT("TintHex must be a colour like #D8C8B0."); return false; }
		for (const TCHAR C : H) { if (!FChar::IsHexDigit(C)) { Error = TEXT("TintHex must be a colour like #D8C8B0."); return false; } }
		Out = FLinearColor::FromSRGBColor(FColor::FromHex(H));
		Out.A = 1.f;
		return true;
	}

	/** Resolves a set to a saved material instance with the requested settings. */
	UMaterialInstanceConstant* MaterialForSet(const FString& SetName, float TileCm, bool bWorldAligned, const FString& TintHex, float Roughness, float Metallic, FString& Error)
	{
		UModellingMaterialsToolset::FTextureSet Set;
		float SetTile = 0.f;
		if (!LoadSet(SetName, false, Set, SetTile, Error)) { return nullptr; }
		FLinearColor Tint;
		if (!ParseTint(TintHex, Tint, Error)) { return nullptr; }
		const float UseTile = TileCm > 0.f ? TileCm : (SetTile > 0.f ? SetTile : GetDefault<UModellingToolsetSettings>()->DefaultTileCm);
		return UModellingMaterialsToolset::GetOrCreateTexturedInstance(Set, UseTile, bWorldAligned, Tint, Roughness, Metallic, Error);
	}

	FString GuessCategory(const FString& Name)
	{
		const FString N = Name.ToLower();
		struct FKey { const TCHAR* Word; const TCHAR* Category; };
		static const FKey Keys[] = {
			{ TEXT("brick"), TEXT("brick") }, { TEXT("wood"), TEXT("wood") }, { TEXT("plank"), TEXT("wood") }, { TEXT("oak"), TEXT("wood") },
			{ TEXT("metal"), TEXT("metal") }, { TEXT("steel"), TEXT("metal") }, { TEXT("iron"), TEXT("metal") }, { TEXT("copper"), TEXT("metal") }, { TEXT("gold"), TEXT("metal") },
			{ TEXT("stone"), TEXT("stone") }, { TEXT("rock"), TEXT("stone") }, { TEXT("marble"), TEXT("stone") }, { TEXT("granite"), TEXT("stone") }, { TEXT("cobble"), TEXT("stone") },
			{ TEXT("concrete"), TEXT("concrete") }, { TEXT("cement"), TEXT("concrete") }, { TEXT("plaster"), TEXT("plaster") }, { TEXT("stucco"), TEXT("plaster") },
			{ TEXT("glass"), TEXT("glass") }, { TEXT("window"), TEXT("glass") }, { TEXT("tile"), TEXT("tile") }, { TEXT("roof"), TEXT("roof") }, { TEXT("shingle"), TEXT("roof") },
			{ TEXT("fabric"), TEXT("fabric") }, { TEXT("cloth"), TEXT("fabric") }, { TEXT("leather"), TEXT("fabric") }, { TEXT("grass"), TEXT("ground") }, { TEXT("dirt"), TEXT("ground") },
			{ TEXT("sand"), TEXT("ground") }, { TEXT("ground"), TEXT("ground") }, { TEXT("water"), TEXT("water") }, { TEXT("paint"), TEXT("paint") }, { TEXT("plastic"), TEXT("plastic") } };
		for (const FKey& K : Keys) { if (N.Contains(K.Word)) { return K.Category; } }
		return TEXT("other");
	}

	FString FindTilingParameter(UMaterialInterface* Material)
	{
		TArray<FMaterialParameterInfo> Infos;
		TArray<FGuid> Ids;
		Material->GetAllScalarParameterInfo(Infos, Ids);
		for (const FMaterialParameterInfo& Info : Infos)
		{
			const FString N = Info.Name.ToString().ToLower();
			if (N.Contains(TEXT("til")) || N.Contains(TEXT("uvscale")) || N.Contains(TEXT("uv_scale")) || N.Contains(TEXT("texturescale")) || N == TEXT("scale"))
			{
				return Info.Name.ToString();
			}
		}
		return FString();
	}

	UMaterialInterface* LoadLibraryMaterial(const FString& MaterialPath, FString& Error)
	{
		FString Path = MaterialPath.TrimStartAndEnd();
		if ((!Path.StartsWith(TEXT("/Game/")) && !Path.StartsWith(TEXT("/Engine/"))) || Path.Contains(TEXT("..")))
		{
			Error = TEXT("MaterialPath must start with /Game/ or /Engine/.");
			return nullptr;
		}
		if (!Path.Contains(TEXT("."))) { Path += TEXT(".") + FPackageName::GetShortName(Path); }
		UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, *Path);
		if (!Material) { Error = FString::Printf(TEXT("No material found at '%s'. Use ListLibraryMaterials."), *Path); }
		return Material;
	}

	TSharedRef<FJsonObject> VecJson(const FVector& V)
	{
		TSharedRef<FJsonObject> O = MakeShared<FJsonObject>();
		O->SetNumberField(TEXT("x"), FMath::RoundToDouble(V.X * 10.0) / 10.0);
		O->SetNumberField(TEXT("y"), FMath::RoundToDouble(V.Y * 10.0) / 10.0);
		O->SetNumberField(TEXT("z"), FMath::RoundToDouble(V.Z * 10.0) / 10.0);
		return O;
	}
}

FString UModellingTextureToolset::ListTextureSets()
{
	const TArray<FSetFiles> Sets = ScanTextureSets();
	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FSetFiles& Set : Sets)
	{
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetStringField(TEXT("name"), Set.Name);
		Item->SetBoolField(TEXT("has_albedo"), Set.Files.Contains(EMapType::Albedo));
		Item->SetBoolField(TEXT("has_normal"), Set.Files.Contains(EMapType::Normal));
		Item->SetBoolField(TEXT("has_roughness"), Set.Files.Contains(EMapType::Roughness));
		Item->SetBoolField(TEXT("has_metallic"), Set.Files.Contains(EMapType::Metallic));
		Item->SetNumberField(TEXT("tile_cm"), Set.TileCm > 0.f ? Set.TileCm : GetDefault<UModellingToolsetSettings>()->DefaultTileCm);
		Item->SetBoolField(TEXT("tile_cm_from_notes"), Set.TileCm > 0.f);
		Item->SetStringField(TEXT("notes"), Set.Notes);
		Item->SetBoolField(TEXT("imported"), FindTextureAsset(Set.Name, EMapType::Albedo) != nullptr);
		Items.Add(MakeShared<FJsonValueObject>(Item));
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("textures_folder"), GetTexturesDir());
	Out->SetArrayField(TEXT("sets"), Items);
	Out->SetStringField(TEXT("naming_rule"), TEXT("Files are grouped by name: <Set>_albedo.png (required), <Set>_normal.png, <Set>_roughness.png, <Set>_metallic.png. An optional <Set>.txt may contain 'tile_cm: 60' and a description. png, jpg, tga and bmp are accepted."));
	return ToJsonString(Out);
}

FString UModellingTextureToolset::ImportTextureSets(bool bReimport)
{
	const TArray<FSetFiles> Sets = ScanTextureSets();
	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FSetFiles& Set : Sets)
	{
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetStringField(TEXT("name"), Set.Name);
		UModellingMaterialsToolset::FTextureSet Loaded;
		float Tile = 0.f;
		FString Error;
		const bool bOk = LoadSet(Set.Name, bReimport, Loaded, Tile, Error);
		Item->SetBoolField(TEXT("ok"), bOk);
		if (!bOk) { Item->SetStringField(TEXT("error"), Error); }
		Items.Add(MakeShared<FJsonValueObject>(Item));
	}
	return ToJsonString(Items);
}

FString UModellingTextureToolset::ApplyTexturePart(const FString& Name, const FString& SetName, float TileCm, bool bWorldAligned, const FString& TintHex, float Roughness, float Metallic)
{
	FEditScope Scope(Name, TEXT("Apply Texture"));
	if (!Scope.IsValid())
	{
		return FString();
	}
	FString Error;
	UMaterialInstanceConstant* Instance = MaterialForSet(SetName, TileCm, bWorldAligned, TintHex, Roughness, Metallic, Error);
	if (!Instance)
	{
		Fail(Error);
		return FString();
	}
	ApplyMaterialToWholePart(Scope.Actor, Scope.Mesh, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), Instance->GetPathName());
	Out->SetBoolField(TEXT("world_aligned"), bWorldAligned);
	if (!bWorldAligned) { Out->SetStringField(TEXT("note"), TEXT("UV mode: run AutoUV on this part if you have not, or the texture may stretch.")); }
	return ToJsonString(Out);
}

FString UModellingTextureToolset::ApplyTextureFaces(const FString& Name, const FModellingSelection& Selection, const FString& SetName, float TileCm, bool bWorldAligned, const FString& TintHex, float Roughness, float Metallic)
{
	FEditScope Scope(Name, TEXT("Apply Texture To Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}
	FString Error;
	UMaterialInstanceConstant* Instance = MaterialForSet(SetName, TileCm, bWorldAligned, TintHex, Roughness, Metallic, Error);
	if (!Instance)
	{
		Fail(Error);
		return FString();
	}
	const int32 Slot = ApplyMaterialToSelection(Scope.Actor, Scope.Mesh, Selected, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), Instance->GetPathName());
	Out->SetNumberField(TEXT("slot"), Slot);
	Out->SetBoolField(TEXT("world_aligned"), bWorldAligned);
	return ToJsonString(Out);
}

FString UModellingTextureToolset::ListLibraryMaterials(const FString& Filter)
{
	const FString Folder = GetDefault<UModellingToolsetSettings>()->MaterialLibraryFolder.TrimStartAndEnd();
	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("library_folder"), Folder);
	if (!Folder.StartsWith(TEXT("/Game/")))
	{
		Out->SetArrayField(TEXT("materials"), {});
		Out->SetStringField(TEXT("note"), TEXT("The material library folder (Project Settings > Plugins > Modelling Toolset) must be under /Game/."));
		return ToJsonString(Out);
	}

	IAssetRegistry& Registry = FAssetRegistryModule::GetRegistry();
	TArray<FAssetData> Assets;
	Registry.GetAssetsByPath(FName(*Folder), Assets, /*bRecursive=*/true);
	const FString Needle = Filter.TrimStartAndEnd().ToLower();

	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FAssetData& Asset : Assets)
	{
		const FTopLevelAssetPath Class = Asset.AssetClassPath;
		if (Class != UMaterial::StaticClass()->GetClassPathName() && Class != UMaterialInstanceConstant::StaticClass()->GetClassPathName()) { continue; }
		const FString AssetName = Asset.AssetName.ToString();
		if (!Needle.IsEmpty() && !AssetName.ToLower().Contains(Needle)) { continue; }
		if (Asset.PackagePath.ToString().StartsWith(TEXT("/Game/ModellingToolset/"))) { continue; } // the plugin's own generated materials

		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetStringField(TEXT("name"), AssetName);
		Item->SetStringField(TEXT("path"), Asset.GetObjectPathString());
		Item->SetStringField(TEXT("category"), GuessCategory(AssetName));
		Items.Add(MakeShared<FJsonValueObject>(Item));
		if (Items.Num() >= 300) { break; }
	}
	Out->SetArrayField(TEXT("materials"), Items);
	Out->SetNumberField(TEXT("count"), Items.Num());
	if (Items.IsEmpty())
	{
		Out->SetStringField(TEXT("note"), TEXT("No materials found. Ask the user to copy a materials folder into the project and set its path in the plugin settings, or use a texture set from ListTextureSets."));
	}
	return ToJsonString(Out);
}

FString UModellingTextureToolset::ApplyLibraryMaterial(const FString& Name, const FString& MaterialPath, const FModellingSelection& Selection)
{
	FString Error;
	UMaterialInterface* Material = LoadLibraryMaterial(MaterialPath, Error);
	if (!Material)
	{
		Fail(Error);
		return FString();
	}
	FEditScope Scope(Name, TEXT("Apply Library Material"));
	if (!Scope.IsValid())
	{
		return FString();
	}

	int32 Slot = 0;
	if (Selection.Mode.IsEmpty() || Selection.Mode.ToLower() == TEXT("all"))
	{
		ApplyMaterialToWholePart(Scope.Actor, Scope.Mesh, Material);
	}
	else
	{
		FGeometryScriptMeshSelection Selected;
		if (!BuildSelection(Scope.Mesh, Selection, Selected)) { return FString(); }
		Slot = ApplyMaterialToSelection(Scope.Actor, Scope.Mesh, Selected, Material);
	}

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), Material->GetPathName());
	Out->SetNumberField(TEXT("slot"), Slot);
	const FString Tiling = FindTilingParameter(Material);
	Out->SetStringField(TEXT("tiling_parameter"), Tiling);
	Out->SetStringField(TEXT("note"), TEXT("Library materials follow the part's UV map. Run AutoUV on the part (if not done) so the texture does not stretch, then check with CaptureViews."));
	return ToJsonString(Out);
}

FModellingCapture UModellingTextureToolset::PreviewMaterial(const FString& SetName, const FString& MaterialPath, float TileCm)
{
	FModellingCapture Out;
	UWorld* World = GetEditorWorld();
	if (!World)
	{
		Fail(TEXT("No editor world is available."));
		return Out;
	}

	FString Error;
	UMaterialInterface* Material = nullptr;
	FString Label;
	if (!SetName.TrimStartAndEnd().IsEmpty())
	{
		Material = MaterialForSet(SetName, TileCm, true, FString(), -1.f, -1.f, Error);
		Label = TEXT("preview_") + SanitizeFileName(SetName);
	}
	else if (!MaterialPath.TrimStartAndEnd().IsEmpty())
	{
		Material = LoadLibraryMaterial(MaterialPath, Error);
		Label = TEXT("preview_") + SanitizeFileName(FPackageName::GetShortName(MaterialPath));
	}
	else
	{
		Error = TEXT("Give a SetName or a MaterialPath.");
	}
	if (!Material)
	{
		Fail(Error);
		return Out;
	}

	if (!RenderMaterialPreview(Material, Label, Out, Error))
	{
		Fail(Error);
	}
	return Out;
}

bool UModellingTextureToolset::RenderMaterialPreview(UMaterialInterface* Material, const FString& Label, FModellingCapture& Out, FString& Error)
{
	UWorld* World = GetEditorWorld();
	if (!World || !Material)
	{
		Error = TEXT("No editor world or material.");
		return false;
	}
	// A temporary sphere and cube, far from the model, textured and photographed, then removed.
	FActorSpawnParameters Params;
	Params.ObjectFlags = RF_Transient;
	Params.bTemporaryEditorActor = true;
	ADynamicMeshActor* Preview = World->SpawnActor<ADynamicMeshActor>(FVector(0, 0, 50000), FRotator::ZeroRotator, Params);
	if (!Preview || !GetDynamicMesh(Preview))
	{
		Error = TEXT("Could not create the preview shapes.");
		return false;
	}
	ON_SCOPE_EXIT { World->DestroyActor(Preview); };

	UDynamicMesh* Mesh = GetDynamicMesh(Preview);
	FGeometryScriptPrimitiveOptions Options;
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSphereLatLong(Mesh, Options, FTransform(FVector(-60, 0, 50)), 50.f, 24, 48, EGeometryScriptPrimitiveOriginMode::Center);
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(Mesh, Options, FTransform(FVector(60, 0, 50)), 100.f, 100.f, 100.f, 0, 0, 0, EGeometryScriptPrimitiveOriginMode::Center);
	ApplyBoxUVs(Mesh); // world-scale UVs so UV-based materials preview at their real tile size too
	ApplyMaterialToWholePart(Preview, Mesh, Material);

	FCaptureRequest Request;
	Request.ExplicitTargets = { Preview };
	Request.Views = TEXT("iso");
	Request.ViewMode = TEXT("lit");
	Request.Resolution = 384;
	Request.bIsolate = true;
	Request.Label = Label;
	Request.bSetReviewImage = false;
	const FCaptureResult Result = CaptureViews(Request);
	if (!Result.bOk)
	{
		Error = Result.Error;
		return false;
	}
	Out.Image.SetFromBitmap(Result.Sheet, Result.SheetSize);
	Out.Summary = Result.SummaryJson;
	return true;
}

FString UModellingTextureToolset::AutoUV(const FString& Name, const FString& Method, const FModellingSelection& Selection)
{
	const FString M = Method.TrimStartAndEnd().ToLower();
	if (M != TEXT("box") && M != TEXT("cylinder") && M != TEXT("unwrap"))
	{
		Fail(TEXT("Method must be 'box', 'cylinder' or 'unwrap'."));
		return FString();
	}
	FEditScope Scope(Name, TEXT("Auto UV"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected))
	{
		return FString();
	}

	UGeometryScriptLibrary_MeshUVFunctions::SetNumUVSets(Scope.Mesh, 1);
	const FTransform Unit(FQuat::Identity, FVector::ZeroVector, FVector(UvUnitCm));
	if (M == TEXT("box"))
	{
		UGeometryScriptLibrary_MeshUVFunctions::SetMeshUVsFromBoxProjection(Scope.Mesh, 0, Unit, Selected, 2);
	}
	else if (M == TEXT("cylinder"))
	{
		// Put the projection axis through the middle of the selected faces.
		FBox Bounds(ForceInit);
		Scope.Mesh->ProcessMesh([&Bounds](const UE::Geometry::FDynamicMesh3& Mesh)
		{
			if (Mesh.TriangleCount() > 0) { const UE::Geometry::FAxisAlignedBox3d B = Mesh.GetBounds(); Bounds = FBox(FVector(B.Min), FVector(B.Max)); }
		});
		const FVector Axis(Bounds.GetCenter().X, Bounds.GetCenter().Y, 0.0);
		UGeometryScriptLibrary_MeshUVFunctions::SetMeshUVsFromCylinderProjection(Scope.Mesh, 0, FTransform(FQuat::Identity, Axis, FVector(UvUnitCm)), Selected, 45.f);

		// The engine wraps the texture exactly once around the cylinder whatever its size. Measure how far the side faces are
		// from "one tile per 100 cm" along each texture axis and correct them, so a 50 cm pipe and a 5 m tower tile the same.
		TArray<int32> SideFaces;
		double SumU = 0.0, SumV = 0.0, SumArea = 0.0;
		Scope.Mesh->ProcessMesh([&](const UE::Geometry::FDynamicMesh3& Mesh)
		{
			const UE::Geometry::FDynamicMeshUVOverlay* UV = Mesh.Attributes()->PrimaryUV();
			for (const int32 Tid : Mesh.TriangleIndicesItr())
			{
				if (!UV->IsSetTriangle(Tid) || FMath::Abs(Mesh.GetTriNormal(Tid).Z) > 0.5) { continue; }
				FVector3d P0, P1, P2;
				Mesh.GetTriVertices(Tid, P0, P1, P2);
				const UE::Geometry::FIndex3i E = UV->GetTriangle(Tid);
				const FVector2d Q0(UV->GetElement(E.A)), Q1(UV->GetElement(E.B)), Q2(UV->GetElement(E.C));
				const FVector2d B1 = (Q1 - Q0) * UvUnitCm, B2 = (Q2 - Q0) * UvUnitCm;
				const double Det = B1.X * B2.Y - B1.Y * B2.X;
				const double Area = 0.5 * ((P1 - P0).Cross(P2 - P0)).Length();
				if (FMath::Abs(Det) < 1e-9 || Area <= 0.0) { continue; }
				// 3D change per texture-centimetre along U and along V.
				const FVector3d DU = ((P1 - P0) * B2.Y - (P2 - P0) * B1.Y) / Det;
				const FVector3d DV = ((P2 - P0) * B1.X - (P1 - P0) * B2.X) / Det;
				SumU += DU.Length() * Area;
				SumV += DV.Length() * Area;
				SumArea += Area;
				SideFaces.Add(Tid);
			}
		});
		if (SumArea > 0.0 && !SideFaces.IsEmpty())
		{
			const double ScaleU = SumU / SumArea, ScaleV = SumV / SumArea;
			if (FMath::Abs(ScaleU - 1.0) > 0.02 || FMath::Abs(ScaleV - 1.0) > 0.02)
			{
				FGeometryScriptMeshSelection Sides;
				UGeometryScriptLibrary_MeshSelectionFunctions::ConvertIndexArrayToMeshSelection(Scope.Mesh, SideFaces, EGeometryScriptMeshSelectionType::Triangles, Sides);
				UGeometryScriptLibrary_MeshUVFunctions::ScaleMeshUVs(Scope.Mesh, 0, FVector2D(ScaleU, ScaleV), FVector2D::ZeroVector, Sides);
			}
		}
	}
	else
	{
		FGeometryScriptPatchBuilderOptions Options;
		UGeometryScriptLibrary_MeshUVFunctions::AutoGeneratePatchBuilderMeshUVs(Scope.Mesh, 0, Options);
		FGeometryScriptUVTexelDensityOptions Density;
		Density.TexelDensityMode = EGeometryScriptTexelDensityMode::ApplyToIslands;
		Density.TargetWorldUnits = UvUnitCm;
		Density.TargetPixelCount = 1024.f;
		Density.TextureResolution = 1024.f;
		UGeometryScriptLibrary_MeshUVFunctions::ApplyTexelDensityUVScaling(Scope.Mesh, 0, Density, Selected);
	}

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("method"), M);
	Out->SetNumberField(TEXT("uv_unit_cm"), UvUnitCm);
	Out->SetStringField(TEXT("note"), TEXT("One UV unit is 100 cm of surface. Use CheckTextureStretch to confirm, and re-run with another method on faces that stretch."));
	return ToJsonString(Out);
}

FString UModellingTextureToolset::CheckTextureStretch(const FString& Name)
{
	ADynamicMeshActor* Actor = FindMeshActor(Name);
	UDynamicMesh* Mesh = GetDynamicMesh(Actor);
	if (!Mesh)
	{
		Fail(FString::Printf(TEXT("No mesh actor named '%s'."), *Name));
		return FString();
	}

	struct FFace { int32 Tid; FVector Centre; double Scale; double Stretch; };
	TArray<FFace> Faces;
	int32 Missing = 0, Total = 0;
	double AreaTotal = 0.0, AreaBadScale = 0.0, AreaBadStretch = 0.0;

	Mesh->ProcessMesh([&](const UE::Geometry::FDynamicMesh3& M)
	{
		const UE::Geometry::FDynamicMeshUVOverlay* UV = (M.HasAttributes() && M.Attributes()->NumUVLayers() > 0) ? M.Attributes()->PrimaryUV() : nullptr;
		for (const int32 Tid : M.TriangleIndicesItr())
		{
			++Total;
			FVector3d P0, P1, P2;
			M.GetTriVertices(Tid, P0, P1, P2);
			const double Area = 0.5 * ((P1 - P0).Cross(P2 - P0)).Length();
			if (Area <= UE_DOUBLE_KINDA_SMALL_NUMBER) { continue; }
			AreaTotal += Area;
			if (!UV || !UV->IsSetTriangle(Tid)) { ++Missing; AreaBadScale += Area; continue; }

			const UE::Geometry::FIndex3i E = UV->GetTriangle(Tid);
			const FVector2d Q0(UV->GetElement(E.A)), Q1(UV->GetElement(E.B)), Q2(UV->GetElement(E.C));
			// Lay the 3D triangle flat: U along the first edge, V perpendicular.
			const FVector3d E1 = P1 - P0, E2 = P2 - P0;
			const FVector3d U = E1.GetSafeNormal();
			const FVector3d N = E1.Cross(E2).GetSafeNormal();
			const FVector3d V = N.Cross(U);
			const FVector2d A1(E1.Length(), 0.0), A2(E2.Dot(U), E2.Dot(V));
			// UV edges in centimetres (one UV unit = 100 cm).
			const FVector2d B1 = (Q1 - Q0) * UvUnitCm, B2 = (Q2 - Q0) * UvUnitCm;
			const double Det = B1.X * B2.Y - B1.Y * B2.X;
			if (FMath::Abs(Det) < 1e-9) { ++Missing; AreaBadScale += Area; continue; }
			// Map T from UV space to the flat 3D triangle: [A1 A2] = T [B1 B2]  =>  T = [A1 A2] * inverse([B1 B2]).
			const double Inv[2][2] = { { B2.Y / Det, -B2.X / Det }, { -B1.Y / Det, B1.X / Det } };
			const double T00 = A1.X * Inv[0][0] + A2.X * Inv[1][0], T01 = A1.X * Inv[0][1] + A2.X * Inv[1][1];
			const double T10 = A1.Y * Inv[0][0] + A2.Y * Inv[1][0], T11 = A1.Y * Inv[0][1] + A2.Y * Inv[1][1];
			// Singular values of T: how much the texture is scaled along its two axes on this face.
			const double S = T00 * T00 + T01 * T01 + T10 * T10 + T11 * T11;
			const double D = FMath::Abs(T00 * T11 - T01 * T10);
			const double Root = FMath::Sqrt(FMath::Max(S * S - 4.0 * D * D, 0.0));
			const double Smax = FMath::Sqrt((S + Root) * 0.5), Smin = FMath::Sqrt(FMath::Max((S - Root) * 0.5, 1e-12));
			const double Scale = FMath::Sqrt(Smax * Smin); // 1 = exactly one tile per 100 cm
			const double Stretch = Smax / Smin;             // 1 = no distortion

			if (Scale < 0.8 || Scale > 1.25) { AreaBadScale += Area; }
			if (Stretch > 1.5) { AreaBadStretch += Area; }
			Faces.Add({ Tid, FVector((P0 + P1 + P2) / 3.0), Scale, Stretch });
		}
	});

	if (Total == 0)
	{
		Fail(TEXT("The part has no geometry."));
		return FString();
	}

	const double BadScalePercent = AreaTotal > 0 ? 100.0 * AreaBadScale / AreaTotal : 0.0;
	const double BadStretchPercent = AreaTotal > 0 ? 100.0 * AreaBadStretch / AreaTotal : 0.0;
	const double WorstPercent = FMath::Max(BadScalePercent, BadStretchPercent);
	FString Verdict;
	if (Missing == Total) { Verdict = TEXT("No texture layout at all. Run AutoUV."); }
	else if (WorstPercent < 3.0) { Verdict = TEXT("Good. Textures will not stretch."); }
	else if (WorstPercent < 15.0) { Verdict = TEXT("Mostly fine. A few areas stretch; see worst_spots."); }
	else { Verdict = TEXT("Textures will stretch noticeably. Run AutoUV (try another method) on the listed areas, or use world-aligned textures."); }

	// Worst faces by distortion, largest first.
	Faces.Sort([](const FFace& A, const FFace& B) { return FMath::Max(A.Stretch, FMath::Max(A.Scale, 1.0 / A.Scale)) > FMath::Max(B.Stretch, FMath::Max(B.Scale, 1.0 / B.Scale)); });
	TArray<TSharedPtr<FJsonValue>> Worst;
	for (int32 i = 0; i < FMath::Min(5, Faces.Num()); ++i)
	{
		const FFace& F = Faces[i];
		if (F.Stretch < 1.5 && F.Scale > 0.8 && F.Scale < 1.25) { break; }
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetObjectField(TEXT("center_local_cm"), VecJson(F.Centre));
		Item->SetNumberField(TEXT("tile_scale"), FMath::RoundToDouble(F.Scale * 100.0) / 100.0);
		Item->SetNumberField(TEXT("stretch_ratio"), FMath::RoundToDouble(F.Stretch * 100.0) / 100.0);
		Worst.Add(MakeShared<FJsonValueObject>(Item));
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("actor"), Actor->GetActorLabel());
	Out->SetStringField(TEXT("verdict"), Verdict);
	Out->SetNumberField(TEXT("faces"), Total);
	Out->SetNumberField(TEXT("faces_without_layout"), Missing);
	Out->SetNumberField(TEXT("percent_area_wrong_tile_size"), FMath::RoundToDouble(BadScalePercent * 10.0) / 10.0);
	Out->SetNumberField(TEXT("percent_area_stretched"), FMath::RoundToDouble(BadStretchPercent * 10.0) / 10.0);
	Out->SetArrayField(TEXT("worst_spots"), Worst);
	Out->SetStringField(TEXT("meaning"), TEXT("tile_scale 1 = one tile per 100 cm as intended (2 = tiles twice too big). stretch_ratio 1 = no distortion (2 = squashed to half width)."));
	return ToJsonString(Out);
}

void UModellingTextureToolset::MeasureUVQuality(UDynamicMesh* Mesh, double& OutWrongTilePercent, double& OutStretchedPercent, int32& OutFacesWithoutLayout, int32& OutFaces)
{
	OutWrongTilePercent = 0.0; OutStretchedPercent = 0.0; OutFacesWithoutLayout = 0; OutFaces = 0;
	if (!Mesh) { return; }
	double AreaTotal = 0.0, AreaBadScale = 0.0, AreaBadStretch = 0.0;
	Mesh->ProcessMesh([&](const UE::Geometry::FDynamicMesh3& M)
	{
		const UE::Geometry::FDynamicMeshUVOverlay* UV = (M.HasAttributes() && M.Attributes()->NumUVLayers() > 0) ? M.Attributes()->PrimaryUV() : nullptr;
		for (const int32 Tid : M.TriangleIndicesItr())
		{
			++OutFaces;
			FVector3d P0, P1, P2;
			M.GetTriVertices(Tid, P0, P1, P2);
			const double Area = 0.5 * ((P1 - P0).Cross(P2 - P0)).Length();
			if (Area <= UE_DOUBLE_KINDA_SMALL_NUMBER) { continue; }
			AreaTotal += Area;
			if (!UV || !UV->IsSetTriangle(Tid)) { ++OutFacesWithoutLayout; AreaBadScale += Area; continue; }
			const UE::Geometry::FIndex3i E = UV->GetTriangle(Tid);
			const FVector2d Q0(UV->GetElement(E.A)), Q1(UV->GetElement(E.B)), Q2(UV->GetElement(E.C));
			const FVector3d E1 = P1 - P0, E2 = P2 - P0;
			const FVector3d U = E1.GetSafeNormal();
			const FVector3d N = E1.Cross(E2).GetSafeNormal();
			const FVector3d V = N.Cross(U);
			const FVector2d A1(E1.Length(), 0.0), A2(E2.Dot(U), E2.Dot(V));
			const FVector2d B1 = (Q1 - Q0) * UvUnitCm, B2 = (Q2 - Q0) * UvUnitCm;
			const double Det = B1.X * B2.Y - B1.Y * B2.X;
			if (FMath::Abs(Det) < 1e-9) { ++OutFacesWithoutLayout; AreaBadScale += Area; continue; }
			const double Inv[2][2] = { { B2.Y / Det, -B2.X / Det }, { -B1.Y / Det, B1.X / Det } };
			const double T00 = A1.X * Inv[0][0] + A2.X * Inv[1][0], T01 = A1.X * Inv[0][1] + A2.X * Inv[1][1];
			const double T10 = A1.Y * Inv[0][0] + A2.Y * Inv[1][0], T11 = A1.Y * Inv[0][1] + A2.Y * Inv[1][1];
			const double S = T00 * T00 + T01 * T01 + T10 * T10 + T11 * T11;
			const double D = FMath::Abs(T00 * T11 - T01 * T10);
			const double Root = FMath::Sqrt(FMath::Max(S * S - 4.0 * D * D, 0.0));
			const double Smax = FMath::Sqrt((S + Root) * 0.5), Smin = FMath::Sqrt(FMath::Max((S - Root) * 0.5, 1e-12));
			const double Scale = FMath::Sqrt(Smax * Smin), Stretch = Smax / Smin;
			if (Scale < 0.8 || Scale > 1.25) { AreaBadScale += Area; }
			if (Stretch > 1.5) { AreaBadStretch += Area; }
		}
	});
	OutWrongTilePercent = AreaTotal > 0 ? 100.0 * AreaBadScale / AreaTotal : 0.0;
	OutStretchedPercent = AreaTotal > 0 ? 100.0 * AreaBadStretch / AreaTotal : 0.0;
}

void UModellingTextureToolset::ApplyBoxUVs(UDynamicMesh* Mesh)
{
	if (!Mesh) { return; }
	FGeometryScriptMeshSelection All;
	UGeometryScriptLibrary_MeshSelectionFunctions::CreateSelectAllMeshSelection(Mesh, All, EGeometryScriptMeshSelectionType::Triangles);
	UGeometryScriptLibrary_MeshUVFunctions::SetNumUVSets(Mesh, 1);
	UGeometryScriptLibrary_MeshUVFunctions::SetMeshUVsFromBoxProjection(Mesh, 0, FTransform(FQuat::Identity, FVector::ZeroVector, FVector(UvUnitCm)), All, 2);
}
