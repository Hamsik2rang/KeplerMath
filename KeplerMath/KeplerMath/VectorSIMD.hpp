#pragma once

#include <intrin.h>
#include <stdint.h>

namespace SIMD {
	
	struct Vector4;
	struct Vector4Int;

	using Vec4f = Vector4;
	using Vec4i = Vector4Int;

	struct alignas(16) Vector4
	{
		union
		{
			struct { float x; float y; float z; float w; };
			struct { float r; float g; float b; float a; };
			float e[4];
			__m128 ps;
		};

		Vector4()
			:e{ 0,0,0,0 }
		{}

		Vector4(float _x, float _y, float _z, float _w)
			:x{_x}
			,y{_y}
			,z{_z}
			,w{_w}
		{}

		Vector4(__m128 m)
			:ps{ m }
		{}

		Vector4(const Vector4& v) = default;
		Vector4(Vector4&& v) = default;

		__forceinline const float SqLength() const
		{
			__m128 result = _mm_mul_ps(ps, ps);
			result = _mm_hadd_ps(result, result);
			result = _mm_hadd_ps(result, result);

			return result.m128_f32[0];
		}

		__forceinline const float Length() const
		{
			const float sqlen = SqLength();
			__m128 result = _mm_sqrt_ps(_mm_set_ps1(sqlen));
		
			return result.m128_f32[0];
		}

		__forceinline const Vector4 Normalize() const
		{
			__m128 result = _mm_div_ps(ps, _mm_set_ps1(Length()));
			
			return result;
		}

		// Operator Overloadings
		__forceinline Vector4& operator=(const Vector4& rhs) { this->ps = rhs.ps; return *this; }
		__forceinline const Vector4 operator+() { return *this; }
		__forceinline const Vector4 operator-() { return _mm_mul_ps(ps, _mm_set1_ps(-1.0f)); }
		__forceinline float& operator[](const int index) { return e[index]; }
		__forceinline const Vector4 operator+(const Vector4& rhs) const { return _mm_add_ps(ps, rhs.ps); }
		__forceinline const Vector4 operator-(const Vector4& rhs) const { return _mm_sub_ps(ps, rhs.ps); }
		__forceinline const Vector4 operator*(const Vector4& rhs) const { return _mm_mul_ps(ps, rhs.ps); }
		__forceinline const Vector4 operator*(const float rhs) const { return _mm_mul_ps(ps, _mm_set_ps1(rhs)); }
		__forceinline const Vector4 operator/(const Vector4& rhs) const { return _mm_div_ps(ps, rhs.ps); }
		__forceinline const Vector4 operator/(const float rhs) const { return _mm_div_ps(ps, _mm_set_ps1(rhs)); }

		__forceinline Vector4& operator+=(const Vector4& rhs) { ps = _mm_add_ps(ps, rhs.ps); return *this; }
		__forceinline Vector4& operator-=(const Vector4& rhs) { ps = _mm_sub_ps(ps, rhs.ps); return *this; }
		
		inline void* operator new(size_t size) { void* p = _aligned_malloc(size, 16); return p; }
		inline void operator delete(void* p) { _aligned_free(p); }

		__forceinline friend const Vector4 operator*(const float lhs, const Vector4& rhs) { return _mm_mul_ps(rhs.ps, _mm_set_ps1(lhs)); }
		__forceinline friend const bool operator==(const Vector4& lhs, const Vector4& rhs) { return (_mm_movemask_ps(_mm_cmpeq_ps(lhs.ps, rhs.ps)) & 0b00001111) == 0b00001111; }
		__forceinline friend const bool operator!=(const Vector4& lhs, const Vector4& rhs) { return lhs != rhs; }
	};

	const float Dot(const Vector4& lhs, const Vector4& rhs)
	{
		__m128 result = _mm_mul_ps(lhs.ps, rhs.ps);
		result = _mm_hadd_ps(result, result);
		result = _mm_hadd_ps(result, result);

		return result.m128_f32[0];
	}

	struct alignas(16) Vector4Int
	{
		union
		{
			struct { int32_t x; int32_t y; int32_t z; int32_t w; };
			struct { int32_t r; int32_t g; int32_t b; int32_t a; };
			float e[4];
		};

		//...
	};
}