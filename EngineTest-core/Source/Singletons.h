#ifndef SINGLETON_H
#define SINGLETON_H

#include "Game.h"
#include "System/Machine.h"
#include "Utils/FileUtils.h"
#include "Graphics/Window.h"
#include "Graphics/Shaders/ShaderFactory.h"

namespace EngineTest
{
	using namespace System;
	using namespace Utils;
	using namespace Graphics;
	using namespace Shaders;

	class Singletons
	{

		static Singletons* s_Singletons;
	private:
		void EstablishSingletons();
	public:
		Singletons();
		~Singletons();

		static void Construct();
		static void Shutdown();
		static inline Singletons* Get() { return s_Singletons; };

	private:
		Machine*						m_Machine;
		FileUtils*						m_FileUtils;
		Window*							m_Window;
		Game*							m_Game;
		ShaderFactory*					m_ShaderFactory;
	public:
		static Machine*					GetMachine();
		static FileUtils*				GetFileUtils();
		static Window*					GetWindow();
		static Game*					GetGame();
		static ShaderFactory*			GetShaderFactory();
	};
}

#endif