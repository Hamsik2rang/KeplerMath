#pragma once

#include "Base.h"
#include "Vector3.hpp"

namespace kepler {

	struct Quaternion
	{
		union
		{
			struct { float x; float y; float z;  };
			float imaginary[3];
			Vec3f v;
		};
		float w;

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

		Quaternion(const float _x, const float _y, const float _z)
			: x{ _x }
			, y{ _y }
			, z{ _z }
			, w{ 1.0f }
		{}

		Quaternion(const Vector3& _v)
			: v{ _v }
			, w{ 1.0f }
		{}

		Quaternion(const Quaternion& q) = default;
		Quaternion(Quaternion&& q) = default;
		//--------------------------------------------------------
	
		// Member Functions --------------------------------------
		
		
		//--------------------------------------------------------

		// Operator Overloadings ---------------------------------
		Quaternion& operator=(const Quaternion& rhs) { v = rhs.v; w = rhs.w; return *this; }
		float& operator[](int index) { /*0 <= index < 3*/ return imaginary[index]; }
		const Quaternion operator+() const { return *this; }
		const Quaternion operator-() const { return Quaternion{ -v }; }
		//...

		//--------------------------------------------------------

		// Friend Operator Overloadings --------------------------


		//--------------------------------------------------------
	};
	// Static Variables --------------------------------------
	const Quaternion Quaternion::Identity = { 0.0f, 0.0f, 0.0f };

	//--------------------------------------------------------
}