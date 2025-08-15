//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------
#ifndef HIERACRCHY_DATA_H
#define HIERACRCHY_DATA_H

#include "HierarchyData.pb.h"
#include "ProtoVersion.h"

namespace Azul
{
	class HierarchyData
	{
	public:
		HierarchyData();
		HierarchyData(const HierarchyData &) = delete;
		HierarchyData &operator = (const HierarchyData &);
		~HierarchyData();

		HierarchyData(unsigned int _numJoints, unsigned int _maxDepth);

		// Serialization 
		void Serialize(HierarchyData_proto &out) const;
		void Deserialize(const HierarchyData_proto &in);

		void Print(const char *const pName) const;

	public:
		char  pVersion[protoVersion::VERSION_NUM_BYTES];
		unsigned int numJoints;
		unsigned int maxDepth;
		unsigned int *poData;
	};

}

#endif

// --- End of File ---
