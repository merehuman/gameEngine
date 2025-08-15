//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateViewport.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	StateViewport::StateViewport()
		: poViewport{nullptr}
	{
	}

	void StateViewport::Initialize(int _width, int _height)
	{
		this->poViewport = new D3D11_VIEWPORT();
		assert(this->poViewport);

		poViewport->Width = static_cast<float>(_width);
		poViewport->Height = static_cast<float>(_height);
		poViewport->TopLeftX = 0.0f;
		poViewport->TopLeftY = 0.0f;
		poViewport->MinDepth = 0.0f;
		poViewport->MaxDepth = 1.0f;
	}

	void StateViewport::Activate()
	{
		assert(this->poViewport);
		DirectXDeviceMan::GetContext()->RSSetViewports(1, this->poViewport);
	}

	StateViewport::~StateViewport()
	{
		delete this->poViewport;
		this->poViewport = nullptr;
	}

}

// --- End of File ---
