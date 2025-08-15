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

TEST(S_Set_Inv_RotTrans, TestConfig::ALL)
{
#if S_Set_Inv_RotTrans

	Trans A(2,3,4);
	Rot B(Rot1::Z,0.33f);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	M = A * B;

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::RotTrans);

	Mat4 N(M);

	h = N.privGetHint();
	CHECK(h == Mat4::Hint::RotTrans);

	M.inv();

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::RotTrans);

	Mat4 L = N * M;

	const bool flag = L.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = L.privGetHint();
	CHECK(h == Mat4::Hint::RotTrans);

#endif
} TEST_END

// ---  End of File ---------------
