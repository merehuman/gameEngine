//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"
#include "MathApp.h"

//----------------------------------------------------------------------------- 
// Mutates result to be a slerp between the source and target by the
// specified factor.
// For a factor of 0.0, result == source.
// For a factor of 1.0, result == target.
//----------------------------------------------------------------------------- 

namespace Azul
{
	void QuatApp::Slerp(Quat& result, const Quat& source, const Quat& target, const float slerpFactor)
	{
        float dot = source.dot(target);

        Quat q1 = target;

        if (dot < 0.0f)
        {
            dot = -dot;
            q1[x] = -target.qx();
            q1[y] = -target.qy();
            q1[z] = -target.qz();
            q1[w] = -target.real();
        }

        if (dot > 0.9995f)
        {
            result = source + slerpFactor * (q1 - source);
            result.norm();
            return;
        }

        float phi = acosf(dot);
        float sin_phi = sinf(phi);

        float weight_src = sinf((1.0f - slerpFactor) * phi) / sin_phi;
        float weight_tar = sinf(slerpFactor * phi) / sin_phi;

        result[x] = weight_src * source[x] + weight_tar * q1[x];
        result[y] = weight_src * source[y] + weight_tar * q1[y];
        result[z] = weight_src * source[z] + weight_tar * q1[z];
        result[w] = weight_src * source[w] + weight_tar * q1[w];


	}
	void QuatApp::SlerpArray(Quat* result, const Quat* source, const Quat* target, const float slerpFactor, const int numQuats)
	{
        for (int i = 0; i < numQuats; ++i)
        {
            Slerp(result[i], source[i], target[i], slerpFactor);
        }
	}
}

// ---  End of File ---------------
