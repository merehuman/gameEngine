//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_VIEWPORT_H
#define STATE_VIEWPORT_H

#include <d3d11.h>

namespace Azul
{
	class StateViewport
	{
	public:
		StateViewport();
		StateViewport(const StateViewport &) = delete;
		StateViewport &operator = (const StateViewport &) = delete;
		virtual ~StateViewport();

		void Initialize(int _width, int _height);
		void Activate();

		D3D11_VIEWPORT *poViewport;
	};

}
#endif 

// --- End of File ---
