//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_SCALE_4x4_H
#define ENGINE_MATH_SCALE_4x4_H

#include "Mat4.h"

namespace Azul
{
	class Scale final : public Mat4
	{
	public:

		//--------------CONSTRUCTORS-------------------------------------
		Scale();
		Scale &operator = (const Scale &A) = default;
		Scale(const Scale &tM) = default;
		~Scale() = default;

		//--------------SPECIALIZED OPERATORS-------------------------------------	
		Scale(Scale &&) = default;
		Scale &operator = (Scale &&) = default;

		Scale(const float sx, const float sy, const float sz);
		explicit Scale(const Vec3 &vScale);
		explicit Scale(const enum Identity_enum);

		//--------------SETTERS-------------------------------------
		void set(const float sx, const float sy, const float sz);
		void set(const Vec3 &vScale);
		void set(const enum Identity_enum);

		//--------------OPERATORS-------------------------------------
		Mat4 operator * (const Mat4 &A) const;
		Scale &operator *= (const Mat4 &A) = delete;

		Mat4 operator * (const Quat &q) const;
		Scale &operator *= (const Quat &q) = delete;

		Scale operator * (const Scale &A) const;
		Scale &operator *= (const Scale &A);

		Mat4 operator * (const Rot &A) const;
		Scale &operator *= (const Rot &A) = delete;

		Mat4 operator * (const Trans &A) const;
		Scale &operator *= (const Trans &A) = delete;

	};
}

#endif

//--- End of File ---
