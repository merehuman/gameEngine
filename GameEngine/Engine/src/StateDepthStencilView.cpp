//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateDepthStencilView.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateDepthStencilView::StateDepthStencilView()
		: poD3dDepthStencilView{nullptr}
	{
	}

	void StateDepthStencilView::Initialize(StateDepthStencilBuffer &r)
	{
		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateDepthStencilView(r.poD3dDepthStencilBuffer, nullptr, &this->poD3dDepthStencilView);
		assert(SUCCEEDED(hr));
	}

	void StateDepthStencilView::Clear(float _clearDepth, uint8_t _clearStencil)
	{
		DirectXDeviceMan::GetContext()->ClearDepthStencilView(this->poD3dDepthStencilView, 
															  D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 
															  _clearDepth, 
															  _clearStencil);

	}

	StateDepthStencilView::~StateDepthStencilView()
	{
		SafeRelease(this->poD3dDepthStencilView);
		this->poD3dDepthStencilView = nullptr;
	}

}

// --- End of File ---
