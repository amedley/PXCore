#ifndef MATRIX4_H
#define MATRIX4_H

#include "../Common.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

namespace EngineTest
{
	namespace Math
	{
		struct Matrix4
		{
			union
			{
				float _elements[16];
				Vector4 _rows[4];
			};
			Matrix4();
			Matrix4(const Matrix4& matrix);
			Matrix4(float diagonal);
			Matrix4(float* elements);
			Matrix4(const Vector4& column0, const Vector4& row1, const Vector4& row2, const Vector4& row3);

			Matrix4& Invert();

			Vector4 GetColumn(int index) const;
			void SetColumn(uint32_t index, const Vector4& column);
			inline Vector3 GetPosition() const { return Vector3(GetColumn(3)); }
			inline void SetPosition(const Vector3& position) { SetColumn(3, Vector4(position, 1.0f)); }

			Matrix4 operator*(const Matrix4& matrix) const;
			Matrix4& operator*=(const Matrix4& matrix);

			static Matrix4 Identity();
			
			static Matrix4 Orthographic(double left, double right, double top, double bottom, double near, double far);
			static Matrix4 Perspective(double fov, double aspectRatio, double near, double far);
			static Matrix4 LookAt(const Vector3& eye, const Vector3& at, const Vector3& up);

			static Matrix4 Translate(const Vector3& translate);
			static Matrix4 Scale(const Vector3& scale);
			static Matrix4 Rotate(double angle, const Vector3& axis);
			static Matrix4 Invert(const Matrix4& matrix);

			static Matrix4 Transpose(const Matrix4& matrix);

			String ToString() const;
		};
	}
}

#endif;