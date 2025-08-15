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

TEST(S_Set_T0, TestConfig::ALL)
{
#if S_Set_T0
	Rot A(Rot1::X, -0.45f);
	Scale S(2, 3, 4);
	Mat4 M = A * S;

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	h = S.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::RotScale);

	M.T();

	h = M.privGetHint();
	CHECK(h == Mat4::Hint::Generalize);

	h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);
	
	h = S.privGetHint();
	CHECK(h == Mat4::Hint::Scale);

#endif
} TEST_END

// ---  End of File ---------------
