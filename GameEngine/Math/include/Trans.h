//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_TRANS_4x4_H
#define ENGINE_MATH_TRANS_4x4_H

#include "Mat4.h"

namespace Azul
{
	class Trans final : public Mat4
	{
	public:

		//---------------CONSTRUCTORS----------------
		Trans();
		Trans &operator = (const Trans &A) = default;
		Trans(const Trans &tM) = default;
		~Trans() = default;

		//---------------SPECIALIZED CONSTRUCTORS----------------
		Trans(Trans &&) = default;
		Trans &operator = (Trans &&) = default;

		Trans(const float tx, const float ty, const float tz);
		explicit Trans(const Vec3 &vTrans);
		explicit Trans(const enum Identity_enum);

		//---------------SETTERS----------------
		void set(const float tx, const float ty, const float tz);
		void set(const Vec3 &vTrans);
		void set(const enum Identity_enum);

		//---------------OPERATORS----------------	
		Mat4 operator * (const Mat4 &A) const;
		Trans &operator *= (const Mat4 &A) = delete;

		Mat4 operator * (const Quat &q) const;
		Trans &operator *= (const Quat &q) = delete;

		Mat4 operator * (const Scale &A) const;
		Trans &operator *= (const Scale &A) = delete;

		Mat4 operator * (const Rot &A) const;
		Trans &operator *= (const Rot &A) = delete;

		Trans operator * (const Trans &A) const;
		Trans &operator *= (const Trans &A);


	};
}

#endif

//--- End of File ---
