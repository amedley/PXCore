#include "Vector3.h"

namespace EngineTest
{
	namespace Math
	{
		Vector3::Vector3()
		{
			_x = 0.0f;
			_y = 0.0f;
			_z = 0.0f;
		}
		Vector3::Vector3(const float& x, const float& y, const float& z)
		{
			_x = x;
			_y = y;
			_z = z;
		}

		Vector3 Vector3::Add(const Vector3& other) const
		{
			return Vector3(_x + other._x, _y + other._y, _z + other._z);
		}
		Vector3 Vector3::Add(const float& other) const
		{
			return Vector3(_x + other, _y + other, _z + other);
		}
		Vector3& Vector3::AddEquals(const Vector3& other)
		{
			_x += other._x;
			_y += other._y;
			_z += other._z;
			return *this;
		}
		Vector3& Vector3::AddEquals(const float& other)
		{
			_x += other;
			_y += other;
			_z += other;
			return *this;
		}

		Vector3 Vector3::Subtract(const Vector3& other) const
		{
			return Vector3(_x - other._x, _y - other._y, _z - other._z);
		}
		Vector3 Vector3::Subtract(const float& other) const
		{
			return Vector3(_x - other, _y - other, _z - other);
		}
		Vector3& Vector3::SubtractEquals(const Vector3& other)
		{
			_x -= other._x;
			_y -= other._y;
			_z -= other._z;
			return *this;
		}
		Vector3& Vector3::SubtractEquals(const float& other)
		{
			_x -= other;
			_y -= other;
			_z -= other;
			return *this;
		}

		Vector3 Vector3::Multiply(const Vector3& other) const
		{
			return Vector3(_x * other._x, _y * other._y, _z * other._z);
		}
		Vector3 Vector3::Multiply(const float& other) const
		{
			return Vector3(_x * other, _y * other, _z * other);
		}
		Vector3& Vector3::MultiplyEquals(const Vector3& other)
		{
			_x *= other._x;
			_y *= other._y;
			_z *= other._z;
			return *this;
		}
		Vector3& Vector3::MultiplyEquals(const float& other)
		{
			_x *= other;
			_y *= other;
			_z *= other;
			return *this;
		}

		Vector3 Vector3::Divide(const Vector3& other) const
		{
			return Vector3(_x / other._x, _y / other._y, _z / other._z);
		}
		Vector3 Vector3::Divide(const float& other) const
		{
			return Vector3(_x / other, _y / other, _z / other);
		}
		Vector3& Vector3::DivideEquals(const Vector3& other)
		{
			_x /= other._x;
			_y /= other._y;
			_z /= other._z;
			return *this;
		}
		Vector3& Vector3::DivideEquals(const float& other)
		{
			_x /= other;
			_y /= other;
			_z /= other;
			return *this;
		}

		bool Vector3::Compare(const Vector3& other) const
		{
			return _x == other._x && _y == other._y && _z == other._z;
		}
		bool Vector3::Compare(const float& other) const
		{
			return _x == other && _y == other && _z == other;
		}


		Vector3 operator+(const Vector3& left, const Vector3& right)
		{
			return left.Add(right);
		}
		Vector3 operator+(const Vector3& left, const float& right)
		{
			return left.Add(right);
		}
		Vector3& operator+=(Vector3& left, const Vector3& right)
		{
			return left.AddEquals(right);
		}
		Vector3& operator+=(Vector3& left, const float& right)
		{
			return left.AddEquals(right);
		}

		Vector3 operator-(const Vector3& left, const Vector3& right)
		{
			return left.Subtract(right);
		}
		Vector3 operator-(const Vector3& left, const float& right)
		{
			return left.Subtract(right);
		}
		Vector3& operator-=(Vector3& left, const Vector3& right)
		{
			return left.SubtractEquals(right);
		}
		Vector3& operator-=(Vector3& left, const float& right)
		{
			return left.SubtractEquals(right);
		}

		Vector3 operator*(const Vector3& left, const Vector3& right)
		{
			return left.Multiply(right);
		}
		Vector3 operator*(const Vector3& left, const float& right)
		{
			return left.Multiply(right);
		}
		Vector3& operator*=(Vector3& left, const Vector3& right)
		{
			return left.MultiplyEquals(right);
		}
		Vector3& operator*=(Vector3& left, const float& right)
		{
			return left.MultiplyEquals(right);
		}

		Vector3 operator/(const Vector3& left, const Vector3& right)
		{
			return left.Divide(right);
		}
		Vector3 operator/(const Vector3& left, const float& right)
		{
			return left.Divide(right);
		}
		Vector3& operator/=(Vector3& left, const Vector3& right)
		{
			return left.DivideEquals(right);
		}
		Vector3& operator/=(Vector3& left, const float& right)
		{
			return left.DivideEquals(right);
		}

		bool operator==(const Vector3& left, const Vector3& right)
		{
			return left.Compare(right);
		}
		bool operator==(const Vector3& left, const float& right)
		{
			return left.Compare(right);
		}
		bool operator!=(const Vector3& left, const Vector3& right)
		{
			return !left.Compare(right);
		}
		bool operator!=(const Vector3& left, const float& right)
		{
			return !left.Compare(right);
		}

		void Vector3::Log()
		{
			LOG("Vector3: %f, %f, %f", _x, _y, _z);
		}
	}
}