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

TEST(S_Set_Inv_Rot, TestConfig::ALL)
{
#if S_Set_Inv_Rot

	Rot A(Rot1::X,0.45f);
	Mat4 B(A);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	B.inv();

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

#endif
} TEST_END

// ---  End of File ---------------
