#ifndef RENDERER
#define RENDERER

#include "../../Common.h"
#include "../Shaders/Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	using namespace Shaders;

	class Renderer
	{
	private:
		Shader* m_Shader;
	protected:
		VertexBuffer* m_VertexBuffer;
		IndexBuffer* m_IndexBuffer;
		void* m_Vertices;
		void* m_Indices;
	public:
		Renderer();
		virtual ~Renderer();

		void SetShader(Shader* shader);
		Shader* GetShader();
	};

}}}

#endif