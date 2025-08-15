//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------
//
//  https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5-system-values
//  https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl/registers---vs-5-0
//  https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl/registers---cs-5-0
//
// -------------------------------------------------------------

struct rowMatrix
{
    row_major matrix m;
};

#define BONE_COUNT_MAX 8//46


// ------------------------------------------
// Vertex data s is sampler, x - slot
// ------------------------------------------


#ifdef VERTEX_pos
    struct VertData_pos  //  vertex constant buffer, slot 0 (VertexSlot::Position)
    {
        float3 pos : POSITION;
    };
#endif

#ifdef VERTEX_color
    struct VertData_color  // vertex constant buffer, slot 1 (VertexSlot::Color)
    {
        float3 color : COLOR;
    };
#endif

#ifdef VERTEX_norm
    struct VertData_norm  // vertex constant buffer, slot 2 (VertexSlot::Norm)
    {
        float3 norm : NORMAL; // norm location
    };
#endif

#ifdef VERTEX_tex
    struct VertData_tex  // vertex constant buffer, slot 3 (VertexSlot::TexCoord)
    {
        float2 tex : TEXCOORD; // uv location
    };
#endif

#ifdef VERTEX_weight
    struct VertData_weight  // vertex constant buffer, slot 4 (VertexSlot::Weights)
    {
        float4 w : BLENDWEIGHT; // weight location
    };
#endif

#ifdef VERTEX_joint
    struct VertData_joint  // vertex constant buffer, slot 5 (VertexSlot::Joints)
    {
        uint4 j : BLENDINDICES; // joints location
    };
#endif

// ------------------------------------------
// sx - s is sampler, x - slot
// ------------------------------------------

#ifdef SAMPLER_sA
    SamplerState sSamplerA : register(s0);
#endif

// --------------------------------------------------
// tx - t is input shader resource views (SRV), x - slot
//      max count == 128
// --------------------------------------------------

#ifdef SRV_tMainTexture
    Texture2D tMainTexture : register(t0);
#endif

// --------------------------------------------------
// bx - b is constant buffer, x - slot
//      in compiled shader its displayed as cbX
//      max count == 15
// --------------------------------------------------

#ifdef CBV_vsProjectionMatrix
    cbuffer AA0 : register(b0) // slot 0  (ConstantBufferSlot::vsProjection)
    {
        row_major matrix vsProjectionMatrix;
    }
#endif

#ifdef CBV_vsViewMatrix
    cbuffer AA1 : register(b1) // slot 1 (ConstantBufferSlot::vsView)
    {
        row_major matrix vsViewMatrix;
    }
#endif

#ifdef CBV_vsWorldMatrix
    cbuffer AA2 : register(b2) // slot 2 (ConstantBufferSlot::vsWorld)
    {
        row_major matrix vsWorldMatrix; // this is the pivot
    }
#endif

#ifdef CBV_vsLightColor
    cbuffer AA3 : register(b3) // slot 3 (ConstantBufferSlot::vsLightColor)
    {
        float4 vsLightColor;
    }
#endif

#ifdef CBV_vsLightPos
    cbuffer AA4 : register(b4) // slot 4 (ConstantBufferSlot::vsLightPos)
    {
        float4 vsLightPos;
    }
#endif

#ifdef CBV_psUVMatrix
    cbuffer AA5 : register(b5) // slot 5 (ConstantBufferSlot::psSprite_UV_Correction)
    {
        row_major matrix psUVMatrix;
    }
#endif

#ifdef CBV_psColorScale
    cbuffer AA6 : register(b6) // slot 6 (ConstantBufferSlot::psSprite_ColorScale)
    {
        float4 psColorScale;
    }
#endif

#ifdef CBV_vsSkinInvBind
    cbuffer AA7 : register(b7) // slot 7 (ConstantBufferSlot::vsSkinInvBind)
    {
       row_major matrix vsSkinInvBind[BONE_COUNT_MAX];
    }
#endif

#ifdef CBV_vsSkinBoneWorld
    cbuffer AA8 : register(b8) // slot 8 (ConstantBufferSlot::vsSkinBoneWorld)
    {
       row_major matrix vsSkinBoneWorld[BONE_COUNT_MAX];
    }
#endif


// --- End of File ---
