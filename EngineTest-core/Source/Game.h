#ifndef GAME_H
#define GAME_H

#include "Debug.h"
#include "Graphics/Window.h"
#include "Math/Math.h"
#include "Utils/FileUtils.h"
#include "Graphics/Shader.h"
#include "Utils/Time.h"
#include "Common.h"

namespace EngineTest
{
	class Game
	{
		static Game* s_Instance;
	public:
		static void Construct();
		static void Shutdown();
		static Game* Get();
		bool Init();
	private:
		bool m_Initialized;
	private:
		Game();
		~Game();
	};
}

#endif