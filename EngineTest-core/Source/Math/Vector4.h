#ifndef VECTOR4_H
#define VECTOR4_H

#include "../Debug.h"

namespace EngineTest
{
	namespace Math
	{
		typedef struct Vector4
		{
			float _x, _y, _z, _w;
			Vector4();
			Vector4(const float& x, const float& y, const float& z, const float& w);

			Vector4 Add(const Vector4& vector) const;
			Vector4 Add(const float& vector) const;
			Vector4& AddEquals(const Vector4& vector);
			Vector4& AddEquals(const float& vector);

			Vector4 Subtract(const Vector4& vector) const;
			Vector4 Subtract(const float& vector) const;
			Vector4& SubtractEquals(const Vector4& vector);
			Vector4& SubtractEquals(const float& vector);

			Vector4 Multiply(const Vector4& vector) const;
			Vector4 Multiply(const float& vector) const;
			Vector4& MultiplyEquals(const Vector4& vector);
			Vector4& MultiplyEquals(const float& vector);

			Vector4 Divide(const Vector4& vector) const;
			Vector4 Divide(const float& vector) const;
			Vector4& DivideEquals(const Vector4& vector);
			Vector4& DivideEquals(const float& vector);

			bool Compare(const Vector4& vector) const;
			bool Compare(const float& vector) const;

			Vector4 Normalize() const;
			Vector4& NormalizeEquals();

			float Magnitude() const;
			float Distance(const Vector4& vector) const;
			float Dot(const Vector4& vector) const;

			friend Vector4 operator+(const Vector4& left, const Vector4& right);
			friend Vector4 operator+(const Vector4& left, const float& right);
			friend Vector4& operator+=(Vector4& left, const Vector4& right);
			friend Vector4& operator+=(Vector4& left, const float& right);

			friend Vector4 operator-(const Vector4& left, const Vector4& right);
			friend Vector4 operator-(const Vector4& left, const float& right);
			friend Vector4& operator-=(Vector4& left, const Vector4& right);
			friend Vector4& operator-=(Vector4& left, const float& right);

			friend Vector4 operator*(const Vector4& left, const Vector4& right);
			friend Vector4 operator*(const Vector4& left, const float& right);
			friend Vector4& operator*=(Vector4& left, const Vector4& right);
			friend Vector4& operator*=(Vector4& left, const float& right);

			friend Vector4 operator/(const Vector4& left, const Vector4& right);
			friend Vector4 operator/(const Vector4& left, const float& right);
			friend Vector4& operator/=(Vector4& left, const Vector4& right);
			friend Vector4& operator/=(Vector4& left, const float& right);

			friend bool operator==(const Vector4& left, const Vector4& right);
			friend bool operator==(const Vector4& left, const float& right);
			friend bool operator!=(const Vector4& left, const Vector4& right);
			friend bool operator!=(const Vector4& left, const float& right);

			void Log();
		} Vector4;
	}
}

#endif VECTOR4_H