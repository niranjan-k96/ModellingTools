// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingSurfaces.h"

#include "ModellingToolsetSettings.h"
#include "ModellingToolsetUtils.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/Texture2D.h"
#include "HAL/FileManager.h"
#include "ImageCore.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"

namespace ModellingToolset
{
	namespace
	{
		FString ColourCacheFile()
		{
			return FPaths::ProjectSavedDir() / TEXT("ModellingToolset") / TEXT("surface_colours.json");
		}

		TMap<FString, FColor> LoadColourCache()
		{
			TMap<FString, FColor> Cache;
			FString Text;
			if (FFileHelper::LoadFileToString(Text, *ColourCacheFile()))
			{
				TSharedPtr<FJsonObject> Obj;
				if (FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Text), Obj) && Obj.IsValid())
				{
					for (const TPair<FString, TSharedPtr<FJsonValue>>& Pair : Obj->Values)
					{
						Cache.Add(Pair.Key, FColor::FromHex(Pair.Value->AsString()));
					}
				}
			}
			return Cache;
		}

		void SaveColourCache(const TMap<FString, FColor>& Cache)
		{
			TSharedRef<FJsonObject> Obj = MakeShared<FJsonObject>();
			for (const TPair<FString, FColor>& Pair : Cache)
			{
				Obj->SetStringField(Pair.Key, Pair.Value.ToHex());
			}
			IFileManager::Get().MakeDirectory(*FPaths::GetPath(ColourCacheFile()), true);
			FFileHelper::SaveStringToFile(ToJsonString(Obj), *ColourCacheFile());
		}

		/**
		 * Megascans ids are lowercase alphanumeric tails such as "sexkaitb" or "pjvxx0" on folders whose words are capitalised
		 * (Brick_Wall_Worn_sexkaitb). A lowercase tail with a digit, an unusual letter, a long consonant run or few vowels is an id.
		 */
		bool LooksLikeId(const FString& Token)
		{
			if (Token.Len() < 5 || Token.Len() > 12) { return false; }
			bool bDigit = false, bOddLetter = false;
			int32 Vowels = 0, Run = 0, LongestRun = 0;
			for (const TCHAR C : Token)
			{
				if (!FChar::IsAlnum(C) || FChar::IsUpper(C)) { return false; }
				if (FChar::IsDigit(C)) { bDigit = true; Run = 0; continue; }
				if (FCString::Strchr(TEXT("jkqvwxz"), C)) { bOddLetter = true; }
				if (FCString::Strchr(TEXT("aeiou"), C)) { ++Vowels; Run = 0; }
				else { ++Run; LongestRun = FMath::Max(LongestRun, Run); }
			}
			return bDigit || bOddLetter || LongestRun >= 4 || Vowels * 10 < Token.Len() * 3;
		}

		void SplitWords(const FString& Text, TArray<FString>& Out)
		{
			FString Current;
			for (const TCHAR C : Text)
			{
				if (FChar::IsAlnum(C)) { Current.AppendChar(FChar::ToLower(C)); }
				else if (!Current.IsEmpty()) { Out.Add(Current); Current.Reset(); }
			}
			if (!Current.IsEmpty()) { Out.Add(Current); }
		}

		/** Words that mean the same surface family. */
		const TMap<FString, TArray<FString>>& Synonyms()
		{
			static const TMap<FString, TArray<FString>> Map = {
				{ TEXT("brick"), { TEXT("brick"), TEXT("bricks"), TEXT("brickwork"), TEXT("masonry") } },
				{ TEXT("concrete"), { TEXT("concrete"), TEXT("cement") } },
				{ TEXT("plaster"), { TEXT("plaster"), TEXT("plastered"), TEXT("stucco"), TEXT("render"), TEXT("rendered"), TEXT("whitewash"), TEXT("whitewashed"), TEXT("limewash") } },
				{ TEXT("paint"), { TEXT("paint"), TEXT("painted") } },
				{ TEXT("marble"), { TEXT("marble") } },
				{ TEXT("tile"), { TEXT("tile"), TEXT("tiles"), TEXT("tiled") } },
				{ TEXT("roof"), { TEXT("roof"), TEXT("roofing"), TEXT("rooftiles"), TEXT("shingle"), TEXT("shingles"), TEXT("terracotta"), TEXT("clay") } },
				{ TEXT("metal"), { TEXT("metal"), TEXT("metallic"), TEXT("steel"), TEXT("iron"), TEXT("panel"), TEXT("panels"), TEXT("sheet"), TEXT("sheets"), TEXT("facade") } },
				{ TEXT("rust"), { TEXT("rust"), TEXT("rusty"), TEXT("rusted"), TEXT("corroded") } },
				{ TEXT("scratched"), { TEXT("scratched"), TEXT("scratch"), TEXT("scratches"), TEXT("worn"), TEXT("scuffed") } },
				{ TEXT("wood"), { TEXT("wood"), TEXT("wooden"), TEXT("timber"), TEXT("plank"), TEXT("planks"), TEXT("veneer"), TEXT("oak"), TEXT("pine"), TEXT("boards"), TEXT("board") } },
				{ TEXT("snow"), { TEXT("snow"), TEXT("snowy") } },
				{ TEXT("grass"), { TEXT("grass"), TEXT("lawn"), TEXT("turf"), TEXT("meadow") } },
				{ TEXT("sand"), { TEXT("sand"), TEXT("sandy"), TEXT("beach"), TEXT("dune") } },
				{ TEXT("soil"), { TEXT("soil"), TEXT("dirt"), TEXT("earth"), TEXT("mud"), TEXT("ground") } },
				{ TEXT("stone"), { TEXT("stone"), TEXT("stones"), TEXT("rock"), TEXT("rocks"), TEXT("cobble"), TEXT("cobbles"), TEXT("cobblestone"), TEXT("granite"), TEXT("slate") } },
				{ TEXT("pavement"), { TEXT("pavement"), TEXT("paving"), TEXT("sidewalk"), TEXT("pavers"), TEXT("flagstone") } },
				{ TEXT("road"), { TEXT("road"), TEXT("asphalt"), TEXT("tarmac"), TEXT("street") } },
				{ TEXT("wall"), { TEXT("wall"), TEXT("walls") } },
				{ TEXT("floor"), { TEXT("floor"), TEXT("floors"), TEXT("flooring") } },
				{ TEXT("cracked"), { TEXT("cracked"), TEXT("crack"), TEXT("cracks"), TEXT("flaked"), TEXT("flaking"), TEXT("peeling"), TEXT("damaged"), TEXT("old"), TEXT("weathered") } },
				{ TEXT("dirty"), { TEXT("dirty"), TEXT("grimy"), TEXT("stained") } },
				{ TEXT("white"), { TEXT("white"), TEXT("cream"), TEXT("ivory"), TEXT("light") } },
				{ TEXT("red"), { TEXT("red"), TEXT("crimson") } },
				{ TEXT("grey"), { TEXT("grey"), TEXT("gray") } } };
			return Map;
		}

		/** Maps any word to its family word, or returns it unchanged. */
		FString Family(const FString& Word)
		{
			for (const TPair<FString, TArray<FString>>& Pair : Synonyms())
			{
				if (Pair.Value.Contains(Word)) { return Pair.Key; }
			}
			return Word;
		}

		FString Readable(const FString& Key)
		{
			TArray<FString> Parts;
			Key.ParseIntoArray(Parts, TEXT("_"), true);
			if (Parts.Num() > 1 && LooksLikeId(Parts.Last())) { Parts.Pop(); }
			return FString::Join(Parts, TEXT(" "));
		}
	}

	FString GuessSurfaceCategory(const FString& Name)
	{
		TArray<FString> Words;
		SplitWords(Name, Words);
		static const TArray<FString> Order = { TEXT("brick"), TEXT("marble"), TEXT("roof"), TEXT("tile"), TEXT("wood"), TEXT("rust"), TEXT("metal"), TEXT("concrete"), TEXT("plaster"), TEXT("paint"),
			TEXT("snow"), TEXT("grass"), TEXT("sand"), TEXT("soil"), TEXT("pavement"), TEXT("road"), TEXT("stone"), TEXT("glass"), TEXT("fabric"), TEXT("water"), TEXT("plastic") };
		TSet<FString> Families;
		for (const FString& W : Words) { Families.Add(Family(W)); }
		for (const FString& Cat : Order)
		{
			if (Families.Contains(Cat)) { return Cat == TEXT("rust") ? TEXT("metal") : Cat; }
		}
		return TEXT("other");
	}

	bool ComputeTextureAverageColour(UTexture2D* Texture, FColor& OutColour)
	{
		if (!Texture)
		{
			return false;
		}
		FImage Mip;
		if (!Texture->Source.IsValid() || !Texture->Source.GetMipImage(Mip, 0))
		{
			return false;
		}
		FImage Small;
		Mip.CopyTo(Small, ERawImageFormat::BGRA8, EGammaSpace::sRGB);
		const TArrayView64<FColor> Pixels = Small.AsBGRA8();
		if (Pixels.Num() == 0)
		{
			return false;
		}
		// Sample a grid, average in linear light, convert back.
		const int64 Step = FMath::Max<int64>(1, Pixels.Num() / 4096);
		FLinearColor Sum(0, 0, 0, 0);
		int64 Count = 0;
		for (int64 i = 0; i < Pixels.Num(); i += Step)
		{
			Sum += FLinearColor::FromSRGBColor(Pixels[i]);
			++Count;
		}
		OutColour = (Sum / static_cast<float>(Count)).ToFColor(true);
		return true;
	}

	TArray<FSurfaceEntry> BuildSurfaceCatalogue(bool bComputeColours)
	{
		TMap<FString, FSurfaceEntry> Entries;
		IAssetRegistry& Registry = FAssetRegistryModule::GetRegistry();
		const FTopLevelAssetPath TextureClass = UTexture2D::StaticClass()->GetClassPathName();
		const FTopLevelAssetPath InstanceClass = UMaterialInstanceConstant::StaticClass()->GetClassPathName();

		for (const FString& Root : GetDefault<UModellingToolsetSettings>()->SurfaceLibraryFolders)
		{
			const FString Folder = Root.TrimStartAndEnd();
			if (!Folder.StartsWith(TEXT("/Game/"))) { continue; }
			Registry.ScanPathsSynchronous({ Folder }, /*bForceRescan=*/false);
			TArray<FAssetData> Assets;
			Registry.GetAssetsByPath(FName(*Folder), Assets, /*bRecursive=*/true);
			for (const FAssetData& Asset : Assets)
			{
				// The surface folder is the first folder below the root.
				FString Relative = Asset.PackagePath.ToString();
				if (!Relative.StartsWith(Folder + TEXT("/"))) { continue; }
				Relative.RightChopInline(Folder.Len() + 1);
				FString Key, Rest;
				if (!Relative.Split(TEXT("/"), &Key, &Rest)) { Key = Relative; }
				if (Key.IsEmpty()) { continue; }

				FSurfaceEntry& E = Entries.FindOrAdd(Key);
				E.Key = Key;
				E.Folder = Folder / Key;
				const FString AssetName = Asset.AssetName.ToString();
				if (Asset.AssetClassPath == TextureClass)
				{
					int32 Underscore;
					const FString Suffix = AssetName.FindLastChar(TEXT('_'), Underscore) ? AssetName.Mid(Underscore + 1).ToUpper() : FString();
					const FString Path = Asset.GetObjectPathString();
					if (Suffix == TEXT("B") || Suffix == TEXT("D") || Suffix == TEXT("ALBEDO") || Suffix == TEXT("BASECOLOR") || Suffix == TEXT("COLOR")) { if (E.AlbedoPath.IsEmpty() || Path.Contains(TEXT("_2K_"))) { E.AlbedoPath = Path; } }
					else if (Suffix == TEXT("N") || Suffix == TEXT("NORMAL")) { if (E.NormalPath.IsEmpty() || Path.Contains(TEXT("_2K_"))) { E.NormalPath = Path; } }
					else if (Suffix == TEXT("ORM") || Suffix == TEXT("MR") || Suffix == TEXT("ORDP") || Suffix == TEXT("RAODM")) { if (E.PackedPath.IsEmpty() || Path.Contains(TEXT("_2K_"))) { E.PackedPath = Path; } }
					else if (Suffix == TEXT("H") || Suffix == TEXT("HEIGHT") || Suffix == TEXT("DISPLACEMENT")) { E.HeightPath = Path; }
				}
				else if (Asset.AssetClassPath == InstanceClass)
				{
					if (E.InstancePath.IsEmpty()) { E.InstancePath = Asset.GetObjectPathString(); }
				}
			}
		}

		TArray<FSurfaceEntry> Out;
		TMap<FString, FColor> Cache = bComputeColours ? LoadColourCache() : TMap<FString, FColor>();
		bool bCacheChanged = false;
		for (TPair<FString, FSurfaceEntry>& Pair : Entries)
		{
			FSurfaceEntry& E = Pair.Value;
			if (E.AlbedoPath.IsEmpty()) { continue; } // a colour texture is the minimum
			E.Name = Readable(E.Key);
			E.Category = GuessSurfaceCategory(E.Name);
			SplitWords(E.Name, E.Words);
			if (bComputeColours)
			{
				if (const FColor* Cached = Cache.Find(E.AlbedoPath))
				{
					E.AverageColour = *Cached;
					E.bHasAverageColour = true;
				}
				else if (UTexture2D* Albedo = LoadObject<UTexture2D>(nullptr, *E.AlbedoPath))
				{
					if (ComputeTextureAverageColour(Albedo, E.AverageColour))
					{
						E.bHasAverageColour = true;
						Cache.Add(E.AlbedoPath, E.AverageColour);
						bCacheChanged = true;
					}
				}
			}
			Out.Add(E);
		}
		if (bCacheChanged) { SaveColourCache(Cache); }
		Out.Sort([](const FSurfaceEntry& A, const FSurfaceEntry& B) { return A.Name < B.Name; });
		return Out;
	}

	const FSurfaceEntry* FindSurface(const TArray<FSurfaceEntry>& Catalogue, const FString& NameOrKey)
	{
		const FString Wanted = NameOrKey.TrimStartAndEnd().Replace(TEXT("_"), TEXT(" ")).ToLower();
		if (Wanted.IsEmpty()) { return nullptr; }
		for (const FSurfaceEntry& E : Catalogue)
		{
			if (E.Name.ToLower() == Wanted || E.Key.Replace(TEXT("_"), TEXT(" ")).ToLower() == Wanted) { return &E; }
		}
		// Then a name that starts with what was asked (so "Brick Wall Worn" finds a folder that still carries an id).
		const FSurfaceEntry* Prefix = nullptr;
		for (const FSurfaceEntry& E : Catalogue)
		{
			if (E.Name.ToLower().StartsWith(Wanted) || E.Key.Replace(TEXT("_"), TEXT(" ")).ToLower().StartsWith(Wanted))
			{
				if (Prefix) { return nullptr; } // ambiguous
				Prefix = &E;
			}
		}
		return Prefix;
	}

	TArray<FSurfaceMatch> RankSurfaces(const TArray<FSurfaceEntry>& Catalogue, const FString& Description, const FString& TargetHex, int32 MaxResults)
	{
		TArray<FString> Words;
		SplitWords(Description, Words);
		TSet<FString> WantedFamilies;
		static const TSet<FString> Stop = { TEXT("a"), TEXT("an"), TEXT("the"), TEXT("of"), TEXT("with"), TEXT("and"), TEXT("some"), TEXT("surface"), TEXT("material"), TEXT("texture") };
		for (const FString& W : Words) { if (!Stop.Contains(W)) { WantedFamilies.Add(Family(W)); } }

		FColor Target = FColor::Black;
		bool bHasTarget = false;
		{
			FString Hex = TargetHex.TrimStartAndEnd(); Hex.RemoveFromStart(TEXT("#"));
			if (Hex.Len() == 6) { Target = FColor::FromHex(Hex); bHasTarget = true; }
		}

		TArray<FSurfaceMatch> Matches;
		for (const FSurfaceEntry& E : Catalogue)
		{
			FSurfaceMatch M;
			M.Entry = &E;

			// Words: each family in the description that the surface's name or category contains. Material words
			// (brick, plaster, wood) count fully; place words (wall, floor) a little; colour words not at all.
			TSet<FString> SurfaceFamilies;
			for (const FString& W : E.Words) { SurfaceFamilies.Add(Family(W)); }
			SurfaceFamilies.Add(E.Category);
			static const TSet<FString> ColourFamilies = { TEXT("white"), TEXT("red"), TEXT("grey"), TEXT("black"), TEXT("brown"), TEXT("blue"), TEXT("green"), TEXT("yellow") };
			static const TSet<FString> PlaceFamilies = { TEXT("wall"), TEXT("floor"), TEXT("cracked"), TEXT("dirty"), TEXT("scratched") };
			auto Weight = [&](const FString& F) { return ColourFamilies.Contains(F) ? 0.0 : (PlaceFamilies.Contains(F) ? 0.3 : 1.0); };
			double WantedWeight = 0.0, HitWeight = 0.0;
			bool bMaterialHit = false, bAnyHit = false;
			TArray<FString> HitWords;
			for (const FString& F : WantedFamilies)
			{
				const double W = Weight(F);
				WantedWeight += W;
				if (SurfaceFamilies.Contains(F))
				{
					HitWeight += W;
					HitWords.Add(F);
					bAnyHit = true;
					if (W >= 1.0) { bMaterialHit = true; }
				}
			}
			if (bMaterialHit) { M.WordScore = FMath::Clamp(0.55 + 0.45 * HitWeight / FMath::Max(WantedWeight, 0.01), 0.0, 1.0); }
			else if (bAnyHit) { M.WordScore = 0.25; }
			else { M.WordScore = 0.0; }

			// Colour: distance between the surface's average colour and the target.
			if (bHasTarget && E.bHasAverageColour)
			{
				const double Dist = FMath::Sqrt(FMath::Square(double(E.AverageColour.R) - Target.R) + FMath::Square(double(E.AverageColour.G) - Target.G) + FMath::Square(double(E.AverageColour.B) - Target.B)) / 441.67;
				M.ColourScore = FMath::Clamp(1.0 - Dist * 1.6, 0.0, 1.0);
			}
			else
			{
				M.ColourScore = 0.5;
			}
			M.Score = 0.65 * M.WordScore + 0.35 * M.ColourScore;
			M.Why = HitWords.IsEmpty() ? TEXT("no word match") : (TEXT("matches: ") + FString::Join(HitWords, TEXT(", ")));
			if (bHasTarget && E.bHasAverageColour) { M.Why += FString::Printf(TEXT("; colour closeness %.0f%%"), M.ColourScore * 100.0); }
			Matches.Add(M);
		}
		Matches.Sort([](const FSurfaceMatch& A, const FSurfaceMatch& B) { return A.Score > B.Score; });
		if (Matches.Num() > MaxResults) { Matches.SetNum(MaxResults); }
		return Matches;
	}

	bool IsUsableMatch(const FSurfaceMatch& Match)
	{
		// A material word match is needed; colour or a place word alone is not enough to pick a surface.
		return Match.Entry && Match.WordScore >= 0.55 && Match.Score >= 0.5;
	}

	FLinearColor TintToMatch(const FColor& AverageSRGB, const FColor& TargetSRGB)
	{
		const FLinearColor Avg = FLinearColor::FromSRGBColor(AverageSRGB);
		const FLinearColor Target = FLinearColor::FromSRGBColor(TargetSRGB);
		auto Ratio = [](float T, float A) { return FMath::Clamp(T / FMath::Max(A, 0.01f), 0.15f, 4.f); };
		return FLinearColor(Ratio(Target.R, Avg.R), Ratio(Target.G, Avg.G), Ratio(Target.B, Avg.B), 1.f);
	}
}
