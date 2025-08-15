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

TEST(S_Set_Inv_Trans, TestConfig::ALL)
{
#if S_Set_Inv_Trans

	Trans A(2,3,4);
	Trans B(A);
	Mat4 M;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	B.inv();

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

	M = A * B;

	const bool flag = M.isIdentity(MATH_TOLERANCE);
	CHECK(flag == true);

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Trans);

#endif
} TEST_END

// ---  End of File ---------------
