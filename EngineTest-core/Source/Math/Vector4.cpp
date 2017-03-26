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

		Vector4 Vector4::Add(const Vector4& other) const
		{
			return Vector4(_x + other._x, _y + other._y, _z + other._z, _w + other._w);
		}
		Vector4 Vector4::Add(const float& other) const
		{
			return Vector4(_x + other, _y + other, _z + other, _w + other);
		}
		Vector4& Vector4::AddEquals(const Vector4& other)
		{
			_x += other._x;
			_y += other._y;
			_z += other._z;
			_w += other._w;
			return *this;
		}
		Vector4& Vector4::AddEquals(const float& other)
		{
			_x += other;
			_y += other;
			_z += other;
			_w += other;
			return *this;
		}

		Vector4 Vector4::Subtract(const Vector4& other) const
		{
			return Vector4(_x - other._x, _y - other._y, _z - other._z, _w - other._w);
		}
		Vector4 Vector4::Subtract(const float& other) const
		{
			return Vector4(_x - other, _y - other, _z - other, _w - other);
		}
		Vector4& Vector4::SubtractEquals(const Vector4& other)
		{
			_x -= other._x;
			_y -= other._y;
			_z -= other._z;
			_w -= other._w;
			return *this;
		}
		Vector4& Vector4::SubtractEquals(const float& other)
		{
			_x -= other;
			_y -= other;
			_z -= other;
			_w -= other;
			return *this;
		}

		Vector4 Vector4::Multiply(const Vector4& other) const
		{
			return Vector4(_x * other._x, _y * other._y, _z * other._z, _w * other._w);
		}
		Vector4 Vector4::Multiply(const float& other) const
		{
			return Vector4(_x * other, _y * other, _z * other, _w * other);
		}
		Vector4& Vector4::MultiplyEquals(const Vector4& other)
		{
			_x *= other._x;
			_y *= other._y;
			_z *= other._z;
			_w *= other._w;
			return *this;
		}
		Vector4& Vector4::MultiplyEquals(const float& other)
		{
			_x *= other;
			_y *= other;
			_z *= other;
			_w *= other;
			return *this;
		}

		Vector4 Vector4::Divide(const Vector4& other) const
		{
			return Vector4(_x / other._x, _y / other._y, _z / other._z, _w / other._w);
		}
		Vector4 Vector4::Divide(const float& other) const
		{
			return Vector4(_x / other, _y / other, _z / other, _w / other);
		}
		Vector4& Vector4::DivideEquals(const Vector4& other)
		{
			_x /= other._x;
			_y /= other._y;
			_z /= other._z;
			_w /= other._w;
			return *this;
		}
		Vector4& Vector4::DivideEquals(const float& other)
		{
			_x /= other;
			_y /= other;
			_z /= other;
			_w /= other;
			return *this;
		}

		bool Vector4::Compare(const Vector4& other) const
		{
			return _x == other._x && _y == other._y && _z == other._z && _w == other._w;
		}
		bool Vector4::Compare(const float& other) const
		{
			return _x == other && _y == other && _z == other && _w == other;
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