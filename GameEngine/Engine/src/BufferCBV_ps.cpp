//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferCBV_ps.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	BufferCBV_ps::BufferCBV_ps( size_t _structSize)
		: structSize{_structSize},
		poBufferCBV{nullptr},
		bCreate{false}
	{
		this->privCreate(_structSize);
	}

	void BufferCBV_ps::privCreate(size_t _structSize)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		this->structSize = _structSize;
		assert(structSize > 0);

		D3D11_BUFFER_DESC BufferDesc{0};

		//  shader resource
		BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferDesc.ByteWidth = this->structSize;
		BufferDesc.CPUAccessFlags = 0;
		BufferDesc.Usage = D3D11_USAGE_DEFAULT;
		BufferDesc.MiscFlags = 0;
		BufferDesc.StructureByteStride = 0;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateBuffer(&BufferDesc, 
														 nullptr, 
														 &this->poBufferCBV);
		assert(SUCCEEDED(hr));
		assert(this->poBufferCBV);
	}

	void BufferCBV_ps::Transfer(void *pBuff)
	{
		// in case set was called before
		assert(this->bCreate == true);
		assert(pBuff);

		DirectXDeviceMan::GetContext()->UpdateSubresource(poBufferCBV,
														  0,
														  nullptr,
														  pBuff,
														  0,
														  0);
	}

	void BufferCBV_ps::SetActive(ConstantBufferSlot slot)
	{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->PSSetConstantBuffers((uint32_t)slot,
															 1,
															 &this->poBufferCBV);
	}

	BufferCBV_ps::~BufferCBV_ps()
	{
		SafeRelease(this->poBufferCBV);
	}

}

//--- End of File ---
