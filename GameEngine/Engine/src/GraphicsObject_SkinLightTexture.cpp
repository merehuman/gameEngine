//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include <d3d11.h>
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_SkinLightTexture.h"
#include "CameraMan.h"
#include "GameMan.h"
#include "TexNodeMan.h"
#include "DirectXDeviceMan.h"
#include "BufferSRV_cs.h"

namespace Azul
{

	// ---------------------------------------------
	//  Transfer data to the constant buffer
	//    CPU ---> GPU
	//    World, View, Projection Matrix
	// ---------------------------------------------
		GraphicsObject_SkinLightTexture::GraphicsObject_SkinLightTexture(Mesh::Name meshName,
																		ShaderObject::Name shaderName,
																		TextureObject::Name texName,
																		Mixer* _pMixer,
																		WorldCompute* _pWorldCompute,
																		Vec3& LightColor,
																		Vec3& LightPos)
			: GraphicsObject(meshName, shaderName), pTex(TexNodeMan::Find(texName)),
			pMixer(_pMixer),
			pWorldCompute(_pWorldCompute),
			poLightColor(nullptr),
			poLightPos(nullptr)
		{
			assert(pTex);
			assert(pMixer);
			assert(pWorldCompute);

			poLightColor = new Vec3(LightColor);
			poLightPos = new Vec3(LightPos);
			assert(poLightColor);
			assert(poLightPos);
		}

		GraphicsObject_SkinLightTexture::GraphicsObject_SkinLightTexture(Mesh* pMesh,
																		ShaderObject::Name shaderName,
																		TextureObject::Name texName,
																		Mixer* _pMixer,
																		WorldCompute* _pWorldCompute,
																		Vec3& LightColor,
																		Vec3& LightPos)															
			: GraphicsObject(pMesh->name, shaderName),
			pTex(TexNodeMan::Find(texName)),
			pMixer(_pMixer),
			pWorldCompute(_pWorldCompute),
			poLightColor(nullptr),
			poLightPos(nullptr)
		{
			assert(pTex);
			assert(pMesh);
			assert(pMixer);
			assert(pWorldCompute);

			poLightColor = new Vec3(LightColor);
			poLightPos = new Vec3(LightPos);
			assert(poLightColor);
			assert(poLightPos);
		}

		GraphicsObject_SkinLightTexture::~GraphicsObject_SkinLightTexture()
		{
			delete poLightColor;
			delete poLightPos;
		}

		void GraphicsObject_SkinLightTexture::SetState()
		{
			this->pTex->ActivateTexture();
			GameMan::GetGame()->mStateRasterizerSolid.Activate();

		}

		void GraphicsObject_SkinLightTexture::SetDataGPU()
		{
			pMesh->ActivateMesh();
			pMesh->ActivateConstantBuffers();
			//pMesh->Transfer_SkinBoneWorldBuffer(this->pBoneWorld);

			pShaderObj->ActivateShader();
			pShaderObj->ActivateCBV();

			Camera* pCam = CameraMan::GetCurrent(Camera::Type::PERSPECTIVE_3D);
			assert(pCam);

			pShaderObj->TransferWorldViewProj(pCam, this->poWorld);
			pShaderObj->TransferLightPos(this->poLightPos);
			pShaderObj->TransferColor(this->poLightColor);

			DirectXDeviceMan::GetContext()->VSSetShaderResources(4, 1, &pWorldCompute->GetBoneWorld()->poShaderResourceView);

		}

		void GraphicsObject_SkinLightTexture::Draw()
		{
			pMesh->RenderIndexBuffer();
		}

		void GraphicsObject_SkinLightTexture::RestoreState()
		{
			// Future - Undo settings to directX
			GameMan::GetGame()->mBlendStateOff.Activate();
		}

}

// --- End of File ---
