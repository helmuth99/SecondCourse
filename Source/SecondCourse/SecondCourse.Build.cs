// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SecondCourse : ModuleRules
{
	public SecondCourse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

<<<<<<< Updated upstream
		PublicDependencyModuleNames.AddRange(new string[] { "Niagara", "NavigationSystem" });
=======
		PublicDependencyModuleNames.AddRange(new string[] { "Niagara", "NavigationSystem", "GameplayTasks","UMG","GameplayTags" });
>>>>>>> Stashed changes

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
