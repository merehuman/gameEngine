//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	Scale::Scale()
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m15 = 1.0f;

		this->privSetScaleHint();
	}

	Scale::Scale(const float sx, const float sy, const float sz)
	{
		this->_m0 = sx;
		this->_m5 = sy;
		this->_m10 = sz;
		this->_m15 = 1.0f;

		this->privSetScaleHint();
	}
	Scale::Scale(const Vec3& vScale)
	{
		this->_m0 = vScale.x();
		this->_m5 = vScale.y();
		this->_m10 = vScale.z();
		this->_m15 = 1.0f;

		this->privSetScaleHint();
	}


	void Scale::set(const float sx, const float sy, const float sz)
	{
		this->_m0 = sx;
		this->_m5 = sy;
		this->_m10 = sz;
		this->_m15 = 1.0f;

		this->privSetScaleHint();
	}
	void Scale::set(const Vec3& vScale)
	{
		this->_m0 = vScale.x();
		this->_m5 = vScale.y();
		this->_m10 = vScale.z();
		this->_m15 = 1.0f;

		this->privSetScaleHint();
	}

	//MULTIPLY OVERLOADS
	Mat4 Scale::operator * (const Mat4& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp;

		temp._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8 + this->_m3 * A._m12;
		temp._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9 + this->_m3 * A._m13;
		temp._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10 + this->_m3 * A._m14;
		temp._m3 = this->_m0 * A._m3 + this->_m1 * A._m7 + this->_m2 * A._m11 + this->_m3 * A._m15;

		temp._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8 + this->_m7 * A._m12;
		temp._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9 + this->_m7 * A._m13;
		temp._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10 + this->_m7 * A._m14;
		temp._m7 = this->_m4 * A._m3 + this->_m5 * A._m7 + this->_m6 * A._m11 + this->_m7 * A._m15;

		temp._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8 + this->_m11 * A._m12;
		temp._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9 + this->_m11 * A._m13;
		temp._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10 + this->_m11 * A._m14;
		temp._m11 = this->_m8 * A._m3 + this->_m9 * A._m7 + this->_m10 * A._m11 + this->_m11 * A._m15;

		temp._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8 + this->_m15 * A._m12;
		temp._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9 + this->_m15 * A._m13;
		temp._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10 + this->_m15 * A._m14;
		temp._m15 = this->_m12 * A._m3 + this->_m13 * A._m7 + this->_m14 * A._m11 + this->_m15 * A._m15;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}

	Mat4 Scale::operator * (const Quat& q) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = Hint::Rot;

		Mat4 temp;

		temp._m0 = this->_m0 * (1.0f - 2.0f * q.qy() * q.qy() - 2.0f * q.qz() * q.qz());
		temp._m1 = this->_m0 * (2.0f * q.qx() * q.qy() + 2.0f * q.real() * q.qz());
		temp._m2 = this->_m0 * (2.0f * q.qx() * q.qz() - 2.0f * q.real () * q.qy());
		temp._m3 = 0.0f;

		temp._m4 = this->_m5 * (2.0f * q.qx() * q.qy() - 2.0f * q.real() * q.qz());
		temp._m5 = this->_m5 * (1.0f - 2.0f * q.qx() * q.qx() - 2.0f * q.qz() * q.qz());
		temp._m6 = this->_m5 * (2.0f * q.qy() * q.qz() + 2.0f * q.real() * q.qx());
		temp._m7 = 0.0f;

		temp._m8 = this->_m10 * (2.0f * q.qx() * q.qz() + 2.0f * q.real() * q.qy());
		temp._m9 = this->_m10 * (2.0f * q.qy() * q.qz() - 2.0f * q.real() * q.qx());
		temp._m10 = this->_m10 * (1.0f - 2.0f * q.qx() * q.qx() - 2.0f * q.qy() * q.qy());
		temp._m11 = 0.0f;

		temp._m12 = 0.0f;
		temp._m13 = 0.0f;
		temp._m14 = 0.0f;
		temp._m15 = 1.0f;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}


	Scale Scale::operator * (const Scale& A) const
	{
		Scale temp;

		temp._m0 = this->_m0 * A._m0;
		temp._m5 = this->_m5 * A._m5;
		temp._m10 = this->_m10 * A._m10;

		temp.privSetScaleHint();

		return temp;
	}
	Scale& Scale::operator *= (const Scale& A)
	{
		this->_m0 *= A._m0;
		this->_m5 *= A._m5;
		this->_m10 *= A._m10;

		this->privSetScaleHint();

		return *this;
	}

	Mat4 Scale::operator * (const Rot& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp;

		temp._m0 = this->_m0 * A._m0;
		temp._m1 = this->_m0 * A._m1;
		temp._m2 = this->_m0 * A._m2;
		temp._m3 = A._m3;

		temp._m4 = this->_m5 * A._m4;
		temp._m5 = this->_m5 * A._m5;
		temp._m6 = this->_m5 * A._m6;
		temp._m7 = A._m7;

		temp._m8 = this->_m10 * A._m8;
		temp._m9 = this->_m10 * A._m9;
		temp._m10 = this->_m10 * A._m10;
		temp._m11 = A._m11;

		temp._m12 = A._m12;
		temp._m13 = A._m13;
		temp._m14 = A._m14;
		temp._m15 = A._m15;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}
	Mat4 Scale::operator * (const Trans& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 temp;

		temp._m0 = this->_m0;
		temp._m1 = this->_m1;
		temp._m2 = this->_m2;
		temp._m3 = this->_m3;

		temp._m4 = this->_m4;
		temp._m5 = this->_m5;
		temp._m6 = this->_m6;
		temp._m7 = this->_m7;

		temp._m8 = this->_m8;
		temp._m9 = this->_m9;
		temp._m10 = this->_m10;
		temp._m11 = this->_m11;

		temp._m12 = this->_m12 + A._m12;
		temp._m13 = this->_m13 + A._m13;
		temp._m14 = this->_m14 + A._m14;
		temp._m15 = this->_m15;

		temp.privSetNewHint(hint, hintA);

		return temp;
	}

}

// ---  End of File ---
