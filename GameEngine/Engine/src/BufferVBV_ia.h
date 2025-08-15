//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_VBV_IA_H
#define BUFFER_VBV_IA_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferVBV_ia
	{
	public:
		BufferVBV_ia();
		BufferVBV_ia(const BufferVBV_ia &r) = delete;
		BufferVBV_ia &operator=(const BufferVBV_ia &) = delete;
		virtual ~BufferVBV_ia();

		void Initialize(size_t numBytes, uint32_t _strideSize, void *pData);
		void SetActive(VertexSlot slot);

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		 numBytes;
		size_t		 strideSize;
		size_t		 offset;
		ID3D11Buffer *poBufferVBV;
		bool         bCreate;
	};
}

#endif

//--- End of File ---
