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

			Vector4 Add(const Vector4& other) const;
			Vector4 Add(const float& other) const;
			Vector4& AddEquals(const Vector4& other);
			Vector4& AddEquals(const float& other);

			Vector4 Subtract(const Vector4& other) const;
			Vector4 Subtract(const float& other) const;
			Vector4& SubtractEquals(const Vector4& other);
			Vector4& SubtractEquals(const float& other);

			Vector4 Multiply(const Vector4& other) const;
			Vector4 Multiply(const float& other) const;
			Vector4& MultiplyEquals(const Vector4& other);
			Vector4& MultiplyEquals(const float& other);

			Vector4 Divide(const Vector4& other) const;
			Vector4 Divide(const float& other) const;
			Vector4& DivideEquals(const Vector4& other);
			Vector4& DivideEquals(const float& other);

			bool Compare(const Vector4& other) const;
			bool Compare(const float& other) const;

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