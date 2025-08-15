//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeReverseIterator.h"

namespace Azul
{
	PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode *rootNode)
	{
		this->root = rootNode;
		this->current = nullptr;
		this->prevNode = nullptr;
	}

	PCSNode *PCSTreeReverseIterator::First()
	{
		PCSNode* node = this->root;
		if (node == nullptr)
		{
			return nullptr;
		}

		while (node->GetForward() != nullptr)
		{
			node = node->GetForward();
		}
		this->current = node;
		return this->current;
	}

	PCSNode *PCSTreeReverseIterator::Next()
	{
		if (this->current != nullptr)
		{
			this->current = this->current->GetReverse();
		}
		return this->current;
	}

	bool PCSTreeReverseIterator::IsDone()
	{
		return this->current == nullptr;
	}

	PCSNode *PCSTreeReverseIterator::Current()
	{
		return this->current;
	}

	PCSNode* PCSTreeReverseIterator::Prev()
	{
		return this->prevNode;
	}

}

// ---  End of File ---
