#include "ShaderFactory.h"

namespace EngineTest { namespace Graphics { namespace Shaders {

	ShaderFactory::ShaderFactory()
	{
		m_Shaders[kBasic2D] = new ShaderBasic2D();
		m_Shaders[kBasic3D] = new ShaderBasic3D();
	}
	ShaderFactory::~ShaderFactory()
	{
		for (int i = 0; i < kSHADER_TYPE_COUNT; i++)
		{
			DELETE(m_Shaders[i]);
		}
	}

	ShaderBasic2D*			ShaderFactory::GetBasic2D()				{ return (ShaderBasic2D*) m_Shaders[kBasic2D]; }
	ShaderBasic3D*			ShaderFactory::GetBasic3D()				{ return (ShaderBasic3D*) m_Shaders[kBasic3D]; }
}}}