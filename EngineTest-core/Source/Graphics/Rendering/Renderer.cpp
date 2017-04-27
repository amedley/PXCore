#include "Renderer.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	Renderer::Renderer()
	{
		m_Shader = NULL;
		m_VertexBuffer = new VertexBuffer();
		m_IndexBuffer = new IndexBuffer();
	}
	Renderer::~Renderer()
	{
		DELETE(m_VertexBuffer);
		DELETE(m_IndexBuffer);
	}

	void Renderer::SetShader(Shader* shader)
	{
		if (m_Shader)
		{
			if (m_Shader->GetType() == shader->GetType())
				return;
			m_Shader->Disable();
		}
		m_Shader = shader;
		if (m_Shader)
		{
			m_Shader->Enable();
		}
	}
	Shader* Renderer::GetShader()
	{
		return m_Shader;
	}
}}}
