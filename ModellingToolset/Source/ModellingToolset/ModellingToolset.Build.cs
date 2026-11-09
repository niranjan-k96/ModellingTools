// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ModellingToolset : ModuleRules
{
	public ModellingToolset(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"ToolsetRegistry",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"ApplicationCore",
				"AssetTools",
				"AssetRegistry",
				"DeveloperSettings",
				"InputCore",
				"DynamicMesh",
				"GeometryCore",
				"GeometryFramework",
				"GeometryScriptingCore",
				"ImageCore",
				"ImageWrapper",
				"Json",
				"JsonUtilities",
				"MaterialEditor",
				"ModelContextProtocol",
				"RenderCore",
				"RHI",
				"Slate",
				"SlateCore",
				"ToolMenus",
				"UnrealEd",
			}
		);
	}
}


