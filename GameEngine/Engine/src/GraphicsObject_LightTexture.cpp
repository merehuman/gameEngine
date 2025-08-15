//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3d11.h>
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_LightTexture.h"
#include "CameraMan.h"
#include "TexNodeMan.h"

namespace Azul
{

	// ---------------------------------------------
	//  Transfer data to the constant buffer
	//    CPU ---> GPU
	//    World, View, Projection Matrix
	// ---------------------------------------------
	GraphicsObject_LightTexture::GraphicsObject_LightTexture(Mesh::Name meshName,
															 ShaderObject::Name shaderName,
															 TextureObject::Name texName,
															 Vec3 &LightColor,
															 Vec3 &LightPos)
		: GraphicsObject(meshName, shaderName),
		pTex(TexNodeMan::Find(texName)),
		poLightColor(nullptr),
		poLightPos(nullptr)
	{
		assert(pTex);

		poLightColor = new Vec3(LightColor);
		poLightPos = new Vec3(LightPos);

		assert(poLightColor);
		assert(poLightPos);
	}

	GraphicsObject_LightTexture::GraphicsObject_LightTexture(Mesh *pMesh,
															 ShaderObject::Name shaderName,
															 TextureObject::Name texName,
														 Vec3 &LightColor,
														 Vec3 &LightPos)
		: GraphicsObject(pMesh->name, shaderName),
		pTex(TexNodeMan::Find(texName)),
	poLightColor(nullptr),
	poLightPos(nullptr)
	{
	assert(pTex);
		assert(pMesh);

	poLightColor = new Vec3(LightColor);
	poLightPos = new Vec3(LightPos);

	assert(poLightColor);
	assert(poLightPos);
	}

	GraphicsObject_LightTexture::~GraphicsObject_LightTexture()
	{
	delete poLightColor;
	delete poLightPos;
	}

	void GraphicsObject_LightTexture::SetState()
	{
	this->pTex->ActivateTexture();
	}

	void GraphicsObject_LightTexture::SetDataGPU()
	{
		pMesh->ActivateMesh();		
	pShaderObj->ActivateShader();
	pShaderObj->ActivateCBV();

		Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
		assert(pCam);

		pShaderObj->TransferWorldViewProj(pCam, this->poWorld);
	pShaderObj->TransferLightPos(this->poLightPos);
	pShaderObj->TransferColor(this->poLightColor);
	}

	void GraphicsObject_LightTexture::Draw()
	{
	pMesh->RenderIndexBuffer();
	}

	void GraphicsObject_LightTexture::RestoreState()
	{
	// Future - Undo settings to directX
	}

}

// --- End of File ---
