//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "Mesh.h"
#include "GraphicsObject_Abstract.h"

namespace Azul
{
	class Mesh;

	class GraphicsObject : public GraphicsObject_Abstract
	{
	public:
	void Render();
	void SetWorld(Mat4 &_world);

	Mesh *GetMesh() const;
	Mat4 &GetWorld();

	virtual ~GraphicsObject() override;

	protected:
		GraphicsObject(Mesh::Name meshName, 
					   ShaderObject::Name shaderName);

	GraphicsObject() = delete;
	GraphicsObject(const GraphicsObject &) = delete;
	GraphicsObject &operator = (const GraphicsObject &) = delete;

	protected:
	Mesh *pMesh;
	Mat4 *poWorld;
	ShaderObject *pShaderObj;
	};
}

#endif

// --- End of File ---
