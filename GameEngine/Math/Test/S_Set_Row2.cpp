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

TEST(S_Set_Row2, TestConfig::ALL)
{
#if S_Set_Row2
	Rot A(Rot1::X, -0.45f);

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	Vec4 v2(1, 2, 3, 4);

	Mat4 &B = A;

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	B.set(Row4::i2, v2);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	h = A.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
