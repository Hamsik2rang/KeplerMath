#include <iostream>
#include <cstdlib>
#include <cstdio>

#include "Math/KeplerMath.h"
#include "Timer.h"

using namespace kepler;

int main(int argc, char** argv)
{
	Quaternion q0 = Quaternion::FromAxisAngle({ 1.0f, 0.0f, 0.0f }, 30.0f);
	Quaternion q1 = Quaternion::FromAxisAngle({ 0.0f, 1.0f, 0.0f }, 60.0f);
	
	auto qt0 = math::Slerp(q0, q1, 0.0f);
	auto qt1 = math::Slerp(q0, q1, 0.2f);
	auto qt2 = math::Slerp(q0, q1, 0.4f);
	auto qt3 = math::Slerp(q0, q1, 0.6f);
	auto qt4 = math::Slerp(q0, q1, 0.8f);
	auto qt5 = math::Slerp(q0, q1, 1.0f);

	::getchar();

	return 0;
}