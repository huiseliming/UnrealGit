// Copyright Epic Games, Inc. All Rights Reserved.

using System.Diagnostics;
using EpicGames.Core;
using UnrealBuildTool;

struct GitCommandOutputInfo
{
	public string CommandArguments;
	public string PreDefinitionsMacroName;
	public string PrintOutputName;
}

public class UnrealGit : ModuleRules
{
	public string ProjectDir
	{
		get
		{
			return System.IO.Path.GetFullPath(System.IO.Path.Combine(ModuleDirectory, "../../"));
		}
	}
	
	
	public UnrealGit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
		string gitCommand = "git";
		Log.TraceInformation("->- Git Metadata Generate ->-");
		bool IsRunGitCommandError = false;
		char[] CharsToTrim = { '\r', '\n' };
		Process process;
		string output;
		ProcessStartInfo startInfo = new ProcessStartInfo();
		startInfo.RedirectStandardOutput = true;
		startInfo.WorkingDirectory = ProjectDir;
		startInfo.FileName = gitCommand;
		
		startInfo.Arguments = @"status --porcelain -unormal";
		process = Process.Start(startInfo);
		process.WaitForExit();
		bool GitIsDirty = true;
		if (process.ExitCode == 0)
		{ 
			output = process.StandardOutput.ReadToEnd();
			if (output.Length == 0)
				GitIsDirty = false;
		}
		else
			IsRunGitCommandError = true;
		PrivateDefinitions.Add("GIT_IS_DIRTY=" + (GitIsDirty? "true" : "false"));
		Log.TraceInformation("  GitIsDirty = " + (GitIsDirty? "true" : "false"));
		GitCommandOutputInfo[] GitCommandArgumentsArray = new GitCommandOutputInfo[]
		{
			new GitCommandOutputInfo
			{ 
				CommandArguments = @"show -s --format=%H",
				PreDefinitionsMacroName = "GIT_HEAD_SHA1",
				PrintOutputName = "GitHeadSHA1" 
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"show -s --format=%an",
				PreDefinitionsMacroName = "GIT_AUTHOR_NAME",
				PrintOutputName = "GitAuthorName"
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"show -s --format=%ae",
				PreDefinitionsMacroName = "GIT_AUTHOR_EMAIL",
				PrintOutputName = "GitAuthorEmail"
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"show -s --format=%ci",
				PreDefinitionsMacroName = "GIT_COMMIT_DATE_ISO8601",
				PrintOutputName = "GitCommitDateISO8601"
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"show -s --format=%s",
				PreDefinitionsMacroName = "GIT_COMMIT_SUBJECT",
				PrintOutputName = "GitCommitSubject"
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"show -s --format=%b",
				PreDefinitionsMacroName = "GIT_COMMIT_BODY",
				PrintOutputName = "GitCommitBody"
			},
			new GitCommandOutputInfo
			{
				CommandArguments = @"describe --always",
				PreDefinitionsMacroName = "GIT_DESCRIBE",
				PrintOutputName = "GitDescribe"
			}
		};
		for (int i = 0; i < GitCommandArgumentsArray.Length; i++)
		{
			startInfo.Arguments = GitCommandArgumentsArray[i].CommandArguments + " HEAD";
			process = Process.Start(startInfo);
			process.WaitForExit();
			output = "";
			if (process.ExitCode == 0)
				output = process.StandardOutput.ReadToEnd().Trim(CharsToTrim);
			else
				IsRunGitCommandError = true;
			PrivateDefinitions.Add(GitCommandArgumentsArray[i].PreDefinitionsMacroName + "=TEXT(\"" + output + "\")");
			Log.TraceInformation("  " + GitCommandArgumentsArray[i].PrintOutputName + " = " + output);
		}
		startInfo.Arguments = "describe --tags HEAD";
		process = Process.Start(startInfo);
		process.WaitForExit();
		string GitTag = "v?.?.?";
		string GitVersion = "?.?.?";
		string GitVersionMajor = "?";
		string GitVersionMinor = "?";
		string GitVersionPatch = "?";
		if (process.ExitCode == 0)
		{
			GitTag = process.StandardOutput.ReadToEnd().Trim(CharsToTrim);
			// tag format must be "v[Major].[Minor].[Patch]" or "[Major].[Minor].[Patch]"
			if (GitTag[0] == 'v')
				GitVersion = GitTag.Substring(1);
			else
				GitVersion = GitTag;
			string[] VersionSplitNumbers = GitVersion.Split('.');
			if (0 < VersionSplitNumbers.Length) GitVersionMajor = VersionSplitNumbers[0];
			if (1 < VersionSplitNumbers.Length) GitVersionMinor = VersionSplitNumbers[1];
			if (2 < VersionSplitNumbers.Length) GitVersionPatch = VersionSplitNumbers[2];
		}
		else
			IsRunGitCommandError = true;
		PrivateDefinitions.Add("GIT_TAG=TEXT(\"" + GitTag + "\")");
		Log.TraceInformation("  GitTag = " + GitTag);

		PrivateDefinitions.Add("GIT_VERSION=TEXT(\"" + GitVersion + "\")");
		PrivateDefinitions.Add("GIT_VERSION_MAJOR=TEXT(\"" + GitVersionMajor + "\")");
		PrivateDefinitions.Add("GIT_VERSION_MINOR=TEXT(\"" + GitVersionMinor + "\")");
		PrivateDefinitions.Add("GIT_VERSION_PATCH=TEXT(\"" + GitVersionPatch + "\")");
		Log.TraceInformation("  GitVersion = " + GitVersion);
		Log.TraceInformation("  GitVersionMajor = " + GitVersionMajor);
		Log.TraceInformation("  GitVersionMinor = " + GitVersionMinor);
		Log.TraceInformation("  GitVersionPatch = " + GitVersionPatch);
		Log.TraceInformation("-<- Git Metadata Generate -<-");
		PrivateDefinitions.Add("IS_RUN_GIT_COMMAND_ERROR=" + (IsRunGitCommandError ? "true" : "false"));
		// Process.Start(gitCommand, gitCommitArgument);
		// Process.Start(gitCommand, gitPushArgument);
	}
}
