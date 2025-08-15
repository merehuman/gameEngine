//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_DEPTH_STENCIL_VIEW_H
#define STATE_DEPTH_STENCIL_VIEW_H

#include <d3d11.h>
#include "StateDepthStencilBuffer.h"

namespace Azul
{
	class StateDepthStencilView
	{
	public:
		StateDepthStencilView();
		StateDepthStencilView(const StateDepthStencilView &) = delete;
		StateDepthStencilView &operator = (const StateDepthStencilView &) = delete;
		virtual ~StateDepthStencilView();

		void Initialize(StateDepthStencilBuffer &r);
		void Clear(float clearDepth,uint8_t clearStencil);

		ID3D11DepthStencilView *poD3dDepthStencilView;
	};

}
#endif 

// --- End of File ---
