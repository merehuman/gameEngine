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

TEST(S_Set_Row1, TestConfig::ALL)
{
#if S_Set_Row1
	Rot A(Rot1::X, -0.45f);

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	Vec4 v1(1, 2, 3, 4);

	Mat4 &B = A;

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	B.set(Row4::i1, v1);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	h = A.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

#endif
} TEST_END

// ---  End of File ---------------
