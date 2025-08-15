//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"

namespace Azul
{

	// constructor
	PCSTree::PCSTree() : pRoot(nullptr)
	{
		mInfo.currNumNodes = 0;
		mInfo.maxNumNodes = 0;
		mInfo.currNumLevels = 0;
		mInfo.maxNumLevels = 0;
	}

	// destructor
	PCSTree::~PCSTree()
	{
		this->pRoot = nullptr;
		mInfo.currNumLevels = 0;
		mInfo.currNumNodes = 0;
		mInfo.maxNumLevels = 0;
		mInfo.maxNumNodes = 0;
	}

	// get Root
	PCSNode *PCSTree::GetRoot() const
	{
		return this->pRoot;
	}

	// insert
	void PCSTree::Insert(PCSNode* const pInNode, PCSNode* const pParent)
	{
		//if node is null
		if (pInNode == nullptr) return;

		//if parent
		if (pParent != nullptr)
		{
			//if first child
			if (pParent->GetChild() == nullptr)
			{
				pParent->SetChild(pInNode);
				pInNode->SetParent(pParent);

				pParent->SetForward(pInNode); //set forward to first child
				pInNode->SetReverse(pParent); //set reverse to parent

				if (pParent->GetNextSibling() != nullptr)
				{
					pInNode->SetForward(pParent->GetNextSibling());
					pParent->GetNextSibling()->SetReverse(pInNode);
				}
				else if (pParent->GetParent() != nullptr)
				{
					if (pParent->GetParent()->GetNextSibling() != nullptr)
					{
						pInNode->SetForward(pParent->GetParent()->GetNextSibling());
						pParent->GetParent()->GetNextSibling()->SetReverse(pInNode);
					}
				}
			}
			//if not first child
			else
			{
				PCSNode* pTmp = pParent->GetChild();

				pParent->SetChild(pInNode);
				pInNode->SetParent(pParent);

				pInNode->SetNextSibling(pTmp);
				pTmp->SetPrevSibling(pInNode);

				pParent->SetForward(pInNode); //set forward to first child
				pInNode->SetForward(pTmp); //set forward to old first child
				
				pTmp->SetReverse(pInNode); //set reverse to new first child
				pInNode->SetReverse(pParent); //set reverse to parent

			}
		}
		//if the root
		else
		{
			this->pRoot = pInNode;
		}


		//update tree info
		mInfo.currNumNodes++;
		if (mInfo.currNumNodes > mInfo.maxNumNodes) { mInfo.maxNumNodes = mInfo.currNumNodes; }

		int numLevels = 1;
		PCSNode* pTmp2 = pInNode->GetParent();
		while (pTmp2 != nullptr)
		{
			numLevels++;
			pTmp2 = pTmp2->GetParent();
		}

		mInfo.currNumLevels = numLevels;
		if (numLevels > mInfo.maxNumLevels) { mInfo.maxNumLevels = numLevels; }
	}

