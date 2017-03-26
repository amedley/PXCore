#ifndef VECTOR2_H
#define VECTOR2_H

#include "../Debug.h"

namespace EngineTest
{
	namespace Math
	{
		typedef struct Vector2
		{
			float _x, _y;
			Vector2();
			Vector2(const float& x, const float& y);

			Vector2 Add(const Vector2& other) const;
			Vector2 Add(const float& other) const;
			Vector2& AddEquals(const Vector2& other);
			Vector2& AddEquals(const float& other);

			Vector2 Subtract(const Vector2& other) const;
			Vector2 Subtract(const float& other) const;
			Vector2& SubtractEquals(const Vector2& other);
			Vector2& SubtractEquals(const float& other);

			Vector2 Multiply(const Vector2& other) const;
			Vector2 Multiply(const float& other) const;
			Vector2& MultiplyEquals(const Vector2& other);
			Vector2& MultiplyEquals(const float& other);

			Vector2 Divide(const Vector2& other) const;
			Vector2 Divide(const float& other) const;
			Vector2& DivideEquals(const Vector2& other);
			Vector2& DivideEquals(const float& other);

			bool Compare(const Vector2& other) const;
			bool Compare(const float& other) const;

			friend Vector2 operator+(const Vector2& left, const Vector2& right);
			friend Vector2 operator+(const Vector2& left, const float& right);
			friend Vector2& operator+=(Vector2& left, const Vector2& right);
			friend Vector2& operator+=(Vector2& left, const float& right);

			friend Vector2 operator-(const Vector2& left, const Vector2& right);
			friend Vector2 operator-(const Vector2& left, const float& right);
			friend Vector2& operator-=(Vector2& left, const Vector2& right);
			friend Vector2& operator-=(Vector2& left, const float& right);

			friend Vector2 operator*(const Vector2& left, const Vector2& right);
			friend Vector2 operator*(const Vector2& left, const float& right);
			friend Vector2& operator*=(Vector2& left, const Vector2& right);
			friend Vector2& operator*=(Vector2& left, const float& right);

			friend Vector2 operator/(const Vector2& left, const Vector2& right);
			friend Vector2 operator/(const Vector2& left, const float& right);
			friend Vector2& operator/=(Vector2& left, const Vector2& right);
			friend Vector2& operator/=(Vector2& left, const float& right);

			friend bool operator==(const Vector2& left, const Vector2& right);
			friend bool operator==(const Vector2& left, const float& right);
			friend bool operator!=(const Vector2& left, const Vector2& right);
			friend bool operator!=(const Vector2& left, const float& right);

			void Log();
		} Vector2;
	}
}

#endif VECTOR2_H