#include "IndexBuffer.h"

namespace EngineTest { namespace Graphics { namespace Rendering {
	
	IndexBuffer* IndexBuffer::s_BoundIndexBuffer = NULL;

	IndexBuffer::IndexBuffer()
	{
		glGenBuffers(1, &m_ID);
	}
	IndexBuffer::~IndexBuffer()
	{
		Unbind();
		glDeleteBuffers(1, &m_ID);
	}

	void IndexBuffer::Bind()
	{
		if (GetBound())
			return;
		if (s_BoundIndexBuffer)
			s_BoundIndexBuffer->Unbind();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		s_BoundIndexBuffer = this;
	}
	void IndexBuffer::BufferData(void* data, uint32 size)
	{
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	void IndexBuffer::Unbind()
	{
		if (!GetBound())
			return;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		s_BoundIndexBuffer = NULL;
	}

	GLuint IndexBuffer::GetID()
	{
		return m_ID;
	}
	bool IndexBuffer::GetBound()
	{
		return this == s_BoundIndexBuffer;
	}
}}}