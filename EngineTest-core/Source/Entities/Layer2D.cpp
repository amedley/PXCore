#include "Common2DIncludes.h"

namespace EngineTest { namespace Entities {

	Layer2D::Layer2D(const Matrix4& proj) : Entity2D(Vector3(0.0f), Vector2(1.0f), Vector4(1.0f))
	{
		m_Proj = proj;
		m_Renderer = new Renderer2D();
		m_Camera = new Camera2D();
		
		SetRenderingGuide(kRenderIfEnabled);
		SetRenderingEnabled(true);
	}
	Layer2D::~Layer2D()
	{
		DELETE(m_Renderer);
		DELETE(m_Camera);
	}

	bool Layer2D::OnUpdate(uint64 gameTick)
	{
		if (!Entity2D::OnUpdate(gameTick))
			return false;

		m_Camera->OnUpdate();

		return true;
	}
	void Layer2D::OnRender()
	{
		m_Renderer->Begin();
		m_Renderer->PushMatrix(m_Proj, false);

		if (!m_Camera->GetTransform().GetMatrixSynced())
			m_Camera->GetTransform().CalculateView();
		m_Renderer->PushMatrix(m_Camera->GetTransform().GetMatrix());

		Entity2D::OnRenderChildEntities(m_Renderer);

		m_Renderer->PopMatrix();

		m_Renderer->PopMatrix();
		m_Renderer->End();
		m_Renderer->Draw();
	}

	Matrix4& Layer2D::GetProj()
	{
		return m_Proj;
	}
	Renderer2D& Layer2D::GetRenderer()
	{
		return *m_Renderer;
	}
	Camera2D& Layer2D::GetCamera()
	{
		return *m_Camera;
	}
}}