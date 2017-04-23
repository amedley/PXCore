#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Matrix4.h"

namespace EngineTest { namespace Math {
	Vector3::Vector3()
	{
		_x = 0.0f;
		_y = 0.0f;
		_z = 0.0f;
	}
	Vector3::Vector3(float scalar)
	{
		_x = scalar;
		_y = scalar;
		_z = scalar;
	}
	Vector3::Vector3(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}
	Vector3::Vector3(const Vector2& vector)
	{
		_x = vector._x;
		_y = vector._y;
		_z = 0.0f;
	}
	Vector3::Vector3(const Vector3& vector)
	{
		_x = vector._x;
		_y = vector._y;
		_z = vector._z;
	}
	Vector3::Vector3(const Vector4& vector)
	{
		_x = vector._x;
		_y = vector._y;
		_z = vector._z;
	}

	Vector3 Vector3::Up()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}
	Vector3 Vector3::Down()
	{
		return Vector3(0.0f, -1.0f, 0.0f);
	}
	Vector3 Vector3::Left()
	{
		return Vector3(-1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::Right()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::Zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::XAxis()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	Vector3 Vector3::YAxis()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}
	Vector3 Vector3::ZAxis()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
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

	Vector3& Vector3::operator=(const Vector3& vector)
	{
		_x = vector._x;
		_y = vector._y;
		_z = vector._z;
		return *this;
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
		Vector3 result = *this;
		float mag = Magnitude();
		if (mag == 0.0f)
			return Vector3(1.0f, 1.0f, 1.0f).NormalizeEquals();
		return result / Magnitude();
	}
	Vector3& Vector3::NormalizeEquals()
	{
		float mag = Magnitude();
		if (mag == 0.0f)
		{
			_x = _y = _z = 1.0f;
			*this /= Magnitude();
			return *this;
		}
		*this /= Magnitude();
		return *this;
	}

	Vector3 Vector3::Multiply(const Matrix4& transform) const
	{
		return Vector3(
			transform[0] * _x + transform[4] * _y + transform[8] * _z + transform[12],
			transform[1] * _x + transform[5] * _y + transform[9] * _z + transform[13],
			transform[2] * _x + transform[6] * _y + transform[10] * _z + transform[14]
		);
	}

	Vector3 Vector3::operator+(const Vector3& vector) const
	{
		return Vector3(_x + vector._x, _y + vector._y, _z + vector._z);
	}
	Vector3 Vector3::operator+(float val) const
	{
		return Vector3(_x + val, _y + val, _z + val);
	}
	Vector3& Vector3::operator+=(const Vector3& vector)
	{
		_x += vector._x;
		_y += vector._y;
		_z += vector._z;
		return *this;
	}
	Vector3& Vector3::operator+=(float val)
	{
		_x += val;
		_y += val;
		_z += val;
		return *this;
	}

	Vector3 Vector3::operator-(const Vector3& vector) const
	{
		return Vector3(_x - vector._x, _y - vector._y, _z - vector._z);
	}
	Vector3 Vector3::operator-(float val) const
	{
		return Vector3(_x - val, _y - val, _z - val);
	}
	Vector3& Vector3::operator-=(const Vector3& vector)
	{
		_x -= vector._x;
		_y -= vector._y;
		_z -= vector._z;
		return *this;
	}
	Vector3& Vector3::operator-=(float val)
	{
		_x -= val;
		_y -= val;
		_z -= val;
		return *this;
	}

	Vector3 Vector3::operator*(const Vector3& vector) const
	{
		return Vector3(_x * vector._x, _y * vector._y, _z * vector._z);
	}
	Vector3 Vector3::operator*(float val) const
	{
		return Vector3(_x * val, _y * val, _z * val);
	}
	Vector3& Vector3::operator*=(const Vector3& vector)
	{
		_x *= vector._x;
		_y *= vector._y;
		_z *= vector._z;
		return *this;
	}
	Vector3& Vector3::operator*=(float val)
	{
		_x *= val;
		_y *= val;
		_z *= val;
		return *this;
	}

	Vector3 Vector3::operator/(const Vector3& vector) const
	{
		return Vector3(_x / vector._x, _y / vector._y, _z / vector._z);
	}
	Vector3 Vector3::operator/(float val) const
	{
		return Vector3(_x / val, _y / val, _z / val);
	}
	Vector3& Vector3::operator/=(const Vector3& vector)
	{
		_x /= vector._x;
		_y /= vector._y;
		_z /= vector._z;
		return *this;
	}
	Vector3& Vector3::operator/=(float val)
	{
		_x /= val;
		_y /= val;
		_z /= val;
		return *this;
	}

	bool Vector3::operator==(const Vector3& vector) const
	{
		return _x == vector._x && _y == vector._y && _z == vector._z;
	}
	bool Vector3::operator==(float val) const
	{
		return _x == val && _y == val && _z == val;
	}
	bool Vector3::operator!=(const Vector3& vector) const
	{
		return !(*this == vector);
	}
	bool Vector3::operator!=(float val) const
	{
		return !(*this == val);
	}
	bool Vector3::operator>=(const Vector3& vector) const
	{
		return _x >= vector._x && _y >= vector._y && _z >= vector._z;
	}
	bool Vector3::operator>=(float val) const
	{
		return _x >= val && _y >= val && _z >= val;
	}
	bool Vector3::operator>(const Vector3& vector) const
	{
		return _x > vector._x && _y > vector._y && _z > vector._z;
	}
	bool Vector3::operator>(float val) const
	{
		return _x > val && _y > val && _z > val;
	}
	bool Vector3::operator<=(const Vector3& vector) const
	{
		return _x <= vector._x && _y <= vector._y && _z <= vector._z;
	}
	bool Vector3::operator<=(float right) const
	{
		return _x <= right && _y <= right && _z <= right;
	}
	bool Vector3::operator<(const Vector3& vector) const
	{
		return _x < vector._x && _y < vector._y && _z < vector._z;
	}
	bool Vector3::operator<(float val) const
	{
		return _x < val && _y < val && _z < val;
	}

	Vector3 operator-(const Vector3& vector)
	{
		return Vector3(-vector._x, -vector._y, -vector._z);
	}

	String Vector3::ToString() const
	{
		std::stringstream result;
		result << "Vector3: (" << _x << ", " << _y << ", " << _z << ")";
		return result.str();
	}
}}