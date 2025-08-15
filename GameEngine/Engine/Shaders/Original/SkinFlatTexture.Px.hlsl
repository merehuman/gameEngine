//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

// Enable data
#define SAMPLER_sA
#define SRV_tMainTexture

#include "ShaderMappings.hlsli"

// -------------------------------------
//  Pixel Shader Input Sematics
//        TEXCOORD - uv tex coord
// -------------------------------------
struct PixelShaderInput
{
    float2 tex : TEXCOORD;
    float4 position : SV_POSITION;
};

// --------------------------------------------------------
//  Pixel Shader Main()
//      SV_TARGET - System Value Target
//                  output stored in a render target 0  (only one target)
// --------------------------------------------------------
float4 SkinFlatTexture_Main(PixelShaderInput inData ) : SV_TARGET
{
	return tMainTexture.Sample(sSamplerA, inData.tex);
}


// --- End of File ---
