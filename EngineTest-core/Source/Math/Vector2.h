#ifndef VECTOR2_H
#define VECTOR2_H

#include "../Common.h"

namespace EngineTest { namespace Math {
	struct Vector3;
	struct Vector4;
		
	struct Vector2
	{
		float _x, _y;
		Vector2();
		Vector2(float scalar);
		Vector2(float x, float y);
		Vector2(const Vector2& vector);
		Vector2(const Vector3& vector);
		Vector2(const Vector4& vector);
			
		float Magnitude() const;
		float Distance(const Vector2& vector) const;
		float Dot(const Vector2& vector) const;

		Vector2& operator=(const Vector2& vector);

		Vector2 Normalize() const;
		Vector2& NormalizeEquals();
			
		Vector2 operator+(const Vector2& vector) const;
		Vector2 operator+(float val) const;
		Vector2& operator+=(const Vector2& vector);
		Vector2& operator+=(float val);

		Vector2 operator-(const Vector2& vector) const;
		Vector2 operator-(float val) const;
		Vector2& operator-=(const Vector2& vector);
		Vector2& operator-=(float val);

		Vector2 operator*(const Vector2& vector) const;
		Vector2 operator*(float val) const;
		Vector2& operator*=(const Vector2& vector);
		Vector2& operator*=(float val);

		Vector2 operator/(const Vector2& vector) const;
		Vector2 operator/(float val) const;
		Vector2& operator/=(const Vector2& vector);
		Vector2& operator/=(float val);

		bool operator==(const Vector2& vector) const;
		bool operator==(float val) const;
		bool operator!=(const Vector2& vector) const;
		bool operator!=(float val) const;
		bool operator>=(const Vector2& vector) const;
		bool operator>=(float val) const;
		bool operator>(const Vector2& vector) const;
		bool operator>(float val) const;
		bool operator<=(const Vector2& vector) const;
		bool operator<=(float val) const;
		bool operator<(const Vector2& vector) const;
		bool operator<(float val) const;

		String ToString() const;
	};
}}

#endif VECTOR2_H