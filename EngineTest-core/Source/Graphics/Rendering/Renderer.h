#ifndef RENDERER
#define RENDERER

#include "../../Common.h"
#include "../Shaders/Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "../../Math/Math.h"

namespace EngineTest { namespace Graphics { namespace Rendering {

	using namespace Shaders;
	using namespace Math;

	class Renderer
	{
	private:
		Shader* m_Shader;
	protected:
		VertexBuffer* m_VertexBuffer;
		IndexBuffer* m_IndexBuffer;
	public:
		Renderer();
		virtual ~Renderer();

		void SetShader(Shader* shader);
		Shader* GetShader();
	};

}}}

#endif