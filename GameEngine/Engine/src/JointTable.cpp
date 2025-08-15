//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "JointTable.h"
#include "StringThis.h"

namespace Azul
{
	JointTable::JointTable()
		: DLink(),
		mName(JointTable::Name::Not_Initialized),
		numJoints(0),
		poJointTable(nullptr)
	{

	}

	JointTable::~JointTable()
	{
		delete[] this->poJointTable;
	}

	size_t JointTable::GetNumJoints()
	{
		return this->numJoints;
	}

	void JointTable::SetJointTableName(Name JointTableName)
	{
		this->mName = JointTableName;
	}

	void JointTable::Set(Name JointTableName, size_t _numJoints, unsigned int *_pJointTable)
	{
		this->mName = JointTableName;
		this->numJoints = _numJoints;

		delete[] this->poJointTable;

		assert(_pJointTable);
		this->poJointTable = new unsigned int[this->numJoints]();
		size_t size = this->numJoints * sizeof(unsigned int);
		memcpy(this->poJointTable, _pJointTable, size);
	}

	bool JointTable::Compare(DLink *pTarget)
	{
		// This is used in ManBase.Find() 
		assert(pTarget != nullptr);

		JointTable *pDataB = (JointTable *)pTarget;

		bool status = false;

		if(this->mName == pDataB->mName)
		{
			status = true;
		}

		return status;
	}

	void JointTable::Dump()
	{
		Trace::out("      JointTable(%p)\n", this);
		Trace::out("      Name: %s \n", StringMe(this->mName));

		DLink::Dump();
	}

	void JointTable::Wash()
	{
		this->mName = JointTable::Name::Not_Initialized;
		this->numJoints = 0;
		this->poJointTable = nullptr;
	}

}

// --- End of File ---
