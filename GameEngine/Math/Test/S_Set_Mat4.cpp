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

TEST(S_Set_Mat4, TestConfig::ALL)
{
#if S_Set_Mat4

	Rot A(Rot1::X, -0.45f);
	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	Scale B(2,3,4);
	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	Mat4 &AA = A;
	Mat4 &BB = B;

	h = AA.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	h = BB.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	AA.set(BB);

	h = AA.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = BB.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = B.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = A.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
