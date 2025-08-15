//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef BUFFER_INPUT_LAYOUT_IA_H
#define BUFFER_INPUT_LAYOUT_IA_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferInputLayout_ia
	{
	public:
		BufferInputLayout_ia() = delete;
		BufferInputLayout_ia(const BufferInputLayout_ia &r) = delete;
		BufferInputLayout_ia &operator=(const BufferInputLayout_ia &) = delete;
		virtual ~BufferInputLayout_ia();

		BufferInputLayout_ia(size_t _numBytes,
						  void *pData,
						  D3D11_INPUT_ELEMENT_DESC *pDesc,
						  unsigned int _DescSize);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		              codeSize;
		ID3D11InputLayout         *poInputLayout;
		D3D11_INPUT_ELEMENT_DESC  *pDesc;
		unsigned int              DescSize;
		bool                      bCreate;
	};
}

#endif

//--- End of File ---
