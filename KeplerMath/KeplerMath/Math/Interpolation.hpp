#pragma once

#include <intrin.h>

#include "Base.h"
#include "Vector4.hpp"

namespace kepler {
	namespace math {
	
		Vector4 Lerp(Vector4 s, Vector4 elem, float t)
		{
			Vector4 result;
			result.ps = _mm_add_ps(_mm_mul_ps(s.ps, _mm_set_ps1(1.0f - t)), _mm_mul_ps(elem.ps, _mm_set_ps1(t)));
			
			return result;
		}


	}
}