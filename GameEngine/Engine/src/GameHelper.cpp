//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

// DirectX includes
#include <d3d11.h>
#include <d3dcompiler.h>

#include "Game.h"
#include "File.h"
#include "StateDepthStencil.h"

namespace Azul
{
	extern unsigned int NumIndices;

	void Game::SetDefaultTargetMode()
	{
	//--------------------------------------------------------
		// Set Rasterizers functions to be used
	//--------------------------------------------------------
		this->mStateRasterizerSolid.Activate();

	//--------------------------------------------------------
		// Set Viewport to be used
	//--------------------------------------------------------
		this->mViewport.Activate();

	//--------------------------------------------------------
		// Set render target
	//      Only one Target, this maps to Pixel shader
	// --------------------------------------------------------
		//g_d3dDeviceContext->OMSetRenderTargets(1, &g_d3dRenderTargetView, g_d3dDepthStencilView);
		this->mStateRenderTargetView.Activate(this->mDepthStencilView);

		//--------------------------------------------------------
		// Set blend target
		//--------------------------------------------------------
		this->mBlendStateOff.Activate();

	//--------------------------------------------------------
		// Set Depth functions to be used
	//--------------------------------------------------------
		this->mStateDepthStencil.Activate();
	}


	float Game::GetAspectRatio() const
	{
	RECT clientRect;
	GetClientRect(g_WindowHandle, &clientRect);

	// Compute the exact client dimensions.
	// This is required for a correct projection matrix.
	float clientWidth = static_cast<float>(clientRect.right - clientRect.left);
	float clientHeight = static_cast<float>(clientRect.bottom - clientRect.top);

	float ratio = clientWidth / clientHeight;

	return ratio;
	}
}

// --- End of File ---
