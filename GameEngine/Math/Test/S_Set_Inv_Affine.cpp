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

TEST(S_Set_Inv_Affine, TestConfig::ALL)
{
#if S_Set_Inv_Affine

	Scale A(2,3,4);
	Trans B(3,4,5);
	Rot   C(Rot1::Y, 0.33f);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	h = C.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	M = A * B * C;

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Affine);

	Mat4 N(M);

	h = N.privGetHint();
	CHECK(h == Mat4::Hint::Affine);

	M.inv();

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Affine);

	Mat4 L = N * M;

	const bool flag = L.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = L.privGetHint();
	CHECK(h == Mat4::Hint::Affine);

#endif
} TEST_END

// ---  End of File ---------------
