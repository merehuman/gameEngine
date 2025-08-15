//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferIBV_ia.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	BufferIBV_ia::BufferIBV_ia()
		: numBytes{0},
		poBufferIBV{nullptr},
		bCreate{false}
	{
		assert(bCreate == false);
	}

	void BufferIBV_ia::Initialize(size_t _numBytes, void *pData)
	{
		assert(pData);
		assert(bCreate == false);

		this->numBytes = _numBytes;
		this->poBufferIBV = nullptr;
		this->privCreate(pData);
	}

	void BufferIBV_ia::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		// Create and initialize the index buffer.
		D3D11_BUFFER_DESC indexBufferDesc{0};
		D3D11_SUBRESOURCE_DATA resourceData{0};

		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.ByteWidth = this->numBytes;
		indexBufferDesc.CPUAccessFlags = 0;
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = pData;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateBuffer(&indexBufferDesc, 
														 &resourceData, 
														 &this->poBufferIBV);
		assert(SUCCEEDED(hr));
		assert(this->poBufferIBV);

	}

	void BufferIBV_ia::SetActive()
	{
		assert(bCreate);

		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->IASetIndexBuffer(this->poBufferIBV, 
														 DXGI_FORMAT_R32_UINT, 
														 0);
	}

	BufferIBV_ia::~BufferIBV_ia()
	{
		SafeRelease(this->poBufferIBV);
	}

}

//--- End of File ---
