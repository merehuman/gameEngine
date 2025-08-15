//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "MeshCube.h"
#include "MathEngine.h"
#include "DirectXDeviceMan.h"
#include "ShaderMappings.h"
//#include "BoundingSphere.h"

using namespace Azul;


uint32_t g_CubeIndices[] =
{
	1, 0,2 ,
	4, 3,5 ,
	7, 6,8 ,
	10,9,11 ,
	13,12,14 ,
	16,15,17 ,
	19,18,20 ,
	22,21,23 ,
	25,24,26 ,
	28,27,29 ,
	31,30,32 ,
	34,33,35
};

VertexPos g_CubeVertices_pos[] =
{
	// Triangle 0
	Vec3(-0.25f,  0.25f, -0.25f),
	Vec3(-0.25f, -0.25f, -0.25f),
	Vec3(0.25f, -0.25f,  -0.25f),

	// Triangle 1
	Vec3(0.25f,  -0.25f, -0.25f),
	Vec3(0.25f,   0.25f, -0.25f),
	Vec3(-0.25f,  0.25f, -0.25f),

	// Triangle 2
	Vec3(0.25f, -0.25f, -0.25f),
	Vec3(0.25f, -0.25f,  0.25f),
	Vec3(0.25f,  0.25f, -0.25f),

	// Triangle 3
	Vec3(0.25f, -0.25f,  0.25f),
	Vec3(0.25f,  0.25f,  0.25f),
	Vec3(0.25f,  0.25f, -0.25f),

	// Triangle 4
	Vec3(0.25f,  -0.25f,  0.25f),
	Vec3(-0.25f,  -0.25f,  0.25f),
	Vec3(0.25f,   0.25f,  0.25f),

	// Triangle 5
	Vec3(-0.25f, -0.25f,  0.25f),
	Vec3(-0.25f,  0.25f,  0.25f),
	Vec3(0.25f,   0.25f,  0.25f),

	// Triangle 6
	Vec3(-0.25f, -0.25f,  0.25f),
	Vec3(-0.25f, -0.25f, -0.25f),
	Vec3(-0.25f,  0.25f,  0.25f),

	// Triangle 7
	Vec3(-0.25f, -0.25f, -0.25f),
	Vec3(-0.25f,  0.25f, -0.25f),
	Vec3(-0.25f,  0.25f,  0.25f),

	// Triangle 8
	Vec3(-0.25f, -0.25f,  0.25f),
	Vec3(0.25f, -0.25f,   0.25f),
	Vec3(0.25f, -0.25f,  -0.25f),

	// Triangle 9
	Vec3(0.25f, -0.25f,  -0.25f),
	Vec3(-0.25f, -0.25f, -0.25f),
	Vec3(-0.25f, -0.25f,  0.25f),

	// Triangle 10
	Vec3(-0.25f,  0.25f, -0.25f),
	Vec3(0.25f,  0.25f,  -0.25f),
	Vec3(0.25f,  0.25f,   0.25f),

	// Triangle 11
	Vec3(0.25f,  0.25f,   0.25f),
	Vec3(-0.25f,  0.25f,  0.25f),
	Vec3(-0.25f,  0.25f, -0.25f)

};

VertexTexCoord g_CubeVertices_texCoord[] =
{
	// Triangle 0
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 1
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 2
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 3
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 4
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 5
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 6
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 7
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 8
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 9
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 10
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 11
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f)

};

VertexNorm g_CubeVertices_norm[] =
{
	// Triangle 0
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  -0.6f, -0.6f),

	// Triangle 1
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),

	// Triangle 2
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 3
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 4
	Vec3f(0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 5
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f,  0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 6
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 7
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 8
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f, -0.6f),

	// Triangle 9
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f,  0.6f),

	// Triangle 10
	Vec3f(-0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f,  0.6f),

	// Triangle 11
	Vec3f(0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f, -0.6f)

};

VertexColor g_CubeVertices_color[] =
{
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f)

};


unsigned int NumCubeVerts = sizeof(g_CubeVertices_pos) / sizeof(g_CubeVertices_pos[0]);
unsigned int NumCubeIndices = sizeof(g_CubeIndices) / sizeof(g_CubeIndices[0]);


MeshCube::MeshCube()
	: Mesh(NumCubeVerts, NumCubeIndices),
	VBVBuffer_pos(),
	VBVBuffer_color(),
	VBVBuffer_norm(),
	VBVBuffer_tex(),
	IBVBuffer()
{
	VBVBuffer_pos.Initialize(sizeof(g_CubeVertices_pos), sizeof(VertexPos), g_CubeVertices_pos);
	VBVBuffer_color.Initialize(sizeof(g_CubeVertices_color), sizeof(VertexColor), g_CubeVertices_color);
	VBVBuffer_norm.Initialize(sizeof(g_CubeVertices_norm), sizeof(VertexNorm), g_CubeVertices_norm);
	VBVBuffer_tex.Initialize(sizeof(g_CubeVertices_texCoord), sizeof(VertexTexCoord), g_CubeVertices_texCoord);
	IBVBuffer.Initialize(sizeof(g_CubeIndices), g_CubeIndices);


	// Find Bounding Volume - quick hack
	//Sphere sphere;
	//Vec3 *pVerts = new Vec3[(unsigned int)this->numVerts]();
	//for(unsigned int i = 0; i < this->numVerts; i++)
	//{
	//	pVerts[i].set(g_CubeVertices_pos[i].Position[x],
	//				  g_CubeVertices_pos[i].Position[y],
	//				  g_CubeVertices_pos[i].Position[z]);
	//	Trace::out("%d:  %f %f %f\n", i, pVerts[i][x], pVerts[i][y], pVerts[i][z]);
	//}
	//RitterSphere(sphere, pVerts, this->numVerts);
	//Trace::out("\n");
	//Trace::out("Ritter: cntr:%f %f %f \n   rad: %f \n", sphere.cntr[x], sphere.cntr[y], sphere.cntr[z], sphere.rad);
	//Trace::out("\n");
	//delete[] pVerts;



}

MeshCube::~MeshCube()
{
}

void MeshCube::ActivateMesh()
{
	// ---------------------------------------------
	//    Set (point to ) vertex: position 
	//    Set (point to ) vertex: color
	//    Set (point to ) vertex: norm
	//    Set (point to ) vertex: texCoord
	// ---------------------------------------------
	this->VBVBuffer_pos.SetActive(VertexSlot::Position);
	this->VBVBuffer_color.SetActive(VertexSlot::Color);
	this->VBVBuffer_norm.SetActive(VertexSlot::Norm);
	this->VBVBuffer_tex.SetActive(VertexSlot::TexCoord);
}

void MeshCube::RenderIndexBuffer()
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
