// Copyright Evan Allen

using UnrealBuildTool;
using System.Collections.Generic;

public class DungeonCrawlerEditorTarget : TargetRules
{
	public DungeonCrawlerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DungeonCrawler" } );
	}
}
