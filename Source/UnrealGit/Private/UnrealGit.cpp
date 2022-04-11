// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealGit.h"
#include "GitMetadata.h"

#define LOCTEXT_NAMESPACE "FUnrealGitModule"

void FUnrealGitModule::StartupModule()
{
#if IS_RUN_GIT_COMMAND_ERROR
#define LOG_VERBOSITY Error
#else
#define LOG_VERBOSITY Log
#endif
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("IsRunGitCommandError : %s"), FGitMetadata::IsRunGitCommandError() ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("IsDirty       : %s"), FGitMetadata::IsDirty() ? TEXT("True") : TEXT("False"));
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("AuthorName    : %s"), FGitMetadata::AuthorName());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("AuthorEmail   : %s"), FGitMetadata::AuthorEmail());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("CommitSHA1    : %s"), FGitMetadata::CommitSHA1());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("CommitDate    : %s"), FGitMetadata::CommitDate());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("CommitSubject : %s"), FGitMetadata::CommitSubject());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("CommitBody    : %s"), FGitMetadata::CommitBody());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("Describe      : %s"), FGitMetadata::Describe());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("Tag           : %s"), FGitMetadata::Tag());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("Version       : %s"), FGitMetadata::Version());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("VersionMajor  : %s"), FGitMetadata::VersionMajor());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("VersionMinor  : %s"), FGitMetadata::VersionMinor());
	UE_LOG(LogTemp, LOG_VERBOSITY, TEXT("VersionPatch  : %s"), FGitMetadata::VersionPatch());

}

void FUnrealGitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealGitModule, UnrealGit)