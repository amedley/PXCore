#ifndef SHADER_BASIC_3D_H
#define SHADER_BASIC_3D_H

#include "Shader.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	class ShaderBasic3D : public Shader
	{
	public:
		ShaderBasic3D();
		~ShaderBasic3D();

		bool Enable();
		bool Disable();
		void EnableVertexAttribs();
	};

}}}

#endif