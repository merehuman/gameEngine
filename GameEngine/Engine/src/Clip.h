//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef CLIP_H
#define CLIP_H

#include "AnimTime.h"
#include "Skel.h"

namespace Azul
{
	class Mixer;
	class FrameBucket;
	class FrameBucketEntry;

	class Clip : public DLink
	{
	public:
		enum Name
			{
			Walk_ChickenBot,
			Mousey_Silly_Dance,
			Elf,
			Sitting,
			Talking,
			Excited,
			Swimming,
			Dancing,
			Not_Initialized
		};

	public:
		Clip();
		Clip(const Clip &) = delete;
		Clip &operator = (const Clip &) = delete;
		virtual ~Clip();

		AnimTime GetTotalTime();
		size_t GetNumNodes();
		Skel::Name GetSkelName();
		void SetClipName(Name clipName);
		Name GetClipName();

		void Set(Clip::Name clipName,
				 unsigned int numNodes,
				 unsigned int numKeyFrames,
				 FrameBucketEntry *pFrameBucket,
				 Skel::Name skelName);

		void AnimateBones(AnimTime tCurr, Mixer *pMixer);

		virtual bool Compare(DLink *pTarget) override;
		virtual void Dump() override;
		virtual void Wash() override;

	private:
		AnimTime privFindMaxTime();
		int  privFindNumFrames();

	private:
		Name         mName;
		size_t       numNodes;
		size_t       numFrames;
		Skel::Name   skelName;
		AnimTime     TotalTime;
		FrameBucket *poHead;
	};
}

#endif

//--- End of File ---
