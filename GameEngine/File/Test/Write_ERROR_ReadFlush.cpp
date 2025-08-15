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
static File::Handle fh_file24;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Write_ERROR_ReadFlush, TestConfig::ALL)
{
#if Write_ERROR_ReadFlush

	File::Handle fh(nullptr);
	File::Error  ferror;

	//----------- WRITE ------------------------------------------

	ferror = File::Open(fh, "file19.bin", File::Mode::READ_WRITE);
	fh_file24 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	const unsigned char data[8] = { 0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22 };

	ferror = File::Write(fh, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------
	ferror = File::Flush(fh);
	CHECK(ferror == File::Error::FLUSH_FAIL);

#endif
} TEST_END


TEST_TEARDOWN(Write_ERROR_ReadFlush)
{
#if Write_ERROR_ReadFlush

	DWORD flags;
	const BOOL status = GetHandleInformation(fh_file24, &flags);
	if (status)
	{
		File::Close(fh_file24);
	}
	system("del /F *.bin");

#endif
}

// --- End of File ---
