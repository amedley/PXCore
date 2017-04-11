#ifndef MACHINE_H
#define MACHINE_H

#include "../Debug.h"

namespace EngineTest
{
	namespace System
	{
		enum OS
		{
			Windows				= 0,
			MacOS				= 1,
			Linux				= 2,
			iOS					= 3,
			Android				= 4,
		};

		enum GFXAPI
		{
			OpenGL				= 0,
			OpenGLES			= 1
		};

		class Machine
		{
		public:
			Machine();
			~Machine();

			OS GetOS();
			GFXAPI GetGFXAPI();
		private:
			OS m_OS;
			GFXAPI m_GFXAPI;
		};

	}
}



#endif