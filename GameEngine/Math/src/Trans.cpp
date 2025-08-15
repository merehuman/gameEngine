//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	Trans::Trans()
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;

		this->privSetTransHint();
	};

	Trans::Trans(const float tx, const float ty, const float tz)
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m12 = tx;
		this->_m13 = ty;
		this->_m14 = tz;
		this->_m15 = 1.0f;

		this->privSetTransHint();
	}
	Trans::Trans(const Vec3& vTrans)
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m12 = vTrans.x();
		this->_m13 = vTrans.y();
		this->_m14 = vTrans.z();
		this->_m15 = 1.0f;

		this->privSetTransHint();
	}

	// Set 
	void Trans::set(const float tx, const float ty, const float tz)
	{
		this->_m12 = tx;
		this->_m13 = ty;
		this->_m14 = tz;

		this->privSetTransHint();
	}
	void Trans::set(const Vec3& vTrans)
	{
		this->_m12 = vTrans.x();
		this->_m13 = vTrans.y();
		this->_m14 = vTrans.z();

		this->privSetTransHint();
	}

	//MULTIPLY OVERLOADS
	Mat4 Trans::operator * (const Mat4& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp(A);

		temp._m0 = A._m0;
		temp._m1 = A._m1;
		temp._m2 = A._m2;
		temp._m3 = A._m3;

		temp._m4 = A._m4;
		temp._m5 = A._m5;
		temp._m6 = A._m6;
		temp._m7 = A._m7;

		temp._m8 = A._m8;
		temp._m9 = A._m9;
		temp._m10 = A._m10;
		temp._m11 = A._m11;

		temp._m12 = A._m0 * this->_m12 + A._m4 * this->_m13 + A._m8 * this->_m14 + A._m12;
		temp._m13 = A._m1 * this->_m12 + A._m5 * this->_m13 + A._m9 * this->_m14 + A._m13;
		temp._m14 = A._m2 * this->_m12 + A._m6 * this->_m13 + A._m10 * this->_m14 + A._m14;
		temp._m15 = A._m3 * this->_m12 + A._m7 * this->_m13 + A._m11 * this->_m14 + A._m15;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}

	Mat4 Trans::operator * (const Quat& q) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = Hint::Rot;

		Mat4 temp;

		float x = q._qx;
		float y = q._qy;
		float z = q._qz;
		float w = q._qw;

		temp._m0 = 1.0f - 2.0f * (y * y + z * z);
		temp._m1 = 2.0f * (x * y + w * z);
		temp._m2 = 2.0f * (x * z - w * y);
		temp._m3 = 0.0f;

		temp._m4 = 2.0f * (x * y - w * z);
		temp._m5 = 1.0f - 2.0f * (x * x + z * z);
		temp._m6 = 2.0f * (y * z + w * x);
		temp._m7 = 0.0f;

		temp._m8 = 2.0f * (x * z + w * y);
		temp._m9 = 2.0f * (y * z - w * x);
		temp._m10 = 1.0f - 2.0f * (x * x + y * y);
		temp._m11 = 0.0f;

		temp._m12 = this->_m12 * temp._m0 + this->_m13 * temp._m4 + this->_m14 * temp._m8;
		temp._m13 = this->_m12 * temp._m1 + this->_m13 * temp._m5 + this->_m14 * temp._m9;
		temp._m14 = this->_m12 * temp._m2 + this->_m13 * temp._m6 + this->_m14 * temp._m10;
		temp._m15 = 1.0f;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}


	Mat4 Trans::operator * (const Scale& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp;

		temp._m0 = this->_m0 * A._m0;
		temp._m1 = this->_m1 * A._m5;
		temp._m2 = this->_m2 * A._m10;
		temp._m3 = this->_m3;

		temp._m4 = this->_m4 * A._m0;
		temp._m5 = this->_m5 * A._m5;
		temp._m6 = this->_m6 * A._m10;
		temp._m7 = this->_m7;

		temp._m8 = this->_m8 * A._m0;
		temp._m9 = this->_m9 * A._m5;
		temp._m10 = this->_m10 * A._m10;
		temp._m11 = this->_m11;

		temp._m12 = this->_m12 * A._m0;
		temp._m13 = this->_m13 * A._m5;
		temp._m14 = this->_m14 * A._m10;
		temp._m15 = this->_m15;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}
	Mat4 Trans::operator * (const Rot& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp;

		temp._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8;
		temp._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9;
		temp._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10;
		temp._m3 = 0.0f;

		temp._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8;
		temp._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9;
		temp._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10;
		temp._m7 = 0.0f;

		temp._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8;
		temp._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9;
		temp._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10;
		temp._m11 = 0.0f;

		temp._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8;
		temp._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9;
		temp._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10;
		temp._m15 = 1.0f;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}
	Trans Trans::operator * (const Trans& A) const
	{
		Trans temp(*this);

		temp._m12 = this->_m12 + A._m12;
		temp._m13 = this->_m13 + A._m13;
		temp._m14 = this->_m14 + A._m14;

		return temp;
	}
	Trans& Trans::operator *= (const Trans& A)
	{
		*this = *this * A;

		this->privSetTransHint();

		return *this;
	}



}

// ---  End of File ---
