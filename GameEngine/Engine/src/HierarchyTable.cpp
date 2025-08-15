//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "HierarchyTable.h"
#include "StringThis.h"

namespace Azul
{
	HierarchyTable::HierarchyTable()
		: DLink(),
		mName(HierarchyTable::Name::Not_Initialized),
		mNumJoints(0),
		mDepth(0),
		poHierarchyTable(nullptr)
	{

	}

	HierarchyTable::~HierarchyTable()
	{
		delete[] this->poHierarchyTable;
	}

	size_t HierarchyTable::GetNumJoints()
	{
		return this->mNumJoints;
	}
	size_t HierarchyTable::GetDepth()
	{
		return this->mDepth;
	}
	void HierarchyTable::SetHierarchyTableName(Name HierarchyTableName)
	{
		this->mName = HierarchyTableName;
	}

	void HierarchyTable::Set(Name JointTableName, 
							 size_t _numJoints, 
							 size_t _depth,
							 unsigned int *_pHierarchyTable)
	{
		this->mName = JointTableName;
		this->mNumJoints = _numJoints;
		this->mDepth = _depth;

		delete[] this->poHierarchyTable;

		assert(_pHierarchyTable);
		size_t count = this->mNumJoints * this->mDepth;
		this->poHierarchyTable = new unsigned int[count]();
		size_t size = count* sizeof(unsigned int);
		memcpy(this->poHierarchyTable, _pHierarchyTable, size);
	}

	bool HierarchyTable::Compare(DLink *pTarget)
	{
		// This is used in ManBase.Find() 
		assert(pTarget != nullptr);

		HierarchyTable *pDataB = (HierarchyTable *)pTarget;

		bool status = false;

		if(this->mName == pDataB->mName)
		{
			status = true;
		}

		return status;
	}

	void HierarchyTable::Dump()
	{
		Trace::out("      HierarchyTable(%p)\n", this);
		Trace::out("      Name: %s \n", StringMe(this->mName));

		DLink::Dump();
	}

	void HierarchyTable::Wash()
	{
		this->mName = HierarchyTable::Name::Not_Initialized;
		this->mNumJoints = 0;
		this->mDepth = 0;
		this->poHierarchyTable = nullptr;
	}

}

// --- End of File ---
