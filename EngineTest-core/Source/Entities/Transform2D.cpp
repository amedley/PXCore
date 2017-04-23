#include "Transform2D.h"

#include "../Singletons.h"

namespace EngineTest { namespace Entities {

	Transform2D::Transform2D(const Vector3& position, const Vector2& size, const Vector2& scale, float rotation)
	{
		m_Position = position;
		m_Size = size;
		m_Scale = scale;
		m_Rotation = rotation;
		m_Matrix = Matrix4(1.0f);
		CalculateModel();
	}
	Transform2D::Transform2D() : Transform2D(Vector3(0.0f), Vector2(1.0f), Vector2(1.0f), 0.0f)
	{
	}
	Transform2D::~Transform2D()
	{

	}

	void Transform2D::SetPosition(const Vector3& position)
	{
		m_Position = position;
		m_MatrixSynced = false;
	}
	void Transform2D::SetSize(const Vector2& size)
	{
		m_Size = size;
		m_MatrixSynced = false;
	}
	void Transform2D::SetScale(const Vector2& scale)
	{
		m_Scale = scale;
		m_MatrixSynced = false;
	}
	void Transform2D::SetRotation(float rotation)
	{
		m_Rotation = rotation;
		m_MatrixSynced = false;
	}

	void Transform2D::ChangePosition(const Vector3& dPosition)
	{
		m_Position += dPosition;
		m_MatrixSynced = false;
	}
	void Transform2D::ChangeSize(const Vector2& dSize)
	{
		m_Size += dSize;
		m_MatrixSynced = false;
	}
	void Transform2D::ChangeScale(const Vector2& dScale)
	{
		m_Scale += dScale;
		m_MatrixSynced = false;
	}
	void Transform2D::ChangeRotation(float dRotation)
	{
		m_Rotation += dRotation;
		m_MatrixSynced = false;
	}

	const Vector3& Transform2D::GetPosition()
	{
		return m_Position;
	}
	const Vector2& Transform2D::GetSize()
	{
		return m_Size;
	}
	const Vector2& Transform2D::GetScale()
	{
		return m_Scale;
	}
	float Transform2D::GetRotation()
	{
		return m_Rotation;
	}

	void Transform2D::CalculateModel()
	{
		Matrix4::Simple2DTransform(m_Matrix, m_Position, m_Size * m_Scale, (float)ToRadians(m_Rotation));
		m_MatrixSynced = true;
	}
	void Transform2D::CalculateView()
	{
		Matrix4::Simple2DTransform(m_Matrix, -m_Position, m_Size * m_Scale, -(float)ToRadians(m_Rotation));
		m_MatrixSynced = true;
	}
	Matrix4& Transform2D::GetMatrix()
	{
		return m_Matrix;
	}

	bool Transform2D::GetMatrixSynced()
	{
		return m_MatrixSynced;	
	}
}}