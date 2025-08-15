//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	//----------------BIG FOUR----------------
	Vec4::Vec4() : _vx(0.0f), _vy(0.0f), _vz(0.0f), _vw(0.0f) {}

	Vec4::Vec4(const float x, const float y, const float z, const float w) :
		_vx(x), _vy(y), _vz(z), _vw(w) {}

	Vec4::Vec4(const Vec3& v, const float w) :
		_vx(v._vx), _vy(v._vy), _vz(v._vz), _vw(w) {}

	Vec4::Vec4(const Vec4& v) :
		_vx(v._vx), _vy(v._vy), _vz(v._vz), _vw(v._vw) {}

	Vec4& Vec4::operator = (const Vec4& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		this->_vw = v._vw;

		return *this;
	}

	Vec4::~Vec4() {}

	//-----------------BRACKET OPERATORS-----------------
	float& Vec4::operator[](const enum x_enum) { return this->_vx; }
	float& Vec4::operator[](const enum y_enum) { return this->_vy; }
	float& Vec4::operator[](const enum z_enum) { return this->_vz; }
	float& Vec4::operator[](const enum w_enum) { return this->_vw; }

	float Vec4::operator[](const enum x_enum) const { return this->_vx; }
	float Vec4::operator[](const enum y_enum) const { return this->_vy; }
	float Vec4::operator[](const enum z_enum) const { return this->_vz; }
	float Vec4::operator[](const enum w_enum) const { return this->_vw; }

	//-----------------ACCESSORS-----------------
	void Vec4::x(const float x) { this->_vx = x; }
	void Vec4::y(const float y) { this->_vy = y; }
	void Vec4::z(const float z) { this->_vz = z; }
	void Vec4::w(const float w) { this->_vw = w; }

	float Vec4::x() const { return this->_vx; }
	float Vec4::y() const { return this->_vy; }
	float Vec4::z() const { return this->_vz; }
	float Vec4::w() const { return this->_vw; }

	//-----------------ADDITION OPERATORS-----------------
	Vec4 Vec4::operator + (void) const
	{
		return *this;
	}

	Vec4 Vec4::operator + (const Vec4& v) const
	{
		return Vec4(this->_vx + v._vx, this->_vy + v._vy, this->_vz + v._vz, this->_vw + v._vw);
	}

	Vec4& Vec4::operator += (const Vec4& v)
	{
		this->_vx += v._vx;
		this->_vy += v._vy;
		this->_vz += v._vz;
		this->_vw += v._vw;

		return *this;
	}

	//-----------------SUBTRACTION OPERATORS-----------------
	Vec4 Vec4::operator - (void) const
	{
		return Vec4(-this->_vx, -this->_vy, -this->_vz, -this->_vw);
	}

	Vec4 Vec4::operator - (const Vec4& v) const
	{
		return Vec4(this->_vx - v._vx, this->_vy - v._vy, this->_vz - v._vz, this->_vw - v._vw);
	}

	Vec4& Vec4::operator -= (const Vec4& v)
	{
		this->_vx -= v._vx;
		this->_vy -= v._vy;
		this->_vz -= v._vz;
		this->_vw -= v._vw;

		return *this;
	}

	//-----------------SCALE OPERATORS-----------------
	Vec4 Vec4::operator * (const float s) const
	{
		return Vec4(this->_vx * s, this->_vy * s, this->_vz * s, this->_vw * s);
	}

	Vec4& Vec4::operator *= (const float s)
	{
		this->_vx *= s;
		this->_vy *= s;
		this->_vz *= s;
		this->_vw *= s;

		return *this;
	}

	Vec4 operator * (const float s, const Vec4& v)
	{
		return v * s;
	}

	//-----------------VEC4*MAT4 OPERATORS-----------------
	Vec4 Vec4::operator * (const Mat4& m) const
	{
		return Vec4(
			this->_vx * m.m0() + this->_vy * m.m4() + this->_vz * m.m8() + this->_vw * m.m12(),
			this->_vx * m.m1() + this->_vy * m.m5() + this->_vz * m.m9() + this->_vw * m.m13(),
			this->_vx * m.m2() + this->_vy * m.m6() + this->_vz * m.m10() + this->_vw * m.m14(),
			this->_vx * m.m3() + this->_vy * m.m7() + this->_vz * m.m11() + this->_vw * m.m15()
		);
	}

	Vec4& Vec4::operator *= (const Mat4& m)
	{
		*this = *this * m;
		return *this;
	}

	//-----------------VEC4 FUNCTIONS-----------------
	float Vec4::mag() const
	{
		return sqrtf(this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz + this->_vw * this->_vw);
	}

	Vec4& Vec4::norm()
	{
		float mag = this->mag();
		this->_vx /= mag;
		this->_vy /= mag;
		this->_vz /= mag;
		this->_vw /= mag;

		return *this;
	}

	Vec4 Vec4::getNorm() const
	{
		float mag = this->mag();
		return Vec4(this->_vx / mag, this->_vy / mag, this->_vz / mag, this->_vw / mag);
	}

	float Vec4::dot(const Vec4& v) const
	{
		return this->_vx * v._vx + this->_vy * v._vy + this->_vz * v._vz + this->_vw * v._vw;
	}

	Vec4Proxy Vec4::len() const
	{
		return Vec4Proxy(this->mag(), 0, 0, 0);
	}

	//-----------------SETTERS-----------------
	void Vec4::set(const float x, const float y, const float z, const float w)
	{
		this->_vx = x;
		this->_vy = y;
		this->_vz = z;
		this->_vw = w;
	}

	void Vec4::set(const Vec4& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		this->_vw = v._vw;
	}

	void Vec4::set(const Vec3& v, const float w)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;
		this->_vw = w;
	}

	//-----------------COMPARISON OPERATORS-----------------
	bool Vec4::isEqual(const Vec4& v, const float epsilon) const
	{
		return
			(fabsf(this->_vx - v._vx) < epsilon) &&
			(fabsf(this->_vy - v._vy) < epsilon) &&
			(fabsf(this->_vz - v._vz) < epsilon) &&
			(fabsf(this->_vw - v._vw) < epsilon);
	}

	bool Vec4::isZero(const float epsilon) const
	{
		return
			(fabsf(this->_vx) < epsilon) &&
			(fabsf(this->_vy) < epsilon) &&
			(fabsf(this->_vz) < epsilon) &&
			(fabsf(this->_vw) < epsilon);
	}

	//-----------------PRINT-----------------
	void Vec4::Print(const char* name) const
	{
		Trace::out("%s: %f %f %f %f\n", name, this->_vx, this->_vy, this->_vz, this->_vw);
	}
}

//--- End of File ---
