//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_BASIC_COMPUTE_H
#define SHADER_OBJECT_BASIC_COMPUTE_H

#include "ShaderObject.h"
#include "BufferComputeShader.h"

namespace Azul
{
	class ShaderObject_BasicCompute : public ShaderObject
	{
	public:
		ShaderObject_BasicCompute() = delete;
		ShaderObject_BasicCompute(const ShaderObject_BasicCompute &) = delete;
		ShaderObject_BasicCompute &operator = (const ShaderObject_BasicCompute &) = delete;
		virtual ~ShaderObject_BasicCompute();

		ShaderObject_BasicCompute(ShaderObject_BasicCompute::Name _name);

		virtual void ActivateShader() override;

		// ---------------------------------------------
		// 	   Data:
		// ---------------------------------------------

		BufferComputeShader ComputeShader;
	};
}

#endif

// --- End of File ---
