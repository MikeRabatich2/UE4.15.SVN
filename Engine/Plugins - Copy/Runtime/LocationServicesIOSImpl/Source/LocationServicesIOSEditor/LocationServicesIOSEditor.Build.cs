// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LocationServicesIOSEditor : ModuleRules
{
    public LocationServicesIOSEditor(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
				}
			);

		PrivateIncludePaths.Add("LocationServicesIOSEditor/Private");

		PrivateDependencyModuleNames.AddRange(
			new string[] 
			{
				"Core",
				"CoreUObject",
                "Engine",
			}
		);

		if (Target.Type == TargetRules.TargetType.Editor)
		{
			DynamicallyLoadedModuleNames.AddRange(
				new string[] 
				{
					"Settings",
				}
			);

			PrivateIncludePathModuleNames.AddRange(
				new string[] 
				{
					"Settings",
				}
			);
		}
	}
}
