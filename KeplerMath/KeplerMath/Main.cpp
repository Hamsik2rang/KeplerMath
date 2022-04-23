#include <cstdlib>
#include <cstdio>

#include "VectorSIMD.hpp"
#include "VectorTemplate.hpp"
#include "Timer.h"

int main(int argc, char** argv)
{
	//{
	//	SIMD::Vec4f a{ 1.0f, 0.0f, 1.0f, 0.0f };
	//	SIMD::Vec4f b{ 1.0f, 1.0f, 1.0f, 0.0f };
	//	SIMD::Vec4f c{ 1.0f, 0.0f, 1.0f, 1.0f };
	//	
	//	printf("%f %f", c.SqLength(), c.Length());
	//
	//	Dot(a, b);
	//}
	

	SIMD::Vec4f a{ 1.0f, 1.0f, 1.0f, 1.0f };
	auto b = a.Normalize();
	printf("%f %f %f %f", b.x, b.y, b.z, b.w);

	//{
	//	SIMD::Vec4i v1{ 1,3,5,7 };
	//	printf("%d", sizeof(v1));

	//	SIMD::Vec4i v2{ 7, 5, 3, 1 };

	//	SIMD::Vec4i v3 = v1 + v2;
	//}

	//{
	//	
	//	Template::Vec4f vt1{ 1.0f,3.0f,5.0f,7.0f };
	//	printf("%d", sizeof(vt1));
	//	Template::Vec4f vt2{ 7.0f,5.0f,3.0f,1.0f };

	//	Template::Vec4f vt3 = vt1 + vt2;
	//}



	return 0;
}