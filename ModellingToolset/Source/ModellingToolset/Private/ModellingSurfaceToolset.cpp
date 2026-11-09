// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingSurfaceToolset.h"

#include "ModellingMaterialsToolset.h"
#include "ModellingSurfaces.h"
#include "ModellingTextureToolset.h"
#include "ModellingToolsetSettings.h"
#include "ModellingToolsetUtils.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetToolsModule.h"
#include "DynamicMeshActor.h"
#include "Engine/Texture2D.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "FileHelpers.h"
#include "IAssetTools.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceConstant.h"
#include "MaterialEditingLibrary.h"
#include "Serialization/JsonSerializer.h"
#include "UDynamicMesh.h"

using namespace ModellingToolset;

namespace
{
	const TCHAR* MaterialFolder = TEXT("/Game/ModellingToolset/Materials");
	const TCHAR* FabGlassPath = TEXT("/Game/Fab/Materials/Standard/M_MS_Glass.M_MS_Glass");

	bool ParseHexColour(const FString& In, FColor& Out)
	{
		FString Hex = In.TrimStartAndEnd(); Hex.RemoveFromStart(TEXT("#"));
		if (Hex.Len() != 6) { return false; }
		for (const TCHAR C : Hex) { if (!FChar::IsHexDigit(C)) { return false; } }
		Out = FColor::FromHex(Hex); Out.A = 255;
		return true;
	}

	bool FinishToRange(const FString& Finish, float& OutMin, float& OutMax)
	{
		const FString F = Finish.TrimStartAndEnd().ToLower();
		if (F.IsEmpty() || F == TEXT("auto")) { OutMin = 0.f; OutMax = 1.f; return true; }
		if (F == TEXT("matte")) { OutMin = 0.55f; OutMax = 1.f; return true; }
		if (F == TEXT("satin")) { OutMin = 0.3f; OutMax = 0.75f; return true; }
		if (F == TEXT("glossy")) { OutMin = 0.f; OutMax = 0.35f; return true; }
		return false;
	}

	TSharedRef<FJsonObject> EntryJson(const FSurfaceEntry& E)
	{
		TSharedRef<FJsonObject> J = MakeShared<FJsonObject>();
		J->SetStringField(TEXT("name"), E.Name);
		J->SetStringField(TEXT("category"), E.Category);
		J->SetStringField(TEXT("average_color"), E.bHasAverageColour ? TEXT("#") + E.AverageColour.ToHex().Left(6) : TEXT("unknown"));
		J->SetBoolField(TEXT("has_normal"), !E.NormalPath.IsEmpty());
		J->SetBoolField(TEXT("has_roughness_metallic"), !E.PackedPath.IsEmpty());
		J->SetBoolField(TEXT("has_height"), !E.HeightPath.IsEmpty());
		J->SetStringField(TEXT("folder"), E.Folder);
		return J;
	}

