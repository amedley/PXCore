#include "Math.h"

namespace EngineTest
{
	namespace Math
	{
		Matrix4::Matrix4()
		{
			memset(_elements, 0, 16 * sizeof(float));
		}
		Matrix4::Matrix4(const Matrix4& matrix)
		{
			memcpy(_elements, matrix._elements, 16 * sizeof(float));
		}
		Matrix4::Matrix4(float* elements)
		{
			memcpy(_elements, elements, 16 * sizeof(float));
		}
		Matrix4::Matrix4(float diagonal)
		{
			for (int i = 0; i < 16; i++)
				_elements[i] = 0.0f;
			_elements[0] = _elements[5] = _elements[10] = _elements[15] = diagonal; 
		}
		Matrix4::Matrix4(const Vector4& column0, const Vector4& column1, const Vector4& column2, const Vector4& column3)
		{
			_columns[0] = column0;
			_columns[1] = column1;
			_columns[2] = column2;
			_columns[3] = column3;
		}

		Matrix4& Matrix4::Invert()
		{
			float temp[16];
			
			temp[0] = _elements[5] * _elements[10] * _elements[15] -
				_elements[5] * _elements[11] * _elements[14] -
				_elements[9] * _elements[6] * _elements[15] +
				_elements[9] * _elements[7] * _elements[14] +
				_elements[13] * _elements[6] * _elements[11] -
				_elements[13] * _elements[7] * _elements[10];

			temp[4] = -_elements[4] * _elements[10] * _elements[15] +
				_elements[4] * _elements[11] * _elements[14] +
				_elements[8] * _elements[6] * _elements[15] -
				_elements[8] * _elements[7] * _elements[14] -
				_elements[12] * _elements[6] * _elements[11] +
				_elements[12] * _elements[7] * _elements[10];

			temp[8] = _elements[4] * _elements[9] * _elements[15] -
				_elements[4] * _elements[11] * _elements[13] -
				_elements[8] * _elements[5] * _elements[15] +
				_elements[8] * _elements[7] * _elements[13] +
				_elements[12] * _elements[5] * _elements[11] -
				_elements[12] * _elements[7] * _elements[9];

			temp[12] = -_elements[4] * _elements[9] * _elements[14] +
				_elements[4] * _elements[10] * _elements[13] +
				_elements[8] * _elements[5] * _elements[14] -
				_elements[8] * _elements[6] * _elements[13] -
				_elements[12] * _elements[5] * _elements[10] +
				_elements[12] * _elements[6] * _elements[9];

			temp[1] = -_elements[1] * _elements[10] * _elements[15] +
				_elements[1] * _elements[11] * _elements[14] +
				_elements[9] * _elements[2] * _elements[15] -
				_elements[9] * _elements[3] * _elements[14] -
				_elements[13] * _elements[2] * _elements[11] +
				_elements[13] * _elements[3] * _elements[10];

			temp[5] = _elements[0] * _elements[10] * _elements[15] -
				_elements[0] * _elements[11] * _elements[14] -
				_elements[8] * _elements[2] * _elements[15] +
				_elements[8] * _elements[3] * _elements[14] +
				_elements[12] * _elements[2] * _elements[11] -
				_elements[12] * _elements[3] * _elements[10];

			temp[9] = -_elements[0] * _elements[9] * _elements[15] +
				_elements[0] * _elements[11] * _elements[13] +
				_elements[8] * _elements[1] * _elements[15] -
				_elements[8] * _elements[3] * _elements[13] -
				_elements[12] * _elements[1] * _elements[11] +
				_elements[12] * _elements[3] * _elements[9];

			temp[13] = _elements[0] * _elements[9] * _elements[14] -
				_elements[0] * _elements[10] * _elements[13] -
				_elements[8] * _elements[1] * _elements[14] +
				_elements[8] * _elements[2] * _elements[13] +
				_elements[12] * _elements[1] * _elements[10] -
				_elements[12] * _elements[2] * _elements[9];

			temp[2] = _elements[1] * _elements[6] * _elements[15] -
				_elements[1] * _elements[7] * _elements[14] -
				_elements[5] * _elements[2] * _elements[15] +
				_elements[5] * _elements[3] * _elements[14] +
				_elements[13] * _elements[2] * _elements[7] -
				_elements[13] * _elements[3] * _elements[6];

			temp[6] = -_elements[0] * _elements[6] * _elements[15] +
				_elements[0] * _elements[7] * _elements[14] +
				_elements[4] * _elements[2] * _elements[15] -
				_elements[4] * _elements[3] * _elements[14] -
				_elements[12] * _elements[2] * _elements[7] +
				_elements[12] * _elements[3] * _elements[6];

			temp[10] = _elements[0] * _elements[5] * _elements[15] -
				_elements[0] * _elements[7] * _elements[13] -
				_elements[4] * _elements[1] * _elements[15] +
				_elements[4] * _elements[3] * _elements[13] +
				_elements[12] * _elements[1] * _elements[7] -
				_elements[12] * _elements[3] * _elements[5];

			temp[14] = -_elements[0] * _elements[5] * _elements[14] +
				_elements[0] * _elements[6] * _elements[13] +
				_elements[4] * _elements[1] * _elements[14] -
				_elements[4] * _elements[2] * _elements[13] -
				_elements[12] * _elements[1] * _elements[6] +
				_elements[12] * _elements[2] * _elements[5];

			temp[3] = -_elements[1] * _elements[6] * _elements[11] +
				_elements[1] * _elements[7] * _elements[10] +
				_elements[5] * _elements[2] * _elements[11] -
				_elements[5] * _elements[3] * _elements[10] -
				_elements[9] * _elements[2] * _elements[7] +
				_elements[9] * _elements[3] * _elements[6];

			temp[7] = _elements[0] * _elements[6] * _elements[11] -
				_elements[0] * _elements[7] * _elements[10] -
				_elements[4] * _elements[2] * _elements[11] +
				_elements[4] * _elements[3] * _elements[10] +
				_elements[8] * _elements[2] * _elements[7] -
				_elements[8] * _elements[3] * _elements[6];

			temp[11] = -_elements[0] * _elements[5] * _elements[11] +
				_elements[0] * _elements[7] * _elements[9] +
				_elements[4] * _elements[1] * _elements[11] -
				_elements[4] * _elements[3] * _elements[9] -
				_elements[8] * _elements[1] * _elements[7] +
				_elements[8] * _elements[3] * _elements[5];

			temp[15] = _elements[0] * _elements[5] * _elements[10] -
				_elements[0] * _elements[6] * _elements[9] -
				_elements[4] * _elements[1] * _elements[10] +
				_elements[4] * _elements[2] * _elements[9] +
				_elements[8] * _elements[1] * _elements[6] -
				_elements[8] * _elements[2] * _elements[5];

			float determinant = _elements[0] * temp[0] + _elements[1] * temp[4] + _elements[2] * temp[8] + _elements[3] * temp[12];
			determinant = 1.0f / determinant;

			for (int i = 0; i < 4 * 4; i++)
				_elements[i] = temp[i] * determinant;

			return *this;
		}

