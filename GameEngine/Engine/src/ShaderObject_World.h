//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_OBJECT_WORLD_H
#define SHADER_OBJECT_WORLD_H

#include "ShaderObject.h"
#include "BufferComputeShader.h"

namespace Azul
{
	class ShaderObject_World : public ShaderObject
	{
	public:
		ShaderObject_World() = delete;
		ShaderObject_World(const ShaderObject_World &) = delete;
		ShaderObject_World &operator = (const ShaderObject_World &) = delete;
		virtual ~ShaderObject_World();

		ShaderObject_World(ShaderObject_World::Name _name);

		virtual void ActivateShader() override;

		// ---------------------------------------------
		// 	   Data:
		// ---------------------------------------------

		BufferComputeShader ComputeShader;
	};
}

#endif

// --- End of File ---