	/** Loads the surface's textures and makes the tweaked material instance. */
	UMaterialInstanceConstant* MaterialForSurface(const FSurfaceEntry& E, const FString& TargetHex, const FString& Finish, float TileCm, bool bWorldAligned, FString& Error, TSharedPtr<FJsonObject>* OutSettings = nullptr)
	{
		UModellingMaterialsToolset::FTextureSet Set;
		Set.Name = E.Key;
		Set.Albedo = LoadObject<UTexture2D>(nullptr, *E.AlbedoPath);
		if (!E.NormalPath.IsEmpty()) { Set.Normal = LoadObject<UTexture2D>(nullptr, *E.NormalPath); }
		if (!E.PackedPath.IsEmpty()) { Set.PackedORM = LoadObject<UTexture2D>(nullptr, *E.PackedPath); }
		if (!Set.Albedo)
		{
			Error = FString::Printf(TEXT("The colour texture of '%s' could not be loaded (%s). If it was just downloaded, save it in the editor first (File > Save All)."), *E.Name, *E.AlbedoPath);
			return nullptr;
		}

		UModellingMaterialsToolset::FSurfaceLook Look;
		Look.TileCm = TileCm > 0.f ? TileCm : GetDefault<UModellingToolsetSettings>()->DefaultSurfaceTileCm;
		Look.bWorldAligned = bWorldAligned;
		if (!FinishToRange(Finish, Look.RoughnessMin, Look.RoughnessMax))
		{
			Error = TEXT("Finish must be 'auto', 'matte', 'satin' or 'glossy'.");
			return nullptr;
		}
		FColor Target;
		if (!TargetHex.TrimStartAndEnd().IsEmpty())
		{
			if (!ParseHexColour(TargetHex, Target))
			{
				Error = TEXT("TargetHex must be a colour like #B04A3A.");
				return nullptr;
			}
			if (E.bHasAverageColour)
			{
				Look.Tint = TintToMatch(E.AverageColour, Target);
			}
		}
		UMaterialInstanceConstant* Instance = UModellingMaterialsToolset::GetOrCreateTexturedInstance(Set, Look, Error);
		if (Instance && OutSettings)
		{
			TSharedRef<FJsonObject> S = MakeShared<FJsonObject>();
			S->SetStringField(TEXT("surface"), E.Name);
			S->SetStringField(TEXT("material"), Instance->GetPathName());
			S->SetNumberField(TEXT("tile_cm"), Look.TileCm);
			S->SetBoolField(TEXT("world_aligned"), bWorldAligned);
			S->SetStringField(TEXT("finish"), Finish.IsEmpty() ? TEXT("auto") : Finish);
			S->SetStringField(TEXT("surface_average_color"), E.bHasAverageColour ? TEXT("#") + E.AverageColour.ToHex().Left(6) : TEXT("unknown"));
			S->SetStringField(TEXT("target_color"), TargetHex);
			S->SetStringField(TEXT("tint_applied"), FString::Printf(TEXT("r %.2f, g %.2f, b %.2f"), Look.Tint.R, Look.Tint.G, Look.Tint.B));
			*OutSettings = S;
		}
		return Instance;
	}

	/** Looks a surface up and reports a helpful error with the closest names when it is missing. */
	const FSurfaceEntry* LookupSurface(const TArray<FSurfaceEntry>& Catalogue, const FString& Surface, FString& Error)
	{
		if (const FSurfaceEntry* E = FindSurface(Catalogue, Surface)) { return E; }
		TArray<FSurfaceMatch> Near = RankSurfaces(Catalogue, Surface, FString(), 3);
		TArray<FString> Names;
		for (const FSurfaceMatch& M : Near) { if (M.Entry) { Names.Add(M.Entry->Name); } }
		Error = FString::Printf(TEXT("No surface named '%s'. %s"), *Surface,
			Catalogue.IsEmpty() ? TEXT("The library is empty: check the surface library folders in the plugin settings, and that the downloaded surfaces are saved (File > Save All).")
			: *FString::Printf(TEXT("Closest names: %s. Use ListSurfaces or FindClosestSurface."), *FString::Join(Names, TEXT(", "))));
		return nullptr;
	}
}

FString UModellingSurfaceToolset::ListSurfaces(const FString& Filter)
{
	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	const FString Needle = Filter.TrimStartAndEnd().ToLower();
	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FSurfaceEntry& E : Catalogue)
	{
		if (!Needle.IsEmpty() && !E.Name.ToLower().Contains(Needle) && !E.Category.Contains(Needle)) { continue; }
		Items.Add(MakeShared<FJsonValueObject>(EntryJson(E)));
	}
	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetArrayField(TEXT("surfaces"), Items);
	Out->SetNumberField(TEXT("count"), Items.Num());
	TArray<TSharedPtr<FJsonValue>> Folders;
	for (const FString& F : GetDefault<UModellingToolsetSettings>()->SurfaceLibraryFolders) { Folders.Add(MakeShared<FJsonValueString>(F)); }
	Out->SetArrayField(TEXT("library_folders"), Folders);
	if (Catalogue.IsEmpty())
	{
		Out->SetStringField(TEXT("note"), TEXT("No surfaces found. Surfaces downloaded from Fab must be saved (File > Save All in the editor) before they can be read, and the library folders are set in Project Settings > Plugins > Modelling Toolset."));
	}
	return ToJsonString(Out);
}