		float Matrix4::operator[](int index) const
		{
			return _elements[index];
		}
		float& Matrix4::operator[](int index)
		{
			return _elements[index];
		}

		Matrix4& Matrix4::operator=(const Matrix4& matrix)
		{
			memcpy((void*) _elements, matrix._elements, 64);
			return *this;
		}
		Matrix4 Matrix4::operator*(const Matrix4& matrix) const
		{
			Matrix4 r;

			r[0] =	_elements[0] * matrix[0] +	_elements[4] * matrix[1] +	_elements[8] *	matrix[2] +	 _elements[12] * matrix[3];
			r[1] =	_elements[1] * matrix[0] +	_elements[5] * matrix[1] +	_elements[9] *	matrix[2] +	 _elements[13] * matrix[3];
			r[2] =	_elements[2] * matrix[0] +	_elements[6] * matrix[1] +	_elements[10] * matrix[2] +	 _elements[14] * matrix[3];
			////r[3] = 0.0f;
			r[3] =	_elements[3] * matrix[0] +	_elements[7] * matrix[1] +	_elements[11] * matrix[2] +	 _elements[15] * matrix[3];
			r[4] =	_elements[0] * matrix[4] +	_elements[4] * matrix[5] +	_elements[8] *	matrix[6] +	 _elements[12] * matrix[7];
			r[5] =	_elements[1] * matrix[4] +	_elements[5] * matrix[5] +	_elements[9] *	matrix[6] +	 _elements[13] * matrix[7];
			r[6] =	_elements[2] * matrix[4] +	_elements[6] * matrix[5] +	_elements[10] * matrix[6] +	 _elements[14] * matrix[7];
			//r[7] = 0.0f;
			r[7] =	_elements[3] * matrix[4] +	_elements[7] * matrix[5] +	_elements[11] * matrix[6] +	 _elements[15] * matrix[7];
			r[8] =	_elements[0] * matrix[8] +	_elements[4] * matrix[9] +	_elements[8] *	matrix[10] + _elements[12] * matrix[11];
			r[9] =	_elements[1] * matrix[8] +	_elements[5] * matrix[9] +	_elements[9] *	matrix[10] + _elements[13] * matrix[11];
			r[10] = _elements[2] * matrix[8] +	_elements[6] * matrix[9] +	_elements[10] * matrix[10] + _elements[14] * matrix[11];
			//r[11] = 0.0f;
			r[11] = _elements[3] * matrix[8] +	_elements[7] * matrix[9] +	_elements[11] * matrix[10] + _elements[15] * matrix[11];
			r[12] = _elements[0] * matrix[12] +	_elements[4] * matrix[13] + _elements[8] *	matrix[14] + _elements[12] * matrix[15];
			r[13] = _elements[1] * matrix[12] +	_elements[5] * matrix[13] +	_elements[9] *	matrix[14] + _elements[13] * matrix[15];
			r[14] = _elements[2] * matrix[12] +	_elements[6] * matrix[13] +	_elements[10] * matrix[14] + _elements[14] * matrix[15];
			//r[15] = 1.0f;
			r[15] = _elements[3] * matrix[12] +	_elements[7] * matrix[13] +	_elements[11] * matrix[14] + _elements[15] * matrix[15];

			return r;
		}

