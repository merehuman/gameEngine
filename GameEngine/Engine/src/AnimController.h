//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef ANIM_CONTROLLER_H
#define ANIM_CONTROLLER_H

#include "TimerController.h"
#include "GameObjectAnim.h"
#include "Anim.h"

namespace Azul
{
	class AnimController
	{
	public:
		AnimController(Anim *pAnim, AnimTime delta);
		AnimController(const AnimController &) = delete;
		AnimController &operator = (const AnimController &) = delete;
		~AnimController();

		void Update();
		
		Anim* GetAnim() const;
		TimerController* GetTimerController() const;

	private:
		TimerController *poTimerControl;
		Anim *poAnim;

	};
}

#endif

// --- End of File ---
