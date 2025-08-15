//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#include "File.h"

namespace Azul
{
	// holds the directory internally to File.cpp
	static char BaseDir[File::BASE_DIR_SIZE] = {0};

	File::Error File::ClearBaseDir() noexcept
	{
		memset(BaseDir, 0x0, File::BASE_DIR_SIZE);
		return File::Error::SUCCESS;
	}

	File::Error File::GetBaseDir(char *const pDirOut, size_t DirOutSize) noexcept
	{
		if (pDirOut == nullptr) { return File::Error::BASE_DIR_NULLPTR_FAIL; }
		if (DirOutSize < File::BASE_DIR_SIZE) { return File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL;  }

		memcpy(pDirOut, BaseDir, File::BASE_DIR_SIZE);

		return File::Error::SUCCESS;
	}

	File::Error File::SetBaseDir(const char *const pDir) noexcept
	{
		if (pDir == nullptr) { return File::Error::BASE_DIR_NULLPTR_FAIL; }

		if (strlen(pDir) >= File::BASE_DIR_SIZE){ return File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL; }

		memset(BaseDir, 0x0, File::BASE_DIR_SIZE);
		memcpy(BaseDir, pDir, strlen(pDir));

		return File::Error::SUCCESS;
	}

	bool File::IsHandleValid(File::Handle fh) noexcept
	{
		if (fh == nullptr) { return false; }
		if (fh == INVALID_HANDLE_VALUE) { return false; }
		
		DWORD dw;
		BOOL b = GetHandleInformation(fh, &dw);
		return b;
	}

	File::Error File::Open(File::Handle &fh, const char *const fileName, File::Mode mode, bool UseBaseAddr) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fileName == nullptr) { return File::Error::OPEN_FILENAME_FAIL; }
		if (UseBaseAddr && BaseDir[0] == 0x0) { return File::Error::OPEN_BASE_DIR_FAIL; }
		if (fh != nullptr && fh != INVALID_HANDLE_VALUE) { return File::Error::OPEN_FAIL; }

		// create the full path
		char fullPath[File::BASE_DIR_SIZE + MAX_PATH];
		memset(fullPath, 0x0, File::BASE_DIR_SIZE + MAX_PATH);

		if (UseBaseAddr)
		{
			memcpy(fullPath, BaseDir, File::BASE_DIR_SIZE);
		}

		strcat_s(fullPath, File::BASE_DIR_SIZE + MAX_PATH, fileName);

		// open the file
		switch (mode)
		{
			case File::Mode::READ:
			{
				fh = CreateFile(fullPath, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
				if (fh == nullptr)
				{
					status = File::Error::OPEN_FAIL;
				}
				break;
			}
			case File::Mode::WRITE:
			{
				fh = CreateFile(fullPath, GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
				if (fh == nullptr)
				{
					status = File::Error::OPEN_FAIL;
				}
				break;
			}
			case File::Mode::READ_WRITE:
			{
				fh = CreateFile(fullPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
				if (fh == nullptr)
				{
					status = File::Error::OPEN_FAIL;
				}
				break;
			}
			default:
			{
				status = File::Error::OPEN_FAIL;
				break;
			}
		}

		return status;
	}

	File::Error File::Close(File::Handle &fh) noexcept
	{
		if (fh == nullptr) { return File::Error::CLOSE_FAIL; }
		if (fh == INVALID_HANDLE_VALUE) { return File::Error::CLOSE_FAIL; }
		if (IsHandleValid(fh) == false) { return File::Error::CLOSE_FAIL; }

		BOOL status = CloseHandle(fh);
		if (status == 0)
		{
			return File::Error::CLOSE_FAIL;
		}

		fh = INVALID_HANDLE_VALUE;
		return File::Error::SUCCESS;

	}

	File::Error File::Write(File::Handle fh, const void *const buffer, const DWORD inSize) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fh == nullptr) { return File::Error::WRITE_FAIL; }
		if (buffer == nullptr) { return File::Error::WRITE_FAIL; }

		DWORD bytesWritten = 0;
		if (WriteFile(fh, buffer, inSize, &bytesWritten, nullptr) == 0)
		{
			status = File::Error::WRITE_FAIL;
		}

		return status;
	}

	File::Error File::Read(File::Handle fh, void *const buffer, const DWORD inSize) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fh == nullptr) { return File::Error::READ_FAIL; }
		if (buffer == nullptr) { return File::Error::READ_FAIL; }
		if (inSize == 0) { return File::Error::READ_FAIL; }

		DWORD bytesRead = 0;
		if (ReadFile(fh, buffer, inSize, &bytesRead, nullptr) == 0)
		{
			status = File::Error::READ_FAIL;
		}

		return status;
	}

	File::Error File::Seek(File::Handle fh, File::Position location, int offset) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fh == nullptr) { return File::Error::SEEK_FAIL; }

		DWORD moveMethod = 0;
		switch (location)
		{
			case File::Position::BEGIN:
			{
				moveMethod = FILE_BEGIN;
				break;
			}
			case File::Position::CURRENT:
			{
				moveMethod = FILE_CURRENT;
				break;
			}
			case File::Position::END:
			{
				moveMethod = FILE_END;
				break;
			}
			default:
			{
				status = File::Error::SEEK_FAIL;
				break;
			}
		}

		if (SetFilePointer(fh, offset, nullptr, moveMethod) == INVALID_SET_FILE_POINTER)
		{
			status = File::Error::SEEK_FAIL;
		}

		return status;
	}

	File::Error File::Tell(File::Handle fh, DWORD &offset) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fh == nullptr) { return File::Error::TELL_FAIL; }

		offset = SetFilePointer(fh, 0, nullptr, FILE_CURRENT);
		if (offset == INVALID_SET_FILE_POINTER)
		{
			status = File::Error::TELL_FAIL;
		}

		return status;
	}

	File::Error File::Flush(File::Handle fh) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		if (fh == nullptr) { return File::Error::FLUSH_FAIL; }

		if (FlushFileBuffers(fh) == 0)
		{
			status = File::Error::FLUSH_FAIL;
		}

		return status;
	}

	File::Error File::GetFileAsBuffer(const char* const pFileName, unsigned char*& pBuff, unsigned int& numBytes) noexcept
	{
		File::Error status = File::Error::SUCCESS;

		File::Handle fh = nullptr;

		status = File::Open(fh, pFileName, File::Mode::READ);
		assert(status == File::Error::SUCCESS);

		status = File::Seek(fh, File::Position::END, 0);
		assert(status == File::Error::SUCCESS);

		DWORD FileLength;
		status = File::Tell(fh, FileLength);
		assert(status == File::Error::SUCCESS);

		char* poNewBuff = new char[FileLength]();
		assert(poNewBuff);

		status = File::Seek(fh, File::Position::BEGIN, 0);
		assert(status == File::Error::SUCCESS);

		status = File::Read(fh, poNewBuff, FileLength);
		assert(status == File::Error::SUCCESS);

		status = File::Close(fh);
		assert(status == File::Error::SUCCESS);

		pBuff = (unsigned char*)poNewBuff;
		numBytes = FileLength;

		return status;
	}


}

// --- End of File ---
