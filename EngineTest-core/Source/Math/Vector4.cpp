#include "Vector4.h"

namespace EngineTest
{
	namespace Math
	{
		Vector4::Vector4()
		{
			_x = 0.0f;
			_y = 0.0f;
			_z = 0.0f;
			_w = 0.0f;
		}
		Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
		{
			_x = x;
			_y = y;
			_z = z;
			_w = w;
		}

		Vector4 Vector4::Add(const Vector4& vector) const
		{
			return Vector4(_x + vector._x, _y + vector._y, _z + vector._z, _w + vector._w);
		}
		Vector4 Vector4::Add(const float& vector) const
		{
			return Vector4(_x + vector, _y + vector, _z + vector, _w + vector);
		}
		Vector4& Vector4::AddEquals(const Vector4& vector)
		{
			_x += vector._x;
			_y += vector._y;
			_z += vector._z;
			_w += vector._w;
			return *this;
		}
		Vector4& Vector4::AddEquals(const float& vector)
		{
			_x += vector;
			_y += vector;
			_z += vector;
			_w += vector;
			return *this;
		}

		Vector4 Vector4::Subtract(const Vector4& vector) const
		{
			return Vector4(_x - vector._x, _y - vector._y, _z - vector._z, _w - vector._w);
		}
		Vector4 Vector4::Subtract(const float& vector) const
		{
			return Vector4(_x - vector, _y - vector, _z - vector, _w - vector);
		}
		Vector4& Vector4::SubtractEquals(const Vector4& vector)
		{
			_x -= vector._x;
			_y -= vector._y;
			_z -= vector._z;
			_w -= vector._w;
			return *this;
		}
		Vector4& Vector4::SubtractEquals(const float& vector)
		{
			_x -= vector;
			_y -= vector;
			_z -= vector;
			_w -= vector;
			return *this;
		}

		Vector4 Vector4::Multiply(const Vector4& vector) const
		{
			return Vector4(_x * vector._x, _y * vector._y, _z * vector._z, _w * vector._w);
		}
		Vector4 Vector4::Multiply(const float& vector) const
		{
			return Vector4(_x * vector, _y * vector, _z * vector, _w * vector);
		}
		Vector4& Vector4::MultiplyEquals(const Vector4& vector)
		{
			_x *= vector._x;
			_y *= vector._y;
			_z *= vector._z;
			_w *= vector._w;
			return *this;
		}
		Vector4& Vector4::MultiplyEquals(const float& vector)
		{
			_x *= vector;
			_y *= vector;
			_z *= vector;
			_w *= vector;
			return *this;
		}

		Vector4 Vector4::Divide(const Vector4& vector) const
		{
			return Vector4(_x / vector._x, _y / vector._y, _z / vector._z, _w / vector._w);
		}
		Vector4 Vector4::Divide(const float& vector) const
		{
			return Vector4(_x / vector, _y / vector, _z / vector, _w / vector);
		}
		Vector4& Vector4::DivideEquals(const Vector4& vector)
		{
			_x /= vector._x;
			_y /= vector._y;
			_z /= vector._z;
			_w /= vector._w;
			return *this;
		}
		Vector4& Vector4::DivideEquals(const float& vector)
		{
			_x /= vector;
			_y /= vector;
			_z /= vector;
			_w /= vector;
			return *this;
		}

		bool Vector4::Compare(const Vector4& vector) const
		{
			return _x == vector._x && _y == vector._y && _z == vector._z && _w == vector._w;
		}
		bool Vector4::Compare(const float& vector) const
		{
			return _x == vector && _y == vector && _z == vector && _w == vector;
		}

		Vector4 Vector4::Normalize() const
		{
			return Divide(Magnitude());
		}
		Vector4& Vector4::NormalizeEquals()
		{
			return DivideEquals(Magnitude());
		}

		float Vector4::Magnitude() const
		{
			return sqrtf(_x * _x + _y * _y + _z * _z + _w * _w);
		}
		float Vector4::Distance(const Vector4& vector) const
		{
			float dx = vector._x - _x;
			float dy = vector._y - _y;
			float dz = vector._z - _z;
			float dw = vector._w - _w;
			return sqrtf(dx * dx + dy * dy + dz * dz + dw * dw);
		}
		float Vector4::Dot(const Vector4& vector) const
		{
			return _x * vector._x + _y * vector._y + _z * vector._z + _w * vector._w;
		}

		Vector4 operator+(const Vector4& left, const Vector4& right)
		{
			return left.Add(right);
		}
		Vector4 operator+(const Vector4& left, const float& right)
		{
			return left.Add(right);
		}
		Vector4& operator+=(Vector4& left, const Vector4& right)
		{
			return left.AddEquals(right);
		}
		Vector4& operator+=(Vector4& left, const float& right)
		{
			return left.AddEquals(right);
		}

		Vector4 operator-(const Vector4& left, const Vector4& right)
		{
			return left.Subtract(right);
		}
		Vector4 operator-(const Vector4& left, const float& right)
		{
			return left.Subtract(right);
		}
		Vector4& operator-=(Vector4& left, const Vector4& right)
		{
			return left.SubtractEquals(right);
		}
		Vector4& operator-=(Vector4& left, const float& right)
		{
			return left.SubtractEquals(right);
		}

		Vector4 operator*(const Vector4& left, const Vector4& right)
		{
			return left.Multiply(right);
		}
		Vector4 operator*(const Vector4& left, const float& right)
		{
			return left.Multiply(right);
		}
		Vector4& operator*=(Vector4& left, const Vector4& right)
		{
			return left.MultiplyEquals(right);
		}
		Vector4& operator*=(Vector4& left, const float& right)
		{
			return left.MultiplyEquals(right);
		}

		Vector4 operator/(const Vector4& left, const Vector4& right)
		{
			return left.Divide(right);
		}
		Vector4 operator/(const Vector4& left, const float& right)
		{
			return left.Divide(right);
		}
		Vector4& operator/=(Vector4& left, const Vector4& right)
		{
			return left.DivideEquals(right);
		}
		Vector4& operator/=(Vector4& left, const float& right)
		{
			return left.DivideEquals(right);
		}

		bool operator==(const Vector4& left, const Vector4& right)
		{
			return left.Compare(right);
		}
		bool operator==(const Vector4& left, const float& right)
		{
			return left.Compare(right);
		}
		bool operator!=(const Vector4& left, const Vector4& right)
		{
			return !left.Compare(right);
		}
		bool operator!=(const Vector4& left, const float& right)
		{
			return !left.Compare(right);
		}

		void Vector4::Log()
		{
			LOG("Vector4: %f, %f, %f, %f", _x, _y, _z, _w);
		}
	}
}