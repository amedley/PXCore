#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace EngineTest
{
	namespace Math
	{
		Vector2::Vector2()
		{
			_x = 0.0f;
			_y = 0.0f;
		}
		Vector2::Vector2(float scalar)
		{
			_x = scalar;
			_y = scalar;
		}
		Vector2::Vector2(float x, float y)
		{
			_x = x;
			_y = y;
		}
		Vector2::Vector2(const Vector2& vector)
		{
			_x = vector._x;
			_y = vector._y;
		}
		Vector2::Vector2(const Vector3& vector)
		{
			_x = vector._x;
			_y = vector._y;
		}
		Vector2::Vector2(const Vector4& vector)
		{
			_x = vector._x;
			_y = vector._y;
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


		Vector2& Vector2::operator=(const Vector2& vector)
		{
			_x = vector._x;
			_y = vector._y;
			return *this;
		}

		Vector2 Vector2::Normalize() const
		{
			Vector2 result = *this;
			return result / Magnitude();
		}
		Vector2& Vector2::NormalizeEquals()
		{
			*this /= Magnitude();
			return *this;
		}

		Vector2 Vector2::operator+(const Vector2& vector) const
		{
			Vector2 result(_x + vector._x, _y + vector._y);
			return result;
		}
		Vector2 Vector2::operator+(float val) const
		{
			return Vector2(_x + val, _y + val);
		}
		Vector2& Vector2::operator+=(const Vector2& vector)
		{
			_x += vector._x;
			_y += vector._y;
			return *this;
		}
		Vector2& Vector2::operator+=(float val)
		{
			_x += val;
			_y += val;
			return *this;
		}

		Vector2 Vector2::operator-(const Vector2& vector) const
		{
			return Vector2(_x - vector._x, _y - vector._y);
		}
		Vector2 Vector2::operator-(float val) const
		{
			return Vector2(_x - val, _y - val);
		}
		Vector2& Vector2::operator-=(const Vector2& vector)
		{
			_x -= vector._x;
			_y -= vector._y;
			return *this;
		}
		Vector2& Vector2::operator-=(float val)
		{
			_x -= val;
			_y -= val;
			return *this;
		}

		Vector2 Vector2::operator*(const Vector2& vector) const
		{
			return Vector2(_x * vector._x, _y * vector._y);
		}
		Vector2 Vector2::operator*(float val) const
		{
			return Vector2(_x * val, _y * val);
		}
		Vector2& Vector2::operator*=(const Vector2& vector)
		{
			_x *= vector._x;
			_y *= vector._y;
			return *this;
		}
		Vector2& Vector2::operator*=(float val)
		{
			_x *= val;
			_y *= val;
			return *this;
		}

		Vector2 Vector2::operator/(const Vector2& vector) const
		{
			return Vector2(_x / vector._x, _y / vector._y);
		}
		Vector2 Vector2::operator/(float val) const
		{
			return Vector2(_x / val, _y / val);
		}
		Vector2& Vector2::operator/=(const Vector2& vector)
		{
			_x /= vector._x;
			_y /= vector._y;
			return *this;
		}
		Vector2& Vector2::operator/=(float val)
		{
			_x /= val;
			_y /= val;
			return *this;
		}

		bool Vector2::operator==(const Vector2& vector) const
		{
			return _x == vector._x && _y == vector._y;
		}
		bool Vector2::operator==(float val) const
		{
			return _x == val && _y == val;
		}
		bool Vector2::operator!=(const Vector2& vector) const
		{
			return !(*this == vector);
		}
		bool Vector2::operator!=(float val) const
		{
			return !(*this == val);
		}
		bool Vector2::operator>=(const Vector2& vector) const
		{
			return _x >= vector._x && _y >= vector._y;
		}
		bool Vector2::operator>=(float val) const
		{
			return _x >= val && _y >= val;
		}
		bool Vector2::operator>(const Vector2& vector) const
		{
			return _x > vector._x && _y > vector._y;
		}
		bool Vector2::operator>(float val) const
		{
			return _x > val && _y > val;
		}
		bool Vector2::operator<=(const Vector2& vector) const
		{
			return _x <= vector._x && _y <= vector._y;
		}
		bool Vector2::operator<=(float val) const
		{
			return _x <= val && _y <= val;
		}
		bool Vector2::operator<(const Vector2& vector) const
		{
			return _x < vector._x && _y < vector._y;
		}
		bool Vector2::operator<(float val) const
		{
			return _x < val && _y < val;
		}

		String Vector2::ToString() const
		{
			std::stringstream result;
			result << "Vector2: (" << _x << ", " << _y << ")";
			return result.str();
		}
	}
}