//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "AnimController.h"
#include "Anim.h"

namespace Azul
{
	AnimController::AnimController(Anim *pAnim, AnimTime delta)
	{
		assert(pAnim);

		// Animation object
		this->poAnim = pAnim;
		assert(this->poAnim);

		// TimerController
		AnimTime maxTime = poAnim->FindMaxTime();
		AnimTime minTime = AnimTime(AnimTime::Duration::ZERO);
		this->poTimerControl = new TimerController(delta, minTime, maxTime);
		assert(this->poTimerControl);

	}

	AnimController::~AnimController()
	{
		delete poAnim;
		delete poTimerControl;
	}

	void AnimController::Update()
	{
		this->poTimerControl->Update();

		// interpolate all bones
		this->poAnim->Animate(this->poTimerControl->GetCurrTime());

	}

	Anim* AnimController::GetAnim() const
	{
		return this->poAnim;
	}

	TimerController* AnimController::GetTimerController() const
	{
		return this->poTimerControl;
	}
}

// --- End of File ---
