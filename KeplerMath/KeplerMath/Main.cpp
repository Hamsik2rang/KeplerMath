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
	auto result = z * (y * x);

	Quaternion q = Quaternion::FromEuler({ 60.0f, 60.0f, 60.0f });
	auto v = q.ToEuler();

	return 0;
}