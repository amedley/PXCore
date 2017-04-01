#ifndef QUATERNION_H
#define QUATERNION

#include "../Common.h"

namespace EngineTest
{
	namespace Math
	{
		struct Matrix4;
		struct Vector3;
		struct Vector4;

		struct Quaternion
		{
			float _x, _y, _z, _w;

			Quaternion();
			Quaternion(const Quaternion& quaternion);
			Quaternion(float x, float y, float z, float w);
			Quaternion(const Vector3& xyz, float w);
			Quaternion(const Vector4& xyzw);
			Quaternion(float scalar);

		};
	}
}

#endif