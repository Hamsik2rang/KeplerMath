#include <cstdlib>
#include <cstdio>
#include <intrin.h>

#include "Math/Vector.h"
#include "VectorTemplate.hpp"
#include "Timer.h"

using namespace kepler;

int main(int argc, char** argv)
{
	Vector3 v1 = { 3.0f, 4.2f, 3.8f };
	Vector3 v2 = { 1.8f, 7.3f, 2.2f };

	float v1len = v1.SqLength();
	float v2len = v2.SqLength();
	float sqlenSum = v1len + v2len;

	printf("%f\n", sqlenSum);
	printf("%f", 3.0f * 3.0f + 4.2f * 4.2f + 3.8f * 3.8f + 1.8f * 1.8f + 7.3f * 7.3f + 2.2f * 2.2f);

	return 0;
}