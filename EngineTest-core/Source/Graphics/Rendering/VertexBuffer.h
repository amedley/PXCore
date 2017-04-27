#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "GL/glew.h"
#include "../../Common.h"
#include "../Shaders/Shader.h"

namespace EngineTest { namespace Graphics { namespace Rendering {
	
	using namespace Shaders;

	class VertexBuffer
	{
		static VertexBuffer* s_BoundVertexBuffer;
	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void Bind(Shader* shader);
		void BufferData(void* data, uint32 size);
		void Unbind();

		GLuint GetID();
		bool GetBound();

	private:
		GLuint m_ID;
	};

}}}

#endif