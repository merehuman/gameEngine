//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef GRAPHICS_OBJECT_SKIN_LIGHT_TEXTURE_H
#define GRAPHICS_OBJECT_SKIN_LIGHT_TEXTURE_H

#include "GraphicsObject.h"
#include "TextureObject.h"
#include "Mixer.h"
#include "WorldCompute.h"

namespace Azul
{
	class GraphicsObject_SkinLightTexture : public GraphicsObject
	{
	public:
		GraphicsObject_SkinLightTexture(Mesh::Name meshName,
			ShaderObject::Name shaderName,
			TextureObject::Name texName,
			Mixer* pMixer,
			WorldCompute* pWorldCompute,
			Vec3& _pLightColor,
			Vec3& _pLightPos);

		// todo - can this be deleted?
		GraphicsObject_SkinLightTexture(Mesh* pMesh,
			ShaderObject::Name shaderName,
			TextureObject::Name texName,
			Mixer* pMixer,
			WorldCompute* pWorldCompute,
			Vec3& _pLightColor,
			Vec3& _pLightPos);

		GraphicsObject_SkinLightTexture() = delete;
		GraphicsObject_SkinLightTexture(const GraphicsObject_SkinLightTexture&) = delete;
		GraphicsObject_SkinLightTexture& operator=(const GraphicsObject_SkinLightTexture&) = delete;
		virtual ~GraphicsObject_SkinLightTexture();

		// Render Material Contract
		virtual void SetState() override;
		virtual void SetDataGPU() override;
		virtual void Draw() override;
		virtual void RestoreState() override;



		// Texture and Compute Data
		TextureObject* pTex;
		Mixer* pMixer;
		WorldCompute* pWorldCompute;

		Vec3* poLightColor;
		Vec3* poLightPos;
	};
}

#endif
