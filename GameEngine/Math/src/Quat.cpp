//-----------------------------------------------------------------------------
// copyright 2025, jessa gillespie, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

	//--------------------CONSTRUCTORS--------------------
	Quat::Quat(void) 
	{
		this->_qx = 0.0f;
		this->_qy = 0.0f;
		this->_qz = 0.0f;
		this->_qw = 1.0f;
	}

	Quat::Quat(const Quat& qIn) 
	{
		this->_qx = qIn._qx;
		this->_qy = qIn._qy;
		this->_qz = qIn._qz;
		this->_qw = qIn._qw;
	}

	Quat::Quat(const Vec3& vect, const float real) 
	{
		this->_qx = vect.x();
		this->_qy = vect.y();
		this->_qz = vect.z();
		this->_qw = real;
	}

	Quat::Quat(const float vx, const float vy, const float vz, const float real) 
	{
		this->_qx = vx;
		this->_qy = vy;
		this->_qz = vz;
		this->_qw = real;
	}

	Quat::Quat(const enum Identity_enum) 
	{
		this->_qx = 0.0f;
		this->_qy = 0.0f;
		this->_qz = 0.0f;
		this->_qw = 1.0f;
	}

	Quat::Quat(const Rot& r) 
	{
		float tr = r._m0 + r._m5 + r._m10;
		float s;

		if (tr > 0.0f)
		{
			s = 2 * sqrtf(tr + 1.0f);
			this->_qw = 0.25f * s;
			this->_qx = -(r._m9 - r._m6) / s;
			this->_qy = -(r._m2 - r._m8) / s;
			this->_qz = -(r._m4 - r._m1) / s;
		}
		else if ((r._m0 > r._m5) && (r._m0 > r._m10))
		{
			s = 2 * sqrtf(1.0f + r._m0 - r._m5 - r._m10);
			this->_qw = -(r._m9 - r._m6) / s;
			this->_qx = 0.25f * s;
			this->_qy = (r._m1 + r._m4) / s;
			this->_qz = (r._m2 + r._m8) / s;
		}
		else if (r._m5 > r._m10)
		{
			s = 2 * sqrtf(1.0f + r._m5 - r._m0 - r._m10);
			this->_qw = -(r._m2 - r._m8) / s;
			this->_qx = (r._m1 + r._m4) / s;
			this->_qy = 0.25f * s;
			this->_qz = (r._m6 + r._m9) / s;
		}
		else
		{
			s = 2 * sqrtf(1.0f + r._m10 - r._m0 - r._m5);
			this->_qw = -(r._m4 - r._m1) / s;
			this->_qx = (r._m2 + r._m8) / s;
			this->_qy = (r._m6 + r._m9) / s;
			this->_qz = 0.25f * s;
		}
	}

	Quat::Quat(const Rot1 type, const float angle) 
	{
		float halfAngle = angle * 0.5f;
		float s = sinf(halfAngle);
		float c = cosf(halfAngle);

		switch (type)
		{
		case Rot1::X:
			this->_qw = c;
			this->_qx = s;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			break;
		case Rot1::Y:
			this->_qw = c;
			this->_qx = 0.0f;
			this->_qy = s;
			this->_qz = 0.0f;
			break;
		case Rot1::Z:
			this->_qw = c;
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = s;
			break;
		}
	}

	Quat::Quat(const Rot3 type, const float angle_x, const float angle_y, const float angle_z) 
	{
		float half_x = 0.5f * angle_x;
		float half_y = 0.5f * angle_y;
		float half_z = 0.5f * angle_z;

		float cos_x = cosf(half_x);
		float sin_x = sinf(half_x);
		float cos_y = cosf(half_y);
		float sin_y = sinf(half_y);
		float cos_z = cosf(half_z);
		float sin_z = sinf(half_z);

		Quat qx(sin_x, 0.0f, 0.0f, cos_x); 
		Quat qy(0.0f, sin_y, 0.0f, cos_y); 
		Quat qz(0.0f, 0.0f, sin_z, cos_z); 

		Quat result;

		switch (type)
		{
		case Rot3::XYZ:
			result = qx * qy * qz;  // X -> Y -> Z
			break;
		case Rot3::XZY:
			result = qx * qz * qy;  // X -> Z -> Y
			break;
		case Rot3::YXZ:
			result = qy * qx * qz;  // Y -> X -> Z
			break;
		case Rot3::YZX:
			result = qy * qz * qx;  // Y -> Z -> X
			break;
		case Rot3::ZXY:
			result = qz * qx * qy;  // Z -> X -> Y
			break;
		case Rot3::ZYX:
			result = qz * qy * qx;  // Z -> Y -> X
			break;
		default:
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			this->_qw = 1.0f;
			return;
		}

		this->_qx = result._qx;
		this->_qy = result._qy;
		this->_qz = result._qz;
		this->_qw = result._qw;

	}

	Quat::Quat(const Axis type, const Vec3& vAxis, const float angle_radians) 
	{
		float half_angle = 0.5f * angle_radians;
		float sin_half_angle = sinf(half_angle);

		Vec3 normAxis = vAxis;
		normAxis.norm();

		this->_qx = normAxis.x() * sin_half_angle;
		this->_qy = normAxis.y() * sin_half_angle;
		this->_qz = normAxis.z() * sin_half_angle;
		this->_qw = cosf(half_angle);
	}

	Quat::Quat(const Orient type, const Vec3& dof, const Vec3& up) 
	{
		float dotProduct = dof.dot(up);
		if (fabsf(dotProduct) > 0.9999f)
		{
			Vec3 adjustedUp = up + Vec3(0.01f, 0.01f, 0.01f); 
			adjustedUp.norm(); 
		}

		Vec3 rz = dof.getNorm();      // Normalized DOF vector (forward)
		Vec3 rx = up.cross(rz);       // Right vector, orthogonal to DOF and UP
		rx.norm();                    // Normalize the right vector
		Vec3 ry = rz.cross(rx);       // Corrected up vector
		ry.norm();                    // Normalize the corrected up vector

		Rot rotMatrix;
		if (type == Orient::LocalToWorld)
		{
			rotMatrix._m0 = rx.x(); 
			rotMatrix._m1 = rx.y(); 
			rotMatrix._m2 = rx.z(); 
			rotMatrix._m3 = 0.0f;   

			rotMatrix._m4 = ry.x(); 
			rotMatrix._m5 = ry.y(); 
			rotMatrix._m6 = ry.z(); 
			rotMatrix._m7 = 0.0f;   

			rotMatrix._m8 = rz.x(); 
			rotMatrix._m9 = rz.y(); 
			rotMatrix._m10 = rz.z();
			rotMatrix._m11 = 0.0f;  

			rotMatrix._m12 = 0.0f;  
			rotMatrix._m13 = 0.0f;  
			rotMatrix._m14 = 0.0f;  
			rotMatrix._m15 = 1.0f;  
		}
		else if (type == Orient::WorldToLocal)
		{
			rotMatrix._m0 = rx.x();  
			rotMatrix._m1 = ry.x();  
			rotMatrix._m2 = rz.x();  
			rotMatrix._m3 = 0.0f;    

			rotMatrix._m4 = rx.y();  
			rotMatrix._m5 = ry.y();  
			rotMatrix._m6 = rz.y();  
			rotMatrix._m7 = 0.0f;    

			rotMatrix._m8 = rx.z();  
			rotMatrix._m9 = ry.z();  
			rotMatrix._m10 = rz.z(); 
			rotMatrix._m11 = 0.0f;   

			rotMatrix._m12 = 0.0f;   
			rotMatrix._m13 = 0.0f;   
			rotMatrix._m14 = 0.0f;   
			rotMatrix._m15 = 1.0f;   
		}

		*this = Quat(rotMatrix);  
	}

	Quat::~Quat(void) {}


	//--------------------SETTERS--------------------
	void Quat::set(const enum Identity_enum)
	{
		this->_qx = 0.0f;
		this->_qy = 0.0f;
		this->_qz = 0.0f;
		this->_qw = 1.0f;
	}

	void Quat::set(const Rot& r)
	{
		float tr = r._m0 + r._m5 + r._m10;
		float s;

		if (tr > 0.0f)
		{
			s = 2 * sqrtf(tr + 1.0f);
			this->_qw = 0.25f * s;
			this->_qx = -(r._m9 - r._m6) / s;
			this->_qy = -(r._m2 - r._m8) / s;
			this->_qz = -(r._m4 - r._m1) / s;
		}
		else if ((r._m0 > r._m5) && (r._m0 > r._m10))
		{
			s = 2 * sqrtf(1.0f + r._m0 - r._m5 - r._m10);
			this->_qw = -(r._m9 - r._m6) / s;
			this->_qx = 0.25f * s;
			this->_qy = (r._m1 + r._m4) / s;
			this->_qz = (r._m2 + r._m8) / s;
		}
		else if (r._m5 > r._m10)
		{
			s = 2 * sqrtf(1.0f + r._m5 - r._m0 - r._m10);
			this->_qw = -(r._m2 - r._m8) / s;
			this->_qx = (r._m1 + r._m4) / s;
			this->_qy = 0.25f * s;
			this->_qz = (r._m6 + r._m9) / s;
		}
		else
		{
			s = 2 * sqrtf(1.0f + r._m10 - r._m0 - r._m5);
			this->_qw = -(r._m4 - r._m1) / s;
			this->_qx = (r._m2 + r._m8) / s;
			this->_qy = (r._m6 + r._m9) / s;
			this->_qz = 0.25f * s;
		}
	}

	void Quat::set(const Rot1 type, const float angle)
	{
		float halfAngle = angle * 0.5f;
		float s = sinf(halfAngle);
		float c = cosf(halfAngle);

		switch (type)
		{
		case Rot1::X:
			this->_qw = c;
			this->_qx = s;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			break;
		case Rot1::Y:
			this->_qw = c;
			this->_qx = 0.0f;
			this->_qy = s;
			this->_qz = 0.0f;
			break;
		case Rot1::Z:
			this->_qw = c;
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = s;
			break;
		}
	}

	void Quat::set(const Rot3 type, const float angle_x, const float angle_y, const float angle_z)
	{
		float half_x = 0.5f * angle_x;
		float half_y = 0.5f * angle_y;
		float half_z = 0.5f * angle_z;

		float cos_x = cosf(half_x);
		float sin_x = sinf(half_x);
		float cos_y = cosf(half_y);
		float sin_y = sinf(half_y);
		float cos_z = cosf(half_z);
		float sin_z = sinf(half_z);

		Quat qx(sin_x, 0.0f, 0.0f, cos_x);
		Quat qy(0.0f, sin_y, 0.0f, cos_y);
		Quat qz(0.0f, 0.0f, sin_z, cos_z);

		Quat result;

		switch (type)
		{
		case Rot3::XYZ:
			result = qx * qy * qz;  // X -> Y -> Z
			break;
		case Rot3::XZY:
			result = qx * qz * qy;  // X -> Z -> Y
			break;
		case Rot3::YXZ:
			result = qy * qx * qz;  // Y -> X -> Z
			break;
		case Rot3::YZX:
			result = qy * qz * qx;  // Y -> Z -> X
			break;
		case Rot3::ZXY:
			result = qz * qx * qy;  // Z -> X -> Y
			break;
		case Rot3::ZYX:
			result = qz * qy * qx;  // Z -> Y -> X
			break;
		default:
			this->_qx = 0.0f;
			this->_qy = 0.0f;
			this->_qz = 0.0f;
			this->_qw = 1.0f;
			return;
		}

		this->_qx = result._qx;
		this->_qy = result._qy;
		this->_qz = result._qz;
		this->_qw = result._qw;
	}

	void Quat::set(const Axis type, const Vec3& vAxis, const float angle_radians)
	{
		float half_angle = 0.5f * angle_radians;
		float sin_half_angle = sinf(half_angle);

		Vec3 normAxis = vAxis;
		normAxis.norm();

		this->_qx = normAxis.x() * sin_half_angle;
		this->_qy = normAxis.y() * sin_half_angle;
		this->_qz = normAxis.z() * sin_half_angle;
		this->_qw = cosf(half_angle);
	}

	void Quat::set(const Orient type, const Vec3& dof, const Vec3& up)
	{
		float dotProduct = dof.dot(up);
		if (fabsf(dotProduct) > 0.9999f)
		{
			Vec3 adjustedUp = up + Vec3(0.01f, 0.01f, 0.01f);
			adjustedUp.norm();
		}

		Vec3 rz = dof.getNorm();      // Normalized DOF vector (forward)
		Vec3 rx = up.cross(rz);       // Right vector, orthogonal to DOF and UP
		rx.norm();                    // Normalize the right vector
		Vec3 ry = rz.cross(rx);       // Corrected up vector
		ry.norm();                    // Normalize the corrected up vector

		Rot rotMatrix;
		if (type == Orient::LocalToWorld)
		{
			rotMatrix._m0 = rx.x();
			rotMatrix._m1 = rx.y();
			rotMatrix._m2 = rx.z();
			rotMatrix._m3 = 0.0f;

			rotMatrix._m4 = ry.x();
			rotMatrix._m5 = ry.y();
			rotMatrix._m6 = ry.z();
			rotMatrix._m7 = 0.0f;

			rotMatrix._m8 = rz.x();
			rotMatrix._m9 = rz.y();
			rotMatrix._m10 = rz.z();
			rotMatrix._m11 = 0.0f;

			rotMatrix._m12 = 0.0f;
			rotMatrix._m13 = 0.0f;
			rotMatrix._m14 = 0.0f;
			rotMatrix._m15 = 1.0f;
		}
		else if (type == Orient::WorldToLocal)
		{
			rotMatrix._m0 = rx.x();
			rotMatrix._m1 = ry.x();
			rotMatrix._m2 = rz.x();
			rotMatrix._m3 = 0.0f;

			rotMatrix._m4 = rx.y();
			rotMatrix._m5 = ry.y();
			rotMatrix._m6 = rz.y();
			rotMatrix._m7 = 0.0f;

			rotMatrix._m8 = rx.z();
			rotMatrix._m9 = ry.z();
			rotMatrix._m10 = rz.z();
			rotMatrix._m11 = 0.0f;

			rotMatrix._m12 = 0.0f;
			rotMatrix._m13 = 0.0f;
			rotMatrix._m14 = 0.0f;
			rotMatrix._m15 = 1.0f;
		}

		*this = Quat(rotMatrix);
	}

	void Quat::set(const float vx, const float vy, const float vz, const float real)
	{
		this->_qx = vx;
		this->_qy = vy;
		this->_qz = vz;
		this->_qw = real;
	}

	float& Quat::operator[](const x_enum value) { return this->_qx; }
	float& Quat::operator[](const y_enum value) { return this->_qy; }
	float& Quat::operator[](const z_enum value) { return this->_qz; }
	float& Quat::operator[](const w_enum value) { return this->_qw; }

	void Quat::qx(const float x) { this->_qx = x; }
	void Quat::qy(const float y) { this->_qy = y; }
	void Quat::qz(const float z) { this->_qz = z; }
	void Quat::real(const float w) { this->_qw = w; }

	void Quat::setVec3(const Vec3& vect) { this->_qx = vect.x(); this->_qy = vect.y(); this->_qz = vect.z(); }
	void Quat::set(const Vec3& vect, const float real) { this->_qx = vect.x(); this->_qy = vect.y(); this->_qz = vect.z(); this->_qw = real; }


	//--------------------GETTERS--------------------
	float Quat::operator[](const x_enum value) const { return this->_qx; }
	float Quat::operator[](const y_enum value) const { return this->_qy; }
	float Quat::operator[](const z_enum value) const { return this->_qz; }
	float Quat::operator[](const w_enum value) const { return this->_qw; }

	float Quat::qx()const { return this->_qx; }
	float Quat::qy()const { return this->_qy; }
	float Quat::qz()const { return this->_qz; }
	float Quat::real()const { return this->_qw; }

	float Quat::getAngle(void) const { return 2.0f * acosf(this->_qw); }
	void Quat::getVec3(Vec3& vOut) const { vOut.set(this->_qx, this->_qy, this->_qz); }
	void Quat::getAxis(Vec3& vOut) const { vOut.set(this->_qx, this->_qy, this->_qz); vOut.norm(); }


	//--------------------FUNCTIONS--------------------

	//--------------------DOT PRODUCT OF QUATS--------------------
	float Quat::dot(const Quat& qin) const
	{
		return (this->_qx * qin._qx) + (this->_qy * qin._qy) + (this->_qz * qin._qz) + (this->_qw * qin._qw);
	}

	//--------------------MAGNITUDE OF QUATS--------------------
	float Quat::mag(void) const
	{
		return sqrtf(this->magSquared());
	}

	//--------------------MAGNITUDE SQUARED OF QUATS--------------------
	//(Remember for Unit Quats, magSquared == 1.0f );
	float Quat::magSquared(void) const
	{
		return (this->_qx * this->_qx) + (this->_qy * this->_qy) + (this->_qz * this->_qz) + (this->_qw * this->_qw);
	}
	float Quat::invMag(void) const
	{
		return 1.0f / this->mag();
	}

	//--------------------CONJUGATE QUAT OPERATIONS--------------------
	Quat& Quat::conj(void)
	{
		this->_qx = -this->_qx;
		this->_qy = -this->_qy;
		this->_qz = -this->_qz;

		return *this;
	}
	Quat Quat::getConj(void) const
	{
		return Quat(-this->_qx, -this->_qy, -this->_qz, this->_qw);
	}

	//--------------------INVERSE QUAT OPERATIONS--------------------
	Quat& Quat::inv(void)
	{
		float invMag = this->invMag();
		this->_qx = -this->_qx * invMag;
		this->_qy = -this->_qy * invMag;
		this->_qz = -this->_qz * invMag;
		this->_qw = this->_qw * invMag;

		return *this;
	}
	Quat Quat::getInv(void) const
	{
		float invMag = this->invMag();
		return Quat(-this->_qx * invMag, -this->_qy * invMag, -this->_qz * invMag, this->_qw * invMag);
	}

	//--------------------NORMALIZE QUAT OPERATIONS--------------------
	Quat& Quat::norm(void)
	{
		float invMag = this->invMag();
		this->_qx *= invMag;
		this->_qy *= invMag;
		this->_qz *= invMag;
		this->_qw *= invMag;

		return *this;
	}
	Quat Quat::getNorm(void) const
	{
		float invMag = this->invMag();
		return Quat(this->_qx * invMag, this->_qy * invMag, this->_qz * invMag, this->_qw * invMag);
	}

	//--------------------LINEAR OPERATIONS--------------------
	//Linear Operator 
	//vout = Quat * Vector * Quat(conjugate)
	//vOut = Quat * vIn * Quat.conj()
	void Quat::Lqvqc(const Vec3& vIn, Vec3& vOut) const
	{
		Quat temp = Quat(vIn, 0.0f);
		Quat conj = this->getConj();

		Quat temp2 = *this * temp;
		temp = temp2 * conj;

		vOut.set(temp._qx, temp._qy, temp._qz);
	}

	//Linear Operator  
	//vOut = Quat(conjugate) * Vector * Quat
	//vOut = Quat.conj() * vIn * Quat		
	void Quat::Lqcvq(const Vec3& vIn, Vec3& vOut) const
	{
		Quat temp = Quat(vIn, 0.0f);
		Quat conj = this->getConj();

		Quat temp2 = conj * temp;
		temp = temp2 * *this;

		vOut.set(temp._qx, temp._qy, temp._qz);
	}

	//--------------------TEST OPERATIONS--------------------
	bool Quat::isEqual(const Quat& qin, const float epsilon) const
	{
		return (fabsf(this->_qx - qin._qx) < epsilon) &&
			(fabsf(this->_qy - qin._qy) < epsilon) &&
			(fabsf(this->_qz - qin._qz) < epsilon) &&
			(fabsf(this->_qw - qin._qw) < epsilon);
	}
	bool Quat::isEquivalent(const Quat& qin, const float epsilon) const
	{
		return this->isEqual(qin, epsilon) || this->isNegEqual(qin, epsilon);
	}
	bool Quat::isNegEqual(const Quat& qin, const float epsilon) const
	{
		return (fabsf(this->_qx + qin._qx) < epsilon) &&
			(fabsf(this->_qy + qin._qy) < epsilon) &&
			(fabsf(this->_qz + qin._qz) < epsilon) &&
			(fabsf(this->_qw + qin._qw) < epsilon);
	}
	bool Quat::isConjugateEqual(const Quat& qin, const float epsilon) const
	{
		return (fabsf(this->_qx + qin._qx) < epsilon) &&
			(fabsf(this->_qy + qin._qy) < epsilon) &&
			(fabsf(this->_qz + qin._qz) < epsilon) &&
			(fabsf(this->_qw - qin._qw) < epsilon);
	}

	bool Quat::isIdentity(const float epsilon) const
	{
		return (fabsf(this->_qx) < epsilon) &&
			(fabsf(this->_qy) < epsilon) &&
			(fabsf(this->_qz) < epsilon) &&
			(fabsf(this->_qw - 1.0f) < epsilon);
	}
	bool Quat::isNormalized(const float epsilon) const
	{
		return fabsf(this->magSquared() - 1.0f) < epsilon;
	}


	//--------------------OVERLOAD EQUALS--------------------
	Quat& Quat::operator=(const Quat& q)
	{
		this->_qx = q._qx;
		this->_qy = q._qy;
		this->_qz = q._qz;
		this->_qw = q._qw;

		return *this;
	}
	Quat& Quat::operator=(const Rot& m)
	{
		this->set(m);
		return *this;
	}


	//--------------------OVERLOAD ADDITION--------------------
	Quat Quat::operator+(void) const
	{
		return *this;
	}

	Quat Quat::operator+(const Quat& q) const
	{
		return Quat(this->_qx + q._qx, this->_qy + q._qy, this->_qz + q._qz, this->_qw + q._qw);
	}

	Quat& Quat::operator+=(const Quat& q)
	{
		this->_qx += q._qx;
		this->_qy += q._qy;
		this->_qz += q._qz;
		this->_qw += q._qw;

		return *this;
	}

	Quat Quat::operator+(const float a) const
	{
		return Quat(this->_qx + a, this->_qy + a, this->_qz + a, this->_qw + a);
	}

	Quat& Quat::operator+=(const float a)
	{
		this->_qx += a;
		this->_qy += a;
		this->_qz += a;
		this->_qw += a;
		return *this;
	}

	Quat operator+(const float a, const Quat& q)
	{
		return Quat(q._qx + a, q._qy + a, q._qz + a, q._qw + a);
	}


	//--------------------OVERLOAD SUBTRACTION--------------------
	Quat Quat::operator-(void) const
	{
		return Quat(-this->_qx, -this->_qy, -this->_qz, -this->_qw);
	}

	Quat Quat::operator-(const Quat& q) const
	{
		return Quat(this->_qx - q._qx,
			this->_qy - q._qy,
			this->_qz - q._qz,
			this->_qw - q._qw);
	}

	Quat& Quat::operator-=(const Quat& q)
	{
		this->_qx -= q._qx;
		this->_qy -= q._qy;
		this->_qz -= q._qz;
		this->_qw -= q._qw;

		return *this;
	}

	Quat Quat::operator-(const float a) const
	{
		return Quat(this->_qx - a, this->_qy - a, this->_qz - a, this->_qw - a);
	}

	Quat& Quat::operator-=(const float a)
	{
		this->_qx -= a;
		this->_qy -= a;
		this->_qz -= a;
		this->_qw -= a;
		return *this;
	}

	Quat operator-(const float a, const Quat& q)
	{
		return Quat(a - q._qx, a - q._qy, a - q._qz, a - q._qw);
	}


	//--------------------OVERLOAD MULTIPLICATION--------------------
	Quat Quat::operator*(const float a) const
	{
		return Quat(this->_qx * a, this->_qy * a, this->_qz * a, this->_qw * a);
	}

	Quat& Quat::operator*=(const float a)
	{
		this->_qx *= a;
		this->_qy *= a;
		this->_qz *= a;
		this->_qw *= a;

		return *this;
	}

	Quat operator*(const float a, const Quat& q)
	{
		return Quat(q._qx * a, q._qy * a, q._qz * a, q._qw * a);
	}

	Mat4 Quat::operator*(const Mat4& m) const
	{
		Mat4 rotMatrix = Mat4(*this); 
		return rotMatrix * m;
	}

	Quat Quat::operator*(const Quat& q) const
	{
		Vec3 p_v(this->_qx, this->_qy, this->_qz);
		Vec3 q_v(q._qx, q._qy, q._qz);

		float new_w = this->_qw * q._qw - p_v.dot(q_v);

		Vec3 new_v = (q_v.cross(p_v)) + (q_v * this->_qw) + (p_v * q._qw);

		return Quat(new_v.x(), new_v.y(), new_v.z(), new_w);
	}

	Quat& Quat::operator*=(const Quat& q)
	{
		*this = *this * q;
		return *this;
	}

	Mat4 Quat::operator*(const Scale& m) const
	{
		Mat4 rotationMatrix = Mat4(*this); 
		return rotationMatrix * m;
	}

	Quat& Quat::operator*=(const Rot& m)
	{
		Quat rotQuat(m);
		*this = *this * rotQuat;
		return *this;
	}

	Rot Quat::operator*(const Rot& m) const
	{
		Quat rotQuat(m); 
		Quat result = *this * rotQuat;
		Rot resultRot = Rot(result);

		return resultRot;
	}

	Mat4 Quat::operator*(const Trans& m) const
	{
		Mat4 rotationMatrix = Mat4(*this);
		return rotationMatrix * m;
	}


	//--------------------OVERLOAD DIVISION--------------------
	Quat Quat::operator/(const Quat& q) const
	{
		Quat temp;
		temp._qx = this->_qx * (1 / q._qx);
		temp._qy = this->_qy * (1 / q._qy);
		temp._qz = this->_qz * (1 / q._qz);
		temp._qw = this->_qw * (1 / q._qw);

		return temp;
	}

	Quat& Quat::operator/=(const Quat& q)
	{
		*this = *this / q;
		return *this;
	}

	Quat Quat::operator/(const float a) const
	{
		float invA = 1.0f / a;
		return Quat(this->_qx * invA, this->_qy * invA, this->_qz * invA, this->_qw * invA);
	}

	Quat& Quat::operator/=(const float a)
	{
		float invA = 1.0f / a;
		this->_qx *= invA;
		this->_qy *= invA;
		this->_qz *= invA;
		this->_qw *= invA;

		return *this;
	}

	Quat operator/(const float a, const Quat& q)
	{
		return Quat(a / q._qx, a / q._qy, a / q._qz, a / q._qw);
	}

	//--------------------PRINTING--------------------	
	void Quat::Print(const char* pName) const
	{
		printf("%s: %f %f %f %f\n", pName, this->_qx, this->_qy, this->_qz, this->_qw);
	}

}

//--- End of File ---
