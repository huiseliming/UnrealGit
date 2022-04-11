// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealGit.h"
#include "GitMetadata.h"

#define LOCTEXT_NAMESPACE "FUnrealGitModule"

void FUnrealGitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (FGitMetadata::IsRunGitCommandError())
	{
		UE_LOG(LogTemp, Error, TEXT("IsRunGitCommandError : %s"), FGitMetadata::IsRunGitCommandError() ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Error, TEXT("IsDirty       : %s"), FGitMetadata::IsDirty() ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Error, TEXT("AuthorName    : %s"), FGitMetadata::AuthorName());
		UE_LOG(LogTemp, Error, TEXT("AuthorEmail   : %s"), FGitMetadata::AuthorEmail());
		UE_LOG(LogTemp, Error, TEXT("CommitSHA1    : %s"), FGitMetadata::CommitSHA1());
		UE_LOG(LogTemp, Error, TEXT("CommitDate    : %s"), FGitMetadata::CommitDate());
		UE_LOG(LogTemp, Error, TEXT("CommitSubject : %s"), FGitMetadata::CommitSubject());
		UE_LOG(LogTemp, Error, TEXT("CommitBody    : %s"), FGitMetadata::CommitBody());
		UE_LOG(LogTemp, Error, TEXT("Describe      : %s"), FGitMetadata::Describe());
		UE_LOG(LogTemp, Error, TEXT("Tag           : %s"), FGitMetadata::Tag());
		UE_LOG(LogTemp, Error, TEXT("Version       : %s"), FGitMetadata::Version());
		UE_LOG(LogTemp, Error, TEXT("VersionMajor  : %s"), FGitMetadata::VersionMajor());
		UE_LOG(LogTemp, Error, TEXT("VersionMinor  : %s"), FGitMetadata::VersionMinor());
		UE_LOG(LogTemp, Error, TEXT("VersionPatch  : %s"), FGitMetadata::VersionPatch());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("IsRunGitCommandError : %s"), FGitMetadata::IsRunGitCommandError() ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Log, TEXT("IsDirty       : %s"), FGitMetadata::IsDirty() ? TEXT("True") : TEXT("False"));
		UE_LOG(LogTemp, Log, TEXT("AuthorName    : %s"), FGitMetadata::AuthorName());
		UE_LOG(LogTemp, Log, TEXT("AuthorEmail   : %s"), FGitMetadata::AuthorEmail());
		UE_LOG(LogTemp, Log, TEXT("CommitSHA1    : %s"), FGitMetadata::CommitSHA1());
		UE_LOG(LogTemp, Log, TEXT("CommitDate    : %s"), FGitMetadata::CommitDate());
		UE_LOG(LogTemp, Log, TEXT("CommitSubject : %s"), FGitMetadata::CommitSubject());
		UE_LOG(LogTemp, Log, TEXT("CommitBody    : %s"), FGitMetadata::CommitBody());
		UE_LOG(LogTemp, Log, TEXT("Describe      : %s"), FGitMetadata::Describe());
		UE_LOG(LogTemp, Log, TEXT("Tag           : %s"), FGitMetadata::Tag());
		UE_LOG(LogTemp, Log, TEXT("Version       : %s"), FGitMetadata::Version());
		UE_LOG(LogTemp, Log, TEXT("VersionMajor  : %s"), FGitMetadata::VersionMajor());
		UE_LOG(LogTemp, Log, TEXT("VersionMinor  : %s"), FGitMetadata::VersionMinor());
		UE_LOG(LogTemp, Log, TEXT("VersionPatch  : %s"), FGitMetadata::VersionPatch());
	}
}

void FUnrealGitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealGitModule, UnrealGit)