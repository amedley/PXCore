#include "VertexBuffer.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	VertexBuffer* VertexBuffer::s_BoundVertexBuffer = NULL;

	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &m_ID);
	}
	VertexBuffer::~VertexBuffer()
	{
		Unbind();
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBuffer::Bind()
	{
		Bind(NULL);
	}
	void VertexBuffer::Bind(Shader* shader)
	{
		if (GetBound())
			return;
		if (s_BoundVertexBuffer)
			s_BoundVertexBuffer->Unbind();
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		s_BoundVertexBuffer = this;
		if (shader)
		{
			shader->EnableVertexAttribs();
		}
	}
	void VertexBuffer::BufferData(void* data, uint32 size)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	}
	void VertexBuffer::Unbind()
	{
		if (!GetBound())
			return;
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		s_BoundVertexBuffer = NULL;
	}

	GLuint VertexBuffer::GetID()
	{
		return m_ID;
	}
	bool VertexBuffer::GetBound()
	{
		return this == s_BoundVertexBuffer;
	}
}}}