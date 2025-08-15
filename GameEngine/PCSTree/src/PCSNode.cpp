//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"

namespace Azul
{
	// constructor
	PCSNode::PCSNode() : pParent(nullptr), pChild(nullptr), pNextSibling(nullptr), pPrevSibling(nullptr), pForward(nullptr), pReverse(nullptr)
	{
		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = '\0';
		}
	}

	// copy constructor
	PCSNode::PCSNode(const PCSNode &in)
	{
		this->pParent = in.pParent;
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;

		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = in.pName[i];
		}
	}

	// Specialize Constructor
	PCSNode::PCSNode(PCSNode* const pInParent, PCSNode* const pInChild, PCSNode* const pInNextSibling, PCSNode* const pInPrevSibling, const char* const pInName)
		: pParent(pInParent), pChild(pInChild), pNextSibling(pInNextSibling), pPrevSibling(pInPrevSibling)
	{
		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = pInName[i];
		}
	}

	PCSNode::PCSNode(const char *const pInName)
	{
		this->pParent = nullptr;
		this->pChild = nullptr;
		this->pNextSibling = nullptr;
		this->pPrevSibling = nullptr;
		this->pForward = nullptr;
		this->pReverse = nullptr;

		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = pInName[i];
		}
	}

	// destructor
	PCSNode::~PCSNode()
	{
		this->pParent = nullptr;
		this->pChild = nullptr;
		this->pNextSibling = nullptr;
		this->pPrevSibling = nullptr;
		this->pForward = nullptr;
		this->pReverse = nullptr;

		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = '\0';
		}
	}

	// assignment operator
	PCSNode &PCSNode::operator = (const PCSNode &in)
	{
		if (this != &in)
		{
			this->pParent = in.pParent;
			this->pChild = in.pChild;
			this->pNextSibling = in.pNextSibling;
			this->pPrevSibling = in.pPrevSibling;
			this->pForward = in.pForward;
			this->pReverse = in.pReverse;

			for (int i = 0; i < PCSNode::NAME_SIZE; i++)
			{
				this->pName[i] = in.pName[i];
			}
		}

		return *this;
	}

	void PCSNode::SetParent(PCSNode *const pIn)
	{
		this->pParent = pIn;
	}

	void PCSNode::SetChild(PCSNode *const pIn)
	{
		this->pChild = pIn;
	}

	void PCSNode::SetNextSibling(PCSNode *const pIn)
	{
		this->pNextSibling = pIn;
	}

	void PCSNode::SetPrevSibling(PCSNode *const pIn)
	{
		this->pPrevSibling = pIn;
	}

	void PCSNode::SetForward(PCSNode *const pIn)
	{
		this->pForward = pIn;
	}

	void PCSNode::SetReverse(PCSNode *const pIn)
	{
		this->pReverse = pIn;
	}

	PCSNode *PCSNode::GetParent(void) const
	{
		return this->pParent;
	}

	PCSNode *PCSNode::GetChild(void) const
	{
		return this->pChild;
	}

	PCSNode *PCSNode::GetNextSibling(void) const
	{
		return this->pNextSibling;
	}

	PCSNode *PCSNode::GetPrevSibling(void) const
	{
		return this->pPrevSibling;
	}

	PCSNode *PCSNode::GetForward(void) const
	{
		return this->pForward;
	}

	PCSNode *PCSNode::GetReverse(void) const
	{
		return this->pReverse;
	}

	PCSNode::Code PCSNode::SetName(const char *const pInName)
	{
		if (pInName == nullptr)
		{
			return PCSNode::Code::FAIL_NULL_PTR;
		}

		for (int i = 0; i < PCSNode::NAME_SIZE; i++)
		{
			this->pName[i] = pInName[i];
		}

		this->pName[PCSNode::NAME_SIZE - 1] = '\0';

		return PCSNode::Code::SUCCESS;
	}

	PCSNode::Code PCSNode::GetName(char *const pOutBuffer, unsigned int sizeOutBuffer) const
	{
		if (pOutBuffer == nullptr)
		{
			return PCSNode::Code::FAIL_NULL_PTR;
		}

		for (unsigned int i = 0; i < PCSNode::NAME_SIZE && i < sizeOutBuffer; i++)
		{
			pOutBuffer[i] = this->pName[i];
		}

		pOutBuffer[sizeOutBuffer - 1] = '\0';

		return PCSNode::Code::SUCCESS;
	}

	void PCSNode::PrintNode() const
	{
		Trace::out("Node: %s\n", this->pName);

		if (this->pParent != nullptr) {
			Trace::out("    Parent: %s\n", this->pParent->pName);
		}
		else
		{
			Trace::out("    Parent: NULL\n");
		}

		if (this->pChild != nullptr) {
			Trace::out("    Child: %s\n", this->pChild->pName);
		}
		else
		{
			Trace::out("    Child: NULL\n");
		}

		if (this->pNextSibling != nullptr) {
			Trace::out("    Next Sibling: %s\n", this->pNextSibling->pName);
		}
		else
		{
			Trace::out("    Next Sibling: NULL\n");
		}

		if (this->pPrevSibling != nullptr) {
			Trace::out("    Prev Sibling: %s\n", this->pPrevSibling->pName);
		}
		else
		{
			Trace::out("    Prev Sibling: NULL\n");
		}

		if (pForward != nullptr) {
			Trace::out("    Forward: %s\n", this->pForward->pName);
		}
		else
		{
			Trace::out("    Forward: NULL\n");
		}

		if (pReverse != nullptr) {
			Trace::out("    Reverse: %s\n\n", this->pReverse->pName);
		}
		else
		{
			Trace::out("    Reverse: NULL\n\n");
		}
	}

	void PCSNode::PrintChildren() const
	{
		Trace::out("Children of %s:\n", this->pName);
		PCSNode* pTmp = this->pChild;
		while (pTmp != nullptr)
		{
			Trace::out("	%s\n", pTmp->pName);
			pTmp = pTmp->pNextSibling;
		}
	}

	void PCSNode::PrintSiblings() const
	{
		Trace::out("Siblings of %s:\n", this->pName);
		PCSNode* pTmp = this->pNextSibling;
		while (pTmp != nullptr)
		{
			Trace::out("	%s\n", pTmp->pName);
			pTmp = pTmp->pNextSibling;
		}
	}

	int PCSNode::GetNumSiblings() const
	{
		PCSNode* pTmp = this->pNextSibling;
		PCSNode* pTmp2 = this->pPrevSibling;
		int count = 1;
		while (pTmp != nullptr)
		{
			count++;
			pTmp = pTmp->pNextSibling;
		}
		while (pTmp2 != nullptr)
		{
			count++;
			pTmp2 = pTmp2->pPrevSibling;
		}
		return count;
	}

	int PCSNode::GetNumChildren() const
	{
		PCSNode* pTmp = this->pChild;
		int count = 0;
		while (pTmp != nullptr)
		{
			count++;
			pTmp = pTmp->pNextSibling;
		}
		return count;
	}
}

// ---  End of File ---
