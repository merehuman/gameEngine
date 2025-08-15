//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

#include "HierarchyTableProto.h"
#include "File.h"
#include "HierarchyData.h"

namespace Azul
{
	HierarchyTableProto::~HierarchyTableProto()
	{
	}

	HierarchyTableProto::HierarchyTableProto(const char *const pFileName)
	{
		assert(pFileName);

		unsigned char *poBuff;
		unsigned int numBytes;

		File::Error ferror;
		ferror = File::GetFileAsBuffer(pFileName, poBuff, numBytes);
		assert(ferror == File::Error::SUCCESS);

		// Now the raw data is poBUff
		// deserialize the data --> mB
		std::string strIn((const char *)poBuff, numBytes);
		HierarchyData_proto mB_proto;

		mB_proto.ParseFromString(strIn);

		HierarchyData mB;
		mB.Deserialize(mB_proto);
		delete[] poBuff;

		this->mNumJoints = mB.numJoints;
		this->mDepth = mB.maxDepth;

		size_t count = this->mNumJoints * this->mDepth;
		this->poHierarchyTable = new unsigned int[count]();
		assert(this->poHierarchyTable);
		size_t size = count * sizeof(unsigned int);
		memcpy(this->poHierarchyTable, mB.poData, size);

	}
}

//--- End of File ---
