// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModellingToolsetModule.h"

#include "ModellingMcpTools.h"

#include "ModellingAssetToolset.h"
#include "ModellingBatchToolset.h"
#include "ModellingDeformToolset.h"
#include "ModellingEditToolset.h"
#include "ModellingJobToolset.h"
#include "ModellingMaterialsToolset.h"
#include "ModellingMeasureToolset.h"
#include "ModellingPrimitivesToolset.h"
#include "ModellingReferenceToolset.h"
#include "ModellingSceneToolset.h"
#include "ModellingSurfaceToolset.h"
#include "ModellingTextureToolset.h"
#include "ModellingTopologyToolset.h"
#include "ModellingVisionToolset.h"

#include "UI/ModellingAssistantUI.h"

#include "IModelContextProtocolModule.h"
#include "Modules/ModuleManager.h"
#include "ToolsetRegistry/UToolsetRegistry.h"

IMPLEMENT_MODULE(FModellingToolsetModule, ModellingToolset)

namespace
{
	/** All toolsets in registration order. The registry validates every AICallable function on registration and logs a warning for bad ones. */
	TArray<UClass*> GetToolsetClasses()
	{
		return {
			UModellingJobToolset::StaticClass(),
			UModellingSceneToolset::StaticClass(),
			UModellingPrimitivesToolset::StaticClass(),
			UModellingEditToolset::StaticClass(),
			UModellingDeformToolset::StaticClass(),
			UModellingTopologyToolset::StaticClass(),
			UModellingMaterialsToolset::StaticClass(),
			UModellingTextureToolset::StaticClass(),
			UModellingSurfaceToolset::StaticClass(),
			UModellingMeasureToolset::StaticClass(),
			UModellingBatchToolset::StaticClass(),
			UModellingAssetToolset::StaticClass(),
			UModellingVisionToolset::StaticClass(),
			UModellingReferenceToolset::StaticClass(),
		};
	}
}

void FModellingToolsetModule::StartupModule()
{
	// Toolsets must be registered explicitly; they are not discovered automatically.
	for (UClass* Class : GetToolsetClasses())
	{
		UToolsetRegistry::RegisterToolsetClass(Class);
	}

	// Folders are created lazily by the tools that need them, so projects that never use the plugin stay clean.
	if (IModelContextProtocolModule* MCP = IModelContextProtocolModule::Get())
	{
		CaptureViewsTool = MakeShared<FModellingCaptureViewsMcpTool>();
		GetReferenceTool = MakeShared<FModellingGetReferenceMcpTool>();
		CompareTool = MakeShared<FModellingCompareMcpTool>();
		MCP->AddTool(CompareTool.ToSharedRef());
		MCP->AddTool(CaptureViewsTool.ToSharedRef());
		MCP->AddTool(GetReferenceTool.ToSharedRef());
	}

	// The toolbar button and the Modelling Assistant panel.
	ModellingToolset::RegisterAssistantUI();
}

void FModellingToolsetModule::ShutdownModule()
{
	ModellingToolset::UnregisterAssistantUI();

	if (IModelContextProtocolModule* MCP = IModelContextProtocolModule::Get())
	{
		if (CompareTool.IsValid()) { MCP->RemoveTool(CompareTool.ToSharedRef()); }
		if (CaptureViewsTool.IsValid()) { MCP->RemoveTool(CaptureViewsTool.ToSharedRef()); }
		if (GetReferenceTool.IsValid()) { MCP->RemoveTool(GetReferenceTool.ToSharedRef()); }
	}
	CompareTool.Reset();
	CaptureViewsTool.Reset();
	GetReferenceTool.Reset();

	TArray<UClass*> Classes = GetToolsetClasses();
	for (int32 i = Classes.Num() - 1; i >= 0; --i)
	{
		UToolsetRegistry::UnregisterToolsetClass(Classes[i]);
	}
}




