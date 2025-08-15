//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#ifndef HIERARCHY_TABLE_H
#define HIERARCHY_TABLE_H

#include "DLink.h"

namespace Azul
{
	class HierarchyTable : public DLink
	{
	public:
		enum Name
		{
			ChickenBot,
			Mousey,
			Elf,
			Sitting,
			Talking,
			Excited,
			Swimming,
			Dancing,
			Not_Initialized
		};

	public:
		HierarchyTable();
		HierarchyTable(const HierarchyTable &) = delete;
		HierarchyTable &operator = (const HierarchyTable &) = delete;
		virtual ~HierarchyTable();

		size_t	GetNumJoints();
		size_t  GetDepth();
		void SetHierarchyTableName(Name JointTableName);

		void Set(Name HierarchyTableName, size_t numJoints, size_t depth, unsigned int *pJointTable);

		virtual bool Compare(DLink *pTarget) override;
		virtual void Dump() override;
		virtual void Wash() override;


	public:
		Name         mName;
		size_t       mNumJoints;
		size_t		 mDepth;
		unsigned int *poHierarchyTable;
	};
}

#endif

//--- End of File ---
