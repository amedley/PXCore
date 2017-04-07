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
		struct Quaternion;

		struct Matrix4
		{
			union
			{
				float _elements[16];
				Vector4 _columns[4];
			};
			Matrix4();
			Matrix4(const Matrix4& matrix);
			Matrix4(float diagonal);
			Matrix4(float* elements);
			Matrix4(const Vector4& column0, const Vector4& column1, const Vector4& column2, const Vector4& column3);

			Matrix4& Invert();

			float operator[](int index) const;
			float& operator[](int index);

			Matrix4& operator=(const Matrix4& matrix);
			Matrix4 operator*(const Matrix4& matrix) const;

			Vector3 GetPosition() const;
			void SetPosition(Vector3& position);

			static Matrix4 Identity();
			
			static Matrix4 Orthographic(double left, double right, double top, double bottom, double near, double far);
			static Matrix4 Perspective(double fov, double aspectRatio, double near, double far);
			static Matrix4 LookAt(const Vector3& eye, const Vector3& at, const Vector3& up);

			static Matrix4 Translate(const Vector3& translate);
			static Matrix4 Scale(const Vector3& scale);
			static Matrix4 Rotate(float radians, const Vector3& unitVec);
			static Matrix4 Rotate(const Quaternion& quat);
			static Matrix4 Invert(const Matrix4& matrix);

			static Matrix4 Transpose(const Matrix4& matrix);

			String ToString() const;
		};
	}
}

#endif;