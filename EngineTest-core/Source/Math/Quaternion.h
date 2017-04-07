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
			Quaternion(const Vector4& vector);
			Quaternion(float scalar);

			Quaternion& operator=(const Quaternion& quaternion);

			Quaternion& SetXYZ(const Vector3& vector);
			const Vector3 GetXYZ() const;

			Quaternion& SetElem(int32 index, float value);
			float GetElem(int32 index) const;
			Vector3 GetAxis() const;
			Vector3 ToEulerAngles() const;

			const Quaternion operator+(const Quaternion& quaternion) const;
			const Quaternion operator-(const Quaternion& quaternion) const;
			const Quaternion operator*(const Quaternion& quaternion) const;
			const Quaternion operator*(float scalar) const;
			const Quaternion operator/(float scalar) const;
			float operator[](int32 index) const;

			Quaternion& operator+=(const Quaternion& quaternion)
			{
				*this = *this + quaternion;
				return *this;
			}

			Quaternion& operator-=(const Quaternion& quaternion)
			{
				*this = *this - quaternion;
				return *this;
			}

			Quaternion& operator*=(const Quaternion& quaternion)
			{
				*this = *this * quaternion;
				return *this;
			}

			Quaternion& operator*=(float scalar)
			{
				*this = *this * scalar;
				return *this;
			}

			Quaternion& operator/=(float scalar)
			{
				*this = *this / scalar;
				return *this;
			}

			const Quaternion operator-() const;
			bool operator==(const Quaternion& quaternion) const;
			bool operator!=(const Quaternion& quaternion) const;
			static Quaternion Identity();
			static Quaternion FromEulerAngles(const Vector3& angles);

			static Vector3 Rotate(const Quaternion& quaternion, const Vector3& vector);

			static const Quaternion Rotation(const Vector3& unitVec0, const Vector3& unitVec1);
			static const Quaternion Rotation(float radians, const Vector3& unitVec);

			static const Quaternion RotationX(float radians)
			{
				float angle = radians * 0.5f;
				return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
			}

			static const Quaternion RotationY(float radians)
			{
				float angle = radians * 0.5f;
				return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
			}

			static const Quaternion RotationZ(float radians)
			{
				float angle = radians * 0.5f;
				return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
			}

			float Dot(const Quaternion& quaternion) const;
			Quaternion Conjugate() const;
		};
	}
}

#endif