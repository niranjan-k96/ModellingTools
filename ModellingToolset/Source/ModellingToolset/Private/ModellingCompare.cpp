// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingCompare.h"

#include "ModellingCapture.h"
#include "ModellingToolsetUtils.h"

#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

namespace ModellingToolset
{
	namespace
	{
		constexpr int32 NormSize = 128;
		constexpr int32 TileSize = 256;
		constexpr int32 BandCount = 8;

		FString CondensedJson(const TSharedRef<FJsonObject>& Object)
		{
			FString Out;
			const TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> Writer =
				TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&Out);
			FJsonSerializer::Serialize(Object, Writer);
			return Out;
		}

		/** Draws an image scaled to fit a square tile (keeping its proportions) onto the canvas at TileX. */
		void DrawFitted(TArray<FColor>& Canvas, int32 CanvasWidth, int32 TileX, const TArray<FColor>& Src, FIntPoint SrcSize)
		{
			const float Scale = FMath::Min(static_cast<float>(TileSize) / SrcSize.X, static_cast<float>(TileSize) / SrcSize.Y);
			const FIntPoint Fit(FMath::Max(1, FMath::RoundToInt(SrcSize.X * Scale)), FMath::Max(1, FMath::RoundToInt(SrcSize.Y * Scale)));
			TArray<FColor> Scaled;
			ResizeImage(Src, SrcSize, Fit, Scaled);
			const int32 OffX = TileX + (TileSize - Fit.X) / 2;
			const int32 OffY = (TileSize - Fit.Y) / 2;
			for (int32 Y = 0; Y < Fit.Y; ++Y)
			{
				for (int32 X = 0; X < Fit.X; ++X)
				{
					Canvas[(OffY + Y) * CanvasWidth + OffX + X] = Scaled[Y * Fit.X + X];
				}
			}
		}
	}

	FMask MakeMask(const TArray<FColor>& Pixels, FIntPoint Size, double Threshold, double* OutBorderSpread)
	{
		FMask Mask;
		Mask.Width = Size.X;
		Mask.Height = Size.Y;
		Mask.Data.Init(0, Size.X * Size.Y);

		// Background = average border colour; spread = how different the border pixels are from each other.
		FVector Sum = FVector::ZeroVector;
		int32 Count = 0;
		auto AddBorder = [&](int32 X, int32 Y) { const FColor C = Pixels[Y * Size.X + X]; Sum += FVector(C.R, C.G, C.B); ++Count; };
		for (int32 X = 0; X < Size.X; ++X) { AddBorder(X, 0); AddBorder(X, Size.Y - 1); }
		for (int32 Y = 1; Y < Size.Y - 1; ++Y) { AddBorder(0, Y); AddBorder(Size.X - 1, Y); }
		const FVector Background = Sum / FMath::Max(Count, 1);

		double SpreadSum = 0.0;
		auto Spread = [&](int32 X, int32 Y) { const FColor C = Pixels[Y * Size.X + X]; SpreadSum += FVector::Dist(FVector(C.R, C.G, C.B), Background); };
		for (int32 X = 0; X < Size.X; ++X) { Spread(X, 0); Spread(X, Size.Y - 1); }
		for (int32 Y = 1; Y < Size.Y - 1; ++Y) { Spread(0, Y); Spread(Size.X - 1, Y); }
		if (OutBorderSpread) { *OutBorderSpread = SpreadSum / FMath::Max(Count, 1); }

		for (int32 i = 0; i < Pixels.Num(); ++i)
		{
			const FColor C = Pixels[i];
			Mask.Data[i] = FVector::Dist(FVector(C.R, C.G, C.B), Background) > Threshold ? 1 : 0;
		}
		return Mask;
	}

	int32 RemoveFloorShadow(FMask& Mask, const TArray<FColor>& Pixels, FIntPoint Size)
	{
		// Background colour from the border, as in MakeMask.
		FVector Sum = FVector::ZeroVector;
		int32 Count = 0;
		auto Add = [&](int32 X, int32 Y) { const FColor C = Pixels[Y * Size.X + X]; Sum += FVector(C.R, C.G, C.B); ++Count; };
		for (int32 X = 0; X < Size.X; ++X) { Add(X, 0); Add(X, Size.Y - 1); }
		for (int32 Y = 1; Y < Size.Y - 1; ++Y) { Add(0, Y); Add(Size.X - 1, Y); }
		const FVector Bg = Sum / FMath::Max(Count, 1);
		const double BgLuma = (Bg.X + Bg.Y + Bg.Z) / 3.0;
		const double BgChroma = FMath::Max3(Bg.X, Bg.Y, Bg.Z) - FMath::Min3(Bg.X, Bg.Y, Bg.Z);
		if (BgLuma < 120.0 || BgChroma > 40.0)
		{
			return 0; // shadows are only recognisable on a light, neutral background
		}

		// A shadow is a darkened, uncoloured version of the background: same hue, a little darker, still fairly light.
		int32 Removed = 0;
		for (int32 i = 0; i < Pixels.Num(); ++i)
		{
			if (!Mask.Data[i]) { continue; }
			const FColor C = Pixels[i];
			const double Luma = (C.R + C.G + C.B) / 3.0;
			const double Chroma = FMath::Max3(C.R, C.G, C.B) - FMath::Min3(C.R, C.G, C.B);
			const bool bNeutral = Chroma <= BgChroma + 18.0;
			const bool bSlightlyDarker = Luma < BgLuma && Luma > BgLuma * 0.45;
			if (bNeutral && bSlightlyDarker)
			{
				Mask.Data[i] = 0;
				++Removed;
			}
		}
		return Removed;
	}

	void RemoveSmallComponents(FMask& Mask, double MinFraction)
	{
		TArray<int32> Label;
		Label.Init(0, Mask.Data.Num());
		TArray<int32> Sizes;
		TArray<int32> Stack;
		int32 Total = 0;

		for (int32 Start = 0; Start < Mask.Data.Num(); ++Start)
		{
			if (!Mask.Data[Start] || Label[Start]) { continue; }
			const int32 Id = Sizes.Num() + 1;
			int32 Size = 0;
			Stack.Reset();
			Stack.Add(Start);
			Label[Start] = Id;
			while (!Stack.IsEmpty())
			{
				const int32 Cur = Stack.Pop(EAllowShrinking::No);
				++Size;
				const int32 X = Cur % Mask.Width, Y = Cur / Mask.Width;
				const int32 Neighbours[4][2] = { { X + 1, Y }, { X - 1, Y }, { X, Y + 1 }, { X, Y - 1 } };
				for (const auto& N : Neighbours)
				{
					if (Mask.IsInside(N[0], N[1]) && Mask.Get(N[0], N[1]) && !Label[N[1] * Mask.Width + N[0]])
					{
						Label[N[1] * Mask.Width + N[0]] = Id;
						Stack.Add(N[1] * Mask.Width + N[0]);
					}
				}
			}
			Sizes.Add(Size);
			Total += Size;
		}

		const double MinSize = FMath::Max(2.0, Total * MinFraction);
		for (int32 i = 0; i < Mask.Data.Num(); ++i)
		{
			if (Label[i] && Sizes[Label[i] - 1] < MinSize) { Mask.Data[i] = 0; }
		}
	}

	bool MaskBounds(const FMask& Mask, FIntRect& OutBounds)
	{
		int32 MinX = Mask.Width, MinY = Mask.Height, MaxX = -1, MaxY = -1;
		for (int32 Y = 0; Y < Mask.Height; ++Y)
		{
			for (int32 X = 0; X < Mask.Width; ++X)
			{
				if (Mask.Get(X, Y)) { MinX = FMath::Min(MinX, X); MaxX = FMath::Max(MaxX, X); MinY = FMath::Min(MinY, Y); MaxY = FMath::Max(MaxY, Y); }
			}
		}
		if (MaxX < 0) { return false; }
		OutBounds = FIntRect(MinX, MinY, MaxX + 1, MaxY + 1);
		return true;
	}

	FMask NormaliseMask(const FMask& Mask, const FIntRect& Bounds, int32 Size)
	{
		FMask Out;
		Out.Width = Size;
		Out.Height = Size;
		Out.Data.Init(0, Size * Size);
		const int32 BW = Bounds.Width(), BH = Bounds.Height();
		for (int32 Y = 0; Y < Size; ++Y)
		{
			for (int32 X = 0; X < Size; ++X)
			{
				const int32 SX = FMath::Clamp(Bounds.Min.X + (X * BW) / Size, 0, Mask.Width - 1);
				const int32 SY = FMath::Clamp(Bounds.Min.Y + (Y * BH) / Size, 0, Mask.Height - 1);
				Out.Data[Y * Size + X] = Mask.Get(SX, SY);
			}
		}
		return Out;
	}

	double IntersectionOverUnion(const FMask& A, const FMask& B)
	{
		if (A.Width != B.Width || A.Height != B.Height) { return 0.0; }
		int32 Inter = 0, Union = 0;
		for (int32 i = 0; i < A.Data.Num(); ++i)
		{
			Inter += (A.Data[i] && B.Data[i]) ? 1 : 0;
			Union += (A.Data[i] || B.Data[i]) ? 1 : 0;
		}
		return Union > 0 ? static_cast<double>(Inter) / Union : 0.0;
	}

	namespace
	{
		TArray<FProfileDifference> CompareBands(const FMask& Ref, const FMask& Mod, int32 Bands, double Threshold, bool bRows)
		{
			TArray<FProfileDifference> Out;
			const int32 N = Ref.Width;
			const int32 PerBand = FMath::Max(1, N / Bands);
			for (int32 Band = 0; Band < Bands; ++Band)
			{
				double RefSum = 0.0, ModSum = 0.0;
				for (int32 Line = Band * PerBand; Line < FMath::Min(N, (Band + 1) * PerBand); ++Line)
				{
					for (int32 Pos = 0; Pos < N; ++Pos)
					{
						const int32 X = bRows ? Pos : Line, Y = bRows ? Line : Pos;
						RefSum += Ref.Get(X, Y);
						ModSum += Mod.Get(X, Y);
					}
				}
				const double Lines = PerBand * N;
				const double Diff = (ModSum - RefSum) / Lines; // fraction of the full extent
				if (FMath::Abs(Diff) > Threshold)
				{
					FProfileDifference D;
					D.FromPercent = (Band * 100) / Bands;
					D.ToPercent = ((Band + 1) * 100) / Bands;
					D.DifferencePercent = Diff * 100.0;
					Out.Add(D);
				}
			}
			return Out;
		}
	}

	TArray<FProfileDifference> CompareWidthBands(const FMask& Reference, const FMask& Model, int32 Bands, double Threshold)
	{
		return CompareBands(Reference, Model, Bands, Threshold, /*bRows=*/true);
	}

	TArray<FProfileDifference> CompareHeightBands(const FMask& Reference, const FMask& Model, int32 Bands, double Threshold)
	{
		return CompareBands(Reference, Model, Bands, Threshold, /*bRows=*/false);
	}

	FCompareResult CompareToReference(const FString& ReferenceName, const FString& View, const FString& ActorNames)
	{
		FCompareResult Result;

		// Reference picture.
		const FString Dir = GetReferencesDir();
		if (ReferenceName.IsEmpty() || ReferenceName != FPaths::GetCleanFilename(ReferenceName) || !IsPathUnder(Dir / ReferenceName, Dir) || !IFileManager::Get().FileExists(*(Dir / ReferenceName)))
		{
			Result.Error = FString::Printf(TEXT("Reference '%s' not found. Use ListReferences."), *ReferenceName);
			return Result;
		}

		const FReferenceMeta Meta = ReadReferenceMeta(ReferenceName);
		FString UseView = View.TrimStartAndEnd().ToLower();
		if (UseView == TEXT("side")) { UseView = TEXT("right"); }
		if (UseView.IsEmpty()) { UseView = Meta.View.IsEmpty() ? FString(TEXT("front")) : Meta.View; }
		static const TArray<FString> AxisViews = { TEXT("front"), TEXT("back"), TEXT("left"), TEXT("right"), TEXT("top"), TEXT("bottom") };
		if (!AxisViews.Contains(UseView))
		{
			Result.Error = TEXT("View must be front, back, left, right, top or bottom. Comparison needs a straight-on view.");
			return Result;
		}

		TArray<FColor> RefPixels;
		FIntPoint RefSize, RefOriginal;
		FString Error;
		if (!LoadImageFile(Dir / ReferenceName, 256, RefPixels, RefSize, RefOriginal, Error))
		{
			Result.Error = Error;
			return Result;
		}

		// Model render from the same view, only the model visible, as pure white on black, so the outline does not depend on
		// the model's colours or lighting.
		FCaptureRequest Request;
		Request.ActorNames = ActorNames;
		Request.Views = UseView;
		Request.ViewMode = TEXT("silhouette");
		Request.Resolution = TileSize;
		Request.bIsolate = true;
		Request.Label = TEXT("compare");
		Request.bSetReviewImage = false;
		const FCaptureResult Capture = CaptureViews(Request);
		if (!Capture.bOk)
		{
			Result.Error = Capture.Error;
			return Result;
		}
		if (Capture.SheetSize != FIntPoint(TileSize, TileSize))
		{
			Result.Error = TEXT("Unexpected capture size.");
			return Result;
		}

		// Silhouettes.
		double RefSpread = 0.0, ModelSpread = 0.0;
		FMask RefMask = MakeMask(RefPixels, RefSize, 36.0, &RefSpread);
		const int32 ShadowPixels = RemoveFloorShadow(RefMask, RefPixels, RefSize);
		FMask ModelMask = MakeMask(Capture.Sheet, Capture.SheetSize, 100.0, &ModelSpread);
		RemoveSmallComponents(RefMask, 0.004);
		RemoveSmallComponents(ModelMask, 0.004);

		FIntRect RefBounds, ModelBounds;
		if (!MaskBounds(RefMask, RefBounds))
		{
			Result.Error = TEXT("Could not find an object in the reference picture. It needs a fairly plain background that differs from the object.");
			return Result;
		}
		if (!MaskBounds(ModelMask, ModelBounds))
		{
			Result.Error = TEXT("Could not find the model in the render. Is there geometry yet?");
			return Result;
		}

		const FMask RefNorm = NormaliseMask(RefMask, RefBounds, NormSize);
		const FMask ModelNorm = NormaliseMask(ModelMask, ModelBounds, NormSize);
		const double Iou = IntersectionOverUnion(RefNorm, ModelNorm);

		const double RefAspect = static_cast<double>(RefBounds.Width()) / RefBounds.Height();
		const double ModelAspect = static_cast<double>(ModelBounds.Width()) / ModelBounds.Height();
		const double AspectErrorPercent = (ModelAspect / RefAspect - 1.0) * 100.0;

		auto Fill = [](const FMask& M) { int32 N = 0; for (const uint8 V : M.Data) { N += V; } return 100.0 * N / M.Data.Num(); };

		// Plain-language hints about where the shapes differ.
		TArray<TSharedPtr<FJsonValue>> Hints;
		auto AddHints = [&](const TArray<FProfileDifference>& Diffs, bool bRows)
		{
			for (const FProfileDifference& D : Diffs)
			{
				const bool bBigger = D.DifferencePercent > 0;
				const FString Where = bRows
					? FString::Printf(TEXT("Between %d%% and %d%% of the way down from the top, the model is %.0f%% %s than the reference (relative to the full width)."),
						D.FromPercent, D.ToPercent, FMath::Abs(D.DifferencePercent), bBigger ? TEXT("wider") : TEXT("narrower"))
					: FString::Printf(TEXT("Between %d%% and %d%% of the way across from the left, the model is %.0f%% %s than the reference (relative to the full height)."),
						D.FromPercent, D.ToPercent, FMath::Abs(D.DifferencePercent), bBigger ? TEXT("taller") : TEXT("shorter"));
				Hints.Add(MakeShared<FJsonValueString>(Where));
			}
		};
		AddHints(CompareWidthBands(RefNorm, ModelNorm, BandCount, 0.12), true);
		AddHints(CompareHeightBands(RefNorm, ModelNorm, BandCount, 0.12), false);

		if (FMath::Abs(AspectErrorPercent) > 8.0)
		{
			Hints.Insert(MakeShared<FJsonValueString>(FString::Printf(
				TEXT("Overall proportions: the model is %.0f%% %s relative to its height than the reference. Adjust the overall width-to-height ratio first."),
				FMath::Abs(AspectErrorPercent), AspectErrorPercent > 0 ? TEXT("wider") : TEXT("narrower"))), 0);
		}

		FString Verdict;
		if (Iou >= 0.90) { Verdict = TEXT("Excellent match. Only fine details are left."); }
		else if (Iou >= 0.78) { Verdict = TEXT("Good match. Fix the listed differences."); }
		else if (Iou >= 0.60) { Verdict = TEXT("Fair match. The overall shape is close but needs work."); }
		else { Verdict = TEXT("Poor match. Re-check the overall proportions and main shapes."); }

		// Side-by-side picture: reference | model | overlap map.
		const int32 W = TileSize * 3;
		Result.Image.Init(FColor(26, 26, 31, 255), W * TileSize);
		Result.ImageSize = FIntPoint(W, TileSize);
		DrawFitted(Result.Image, W, 0, RefPixels, RefSize);
		DrawFitted(Result.Image, W, TileSize, Capture.Sheet, Capture.SheetSize);
		for (int32 Y = 0; Y < TileSize; ++Y)
		{
			for (int32 X = 0; X < TileSize; ++X)
			{
				const uint8 R = RefNorm.Get(X * NormSize / TileSize, Y * NormSize / TileSize);
				const uint8 M = ModelNorm.Get(X * NormSize / TileSize, Y * NormSize / TileSize);
				FColor C(26, 26, 31, 255);
				if (R && M) { C = FColor(150, 150, 150, 255); }
				else if (M) { C = FColor(230, 70, 60, 255); }   // model only
				else if (R) { C = FColor(60, 110, 235, 255); }  // reference only
				Result.Image[Y * W + 2 * TileSize + X] = C;
			}
		}

		// Keep the side-by-side picture with the other progress pictures.
		FString SavedFile;
		{
			TSharedPtr<FJsonObject> CaptureSummary;
			FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Capture.SummaryJson), CaptureSummary);
			FString SessionDir;
			if (CaptureSummary.IsValid() && CaptureSummary->TryGetStringField(TEXT("session_folder"), SessionDir))
			{
				const int32 Step = static_cast<int32>(CaptureSummary->GetNumberField(TEXT("step")));
				SavedFile = SessionDir / FString::Printf(TEXT("step_%03d_compare_%s_vs_%s.png"), Step, *SanitizeFileName(FPaths::GetBaseFilename(ReferenceName)), *UseView);
				if (!SavePng(SavedFile, Result.Image, Result.ImageSize)) { SavedFile.Reset(); }
			}
		}

		TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
		Out->SetStringField(TEXT("reference"), ReferenceName);
		Out->SetStringField(TEXT("view"), UseView);
		if (!SavedFile.IsEmpty()) { Out->SetStringField(TEXT("saved_file"), SavedFile); }
		Out->SetNumberField(TEXT("overlap_score"), FMath::RoundToDouble(Iou * 1000.0) / 1000.0);
		Out->SetStringField(TEXT("verdict"), Verdict);
		Out->SetNumberField(TEXT("aspect_reference_width_over_height"), FMath::RoundToDouble(RefAspect * 1000.0) / 1000.0);
		Out->SetNumberField(TEXT("aspect_model_width_over_height"), FMath::RoundToDouble(ModelAspect * 1000.0) / 1000.0);
		Out->SetNumberField(TEXT("aspect_error_percent"), FMath::RoundToDouble(AspectErrorPercent * 10.0) / 10.0);
		Out->SetNumberField(TEXT("filled_percent_reference"), FMath::RoundToDouble(Fill(RefNorm) * 10.0) / 10.0);
		Out->SetNumberField(TEXT("filled_percent_model"), FMath::RoundToDouble(Fill(ModelNorm) * 10.0) / 10.0);
		Out->SetArrayField(TEXT("where_it_differs"), Hints);
		Out->SetStringField(TEXT("reference_background"), RefSpread < 12.0 ? TEXT("plain (reliable)") : TEXT("busy (silhouette may be unreliable; judge by eye too)"));
		if (ShadowPixels > 0)
		{
			Out->SetStringField(TEXT("shadow_handling"), FString::Printf(TEXT("A floor shadow was detected in the reference and ignored (%d pixels), so it does not count as part of the object."), ShadowPixels));
		}
		Out->SetStringField(TEXT("picture_legend"), TEXT("Left: reference. Middle: model. Right: overlap, grey = both, red = model only, blue = reference only."));
		if (Meta.HeightCm > 0) { Out->SetNumberField(TEXT("reference_height_cm_from_notes"), Meta.HeightCm); }
		Result.SummaryJson = CondensedJson(Out);
		Result.bOk = true;
		return Result;
	}
}
