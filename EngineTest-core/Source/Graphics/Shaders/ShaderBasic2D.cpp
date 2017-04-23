#include "ShaderBasic2D.h"
#include "../Rendering/Vertex2DTypes.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	using namespace Rendering;

	ShaderBasic2D::ShaderBasic2D() : Shader(kBasic2D, "Resources/Shaders/basic2D.vert", "Resources/Shaders/basic2D.frag")
	{
		
	}
	ShaderBasic2D::~ShaderBasic2D()
	{
	
	}


	bool ShaderBasic2D::Enable()
	{
		if (!Shader::Enable())
			return false;

		return true;
	}
	bool ShaderBasic2D::Disable()
	{
		if (!Shader::Disable())
			return false;
		return true;
	}
	void ShaderBasic2D::EnableVertexAttribs()
	{
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)(offsetof(Vertex2D, _position)));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)(offsetof(Vertex2D, _color)));
		glEnableVertexAttribArray(1);
	}
}}}