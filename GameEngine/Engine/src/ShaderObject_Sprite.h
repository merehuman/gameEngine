//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_SPRITE_H
#define SHADER_OBJECT_SPRITE_H

#include "ShaderObject.h"
#include "BufferCBV_vs.h"
#include "BufferCBV_ps.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout_ia.h"

namespace Azul
{
	class ShaderObject_Sprite : public ShaderObject
	{
	public:

	public:
		ShaderObject_Sprite() = delete;
		ShaderObject_Sprite(const ShaderObject_Sprite &) = delete;
		ShaderObject_Sprite &operator = (const ShaderObject_Sprite &) = delete;
		virtual ~ShaderObject_Sprite();

		ShaderObject_Sprite(ShaderObject_Sprite::Name _name);

		virtual void ActivateShader() override;
		virtual void ActivateCBV() override;
		virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;
		virtual void TransferUVCorrection(Mat4 *pUVMatrix) override;
		virtual void TransferScaleColor(Color *pScaleColor) override;
		// ---------------------------------------------
		// 	   Data:
		// ---------------------------------------------

		BufferCBV_vs ConstantBuff_Projection;
		BufferCBV_vs ConstantBuff_World;
		BufferCBV_vs ConstantBuff_View;

		BufferCBV_ps ConstantBuff_uvMatrix; 
		BufferCBV_ps ConstantBuff_scaleColor;

		BufferVertexShader VertexShader;
		BufferPixelShader  PixelShader;
		BufferInputLayout_ia  InputLayout;

	};
}

#endif

// --- End of File ---
