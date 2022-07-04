#include "Vector3.hpp"

namespace kepler {

	const Vector3 KEPLER_MATH_API Vector3::Zero		= { 0.0f, 0.0f, 0.0f };
	const Vector3 KEPLER_MATH_API Vector3::Up		= { 0.0f, 1.0f, 0.0f };
	const Vector3 KEPLER_MATH_API Vector3::Down		= { 0.0f, -1.0f, 0.0f };
	const Vector3 KEPLER_MATH_API Vector3::Right	= { 1.0f, 0.0f, 0.0f };
	const Vector3 KEPLER_MATH_API Vector3::Left		= { -1.0f, 0.0f, 0.0f };
	const Vector3 KEPLER_MATH_API Vector3::Front	= { 0.0f, 0.0f, 1.0f };
	const Vector3 KEPLER_MATH_API Vector3::Back		= { 0.0f, 0.0f, -1.0f };

}