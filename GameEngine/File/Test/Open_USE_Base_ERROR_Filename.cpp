//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "File.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

using namespace Azul;

// used for teardown
static File::Handle fh_file4;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_USE_Base_ERROR_Filename, TestConfig::ALL)
{
#if Open_USE_Base_ERROR_Filename 

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, nullptr, File::Mode::WRITE, true);
	fh_file4 = fh;

	CHECK(ferror == File::Error::OPEN_FILENAME_FAIL);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Open_USE_Base_ERROR_Filename)
{
#if Open_USE_Base_ERROR_Filename 

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file4, &flags);
	if (status)
	{
		File::Close(fh_file4);
	}
	system("del /F *.bin");

#endif
}

// --- End of File ---
