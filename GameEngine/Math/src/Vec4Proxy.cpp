//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	//--------------CONSTRUCTORS----------------
	Vec4Proxy::Vec4Proxy(float a, float b, float c, float d)
		: x(a), y(b), z(c), w(d) {}

	Vec4Proxy::operator float() const
	{
		return x;
	}

	//--------------MULTIPLICATION OPERATORS----------------
	float Vec4Proxy::operator * (const Vec4Proxy& r) const
	{
		return this->x * r.x;
	}

	//--------------COMPARISON OPERATORS----------------
	bool Vec4Proxy::operator > (const Vec4Proxy& r) const
	{
		return (x > r.x);
	}

	bool Vec4Proxy::operator < (const Vec4Proxy& r) const
	{
		return (x < r.x);
	}

	bool Vec4Proxy::operator == (const Vec4Proxy& r) const
	{
		return (x == r.x);
	}

	bool Vec4Proxy::operator >= (const Vec4Proxy& r) const
	{
		return (x >= r.x);
	}

	bool Vec4Proxy::operator <= (const Vec4Proxy& r) const
	{
		return (x <= r.x);
	}

	bool Vec4Proxy::operator != (const Vec4Proxy& r) const
	{
		return !(*this == r);
	}


}

//--- End of File ---
