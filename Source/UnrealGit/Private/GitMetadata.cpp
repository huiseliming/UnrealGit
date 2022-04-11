#include "GitMetadata.h"


//bool FGitMetadata::IsMetadataPopulated()
//{
//	return true;
//}

bool FGitMetadata::RunGitCommandHasError()
{
	return RUN_GIT_COMMAND_HAS_ERROR;
}

bool FGitMetadata::IsDirty()
{
	return GIT_IS_DIRTY;
}

TCHAR* FGitMetadata::AuthorName()
{
	return GIT_AUTHOR_NAME;
}

TCHAR* FGitMetadata::AuthorEmail()
{
	return GIT_AUTHOR_EMAIL;
}

TCHAR* FGitMetadata::CommitSHA1()
{
	return GIT_HEAD_SHA1;
}

TCHAR* FGitMetadata::CommitDate()
{
	return GIT_COMMIT_DATE_ISO8601;
}

TCHAR* FGitMetadata::CommitSubject()
{
	return GIT_COMMIT_SUBJECT;
}

TCHAR* FGitMetadata::CommitBody()
{
	return GIT_COMMIT_BODY;
}

TCHAR* FGitMetadata::Describe()
{
	return GIT_DESCRIBE;
}

TCHAR* FGitMetadata::Tag()
{
	return GIT_TAG;
}

TCHAR* FGitMetadata::Version()
{
	return GIT_VERSION;
}

TCHAR* FGitMetadata::VersionMajor()
{
	return GIT_VERSION_MAJOR;
}

TCHAR* FGitMetadata::VersionMinor()
{
	return GIT_VERSION_MINOR;
}

TCHAR* FGitMetadata::VersionPatch()
{
	return GIT_VERSION_PATCH;
}
