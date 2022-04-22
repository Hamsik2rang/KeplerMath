#pragma once

#include <intrin.h>
#include <stdint.h>

namespace SIMD {
	
	struct Vector4Float;
	struct Vector4Int;

	using Vec4f = Vector4Float;
	using Vec4i = Vector4Int;

	struct alignas(16) Vector4Float
	{
		union
		{
			struct { float x; float y; float z; float w; };
			struct { float r; float g; float b; float a; };
			float e[4];
			__m128 m;
		};

		Vector4Float()
			:e{ 0,0,0,0 }
		{}

		Vector4Float(float _x, float _y, float _z, float _w)
			:x{_x}
			,y{_y}
			,z{_z}
			,w{_w}
		{}

		Vector4Float(const Vector4Float& v) = default;
		Vector4Float(Vector4Float&& v) = default;

		__forceinline Vector4Float& operator=(const Vector4Float& rhs)
		{
			/*__m128* lv = reinterpret_cast<__m128*>(this);
			const __m128* rv = reinterpret_cast<const __m128*>(&rhs);
			*lv = *rv;*/
			this->m = rhs.m;

			return *this;
		}

		__forceinline const Vector4Float operator+()
		{
			return *this;
		}

		__forceinline const Vector4Float operator-()
		{
			Vector4Float _result;
			const __m128 scalar = _mm_set1_ps(-1.0f);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			__m128* v = reinterpret_cast<__m128*>(this);
			*result = _mm_mul_ps(*v, scalar);

			return _result;
		}

		__forceinline float& operator[](const int index)
		{
			return e[index];
		}

		__forceinline const float operator[](const int index) const
		{
			return e[index];
		}

		__forceinline const Vector4Float operator+(const Vector4Float& rhs) const
		{
			Vector4Float _result;
			const __m128* lv = reinterpret_cast<const __m128*>(this);
			const __m128* rv = reinterpret_cast<const __m128*>(&rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_add_ps(*lv, *rv);

			return _result;
		}

		__forceinline const Vector4Float operator-(const Vector4Float& rhs) const
		{
			Vector4Float _result;
			const __m128* lv = reinterpret_cast<const __m128*>(this);
			const __m128* rv = reinterpret_cast<const __m128*>(&rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_sub_ps(*lv, *rv);

			return _result;
		}

		__forceinline const Vector4Float operator*(const Vector4Float& rhs) const 
		{
			Vector4Float _result;
			const __m128* lv = reinterpret_cast<const __m128*>(this);
			const __m128* rv = reinterpret_cast<const __m128*>(&rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_mul_ps(*lv, *rv);

			return _result;
		}

		__forceinline const Vector4Float operator*(const float rhs) const
		{
			Vector4Float _result;
			const __m128* v = reinterpret_cast<const __m128*>(this);
			const __m128 scalar = _mm_set_ps1(rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_mul_ps(*v, scalar);

			return _result;
		}

		__forceinline const Vector4Float operator/(const Vector4Float& rhs) const 
		{
			Vector4Float _result;
			const __m128* lv = reinterpret_cast<const __m128*>(this);
			const __m128* rv = reinterpret_cast<const __m128*>(&rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_div_ps(*lv, *rv);

			return _result;
		}

		__forceinline const Vector4Float operator/(const float rhs) const
		{
			Vector4Float _result;
			const __m128* v = reinterpret_cast<const __m128*>(this);
			const __m128 scalar = _mm_set_ps1(rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_div_ps(*v, scalar);

			return _result;
		}

		__forceinline Vector4Float& operator+=(const Vector4Float& rhs)
		{
			__m128* result = reinterpret_cast<__m128*>(this);
			const __m128* v = reinterpret_cast<const __m128*>(&rhs);

			*result = _mm_add_ps(*result, *v);

			return *this;
		}

		__forceinline Vector4Float& operator-=(const Vector4Float& rhs)
		{
			__m128* result = reinterpret_cast<__m128*>(this);
			const __m128* v = reinterpret_cast<const __m128*>(&rhs);

			*result = _mm_sub_ps(*result, *v);

			return *this;
		}

		inline void* operator new(size_t size)
		{
			void* p = _aligned_malloc(size, 16);

			return p;
		}

		inline void operator delete(void* p)
		{
			_aligned_free(p);
		}

		__forceinline friend const Vector4Float operator*(const float lhs, const Vector4Float& rhs)
		{
			Vector4Float _result;
			const __m128 scalar = _mm_set1_ps(lhs);
			const __m128* v = reinterpret_cast<const __m128*>(&rhs);
			__m128* result = reinterpret_cast<__m128*>(&_result);
			*result = _mm_mul_ps(*v, scalar);

			return _result;
		}

		__forceinline friend const bool operator==(const Vector4Float& lhs, const Vector4Float& rhs)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
		}

		__forceinline friend const bool operator!=(const Vector4Float& lhs, const Vector4Float& rhs)
		{
			return lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z || lhs.w != rhs.w;
		}
	};

	struct alignas(16) Vector4Int
	{
		union
		{
			struct { int32_t x; int32_t y; int32_t z; int32_t w; };
			struct { int32_t r; int32_t g; int32_t b; int32_t a; };
			float e[4];
		};

		__forceinline const Vector4Int operator+(const Vector4Int& v)
		{
			Vector4Int ret;
			const __m128i* lv = reinterpret_cast<const __m128i*>(this);
			const __m128i* rv = reinterpret_cast<const __m128i*>(&v);
			__m128i* result = reinterpret_cast<__m128i*>(&ret);
			*result = _mm_add_epi32(*lv, *rv);

			return ret;
		}
	};

}