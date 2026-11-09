// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingReferenceToolset.h"

#include "ModellingToolsetUtils.h"

#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"

using namespace ModellingToolset;

namespace
{
	bool IsSupportedImage(const FString& FileName)
	{
		const FString Ext = FPaths::GetExtension(FileName).ToLower();
		return Ext == TEXT("png") || Ext == TEXT("jpg") || Ext == TEXT("jpeg") || Ext == TEXT("bmp");
	}

	FString ReadNotes(const FString& ImageFullPath)
	{
		for (const TCHAR* Ext : { TEXT("txt"), TEXT("md") })
		{
			const FString NotesPath = FPaths::ChangeExtension(ImageFullPath, Ext);
			FString Text;
			if (IFileManager::Get().FileExists(*NotesPath) && FFileHelper::LoadFileToString(Text, *NotesPath))
			{
				return Text;
			}
		}
		return FString();
	}
}

FString UModellingReferenceToolset::ListReferences()
{
	EnsureWorkspaceFolders();
	const FString Dir = GetReferencesDir();

	TArray<FString> Files;
	IFileManager::Get().FindFiles(Files, *(Dir / TEXT("*.*")), /*Files=*/true, /*Directories=*/false);
	Files.Sort();

	TArray<TSharedPtr<FJsonValue>> Items;
	for (const FString& File : Files)
	{
		if (!IsSupportedImage(File))
		{
			continue;
		}
		const FString Full = Dir / File;
		TSharedRef<FJsonObject> Item = MakeShared<FJsonObject>();
		Item->SetStringField(TEXT("name"), File);
		Item->SetNumberField(TEXT("size_bytes"), static_cast<double>(IFileManager::Get().FileSize(*Full)));
		Item->SetBoolField(TEXT("has_notes"), !ReadNotes(Full).IsEmpty());

		// What the user labelled this picture as (from notes like "view: front" or a name like House_front.png).
		const FReferenceMeta Meta = ReadReferenceMeta(File);
		Item->SetStringField(TEXT("view"), Meta.View.IsEmpty() ? FString(TEXT("unknown")) : Meta.View);
		if (Meta.HeightCm > 0) { Item->SetNumberField(TEXT("height_cm"), Meta.HeightCm); }
		if (Meta.WidthCm > 0) { Item->SetNumberField(TEXT("width_cm"), Meta.WidthCm); }
		if (Meta.DepthCm > 0) { Item->SetNumberField(TEXT("depth_cm"), Meta.DepthCm); }
		Items.Add(MakeShared<FJsonValueObject>(Item));
	}

	TSharedRef<FJsonObject> Out = MakeShared<FJsonObject>();
	Out->SetStringField(TEXT("references_folder"), Dir);
	Out->SetArrayField(TEXT("images"), Items);
	Out->SetStringField(TEXT("supported_formats"), TEXT("png, jpg, jpeg, bmp"));
	return ToJsonString(Out);
}

FModellingReference UModellingReferenceToolset::GetReference(const FString& Name, int32 MaxDimension)
{
	FModellingReference Result;

	// Plain file names only; the resolved path must stay inside the references folder.
	const FString Dir = GetReferencesDir();
	if (Name.IsEmpty() || Name != FPaths::GetCleanFilename(Name))
	{
		Fail(TEXT("Name must be a plain file name from ListReferences, without folders."));
		return Result;
	}
	const FString Full = Dir / Name;
	if (!IsPathUnder(Full, Dir) || !IFileManager::Get().FileExists(*Full))
	{
		Fail(FString::Printf(TEXT("Reference '%s' not found. Use ListReferences."), *Name));
		return Result;
	}

	TArray<FColor> Pixels;
	FIntPoint Size, Original;
	FString Error;
	if (!LoadImageFile(Full, MaxDimension, Pixels, Size, Original, Error))
	{
		Fail(Error);
		return Result;
	}

	Result.Image.SetFromBitmap(Pixels, Size);
	Result.Name = Name;
	Result.Notes = ReadNotes(Full);
	Result.OriginalWidth = Original.X;
	Result.OriginalHeight = Original.Y;
	return Result;
}
