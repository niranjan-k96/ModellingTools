// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingMcpTools.h"

#include "ModellingCapture.h"
#include "ModellingCompare.h"
#include "ModellingToolsetUtils.h"

#include "Dom/JsonObject.h"
#include "HAL/FileManager.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "JsonDomBuilder.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "ModelContextProtocolToolResults.h"
#include "Modules/ModuleManager.h"

using namespace ModellingToolset;

namespace
{
	/** Encodes pixels as PNG; returns an empty array on failure. */
	TArray<uint8> EncodePng(const TArray<FColor>& Pixels, FIntPoint Size)
	{
		TArray<uint8> Out;
		IImageWrapperModule& Module = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
		const TSharedPtr<IImageWrapper> Wrapper = Module.CreateImageWrapper(EImageFormat::PNG);
		if (Wrapper.IsValid() && Wrapper->SetRaw(Pixels.GetData(), Pixels.Num() * sizeof(FColor), Size.X, Size.Y, ERGBFormat::BGRA, 8))
		{
			const TArray64<uint8>& Data = Wrapper->GetCompressed();
			Out.Append(Data.GetData(), static_cast<int32>(Data.Num()));
		}
		return Out;
	}

	/** Builds an MCP result with a leading text block followed by the image block. */
	FModelContextProtocolToolResult MakeImageWithText(const FString& Text, const TArray<FColor>& Pixels, FIntPoint Size)
	{
		TArray<uint8> Png = EncodePng(Pixels, Size);
		if (Png.IsEmpty())
		{
			return UE::ModelContextProtocol::MakeErrorResult(TEXT("Failed to encode the image."));
		}

		FModelContextProtocolToolResult Result = UE::ModelContextProtocol::MakeImageResult(TEXT("image/png"), TArrayView<uint8>(Png));
		if (Result.JsonObject.IsValid())
		{
			const TArray<TSharedPtr<FJsonValue>>* Existing = nullptr;
			if (Result.JsonObject->TryGetArrayField(TEXT("content"), Existing) && Existing)
			{
				TArray<TSharedPtr<FJsonValue>> Content = *Existing;
				Content.Insert(MakeShared<FJsonValueObject>(UE::ModelContextProtocol::MakeTextContentObject(Text)), 0);
				Result.JsonObject->SetArrayField(TEXT("content"), Content);
			}
		}
		return Result;
	}

	FJsonDomBuilder::FObject StringProp(const TCHAR* Description)
	{
		FJsonDomBuilder::FObject P;
		P.Set(TEXT("type"), TEXT("string"));
		P.Set(TEXT("description"), Description);
		return P;
	}

	FJsonDomBuilder::FObject IntProp(const TCHAR* Description)
	{
		FJsonDomBuilder::FObject P;
		P.Set(TEXT("type"), TEXT("integer"));
		P.Set(TEXT("description"), Description);
		return P;
	}

	FJsonDomBuilder::FObject BoolProp(const TCHAR* Description)
	{
		FJsonDomBuilder::FObject P;
		P.Set(TEXT("type"), TEXT("boolean"));
		P.Set(TEXT("description"), Description);
		return P;
	}
}

// ---- modelling_capture_views ---------------------------------------------------------------------

FString FModellingCaptureViewsMcpTool::GetName() const
{
	return TEXT("modelling_capture_views");
}

FString FModellingCaptureViewsMcpTool::GetDescription() const
{
	return TEXT("Renders the model built with the Modelling Toolset from several camera angles, saves every view to the progress folder, ")
		TEXT("and returns a contact sheet image plus a JSON summary. Axis: +X front, +Y right, +Z up. Call after every meaningful modelling step.");
}

