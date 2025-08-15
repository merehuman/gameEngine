//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_SKIN_FLAT_TEXTURE_H
#define SHADER_OBJECT_SKIN_FLAT_TEXTURE_H

#include "ShaderObject.h"
#include "BufferCBV_vs.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout_ia.h"

namespace Azul
{
	class ShaderObject_SkinFlatTexture : public ShaderObject
	{
	public:
		ShaderObject_SkinFlatTexture() = delete;
		ShaderObject_SkinFlatTexture(const ShaderObject_SkinFlatTexture &) = delete;
		ShaderObject_SkinFlatTexture &operator = (const ShaderObject_SkinFlatTexture &) = delete;
		virtual ~ShaderObject_SkinFlatTexture();

		ShaderObject_SkinFlatTexture(ShaderObject_SkinFlatTexture::Name _name);

		virtual void ActivateShader() override;
		virtual void ActivateCBV() override;
		virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;

		// ---------------------------------------------
		// 	   Data:
		// ---------------------------------------------

		BufferCBV_vs ConstantBuff_Projection;
		BufferCBV_vs ConstantBuff_World;
		BufferCBV_vs ConstantBuff_View;

		BufferVertexShader VertexShader;
		BufferPixelShader  PixelShader;
		BufferInputLayout_ia  InputLayout;

	};
}

#endif

// --- End of File ---
