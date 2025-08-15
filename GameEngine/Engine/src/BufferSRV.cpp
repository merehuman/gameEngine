//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "BufferSRV.h"
#include "DirectXDeviceMan.h"
#include "BufferTexture2D.h"

namespace Azul
{

	BufferSRV::BufferSRV()
		: mFormat{DXGI_FORMAT_UNKNOWN},
		poSRV{nullptr},
		bCreate{false}
	{
	
	}

	void BufferSRV::Initialize(textureData::TEXTURE_NCOMPONENT Component, 
							   BufferTexture2D &Texture2dBuffer)
	{
		assert(bCreate == false);

		if(Component == textureData::TEXTURE_NCOMPONENT::NCOMPONENT_RGB
		   || Component == textureData::TEXTURE_NCOMPONENT::NCOMPONENT_RGBA)
		{
			mFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
		}

		if(Component == textureData::TEXTURE_NCOMPONENT::NCOMPONENT_BGR
		   || Component == textureData::TEXTURE_NCOMPONENT::NCOMPONENT_BGRA)
		{
			mFormat = DXGI_FORMAT_B8G8R8A8_UNORM;
		}

		assert(mFormat != DXGI_FORMAT_UNKNOWN);

		this->privCreate(Texture2dBuffer);
	}

	void BufferSRV::privCreate(BufferTexture2D &rTex2D)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		// Create texture
		HRESULT hr;

		D3D11_SHADER_RESOURCE_VIEW_DESC SRVDesc;
		memset(&SRVDesc, 0, sizeof(SRVDesc));

		SRVDesc.Format = mFormat;
		SRVDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		SRVDesc.Texture2D.MipLevels = 1;

		ID3D11Texture2D *poTex = rTex2D.GetID3D11Texture2D();
		assert(poTex);

		hr = DirectXDeviceMan::GetDevice()->CreateShaderResourceView(poTex, 
																	 &SRVDesc, 
																	 &poSRV);
		assert(SUCCEEDED(hr));
	}

	void BufferSRV::SetActive(ShaderResourceBufferSlot slot)
	{
		assert(bCreate == true);
		DirectXDeviceMan::GetContext()->PSSetShaderResources((uint32_t)slot,
															 1,
															 &this->poSRV);
	}

	BufferSRV::~BufferSRV()
	{
		SafeRelease(this->poSRV);
	}

}

//--- End of File ---
