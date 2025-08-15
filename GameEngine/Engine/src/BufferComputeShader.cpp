//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferComputeShader.h"
#include "DirectXDeviceMan.h"
#include "ShaderObject.h"

namespace Azul
{
	BufferComputeShader::BufferComputeShader(size_t _numBytes, void *pData)
		: codeSize{_numBytes},
		poComputeShader{nullptr},
		bCreate{false}
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferComputeShader::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateComputeShader(pData,
																this->codeSize,
																nullptr,
																&this->poComputeShader);
		assert(SUCCEEDED(hr));
		assert(this->poComputeShader);

		assert(std::string("cs_5_0") == (ShaderObject::GetLatestProfile_ComputeShader()));
	}

	void BufferComputeShader::SetActive()
	{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->CSSetShader(this->poComputeShader, nullptr, 0);
	}

	BufferComputeShader::~BufferComputeShader()
	{
		SafeRelease(this->poComputeShader);
	}

}

//--- End of File ---
