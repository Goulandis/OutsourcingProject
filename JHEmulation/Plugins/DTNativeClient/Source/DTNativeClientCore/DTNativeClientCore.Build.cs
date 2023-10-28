using System.IO;
using UnrealBuildTool;

public class DTNativeClientCore : ModuleRules
{
	public DTNativeClientCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"Projects"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Slate",
			"SlateCore",
		});

		string ThirdpartyPath = Path.Combine(PluginDirectory, "Source", "ThirdParty");

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicIncludePaths.Add(Path.Combine(ThirdpartyPath, "dtnacl", "api", "c"));

			PublicAdditionalLibraries.Add(Path.Combine(ThirdpartyPath, "dtnacl", "lib", "windows", "x64", "dtnacl_core.lib"));

			RuntimeDependencies.Add("$(BinaryOutputDir)/dtnacl_core.dll", Path.Combine(ThirdpartyPath, "dtnacl", "bin", "windows", "x64", "dtnacl_core.dll"));
		}
	}
}
