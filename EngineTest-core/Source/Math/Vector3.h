#ifndef VECTOR3_H
#define VECTOR3_H

#include "../Debug.h"

namespace EngineTest
{
	namespace Math
	{
		typedef struct Vector3
		{
			float _x, _y, _z;
			Vector3();
			Vector3(const float& x, const float& y, const float& z);

			Vector3 Add(const Vector3& other) const;
			Vector3 Add(const float& other) const;
			Vector3& AddEquals(const Vector3& other);
			Vector3& AddEquals(const float& other);

			Vector3 Subtract(const Vector3& other) const;
			Vector3 Subtract(const float& other) const;
			Vector3& SubtractEquals(const Vector3& other);
			Vector3& SubtractEquals(const float& other);

			Vector3 Multiply(const Vector3& other) const;
			Vector3 Multiply(const float& other) const;
			Vector3& MultiplyEquals(const Vector3& other);
			Vector3& MultiplyEquals(const float& other);

			Vector3 Divide(const Vector3& other) const;
			Vector3 Divide(const float& other) const;
			Vector3& DivideEquals(const Vector3& other);
			Vector3& DivideEquals(const float& other);

			bool Compare(const Vector3& other) const;
			bool Compare(const float& other) const;

			friend Vector3 operator+(const Vector3& left, const Vector3& right);
			friend Vector3 operator+(const Vector3& left, const float& right);
			friend Vector3& operator+=(Vector3& left, const Vector3& right);
			friend Vector3& operator+=(Vector3& left, const float& right);

			friend Vector3 operator-(const Vector3& left, const Vector3& right);
			friend Vector3 operator-(const Vector3& left, const float& right);
			friend Vector3& operator-=(Vector3& left, const Vector3& right);
			friend Vector3& operator-=(Vector3& left, const float& right);

			friend Vector3 operator*(const Vector3& left, const Vector3& right);
			friend Vector3 operator*(const Vector3& left, const float& right);
			friend Vector3& operator*=(Vector3& left, const Vector3& right);
			friend Vector3& operator*=(Vector3& left, const float& right);

			friend Vector3 operator/(const Vector3& left, const Vector3& right);
			friend Vector3 operator/(const Vector3& left, const float& right);
			friend Vector3& operator/=(Vector3& left, const Vector3& right);
			friend Vector3& operator/=(Vector3& left, const float& right);

			friend bool operator==(const Vector3& left, const Vector3& right);
			friend bool operator==(const Vector3& left, const float& right);
			friend bool operator!=(const Vector3& left, const Vector3& right);
			friend bool operator!=(const Vector3& left, const float& right);

			void Log();
		} Vector3;
	}
}

#endif VECTOR3_H