#ifndef MATRIX4_H
#define MATRIX4_H

#include "Math.h"
#include <math.h>
#include "../Debug.h"

namespace EngineTest
{
	namespace Math
	{
		typedef union Matrix4
		{
			float _elements[16];
			Vector4 _columns[4];

			Matrix4();
			Matrix4(float diagonal);

			static Matrix4 Identitiy();
			
			static Matrix4 Orthographic(double left, double right, double top, double bottom, double near, double far);
			static Matrix4 Perspective(double fov, double aspectRatio, double near, double far);
			static Matrix4 LookAt(const Vector3& eye, const Vector3& at, const Vector3& up);

			static Matrix4 Translate(const Vector3& translate);
			static Matrix4 Scale(const Vector3& scale);
			static Matrix4 Rotate(double angle, const Vector3& axis);

			Matrix4 Multiply(const Matrix4& matrix) const;
			Matrix4& MultiplyEquals(const Matrix4& matrix);

			friend Matrix4 operator*(const Matrix4& left, const Matrix4& right);
			friend Matrix4& operator*=(Matrix4& left, const Matrix4& right);

			void Log();

		} Matrixf;
	}
}

#endif;