	// Remove
	void PCSTree::Remove(PCSNode* const pInNode)
	{
		//if node is null
		if (pInNode == nullptr) return;

		//if root
		if (pInNode == this->pRoot)
		{
			RemoveHelper(this->pRoot);
			this->pRoot = nullptr;
			mInfo.currNumLevels = 0;
			mInfo.currNumNodes = 0;
			return;
		}
		else
		{
			//get the siblings and parent
			PCSNode* pPrev = pInNode->GetPrevSibling();
			PCSNode* pNext = pInNode->GetNextSibling();
			PCSNode* pParent = pInNode->GetParent();

			//remove subtree
			RemoveHelper(pInNode->GetChild());

			if (pPrev != nullptr && pNext != nullptr) //if both siblings exist
			{
				pPrev->SetNextSibling(pNext);
				pNext->SetPrevSibling(pPrev);
				
				pInNode->GetReverse()->SetForward(pNext);
				pNext->SetReverse(pInNode->GetReverse());

			}
			else if (pPrev == nullptr && pNext != nullptr) //if first but not last
			{
				if (pParent != nullptr && pParent->GetChild() == pInNode)
				{
					pParent->SetChild(pNext);
					pParent->SetForward(pNext);
					pNext->SetReverse(pParent);
					pNext->SetPrevSibling(nullptr);
				}
			}
			else if (pPrev != nullptr && pNext == nullptr) //if last but not first
			{
				pPrev->SetNextSibling(nullptr);

				if (pInNode->GetReverse() == pInNode->GetPrevSibling()) //if no children
				{
					pPrev->SetForward(nullptr);
				}
				else
				{
					pInNode->GetReverse()->SetForward(nullptr);
				}

				if (pParent->GetNextSibling() != nullptr)
				{
					pPrev->SetForward(pParent->GetNextSibling());
					pParent->GetNextSibling()->SetReverse(pPrev);
				}
				else if (pParent->GetParent() != nullptr)
				{
					if (pParent->GetParent()->GetNextSibling() != nullptr)
					{
						pPrev->SetForward(pParent->GetParent()->GetNextSibling());
						pParent->GetParent()->GetNextSibling()->SetReverse(pPrev);
					}
				}
			}
			else //if only child
			{
				if (pParent != nullptr && pParent->GetChild() == pInNode)
				{
					pParent->SetChild(nullptr);
					pParent->SetForward(nullptr);
					if (pParent == this->pRoot)
					{
						pParent->SetForward(nullptr);
					}
					else
					{
						if (pParent->GetNextSibling() != nullptr)
						{
							pParent->SetForward(pParent->GetNextSibling());
							pParent->GetNextSibling()->SetReverse(pParent);
						}
						else if (pParent->GetParent() != nullptr)
						{
							if (pParent->GetParent()->GetNextSibling() != nullptr)
							{
								pParent->SetForward(pParent->GetParent()->GetNextSibling());
								pParent->GetParent()->GetNextSibling()->SetReverse(pParent);
							}
						}
					}
				}
			}
		}

		//clean up the removed node
		pInNode->SetParent(nullptr);
		pInNode->SetNextSibling(nullptr);
		pInNode->SetPrevSibling(nullptr);
		pInNode->SetChild(nullptr);
		pInNode->SetForward(nullptr);
		pInNode->SetReverse(nullptr);

		//update tree info
		mInfo.currNumNodes--;
		mInfo.currNumLevels = 0;
		LevelsHelper(this->pRoot, 0);
	}

	void PCSTree::RemoveHelper(PCSNode* const pNode)
	{
		if (pNode != nullptr)
		{
			RemoveHelper(pNode->GetNextSibling());
			RemoveHelper(pNode->GetChild());

			pNode->SetParent(nullptr);
			pNode->SetNextSibling(nullptr);
			pNode->SetPrevSibling(nullptr);
			pNode->SetForward(nullptr);
			pNode->SetReverse(nullptr);
			pNode->SetChild(nullptr);
			mInfo.currNumNodes--;
		}
	}

	void PCSTree::LevelsHelper(PCSNode* const pNode, int level)
	{
		if (pNode != nullptr)
		{
			LevelsHelper(pNode->GetChild(), level + 1);
			LevelsHelper(pNode->GetNextSibling(), level);
		}

		if (level > mInfo.currNumLevels) { mInfo.currNumLevels = level; }
	}

	// get tree info
	void PCSTree::GetInfo(Info &info)
	{
		info = this->mInfo;
	}

	void PCSTree::Print() const
	{
		if (this->pRoot != nullptr)
		{
			PrintHelper(this->pRoot, 0);
		}
	}

	void PCSTree::PrintHelper(PCSNode* const pNode, int level) const
	{
		if (pNode != nullptr)
		{
			for (int i = 0; i < level; i++)
			{
				Trace::out("\t");
			}
			pNode->PCSNode::PrintNode();

			PrintHelper(pNode->GetChild(), level + 1);
			PrintHelper(pNode->GetNextSibling(), level);
		}
	}

}

// ---  End of File ---
