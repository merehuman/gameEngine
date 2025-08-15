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
static File::Handle fh_file9;
static File::Handle fh_file10;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST_WITH_TEARDOWN(Open_USE_Base_COMBO, TestConfig::ALL)
{
#if Open_USE_Base_COMBO

	File::Handle fh(nullptr);
	File::Error  ferror;

	system("mkdir Temp");

	ferror = File::SetBaseDir(".\\Temp\\");
	CHECK(ferror == File::Error::SUCCESS);

	//----------- WRITE ------------------------------------------

	ferror = File::Open(fh, "file9.bin", File::Mode::WRITE, true);
	fh_file9 = fh;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh != nullptr);

	const unsigned char data[8] = {0xaa,0xbb,0xcc,0xdd,0xee,0xff,0x11,0x22};

	ferror = File::Write(fh, &data[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	ferror = File::Close(fh);
	CHECK(ferror == File::Error::SUCCESS);

	//----------- READ ------------------------------------------

	File::Handle fh2(nullptr);

	ferror = File::Open(fh2, "file9.bin", File::Mode::READ, true);
	fh_file10 = fh2;
	CHECK(ferror == File::Error::SUCCESS);
	CHECK(fh2 != nullptr);

	unsigned char dataFromFile[8];
	ferror = File::Read(fh2, &dataFromFile[0], 8);
	CHECK(ferror == File::Error::SUCCESS);

	CHECK(memcmp(&data[0], &dataFromFile[0], 8) == 0);

	ferror = File::Close(fh2);
	CHECK(ferror == File::Error::SUCCESS);

#endif
} TEST_END

TEST_TEARDOWN(Open_USE_Base_COMBO)
{
#if Open_USE_Base_COMBO

	DWORD flags;
	BOOL status = GetHandleInformation(fh_file9, &flags);
	if(status)
	{
		File::Close(fh_file9);
	}

	status = GetHandleInformation(fh_file10, &flags);
	if(status)
	{
		File::Close(fh_file10);
	}

	system("rmdir /q /s Temp");
	system("del /F *.bin");

#endif
}

// --- End of File ---
