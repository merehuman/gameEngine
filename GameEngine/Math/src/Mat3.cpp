//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	//----------------BIG 4--------------------
	Mat3::Mat3() :
		_m0(0.0f), _m1(0.0f), _m2(0.0f), _m3(0.0f),
		_m4(0.0f), _m5(0.0f), _m6(0.0f), _m7(0.0f),
		_m8(0.0f), _m9(0.0f), _m10(0.0f), _m11(0.0f),
		_m12(0.0f), _m13(0.0f), _m14(0.0f), _m15(0.0f) {};

	Mat3::Mat3(const Mat3& inM) :
		_m0(inM._m0), _m1(inM._m1), _m2(inM._m2), _m3(inM._m3),
		_m4(inM._m4), _m5(inM._m5), _m6(inM._m6), _m7(inM._m7),
		_m8(inM._m8), _m9(inM._m9), _m10(inM._m10), _m11(inM._m11),
		_m12(inM._m12), _m13(inM._m13), _m14(inM._m14), _m15(inM._m15) {};

	Mat3& Mat3::operator = (const Mat3& inM)
	{
		this->_m0 = inM._m0;
		this->_m1 = inM._m1;
		this->_m2 = inM._m2;
		this->_m3 = inM._m3;
		this->_m4 = inM._m4;
		this->_m5 = inM._m5;
		this->_m6 = inM._m6;
		this->_m7 = inM._m7;
		this->_m8 = inM._m8;
		this->_m9 = inM._m9;
		this->_m10 = inM._m10;
		this->_m11 = inM._m11;
		this->_m12 = inM._m12;
		this->_m13 = inM._m13;
		this->_m14 = inM._m14;
		this->_m15 = inM._m15;

		return *this;
	};

	Mat3::~Mat3() {};

	//----------------BIG 6------------------
	Mat3::Mat3(const Vec3& tV0, const Vec3& tV1, const Vec3& tV2) :
		_m0(tV0.x()), _m1(tV0.y()), _m2(tV0.z()), _m3(0.0f),
		_m4(tV1.x()), _m5(tV1.y()), _m6(tV1.z()), _m7(0.0f),
		_m8(tV2.x()), _m9(tV2.y()), _m10(tV2.z()), _m11(0.0f),
		_m12(0.0f), _m13(0.0f), _m14(0.0f), _m15(1.0f) {}

	Mat3::Mat3(const Mat4& m) :
		_m0(m._m0), _m1(m._m1), _m2(m._m2), _m3(0.0f),
		_m4(m._m4), _m5(m._m5), _m6(m._m6), _m7(0.0f),
		_m8(m._m8), _m9(m._m9), _m10(m._m10), _m11(0.0f),
		_m12(0.0f), _m13(0.0f), _m14(0.0f), _m15(1.0f) {}

	Mat3::Mat3(const Identity_enum type) :
		_m0(0.0f), _m1(0.0f), _m2(0.0f), _m3(0.0f),
		_m4(0.0f), _m5(0.0f), _m6(0.0f), _m7(0.0f),
		_m8(0.0f), _m9(0.0f), _m10(0.0f), _m11(0.0f),
		_m12(0.0f), _m13(0.0f), _m14(0.0f), _m15(0.0f)
	{
		switch (type)
		{
		case Identity_enum::Identity:
			_m0 = 1.0f;
			_m1 = 0.0f;
			_m2 = 0.0f;
			_m3 = 0.0f;
			_m4 = 0.0f;
			_m5 = 1.0f;
			_m6 = 0.0f;
			_m8 = 0.0f;
			_m9 = 0.0f;
			_m10 = 1.0f;
			_m11 = 0.0f;
			_m12 = 0.0f;
			_m13 = 0.0f;
			_m14 = 0.0f;
			_m15 = 1.0f;

			break;
		default:
			assert(0);
			break;
		}
	}

	//-----------------GETTERS-----------------
	Vec3 Mat3::get(const Row3 row) const
	{
		if (row == Row3::i0)
		{
			return Vec3(_m0, _m1, _m2);
		}
		else if (row == Row3::i1)
		{
			return Vec3(_m4, _m5, _m6);
		}
		else if (row == Row3::i2)
		{
			return Vec3(_m8, _m9, _m10);
		}
		else
		{
			assert(0);
			return Vec3();
		}
	}

	//-----------------SETTERS-----------------
	void Mat3::set(const Mat3& mIn)
	{
		this->_m0 = mIn._m0;
		this->_m1 = mIn._m1;
		this->_m2 = mIn._m2;
		this->_m3 = mIn._m3;
		this->_m4 = mIn._m4;
		this->_m5 = mIn._m5;
		this->_m6 = mIn._m6;
		this->_m7 = mIn._m7;
		this->_m8 = mIn._m8;
		this->_m9 = mIn._m9;
		this->_m10 = mIn._m10;
		this->_m11 = mIn._m11;
		this->_m12 = mIn._m12;
		this->_m13 = mIn._m13;
		this->_m14 = mIn._m14;
		this->_m15 = mIn._m15;
	}

	void Mat3::set(const Identity_enum type)
	{
		switch (type)
		{
		case Identity_enum::Identity:
			_m0 = 1.0f;
			_m1 = 0.0f;
			_m2 = 0.0f;
			_m3 = 0.0f;
			_m4 = 0.0f;
			_m5 = 1.0f;
			_m6 = 0.0f;
			_m8 = 0.0f;
			_m9 = 0.0f;
			_m10 = 1.0f;
			_m11 = 0.0f;
			_m12 = 0.0f;
			_m13 = 0.0f;
			_m14 = 0.0f;
			_m15 = 1.0f;
			break;
		default:
			assert(0);
			break;
		}
	}

	void Mat3::set(const Row3 type, const Vec3& V)
	{
		if (type == Row3::i0)
		{
			_m0 = V.x();
			_m1 = V.y();
			_m2 = V.z();
		}
		else if (type == Row3::i1)
		{
			_m4 = V.x();
			_m5 = V.y();
			_m6 = V.z();
		}
		else if (type == Row3::i2)
		{
			_m8 = V.x();
			_m9 = V.y();
			_m10 = V.z();
		}
		else
		{
			assert(0);
		}
	}

	void Mat3::set(const Vec3& tV0, const Vec3& tV1, const Vec3& tV2)
	{
		_m0 = tV0.x();
		_m1 = tV0.y();
		_m2 = tV0.z();
		_m3 = 0.0f;
		_m4 = tV1.x();
		_m5 = tV1.y();
		_m6 = tV1.z();
		_m7 = 0.0f;
		_m8 = tV2.x();
		_m9 = tV2.y();
		_m10 = tV2.z();
		_m11 = 0.0f;
		_m12 = 0.0f;
		_m13 = 0.0f;
		_m14 = 0.0f;
		_m15 = 1.0f;
	}

	//-----------------BRACKET OPERATORS-----------------
	float& Mat3::operator[] (const m0_enum) { return this->_m0; }
	float& Mat3::operator[] (const m1_enum) { return this->_m1; }
	float& Mat3::operator[] (const m2_enum) { return this->_m2; }

	float& Mat3::operator[] (const m4_enum) { return this->_m4; }
	float& Mat3::operator[] (const m5_enum) { return this->_m5; }
	float& Mat3::operator[] (const m6_enum) { return this->_m6; }

	float& Mat3::operator[] (const m8_enum) { return this->_m8; }
	float& Mat3::operator[] (const m9_enum) { return this->_m9; }
	float& Mat3::operator[] (const m10_enum) { return this->_m10; }

	float Mat3::operator[] (const m0_enum) const { return this->_m0; }
	float Mat3::operator[] (const m1_enum) const { return this->_m1; }
	float Mat3::operator[] (const m2_enum) const { return this->_m2; }

	float Mat3::operator[] (const m4_enum) const { return this->_m4; }
	float Mat3::operator[] (const m5_enum) const { return this->_m5; }
	float Mat3::operator[] (const m6_enum) const { return this->_m6; }

	float Mat3::operator[] (const m8_enum) const { return this->_m8; }
	float Mat3::operator[] (const m9_enum) const { return this->_m9; }
	float Mat3::operator[] (const m10_enum) const { return this->_m10; }

	//-----------------ACCESSORS-----------------
	void Mat3::m0(const float val) { this->_m0 = val; }
	void Mat3::m1(const float val) { this->_m1 = val; }
	void Mat3::m2(const float val) { this->_m2 = val; }

	void Mat3::m4(const float val) { this->_m4 = val; }
	void Mat3::m5(const float val) { this->_m5 = val; }
	void Mat3::m6(const float val) { this->_m6 = val; }

	void Mat3::m8(const float val) { this->_m8 = val; }
	void Mat3::m9(const float val) { this->_m9 = val; }
	void Mat3::m10(const float val) { this->_m10 = val; }

	float Mat3::m0() const { return this->_m0; }
	float Mat3::m1() const { return this->_m1; }
	float Mat3::m2() const { return this->_m2; }

	float Mat3::m4() const { return this->_m4; }
	float Mat3::m5() const { return this->_m5; }
	float Mat3::m6() const { return this->_m6; }

	float Mat3::m8() const { return this->_m8; }
	float Mat3::m9() const { return this->_m9; }
	float Mat3::m10() const { return this->_m10; }

	//-----------------DETERMINANT-----------------
	float Mat3::det() const
	{
		return
			_m0 * (_m5 * _m10 - _m6 * _m9) -
			_m1 * (_m4 * _m10 - _m6 * _m8) +
			_m2 * (_m4 * _m9 - _m5 * _m8);
	}

	//-----------------TRANSPOSE-----------------
	Mat3& Mat3::T(void)
	{
		float tmp = _m1;
		_m1 = _m4;
		_m4 = tmp;

		tmp = _m2;
		_m2 = _m8;
		_m8 = tmp;

		tmp = _m6;
		_m6 = _m9;
		_m9 = tmp;

		return *this;
	}

	Mat3 Mat3::getT(void) const
	{
		Mat3 tmp(*this);
		return tmp.T();
	}

	//-----------------INVERSE-----------------
	Mat3& Mat3::inv(void)
	{
		float det = this->det();
		assert(fabs(det) > MATH_TOLERANCE);

		float invDet = 1.0f / det;

		float tmp0 = _m5 * _m10 - _m6 * _m9;
		float tmp1 = -(_m4 * _m10 - _m6 * _m8);
		float tmp2 = _m4 * _m9 - _m5 * _m8;

		float tmp4 = -(_m1 * _m10 - _m2 * _m9);
		float tmp5 = _m0 * _m10 - _m2 * _m8;
		float tmp6 = -(_m0 * _m9 - _m1 * _m8);

		float tmp8 = _m1 * _m6 - _m2 * _m5;
		float tmp9 = -(_m0 * _m6 - _m2 * _m4);
		float tmp10 = _m0 * _m5 - _m1 * _m4;

		_m0 = tmp0 * invDet;
		_m1 = tmp4 * invDet;
		_m2 = tmp8 * invDet;

		_m4 = tmp1 * invDet;
		_m5 = tmp5 * invDet;
		_m6 = tmp9 * invDet;

		_m8 = tmp2 * invDet;
		_m9 = tmp6 * invDet;
		_m10 = tmp10 * invDet;

		return *this;

	}

	Mat3 Mat3::getInv(void) const
	{
		Mat3 tmp(*this);
		return tmp.inv();
	}

	//-----------------COMPARISON-----------------
	bool Mat3::isEqual(const Mat3& inM, const float epsilon) const
	{
		bool isEqual = true;

		if (fabs(this->_m0 - inM._m0) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m1 - inM._m1) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m2 - inM._m2) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m4 - inM._m4) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m5 - inM._m5) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m6 - inM._m6) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m8 - inM._m8) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m9 - inM._m9) > epsilon)
		{
			isEqual = false;
		}
		if (fabs(this->_m10 - inM._m10) > epsilon)
		{
			isEqual = false;
		}

		return isEqual;
	}

	bool Mat3::isIdentity(const float epsilon) const
	{
		bool isIdentity = true;

		if (fabs(this->_m0 - 1.0f) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m1) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m2) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m4) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m5 - 1.0f) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m6) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m8) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m9) > epsilon)
		{
			isIdentity = false;
		}
		if (fabs(this->_m10 - 1.0f) > epsilon)
		{
			isIdentity = false;
		}

		return isIdentity;
	}

	//-----------------ADD OPERATORS-----------------
	Mat3 Mat3::operator + (void) const
	{
		return *this;
	}

	Mat3 Mat3::operator + (const Mat3& A) const
	{
		return Mat3(
			Vec3(this->_m0 + A._m0, this->_m1 + A._m1, this->_m2 + A._m2),
			Vec3(this->_m4 + A._m4, this->_m5 + A._m5, this->_m6 + A._m6),
			Vec3(this->_m8 + A._m8, this->_m9 + A._m9, this->_m10 + A._m10));
	}

	Mat3& Mat3::operator += (const Mat3& A)
	{
		this->_m0 += A._m0;
		this->_m1 += A._m1;
		this->_m2 += A._m2;
		this->_m4 += A._m4;
		this->_m5 += A._m5;
		this->_m6 += A._m6;
		this->_m8 += A._m8;
		this->_m9 += A._m9;
		this->_m10 += A._m10;

		return *this;
	}

	//-----------------SUBTRACT OPERATORS-----------------
	Mat3 Mat3::operator - (void) const
	{
		return Mat3(
			Vec3(-this->_m0, -this->_m1, -this->_m2),
			Vec3(-this->_m4, -this->_m5, -this->_m6),
			Vec3(-this->_m8, -this->_m9, -this->_m10));
	}

	Mat3 Mat3::operator - (const Mat3& A) const
	{
		return Mat3(
			Vec3(this->_m0 - A._m0, this->_m1 - A._m1, this->_m2 - A._m2),
			Vec3(this->_m4 - A._m4, this->_m5 - A._m5, this->_m6 - A._m6),
			Vec3(this->_m8 - A._m8, this->_m9 - A._m9, this->_m10 - A._m10));
	}

	Mat3& Mat3::operator -= (const Mat3& A)
	{
		this->_m0 -= A._m0;
		this->_m1 -= A._m1;
		this->_m2 -= A._m2;
		this->_m4 -= A._m4;
		this->_m5 -= A._m5;
		this->_m6 -= A._m6;
		this->_m8 -= A._m8;
		this->_m9 -= A._m9;
		this->_m10 -= A._m10;

		return *this;
	}

	//-----------------SCALE OPERATORS-----------------
	Mat3 Mat3::operator * (const float s) const
	{
		return Mat3(
			Vec3(this->_m0 * s, this->_m1 * s, this->_m2 * s),
			Vec3(this->_m4 * s, this->_m5 * s, this->_m6 * s),
			Vec3(this->_m8 * s, this->_m9 * s, this->_m10 * s));
	}

	Mat3 operator *(const float scale, const Mat3& A)
	{
		return A * scale;
	}


	Mat3& Mat3::operator *= (const float s)
	{
		this->_m0 *= s;
		this->_m1 *= s;
		this->_m2 *= s;
		this->_m4 *= s;
		this->_m5 *= s;
		this->_m6 *= s;
		this->_m8 *= s;
		this->_m9 *= s;
		this->_m10 *= s;

		return *this;
	}

	//-----------------MATRIX MULTIPLICATION-----------------
	Mat3 Mat3::operator * (const Mat3& A) const
	{
		return Mat3(
			Vec3(
				this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8,
				this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9,
				this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10),
			Vec3(
				this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8,
				this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9,
				this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10),
			Vec3(
				this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8,
				this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9,
				this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10));
	}

	Mat3& Mat3::operator *= (const Mat3& A)
	{
		Mat3 tmp(*this);

		this->_m0 = tmp._m0 * A._m0 + tmp._m1 * A._m4 + tmp._m2 * A._m8;
		this->_m1 = tmp._m0 * A._m1 + tmp._m1 * A._m5 + tmp._m2 * A._m9;
		this->_m2 = tmp._m0 * A._m2 + tmp._m1 * A._m6 + tmp._m2 * A._m10;

		this->_m4 = tmp._m4 * A._m0 + tmp._m5 * A._m4 + tmp._m6 * A._m8;
		this->_m5 = tmp._m4 * A._m1 + tmp._m5 * A._m5 + tmp._m6 * A._m9;
		this->_m6 = tmp._m4 * A._m2 + tmp._m5 * A._m6 + tmp._m6 * A._m10;

		this->_m8 = tmp._m8 * A._m0 + tmp._m9 * A._m4 + tmp._m10 * A._m8;
		this->_m9 = tmp._m8 * A._m1 + tmp._m9 * A._m5 + tmp._m10 * A._m9;
		this->_m10 = tmp._m8 * A._m2 + tmp._m9 * A._m6 + tmp._m10 * A._m10;

		return *this;
	}

	//-----------------PRINTING-----------------
	void Mat3::Print(const char* pName) const
	{
		Trace::out("%s: \n", pName);
		Trace::out("| %f %f %f |\n", this->_m0, this->_m1, this->_m2);
		Trace::out("| %f %f %f |\n", this->_m4, this->_m5, this->_m6);
		Trace::out("| %f %f %f |\n", this->_m8, this->_m9, this->_m10);
		Trace::out("\n");
	}


}

// ---  End of File ---
