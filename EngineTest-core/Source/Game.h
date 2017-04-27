#ifndef GAME_H
#define GAME_H

#include "Debug.h"
#include "Graphics/Window.h"
#include "Math/Math.h"
#include "Utils/FileUtils.h"
#include "Utils/Time.h"
#include "Common.h"
#include "Entities/Common2DIncludes.h"
#include "Graphics/Shaders/ShaderFactory.h"
#include "Graphics/Rendering/Renderer2D.h"
#include "Graphics/Rendering/Vertex2DTypes.h"
#include "Utils/Random.h"
#include "Utils/Time.h"
#include "Utils/ThreadUtils.h"

namespace EngineTest
{
	using namespace Math;
	using namespace Graphics;
	using namespace Rendering;
	using namespace Entities;
	using namespace Utils;

	class Game
	{
	private:
		uint64 m_Ticks;
		double m_TimeSpent;

		Random* m_Random;
		Layer2D* m_Layer2D;
		Group2D* m_Group2D;
		float m_Width;
		float m_Height;
	public:
		Game();
		~Game();

		void Init();

		uint64 GetTicks();
	private:
		void OnUpdate();
		void OnRender();
	};
}

#endif