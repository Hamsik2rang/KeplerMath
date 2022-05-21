#pragma once

#include <cmath>

#include "Base.h"
#include "Vector3.hpp"
#include "Trigonometry.h"

namespace kepler {

	struct Quaternion
	{
		float w;
		union
		{
			struct { float x; float y; float z;  };
			float img[3];
			Vec3f v;
		};

		// Static Variables --------------------------------------
		static const Quaternion Identity;
		//--------------------------------------------------------

		// Constructor -------------------------------------------
		Quaternion()
			: x{ 0.0f }
			, y{ 0.0f }
			, z{ 0.0f }
			, w{ 1.0f }
		{}

		Quaternion(const float _x, const float _y, const float _z, const float _w = 1.0f)
			: x{ _x }
			, y{ _y }
			, z{ _z }
			, w{ _w }
		{}

		Quaternion(const Vector3& _v, const float _w = 1.0f)
			: v{ _v }
			, w{ _w }
		{}

		Quaternion(const Quaternion& q) = default;
		Quaternion(Quaternion&& q) = default;
		//--------------------------------------------------------
	
		// Static Member Functions -------------------------------
		
		//--------------------------------------------------------

		// Member Functions --------------------------------------
		const float Length() const { return ::sqrtf(v.SqLength() + w * w); }
		const float SqLength() const { return v.SqLength() + w * w; }
		const Vector3 ToEuler() const 
		{
			Vector3 angle = Vec3f::Zero;
			// pitch(x-axis)
			float sycp = 2.0f * (w * x + y * z);
			float cycp = 1.0f - 2.0f * (x * x + y * y);
			angle.x = ::atan2f(sycp, cycp);

			// yaw(y-axis)
			float sp = 2 * (w * y - z * x);
			if (::fabs(sp) >= 1.0f)
			{
				angle.y = ::copysignf(math::constant::PIDIV2, sp);
			}
			else
			{
				angle.y = ::asinf(sp);
			}

			// roll(z-axis)
			float cpsr = 2.0f * (w * z + x * y);
			float cpcr = 1.0f - 2.0f * (y * y + z * z);
			angle.z = ::atan2f(cpsr, cpcr);

			return angle; 
		};
		

		//--------------------------------------------------------

		// Operator Overloadings ---------------------------------
		Quaternion& operator=(const Quaternion& rhs) { v = rhs.v; w = rhs.w; return *this; }
		const Quaternion operator+() const { return *this; }
		const Quaternion operator-() const { return Quaternion{ -v }; }

		const Quaternion operator+(const Quaternion& rhs) const { Quaternion result{ v + rhs.v, w + rhs.w }; return result; }
		const Quaternion operator-(const Quaternion& rhs) const { Quaternion result{ v - rhs.v, w + rhs.w }; return result; }
		const Quaternion operator*(const float rhs) const { Quaternion result{ v * rhs, w * rhs }; return result; }
		const Quaternion operator/(const float rhs) const { Quaternion result{ v / rhs, w / rhs }; return result; }

		const Quaternion operator*(const Quaternion& rhs) const { Quaternion result{ w * rhs.v + rhs.w * v + Cross(v, rhs.v), w * rhs.w - Dot(v, rhs.v) }; return result; }
		
		Quaternion& operator+=(const Quaternion& rhs) { v += rhs.v; w += rhs.w; return *this; }
		Quaternion& operator-=(const Quaternion& rhs) { v -= rhs.v; w -= rhs.w; return *this; }
		Quaternion& operator*=(const float rhs) { v *= rhs; w *= rhs; return *this; }

		Quaternion& operator*=(const Quaternion& rhs) { float tempW = w; w = tempW * rhs.w - Dot(v, rhs.v); v = tempW * rhs.v + rhs.w * v + Cross(v, rhs.v); return *this; }
		//--------------------------------------------------------

		// Friend Operator Overloadings --------------------------
		friend const Quaternion operator*(const float lhs, const Quaternion& rhs) { return rhs * lhs; }
		friend const bool operator==(const Quaternion& lhs, const Quaternion& rhs) { return lhs.w == rhs.w && lhs.v == rhs.v; }
		friend const bool operator!=(const Quaternion& lhs, const Quaternion& rhs) { return !(lhs == rhs); }

		//--------------------------------------------------------
	};
	// Static Variables --------------------------------------
	const Quaternion Quaternion::Identity = { 0.0f, 0.0f, 0.0f };

	//--------------------------------------------------------
}