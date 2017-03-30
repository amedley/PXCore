#include "Vector3.h"
#include "Matrix4.h"

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

		Vector3 Vector3::Add(const Vector3& vector) const
		{
			return Vector3(_x + vector._x, _y + vector._y, _z + vector._z);
		}
		Vector3 Vector3::Add(const float& vector) const
		{
			return Vector3(_x + vector, _y + vector, _z + vector);
		}
		Vector3& Vector3::AddEquals(const Vector3& vector)
		{
			_x += vector._x;
			_y += vector._y;
			_z += vector._z;
			return *this;
		}
		Vector3& Vector3::AddEquals(const float& vector)
		{
			_x += vector;
			_y += vector;
			_z += vector;
			return *this;
		}

		Vector3 Vector3::Subtract(const Vector3& vector) const
		{
			return Vector3(_x - vector._x, _y - vector._y, _z - vector._z);
		}
		Vector3 Vector3::Subtract(const float& vector) const
		{
			return Vector3(_x - vector, _y - vector, _z - vector);
		}
		Vector3& Vector3::SubtractEquals(const Vector3& vector)
		{
			_x -= vector._x;
			_y -= vector._y;
			_z -= vector._z;
			return *this;
		}
		Vector3& Vector3::SubtractEquals(const float& vector)
		{
			_x -= vector;
			_y -= vector;
			_z -= vector;
			return *this;
		}

		Vector3 Vector3::Multiply(const Vector3& vector) const
		{
			return Vector3(_x * vector._x, _y * vector._y, _z * vector._z);
		}
		Vector3 Vector3::Multiply(const float& vector) const
		{
			return Vector3(_x * vector, _y * vector, _z * vector);
		}
		Vector3& Vector3::MultiplyEqualsMatrix4(const float* vector)
		{
			_x = _x * vector[0] + _y * vector[4] + _z * vector[8] + vector[12];
			_y = _x * vector[1] + _y * vector[5] + _z * vector[9] + vector[13];
			_z = _x * vector[2] + _y * vector[6] + _z * vector[10] + vector[14];

			return *this;
		}
		Vector3& Vector3::MultiplyEquals(const Vector3& vector)
		{
			_x *= vector._x;
			_y *= vector._y;
			_z *= vector._z;
			return *this;
		}
		Vector3& Vector3::MultiplyEquals(const float& vector)
		{
			_x *= vector;
			_y *= vector;
			_z *= vector;
			return *this;
		}

		Vector3 Vector3::Divide(const Vector3& vector) const
		{
			return Vector3(_x / vector._x, _y / vector._y, _z / vector._z);
		}
		Vector3 Vector3::Divide(const float& vector) const
		{
			return Vector3(_x / vector, _y / vector, _z / vector);
		}
		Vector3& Vector3::DivideEquals(const Vector3& vector)
		{
			_x /= vector._x;
			_y /= vector._y;
			_z /= vector._z;
			return *this;
		}
		Vector3& Vector3::DivideEquals(const float& vector)
		{
			_x /= vector;
			_y /= vector;
			_z /= vector;
			return *this;
		}

		bool Vector3::Compare(const Vector3& vector) const
		{
			return _x == vector._x && _y == vector._y && _z == vector._z;
		}
		bool Vector3::Compare(const float& vector) const
		{
			return _x == vector && _y == vector && _z == vector;
		}

		Vector3 Vector3::Cross(const Vector3& vector) const
		{
			return Vector3(_y * vector._z - _z * vector._y, _z * vector._x - _x * vector._z, _x * vector._y - _y * vector._x);
		}
		Vector3& Vector3::CrossEquals(const Vector3& vector)
		{
			float x = _y * vector._z - _z * vector._y;
			float y = _z * vector._x - _x * vector._z;
			float z = _x * vector._y - _y * vector._x;
			_x = x;
			_y = y;
			_z = z;
			return *this;
		}

		Vector3 Vector3::Normalize() const
		{
			return Divide(Magnitude());
		}
		Vector3& Vector3::NormalizeEquals()
		{
			return DivideEquals(Magnitude());
		}

		float Vector3::Magnitude() const
		{
			return sqrtf(_x * _x + _y * _y + _z * _z);
		}
		float Vector3::Distance(const Vector3& vector) const
		{
			float dx = vector._x - _x;
			float dy = vector._y - _y;
			float dz = vector._z - _z;
			return sqrtf(dx * dx + dy * dy + dz * dz);
		}
		float Vector3::Dot(const Vector3& vector) const
		{
			return _x * vector._x + _y * vector._y + _z * vector._z;
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