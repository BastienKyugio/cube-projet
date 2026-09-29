// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjetCube : ModuleRules
{
	public ProjetCube(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProjetCube",
			"ProjetCube/Variant_Platforming",
			"ProjetCube/Variant_Platforming/Animation",
			"ProjetCube/Variant_Combat",
			"ProjetCube/Variant_Combat/AI",
			"ProjetCube/Variant_Combat/Animation",
			"ProjetCube/Variant_Combat/Gameplay",
			"ProjetCube/Variant_Combat/Interfaces",
			"ProjetCube/Variant_Combat/UI",
			"ProjetCube/Variant_SideScrolling",
			"ProjetCube/Variant_SideScrolling/AI",
			"ProjetCube/Variant_SideScrolling/Gameplay",
			"ProjetCube/Variant_SideScrolling/Interfaces",
			"ProjetCube/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
