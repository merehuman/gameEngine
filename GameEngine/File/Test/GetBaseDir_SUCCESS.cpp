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

TEST_WITH_TEARDOWN(GetBaseDir_SUCCESS, TestConfig::ALL)
{
#if GetBaseDir_SUCCESS

	File::Error  ferror;

	ferror = File::SetBaseDir("C:\\Code\\Monkey\\");
	CHECK(ferror == File::Error::SUCCESS);

	char buff[File::BASE_DIR_SIZE];
	ferror = File::GetBaseDir(buff, File::BASE_DIR_SIZE);
	CHECK(ferror == File::Error::SUCCESS);

	CHECK( strcmp(buff,"C:\\Code\\Monkey\\") == 0);

	ferror = File::ClearBaseDir();
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(GetBaseDir_SUCCESS)
{
#if GetBaseDir_SUCCESS

	system("del /F *.bin");

#endif
}

// --- End of File ---
