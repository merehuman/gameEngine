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

TEST(S_Set_Inv_General, TestConfig::ALL)
{
#if S_Set_Inv_General

	Mat4 A(Vec4(1,2,3,4), Vec4(2,1,5,4), Vec4(9,-2,2,3), Vec4(3,3,3,1));
	Mat4 B(A);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	B.inv();

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
