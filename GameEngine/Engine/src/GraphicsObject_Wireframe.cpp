//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3d11.h>
#include "Engine.h"
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_Wireframe.h"
#include "ShaderObject.h"
#include "DirectXDeviceMan.h"
#include "CameraMan.h"
#include "GameMan.h"

namespace Azul
{

	// ---------------------------------------------
	//  Transfer data to the constant buffer
	//    CPU ---> GPU
	//    World, View, Projection Matrix
	// ---------------------------------------------
	GraphicsObject_Wireframe::GraphicsObject_Wireframe(Mesh::Name meshName,
													   ShaderObject::Name shaderName,
													   Vec3 &rColor)
		: GraphicsObject(meshName, shaderName),
		poLightColor(nullptr)

	{
	assert(pMesh);
	assert(pShaderObj);
	assert(poWorld);

	this->poLightColor = new Vec3(rColor);
	assert(poLightColor);

	}

	GraphicsObject_Wireframe::~GraphicsObject_Wireframe()
	{
	delete this->poLightColor;
	}

	void GraphicsObject_Wireframe::SetState()
	{
		GameMan::GetGame()->mStateRasterizerWireframe.Activate();
	}

	void GraphicsObject_Wireframe::SetDataGPU()
	{
		pMesh->ActivateMesh();
	pShaderObj->ActivateShader();
	pShaderObj->ActivateCBV();

		Camera *pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
		assert(pCam);

		pShaderObj->TransferWorldViewProj(pCam, this->poWorld);
	pShaderObj->TransferColor(this->poLightColor);
	}

	void GraphicsObject_Wireframe::Draw()
	{
	pMesh->RenderIndexBuffer();
	}

	void GraphicsObject_Wireframe::RestoreState()
	{
		GameMan::GetGame()->mStateRasterizerSolid.Activate();
	}
}

// ---  End of File ---
