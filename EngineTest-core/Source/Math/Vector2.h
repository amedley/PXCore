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

			Vector2 Add(const Vector2& vector) const;
			Vector2 Add(const float& vector) const;
			Vector2& AddEquals(const Vector2& vector);
			Vector2& AddEquals(const float& vector);

			Vector2 Subtract(const Vector2& vector) const;
			Vector2 Subtract(const float& vector) const;
			Vector2& SubtractEquals(const Vector2& vector);
			Vector2& SubtractEquals(const float& vector);

			Vector2 Multiply(const Vector2& vector) const;
			Vector2 Multiply(const float& vector) const;
			Vector2& MultiplyEquals(const Vector2& vector);
			Vector2& MultiplyEquals(const float& vector);

			Vector2 Divide(const Vector2& vector) const;
			Vector2 Divide(const float& vector) const;
			Vector2& DivideEquals(const Vector2& vector);
			Vector2& DivideEquals(const float& vector);

			bool Compare(const Vector2& vector) const;
			bool Compare(const float& vector) const;

			Vector2 Normalize() const;
			Vector2& NormalizeEquals();
			
			float Magnitude() const;
			float Distance(const Vector2& vector) const;
			float Dot(const Vector2& vector) const;

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