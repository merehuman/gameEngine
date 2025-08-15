//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateDepthStencil.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateDepthStencil::StateDepthStencil()
		:poD3dDepthStencilState{nullptr}
	{
	}

	void StateDepthStencil::Initialize()
	{
		// Setup depth/stencil state.
		D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc{0};

		depthStencilStateDesc.DepthEnable = TRUE;
		depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;

		// not using any stencil... its disabled
		depthStencilStateDesc.StencilEnable = FALSE;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateDepthStencilState(&depthStencilStateDesc, &this->poD3dDepthStencilState);
		assert(SUCCEEDED(hr));
	}

	void StateDepthStencil::Activate()
	{
		assert(this->poD3dDepthStencilState);
		DirectXDeviceMan::GetContext()->OMSetDepthStencilState(this->poD3dDepthStencilState, 1);
	}

	StateDepthStencil::~StateDepthStencil()
	{
		SafeRelease(this->poD3dDepthStencilState);
		this->poD3dDepthStencilState = nullptr;
	}

}

// --- End of File ---
