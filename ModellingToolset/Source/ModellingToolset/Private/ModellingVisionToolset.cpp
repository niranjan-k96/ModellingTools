// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingVisionToolset.h"

#include "ModellingCapture.h"
#include "ModellingCompare.h"
#include "ModellingToolsetUtils.h"

#include "HAL/FileManager.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"

using namespace ModellingToolset;

FModellingCapture UModellingVisionToolset::CaptureViews(
	const FString& ActorNames, const FString& Views, const FString& ViewMode,
	int32 Resolution, bool bIsolate, bool bForcePerspective, const FString& Label)
{
	FModellingCapture Out;

	FCaptureRequest Request;
	Request.ActorNames = ActorNames;
	Request.Views = Views;
	Request.ViewMode = ViewMode;
	Request.Resolution = Resolution;
	Request.bIsolate = bIsolate;
	Request.bForcePerspective = bForcePerspective;
	Request.Label = Label;

	const FCaptureResult Result = ModellingToolset::CaptureViews(Request);
	if (!Result.bOk)
	{
		Fail(Result.Error);
		return Out;
	}

	Out.Image.SetFromBitmap(Result.Sheet, Result.SheetSize);
	Out.Summary = Result.SummaryJson;
	return Out;
}

FModellingComparison UModellingVisionToolset::CompareToReference(const FString& ReferenceName, const FString& View, const FString& ActorNames)
{
	FModellingComparison Out;
	const FCompareResult Result = ModellingToolset::CompareToReference(ReferenceName, View, ActorNames);
	if (!Result.bOk)
	{
		Fail(Result.Error);
		return Out;
	}
	Out.Image.SetFromBitmap(Result.Image, Result.ImageSize);
	Out.Summary = Result.SummaryJson;
	return Out;
}

FString UModellingVisionToolset::StartSession(const FString& Name)
{
	return StartCaptureSession(Name);
}

FString UModellingVisionToolset::ListProgressImages(int32 MaxItems)
{
	const FString Root = GetProgressDir();
	TArray<FString> Files;
	IFileManager::Get().FindFilesRecursive(Files, *Root, TEXT("*.png"), /*Files=*/true, /*Directories=*/false);
	Files.Sort();

	const int32 Count = FMath::Clamp(MaxItems, 1, 200);
	TArray<TSharedPtr<FJsonValue>> Items;
	for (int32 i = Files.Num() - 1; i >= 0 && Items.Num() < Count; --i)
	{
		FString Relative = Files[i];
		if (FPaths::MakePathRelativeTo(Relative, *(Root + TEXT("/"))))
		{
			Items.Add(MakeShared<FJsonValueString>(Relative));
		}
	}
	return ToJsonString(Items);
}

FToolsetImage UModellingVisionToolset::GetProgressImage(const FString& RelativePath, int32 MaxDimension)
{
	FToolsetImage Image;
	const FString Root = GetProgressDir();
	const FString Full = FPaths::ConvertRelativePathToFull(Root / RelativePath);
	if (!IsPathUnder(Full, Root))
	{
		Fail(TEXT("Path must be inside the progress folder."));
		return Image;
	}
	if (!Full.EndsWith(TEXT(".png"), ESearchCase::IgnoreCase) || !IFileManager::Get().FileExists(*Full))
	{
		Fail(FString::Printf(TEXT("No PNG found at '%s'. Use ListProgressImages."), *RelativePath));
		return Image;
	}

	TArray<FColor> Pixels;
	FIntPoint Size, Original;
	FString Error;
	if (!LoadImageFile(Full, MaxDimension, Pixels, Size, Original, Error))
	{
		Fail(Error);
		return Image;
	}
	Image.SetFromBitmap(Pixels, Size);
	return Image;
}
