//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(S_Set_Inv_TransScale, TestConfig::ALL)
{
#if S_Set_Inv_TransScale

	Scale A(2,3,4);
	Trans B(3,4,5);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	M = A * B;

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::TransScale);

	Mat4 N(M);

	h = N.privGetHint();
	CHECK(h == Mat4::Hint::TransScale);

	M.inv();

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::TransScale);

	Mat4 L = N * M;

	const bool flag = L.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = L.privGetHint();
	CHECK(h == Mat4::Hint::TransScale);

#endif
} TEST_END

// ---  End of File ---------------
