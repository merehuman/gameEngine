//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_RENDER_TARGET_VIEW_H
#define STATE_RENDER_TARGET_VIEW_H

#include <d3d11.h>
#include "MathEngine.h"
#include "StateDepthStencilView.h"

namespace Azul
{
	class StateRenderTargetView
	{
	public:
		StateRenderTargetView();
		StateRenderTargetView(const StateRenderTargetView &) = delete;
		StateRenderTargetView &operator = (const StateRenderTargetView &) = delete;
		virtual ~StateRenderTargetView();

		void Initialize(ID3D11Texture2D *backBuffer);
		void Clear(const Vec4 &r);
		void Activate(StateDepthStencilView &r);

		ID3D11RenderTargetView *poD3dRenderTargetView;
	};

}
#endif 

// --- End of File ---
