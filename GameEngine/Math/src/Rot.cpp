//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

	//---------------CONSTRUCTORS-------------------
	Rot::Rot()
	{
		this->_m0 = 1.0f; this->_m1 = 0.0f; this->_m2 = 0.0f; this->_m3 = 0.0f;
		this->_m4 = 0.0f; this->_m5 = 1.0f; this->_m6 = 0.0f; this->_m7 = 0.0f;
		this->_m8 = 0.0f; this->_m9 = 0.0f; this->_m10 = 1.0f; this->_m11 = 0.0f;
		this->_m12 = 0.0f; this->_m13 = 0.0f; this->_m14 = 0.0f; this->_m15 = 1.0f;

		this->privSetRotHint();
	};

	Rot::Rot(const Quat& q)
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

	Rot& Rot::operator = (const Quat& q)
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

	Rot::Rot(const enum Identity_enum)
	{
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
		this->privSetRotHint();
	}


	Rot::Rot(const Rot1 type, const float angle)
	{
		switch (type)
		{
		case Rot1::X:
			this->_m0 = 1.0f;
			this->_m1 = 0.0f;
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = cos(angle);
			this->_m6 = sin(angle);
			this->_m7 = 0.0f;
			this->_m8 = 0.0f;
			this->_m9 = -sin(angle);
			this->_m10 = cos(angle);
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		case Rot1::Y:
			this->_m0 = cos(angle);
			this->_m1 = 0.0f;
			this->_m2 = -sin(angle);
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = 1.0f;
			this->_m6 = 0.0f;
			this->_m7 = 0.0f;
			this->_m8 = sin(angle);
			this->_m9 = 0.0f;
			this->_m10 = cos(angle);
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		case Rot1::Z:
			this->_m0 = cos(angle);
			this->_m1 = sin(angle);
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = -sin(angle);
			this->_m5 = cos(angle);
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
		}
		this->privSetRotHint();
	}

	Rot::Rot(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2)
	{
		Mat4 r1 = {
			Vec4(1, 0, 0, 0),
			Vec4(0, cos(angle_0), sin(angle_0), 0),
			Vec4(0, -sin(angle_0), cos(angle_0), 0),
			Vec4(0, 0, 0, 1)
		};
		Mat4 r2 = {
			Vec4(cos(angle_1), 0, -sin(angle_1), 0),
			Vec4(0, 1, 0, 0),
			Vec4(sin(angle_1), 0, cos(angle_1), 0),
			Vec4(0, 0, 0, 1)
		};
		Mat4 r3 = {
			Vec4(cos(angle_2), sin(angle_2), 0, 0),
			Vec4(-sin(angle_2), cos(angle_2), 0, 0),
			Vec4(0, 0, 1, 0),
			Vec4(0, 0, 0, 1)
		};
		switch (mode)
		{
		case Rot3::XYZ:
			this->Mat4::set(r1 * r2 * r3);
			break;
		case Rot3::XZY:
			this->Mat4::set(r1 * r3 * r2);
			break;
		case Rot3::YXZ:
			this->Mat4::set(r2 * r1 * r3);
			break;
		case Rot3::YZX:
			this->Mat4::set(r2 * r3 * r1);
			break;
		case Rot3::ZXY:
			this->Mat4::set(r3 * r1 * r2);
			break;
		case Rot3::ZYX:
			this->Mat4::set(r3 * r2 * r1);
			break;
		}

		this->privSetRotHint();

	}

	Rot::Rot(const Axis mode, const Vec3& vAxis, const float angle_radians)
	{
		Vec3 qV;
		if (mode == Axis::AxisAngle)
		{
			qV = vAxis.getNorm();
		}
		else
		{
			qV = vAxis;
		}

		const float angle_a = 0.5f * angle_radians;
		float cos_a;
		float sin_a;

		Trig::cossin(cos_a, sin_a, angle_a);

		qV *= sin_a;

		Vec4 Q;
		Q[x] = qV[x];
		Q[y] = qV[y];
		Q[z] = qV[z];
		Q[w] = cos_a;

		// this function has been transposed
		float x2, y2, z2;
		float xx, xy, xz;
		float yy, yz, zz;
		float wx, wy, wz;

		// ADD test to make sure that quat is normalized

		x2 = Q[x] + Q[x];
		y2 = Q[y] + Q[y];
		z2 = Q[z] + Q[z];

		xx = Q[x] * x2;
		xy = Q[x] * y2;
		xz = Q[x] * z2;

		yy = Q[y] * y2;
		yz = Q[y] * z2;
		zz = Q[z] * z2;

		wx = Q[w] * x2;
		wy = Q[w] * y2;
		wz = Q[w] * z2;

		this->_m0 = 1.0f - (yy + zz);
		this->_m1 = xy + wz;
		this->_m2 = xz - wy;
		this->_m3 = 0.0f;

		this->_m4 = xy - wz;
		this->_m5 = 1.0f - (xx + zz);
		this->_m6 = yz + wx;
		this->_m7 = 0.0f;

		this->_m8 = xz + wy;
		this->_m9 = yz - wx;
		this->_m10 = 1.0f - (xx + yy);
		this->_m11 = 0.0f;

		this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

		this->privSetRotHint();

	}

	Rot::Rot(const Orient type, const Vec3& dof, const Vec3& up)
	{
		/* make sure the DOF and VUP are not parallel */
		//MATHASSERT( gsVectDot(vect_dof, vect_vup) != 1.0f ); "gsMatDofOrient: vect_dof and vect_vup are parallel"));

		/* rz = vect_dof */
		const Vec3 rz = dof.getNorm();

		/* find rx */
		Vec3 rx = up.cross(rz);
		rx.norm();

		/* find ry */
		Vec3 ry = rz.cross(rx);
		ry.norm();

		if (type == Orient::LocalToWorld)
		{
			// For LocalToWorld, the basis vectors are columns of the matrix
			this->Mat4::set(Vec4(rx, 0), Vec4(ry, 0), Vec4(rz, 0), Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}
		else if (type == Orient::WorldToLocal)
		{
			// For WorldToLocal, the basis vectors need to be rows of the matrix (transpose of LocalToWorld)
			this->Mat4::set(Vec4(rx.x(), ry.x(), rz.x(), 0),
				Vec4(rx.y(), ry.y(), rz.y(), 0),
				Vec4(rx.z(), ry.z(), rz.z(), 0),
				Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}

		this->_m3 = 0.0f;
		this->_m7 = 0.0f;
		this->_m11 = 0.0f;
		this->_m15 = 1.0f;

		this->privSetRotHint();
	}




	////-------------------------------------------------------------------------------
	void Rot::set(const Quat& q)
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

	void Rot::set(const Rot& r)
	{
		this->_m0 = r._m0;
		this->_m1 = r._m1;
		this->_m2 = r._m2;
		this->_m3 = r._m3;
		
		this->_m4 = r._m4;
		this->_m5 = r._m5;
		this->_m6 = r._m6;
		this->_m7 = r._m7;

		this->_m8 = r._m8;
		this->_m9 = r._m9;
		this->_m10 = r._m10;
		this->_m11 = r._m11;

		this->_m12 = r._m12;
		this->_m13 = r._m13;
		this->_m14 = r._m14;
		this->_m15 = r._m15;

	}

	void Rot::set(const enum Identity_enum)
	{
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
		this->privSetRotHint();
	}


	
	void Rot::set(const Rot1 type, const float angle)
	{
		switch (type)
		{
		case Rot1::X:
			this->_m0 = 1.0f;
			this->_m1 = 0.0f;
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = cos(angle);
			this->_m6 = sin(angle);
			this->_m7 = 0.0f;
			this->_m9 = -sin(angle);
			this->_m10 = cos(angle);
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		case Rot1::Y:
			this->_m0 = cos(angle);
			this->_m1 = 0.0f;
			this->_m2 = -sin(angle);
			this->_m3 = 0.0f;
			this->_m4 = 0.0f;
			this->_m5 = 1.0f;
			this->_m6 = 0.0f;
			this->_m7 = 0.0f;
			this->_m8 = sin(angle);
			this->_m9 = 0.0f;
			this->_m10 = cos(angle);
			this->_m11 = 0.0f;
			this->_m12 = 0.0f;
			this->_m13 = 0.0f;
			this->_m14 = 0.0f;
			this->_m15 = 1.0f;
			break;
		case Rot1::Z:
			this->_m0 = cos(angle);
			this->_m1 = sin(angle);
			this->_m2 = 0.0f;
			this->_m3 = 0.0f;
			this->_m4 = -sin(angle);
			this->_m5 = cos(angle);
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
		}

		this->privSetRotHint();
	}

	void Rot::set(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2)
	{
		Mat4 r1 = {
			Vec4(1, 0, 0, 0),
			Vec4(0, cos(angle_0), sin(angle_0), 0),
			Vec4(0, -sin(angle_0), cos(angle_0), 0),
			Vec4(0, 0, 0, 1)
		};
		Mat4 r2 = {
			Vec4(cos(angle_1), 0, -sin(angle_1), 0),
			Vec4(0, 1, 0, 0),
			Vec4(sin(angle_1), 0, cos(angle_1), 0),
			Vec4(0, 0, 0, 1)
		};
		Mat4 r3 = {
			Vec4(cos(angle_2), sin(angle_2), 0, 0),
			Vec4(-sin(angle_2), cos(angle_2), 0, 0),
			Vec4(0, 0, 1, 0),
			Vec4(0, 0, 0, 1)
		};
		switch (mode)
		{
		case Rot3::XYZ:
			this->Mat4::set(r1 * r2 * r3);
			break;
		case Rot3::XZY:
			this->Mat4::set(r1 * r3 * r2);
			break;
		case Rot3::YXZ:
			this->Mat4::set(r2 * r1 * r3);
			break;
		case Rot3::YZX:
			this->Mat4::set(r2 * r3 * r1);
			break;
		case Rot3::ZXY:
			this->Mat4::set(r3 * r1 * r2);
			break;
		case Rot3::ZYX:
			this->Mat4::set(r3 * r2 * r1);
			break;
		}

		this->privSetRotHint();

	}

	void Rot::set(const Axis mode, const Vec3& vAxis, const float angle_radians)
	{
		Vec3 qV;
		if (mode == Axis::AxisAngle)
		{
			qV = vAxis.getNorm();
		}
		else
		{
			qV = vAxis;
		}

		const float angle_a = 0.5f * angle_radians;
		float cos_a;
		float sin_a;

		Trig::cossin(cos_a, sin_a, angle_a);

		qV *= sin_a;

		Vec4 Q;
		Q[x] = qV[x];
		Q[y] = qV[y];
		Q[z] = qV[z];
		Q[w] = cos_a;

		// this function has been transposed
		float x2, y2, z2;
		float xx, xy, xz;
		float yy, yz, zz;
		float wx, wy, wz;

		// ADD test to make sure that quat is normalized

		x2 = Q[x] + Q[x];
		y2 = Q[y] + Q[y];
		z2 = Q[z] + Q[z];

		xx = Q[x] * x2;
		xy = Q[x] * y2;
		xz = Q[x] * z2;

		yy = Q[y] * y2;
		yz = Q[y] * z2;
		zz = Q[z] * z2;

		wx = Q[w] * x2;
		wy = Q[w] * y2;
		wz = Q[w] * z2;

		this->_m0 = 1.0f - (yy + zz);
		this->_m1 = xy + wz;
		this->_m2 = xz - wy;
		this->_m3 = 0.0f;

		this->_m4 = xy - wz;
		this->_m5 = 1.0f - (xx + zz);
		this->_m6 = yz + wx;
		this->_m7 = 0.0f;

		this->_m8 = xz + wy;
		this->_m9 = yz - wx;
		this->_m10 = 1.0f - (xx + yy);
		this->_m11 = 0.0f;

		this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

		this->privSetRotHint();

	}

	void Rot::set(const Orient mode, const Vec3& dof, const Vec3& up)
	{
		/* make sure the DOF and VUP are not parallel */
		//MATHASSERT( gsVectDot(vect_dof, vect_vup) != 1.0f ); "gsMatDofOrient: vect_dof and vect_vup are parallel"));

		/* rz = vect_dof */
		const Vec3 rz = dof.getNorm();

		/* find rx */
		Vec3 rx = up.cross(rz);
		rx.norm();

		/* find ry */
		Vec3 ry = rz.cross(rx);
		ry.norm();

		if (mode == Orient::LocalToWorld)
		{
			// For LocalToWorld, the basis vectors are columns of the matrix
			this->Mat4::set(Vec4(rx, 0), Vec4(ry, 0), Vec4(rz, 0), Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}
		else if (mode == Orient::WorldToLocal)
		{
			// For WorldToLocal, the basis vectors need to be rows of the matrix (transpose of LocalToWorld)
			this->Mat4::set(Vec4(rx.x(), ry.x(), rz.x(), 0),
				Vec4(rx.y(), ry.y(), rz.y(), 0),
				Vec4(rx.z(), ry.z(), rz.z(), 0),
				Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}

		this->_m3 = 0.0f;
		this->_m7 = 0.0f;
		this->_m11 = 0.0f;
		this->_m15 = 1.0f;

		this->privSetRotHint();

	}

	//------------------MULTIPLY OPERATORS------------------
	Mat4 Rot::operator * (const Mat4& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 tmp;
		tmp._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8;
		tmp._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9;
		tmp._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10;
		tmp._m3 = this->_m0 * A._m3 + this->_m1 * A._m7 + this->_m2 * A._m11;

		tmp._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8;
		tmp._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9;
		tmp._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10;
		tmp._m7 = this->_m4 * A._m3 + this->_m5 * A._m7 + this->_m6 * A._m11;

		tmp._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8;
		tmp._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9;
		tmp._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10;
		tmp._m11 = this->_m8 * A._m3 + this->_m9 * A._m7 + this->_m10 * A._m11;

		tmp._m12 = this->_m12 * A._m0 + this->_m13 * A._m4 + this->_m14 * A._m8 + A._m12;
		tmp._m13 = this->_m12 * A._m1 + this->_m13 * A._m5 + this->_m14 * A._m9 + A._m13;
		tmp._m14 = this->_m12 * A._m2 + this->_m13 * A._m6 + this->_m14 * A._m10 + A._m14;
		tmp._m15 = this->_m12 * A._m3 + this->_m13 * A._m7 + this->_m14 * A._m11 + A._m15;

		tmp.privSetNewHint(hint, hintA);

		return tmp;
	}
	Mat4 Rot::operator * (const Scale& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 tmp;
		tmp._m0 = this->_m0 * A._m0;
		tmp._m1 = this->_m1 * A._m5;
		tmp._m2 = this->_m2 * A._m10;
		tmp._m3 = this->_m3;

		tmp._m4 = this->_m4 * A._m0;
		tmp._m5 = this->_m5 * A._m5;
		tmp._m6 = this->_m6 * A._m10;
		tmp._m7 = this->_m7;

		tmp._m8 = this->_m8 * A._m0;
		tmp._m9 = this->_m9 * A._m5;
		tmp._m10 = this->_m10 * A._m10;
		tmp._m11 = this->_m11;

		tmp._m12 = this->_m12;
		tmp._m13 = this->_m13;
		tmp._m14 = this->_m14;
		tmp._m15 = this->_m15;

		tmp.privSetNewHint(hint, hintA);

		return tmp;
	}

	Rot Rot::operator * (const Quat& A) const
	{
		Rot convertQuat(A);
		return *this * convertQuat;
	}
	Rot& Rot::operator *= (const Quat& A)
	{
		*this = *this * A;

		this->privSetRotHint();

		return *this;
	}


	Rot Rot::operator * (const Rot& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Rot tmp;
		tmp._m0 = this->_m0 * A._m0 + this->_m1 * A._m4 + this->_m2 * A._m8;
		tmp._m1 = this->_m0 * A._m1 + this->_m1 * A._m5 + this->_m2 * A._m9;
		tmp._m2 = this->_m0 * A._m2 + this->_m1 * A._m6 + this->_m2 * A._m10;
		tmp._m3 = 0.0f;

		tmp._m4 = this->_m4 * A._m0 + this->_m5 * A._m4 + this->_m6 * A._m8;
		tmp._m5 = this->_m4 * A._m1 + this->_m5 * A._m5 + this->_m6 * A._m9;
		tmp._m6 = this->_m4 * A._m2 + this->_m5 * A._m6 + this->_m6 * A._m10;
		tmp._m7 = 0.0f;

		tmp._m8 = this->_m8 * A._m0 + this->_m9 * A._m4 + this->_m10 * A._m8;
		tmp._m9 = this->_m8 * A._m1 + this->_m9 * A._m5 + this->_m10 * A._m9;
		tmp._m10 = this->_m8 * A._m2 + this->_m9 * A._m6 + this->_m10 * A._m10;
		tmp._m11 = 0.0f;

		tmp._m12 = 0.0f;
		tmp._m13 = 0.0f;
		tmp._m14 = 0.0f;
		tmp._m15 = 1.0f;

		tmp.privSetNewHint(hint, hintA);

		return tmp;
	}
	Rot& Rot::operator *= (const Rot& A)
	{
		*this = *this * A;

		this->privSetRotHint();

		return *this;
	}

	Mat4 Rot::operator * (const Trans& A) const
	{
		Hint hint = this->privGetHint();
		Hint hintA = A.privGetHint();

		Mat4 tmp;
		tmp._m0 = this->_m0;
		tmp._m1 = this->_m1;
		tmp._m2 = this->_m2;
		tmp._m3 = this->_m3;

		tmp._m4 = this->_m4;
		tmp._m5 = this->_m5;
		tmp._m6 = this->_m6;
		tmp._m7 = this->_m7;

		tmp._m8 = this->_m8;
		tmp._m9 = this->_m9;
		tmp._m10 = this->_m10;
		tmp._m11 = this->_m11;

		tmp._m12 = this->_m12 + A._m12;
		tmp._m13 = this->_m13 + A._m13;
		tmp._m14 = this->_m14 + A._m14;
		tmp._m15 = this->_m15;

		tmp.privSetNewHint(hint, hintA);

		return tmp;
	}


}

// ---  End of File ---
