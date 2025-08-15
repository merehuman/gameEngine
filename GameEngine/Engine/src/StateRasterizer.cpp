//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateRasterizer.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateRasterizer::StateRasterizer()
		: poD3dRasterizerState{nullptr}
	{
	}

	void StateRasterizer::Initialize(D3D11_FILL_MODE _FillMode, D3D11_CULL_MODE _CullMode)
	{
		// Setup rasterizer state.
		D3D11_RASTERIZER_DESC rasterizerDesc;
		memset(&rasterizerDesc, 0, sizeof(D3D11_RASTERIZER_DESC));

		rasterizerDesc.AntialiasedLineEnable = FALSE;
		rasterizerDesc.CullMode = _CullMode;//D3D11_CULL_FRONT; //D3D11_CULL_NONE;

		rasterizerDesc.DepthBias = 0;
		rasterizerDesc.DepthBiasClamp = 0.0f;
		rasterizerDesc.DepthClipEnable = TRUE;
		rasterizerDesc.FillMode = _FillMode;//D3D11_FILL_SOLID;
		rasterizerDesc.FrontCounterClockwise = FALSE;
		rasterizerDesc.MultisampleEnable = FALSE;

		// To Do add scissor rectangle... its faster
		rasterizerDesc.ScissorEnable = FALSE;
		rasterizerDesc.SlopeScaledDepthBias = 0.0f;

		// Create the rasterizer state object.
		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateRasterizerState(&rasterizerDesc, &this->poD3dRasterizerState);
		assert(SUCCEEDED(hr));
	}

	void StateRasterizer::Activate()
	{
		assert(this->poD3dRasterizerState);
		DirectXDeviceMan::GetContext()->RSSetState(this->poD3dRasterizerState);
	}

	StateRasterizer::~StateRasterizer()
	{
		SafeRelease(this->poD3dRasterizerState);
		this->poD3dRasterizerState = nullptr;
	}

}

// --- End of File ---
