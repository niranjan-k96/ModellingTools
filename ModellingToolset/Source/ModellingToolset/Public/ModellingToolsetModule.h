// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"

class FModellingCaptureViewsMcpTool;
class FModellingCompareMcpTool;
class FModellingGetReferenceMcpTool;

/**
 * Editor-only module.
 *  - Toolsets (UToolsetDefinition subclasses) are discovered by the ToolsetRegistry through reflection.
 *  - Two raw MCP tools are registered here because they must return real image content blocks.
 */
class FModellingToolsetModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<FModellingCaptureViewsMcpTool> CaptureViewsTool;
	TSharedPtr<FModellingCompareMcpTool> CompareTool;
	TSharedPtr<FModellingGetReferenceMcpTool> GetReferenceTool;
};
