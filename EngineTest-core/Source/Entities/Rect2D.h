#ifndef RECT_2D_H
#define RECT_2D_H

#include "../Math/Math.h"

namespace EngineTest { namespace Entities {

	using namespace Math;

	class Rect2D
	{
	public:
		Rect2D();
		~Rect2D();

		float GetScale();
		void SetScale(float scale);
		void CalculateVertices(const Matrix4& matrix);

		Vector3 m_V0;		// Calculated top left
		Vector3 m_V1;		// Calculated bottom left
		Vector3 m_V2;		// Calculated bottom right
		Vector3 m_V3;		// Calculated top right
	private:
		Vector3 m_TL;		// Top left
		Vector3 m_BL;		// Bottom left
		Vector3 m_BR;		// Bottom right
		Vector3 m_TR;		// Top right
		float m_Scale;
	};

}}

#endif