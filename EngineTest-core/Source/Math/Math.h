#ifndef MATH_H
#define MATH_H

#define _USE_MATH_DEFINES
#include <math.h>
#include "Vectors.h"

namespace EngineTest { namespace Math {

#define PI 3.141592653589793f
#define ToRadians(degrees) (degrees * PI / 180.0)
#define ToDegrees(radians) (radians * 180 / PI)
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a > b ? a : b)
#define Clamp(val, min, max) (val < min ? min : val > max ? max : val)

	inline float Lerp(float val, float a, float b)
	{
		return a * (1.0f - val) + b * val;
	}
	inline Vector2 Lerp(float val, const Vector2& a, const Vector2& b)
	{
		return a * (1.0f - val) + b * val;
	}
	inline Vector3 Lerp(float val, const Vector3& a, const Vector3& b)
	{
		return a * (1.0f - val) + b * val;
	}
	inline Vector4 Lerp(float val, const Vector4& a, const Vector4& b)
	{
		return a * (1.0f - val) + b * val;
	}
}}

#endif