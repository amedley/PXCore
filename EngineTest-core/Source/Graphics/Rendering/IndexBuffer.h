#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include "GL/glew.h"
#include "../../Common.h"

namespace EngineTest { namespace Graphics { namespace Rendering {
	
	class IndexBuffer
	{
		static IndexBuffer* s_BoundIndexBuffer;
	public:
		IndexBuffer();
		~IndexBuffer();

		void Bind();
		void BufferData(void* data, uint32 size);
		void Unbind();

		GLuint GetID();
		bool GetBound();

	private:
		GLuint m_ID;
	};

}}}

#endif