TSharedPtr<FJsonObject> FModellingCaptureViewsMcpTool::GetInputJsonSchema() const
{
	FJsonDomBuilder::FObject Properties;
	Properties.Set(TEXT("actor_names"), StringProp(TEXT("Comma-separated actor labels to frame. Empty frames every actor the toolset created.")));
	Properties.Set(TEXT("views"), StringProp(TEXT("Comma-separated: iso, iso_back, front, back, right, left, top, bottom. Default 'iso,front,right,top'.")));
	Properties.Set(TEXT("view_mode"), StringProp(TEXT("lit (default, fixed studio lighting), clay (neutral grey, best for form), unlit (flat colour), or normals (surface direction as colour).")));
	Properties.Set(TEXT("resolution"), IntProp(TEXT("Pixel size of one square tile (128 to 2048). 0 or omitted uses the project setting.")));
	Properties.Set(TEXT("isolate"), BoolProp(TEXT("Render only the framed actors and hide the rest of the level.")));
	Properties.Set(TEXT("force_perspective"), BoolProp(TEXT("Use perspective for axis views instead of orthographic.")));
	Properties.Set(TEXT("label"), StringProp(TEXT("Short tag used in file names and the log, e.g. 'added_roof'.")));

	FJsonDomBuilder::FObject Schema;
	Schema.Set(TEXT("type"), TEXT("object"));
	Schema.Set(TEXT("properties"), Properties);
	return Schema.AsJsonObject();
}

FModelContextProtocolToolResult FModellingCaptureViewsMcpTool::Run(const TSharedPtr<FJsonObject>& Params)
{
	FCaptureRequest Request;
	if (Params.IsValid())
	{
		Params->TryGetStringField(TEXT("actor_names"), Request.ActorNames);
		Params->TryGetStringField(TEXT("views"), Request.Views);
		FString Mode;
		if (Params->TryGetStringField(TEXT("view_mode"), Mode) && !Mode.IsEmpty())
		{
			Request.ViewMode = Mode;
		}
		double Resolution = 0;
		if (Params->TryGetNumberField(TEXT("resolution"), Resolution))
		{
			Request.Resolution = static_cast<int32>(Resolution);
		}
		Params->TryGetBoolField(TEXT("isolate"), Request.bIsolate);
		Params->TryGetBoolField(TEXT("force_perspective"), Request.bForcePerspective);
		Params->TryGetStringField(TEXT("label"), Request.Label);
	}

	const FCaptureResult Result = CaptureViews(Request);
	if (!Result.bOk)
	{
		return UE::ModelContextProtocol::MakeErrorResult(Result.Error);
	}
	return MakeImageWithText(Result.SummaryJson, Result.Sheet, Result.SheetSize);
}

// ---- modelling_compare_to_reference --------------------------------------------------------------

FString FModellingCompareMcpTool::GetName() const
{
	return TEXT("modelling_compare_to_reference");
}

FString FModellingCompareMcpTool::GetDescription() const
{
	return TEXT("Compares the model with a reference picture from a straight-on view. Returns a side-by-side image (reference, model, overlap map) ")
		TEXT("and a JSON summary with an overlap score, a verdict and plain hints about where the shapes differ. Use after blocking out and before asking for review.");
}

TSharedPtr<FJsonObject> FModellingCompareMcpTool::GetInputJsonSchema() const
{
	FJsonDomBuilder::FObject Properties;
	Properties.Set(TEXT("reference"), StringProp(TEXT("File name of the reference picture, from ListReferences.")));
	Properties.Set(TEXT("view"), StringProp(TEXT("front, back, left, right, top or bottom. Empty uses the reference's label, or front.")));
	Properties.Set(TEXT("actor_names"), StringProp(TEXT("Comma-separated actor labels to compare. Empty uses every actor the toolset created.")));

	FJsonDomBuilder::FArray Required;
	Required.Add(TEXT("reference"));

	FJsonDomBuilder::FObject Schema;
	Schema.Set(TEXT("type"), TEXT("object"));
	Schema.Set(TEXT("properties"), Properties);
	Schema.Set(TEXT("required"), Required);
	return Schema.AsJsonObject();
}

