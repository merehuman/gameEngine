//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#pragma pack_matrix( row_major )

//--------------------------------------------------------------------------------------
// File: Mixer.Cx.hlsl
// blends bone animations between two keyframes
// writes the blended bone transformations to an output buffer which is used by the world shader
//--------------------------------------------------------------------------------------

// ---------------------------------------------
// Structure for SRV and UAV Buffer
// ---------------------------------------------
struct BoneType
{
    float4 t; //trans
    float4 q; //quat
    float4 s; //scale
};

// ---------------------------------------------
// Functions
// ---------------------------------------------
float4 slerp(float4 src, float4 tar, float t); //spherical linear interpolation
float4 lerpMe(float4 src, float4 tar, float t); //linear interpolation

// ---------------------------------------------
// tx - t is shader resource views (SRV), x - slot
// ---------------------------------------------

//first and second keyframe data
StructuredBuffer<BoneType> KeyA : register(t1); // slot 1 (ShaderResourceBufferSlot::KeyA)   
StructuredBuffer<BoneType> KeyB : register(t2); // slot 2 (ShaderResourceBufferSlot::KeyB)

// ------------------------------------------
// bx - b is constant buffer, x - slot
// ------------------------------------------

//blend factor and number of bones
cbuffer AA : register(b9) // slot 9 (ConstantBufferSlot::csMixer)
{
    float ts;
    uint numNodes;
};

// ----------------------------------------------------
// ux - u is  unordered access views (UAV), x - slot 
// ----------------------------------------------------

//output buffer for interpolated keyframes
RWStructuredBuffer<BoneType> MixerOut : register(u0); // slot 0  (UnorderedAccessBufferSlot::MixerABOut)

[numthreads(1, 1, 1)] //each thread processes one bone
// runs once per thread to blend bone transformations
void Mixer_Main(uint3 dtID : SV_DispatchThreadID)
{
    uint boneIndex = dtID.x; // bone index

    // protection incase index is outside array range
    if (dtID.x < numNodes)
    {
    	MixerOut[boneIndex] = KeyA[boneIndex];
  
        // blend the bone transformations
        float4 trans = lerpMe(KeyA[boneIndex].t, KeyB[boneIndex].t, ts);
        float4 quat = slerp(KeyA[boneIndex].q, KeyB[boneIndex].q, ts);
        float4 scale = lerpMe(KeyA[boneIndex].s, KeyB[boneIndex].s, ts);

        // store the blended bone transformation
        MixerOut[boneIndex].t = trans;
        MixerOut[boneIndex].q = quat;
        MixerOut[boneIndex].s = scale;
    }
	
}

float4 lerpMe(float4 src, float4 tar, float t)
{
    float4 result;
    
    result.x = src.x + t * (tar.x - src.x);
    result.y = src.y + t * (tar.y - src.y);
    result.z = src.z + t * (tar.z - src.z);
    result.w = 1.0f;
    
    return result;
}

float4 slerp(float4 src, float4 tar, float t)
{
    float4 result;
    float4 target;
    float QUAT_EPSILON = 0.001f;

	// Not sure if dot is 3D or 4D... need 4D
	//float cosom = dot(src, tar);
	
    float cosom = src.x * tar.x + src.y * tar.y + src.z * tar.z + src.w * tar.w;

    if (cosom >= 1.0f)
    {
		// do nothing
        result = src;
    }
    else
    {
		// adjust signs if necessary
        if (cosom < 0.0f)
        {
            cosom = -cosom;
            target = -tar;
        }
        else
        {
            target = tar;
        }

		// If the the source and target are close, we can do a lerp.
        float tarFactor = t;
        float srcFactor = 1.0f - t;

		// calculate coefficients
        if (cosom < (1.0f - QUAT_EPSILON))
        {
			// Quats are not close enough for a lerp.
			// Calculating coefficients for a slerp.
            const float omega = acos(cosom);
            const float sinom = 1.0f / sin(omega);

            srcFactor = sin(srcFactor * omega) * sinom;
            tarFactor = sin(tarFactor * omega) * sinom;
        }

        result.x = src.x * srcFactor + target.x * tarFactor;
        result.y = src.y * srcFactor + target.y * tarFactor;
        result.z = src.z * srcFactor + target.z * tarFactor;
        result.w = src.w * srcFactor + target.w * tarFactor;
    }

    return result;
}


// --- End of File ---
