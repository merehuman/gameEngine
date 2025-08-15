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

TEST(S6_Hint_bracket_M6, TestConfig::ALL)
{
#if S6_Hint_bracket_M6
	Rot A(Rot1::X, -0.45f);

	Mat4::Hint h = A.privGetHint();
	CHECK(h == Mat4::Hint::Rot);

	A[m6] = 11.0f;

	h = A.privGetHint();

	CHECK(h == Mat4::Hint::Generalize);
	
#endif
} TEST_END

// ---  End of File ---------------
