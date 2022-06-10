// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAME_FOR_OOP_KR : ModuleRules
{
	public GAME_FOR_OOP_KR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG", "InputCore", "HeadMountedDisplay", "AIModule" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
