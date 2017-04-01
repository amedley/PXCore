#include "Vector2.h"
#include "Vector3.h"
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
		Vector4::Vector4(float scalar)
		{
			_x = scalar;
			_y = scalar;
			_z = scalar;
			_w = scalar;
		}
		Vector4::Vector4(float x, float y, float z, float w)
		{
			_x = x;
			_y = y;
			_z = z;
			_w = w;
		}
		Vector4::Vector4(const Vector2& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = 0.0f;
			_w = 0.0f;
		}
		Vector4::Vector4(const Vector3& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			_w = 0.0f;
		}
		Vector4::Vector4(const Vector3& vector, float w)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			_w = w;
		}
		Vector4::Vector4(const Vector4& vector)
		{

			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			_w = vector._w;
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

		Vector4& Vector4::operator=(const Vector4& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			_w = vector._w;
			return *this;
		}

		Vector4 Vector4::Normalize() const
		{
			Vector4 result = *this;
			return result / Magnitude();
		}
		Vector4& Vector4::NormalizeEquals()
		{
			*this /= Magnitude();
			return *this;
		}

		Vector4 Vector4::operator+(const Vector4& vector) const
		{
			return Vector4(_x + vector._x, _y + vector._y, _z + vector._z, _w + vector._w);
		}
		Vector4 Vector4::operator+(float val) const
		{
			return Vector4(_x + val, _y + val, _z + val, _w + val);
		}
		Vector4& Vector4::operator+=(const Vector4& vector)
		{
			_x += vector._x;
			_y += vector._y;
			_z += vector._z;
			_w += vector._w;
			return *this;
		}
		Vector4& Vector4::operator+=(float val)
		{
			_x += val;
			_y += val;
			_z += val;
			_w += val;
			return *this;
		}

		Vector4 Vector4::operator-(const Vector4& vector) const
		{
			return Vector4(_x - vector._x, _y - vector._y, _z - vector._z, _w - vector._w);
		}
		Vector4 Vector4::operator-(float val) const
		{
			return Vector4(_x - val, _y - val, _z - val, _w - val);
		}
		Vector4& Vector4::operator-=(const Vector4& vector)
		{
			_x -= vector._x;
			_y -= vector._y;
			_z -= vector._z;
			_w -= vector._w;
			return *this;
		}
		Vector4& Vector4::operator-=(float val)
		{
			_x -= val;
			_y -= val;
			_z -= val;
			_w -= val;
			return *this;
		}

		Vector4 Vector4::operator*(const Vector4& vector) const
		{
			return Vector4(_x * vector._x, _y * vector._y, _z * vector._z, _w * vector._w);
		}
		Vector4 Vector4::operator*(float val) const
		{
			return Vector4(_x * val, _y * val, _z * val, _w * val);
		}
		Vector4& Vector4::operator*=(const Vector4& vector)
		{
			_x *= vector._x;
			_y *= vector._y;
			_z *= vector._z;
			_w *= vector._w;
			return *this;
		}
		Vector4& Vector4::operator*=(float val)
		{
			_x *= val;
			_y *= val;
			_z *= val;
			_w *= val;
			return *this;
		}

		Vector4 Vector4::operator/(const Vector4& vector) const
		{
			return Vector4(_x / vector._x, _y / vector._y, _z / vector._z, _w / vector._w);
		}
		Vector4 Vector4::operator/(float val) const
		{
			return Vector4(_x / val, _y / val, _z / val, _w / val);
		}
		Vector4& Vector4::operator/=(const Vector4& vector)
		{
			_x /= vector._x;
			_y /= vector._y;
			_z /= vector._z;
			_w /= vector._w;
			return *this;
		}
		Vector4& Vector4::operator/=(float val)
		{
			_x /= val;
			_y /= val;
			_z /= val;
			_w /= val;
			return *this;
		}

		bool Vector4::operator==(const Vector4& vector) const
		{
			return _x == vector._x && _y == vector._y && _z == vector._z && _w == vector._w;
		}
		bool Vector4::operator==(float val) const
		{
			return _x == val && _y == val && _z == val && _w == val;
		}
		bool Vector4::operator!=(const Vector4& vector) const
		{
			return !(*this == vector);
		}
		bool Vector4::operator!=(float val) const
		{
			return !(*this == val);
		}
		bool Vector4::operator>=(const Vector4& vector) const
		{
			return _x >= vector._x && _y >= vector._y && _z >= vector._z && _w >= vector._w;
		}
		bool Vector4::operator>=(float val) const
		{
			return _x >= val && _y >= val && _z >= val && _w >= val;
		}
		bool Vector4::operator>(const Vector4& vector) const
		{
			return _x > vector._x && _y > vector._y && _z > vector._z && _w > vector._w;
		}
		bool Vector4::operator>(float val) const
		{
			return _x > val && _y > val && _z > val && _w > val;
		}
		bool Vector4::operator<=(const Vector4& vector) const
		{
			return _x <= vector._x && _y <= vector._y && _z <= vector._z && _w <= vector._w;
		}
		bool Vector4::operator<=(float val) const
		{
			return _x <= val && _y <= val && _z <= val && _w <= val;
		}
		bool Vector4::operator<(const Vector4& vector) const
		{
			return _x < vector._x && _y < vector._y && _z < vector._z && _w < vector._w;
		}
		bool Vector4::operator<(float val) const
		{
			return _x < val && _y < val && _z < val && _w < val;
		}

		String Vector4::ToString() const
		{
			std::stringstream result;
			result << "Vector4: (" << _x << ", " << _y << ", " << _z << ", " << _w << ")";
			return result.str();
		}
	}
}