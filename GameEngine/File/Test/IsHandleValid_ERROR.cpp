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
static File::Handle fh_file1b;
static File::Handle fh_file1c;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(IsHandleValid_ERROR, TestConfig::ALL)
{
#if IsHandleValid_ERROR

	File::Handle fh(nullptr);
	File::Error  ferror;

	ferror = File::Open(fh, "file1.bin", File::Mode::WRITE);
	// used to clean up at end of test
	fh_file1b = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	bool status = File::IsHandleValid(fh);
	CHECK(status == true);

	ferror = File::Close(fh);
	// used to clean up at end of test
	fh_file1c = fh;

	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr );

	status = File::IsHandleValid(fh);
	CHECK(status == false);

#endif
} TEST_END

TEST_TEARDOWN(IsHandleValid_ERROR)
{
#if IsHandleValid_ERROR

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file1b, &flags);
	if (status)
	{
		File::Close(fh_file1b);
	}

	status = GetHandleInformation(fh_file1c, &flags);
	if (status)
	{
		File::Close(fh_file1c);
	}

	system("del /F *.bin");

#endif
}

// --- End of File ---
