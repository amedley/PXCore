#include "ShaderBasic3D.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	ShaderBasic3D::ShaderBasic3D() : Shader(kBasic3D, "Resources/Shaders/basic3D.vert", "Resources/Shaders/basic3D.frag")
	{
		
	}
	ShaderBasic3D::~ShaderBasic3D()
	{
	
	}

	bool ShaderBasic3D::Enable()
	{
		if (!Shader::Enable())
			return false;
		return true;
	}
	bool ShaderBasic3D::Disable()
	{
		if (!Shader::Disable())
			return false;
		return true;
	}
	void ShaderBasic3D::EnableVertexAttribs()
	{
	}
}}}