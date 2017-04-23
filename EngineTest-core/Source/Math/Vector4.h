#ifndef VECTOR4_H
#define VECTOR4_H

#include "../Common.h"

namespace EngineTest { namespace Math {
	struct Vector2;
	struct Vector3;
	struct Matrix4;

	struct Vector4
	{
		float _x, _y, _z, _w;
		Vector4();
		Vector4(float scalar);
		Vector4(float x, float y, float z, float w);
		Vector4(const Vector2& vector);
		Vector4(const Vector3& vector);
		Vector4(const Vector3& xyz, float w);
		Vector4(const Vector4& vector);

		float Magnitude() const;
		float Distance(const Vector4& vector) const;
		float Dot(const Vector4& vector) const;

		Vector4& operator=(const Vector4& vector);

		Vector4 Normalize() const;
		Vector4& NormalizeEquals();

		Vector4 Multiply(const Matrix4& transform) const;

		Vector4 operator+(const Vector4& vector) const;
		Vector4 operator+(float val) const;
		Vector4& operator+=(const Vector4& vector);
		Vector4& operator+=(float val);

		Vector4 operator-(const Vector4& vector) const;
		Vector4 operator-(float val) const;
		Vector4& operator-=(const Vector4& vector);
		Vector4& operator-=(float val);

		Vector4 operator*(const Vector4& vector) const;
		Vector4 operator*(float val) const;
		Vector4& operator*=(const Vector4& vector);
		Vector4& operator*=(float val);

		Vector4 operator/(const Vector4& vector) const;
		Vector4 operator/(float val) const;
		Vector4& operator/=(const Vector4& vector);
		Vector4& operator/=(float val);

		bool operator==(const Vector4& vector) const;
		bool operator==(float val) const;
		bool operator!=(const Vector4& vector) const;
		bool operator!=(float val) const;
		bool operator>=(const Vector4& vector) const;
		bool operator>=(float val) const;
		bool operator>(const Vector4& vector) const;
		bool operator>(float val) const;
		bool operator<=(const Vector4& vector) const;
		bool operator<=(float val) const;
		bool operator<(const Vector4& vector) const;
		bool operator<(float val) const;

		String ToString() const;
	};
}}

#endif VECTOR4_H