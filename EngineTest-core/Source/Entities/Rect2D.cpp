#include "Rect2D.h"

namespace EngineTest { namespace Entities {

	Rect2D::Rect2D()
	{
		SetScale(1.0f);
	}
	Rect2D::~Rect2D()
	{
	}

	float Rect2D::GetScale()
	{
		return m_Scale;
	}
	void Rect2D::SetScale(float scale)
	{
		m_TL = Vector3(-0.5f, -0.5f, 0.0f) * scale;
		m_BL = Vector3(-0.5f, +0.5f, 0.0f) * scale;
		m_BR = Vector3(+0.5f, +0.5f, 0.0f) * scale;
		m_TR = Vector3(+0.5f, -0.5f, 0.0f) * scale;
		m_Scale = scale;
	}
	void Rect2D::CalculateVertices(const Matrix4& matrix)
	{
		m_V0 = m_TL.Multiply(matrix);
		m_V1 = m_BL.Multiply(matrix);
		m_V2 = m_BR.Multiply(matrix);
		m_V3 = m_TR.Multiply(matrix);
	}
}}