//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
#include "Mat4Test.h"

using namespace Azul;

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

TEST(SpeedTestH, TestConfig::ALL)
{
#if SpeedTestH

	Mat4 A;
	Mat4 A0;
	Mat4 B;
	Mat4 B2;
	Mat4 C;

	A.set(Vec4(5, 2, 6, 2),
		Vec4(6, 2, 6, 3),
		Vec4(6, 2, 1, 6),
		Vec4(8, 5, 8, 7));

	Mat4 *pA = &A;
	Mat4 *pB = &B;

	Mat4Test *pA2 = (Mat4Test *)&A;
	Mat4Test *pB2 = (Mat4Test *)&B2;

	PerformanceTimer tA0;
	PerformanceTimer tA1;
	PerformanceTimer tA2;
	PerformanceTimer tB;

	tA0.Tic();
	for(int i = 0; i < 1000000; i++)
	{
		*pB = pA->getInv();
	}
	tA0.Toc();

	tA1.Tic();
	for(int i = 0; i < 1000000; i++)
	{
		*pB = pA->getInv();
	}
	tA1.Toc();

	tA2.Tic();
	for(int i = 0; i < 1000000; i++)
	{
		*pB = pA->getInv();
	}
	tA2.Toc();

	tB.Tic();
	for (int i = 0; i < 1000000; i++)
	{
		*pB2 = pA2->getInv2();
	}
	tB.Toc();

	Trace::out("4x4 Mat4 -> M = M; \n");

	float ratio0 = (float)tB.TimeInSeconds() / (float)tA0.TimeInSeconds();
	float ratio1 = (float)tB.TimeInSeconds() / (float)tA1.TimeInSeconds();
	float ratio2 = (float)tB.TimeInSeconds() / (float)tA2.TimeInSeconds();

	float ratio = ratio0;
	if(ratio1 > ratio0)
	{
		ratio = ratio1;
	}

	if(ratio2 > ratio)
	{
		ratio = ratio2;
	}

	Trace::out2("   ratio: %f <-- %f %f %f\n", ratio, ratio0, ratio1, ratio2);


	C = A * B;

	CHECK(true == C.isIdentity());

	C = A * B2;

	CHECK(true == C.isIdentity());

#if _DEBUG
	CHECK(ratio > 0.75f);
#else
	CHECK(ratio > 0.80f);
#endif

#endif
} TEST_END

// ---  End of File ---
