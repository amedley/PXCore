#ifndef VECTOR3_H
#define VECTOR3_H

#include "../Common.h"

namespace EngineTest { namespace Math {
	struct Vector2;
	struct Vector4;
	struct Matrix4;

	struct Vector3
	{
		float _x, _y, _z;
		Vector3();
		Vector3(float scalar);
		Vector3(float x, float y, float z);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
		Vector3(const Vector4& vector);

		static Vector3 Up();
		static Vector3 Down();
		static Vector3 Left();
		static Vector3 Right();
		static Vector3 Zero();

		static Vector3 XAxis();
		static Vector3 YAxis();
		static Vector3 ZAxis();

		float Magnitude() const;
		float Distance(const Vector3& vector) const;
		float Dot(const Vector3& vector) const;

		Vector3& operator=(const Vector3& vector);

		Vector3 Cross(const Vector3& vector) const;
		Vector3& CrossEquals(const Vector3& vector);

		Vector3 Normalize() const;
		Vector3& NormalizeEquals();

		Vector3 Multiply(const Matrix4& transform) const;

		Vector3 operator+(const Vector3& vector) const;
		Vector3 operator+(float val) const;
		Vector3& operator+=(const Vector3& vector);
		Vector3& operator+=(float val);

		Vector3 operator-(const Vector3& vector) const;
		Vector3 operator-(float val) const;
		Vector3& operator-=(const Vector3& vector);
		Vector3& operator-=(float val);

		Vector3 operator*(const Vector3& vector) const;
		Vector3 operator*(float val) const;
		Vector3& operator*=(const Vector3& vector);
		Vector3& operator*=(float val);

		Vector3 operator/(const Vector3& vector) const;
		Vector3 operator/(float val) const;
		Vector3& operator/=(const Vector3& vector);
		Vector3& operator/=(float val);

		bool operator==(const Vector3& vector) const;
		bool operator==(float val) const;
		bool operator!=(const Vector3& vector) const;
		bool operator!=(float val) const;
		bool operator>=(const Vector3& vector) const;
		bool operator>=(float val) const;
		bool operator>(const Vector3& vector) const;
		bool operator>(float val) const;
		bool operator<=(const Vector3& vector) const;
		bool operator<=(float val) const;
		bool operator<(const Vector3& vector) const;
		bool operator<(float val) const;

		friend Vector3 operator-(const Vector3& vector);

		String ToString() const;
	};
}}

#endif VECTOR3_H