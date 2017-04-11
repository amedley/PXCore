#ifndef SINGLETON_H
#define SINGLETON_H

#include "Game.h"
#include "System/Machine.h"
#include "Utils/FileUtils.h"
#include "Graphics/Window.h"

namespace EngineTest
{
	using namespace System;
	using namespace Utils;
	using namespace Graphics;

	class Singletons
	{

		static Singletons* s_Singletons;
	private:
		Singletons();
		~Singletons();
		void EstablishSingletons();
	public:
		static void Construct();
		static void Shutdown();
		static inline Singletons* Get() { return s_Singletons; };

	private:
		Machine*						m_Machine;
		FileUtils*						m_FileUtils;
		Window*							m_Window;
		Game*							m_Game;
	public:
		static Machine*					GetMachine();
		static FileUtils*				GetFileUtils();
		static Window*					GetWindow();
		static Game*					GetGame();
	};
}

#endif