#include "Machine.h"

namespace EngineTest { namespace System {
	Machine::Machine()
	{
		SetUpMachine();
	}
	Machine::~Machine()
	{
		
	}

	void Machine::SetUpMachine()
	{
		#if defined(_WIN32)
			m_OS = kWindows;
			m_GFXAPI = kOpenGL;
		#elif defined(__APPLE__)
			#if TARGET_OS_PHONE
				m_OS = kIOS;
				m_GFXAPI = kOpenGLES;
			#elif TARGET_OS_MAC
				m_OS = kMacOS;
				m_GFXAPI = kOpenGL;
			#endif
		#elif defined(__ANDROID__)
			m_OS = kAndroid;
			m_GFXAPI = kOpenGLES;
		#elif defined(__linux__)
			m_OS = kLinux;
			m_GFXAPI = kOpenGL;
		#endif
		LOG("Machine finished setting up! OS: %i, OGL: %i", m_OS, m_GFXAPI);
	}

	OS Machine::GetOS()
	{
		return m_OS;
	}
	GFXAPI Machine::GetGFXAPI()
	{
		return m_GFXAPI;
	}
}}