FString UModellingSurfaceToolset::FindClosestSurface(const FString& Description, const FString& TargetHex, int32 MaxResults)
{
	if (Description.TrimStartAndEnd().IsEmpty() && TargetHex.TrimStartAndEnd().IsEmpty())
	{
		Fail(TEXT("Give a Description (what the surface is) and, if you can, a TargetHex colour."));
		return FString();
	}
	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	const TArray<FSurfaceMatch> Matches = RankSurfaces(Catalogue, Description, TargetHex, FMath::Clamp(MaxResults, 1, 10));

	FColor Target; const bool bHasTarget = ParseHexColour(TargetHex, Target);
	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FSurfaceMatch& M : Matches)
	{
		TSharedRef<FJsonObject> J = EntryJson(*M.Entry);
		J->SetNumberField(TEXT("score"), FMath::RoundToDouble(M.Score * 100.0) / 100.0);
		J->SetStringField(TEXT("why"), M.Why);
		J->SetBoolField(TEXT("usable"), IsUsableMatch(M));
		if (bHasTarget && M.Entry->bHasAverageColour)
		{
			const FLinearColor Tint = TintToMatch(M.Entry->AverageColour, Target);
			J->SetStringField(TEXT("tint_to_match"), FString::Printf(TEXT("r %.2f, g %.2f, b %.2f"), Tint.R, Tint.G, Tint.B));
			const bool bStrong = FMath::Max3(Tint.R, Tint.G, Tint.B) > 2.5f || FMath::Min3(Tint.R, Tint.G, Tint.B) < 0.35f;
			J->SetStringField(TEXT("tint_note"), bStrong ? TEXT("a strong tint: the colours differ a lot, the result may look unnatural") : TEXT("a mild tint"));
		}
		Items.Add(MakeShared<FJsonValueObject>(J));
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("description"), Description);
	Out->SetStringField(TEXT("target_color"), TargetHex);
	Out->SetArrayField(TEXT("candidates"), Items);
	const bool bUsable = Matches.Num() > 0 && IsUsableMatch(Matches[0]);
	Out->SetBoolField(TEXT("use_flat_color"), !bUsable);
	Out->SetStringField(TEXT("advice"), bUsable
		? FString::Printf(TEXT("Use '%s' with ApplySurfacePart or ApplySurfaceFaces, passing the same TargetHex so it is tinted to match."), *Matches[0].Entry->Name)
		: (Catalogue.IsEmpty() ? TEXT("The library is empty (are the downloaded surfaces saved?). Use PaintPart with the reference colour.")
			: TEXT("Nothing in the library is this kind of surface. Use PaintPart or PaintFaces with the reference colour, and tell the user which surface would be needed.")));
	return ToJsonString(Out);
}

FModellingCapture UModellingSurfaceToolset::PreviewSurface(const FString& Surface, const FString& TargetHex, const FString& Finish, float TileCm)
{
	FModellingCapture Out;
	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	FString Error;
	const FSurfaceEntry* E = LookupSurface(Catalogue, Surface, Error);
	if (!E) { Fail(Error); return Out; }
	TSharedPtr<FJsonObject> Settings;
	UMaterialInstanceConstant* Instance = MaterialForSurface(*E, TargetHex, Finish, TileCm, true, Error, &Settings);
	if (!Instance) { Fail(Error); return Out; }
	if (!UModellingTextureToolset::RenderMaterialPreview(Instance, TEXT("preview_") + SanitizeFileName(E->Name), Out, Error))
	{
		Fail(Error);
		return Out;
	}
	if (Settings.IsValid())
	{
		Settings->SetStringField(TEXT("capture"), Out.Summary);
		Out.Summary = ToJsonString(Settings.ToSharedRef());
	}
	return Out;
}

