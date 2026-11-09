// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ToolsetRegistry/AgentSkill.h"

#include "ModellingSkill.generated.h"

/**
 * Agent skill that teaches the AI the Modelling Toolset workflow: read the job, study every reference image FIRST,
 * model step by step while checking screenshots, then ask the user to review. The user either requests changes or
 * presses Done, which exports the FBX. Discovered automatically through the Agent Skill toolset (ListSkills / GetSkills).
 */
UCLASS()
class UModellingWorkflowSkill : public UAgentSkill
{
	GENERATED_BODY()

public:
	UModellingWorkflowSkill();

protected:
	virtual FString GeneratePrompt_Implementation(const FString& InitialInstructions) const override;
};
