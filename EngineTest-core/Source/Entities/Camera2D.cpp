#include "Camera2D.h"
#include "../Math/Math.h"
#include "Transform2D.h"

namespace EngineTest { namespace Entities {

	Camera2D::Camera2D() : Camera::Camera()
	{
		m_Transform = new Transform2D(Vector3(0.0f), Vector2(1.0f), Vector2(1.0f), 0.0f);
	}
	Camera2D::~Camera2D()
	{
		DELETE(m_Transform);
	}

	void Camera2D::OnUpdate()
	{
		Camera::OnUpdate();
	}
	Transform2D& Camera2D::GetTransform()
	{
		return *m_Transform;
	}
}}