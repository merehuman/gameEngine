//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_MIXER_H
#define SHADER_OBJECT_MIXER_H

#include "ShaderObject.h"
#include "BufferComputeShader.h"

namespace Azul
{
	class ShaderObject_Mixer : public ShaderObject
	{
	public:
		ShaderObject_Mixer() = delete;
		ShaderObject_Mixer(const ShaderObject_Mixer &) = delete;
		ShaderObject_Mixer &operator = (const ShaderObject_Mixer &) = delete;
		virtual ~ShaderObject_Mixer();

		ShaderObject_Mixer(ShaderObject_Mixer::Name _name);

		virtual void ActivateShader() override;

		// ---------------------------------------------
		// 	   Data:
		// ---------------------------------------------

		BufferComputeShader ComputeShader;
	};
}

#endif

// --- End of File ---