		Vector3 Matrix4::GetPosition() const
		{
			return Vector3(_elements[12], _elements[13], _elements[14]);
		}
		void Matrix4::SetPosition(Vector3& position)
		{
			_elements[12] = position._x;
			_elements[13] = position._y;
			_elements[14] = position._z;
		}

		Matrix4 Matrix4::Identity()
		{
			return Matrix4(1.0f);
		}
		Matrix4 Matrix4::Orthographic(double left, double right, double top, double bottom, double near, double far)
		{
			Matrix4 result(1.0f);

			result._elements[0] = (float)(2.0 / (right - left));
			result._elements[5] = (float)(2.0 / (top - bottom));
			result._elements[10] = (float)(2.0 / (near - far));
			result._elements[12] = (float)((left + right) / (left - right));
			result._elements[13] = (float)((bottom + top) / (bottom - top));
			result._elements[14] = (float)((far + near) / (far - near));

			return result;
		}
		Matrix4 Matrix4::Perspective(double fov, double aspectRatio, double near, double far)
		{
			Matrix4 result;

			double q = 1.0 / tan(ToRadians(fov * 0.5f));
			double a = q / aspectRatio;
			double b = (near + far) / (near - far);
			double c = (2.0 * near * far) / (near - far);

			result._elements[0] = (float)a;
			result._elements[5] = (float)q;
			result._elements[10] = (float)b;
			result._elements[11] = -1.0f;
			result._elements[14] = (float)c;

			return result;
		}
		Matrix4 Matrix4::LookAt(const Vector3& eye, const Vector3& at, const Vector3& up)
		{
			Matrix4 result(1.0f);

			Vector3 f = (at - eye).Normalize();
			Vector3 s = f.Cross(up.Normalize());
			Vector3 u = s.Cross(f);


			result._elements[0] = s._x;
			result._elements[4] = s._y;
			result._elements[8] = s._z;

			result._elements[1] = u._x;
			result._elements[5] = u._y;
			result._elements[9] = u._z;

			result._elements[2] = -f._x;
			result._elements[6] = -f._y;
			result._elements[10] = -f._z;

			result = result * Matrix4::Translate(Vector3(-eye._x, -eye._y, -eye._z));
			return result;
		}
		Matrix4 Matrix4::Translate(const Vector3& translate)
		{
			Matrix4 result(1.0f);

			result._elements[12] = translate._x;
			result._elements[13] = translate._y;
			result._elements[14] = translate._z;

			return result;
		}
		Matrix4 Matrix4::Scale(const Vector3& scale)
		{
			Matrix4 result(1.0f);

			result._elements[0] = scale._x;
			result._elements[5] = scale._y;
			result._elements[10] = scale._z;

			return result;
		}
		Matrix4 Matrix4::Rotate(float radians, const Vector3& unitVec)
		{
			double c = cos(radians);
			double omc = 1.0 - c;
			double s = sin(radians);

			double x = (double)unitVec._x;
			double y = (double)unitVec._y;
			double z = (double)unitVec._z;

			Matrix4 result(1.0f);

			result._elements[0] = (float)(x * x * omc + c);
			result._elements[1] = (float)(x * y * omc - z * s);
			result._elements[2] = (float)(x * z * omc + y * s);

			result._elements[4] = (float)(y * x * omc + z * s);
			result._elements[5] = (float)(y * y * omc + c);
			result._elements[6] = (float)(y * z * omc - x * s);

			result._elements[8] = (float)(z * x * omc - y * s);
			result._elements[9] = (float)(z * y * omc + x * s);
			result._elements[10] = (float)(z * z * omc + c);

			return result;
		}
		Matrix4 Matrix4::Rotate(const Quaternion& quat)
		{
			Matrix4 result = Identity();

			float qx, qy, qz, qw, qx2, qy2, qz2, qxqx2, qyqy2, qzqz2, qxqy2, qyqz2, qzqw2, qxqz2, qyqw2, qxqw2;
			qx = quat._x;
			qy = quat._y;
			qz = quat._z;
			qw = quat._w;
			qx2 = (qx + qx);
			qy2 = (qy + qy);
			qz2 = (qz + qz);
			qxqx2 = (qx * qx2);
			qxqy2 = (qx * qy2);
			qxqz2 = (qx * qz2);
			qxqw2 = (qw * qx2);
			qyqy2 = (qy * qy2);
			qyqz2 = (qy * qz2);
			qyqw2 = (qw * qy2);
			qzqz2 = (qz * qz2);
			qzqw2 = (qw * qz2);

			result._elements[0 + 0 * 4] = (1.0f - qyqy2) - qzqz2;
			result._elements[0 + 1 * 4] = qxqy2 - qzqw2;
			result._elements[0 + 2 * 4] = qxqz2 + qyqw2;

			result._elements[1 + 0 * 4] = qxqy2 + qzqw2;
			result._elements[1 + 1 * 4] = (1.0f - qxqx2) - qzqz2;
			result._elements[1 + 2 * 4] = qyqz2 - qxqw2;

			result._elements[2 + 0 * 4] = qxqz2 - qyqw2;
			result._elements[2 + 1 * 4] = qyqz2 + qxqw2;
			result._elements[2 + 2 * 4] = (1.0f - qxqx2) - qyqy2;

			return result;
		}
		Matrix4 Matrix4::Invert(const Matrix4& matrix)
		{
			Matrix4 result = matrix;
			return result.Invert();
		}

