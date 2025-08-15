//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_CONST_COLOR_H
#define SHADER_OBJECT_CONST_COLOR_H

#include "ShaderObject.h"
#include "BufferCBV_vs.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout_ia.h"

namespace Azul
{
	class ShaderObject_ConstColor : public ShaderObject
	{
	public:

	public:
	ShaderObject_ConstColor() = delete;
	ShaderObject_ConstColor(const ShaderObject_ConstColor &) = delete;
	ShaderObject_ConstColor &operator = (const ShaderObject_ConstColor &) = delete;
		virtual ~ShaderObject_ConstColor();

		ShaderObject_ConstColor(ShaderObject_ConstColor::Name _name);

	virtual void ActivateShader() override;
	virtual void ActivateCBV() override;
	virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;

	virtual void TransferColor(Vec3 *pColor) override;

	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------

		BufferCBV_vs ConstantBuff_Projection;
		BufferCBV_vs ConstantBuff_World;
		BufferCBV_vs ConstantBuff_View;

		BufferCBV_vs ConstantBuff_Color;

	BufferVertexShader VertexShader;
	BufferPixelShader  PixelShader;
		BufferInputLayout_ia  InputLayout;

	};
}

#endif

// --- End of File ---
