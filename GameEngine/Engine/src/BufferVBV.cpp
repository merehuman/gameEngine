//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferVBV.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	BufferVBV::BufferVBV()
		: numBytes{0},
		strideSize{0},
		offset{0},
		poBufferVBV{nullptr},
		bCreate{false}
	{
		assert(this->bCreate == false);
	}


	void BufferVBV::Initialize(size_t _numBytes, uint32_t _strideSize, void *pData)
	{
		assert(bCreate == false);
		assert(pData);
		this->numBytes = _numBytes;
		this->strideSize = _strideSize;
		this->offset = 0;
		this->poBufferVBV = nullptr;
		this->privCreate(pData);
	}

	void BufferVBV::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		// Create an initialize the vertex buffer.
		D3D11_BUFFER_DESC vertexBufferDesc{0};
		D3D11_SUBRESOURCE_DATA resourceData{0};

		// type of buffer
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.ByteWidth = this->numBytes;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = pData;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateBuffer(&vertexBufferDesc, &resourceData, &this->poBufferVBV);

		assert(SUCCEEDED(hr));
		assert(this->poBufferVBV);
	}

	void BufferVBV::SetActive(VertexSlot slot)
	{
		//w1(4)
		if(this->bCreate)
		{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->IASetVertexBuffers((uint32_t)slot,
														   1,
														   &this->poBufferVBV,
														   &this->strideSize,
														   &this->offset);
	}
	}

	BufferVBV::~BufferVBV()
	{
		//w1(4)
		if(this->bCreate)
		{
		SafeRelease(this->poBufferVBV);
	}
	}

}

//--- End of File ---
