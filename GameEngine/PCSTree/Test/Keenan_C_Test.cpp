//----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Modifying any Unit Test to alter the outcome results 
//       is also an Academic Integrity Violation       
//---------------------------------------------------------------------------
// Stubbed out


char pTest_ResultComplete[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_W[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_Q"
};

char pTest_Result_V[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_W",
"Node_Q"
};

char pTest_Result_U[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_T[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_S[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_Q"
};

char pTest_Result_P[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_Q"
};

char pTest_Result_Q[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W"
};

char pTest_Result_O[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_R[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C"
};

char pTest_Result_C[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N"
};

char pTest_Result_N[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_M[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_L[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_K[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_B[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_J[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_G",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_G[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_I",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_I[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_E",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_E[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_H",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_A[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_H[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_F",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_F[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_D",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_D[24][PCSNode::NAME_SIZE]
{
"Root",
"Node_A",
"Node_E",
"Node_I",
"Node_G",
"Node_J",
"Node_B",
"Node_K",
"Node_L",
"Node_M",
"Node_N",
"Node_C",
"Node_R",
"Node_O",
"Node_P",
"Node_S",
"Node_T",
"Node_U",
"Node_V",
"Node_W",
"Node_Q"
};

char pTest_Result_ABC[24][PCSNode::NAME_SIZE]
{
"Root"
};

TEST(Keenan_C_Enable, TestConfig::ALL)
{
#if Keenan_C_Enable

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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			CHECK(count == 24);

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_ResultComplete[i]) == 0);
			}

			count = 0;
			PCSTreeForwardIterator pForIter(tree.GetRoot());
			PCSNode *pNode = pForIter.First();

			CHECK(count == 0);
			CHECK(pNode == &nodeRoot);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 1);
			CHECK(pNode == &nodeA);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 2);
			CHECK(pNode == &nodeD);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 3);
			CHECK(pNode == &nodeF);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 4);
			CHECK(pNode == &nodeH);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 5);
			CHECK(pNode == &nodeE);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 6);
			CHECK(pNode == &nodeI);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 7);
			CHECK(pNode == &nodeG);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 8);
			CHECK(pNode == &nodeJ);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 9);
			CHECK(pNode == &nodeB);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 10);
			CHECK(pNode == &nodeK);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 11);
			CHECK(pNode == &nodeL);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 12);
			CHECK(pNode == &nodeM);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 13);
			CHECK(pNode == &nodeN);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 14);
			CHECK(pNode == &nodeC);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 15);
			CHECK(pNode == &nodeR);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 16);
			CHECK(pNode == &nodeO);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 17);
			CHECK(pNode == &nodeP);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 18);
			CHECK(pNode == &nodeS);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 19);
			CHECK(pNode == &nodeT);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 20);
			CHECK(pNode == &nodeU);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 21);
			CHECK(pNode == &nodeV);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 22);
			CHECK(pNode == &nodeW);
			pNode = pForIter.Next();
			count++;

			CHECK(count == 23);
			CHECK(pNode == &nodeQ);
			pNode = pForIter.Next();
			count++;

			CHECK(pForIter.IsDone() == true);

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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_W[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				if(strcmp(pResult[i], pTest_Result_V[i]) != 0)
				{
					Trace::out("r:%s t:%s \n", pResult[i], pTest_Result_V[i]);
				}
				CHECK(strcmp(pResult[i], pTest_Result_V[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_U[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_T[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_S[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_P[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_Q[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_O[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_R[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_C[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_N[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_M[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_L[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_K[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_B[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_J[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_G[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_I[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_E[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_A[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_H[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_F[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_D[i]) == 0);
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

			PCSTreeForwardIterator pForIterCount(tree.GetRoot());
			int count = 0;

			for(pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
			{
				//pForIterCount.Current()->PrintNode();

				char buff[PCSNode::NAME_SIZE]{0};
				pForIterCount.Current()->GetName(buff, PCSNode::NAME_SIZE);

				memcpy_s(pResult[count],
						 PCSNode::NAME_SIZE,
						 buff,
						 PCSNode::NAME_SIZE);

				count++;
			}

			for(int i = 0; i < 24; i++)
			{
				CHECK(strcmp(pResult[i], pTest_Result_ABC[i]) == 0);
			}
		}
	}


#endif
} TEST_END

// --- End of File ---





