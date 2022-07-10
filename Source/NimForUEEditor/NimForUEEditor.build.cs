using System.IO;
using UnrealBuildTool;
 
public class NimForUEEditor : ModuleRules
{
	public NimForUEEditor(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"UnrealEd",
			"Slate",
			"SlateCore",
		});
		PrivateDependencyModuleNames.AddRange(new string[] { });

	}

}