//--------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//--------------------------------------------------------------

#pragma pack_matrix( row_major )

//--------------------------------------------------------------------------------------
// File: BasicCompute11.hlsl

// This file contains the Compute Shader to perform array A + array B
// processes thread info and writes it to a unorderd access buffer
//--------------------------------------------------------------------------------------

// thread identifiers
struct BufType
{
    uint3 mGroupID; // Dispatch, thread group id
    uint3 mGroupThreadID; // Local, local thread id
    uint3 mDispatchThreadID; // combo, global thread id across dispatch 
    uint mGroupIndex; // flatten index, flattened thread index within the group
};

// ---------------------------------------------
// tx - t is shader resource views (SRV), x - slot
// ---------------------------------------------

//StructuredBuffer<BufType> Buffer0 : register(t0); // slot 0  (SRVBufferSlot::InputA)
//StructuredBuffer<BufType> Buffer1 : register(t1); // slot 1  (SRVBufferSlot::InputB)

// ---------------------------------------------
// ux - u is  unordered access views (UAV), x - slot 
// ---------------------------------------------
RWStructuredBuffer<BufType> BufferOut : register(u2); // slot 2  (UAVBufferSlot::Test)

[numthreads(8,1,1)]

//how many threads are launched in a group
// 8 threads in the x direction
// 1 thread in the y direction
// 1 thread in the z direction

void BasicCompute_Main( uint3 gID : SV_GroupID,
                        uint3 gtID : SV_GroupThreadID,
                        uint3 dtID : SV_DispatchThreadID,
                        uint gIndex : SV_GroupIndex)
{
    //SV_GroupIndex = SV_GroupThreadID.z * dimx * dimy +
    //                SV_GroupThreadID.y * dimx +
    //                SV_GroupThreadID.x
    // dispatch(2,1,1)

    uint index = gIndex + (gID.x + gID.y * 3)*8;
    BufferOut[index].mGroupID.x = gID.x;
    BufferOut[index].mGroupID.y = gID.y;
    BufferOut[index].mGroupID.z = gID.z;
    BufferOut[index].mGroupThreadID.x = gtID.x;
    BufferOut[index].mGroupThreadID.y = gtID.y;
    BufferOut[index].mGroupThreadID.z = gtID.z;
    BufferOut[index].mDispatchThreadID.x = dtID.x;
    BufferOut[index].mDispatchThreadID.y = dtID.y;
    BufferOut[index].mDispatchThreadID.z = dtID.z;
    BufferOut[index].mGroupIndex = gIndex;
    
}

// --- End of File ---
