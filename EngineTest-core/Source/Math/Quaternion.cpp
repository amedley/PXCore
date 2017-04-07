#include "Quaternion.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace EngineTest
{
	namespace Math
	{

#define _VECTORMATH_SLERP_TOL 0.999f

		Quaternion::Quaternion()
		{
			_x = 0.0f;
			_y = 0.0f;
			_z = 0.0f;
			_w = 1.0f;
		}

		Quaternion::Quaternion(const Quaternion& quaternion)
		{
			_x = quaternion._x;
			_y = quaternion._y;
			_z = quaternion._z;
			_w = quaternion._w;
		}

		Quaternion::Quaternion(float x, float y, float z, float w)
		{
			_x = x;
			_y = y;
			_z = z;
			_w = w;
		}

		Quaternion::Quaternion(const Vector4& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			_w = vector._w;
		}

		Quaternion::Quaternion(float scalar)
		{
			_x = scalar;
			_y = scalar;
			_z = scalar;
			_w = scalar;
		}

		Quaternion::Quaternion(const Vector3& xyz, float w)
		{
			SetXYZ(xyz);
			_w = w;
		}

		Quaternion Quaternion::Identity()
		{
			return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
		}

		Quaternion Quaternion::FromEulerAngles(const Vector3& angles)
		{
			Quaternion pitch(Vector3(1.0, 0.0, 0.0), angles._x);
			Quaternion yaw(Vector3(0.0, 1.0, 0.0), angles._y);
			Quaternion roll(Vector3(0.0, 0.0, 1.0), angles._z);
			return pitch * yaw * roll;
		}

		Quaternion& Quaternion::operator=(const Quaternion& quaternion)
		{
			_x = quaternion._x;
			_y = quaternion._y;
			_z = quaternion._z;
			_w = quaternion._w;
			return *this;
		}

		Quaternion& Quaternion::SetXYZ(const Vector3& vector)
		{
			_x = vector._x;
			_y = vector._y;
			_z = vector._z;
			return *this;
		}

		const Vector3 Quaternion::GetXYZ() const
		{
			return Vector3(_x, _y, _z);
		}

		Quaternion& Quaternion::SetElem(int32 index, float value)
		{
			*(&_x + index) = value;
			return *this;
		}

		float Quaternion::GetElem(int32 index) const
		{
			return *(&_x + index);
		}

		float Quaternion::operator[](int32 index) const
		{
			return *(&_x + index);
		}

		Vector3 Quaternion::GetAxis() const
		{
			float x = 1.0f - _w * _w;
			if (x < 0.0000001f) // Divide by zero safety check
				return Vector3::XAxis();

			float x2 = x * x;
			return GetXYZ() / x2;
		}

		Vector3 Quaternion::ToEulerAngles() const
		{
			return Vector3(atan2(2 * _x * _w - 2 * _y * _z, 1 - 2 * _x * _x - 2 * _z * _z),
				atan2(2 * _y * _w - 2 * _x * _z, 1 - 2 * _y * _y - 2 * _z * _z),
				asin(2 * _x * _y + 2 * _z * _w));
		}

		const Quaternion Quaternion::operator+(const Quaternion& quaternion) const
		{
			return Quaternion(_x + quaternion._x, _y + quaternion._y, _z + quaternion._z, _w + quaternion._w);
		}

		const Quaternion Quaternion::operator-(const Quaternion& quaternion) const
		{
			return Quaternion(_x - quaternion._x, _y - quaternion._y, _z - quaternion._z, _w - quaternion._w);
		}

		const Quaternion Quaternion::operator*(float scalar) const
		{
			return Quaternion(_x * scalar, _y * scalar, _z * scalar, _w * scalar);
		}

		const Quaternion Quaternion::operator/(float scalar) const
		{
			return Quaternion(_x / scalar, _y / scalar, _z / scalar, _w / scalar);
		}

		const Quaternion Quaternion::operator-() const
		{
			return Quaternion(-_x, -_y, -_z, -_w);
		}

		bool Quaternion::operator==(const Quaternion& quaternion) const
		{
			return _x == quaternion._x && _y == quaternion._y && _z == quaternion._z && _w == quaternion._w;
		}

		bool Quaternion::operator!=(const Quaternion& quaternion) const
		{
			return !(*this == quaternion);
		}

		float Norm(const Quaternion& quaternion)
		{
			return quaternion._x * quaternion._x + quaternion._y * quaternion._y + quaternion._z * quaternion._z + quaternion._w * quaternion._w;
		}

		float Length(const Quaternion& quaternion)
		{
			return sqrt(Norm(quaternion));
		}

		const Quaternion Normalize(const Quaternion& quaternion)
		{
			return quaternion / sqrtf(Norm(quaternion));
		}

		const Quaternion Quaternion::Rotation(const Vector3& unitVec0, const Vector3& unitVec1)
		{
			float cosHalfAngleX2, recipCosHalfAngleX2;
			cosHalfAngleX2 = sqrt((2.0f * (1.0f + unitVec0.Dot(unitVec1))));
			recipCosHalfAngleX2 = (1.0f / cosHalfAngleX2);
			return Quaternion((unitVec0.Cross(unitVec1) * recipCosHalfAngleX2), (cosHalfAngleX2 * 0.5f));
		}

		const Quaternion Quaternion::Rotation(float radians, const Vector3& unitVec)
		{
			float angle = radians * 0.5f;
			return Quaternion((unitVec * sin(angle)), cos(angle));
		}

		const Quaternion Quaternion::operator*(const Quaternion& quaternion) const
		{
			return Normalize(Quaternion(
				(((_w * quaternion._x) + (_x * quaternion._w)) + (_y * quaternion._z)) - (_z * quaternion._y),
				(((_w * quaternion._y) + (_y * quaternion._w)) + (_z * quaternion._x)) - (_x * quaternion._z),
				(((_w * quaternion._z) + (_z * quaternion._w)) + (_x * quaternion._y)) - (_y * quaternion._x),
				(((_w * quaternion._w) - (_x * quaternion._x)) - (_y * quaternion._y)) - (_z * quaternion._z)
			));
		}

		Vector3 Quaternion::Rotate(const Quaternion& quaternion, const Vector3& vector)
		{
			float tmpX, tmpY, tmpZ, tmpW;
			tmpX = (((quaternion._w * vector._x) + (quaternion._y * vector._z)) - (quaternion._z * vector._y));
			tmpY = (((quaternion._w * vector._y) + (quaternion._z * vector._x)) - (quaternion._x * vector._z));
			tmpZ = (((quaternion._w * vector._z) + (quaternion._x * vector._y)) - (quaternion._y * vector._x));
			tmpW = (((quaternion._x * vector._x) + (quaternion._y * vector._y)) + (quaternion._z * vector._z));
			return Vector3(
				((((tmpW * quaternion._x) + (tmpX * quaternion._w)) - (tmpY * quaternion._z)) + (tmpZ * quaternion._y)),
				((((tmpW * quaternion._y) + (tmpY * quaternion._w)) - (tmpZ * quaternion._x)) + (tmpX * quaternion._z)),
				((((tmpW * quaternion._z) + (tmpZ * quaternion._w)) - (tmpX * quaternion._y)) + (tmpY * quaternion._x))
			);
		}

		Quaternion Quaternion::Conjugate() const
		{
			return Quaternion(-_x, -_y, -_z, _w);
		}

		const Quaternion Select(const Quaternion& quat0, const Quaternion& quat1, bool select1)
		{
			return Quaternion(select1 ? quat1._x : quat0._x, select1 ? quat1._y : quat0._y, select1 ? quat1._z : quat0._z, select1 ? quat1._w : quat0._w);
		}

		float Quaternion::Dot(const Quaternion& other) const
		{
			float result = (_x * other._x);
			result = (result + (_y * other._y));
			result = (result + (_z * other._z));
			result = (result + (_w * other._w));
			return result;
		}

	}
}