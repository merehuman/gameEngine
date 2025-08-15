//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#ifndef SHADER_MAPPINGS_H
#define SHADER_MAPPINGS_H

namespace Azul
{

	enum class VertexSlot : uint32_t
	{
		Position,  //0
		Color,     //1
		Norm,      //2
		TexCoord,  //3
		Weights,   //4  Skin
		Joints     //5  Skin
	};
 
	// in shaders these are CBV slot "bx"
	enum class ConstantBufferSlot : uint32_t
	{
		vsProjection,   // 0
		vsView,         // 1
		vsWorld,        // 2

		vsLightColor,    // 3
		vsLightPos,      // 4

		psSprite_UV_Correction, // 5
		psSprite_ColorScale,    //6

		vsSkinInvBind ,      //7  Skin
		vsSkinBoneWorld,     //8  Skin

		csMixer,         //9
		csWorld			 //10
	};


	// in shaders these are Sampler slot "sx"
	enum class ShaderSamplerSlot : uint32_t
	{
		SampleA   // slot 0
	};


	// in shaders these are SRV slot "tx"
	enum class ShaderResourceBufferSlot : uint32_t
	{
		Texture,		 // 0
		KeyA,            // 1  
		KeyB,            // 2  
		HierarchyTable,  // 3
		BoneWorldIn,     // 4
		InvBind          // 5
	};

	// in shaders these are UAV slot "ux"
	enum class UnorderedAccessBufferSlot : uint32_t
	{
		MixerABOut,    // slot 0  
		BoneWorldOut,   // slot 1  

		Test // 2

	};


}

#endif

// --- End of File ---
