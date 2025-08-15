//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode *rootNode)
	{
		this->root = rootNode;
		this->current = nullptr;
	}

	PCSNode *PCSTreeForwardIterator::First()
	{
		this->current = this->root;
		return this->current;
	}

	PCSNode *PCSTreeForwardIterator::Next()
	{
		if (this->current != nullptr)
		{
			this->current = this->current->GetForward();
		}
		return this->current;
	}

	bool PCSTreeForwardIterator::IsDone()
	{
		return this->current == nullptr;
	}

	PCSNode *PCSTreeForwardIterator::Current()
	{
		return this->current;
	}

}

// ---  End of File ---
