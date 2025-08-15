//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef SKELETON_H
#define SKELETON_H

#include "GameObjectAnim.h"
#include "Bone.h"
#include "Skel.h"
#include "JointTable.h"
#include "Clip.h"

namespace Azul
{
	class Skeleton
	{
	public:

		Skeleton(Clip::Name _name);

		Skeleton() = delete;
		Skeleton(const Skeleton &) = delete;
		Skeleton &operator = (const Skeleton &) = delete;
		~Skeleton();

		Clip *GetClip();
		Bone *GetBoneResult();
		//GameObjectAnim *GetFirstBone();
		//GameObjectAnim *FindBoneByIndex(int index);
		int GetNumNodes() const;

	private:
	//	void privSetAnimationHierarchy();

	private:
		//GameObjectAnim	*pFirstBone;
		int             mNumNodes;
		Bone			*poBoneResult;
		Skel			*pSkel;
		Clip			*pClip;
	};
}

#endif

// --- End of File ---
