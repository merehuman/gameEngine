//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "File.h"

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

using namespace Azul;

// used for teardown
static File::Handle fh_file1;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(SetBaseDir_SUCCESS, TestConfig::ALL)
{
#if SetBaseDir_SUCCESS

	File::Error  ferror;

	ferror = File::SetBaseDir("C:\\Code\\Monkey\\");

	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(SetBaseDir_SUCCESS)
{
#if SetBaseDir_SUCCESS

	system("del /F *.bin");

#endif
}

// --- End of File ---
