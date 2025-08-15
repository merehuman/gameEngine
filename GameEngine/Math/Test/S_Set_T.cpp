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

TEST(S_Set_T, TestConfig::ALL)
{
#if S_Set_T
	Rot A(Rot1::X, -0.45f);

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	Mat4 &B = A;

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	B.T();

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

#endif
} TEST_END

// ---  End of File ---------------
