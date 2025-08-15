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
static File::Handle fh_file25;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Close_ERROR_Close,TestConfig::ALL)
{
#if Close_ERROR_Close 

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file4.bin", File::Mode::WRITE);
	fh_file25 = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::CLOSE_FAIL);

#endif
} TEST_END

TEST_TEARDOWN(Close_ERROR_Close)
{
#if Close_ERROR_Close 

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file25, &flags);
	if (status)
	{
		File::Close(fh_file25);
	}
	system("del /F *.bin");

#endif
}

// --- End of File ---
