// Copyright Evan Allen

using UnrealBuildTool;
using System.Collections.Generic;

public class DungeonCrawlerTarget : TargetRules
{
	public DungeonCrawlerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DungeonCrawler" } );
	}
}
