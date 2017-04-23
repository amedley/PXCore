#include "Renderer2D.h"
#include "../../Entities/Common2DIncludes.h"
#include "../../Singletons.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	Renderer2D::Renderer2D() : Renderer()
	{
		m_TransformStackSize = 0;
		m_TransformStackResult = m_TransformStack - 1;
		m_Vertices = malloc(sizeof(Vertex2D) * MAX_RECTANGLES_PER_DRAW * 4);
		m_Indices = malloc(sizeof(uint16) * MAX_RECTANGLES_PER_DRAW * 6);

		uint16* indices = (uint16*) m_Indices;
		for (int i = 0; i < MAX_RECTANGLES_PER_DRAW; i++)
		{
			int rectVert =	i * 4;
			int rectIndex = i * 6;
			indices[rectIndex + 0] = rectVert + 0;
			indices[rectIndex + 1] = rectVert + 1;
			indices[rectIndex + 2] = rectVert + 3;
			indices[rectIndex + 3] = rectVert + 3;
			indices[rectIndex + 4] = rectVert + 1;
			indices[rectIndex + 5] = rectVert + 2;
		}
		m_IndexBuffer->Bind();
		m_IndexBuffer->BufferData(m_Indices, sizeof(uint16) * MAX_RECTANGLES_PER_DRAW * 6);
		m_IndexBuffer->Unbind();

		SetShader(Singletons::GetShaderFactory()->GetBasic2D());
	}
	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::PushMatrix(const Matrix4& transform, bool multiply)
	{
		if (multiply)
		{
			m_TransformStack[m_TransformStackSize] = m_TransformStack[m_TransformStackSize - 1] * transform;
		}
		else
		{
			m_TransformStack[m_TransformStackSize] = transform;
		}
		m_TransformStackSize++;
		m_TransformStackResult++;
	}
	void Renderer2D::PushMatrix(const Matrix4& transform)
	{
		PushMatrix(transform, true);
	}
	void Renderer2D::PopMatrix()
	{
		m_TransformStackSize--;
		m_TransformStackResult--;
	}
	Matrix4& Renderer2D::GetTransformMatrix()
	{
		return *m_TransformStackResult;
	}

	void Renderer2D::Begin()
	{
		m_VertexBuffer->Bind();
		GetShader()->EnableVertexAttribs();
	}
	void Renderer2D::Submit(Entity2D* sender, Rect2D* rect, ColorRGBA* colorRGBA)
	{
		Vector4& finalRGBA = colorRGBA->GetRGBAMultiplied();

		Vertex2D* vertexPointer = (Vertex2D*) m_Vertices;
		vertexPointer += m_SubmissionCount * 4;

		vertexPointer[0] = { rect->m_V0, finalRGBA };
		vertexPointer[1] = { rect->m_V1, finalRGBA };
		vertexPointer[2] = { rect->m_V2, finalRGBA };
		vertexPointer[3] = { rect->m_V3, finalRGBA };

		m_SubmissionCount++;
	}
	void Renderer2D::End()
	{
		m_VertexBuffer->BufferData(m_Vertices, sizeof(Vertex2D) * m_SubmissionCount * 4);
	}
	void Renderer2D::Draw()
	{
		m_IndexBuffer->Bind();
		glDrawElements(GL_TRIANGLES, m_SubmissionCount * 6, GL_UNSIGNED_SHORT, NULL);
		m_SubmissionCount = 0;
	}
}}}
