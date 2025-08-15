//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MESH_SPHERE_H
#define MESH_SPHERE_H

#include "Mesh.h"
#include "BufferIBV.h"
#include "BufferVBV.h"


class MeshSphere : public Mesh
{
public:
	MeshSphere();
	MeshSphere(const MeshSphere &) = delete;
	MeshSphere &operator = (MeshSphere &) = delete;
	virtual ~MeshSphere();

	virtual void ActivateMesh() override;
	virtual void RenderIndexBuffer() override;

	// Data
	BufferVBV VBVBuffer_pos;

	BufferVBV VBVBuffer_tex;
	BufferVBV VBVBuffer_norm;

	BufferIBV IBVBuffer;


};

#endif

// --- End of File ---
