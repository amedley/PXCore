#ifndef SHADER_BASIC_2D_H
#define SHADER_BASIC_2D_H

#include "Shader.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	class ShaderBasic2D : public Shader
	{
	public:
		ShaderBasic2D();
		~ShaderBasic2D();

		bool Enable();
		bool Disable();
		void EnableVertexAttribs();
	};

}}}

#endif