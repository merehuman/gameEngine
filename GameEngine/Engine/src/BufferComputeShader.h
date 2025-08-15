//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_COMPUTE_SHADER_H
#define BUFFER_COMPUTE_SHADER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferComputeShader
	{
	public:
		BufferComputeShader() = delete;
		BufferComputeShader(const BufferComputeShader &r) = delete;
		BufferComputeShader &operator=(const BufferComputeShader &) = delete;
		virtual ~BufferComputeShader();

		BufferComputeShader(size_t numBytes, void *pData);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		         codeSize;
		ID3D11ComputeShader *poComputeShader;
		bool                 bCreate;
	};
}

#endif

//--- End of File ---
