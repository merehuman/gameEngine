//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef ANIM_H
#define ANIM_H

#include "AnimTimer.h"
#include "MathEngine.h"
#include "GameObjectAnimSkin.h"
#include "GameObjectAnimSkeleton.h"
#include "Clip.h"
#include "Skeleton.h"
#include "JointTable.h"
#include "Mixer.h"

namespace Azul
{
	class Anim
	{
	public:

		Anim(Skeleton *ptSkeleton, Mixer *pMixer);

		Anim() = delete;
		Anim(const Anim &) = delete;
		Anim &operator = (const Anim &) = delete;
		~Anim();

		void Animate(AnimTime tCurr);
		AnimTime FindMaxTime();

	private:
		Skeleton        *poSkeleton;
		Clip *pClip;
		Mixer *pMixer;
	};

}

#endif

// --- End of File ---
