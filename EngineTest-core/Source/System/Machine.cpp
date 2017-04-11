#include "Machine.h"

namespace EngineTest
{
	namespace System
	{
		Machine::Machine()
		{
			#if defined(_WIN32)
				m_OS = Windows;
				m_GFXAPI = OpenGL;
			#elif defined(__APPLE__)
				#if TARGET_OS_PHONE
					m_OS = iOS;
					m_GFXAPI = OpenGLES;
				#elif TARGET_OS_MAC
					m_OS = MacOS;
					m_GFXAPI = OpenGL;
				#endif
			#elif defined(__ANDROID__)
				m_OS = Android;
				m_GFXAPI = OpenGLES;
			#elif defined(__linux__)
				m_OS = Linux;
				m_GFXAPI = OpenGL;
			#endif
		}
		Machine::~Machine()
		{
		
		}


		OS Machine::GetOS()
		{
			return m_OS;
		}
		GFXAPI Machine::GetGFXAPI()
		{
			return m_GFXAPI;
		}
	}
}