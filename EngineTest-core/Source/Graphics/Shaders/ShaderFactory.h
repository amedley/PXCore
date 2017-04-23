#ifndef SHADER_FACTORY_H
#define SHADER_FACTORY_H

#include "ShaderBasic2D.h"
#include "ShaderBasic3D.h"


namespace EngineTest { namespace Graphics { namespace Shaders {

	class ShaderFactory
	{
	private:
		Shader* m_Shaders[kSHADER_TYPE_COUNT];

	public:
		ShaderFactory();
		~ShaderFactory();

		ShaderBasic2D* GetBasic2D();
		ShaderBasic3D* GetBasic3D();
	};

}}}

#endif