FString UModellingSurfaceToolset::ApplySurfacePart(const FString& Name, const FString& Surface, const FString& TargetHex, const FString& Finish, float TileCm, bool bWorldAligned)
{
	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	FString Error;
	const FSurfaceEntry* E = LookupSurface(Catalogue, Surface, Error);
	if (!E) { Fail(Error); return FString(); }
	FEditScope Scope(Name, TEXT("Apply Surface"));
	if (!Scope.IsValid()) { return FString(); }
	TSharedPtr<FJsonObject> Settings;
	UMaterialInstanceConstant* Instance = MaterialForSurface(*E, TargetHex, Finish, TileCm, bWorldAligned, Error, &Settings);
	if (!Instance) { Fail(Error); return FString(); }
	ApplyMaterialToWholePart(Scope.Actor, Scope.Mesh, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	if (Settings.IsValid()) { Out->SetObjectField(TEXT("surface_settings"), Settings); }
	if (!bWorldAligned) { Out->SetStringField(TEXT("note"), TEXT("UV mode: run AutoUV on this part first or the texture may stretch.")); }
	return ToJsonString(Out);
}

FString UModellingSurfaceToolset::ApplySurfaceFaces(const FString& Name, const FModellingSelection& Selection, const FString& Surface, const FString& TargetHex, const FString& Finish, float TileCm, bool bWorldAligned)
{
	const TArray<FSurfaceEntry> Catalogue = BuildSurfaceCatalogue(true);
	FString Error;
	const FSurfaceEntry* E = LookupSurface(Catalogue, Surface, Error);
	if (!E) { Fail(Error); return FString(); }
	FEditScope Scope(Name, TEXT("Apply Surface To Faces"));
	FGeometryScriptMeshSelection Selected;
	if (!Scope.IsValid() || !BuildSelection(Scope.Mesh, Selection, Selected)) { return FString(); }
	TSharedPtr<FJsonObject> Settings;
	UMaterialInstanceConstant* Instance = MaterialForSurface(*E, TargetHex, Finish, TileCm, bWorldAligned, Error, &Settings);
	if (!Instance) { Fail(Error); return FString(); }
	const int32 Slot = ApplyMaterialToSelection(Scope.Actor, Scope.Mesh, Selected, Instance);

	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetNumberField(TEXT("slot"), Slot);
	if (Settings.IsValid()) { Out->SetObjectField(TEXT("surface_settings"), Settings); }
	return ToJsonString(Out);
}

FString UModellingSurfaceToolset::ApplyGlass(const FString& Name, const FModellingSelection& Selection, const FString& TintHex, float Opacity, float Roughness, float IOR)
{
	FColor Tint;
	if (!ParseHexColour(TintHex.IsEmpty() ? TEXT("#FFFFFF") : TintHex, Tint))
	{
		Fail(TEXT("TintHex must be a colour like #DDEEFF."));
		return FString();
	}
	Opacity = FMath::Clamp(Opacity, 0.f, 1.f);
	Roughness = FMath::Clamp(Roughness, 0.f, 1.f);
	IOR = FMath::Clamp(IOR, 1.f, 3.f);

	// Prefer the Megascans glass when the project has it; otherwise the plugin's own.
	UMaterial* Parent = LoadObject<UMaterial>(nullptr, FabGlassPath);
	const bool bFab = Parent != nullptr;
	FString Error;
	if (!Parent) { Parent = UModellingMaterialsToolset::GetGlassMaterial(Error); }
	if (!Parent) { Fail(Error); return FString(); }

	const FString AssetName = FString::Printf(TEXT("MI_Glass_%s_O%d_R%d_I%d"), *Tint.ToHex().Left(6), FMath::RoundToInt(Opacity * 100.f), FMath::RoundToInt(Roughness * 100.f), FMath::RoundToInt(IOR * 100.f));
	const FString ObjectPath = FString::Printf(TEXT("%s/%s.%s"), MaterialFolder, *AssetName, *AssetName);
	UMaterialInstanceConstant* Instance = FindObject<UMaterialInstanceConstant>(nullptr, *ObjectPath);
	if (!Instance)
	{
		const FAssetData Existing = FAssetRegistryModule::GetRegistry().GetAssetByObjectPath(FSoftObjectPath(ObjectPath));
		if (Existing.IsValid()) { Instance = Cast<UMaterialInstanceConstant>(Existing.GetAsset()); }
	}
	if (!Instance)
	{
		UMaterialInstanceConstantFactoryNew* Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
		Factory->InitialParent = Parent;
		Instance = Cast<UMaterialInstanceConstant>(FAssetToolsModule::GetModule().Get().CreateAsset(AssetName, MaterialFolder, UMaterialInstanceConstant::StaticClass(), Factory));
		if (!Instance) { Fail(TEXT("Could not create the glass material instance.")); return FString(); }
	}
	const FLinearColor Linear = FLinearColor::FromSRGBColor(Tint);
	if (bFab)
	{
		UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("Glass Color"), Linear);
		UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("BaseColor Tint"), Linear);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Base Opacity"), Opacity);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Base Window Roughness"), Roughness);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("IOR"), IOR);
		UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("Use Texture for Transmittance Color"), false, EMaterialParameterAssociation::GlobalParameter, false);
		UMaterialEditingLibrary::SetMaterialInstanceStaticSwitchParameterValue(Instance, TEXT("Use Refraction"), IOR > 1.001f, EMaterialParameterAssociation::GlobalParameter, false);
	}
	else
	{
		UMaterialEditingLibrary::SetMaterialInstanceVectorParameterValue(Instance, TEXT("Color"), Linear);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Opacity"), Opacity);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("Roughness"), Roughness);
		UMaterialEditingLibrary::SetMaterialInstanceScalarParameterValue(Instance, TEXT("IOR"), IOR);
	}
	UMaterialEditingLibrary::UpdateMaterialInstance(Instance);
	Instance->MarkPackageDirty();
	UEditorLoadingAndSavingUtils::SavePackages({ Instance->GetOutermost() }, /*bOnlyDirty=*/false);

	FEditScope Scope(Name, TEXT("Apply Glass"));
	if (!Scope.IsValid()) { return FString(); }
	int32 Slot = 0;
	if (Selection.Mode.IsEmpty() || Selection.Mode.ToLower() == TEXT("all"))
	{
		ApplyMaterialToWholePart(Scope.Actor, Scope.Mesh, Instance);
	}
	else
	{
		FGeometryScriptMeshSelection Selected;
		if (!BuildSelection(Scope.Mesh, Selection, Selected)) { return FString(); }
		Slot = ApplyMaterialToSelection(Scope.Actor, Scope.Mesh, Selected, Instance);
	}
	TSharedRef<FJsonObject> Out = DescribeActor(Scope.Actor);
	Out->SetStringField(TEXT("material"), Instance->GetPathName());
	Out->SetStringField(TEXT("glass_master"), bFab ? TEXT("Megascans M_MS_Glass") : TEXT("plugin M_ModellingGlass"));
	Out->SetNumberField(TEXT("slot"), Slot);
	Out->SetNumberField(TEXT("opacity"), Opacity);
	Out->SetNumberField(TEXT("roughness"), Roughness);
	Out->SetNumberField(TEXT("ior"), IOR);
	return ToJsonString(Out);
}