FModelContextProtocolToolResult FModellingCompareMcpTool::Run(const TSharedPtr<FJsonObject>& Params)
{
	FString Reference, View, ActorNames;
	if (!Params.IsValid() || !Params->TryGetStringField(TEXT("reference"), Reference) || Reference.IsEmpty())
	{
		return UE::ModelContextProtocol::MakeErrorResult(TEXT("Missing required 'reference'."));
	}
	Params->TryGetStringField(TEXT("view"), View);
	Params->TryGetStringField(TEXT("actor_names"), ActorNames);

	const FCompareResult Result = CompareToReference(Reference, View, ActorNames);
	if (!Result.bOk)
	{
		return UE::ModelContextProtocol::MakeErrorResult(Result.Error);
	}
	return MakeImageWithText(Result.SummaryJson, Result.Image, Result.ImageSize);
}

// ---- modelling_get_reference ---------------------------------------------------------------------

FString FModellingGetReferenceMcpTool::GetName() const
{
	return TEXT("modelling_get_reference");
}

FString FModellingGetReferenceMcpTool::GetDescription() const
{
	return TEXT("Reads one reference image the user placed in the Modelling Toolset references folder and returns it as a real image ")
		TEXT("plus its notes text. Use the name from ModellingReferenceToolset ListReferences.");
}

TSharedPtr<FJsonObject> FModellingGetReferenceMcpTool::GetInputJsonSchema() const
{
	FJsonDomBuilder::FObject Properties;
	Properties.Set(TEXT("name"), StringProp(TEXT("File name inside the references folder, without folders.")));
	Properties.Set(TEXT("max_dimension"), IntProp(TEXT("Longest side in pixels after downscaling (128 to 4096). Default 1024.")));

	FJsonDomBuilder::FArray Required;
	Required.Add(TEXT("name"));

	FJsonDomBuilder::FObject Schema;
	Schema.Set(TEXT("type"), TEXT("object"));
	Schema.Set(TEXT("properties"), Properties);
	Schema.Set(TEXT("required"), Required);
	return Schema.AsJsonObject();
}

FModelContextProtocolToolResult FModellingGetReferenceMcpTool::Run(const TSharedPtr<FJsonObject>& Params)
{
	FString Name;
	if (!Params.IsValid() || !Params->TryGetStringField(TEXT("name"), Name) || Name.IsEmpty())
	{
		return UE::ModelContextProtocol::MakeErrorResult(TEXT("Missing required 'name'."));
	}
	double MaxDimension = 1024;
	Params->TryGetNumberField(TEXT("max_dimension"), MaxDimension);

	// Plain file names only; the resolved path must stay inside the references folder.
	const FString Dir = GetReferencesDir();
	if (Name != FPaths::GetCleanFilename(Name))
	{
		return UE::ModelContextProtocol::MakeErrorResult(TEXT("'name' must be a plain file name without folders."));
	}
	const FString Full = Dir / Name;
	if (!IsPathUnder(Full, Dir) || !IFileManager::Get().FileExists(*Full))
	{
		return UE::ModelContextProtocol::MakeErrorResult(FString::Printf(TEXT("Reference '%s' not found."), *Name));
	}

	TArray<FColor> Pixels;
	FIntPoint Size, Original;
	FString Error;
	if (!LoadImageFile(Full, static_cast<int32>(MaxDimension), Pixels, Size, Original, Error))
	{
		return UE::ModelContextProtocol::MakeErrorResult(Error);
	}

	FString Notes;
	for (const TCHAR* Ext : { TEXT("txt"), TEXT("md") })
	{
		const FString NotesPath = FPaths::ChangeExtension(Full, Ext);
		if (IFileManager::Get().FileExists(*NotesPath) && FFileHelper::LoadFileToString(Notes, *NotesPath))
		{
			break;
		}
	}

	const FString Text = FString::Printf(TEXT("%s (original %dx%d, returned %dx%d). Notes: %s"),
		*Name, Original.X, Original.Y, Size.X, Size.Y, Notes.IsEmpty() ? TEXT("(none)") : *Notes);
	return MakeImageWithText(Text, Pixels, Size);
}

