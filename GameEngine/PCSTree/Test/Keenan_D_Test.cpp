//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeReverseIterator.h"
#include "PCSTreeReverseIterator.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Modifying any Unit Test to alter the outcome results 
//       is also an Academic Integrity Violation       
//---------------------------------------------------------------------------

char pTestRev_ResultComplete[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_Q[24][PCSNode::NAME_SIZE]
{
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_W[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_V[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_U[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};


char pTestRev_Result_T[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};


char pTestRev_Result_S[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_P[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_O[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};


char pTestRev_Result_R[24][PCSNode::NAME_SIZE]
{
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_C[24][PCSNode::NAME_SIZE]
{
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_N[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_M[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_L[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};


char pTestRev_Result_K[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_B[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_J[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_G",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};


char pTestRev_Result_G[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_I",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_I[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_E",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_E[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_H",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_H[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_F",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_F[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_D",
"Node_A",
"Root"
};

char pTestRev_Result_D[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Node_J",
"Node_G",
"Node_I",
"Node_E",
"Node_A",
"Root"
};

char pTestRev_Result_A[24][PCSNode::NAME_SIZE]
{
"Node_Q",
"Node_W",
"Node_V",
"Node_U",
"Node_T",
"Node_S",
"Node_P",
"Node_O",
"Node_R",
"Node_C",
"Node_N",
"Node_M",
"Node_L",
"Node_K",
"Node_B",
"Root"
};

char pTestRev_Result_ABC[24][PCSNode::NAME_SIZE]
{
"Root"
};

// Stubbed out
TEST(Keenan_D_Enable, TestConfig::ALL)
{
#if Keenan_D_Enable


	// Full treee
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);


			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			//Trace::out("\n\n\n--------\n\n\n");

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			CHECK(count == 24);

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_ResultComplete[i]) == 0);
			}

			count = 0;
			PCSTreeReverseIterator pRevIter(tree.GetRoot());
			PCSNode *pNode = pRevIter.First();

			CHECK(count == 0);
			CHECK(pNode == &nodeQ);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 1);
			CHECK(pNode == &nodeW);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 2);
			CHECK(pNode == &nodeV);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 3);
			CHECK(pNode == &nodeU);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 4);
			CHECK(pNode == &nodeT);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 5);
			CHECK(pNode == &nodeS);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 6);
			CHECK(pNode == &nodeP);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 7);
			CHECK(pNode == &nodeO);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 8);
			CHECK(pNode == &nodeR);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 9);
			CHECK(pNode == &nodeC);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 10);
			CHECK(pNode == &nodeN);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 11);
			CHECK(pNode == &nodeM);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 12);
			CHECK(pNode == &nodeL);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 13);
			CHECK(pNode == &nodeK);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 14);
			CHECK(pNode == &nodeB);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 15);
			CHECK(pNode == &nodeJ);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 16);
			CHECK(pNode == &nodeG);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 17);
			CHECK(pNode == &nodeI);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 18);
			CHECK(pNode == &nodeE);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 19);
			CHECK(pNode == &nodeH);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 20);
			CHECK(pNode == &nodeF);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 21);
			CHECK(pNode == &nodeD);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 22);
			CHECK(pNode == &nodeA);
			pNode = pRevIter.Next();
			count++;

			CHECK(count == 23);
			CHECK(pNode == &nodeRoot);
			pNode = pRevIter.Next();
			count++;

			CHECK(pRevIter.IsDone() == true);

		}
	}

	// Remove W
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeW);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_W[i]) == 0);
			}

		}
	}

	// Remove V
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeV);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				if(strcmp(pResult[i], pTestRev_Result_V[i]) != 0)
				{
					Trace::out("r:%s t:%s \n", pResult[i], pTestRev_Result_V[i]);
				}
				CHECK(strcmp(pResult[i], pTestRev_Result_V[i]) == 0);
			}
		}
	}

	// Remove U
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeU);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_U[i]) == 0);
			}
		}
	}

	// Remove T
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeT);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_T[i]) == 0);
			}
		}
	}

	// Remove S
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeS);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_S[i]) == 0);
			}
		}
	}

	// Remove P
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeP);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_P[i]) == 0);
			}
		}
	}

	// Remove Q
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeQ);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_Q[i]) == 0);
			}
		}
	}

	// Remove O
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeO);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_O[i]) == 0);
			}
		}
	}

	// Remove R
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeR);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_R[i]) == 0);
			}
		}
	}

	// Remove C
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeC);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_C[i]) == 0);
			}
		}
	}

	// Remove N
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeN);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_N[i]) == 0);
			}
		}
	}

	// Remove M
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeM);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_M[i]) == 0);
			}
		}
	}

	// Remove L
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeL);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_L[i]) == 0);
			}
		}
	}

	// Remove K
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeK);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_K[i]) == 0);
			}
		}
	}

	// Remove B
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeB);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_B[i]) == 0);
			}
		}
	}

	// Remove J
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeJ);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_J[i]) == 0);
			}
		}
	}

	// Remove G
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeG);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_G[i]) == 0);
			}
		}
	}

	// Remove I
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeI);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_I[i]) == 0);
			}
		}
	}

	// Remove E
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeE);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_E[i]) == 0);
			}
		}
	}

	// Remove A
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeA);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_A[i]) == 0);
			}
		}
	}

	// Remove H
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeH);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_H[i]) == 0);
			}
		}
	}

	// Remove F
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeF);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_F[i]) == 0);
			}
		}
	}

	// Remove D
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeD);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_D[i]) == 0);
			}
		}
	}

	// Remove ABC
	{{
			PCSTree::Info info;
			PCSTree tree;
			PCSNode *root;

			PCSNode nodeRoot("Root");
			PCSNode nodeA("Node_A");
			PCSNode nodeB("Node_B");
			PCSNode nodeC("Node_C");
			PCSNode nodeD("Node_D");
			PCSNode nodeE("Node_E");
			PCSNode nodeI("Node_I");
			PCSNode nodeK("Node_K");
			PCSNode nodeL("Node_L");
			PCSNode nodeR("Node_R");
			PCSNode nodeF("Node_F");
			PCSNode nodeG("Node_G");
			PCSNode nodeJ("Node_J");
			PCSNode nodeM("Node_M");
			PCSNode nodeN("Node_N");
			PCSNode nodeO("Node_O");
			PCSNode nodeP("Node_P");
			PCSNode nodeQ("Node_Q");
			PCSNode nodeH("Node_H");
			PCSNode nodeS("Node_S");
			PCSNode nodeT("Node_T");
			PCSNode nodeU("Node_U");
			PCSNode nodeV("Node_V");
			PCSNode nodeW("Node_W");

			root = tree.GetRoot();

			tree.Insert(&nodeRoot, root);
			tree.Insert(&nodeC, &nodeRoot);
			tree.Insert(&nodeB, &nodeRoot);
			tree.Insert(&nodeA, &nodeRoot);
			tree.Insert(&nodeI, &nodeA);
			tree.Insert(&nodeE, &nodeA);
			tree.Insert(&nodeD, &nodeA);
			tree.Insert(&nodeL, &nodeB);
			tree.Insert(&nodeK, &nodeB);
			tree.Insert(&nodeR, &nodeC);
			tree.Insert(&nodeF, &nodeD);
			tree.Insert(&nodeJ, &nodeI);
			tree.Insert(&nodeG, &nodeI);
			tree.Insert(&nodeN, &nodeL);
			tree.Insert(&nodeM, &nodeL);
			tree.Insert(&nodeQ, &nodeR);
			tree.Insert(&nodeP, &nodeR);
			tree.Insert(&nodeO, &nodeR);
			tree.Insert(&nodeH, &nodeF);
			tree.Insert(&nodeS, &nodeP);
			tree.Insert(&nodeW, &nodeS);
			tree.Insert(&nodeV, &nodeS);
			tree.Insert(&nodeU, &nodeS);
			tree.Insert(&nodeT, &nodeS);

			tree.GetInfo(info);
			CHECK(info.maxNumNodes == 24);
			CHECK(info.maxNumLevels == 6);
			CHECK(info.currNumLevels == 6);
			CHECK(info.currNumNodes == 24);

			char pResult[24][PCSNode::NAME_SIZE];

			for(int i = 0; i < 24; i++)
			{
				memset(pResult[i], 0, PCSNode::NAME_SIZE);
			}

			tree.Remove(&nodeC);
			tree.Remove(&nodeB);
			tree.Remove(&nodeA);

			PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
			int count = 0;

			for(pRevIterCount.First(); !pRevIterCount.IsDone(); pRevIterCount.Next())
			{
				//pRevIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pRevIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTestRev_Result_ABC[i]) == 0);
			}
		}
	}

#endif
} TEST_END

// --- End of File ---




