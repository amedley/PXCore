#ifndef MACHINE_H
#define MACHINE_H

#include "../Debug.h"

namespace EngineTest { namespace System {
	enum OS
	{
		kWindows				= 0,
		kMacOS,
		kLinux,
		kIOS,
		kAndroid,
	};

	enum GFXAPI
	{
		kOpenGL					= 0,
		kOpenGLES
	};

	class Machine
	{
	private:
		OS m_OS;
		GFXAPI m_GFXAPI;
	public:
		Machine();
		~Machine();

		OS GetOS();
		GFXAPI GetGFXAPI();
	private:
		void SetUpMachine();
	};
}}



#endif