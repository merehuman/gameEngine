//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	//--------------CONSTRUCTORS----------------
	Vec3Proxy::Vec3Proxy(float a, float b, float c)
		: x(a), y(b), z(c) {}

	Vec3Proxy::operator float() const
	{
		return x;
	}

	//--------------MULTIPLICATION OPERATORS----------------
	float Vec3Proxy::operator * (const Vec3Proxy& r) const
	{
		return this->x * r.x;
	}

	//--------------COMPARISON OPERATORS----------------
	bool Vec3Proxy::operator > (const Vec3Proxy& r) const
	{
		return (x > r.x); //&& (y > r.y) && (z > r.z);
	}

	bool Vec3Proxy::operator < (const Vec3Proxy& r) const
	{
		return (x < r.x); //&& (y < r.y) && (z < r.z);
	}

	bool Vec3Proxy::operator == (const Vec3Proxy& r) const
	{
		return (x == r.x); //&& (y == r.y) && (z == r.z);
	}

	bool Vec3Proxy::operator >= (const Vec3Proxy& r) const
	{
		return (x >= r.x); //&& (y >= r.y) && (z >= r.z);
	}

	bool Vec3Proxy::operator <= (const Vec3Proxy& r) const
	{
		return (x <= r.x); //&& (y <= r.y) && (z <= r.z);
	}

	bool Vec3Proxy::operator != (const Vec3Proxy& r) const
	{
		return !(*this == r);
	}

}

//--- End of File ---
