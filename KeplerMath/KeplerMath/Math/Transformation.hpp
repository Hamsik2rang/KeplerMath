#pragma once

#include <intrin.h>

#include "Base.h"
#include "Matrix.h"
#include "Vector.h"
#include "Trigonometry.h"

namespace kepler {
	namespace math {

		const Mat44f GetTransformMatrix(const Vector3& position)
		{
			Mat44f T{
				1.0f,		0.0f,		0.0f,		0.0f,
				0.0f,		1.0f,		0.0f,		0.0f,
				0.0f,		0.0f,		1.0f,		0.0f,
				position.x, position.y, position.z, 1.0f
			};

			return T;
		}

		const Mat44f GetRotationMatrix(const Vector3& rotation)
		{
			Mat44f Rx{
				1.0f, 0.0f,					0.0f,				0.0f,
				0.0f, ::cosf(rotation.x),	::sinf(rotation.x),	0.0f,
				0.0f, -::sinf(rotation.x),	cosf(rotation.x),	0.0f,
				0.0f, 0.0f,					0.0f,				1.0f
			};

			Mat44f Ry{
				::cosf(rotation.y),  0.0f, -::sinf(rotation.y), 0.0f,
				0.0f,				 1.0f, 0.0f,			    0.0f,
				::sinf(rotation.y), 0.0f, ::cosf(rotation.y),	0.0f,
				0.0f,				 0.0f, 0.0f,				1.0f
			};

			Mat44f Rz{
				::cosf(rotation.z),		::sinf(rotation.z), 0.0f, 0.0f,
				-::sinf(rotation.z),	::cosf(rotation.z), 0.0f, 0.0f,
				0.0f,					0.0f,				1.0f, 0.0f,
				0.0f,					0.0f,				0.0f, 1.0f
			};

			return Rx * Ry * Rz;
		}

		const Mat44f GetScalingMatrix(const Vector3& scale)
		{
			Mat44f scaling{
				scale.x,	0.0f,		0.0f,		0.0f,
				0.0f,		scale.y,	0.0f,		0.0f,
				0.0f,		0.0f,		scale.z,	0.0f,
				0.0f,		0.0f,		0.0f,		1.0f
			};

			return scaling;
		}

		const Mat44f WorldMatrix(const Vector3& position, const Vector3& rotation, const Vector3& scale)
		{
			return GetScalingMatrix(scale) * GetRotationMatrix(rotation) * GetTransformMatrix(position);
		}

		const Mat44f LookAt(const Vector3& eye, const Vector3& at, const Vector3& worldUp = { 0.0f, 1.0f, 0.0f })
		{
			// Gram-Schmidt process
			Vec3 right = Cross(worldUp, at).Normalize();
			Vec3 up = Cross(at, right).Normalize();
			Vec3 front = Cross(right, up);

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