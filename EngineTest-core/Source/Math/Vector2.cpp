#include "Vector2.h"

namespace EngineTest
{
	namespace Math
	{
		Vector2::Vector2()
		{
			_x = 0.0f;
			_y = 0.0f;
		}
		Vector2::Vector2(const float& x, const float& y)
		{
			_x = x;
			_y = y;
		}

		Vector2 Vector2::Add(const Vector2& vector) const
		{
			return Vector2(_x + vector._x, _y + vector._y);
		}
		Vector2 Vector2::Add(const float& vector) const
		{
			return Vector2(_x + vector, _y + vector);
		}
		Vector2& Vector2::AddEquals(const Vector2& vector)
		{
			_x += vector._x;
			_y += vector._y;
			return *this;
		}
		Vector2& Vector2::AddEquals(const float& vector)
		{
			_x += vector;
			_y += vector;
			return *this;
		}

		Vector2 Vector2::Subtract(const Vector2& vector) const
		{
			return Vector2(_x - vector._x, _y - vector._y);
		}
		Vector2 Vector2::Subtract(const float& vector) const
		{
			return Vector2(_x - vector, _y - vector);
		}
		Vector2& Vector2::SubtractEquals(const Vector2& vector)
		{
			_x -= vector._x;
			_y -= vector._y;
			return *this;
		}
		Vector2& Vector2::SubtractEquals(const float& vector)
		{
			_x -= vector;
			_y -= vector;
			return *this;
		}

		Vector2 Vector2::Multiply(const Vector2& vector) const
		{
			return Vector2(_x * vector._x, _y * vector._y);
		}
		Vector2 Vector2::Multiply(const float& vector) const
		{
			return Vector2(_x * vector, _y * vector);
		}
		Vector2& Vector2::MultiplyEquals(const Vector2& vector)
		{
			_x *= vector._x;
			_y *= vector._y;
			return *this;
		}
		Vector2& Vector2::MultiplyEquals(const float& vector)
		{
			_x *= vector;
			_y *= vector;
			return *this;
		}

		Vector2 Vector2::Divide(const Vector2& vector) const
		{
			return Vector2(_x / vector._x, _y / vector._y);
		}
		Vector2 Vector2::Divide(const float& vector) const
		{
			return Vector2(_x / vector, _y / vector);
		}
		Vector2& Vector2::DivideEquals(const Vector2& vector)
		{
			_x /= vector._x;
			_y /= vector._y;
			return *this;
		}
		Vector2& Vector2::DivideEquals(const float& vector)
		{
			_x /= vector;
			_y /= vector;
			return *this;
		}

		bool Vector2::Compare(const Vector2& vector) const
		{
			return _x == vector._x && _y == vector._y;
		}
		bool Vector2::Compare(const float& vector) const
		{
			return _x == vector && _y == vector;
		}

		Vector2 Vector2::Normalize() const
		{
			return Divide(Magnitude());
		}
		Vector2& Vector2::NormalizeEquals()
		{
			return DivideEquals(Magnitude());
		}

		float Vector2::Magnitude() const
		{
			return sqrtf(_x * _x + _y * _y);
		}
		float Vector2::Distance(const Vector2& vector) const
		{
			float dx = vector._x - _x;
			float dy = vector._y - _y;
			return sqrtf(dx * dx + dy * dy);
		}
		float Vector2::Dot(const Vector2& vector) const
		{
			return _x * vector._x + _y * vector._y;
		}

		Vector2 operator+(const Vector2& left, const Vector2& right)
		{
			return left.Add(right);
		}
		Vector2 operator+(const Vector2& left, const float& right)
		{
			return left.Add(right);
		}
		Vector2& operator+=(Vector2& left, const Vector2& right)
		{
			return left.AddEquals(right);
		}
		Vector2& operator+=(Vector2& left, const float& right)
		{
			return left.AddEquals(right);
		}

		Vector2 operator-(const Vector2& left, const Vector2& right)
		{
			return left.Subtract(right);
		}
		Vector2 operator-(const Vector2& left, const float& right)
		{
			return left.Subtract(right);
		}
		Vector2& operator-=(Vector2& left, const Vector2& right)
		{
			return left.SubtractEquals(right);
		}
		Vector2& operator-=(Vector2& left, const float& right)
		{
			return left.SubtractEquals(right);
		}

		Vector2 operator*(const Vector2& left, const Vector2& right)
		{
			return left.Multiply(right);
		}
		Vector2 operator*(const Vector2& left, const float& right)
		{
			return left.Multiply(right);
		}
		Vector2& operator*=(Vector2& left, const Vector2& right)
		{
			return left.MultiplyEquals(right);
		}
		Vector2& operator*=(Vector2& left, const float& right)
		{
			return left.MultiplyEquals(right);
		}

		Vector2 operator/(const Vector2& left, const Vector2& right)
		{
			return left.Divide(right);
		}
		Vector2 operator/(const Vector2& left, const float& right)
		{
			return left.Divide(right);
		}
		Vector2& operator/=(Vector2& left, const Vector2& right)
		{
			return left.DivideEquals(right);
		}
		Vector2& operator/=(Vector2& left, const float& right)
		{
			return left.DivideEquals(right);
		}

		bool operator==(const Vector2& left, const Vector2& right)
		{
			return left.Compare(right);
		}
		bool operator==(const Vector2& left, const float& right)
		{
			return left.Compare(right);
		}
		bool operator!=(const Vector2& left, const Vector2& right)
		{
			return !left.Compare(right);
		}
		bool operator!=(const Vector2& left, const float& right)
		{
			return !left.Compare(right);
		}

		void Vector2::Log()
		{
			LOG("Vector2: %f, %f", _x, _y);
		}
	}
}