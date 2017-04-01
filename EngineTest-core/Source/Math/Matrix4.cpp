#include "Matrix4.h"
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
		Matrix4::Matrix4(const Vector4& row0, const Vector4& row1, const Vector4& row2, const Vector4& row3)
		{
			_rows[0] = row0;
			_rows[1] = row1;
			_rows[2] = row2;
			_rows[3] = row3;
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

		Vector4 Matrix4::GetColumn(int index) const
		{
			return Vector4(_elements[index], _elements[index + 4], _elements[index + 8], _elements[index + 12]);
		}
		void Matrix4::SetColumn(uint32_t index, const Vector4& column)
		{
			_elements[index] = column._x;
			_elements[index + 4] = column._y;
			_elements[index + 8] = column._z;
			_elements[index + 12] = column._w;
		}

		Matrix4 Matrix4::operator*(const Matrix4& matrix) const
		{
			Matrix4 result;
			float* src = (float*)&matrix;
			float* data = (float*)&result;
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += _elements[x + e * 4] * src[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}
			return result;
		}
		Matrix4& Matrix4::operator*=(const Matrix4& matrix)
		{
			float* src = (float*)&matrix;

			/*float data[]
			{
				_elements[0] * src[0]  +	_elements[4] * src[1]  +	_elements[8]  * src[2]  +	_elements[12] * src[3],
				_elements[1] * src[0]  +	_elements[5] * src[1]  +	_elements[9]  * src[2]  +	_elements[13] * src[3],
				_elements[2] * src[0]  +	_elements[6] * src[1]  +	_elements[10] * src[2]  +	_elements[14] * src[3],
				_elements[3] * src[0]  +	_elements[7] * src[1]  +	_elements[11] * src[2]  +	_elements[15] * src[3],
				_elements[0] * src[4]  +	_elements[4] * src[5]  +	_elements[8]  * src[6]  +	_elements[12] * src[7],
				_elements[1] * src[4]  +	_elements[5] * src[5]  +	_elements[9]  * src[6]  +	_elements[13] * src[7],
				_elements[2] * src[4]  +	_elements[6] * src[5]  +	_elements[10] * src[6]  +	_elements[14] * src[7],
				_elements[3] * src[4]  +	_elements[7] * src[5]  +	_elements[11] * src[6]  +	_elements[15] * src[7],
				_elements[0] * src[8]  +	_elements[4] * src[9]  +	_elements[8]  * src[10] +	_elements[12] * src[11],
				_elements[1] * src[8]  +	_elements[5] * src[9]  +	_elements[9]  * src[10] +	_elements[13] * src[11],
				_elements[2] * src[8]  +	_elements[6] * src[9]  +	_elements[10] * src[10] +	_elements[14] * src[11],
				_elements[3] * src[8]  +	_elements[7] * src[9]  +	_elements[11] * src[10] +	_elements[15] * src[11],
				_elements[0] * src[12] +	_elements[4] * src[13] +	_elements[8]  * src[14] +	_elements[12] * src[15],
				_elements[1] * src[12] +	_elements[5] * src[13] +	_elements[9]  * src[14] +	_elements[13] * src[15],
				_elements[2] * src[12] +	_elements[6] * src[13] +	_elements[10] * src[14] +	_elements[14] * src[15],
				_elements[3] * src[12] +	_elements[7] * src[13] +	_elements[11] * src[14] +	_elements[15] * src[15]
			};*/

			float data[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0;
					for (int e = 0; e < 4; e++)
					{
						sum += _elements[x + e * 4] * src[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}

			memcpy(_elements, data, sizeof(float) * 16);
			return *this;
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
			Matrix4 result(1.0f);

			double q = 1.0 / tan(ToRadians(0.5 * fov));
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

			Vector3 f = (at - eye).NormalizeEquals();
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

			return result *= Matrix4::Translate(Vector3(-eye._x, -eye._y, -eye._z));
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
		Matrix4 Matrix4::Rotate(const double angle, const Vector3& axis)
		{
			double r = ToRadians(angle);
			double c = cos(r);
			double omc = 1.0 - c;
			double s = sin(r);

			double x = (double)axis._x;
			double y = (double)axis._y;
			double z = (double)axis._z;

			Matrix4 result(1.0f);

			result._elements[0] = (float)(x * x * omc + c);
			result._elements[1] = (float)(x * y * omc + z * s);
			result._elements[2] = (float)(x * z * omc - y * s);

			result._elements[4] = (float)(y * x * omc - z * s);
			result._elements[5] = (float)(y * y * omc + c);
			result._elements[6] = (float)(y * z * omc + x * s);

			result._elements[8] = (float)(z * x * omc - y * s);
			result._elements[9] = (float)(z * y * omc - x * s);
			result._elements[10] = (float)(z * z * omc + c);

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
				Vector4(matrix._rows[0]._x, matrix._rows[1]._x, matrix._rows[2]._x, matrix._rows[3]._x),
				Vector4(matrix._rows[0]._y, matrix._rows[1]._y, matrix._rows[2]._y, matrix._rows[3]._y),
				Vector4(matrix._rows[0]._z, matrix._rows[1]._z, matrix._rows[2]._z, matrix._rows[3]._z),
				Vector4(matrix._rows[0]._w, matrix._rows[1]._w, matrix._rows[2]._w, matrix._rows[3]._w)
			);
		}


		String Matrix4::ToString() const
		{
			std::stringstream result;
			result << "Matrix4:\n(" << _rows[0]._x << ", " << _rows[1]._x << ", " << _rows[2]._x << ", " << _rows[3]._x << "),\n";
			result << "(" << _rows[0]._y << ", " << _rows[1]._y << ", " << _rows[2]._y << ", " << _rows[3]._y << "),\n";
			result << "(" << _rows[0]._z << ", " << _rows[1]._z << ", " << _rows[2]._z << ", " << _rows[3]._z << "),\n";
			result << "(" << _rows[0]._w << ", " << _rows[1]._w << ", " << _rows[2]._w << ", " << _rows[3]._w << ")\n";
			return result.str();
		}
	}
}