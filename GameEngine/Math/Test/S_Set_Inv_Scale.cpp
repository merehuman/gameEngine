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

TEST(S_Set_Inv_Scale, TestConfig::ALL)
{
#if S_Set_Inv_Scale

	Scale A(2,3,4);
	Scale B(A);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	B.inv();

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	M = A * B;

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
