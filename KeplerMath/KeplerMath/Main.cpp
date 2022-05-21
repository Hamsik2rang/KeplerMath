#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <intrin.h>

#include "Math/Vector.h"
#include "VectorTemplate.hpp"
#include "Timer.h"
#include "Math/Matrix44.hpp"
#include "Math/Quaternion.h"

using namespace kepler;

int main(int argc, char** argv)
{
	Quaternion x = { ::sinf(math::DegToRad(30.0f)) * Vec3f::Right, ::cosf(math::DegToRad(30.0f)) };
	Quaternion y = { ::sinf(math::DegToRad(30.0f)) * Vec3f::Up, ::cosf(math::DegToRad(30.0f)) };
	Quaternion z = { ::sinf(math::DegToRad(30.0f)) * Vec3f::Front, ::cosf(math::DegToRad(30.0f)) };

	auto result = x * y * z;

	return 0;
}