		Matrix4 Matrix4::Transpose(const Matrix4& matrix)
		{
			return Matrix4(
				Vector4(matrix._columns[0]._x, matrix._columns[1]._x, matrix._columns[2]._x, matrix._columns[3]._x),
				Vector4(matrix._columns[0]._y, matrix._columns[1]._y, matrix._columns[2]._y, matrix._columns[3]._y),
				Vector4(matrix._columns[0]._z, matrix._columns[1]._z, matrix._columns[2]._z, matrix._columns[3]._z),
				Vector4(matrix._columns[0]._w, matrix._columns[1]._w, matrix._columns[2]._w, matrix._columns[3]._w)
			);
		}


		String Matrix4::ToString() const
		{
			std::stringstream result;
			result << "Matrix4:\n(" << _columns[0]._x << ", " << _columns[1]._x << ", " << _columns[2]._x << ", " << _columns[3]._x << "),\n";
			result << "(" << _columns[0]._y << ", " << _columns[1]._y << ", " << _columns[2]._y << ", " << _columns[3]._y << "),\n";
			result << "(" << _columns[0]._z << ", " << _columns[1]._z << ", " << _columns[2]._z << ", " << _columns[3]._z << "),\n";
			result << "(" << _columns[0]._w << ", " << _columns[1]._w << ", " << _columns[2]._w << ", " << _columns[3]._w << ")\n";
			return result.str();
		}
	}
}