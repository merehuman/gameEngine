//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateRenderTargetView.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateRenderTargetView::StateRenderTargetView()
		: poD3dRenderTargetView{nullptr}
	{
	}

	void StateRenderTargetView::Initialize(ID3D11Texture2D *backBuffer)
	{
		HRESULT hr = DirectXDeviceMan::GetDevice()->CreateRenderTargetView(backBuffer, nullptr, &this->poD3dRenderTargetView);
		(SUCCEEDED(hr));
	}

	void StateRenderTargetView::Clear(const Vec4 &r)
	{
		DirectXDeviceMan::GetContext()->ClearRenderTargetView(this->poD3dRenderTargetView, 
															  (const float *)&r);

	}

	void StateRenderTargetView::Activate(StateDepthStencilView &r)
	{
		DirectXDeviceMan::GetContext()->OMSetRenderTargets(1, 
														   &this->poD3dRenderTargetView,
														   r.poD3dDepthStencilView);
	}

	StateRenderTargetView::~StateRenderTargetView()
	{
		SafeRelease(this->poD3dRenderTargetView);
		this->poD3dRenderTargetView = nullptr;
	}

}

// --- End of File ---
