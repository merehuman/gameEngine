//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_SHADER_RESOURCE_VIEW_H
#define BUFFER_SHADER_RESOURCE_VIEW_H

#include <d3d11.h>
#include "ShaderMappings.h"
#include "textureData.h"

namespace Azul
{
	class BufferTexture2D;

	class BufferSRV
	{
	public:
		BufferSRV();
		BufferSRV(const BufferSRV &r) = delete;
		BufferSRV &operator=(const BufferSRV &) = delete;
		virtual ~BufferSRV();

		void Initialize(textureData::TEXTURE_NCOMPONENT component, 
						BufferTexture2D &Texture2dBuffer);

		void SetActive(ShaderResourceBufferSlot slot);

	private:
		void privCreate(BufferTexture2D &rTex2D);

		// ----------------------
		//  Data
		// ----------------------
	public:
		DXGI_FORMAT mFormat;
		ID3D11ShaderResourceView *poSRV;
		bool					 bCreate;
	};
}

#endif

//--- End of File ---
