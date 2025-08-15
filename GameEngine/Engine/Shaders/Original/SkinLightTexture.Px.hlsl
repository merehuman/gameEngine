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
struct VertexShaderOutput
{
    float2 tex : TEXCOORD;
    float4 color : COLOR;
    float4 position : SV_POSITION;
};

// --------------------------------------------------------
//  Pixel Shader Main()
//      SV_TARGET - System Value Target
//                  output stored in a render target 0  (only one target)
// takes data from the vertex shader, samples the texture, and returns the color
// --------------------------------------------------------
float4 SkinLightTexture_Main(VertexShaderOutput inData) : SV_TARGET
{
    return inData.color * tMainTexture.Sample(sSamplerA, inData.tex);
}


// --- End of File ---
