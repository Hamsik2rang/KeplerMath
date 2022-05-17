#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <intrin.h>

#include "Math/Vector.h"
#include "VectorTemplate.hpp"
#include "Timer.h"
#include "Math/Matrix44.hpp"

using namespace kepler;

int main(int argc, char** argv)
{
	Mat44f m = {
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		-1.0f, -2.0f, -3.0f, -4.0f,
		-5.0f, -6.0f, -7.0f, -8.0f
	};

	std::cout << m << "\n";

	m = m.Transpose();
	std::cout << m << "\n";

	//std::cout << m * Mat44f::Identity;

	Vector3 v = { 1.0f, 3.0f, 5.0f };
	Vector4 v4 = v.ToAffine();


	Vector3 v3{ 2.0f,3.0f, 4.0f };

	auto t1 = v3.Length();
	auto t2 = v3.SqLength();

	return 0;
}