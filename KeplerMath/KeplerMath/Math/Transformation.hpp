#pragma once

#include <intrin.h>

#include "Base.h"
#include "Matrix.h"
#include "Vector.h"
#include "Trigonometry.h"

namespace kepler {
	namespace math {

		const Mat44f GetTransform(const Vector3& position)
		{
			Mat44f T{
				1.0f,		0.0f,		0.0f,		0.0f,
				0.0f,		1.0f,		0.0f,		0.0f,
				0.0f,		0.0f,		1.0f,		0.0f,
				position.x, position.y, position.z, 1.0f
			};

			return T;
		}

		const Mat44f GetRotationX(const float angle)
		{
			Mat44f Rx{
				1.0f, 0.0f,				0.0f,			0.0f,
				0.0f, ::cosf(angle),	::sinf(angle),	0.0f,
				0.0f, -::sinf(angle),	cosf(angle),	0.0f,
				0.0f, 0.0f,				0.0f,			1.0f
			};

			return Rx;
		}

		const Mat44f GetRotationY(const float angle)
		{
			Mat44f Ry{
				::cosf(angle),  0.0f, -::sinf(angle),	0.0f,
				0.0f,			1.0f, 0.0f,				0.0f,
				::sinf(angle),	0.0f, ::cosf(angle),	0.0f,
				0.0f,			0.0f, 0.0f,				1.0f
			};

			return Ry;
		}

		const Mat44f GetRotationZ(const float angle)
		{
			Mat44f Rz{
				::cosf(angle),	::sinf(angle),	0.0f, 0.0f,
				-::sinf(angle),	::cosf(angle),	0.0f, 0.0f,
				0.0f,			0.0f,			1.0f, 0.0f,
				0.0f,			0.0f,			0.0f, 1.0f
			};

			return Rz;
		}

		const Mat44f GetRotation(const Vector3& rotation)
		{
			Mat44f Rx = GetRotationX(rotation.x);
			Mat44f Ry = GetRotationY(rotation.y);
			Mat44f Rz = GetRotationZ(rotation.z);

			return Rx * Ry * Rz;
		}

		const Mat44f GetScaling(const Vector3& scale)
		{
			Mat44f scaling{
				scale.x,	0.0f,		0.0f,		0.0f,
				0.0f,		scale.y,	0.0f,		0.0f,
				0.0f,		0.0f,		scale.z,	0.0f,
				0.0f,		0.0f,		0.0f,		1.0f
			};

			return scaling;
		}

		const Mat44f World(const Vector3& position, const Vector3& rotation, const Vector3& scale)
		{
			return GetScaling(scale) * GetRotation(rotation) * GetTransform(position);
		}

		const Mat44f LookAt(const Vector3& eye, const Vector3& at, const Vector3& worldUp = { 0.0f, 1.0f, 0.0f })
		{
			// Gram-Schmidt process
			Vec3f right = Cross(worldUp, at).Normalize();
			Vec3f up = Cross(at, right).Normalize();
			Vec3f front = Cross(right, up);

			Mat44f view{
				right.x,	up.x,	front.z,	0.0f,
				right.y,	up.y,	front.z,	0.0f,
				right.z,	up.z,	front.z,	0.0f,
				-eye.x,		-eye.y,	-eye.z,		1.0f
			};

			return view;
		}

		const Mat44f Perspective(const float fovY, const float aspect, const float near, const float far)
		{
			Mat44f perspective{
			1.0f / (std::tanf(DegToRad(fovY / 2.0f)) * aspect), 0.0f, 0.0f, 0.0f ,
			0.0f, 1.0f / std::tanf(DegToRad(fovY / 2.0f)), 0.0f, 0.0f ,
			0.0f, 0.0f, far / (far - near), -1.0f,
			0.0f, 0.0f, near* far / (far - near), 0.0f
			};

			return perspective;
		}

		const Mat44f Orthographic(const float left, const float right, const float top, const float bottom, const float near, const float far)
		{
			Mat44f orthographic{
				2.0f / (right - left), 0.0f, 0.0f, -(right + left) / (right - left),
				0.0f, 2.0f / (top - bottom), 0.0f, -(top + bottom) / (top - bottom),
				0.0f, 0.0f, -2.0f / (far - near),	-(far + near) / (far - near),
				0.0f, 0.0f, 0.0f, 1.0f
			};
		}
	}
}