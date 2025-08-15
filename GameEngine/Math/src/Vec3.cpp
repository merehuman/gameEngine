//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	//----------------BIG 4--------------------
	Vec3::Vec3() : _vx(0.0f), _vy(0.0f), _vz(0.0f) {}

	Vec3::Vec3(const Vec3& inV) :
		_vx(inV._vx), _vy(inV._vy), _vz(inV._vz) {}

	Vec3& Vec3::operator=(const Vec3& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;

		return *this;
	}

	Vec3::~Vec3() {}

	//----------------CONSTRUCTORS------------------
	Vec3::Vec3(const float inX, const float inY, const float inZ) :
		_vx(inX), _vy(inY), _vz(inZ) {}

	Vec3::Vec3(const Vec4& v) :
		_vx(v._vx), _vy(v._vy), _vz(v._vz) {}

	Vec3& Vec3::operator=(const Vec4& v)
	{
		this->_vx = v._vx;
		this->_vy = v._vy;
		this->_vz = v._vz;

		return *this;
	}

	//----------------BRACKETS--------------------
	float& Vec3::operator[](const enum x_enum) { return this->_vx; }
	float& Vec3::operator[](const enum y_enum) { return this->_vy; }
	float& Vec3::operator[](const enum z_enum) { return this->_vz; }

	float Vec3::operator[](const enum x_enum) const { return this->_vx; }
	float Vec3::operator[](const enum y_enum) const { return this->_vy; }
	float Vec3::operator[](const enum z_enum) const { return this->_vz; }

	//----------------ACCESSORS--------------------
	void Vec3::x(const float inX) { this->_vx = inX; }
	void Vec3::y(const float inY) { this->_vy = inY; }
	void Vec3::z(const float inZ) { this->_vz = inZ; }

	float Vec3::x() const { return this->_vx; }
	float Vec3::y() const { return this->_vy; }
	float Vec3::z() const { return this->_vz; }

	//----------------ADD OPERATORS------------------
	Vec3 Vec3::operator+(void) const
	{
		return *this;
	}

	Vec3 Vec3::operator+(const Vec3& inV) const
	{
		return Vec3(this->_vx + inV._vx, this->_vy + inV._vy, this->_vz + inV._vz);
	}

	Vec3& Vec3::operator+=(const Vec3& inV)
	{
		this->_vx += inV._vx;
		this->_vy += inV._vy;
		this->_vz += inV._vz;

		return *this;
	}

	//----------------SUBTRACT OPERATORS------------------
	Vec3 Vec3::operator-(void) const
	{
		return Vec3(-this->_vx, -this->_vy, -this->_vz);
	}

	Vec3 Vec3::operator-(const Vec3& inV) const
	{
		return Vec3(this->_vx - inV._vx, this->_vy - inV._vy, this->_vz - inV._vz);
	}

	Vec3& Vec3::operator-=(const Vec3& inV)
	{
		this->_vx -= inV._vx;
		this->_vy -= inV._vy;
		this->_vz -= inV._vz;

		return *this;
	}

	//----------------SCALE OPERATORS------------------
	Vec3 Vec3::operator*(const float s) const
	{
		return Vec3(this->_vx * s, this->_vy * s, this->_vz * s);
	}

	Vec3 operator *(const float scale, const Vec3& inV)
	{
		return Vec3(inV._vx * scale, inV._vy * scale, inV._vz * scale);
	}

	Vec3& Vec3::operator*=(const float s)
	{
		this->_vx *= s;
		this->_vy *= s;
		this->_vz *= s;

		return *this;
	}

	//----------------VEC3*MAT3 OPERATORS------------------
	Vec3 Vec3::operator*(const Mat3& inM) const
	{
		return Vec3(
			this->_vx * inM._m0 + this->_vy * inM._m4 + this->_vz * inM._m8,
			this->_vx * inM._m1 + this->_vy * inM._m5 + this->_vz * inM._m9,
			this->_vx * inM._m2 + this->_vy * inM._m6 + this->_vz * inM._m10
		);
	}

	Vec3& Vec3::operator*=(const Mat3& inM)
	{
		this->set(*this * inM);
		return *this;
	}


	//---------------VEC3 * QUAT OPERATORS-------------------------------------
	Vec3 Vec3::operator* (const Quat& q) const
	{
		Quat vectorQuat(this->_vx, this->_vy, this->_vz, 0.0f);

		Quat qInverse = q.getConj();

		Quat resultQuat = qInverse * vectorQuat * q;

		return Vec3(resultQuat.qx(), resultQuat.qy(), resultQuat.qz());
	}

	Vec3& Vec3::operator*= (const Quat& q)
	{
		Quat vectorQuat(this->_vx, this->_vy, this->_vz, 0.0f); 

		Quat qInverse = q.getConj();

		Quat resultQuat = qInverse * vectorQuat * q ;

		this->_vx = resultQuat.qx();
		this->_vy = resultQuat.qy();
		this->_vz = resultQuat.qz();

		return *this;
	}

	//----------------DIVIDE OPERATORS------------------
	Vec3& Vec3::operator/=(const float s)
	{
		this->_vx /= s;
		this->_vy /= s;
		this->_vz /= s;

		return *this;
	}

	//----------------VECTOR FUNCTIONS------------------
	float Vec3::mag(void) const //GET RID OF SQRT???
	{
		return sqrtf(this->_vx * this->_vx + this->_vy * this->_vy + this->_vz * this->_vz);
	}

	Vec3& Vec3::norm(void)
	{
		return *this /= this->mag();
	}

	Vec3 Vec3::getNorm(void) const
	{
		float mag = this->mag();
		return Vec3(this->_vx / mag, this->_vy / mag, this->_vz / mag);
	}

	float Vec3::dot(const Vec3& inV) const
	{
		return this->_vx * inV._vx + this->_vy * inV._vy + this->_vz * inV._vz;
	}

	Vec3 Vec3::cross(const Vec3& inV) const
	{
		return Vec3(
			this->_vy * inV._vz - this->_vz * inV._vy,
			this->_vz * inV._vx - this->_vx * inV._vz,
			this->_vx * inV._vy - this->_vy * inV._vx
		);
	}

	Vec3Proxy Vec3::len(void) const
	{
		return Vec3Proxy(this->mag(), 0, 0);
	}

	float Vec3::getAngle(const Vec3& inV) const
	{
		return acosf(this->dot(inV) / (this->mag() * inV.mag()));
	}

	//----------------SET------------------
	void Vec3::set(const float inX, const float inY, const float inZ)
	{
		this->_vx = inX;
		this->_vy = inY;
		this->_vz = inZ;
	}

	void Vec3::set(const Vec3& inV)
	{
		this->_vx = inV._vx;
		this->_vy = inV._vy;
		this->_vz = inV._vz;
	}

	void Vec3::set(const Vec4& inV)
	{
		this->_vx = inV._vx;
		this->_vy = inV._vy;
		this->_vz = inV._vz;
	}

	//----------------COMPARISON------------------
	bool Vec3::isEqual(const Vec3& inV, const float epsilon) const
	{
		return
			(fabs(this->_vx - inV._vx) < epsilon) &&
			(fabs(this->_vy - inV._vy) < epsilon) &&
			(fabs(this->_vz - inV._vz) < epsilon);
	}

	bool Vec3::isZero(const float epsilon) const
	{
		return
			(fabs(this->_vx) < epsilon) &&
			(fabs(this->_vy) < epsilon) &&
			(fabs(this->_vz) < epsilon);
	}

	//----------------PRINT------------------
	void Vec3::Print(const char* inName) const
	{
		Trace::out("%s: %f %f %f\n", inName, this->_vx, this->_vy, this->_vz);
	}
}

//--- End of File ---
