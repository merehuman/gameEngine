//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_CBV_PS_H
#define BUFFER_CBV_PS_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferCBV_ps
	{
	public:
		BufferCBV_ps() = delete;
		BufferCBV_ps(const BufferCBV_ps &r) = delete;
		BufferCBV_ps &operator=(const BufferCBV_ps &) = delete;
		virtual ~BufferCBV_ps();

		BufferCBV_ps(size_t structSize);

		void Transfer(void *pBuff);
		void SetActive(ConstantBufferSlot slot);

	private:
		void privCreate(size_t structSize);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t       structSize;
		ID3D11Buffer *poBufferCBV;
		bool         bCreate;
	};
}

#endif

//--- End of File ---
