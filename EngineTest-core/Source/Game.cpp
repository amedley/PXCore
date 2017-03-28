#include "Game.h"

namespace EngineTest
{
	using namespace Graphics;
	using namespace Math;
	using namespace Utils;

	Game* Game::s_Instance = nullptr;
	void Game::Construct()
	{
		if (s_Instance)
			Assert(false, "s_Instance of Game already exists!");
		s_Instance = new Game();
	}
	void Game::Shutdown()
	{
		if (!s_Instance)
			Assert(false, "s_Instance of Game does not exist!");

		FileUtils::Get()->Shutdown();
		Window::Get()->Shutdown();
		delete s_Instance;
		exit(0);
	}
	Game* Game::Get()
	{
		if (!s_Instance)
			Assert(false, "s_Instance of Game does not exist!");
		return s_Instance;
	}

	Game::Game()
	{
		m_Initialized = false;
	}
	Game::~Game()
	{
		LOG("Game deallocated");
	}

	bool Game::Init()
	{
		if (m_Initialized)
		{
			Assert(false, "Game already initialized!");
			return false;
		}
		m_Initialized = true;
		
		FileUtils::Construct();
		Window::Construct();

		FileUtils::Get()->Init();
		Window::Get()->Init("EngineTest!", 800, 600);
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


		GLfloat vertices[] =
		{
			-1.0f,	-1.0f,	-0.0f,
			-1.0f,	+1.0f,	-0.0f,
			+1.0f,	+1.0f,	-0.0f,
			+1.0f,	+1.0f,	-0.0f,
			+1.0f,	-1.0f,	-0.0f,
			-1.0f,	-1.0f,	-0.0f
		};
		GLuint vbo;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		glEnableVertexAttribArray(0);

		
		Shader shader("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
		shader.Enable();

		//Matrix4 proj = Matrix4::Orthographic(-160.0f, 160.0f, -284.0f, 248.0f, -1.0f, 1.0f);
		Matrix4 proj = Matrix4::Perspective(75.0, 4.0 / 3.0, -0.1, -100.0);

		Matrix4 view = Matrix4::Identitiy();
		view *= Matrix4::Translation(Vector3(0.0f, 0.0f, 0.0f));
		
		shader.SetUniformMatrix4("pr_matrix", proj);
		shader.SetUniformMatrix4("vw_matrix", view);

		shader.SetUniform3f("light_pos", Vector3(1.0f, 0.0f, -0.2f));

		float rot = 0.0f;
		int ticks = 0;
		float offs = 0.0f;

		while (!Window::Get()->IsClosed())
		{
			Window::Get()->Clear();
			ticks++;
			offs = sinf((float)ticks / 20.0f * (double)M_PI / 180.0f);
			shader.SetUniform3f("light_pos", Vector3(1.0f, 0.0f, -offs));

			Matrix4 model = Matrix4::Identitiy();
			model *= Matrix4::Translation(Vector3(0.0f, 0.0f, -5.0f));
			model *= Matrix4::Rotation(rot, Vector3(1.0f, 0.0f, 0.0f));
			shader.SetUniformMatrix4("ml_matrix", model);

			rot += 0.01f;

			glDrawArrays(GL_TRIANGLES, 0, 6);

			Window::Get()->OnUpdate();
		}
		return true;
	}
}