//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

	//--------------------CONSTRUCTORS---------------------------------
	Mat4::Mat4() :
		_v0(0.0f, 0.0f, 0.0f, 0.0f),
		_v1(0.0f, 0.0f, 0.0f, 0.0f),
		_v2(0.0f, 0.0f, 0.0f, 0.0f),
		_v3(0.0f, 0.0f, 0.0f, 0.0f)
	{
		this->privSetGeneralHint();
	};

	Mat4& Mat4::operator = (const Mat4& A)
	{
		this->_m0 = A._m0;
		this->_m1 = A._m1;
		this->_m2 = A._m2;
		this->_m3 = A._m3;
		this->_m4 = A._m4;
		this->_m5 = A._m5;
		this->_m6 = A._m6;
		this->_m7 = A._m7;
		this->_m8 = A._m8;
		this->_m9 = A._m9;
		this->_m10 = A._m10;
		this->_m11 = A._m11;
		this->_m12 = A._m12;
		this->_m13 = A._m13;
		this->_m14 = A._m14;
		this->_m15 = A._m15;

		this->privSetGeneralHint();

		return *this;
	}

	Mat4::Mat4(const Mat4& tM) : _v0(tM._v0), _v1(tM._v1), _v2(tM._v2), _v3(tM._v3)
	{
		this->privSetCopyHint();
	}

	Mat4::~Mat4() {}

	Mat4& Mat4::operator = (const Quat& q)
	{
		float xx = q._qx * q._qx;
		float yy = q._qy * q._qy;
		float zz = q._qz * q._qz;
		float xy = q._qx * q._qy;
		float xz = q._qx * q._qz;
		float yz = q._qy * q._qz;
		float wx = q._qw * q._qx;
		float wy = q._qw * q._qy;
		float wz = q._qw * q._qz;

		this->_m0 = 1.0f - 2.0f * (yy + zz);
		this->_m1 = 2.0f * (xy + wz);
		this->_m2 = 2.0f * (xz - wy);
		this->_m3 = 0.0f;

		this->_m4 = 2.0f * (xy - wz);
		this->_m5 = 1.0f - 2.0f * (xx + zz);
		this->_m6 = 2.0f * (yz + wx);
		this->_m7 = 0.0f;

		this->_m8 = 2.0f * (xz + wy);
		this->_m9 = 2.0f * (yz - wx);
		this->_m10 = 1.0f - 2.0f * (xx + yy);
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;

		return *this;
	}


	Mat4::Mat4(const Vec4& tV0, const Vec4& tV1, const Vec4& tV2, const Vec4& tV3)
		:
		_v0(tV0), _v1(tV1), _v2(tV2), _v3(tV3)
	{
		this->privSetGeneralHint();
	}

	Mat4::Mat4(const Identity_enum type)
	{
		switch (type)
		{
		case Identity_enum::Identity:
			this->_m0 = 1.0f;
			this->_m1 = 0.0f;
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = 1.0f;
			this->_m6 = 0.0f;
			this->_m7 = 0.0f;
			this->_m8 = 0.0f;
			this->_m9 = 0.0f;
			this->_m10 = 1.0f;
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		default:
			break;
		}

		this->privSetRotHint();
	}

	Mat4::Mat4(const Quat& q)
	{
		float xx = q._qx * q._qx;
		float yy = q._qy * q._qy;
		float zz = q._qz * q._qz;
		float xy = q._qx * q._qy;
		float xz = q._qx * q._qz;
		float yz = q._qy * q._qz;
		float wx = q._qw * q._qx;
		float wy = q._qw * q._qy;
		float wz = q._qw * q._qz;

		this->_m0 = 1.0f - 2.0f * (yy + zz);
		this->_m1 = 2.0f * (xy + wz);
		this->_m2 = 2.0f * (xz - wy);
		this->_m3 = 0.0f;

		this->_m4 = 2.0f * (xy - wz);
		this->_m5 = 1.0f - 2.0f * (xx + zz);
		this->_m6 = 2.0f * (yz + wx);
		this->_m7 = 0.0f;

		this->_m8 = 2.0f * (xz + wy);
		this->_m9 = 2.0f * (yz - wx);
		this->_m10 = 1.0f - 2.0f * (xx + yy);
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}


	//--------------------SETTERS------------------------
	void Mat4::set(const Mat4& mIn)
	{
		this->_v0 = mIn._v0;
		this->_v1 = mIn._v1;
		this->_v2 = mIn._v2;
		this->_v3 = mIn._v3;

		this->privSetCopyHint();
	}

	void Mat4::set(const Vec4& V0, const Vec4& V1, const Vec4& V2, const Vec4& V3)
	{
		this->_v0 = V0;
		this->_v1 = V1;
		this->_v2 = V2;
		this->_v3 = V3;

		this->privSetCopyHint();
	}

	void Mat4::set(const Identity_enum type)
	{
		//Hint hint = this->privGetHint();
		//Hint newHint = Hint::Generalize;

		switch (type)
		{
		case Identity_enum::Identity:
			this->_m0 = 1.0f;
			this->_m1 = 0.0f;
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = 1.0f;
			this->_m6 = 0.0f;
			this->_m7 = 0.0f;
			this->_m8 = 0.0f;
			this->_m9 = 0.0f;
			this->_m10 = 1.0f;
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		default:
			break;
		}

		//this->privSetNewHint(hint, newHint);
		this->privSetRotHint();
	}

	void Mat4::set(const Row4 type, const Vec4& V)
	{
		switch (type)
		{
		case Row4::i0:
			this->_m0 = V.x();
			this->_m1 = V.y();
			this->_m2 = V.z();
			this->_m3 = V.w();
			break;
		case Row4::i1:
			this->_m4 = V.x();
			this->_m5 = V.y();
			this->_m6 = V.z();
			this->_m7 = V.w();
			break;
		case Row4::i2:
			this->_m8 = V.x();
			this->_m9 = V.y();
			this->_m10 = V.z();
			this->_m11 = V.w();
			break;
		case Row4::i3:
			this->_m12 = V.x();
			this->_m13 = V.y();
			this->_m14 = V.z();
			this->_m15 = V.w();
			break;
		}

		this->privSetGeneralHint();
	}

	void Mat4::set(const Quat& q)
	{
		float xx = q._qx * q._qx;
		float yy = q._qy * q._qy;
		float zz = q._qz * q._qz;
		float xy = q._qx * q._qy;
		float xz = q._qx * q._qz;
		float yz = q._qy * q._qz;
		float wx = q._qw * q._qx;
		float wy = q._qw * q._qy;
		float wz = q._qw * q._qz;

		this->_m0 = 1.0f - 2.0f * (yy + zz);
		this->_m1 = 2.0f * (xy + wz);
		this->_m2 = 2.0f * (xz - wy);
		this->_m3 = 0.0f;

		this->_m4 = 2.0f * (xy - wz);
		this->_m5 = 1.0f - 2.0f * (xx + zz);
		this->_m6 = 2.0f * (yz + wx);
		this->_m7 = 0.0f;

		this->_m8 = 2.0f * (xz + wy);
		this->_m9 = 2.0f * (yz - wx);
		this->_m10 = 1.0f - 2.0f * (xx + yy);
		this->_m11 = 0.0f;

		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}


	//--------------------GETTERS------------------------
	Vec4 Mat4::get(const Row4 type) const
	{
		Vec4 V;

		switch (type)
		{
		case Row4::i0:
			V.set(this->_m0, this->_m1, this->_m2, this->_m3);
			break;
		case Row4::i1:
			V.set(this->_m4, this->_m5, this->_m6, this->_m7);
			break;
		case Row4::i2:
			V.set(this->_m8, this->_m9, this->_m10, this->_m11);
			break;
		case Row4::i3:
			V.set(this->_m12, this->_m13, this->_m14, this->_m15);
			break;
		}

		return V;
	}

	//--------------------BRACKET OPERATORS------------------------
	Mat4Proxy Mat4::operator[](const m0_enum) { return Mat4Proxy(*this, this->_m0); }
	Mat4Proxy Mat4::operator[](const m1_enum) { return Mat4Proxy(*this, this->_m1); }
	Mat4Proxy Mat4::operator[](const m2_enum) { return Mat4Proxy(*this, this->_m2); }
	Mat4Proxy Mat4::operator[](const m3_enum) { return Mat4Proxy(*this, this->_m3); }
	Mat4Proxy Mat4::operator[](const m4_enum) { return Mat4Proxy(*this, this->_m4); }
	Mat4Proxy Mat4::operator[](const m5_enum) { return Mat4Proxy(*this, this->_m5); }
	Mat4Proxy Mat4::operator[](const m6_enum) { return Mat4Proxy(*this, this->_m6); }
	Mat4Proxy Mat4::operator[](const m7_enum) { return Mat4Proxy(*this, this->_m7); }
	Mat4Proxy Mat4::operator[](const m8_enum) { return Mat4Proxy(*this, this->_m8); }
	Mat4Proxy Mat4::operator[](const m9_enum) { return Mat4Proxy(*this, this->_m9); }
	Mat4Proxy Mat4::operator[](const m10_enum) { return Mat4Proxy(*this, this->_m10); }
	Mat4Proxy Mat4::operator[](const m11_enum) { return Mat4Proxy(*this, this->_m11); }
	Mat4Proxy Mat4::operator[](const m12_enum) { return Mat4Proxy(*this, this->_m12); }
	Mat4Proxy Mat4::operator[](const m13_enum) { return Mat4Proxy(*this, this->_m13); }
	Mat4Proxy Mat4::operator[](const m14_enum) { return Mat4Proxy(*this, this->_m14); }
	Mat4Proxy Mat4::operator[](const m15_enum) { return Mat4Proxy(*this, this->_m15); }

	float Mat4::operator[](const m0_enum) const { return this->_m0; }
	float Mat4::operator[](const m1_enum) const { return this->_m1; }
	float Mat4::operator[](const m2_enum) const { return this->_m2; }
	float Mat4::operator[](const m3_enum) const { return this->_m3; }
	float Mat4::operator[](const m4_enum) const { return this->_m4; }
	float Mat4::operator[](const m5_enum) const { return this->_m5; }
	float Mat4::operator[](const m6_enum) const { return this->_m6; }
	float Mat4::operator[](const m7_enum) const { return this->_m7; }
	float Mat4::operator[](const m8_enum) const { return this->_m8; }
	float Mat4::operator[](const m9_enum) const { return this->_m9; }
	float Mat4::operator[](const m10_enum) const { return this->_m10; }
	float Mat4::operator[](const m11_enum) const { return this->_m11; }
	float Mat4::operator[](const m12_enum) const { return this->_m12; }
	float Mat4::operator[](const m13_enum) const { return this->_m13; }
	float Mat4::operator[](const m14_enum) const { return this->_m14; }
	float Mat4::operator[](const m15_enum) const { return this->_m15; }

	//--------------------ACCESSORS------------------------
	void Mat4::m0(const float v) { this->_m0 = v; this->privSetGeneralHint(); }
	void Mat4::m1(const float v) { this->_m1 = v; this->privSetGeneralHint(); }
	void Mat4::m2(const float v) { this->_m2 = v; this->privSetGeneralHint(); }
	void Mat4::m3(const float v) { this->_m3 = v; this->privSetGeneralHint(); }
	void Mat4::m4(const float v) { this->_m4 = v; this->privSetGeneralHint(); }
	void Mat4::m5(const float v) { this->_m5 = v; this->privSetGeneralHint(); }
	void Mat4::m6(const float v) { this->_m6 = v; this->privSetGeneralHint(); }
	void Mat4::m7(const float v) { this->_m7 = v; this->privSetGeneralHint(); }
	void Mat4::m8(const float v) { this->_m8 = v; this->privSetGeneralHint(); }
	void Mat4::m9(const float v) { this->_m9 = v; this->privSetGeneralHint(); }
	void Mat4::m10(const float v) { this->_m10 = v; this->privSetGeneralHint(); }
	void Mat4::m11(const float v) { this->_m11 = v; this->privSetGeneralHint(); }
	void Mat4::m12(const float v) { this->_m12 = v; this->privSetGeneralHint(); }
	void Mat4::m13(const float v) { this->_m13 = v; this->privSetGeneralHint(); }
	void Mat4::m14(const float v) { this->_m14 = v; this->privSetGeneralHint(); }
	void Mat4::m15(const float v) { this->_m15 = v; this->privSetGeneralHint(); }

	float Mat4::m0() const { return this->_m0; }
	float Mat4::m1() const { return this->_m1; }
	float Mat4::m2() const { return this->_m2; }
	float Mat4::m3() const { return this->_m3; }
	float Mat4::m4() const { return this->_m4; }
	float Mat4::m5() const { return this->_m5; }
	float Mat4::m6() const { return this->_m6; }
	float Mat4::m7() const { return this->_m7; }
	float Mat4::m8() const { return this->_m8; }
	float Mat4::m9() const { return this->_m9; }
	float Mat4::m10() const { return this->_m10; }
	float Mat4::m11() const { return this->_m11; }
	float Mat4::m12() const { return this->_m12; }
	float Mat4::m13() const { return this->_m13; }
	float Mat4::m14() const { return this->_m14; }
	float Mat4::m15() const { return this->_m15; }

	//--------------------DETERMINANT------------------------
	float Mat4::det() const
	{
		return this->_m0 * (this->_m5 * (this->_m10 * this->_m15 - this->_m11 * this->_m14) - this->_m6 * (this->_m9 * this->_m15 - this->_m11 * this->_m13) + this->_m7 * (this->_m9 * this->_m14 - this->_m10 * this->_m13))
			- this->_m1 * (this->_m4 * (this->_m10 * this->_m15 - this->_m11 * this->_m14) - this->_m6 * (this->_m8 * this->_m15 - this->_m11 * this->_m12) + this->_m7 * (this->_m8 * this->_m14 - this->_m10 * this->_m12))
			+ this->_m2 * (this->_m4 * (this->_m9 * this->_m15 - this->_m11 * this->_m13) - this->_m5 * (this->_m8 * this->_m15 - this->_m11 * this->_m12) + this->_m7 * (this->_m8 * this->_m13 - this->_m9 * this->_m12))
			- this->_m3 * (this->_m4 * (this->_m9 * this->_m14 - this->_m10 * this->_m13) - this->_m5 * (this->_m8 * this->_m14 - this->_m10 * this->_m12) + this->_m6 * (this->_m8 * this->_m13 - this->_m9 * this->_m12));
	}

	//-------------------TRANSPOSE-------------------------
	Mat4& Mat4::T(void)
	{
		Hint hint = this->privGetHint();
		Hint newHint = Hint::Generalize;

		float temp;

		switch (hint)
		{
		case Hint::Rot:
			// Transpose only the rotational part (upper-left 3x3)

			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			newHint = Hint::Rot;
			break;

		case Hint::Scale:
			newHint = Hint::Scale;
			break;

		case Hint::RotScale:
			// Transpose the rotational part (upper-left 3x3)

			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			newHint = Hint::Generalize;
			break;

		case Hint::Affine:
			// Transpose the rotational part (upper-left 3x3)

			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			newHint = Hint::Affine;
			break;

		case Hint::RotTrans:
			// Transpose the rotational part (upper-left 3x3)

			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			newHint = Hint::RotTrans;
			break;

		case Hint::TransScale:
			// Transpose the rotational part (upper-left 3x3)

			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			newHint = Hint::TransScale;
			break;

		case Hint::Trans:
			newHint = Hint::Generalize;
			break;

		case Hint::Generalize:
			// Full 4x4 transpose
			temp = this->_m1;
			this->_m1 = this->_m4;
			this->_m4 = temp;

			temp = this->_m2;
			this->_m2 = this->_m8;
			this->_m8 = temp;

			temp = this->_m3;
			this->_m3 = this->_m12;
			this->_m12 = temp;

			temp = this->_m6;
			this->_m6 = this->_m9;
			this->_m9 = temp;

			temp = this->_m7;
			this->_m7 = this->_m13;
			this->_m13 = temp;

			temp = this->_m11;
			this->_m11 = this->_m14;
			this->_m14 = temp;

			newHint = Hint::Generalize;

			break;

		default:
			newHint = Hint::Generalize;
			break;
		}

		this->privSetNewHint(hint, newHint);

		return *this;
	}

	Mat4 Mat4::getT(void) const
	{
		Mat4 temp(*this);

		temp.T();

		temp.privSetCopyHint();

		return temp;
	}

	//--------------------INVERSE------------------------
	Mat4 Mat4::getInv(void) const
	{
		Mat4 temp(*this);

		temp.inv();

		return temp;
	}

	Mat4& Mat4::inv(void)
	{
#ifdef MATH_USE_HINTS
		switch (this->privGetHint())
		{
		case Hint::Generalize:
		{
			const float det = this->det();

			if (det != 0.0f)
			{
				const float invDet = 1.0f / det;
				Mat4 result;

				result._m0 = (_m5 * (_m10 * _m15 - _m11 * _m14) - _m6 * (_m9 * _m15 - _m11 * _m13) + _m7 * (_m9 * _m14 - _m10 * _m13));
				result._m1 = -(_m1 * (_m10 * _m15 - _m11 * _m14) - _m2 * (_m9 * _m15 - _m11 * _m13) + _m3 * (_m9 * _m14 - _m10 * _m13));
				result._m2 = (_m1 * (_m6 * _m15 - _m7 * _m14) - _m2 * (_m5 * _m15 - _m7 * _m13) + _m3 * (_m5 * _m14 - _m6 * _m13));
				result._m3 = -(_m1 * (_m6 * _m11 - _m7 * _m10) - _m2 * (_m5 * _m11 - _m7 * _m9) + _m3 * (_m5 * _m10 - _m6 * _m9));

				result._m4 = -(_m4 * (_m10 * _m15 - _m11 * _m14) - _m6 * (_m8 * _m15 - _m11 * _m12) + _m7 * (_m8 * _m14 - _m10 * _m12));
				result._m5 = (_m0 * (_m10 * _m15 - _m11 * _m14) - _m2 * (_m8 * _m15 - _m11 * _m12) + _m3 * (_m8 * _m14 - _m10 * _m12));
				result._m6 = -(_m0 * (_m6 * _m15 - _m7 * _m14) - _m2 * (_m4 * _m15 - _m7 * _m12) + _m3 * (_m4 * _m14 - _m6 * _m12));
				result._m7 = (_m0 * (_m6 * _m11 - _m7 * _m10) - _m2 * (_m4 * _m11 - _m7 * _m8) + _m3 * (_m4 * _m10 - _m6 * _m8));

				result._m8 = (_m4 * (_m9 * _m15 - _m11 * _m13) - _m5 * (_m8 * _m15 - _m11 * _m12) + _m7 * (_m8 * _m13 - _m9 * _m12));
				result._m9 = -(_m0 * (_m9 * _m15 - _m11 * _m13) - _m1 * (_m8 * _m15 - _m11 * _m12) + _m3 * (_m8 * _m13 - _m9 * _m12));
				result._m10 = (_m0 * (_m5 * _m15 - _m7 * _m13) - _m1 * (_m4 * _m15 - _m7 * _m12) + _m3 * (_m4 * _m13 - _m5 * _m12));
				result._m11 = -(_m0 * (_m5 * _m11 - _m7 * _m9) - _m1 * (_m4 * _m11 - _m7 * _m8) + _m3 * (_m4 * _m9 - _m5 * _m8));

				result._m12 = -(_m4 * (_m9 * _m14 - _m10 * _m13) - _m5 * (_m8 * _m14 - _m10 * _m12) + _m6 * (_m8 * _m13 - _m9 * _m12));
				result._m13 = (_m0 * (_m9 * _m14 - _m10 * _m13) - _m1 * (_m8 * _m14 - _m10 * _m12) + _m2 * (_m8 * _m13 - _m9 * _m12));
				result._m14 = -(_m0 * (_m5 * _m14 - _m6 * _m13) - _m1 * (_m4 * _m14 - _m6 * _m12) + _m2 * (_m4 * _m13 - _m5 * _m12));
				result._m15 = (_m0 * (_m5 * _m10 - _m6 * _m9) - _m1 * (_m4 * _m10 - _m6 * _m8) + _m2 * (_m4 * _m9 - _m5 * _m8));

				result *= invDet;

				*this = result;
			}

			//this->privSetGeneralHint();

			break;
		}
		case Hint::Rot:
		{
			//compute transpose of rotation matrix
			return this->T();
		}
		case Hint::RotScale:
		{
			//compute transpose of rotation matrix
			//compute matrix inverse is M(1/scale)

			Hint hint = this->privGetHint();

			const float det = this->det();

			if (det != 0.0f)
			{
				const float invDet = 1.0f / det;

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

				_m15 = 1.0f;
			}

			this->privSetNewHint(Hint::RotScale, hint);

			break;
		}
		case Hint::RotTrans:
		{
			//compute transpose of rotation matrix
			//compute negation of translation 

			float temp = -(this->_m0 * this->_m12 + this->_m1 * this->_m13 + this->_m2 * this->_m14);
			float temp2 = -(this->_m4 * this->_m12 + this->_m5 * this->_m13 + this->_m6 * this->_m14);
			float temp3 = -(this->_m8 * this->_m12 + this->_m9 * this->_m13 + this->_m10 * this->_m14);

			// Set the new translation
			this->_m12 = temp;
			this->_m13 = temp2;
			this->_m14 = temp3;

			this->T();

			this->privSetNewHint(Hint::RotTrans, this->privGetHint());

			break;
		}
		case Hint::Scale:
		{
			//compute matrix inverse is M(1/scale)

			this->_m0 = 1.0f / this->_m0;
			this->_m5 = 1.0f / this->_m5;
			this->_m10 = 1.0f / this->_m10;

			this->privSetScaleHint();

			break;
		}
		case Hint::Trans:
		{
			//compute inverse of translation matrix by negating translation
			this->_m12 = -(this->_m12);
			this->_m13 = -(this->_m13);
			this->_m14 = -(this->_m14);

			this->privSetTransHint();

			break;
		}
		case Hint::TransScale:
		{
			//compute inverse of translation matrix by negating translation
			//compute matrix inverse is M(1/scale)

			this->_m0 = 1.0f / this->_m0;
			this->_m5 = 1.0f / this->_m5;
			this->_m10 = 1.0f / this->_m10;

			this->_m12 = -(this->_m12 * this->_m0);
			this->_m13 = -(this->_m13 * this->_m5);
			this->_m14 = -(this->_m14 * this->_m10);

			this->privSetNewHint(Hint::TransScale, this->privGetHint());

			break;
		}
		case Hint::Affine:
		{
			//generalized affine matrix inverse
			Hint hint = this->privGetHint();

			const float det = this->det();
			if (det != 0.0f)
			{
				const float invDet = 1.0f / det;

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

				float t0 = -(this->_m12);
				float t1 = -(this->_m13);
				float t2 = -(this->_m14);

				this->_m12 = _m0 * t0 + _m4 * t1 + _m8 * t2;
				this->_m13 = _m1 * t0 + _m5 * t1 + _m9 * t2;
				this->_m14 = _m2 * t0 + _m6 * t1 + _m10 * t2;

				_m15 = 1.0f;

			}

			this->privSetNewHint(Hint::Affine, hint);

			break;
		}

		default:
			break;
		}
#endif

		return *this;
	}

	//--------------------COMPARISON OPERATORS------------------------
	bool Mat4::isEqual(const Mat4& tM, const float epsilon) const
	{
		return (Util::isEqual(this->_m0, tM._m0, epsilon) &&
			Util::isEqual(this->_m1, tM._m1, epsilon) &&
			Util::isEqual(this->_m2, tM._m2, epsilon) &&
			Util::isEqual(this->_m3, tM._m3, epsilon) &&
			Util::isEqual(this->_m4, tM._m4, epsilon) &&
			Util::isEqual(this->_m5, tM._m5, epsilon) &&
			Util::isEqual(this->_m6, tM._m6, epsilon) &&
			Util::isEqual(this->_m7, tM._m7, epsilon) &&
			Util::isEqual(this->_m8, tM._m8, epsilon) &&
			Util::isEqual(this->_m9, tM._m9, epsilon) &&
			Util::isEqual(this->_m10, tM._m10, epsilon) &&
			Util::isEqual(this->_m11, tM._m11, epsilon) &&
			Util::isEqual(this->_m12, tM._m12, epsilon) &&
			Util::isEqual(this->_m13, tM._m13, epsilon) &&
			Util::isEqual(this->_m14, tM._m14, epsilon) &&
			Util::isEqual(this->_m15, tM._m15, epsilon));
	}

	bool Mat4::isIdentity(const float epsilon) const
	{
		return (Util::isEqual(this->_m0, 1.0f, epsilon) &&
			Util::isEqual(this->_m1, 0.0f, epsilon) &&
			Util::isEqual(this->_m2, 0.0f, epsilon) &&
			Util::isEqual(this->_m3, 0.0f, epsilon) &&
			Util::isEqual(this->_m4, 0.0f, epsilon) &&
			Util::isEqual(this->_m5, 1.0f, epsilon) &&
			Util::isEqual(this->_m6, 0.0f, epsilon) &&
			Util::isEqual(this->_m7, 0.0f, epsilon) &&
			Util::isEqual(this->_m8, 0.0f, epsilon) &&
			Util::isEqual(this->_m9, 0.0f, epsilon) &&
			Util::isEqual(this->_m10, 1.0f, epsilon) &&
			Util::isEqual(this->_m11, 0.0f, epsilon) &&
			Util::isEqual(this->_m12, 0.0f, epsilon) &&
			Util::isEqual(this->_m13, 0.0f, epsilon) &&
			Util::isEqual(this->_m14, 0.0f, epsilon) &&
			Util::isEqual(this->_m15, 1.0f, epsilon));
	}

	bool Mat4::isRotation(const float epsilon) const
	{
		return (Util::isEqual(this->_m3, 0.0f, epsilon) &&
			Util::isEqual(this->_m7, 0.0f, epsilon) &&
			Util::isEqual(this->_m11, 0.0f, epsilon) &&
			Util::isEqual(this->_m12, 0.0f, epsilon) &&
			Util::isEqual(this->_m13, 0.0f, epsilon) &&
			Util::isEqual(this->_m14, 0.0f, epsilon) &&
			Util::isEqual(this->_m15, 1.0f, epsilon));
	}

	//--------------------ADD OPERATORS------------------------
	Mat4 Mat4::operator + (void) const
	{
		this->privSetCopyHint();
		return Mat4(*this);
	}

	Mat4 Mat4::operator+(const Mat4& tM) const
	{
		Mat4 temp(*this);

		temp._m0 += tM._m0;
		temp._m1 += tM._m1;
		temp._m2 += tM._m2;
		temp._m3 += tM._m3;
		temp._m4 += tM._m4;
		temp._m5 += tM._m5;
		temp._m6 += tM._m6;
		temp._m7 += tM._m7;
		temp._m8 += tM._m8;
		temp._m9 += tM._m9;
		temp._m10 += tM._m10;
		temp._m11 += tM._m11;
		temp._m12 += tM._m12;
		temp._m13 += tM._m13;
		temp._m14 += tM._m14;
		temp._m15 += tM._m15;

		temp.privSetGeneralHint();

		return temp;
	}

	Mat4& Mat4::operator += (const Mat4& A)
	{
		this->_m0 += A._m0;
		this->_m1 += A._m1;
		this->_m2 += A._m2;
		this->_m3 += A._m3;
		this->_m4 += A._m4;
		this->_m5 += A._m5;
		this->_m6 += A._m6;
		this->_m7 += A._m7;
		this->_m8 += A._m8;
		this->_m9 += A._m9;
		this->_m10 += A._m10;
		this->_m11 += A._m11;
		this->_m12 += A._m12;
		this->_m13 += A._m13;
		this->_m14 += A._m14;
		this->_m15 += A._m15;

		this->privSetGeneralHint();

		return *this;
	}

	//--------------------SUB OPERATORS------------------------
	Mat4 Mat4::operator - (void) const
	{
		Mat4 temp(*this);

		temp._m0 = -temp._m0;
		temp._m1 = -temp._m1;
		temp._m2 = -temp._m2;
		temp._m3 = -temp._m3;
		temp._m4 = -temp._m4;
		temp._m5 = -temp._m5;
		temp._m6 = -temp._m6;
		temp._m7 = -temp._m7;
		temp._m8 = -temp._m8;
		temp._m9 = -temp._m9;
		temp._m10 = -temp._m10;
		temp._m11 = -temp._m11;
		temp._m12 = -temp._m12;
		temp._m13 = -temp._m13;
		temp._m14 = -temp._m14;
		temp._m15 = -temp._m15;

		temp.privSetGeneralHint();

		return temp;
	}

	Mat4 Mat4::operator - (const Mat4& A) const
	{
		Mat4 temp(*this);

		temp._m0 -= A._m0;
		temp._m1 -= A._m1;
		temp._m2 -= A._m2;
		temp._m3 -= A._m3;
		temp._m4 -= A._m4;
		temp._m5 -= A._m5;
		temp._m6 -= A._m6;
		temp._m7 -= A._m7;
		temp._m8 -= A._m8;
		temp._m9 -= A._m9;
		temp._m10 -= A._m10;
		temp._m11 -= A._m11;
		temp._m12 -= A._m12;
		temp._m13 -= A._m13;
		temp._m14 -= A._m14;
		temp._m15 -= A._m15;

		temp.privSetGeneralHint();

		return temp;
	}

	Mat4& Mat4::operator -= (const Mat4& A)
	{
		this->_m0 -= A._m0;
		this->_m1 -= A._m1;
		this->_m2 -= A._m2;
		this->_m3 -= A._m3;
		this->_m4 -= A._m4;
		this->_m5 -= A._m5;
		this->_m6 -= A._m6;
		this->_m7 -= A._m7;
		this->_m8 -= A._m8;
		this->_m9 -= A._m9;
		this->_m10 -= A._m10;
		this->_m11 -= A._m11;
		this->_m12 -= A._m12;
		this->_m13 -= A._m13;
		this->_m14 -= A._m14;
		this->_m15 -= A._m15;

		this->privSetGeneralHint();

		return *this;
	}

	//--------------------SCALE OPERATORS------------------------
	Mat4 Mat4::operator * (const float s) const
	{
		Mat4 temp(*this);

		temp._m0 *= s;
		temp._m1 *= s;
		temp._m2 *= s;
		temp._m3 *= s;
		temp._m4 *= s;
		temp._m5 *= s;
		temp._m6 *= s;
		temp._m7 *= s;
		temp._m8 *= s;
		temp._m9 *= s;
		temp._m10 *= s;
		temp._m11 *= s;
		temp._m12 *= s;
		temp._m13 *= s;
		temp._m14 *= s;
		temp._m15 *= s;

		temp.privSetGeneralHint();

		return temp;
	}

	Mat4 operator *(const float scale, const Mat4& A)
	{
		Mat4 temp(A);
		temp *= scale;

		temp.privSetGeneralHint();

		return temp;
	}

	Mat4& Mat4::operator *= (const float scale)
	{
		this->_m0 *= scale;
		this->_m1 *= scale;
		this->_m2 *= scale;
		this->_m3 *= scale;
		this->_m4 *= scale;
		this->_m5 *= scale;
		this->_m6 *= scale;
		this->_m7 *= scale;
		this->_m8 *= scale;
		this->_m9 *= scale;
		this->_m10 *= scale;
		this->_m11 *= scale;
		this->_m12 *= scale;
		this->_m13 *= scale;
		this->_m14 *= scale;
		this->_m15 *= scale;

		this->privSetGeneralHint();

		return *this;
	}

	//--------------------MULTIPLICATION OPERATORS------------------------
	Mat4 Mat4::operator * (const Mat4& A) const
	{
		Hint hint = this->privGetHint();
		Hint newHint = A.privGetHint();

		Vec4 row0(_m0 * A._m0 + _m1 * A._m4 + _m2 * A._m8 + _m3 * A._m12,
			_m0 * A._m1 + _m1 * A._m5 + _m2 * A._m9 + _m3 * A._m13,
			_m0 * A._m2 + _m1 * A._m6 + _m2 * A._m10 + _m3 * A._m14,
			_m0 * A._m3 + _m1 * A._m7 + _m2 * A._m11 + _m3 * A._m15);

		Vec4 row1(_m4 * A._m0 + _m5 * A._m4 + _m6 * A._m8 + _m7 * A._m12,
			_m4 * A._m1 + _m5 * A._m5 + _m6 * A._m9 + _m7 * A._m13,
			_m4 * A._m2 + _m5 * A._m6 + _m6 * A._m10 + _m7 * A._m14,
			_m4 * A._m3 + _m5 * A._m7 + _m6 * A._m11 + _m7 * A._m15);

		Vec4 row2(_m8 * A._m0 + _m9 * A._m4 + _m10 * A._m8 + _m11 * A._m12,
			_m8 * A._m1 + _m9 * A._m5 + _m10 * A._m9 + _m11 * A._m13,
			_m8 * A._m2 + _m9 * A._m6 + _m10 * A._m10 + _m11 * A._m14,
			_m8 * A._m3 + _m9 * A._m7 + _m10 * A._m11 + _m11 * A._m15);

		Vec4 row3(_m12 * A._m0 + _m13 * A._m4 + _m14 * A._m8 + _m15 * A._m12,
			_m12 * A._m1 + _m13 * A._m5 + _m14 * A._m9 + _m15 * A._m13,
			_m12 * A._m2 + _m13 * A._m6 + _m14 * A._m10 + _m15 * A._m14,
			_m12 * A._m3 + _m13 * A._m7 + _m14 * A._m11 + _m15 * A._m15);

		Mat4 temp(row0, row1, row2, row3);

		temp.privSetNewHint(hint, newHint);

		return temp;
	}

	Mat4& Mat4::operator *= (const Mat4& A)
	{
		*this = *this * A;
		return *this;
	}

	//--------------------CASTING OPERATORS------------------------
	//THESE ARE INCORRECT JUST NEED TO CAST SO THAT IT CALLS RELEVANT OPERATION
	Mat4 Mat4::operator * (const Quat& q) const
	{
		Mat4 temp(q);
		return *this * temp;
	}

	Mat4& Mat4::operator *= (const Quat& q)
	{
		Mat4 temp(q);
		*this = *this * temp;
		return *this;
	}


	Mat4 Mat4::operator * (const Scale& A) const
	{
		Hint hint = this->privGetHint();
		Hint newHint = Hint::Scale;

		Mat4 result;

		result._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8 + this->_m3 * A._m12;
		result._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9 + this->_m3 * A._m13;
		result._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10 + this->_m3 * A._m14;
		result._m3 = this->_m0 * A._m3 + this->_m1 * A._m7 + this->_m2 * A._m11 + this->_m3 * A._m15;

		result._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8 + this->_m7 * A._m12;
		result._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9 + this->_m7 * A._m13;
		result._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10 + this->_m7 * A._m14;
		result._m7 = this->_m4 * A._m3 + this->_m5 * A._m7 + this->_m6 * A._m11 + this->_m7 * A._m15;

		result._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8 + this->_m11 * A._m12;
		result._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9 + this->_m11 * A._m13;
		result._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10 + this->_m11 * A._m14;
		result._m11 = this->_m8 * A._m3 + this->_m9 * A._m7 + this->_m10 * A._m11 + this->_m11 * A._m15;

		result._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8 + this->_m15 * A._m12;
		result._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9 + this->_m15 * A._m13;
		result._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10 + this->_m15 * A._m14;
		result._m15 = this->_m12 * A._m3 + this->_m13 * A._m7 + this->_m14 * A._m11 + this->_m15 * A._m15;


		result.privSetNewHint(hint, newHint);

		return result;
	}
	Mat4& Mat4::operator *= (const Scale& A)
	{
		*this = *this * A;
		return *this;
	}

	Mat4 Mat4::operator * (const Rot& A) const
	{
		Hint hint = this->privGetHint();
		Hint newHint = Hint::Rot;

		Mat4 result;

		result._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8;
		result._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9;
		result._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10;
		result._m3 = this->_m3;

		result._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8;
		result._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9;
		result._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10;
		result._m7 = this->_m7;

		result._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8;
		result._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9;
		result._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10;
		result._m11 = this->_m11;

		result._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8;
		result._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9;
		result._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10;
		result._m15 = this->_m15;

		result.privSetNewHint(hint, newHint);

		return result;
	}
	Mat4& Mat4::operator *= (const Rot& A)
	{
		*this = *this * A;
		return *this;
	}

	Mat4 Mat4::operator * (const Trans& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 result(*this);

		result._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8 + this->_m3 * A._m12;
		result._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9 + this->_m3 * A._m13;
		result._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10 + this->_m3 * A._m14;
		result._m3 = this->_m0 * A._m3 + this->_m1 * A._m7 + this->_m2 * A._m11 + this->_m3 * A._m15;

		result._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8 + this->_m7 * A._m12;
		result._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9 + this->_m7 * A._m13;
		result._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10 + this->_m7 * A._m14;
		result._m7 = this->_m4 * A._m3 + this->_m5 * A._m7 + this->_m6 * A._m11 + this->_m7 * A._m15;

		result._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8 + this->_m11 * A._m12;
		result._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9 + this->_m11 * A._m13;
		result._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10 + this->_m11 * A._m14;
		result._m11 = this->_m8 * A._m3 + this->_m9 * A._m7 + this->_m10 * A._m11 + this->_m11 * A._m15;

		result._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8 + this->_m15 * A._m12;
		result._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9 + this->_m15 * A._m13;
		result._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10 + this->_m15 * A._m14;
		result._m15 = this->_m12 * A._m3 + this->_m13 * A._m7 + this->_m14 * A._m11 + this->_m15 * A._m15;

		result.privSetNewHint(hint, hintA);

		return result;
	}
	Mat4& Mat4::operator *= (const Trans& A)
	{
		*this = *this * A;
		return *this;
	}

	//--------------------PRINTING------------------------
	void Mat4::Print(const char* pName) const
	{
		Trace::out("\n%s: \n", pName);
		Trace::out("| %f %f %f %f |\n", this->_m0, this->_m1, this->_m2, this->_m3);
		Trace::out("| %f %f %f %f |\n", this->_m4, this->_m5, this->_m6, this->_m7);
		Trace::out("| %f %f %f %f |\n", this->_m8, this->_m9, this->_m10, this->_m11);
		Trace::out("| %f %f %f %f |\n", this->_m12, this->_m13, this->_m14, this->_m15);

	}



}

// ---  End of File ---
