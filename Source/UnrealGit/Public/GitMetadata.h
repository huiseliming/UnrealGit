#pragma once


class FGitMetadata {
public:
	// Is the metadata populated? We may not have metadata if
	// there wasn't a .git directory (e.g. downloaded source
	// code without revision history).
	//static bool IsMetadataPopulated();
	
	static bool RunGitCommandHasError();
	
	// Were there any uncommitted changes that won't be reflected
	// in the CommitID?
	static bool IsDirty();

	// The commit author's name.
	static TCHAR* AuthorName();
	// The commit author's email.
	static TCHAR* AuthorEmail();
	// The commit SHA1.
	static TCHAR* CommitSHA1();
	// The ISO8601 commit date.
	static TCHAR* CommitDate();
	// The commit subject.
	static TCHAR* CommitSubject();
	// The commit body.
	static TCHAR* CommitBody();
	// The commit describe.
	static TCHAR* Describe();

	static TCHAR* Tag();
	static TCHAR* Version();
	static TCHAR* VersionMajor();
	static TCHAR* VersionMinor();
	static TCHAR* VersionPatch();
};

