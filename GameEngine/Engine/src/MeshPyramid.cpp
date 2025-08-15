//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "MeshPyramid.h"
#include "MathEngine.h"
#include "DirectXDeviceMan.h"
#include "ShaderMappings.h"

using namespace Azul;

VertexPos g_PyramidVertices_pos[] =
{
	Vec3(0,  0, 2),  //0
	Vec3(-1, -1, 0),  //1
	Vec3(1, -1, 0),  //2
	Vec3(1,  1, 0),  //3
	Vec3(-1,  1, 0)   //4
};

VertexColor g_PyramidVertices_color[] =
{
	 Vec3(0.0f, 0.0f, 1.0f) , // 0
	 Vec3(0.0f, 1.0f, 0.0f) , // 1
	 Vec3(1.0f, 1.0f, 0.0f) , // 2
	 Vec3(1.0f, 0.0f, 0.0f) , // 3
	 Vec3(1.0f, 0.0f, 1.0f)   // 4
};


uint32_t g_PyramidIndices[] =
{
	1, 0, 4,
	2, 0, 1,
	3, 0, 2,
	4, 0, 3,
	4, 2, 1,
	4, 3, 2
};


VertexTexCoord g_PyramidVertices_texCoord[] =
{
	Vec2f(0.5f, 0.5f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f)
};

VertexNorm g_PyramidVertices_norm[] =
{
	Vec3f(0.0f,  0.0f,  1.0f),
	Vec3f(-0.4f, -0.4f, -0.8f),
	Vec3f(0.4f, -0.4f, -0.8f),
	Vec3f(0.4f,  0.4f, -0.8f),
	Vec3f(-0.4f,  0.4f, -0.8f)

};

unsigned int NumPyramidVerts = sizeof(g_PyramidVertices_pos) / sizeof(g_PyramidVertices_pos[0]);
unsigned int NumPyramidIndices = sizeof(g_PyramidIndices) / sizeof(g_PyramidIndices[0]);


MeshPyramid::MeshPyramid()
	: Mesh(NumPyramidVerts, NumPyramidIndices),
	VBVBuffer_pos(),
	VBVBuffer_color(),
	VBVBuffer_tex(),
	VBVBuffer_norm(),
	IBVBuffer()
{
	VBVBuffer_pos.Initialize(sizeof(g_PyramidVertices_pos), sizeof(VertexPos), g_PyramidVertices_pos);
	VBVBuffer_color.Initialize(sizeof(g_PyramidVertices_color), sizeof(VertexColor), g_PyramidVertices_color);
	VBVBuffer_tex.Initialize(sizeof(g_PyramidVertices_texCoord), sizeof(VertexTexCoord), g_PyramidVertices_texCoord);
	VBVBuffer_norm.Initialize(sizeof(g_PyramidVertices_norm), sizeof(VertexNorm), g_PyramidVertices_norm);
	IBVBuffer.Initialize(sizeof(g_PyramidIndices), g_PyramidIndices);
}

MeshPyramid::~MeshPyramid()
{
}

void MeshPyramid::ActivateMesh()
{
	// ---------------------------------------------
	//    Set (point to ) vertex: position 
	//    Set (point to ) vertex: color
	//    Set (point to ) vertex: texCoord
	//    Set (point ot ) vertex: norm
	// ---------------------------------------------
	this->VBVBuffer_pos.SetActive(VertexSlot::Position);
	this->VBVBuffer_color.SetActive(VertexSlot::Color);
	this->VBVBuffer_tex.SetActive(VertexSlot::TexCoord);
	this->VBVBuffer_norm.SetActive(VertexSlot::Norm);
}

void MeshPyramid::RenderIndexBuffer()
{
	// ---------------------------------------------
	//    Set (point to ) Index buffer 
	//    Render configuration: Triangles
	// ---------------------------------------------
	this->IBVBuffer.SetActive();
	DirectXDeviceMan::GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//--------------------------------------------------------
	// RENDER - using index data
	//--------------------------------------------------------
	DirectXDeviceMan::GetContext()->DrawIndexed(numIndices, 0, 0);
}

// --- End of File ---
