#pragma once

#include <intrin.h>
#include "VectorSIMD.hpp"

namespace kepler {
	namespace meth {
	
		Vector4 Lerp(Vector4 s, Vector4 e, float t)
		{
			Vector4 result;
			result.ps = _mm_add_ps(_mm_mul_ps(s.ps, _mm_set_ps1(1.0f - t)), _mm_mul_ps(e.ps, _mm_set_ps1(t)));
			
			return result;
		}

	}
}