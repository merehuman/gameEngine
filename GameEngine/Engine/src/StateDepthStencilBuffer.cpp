//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateDepthStencilBuffer.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateDepthStencilBuffer::StateDepthStencilBuffer()
		: poD3dDepthStencilBuffer{nullptr}
	{
	}

	void StateDepthStencilBuffer::Initialize(uint32_t clientWidth, uint32_t clientHeight)
	{
		// Create the depth buffer for use with the depth/stencil view.
		D3D11_TEXTURE2D_DESC depthStencilBufferDesc{0};

		depthStencilBufferDesc.ArraySize = 1;
		depthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthStencilBufferDesc.CPUAccessFlags = 0; // No CPU access required.
		// 24-bit depth/8-bit stencil --> future make it 32 bit depth
		depthStencilBufferDesc.Format = DXGI_FORMAT_D32_FLOAT;
		depthStencilBufferDesc.Width = clientWidth;
		depthStencilBufferDesc.Height = clientHeight;
		depthStencilBufferDesc.MipLevels = 1;
		depthStencilBufferDesc.SampleDesc.Count = 1;
		depthStencilBufferDesc.SampleDesc.Quality = 0;
		depthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateTexture2D(&depthStencilBufferDesc, nullptr, &this->poD3dDepthStencilBuffer);
		assert(SUCCEEDED(hr));
	}

	StateDepthStencilBuffer::~StateDepthStencilBuffer()
	{
		SafeRelease(this->poD3dDepthStencilBuffer);
		this->poD3dDepthStencilBuffer = nullptr;
	}

}

// --- End of File ---
