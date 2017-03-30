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

		
		GLuint vbo;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, 0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		float vertices[]
		{
			-0.5f, -0.5f, +0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, +0.5f, +0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			+0.5f, +0.5f, +0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			+0.5f, +0.5f, +0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			+0.5f, -0.5f, +0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			-0.5f, -0.5f, +0.0f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		
		Shader shader("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
		shader.Enable();

		float rot = 0.0f;

		float eyeX = 0.0f;
		float eyeY = 0.0f;
		float eyeZ = -0.1f;
		float atX = eyeX;
		float atY = eyeY;
		float atZ = eyeZ - 1.0f;

		while (!Window::Get()->IsClosed())
		{
			if (Window::Get()->IsKeyDown(GLFW_KEY_W))
			{
				eyeZ -= 0.01f;
				atZ -= 0.01f;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_A))
			{
				eyeX -= 0.01f;
				atX -= 0.01f;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_S))
			{
				eyeZ += 0.01f;
				atZ += 0.01f;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_D))
			{
				eyeX += 0.01f;
				atX += 0.01f;
			}

			Window::Get()->Clear();

			//Matrix4 proj = Matrix4::Orthographic(-8.0, 8.0, -6.0, 6.0, -0.1, -100.0);
			Matrix4 proj = Matrix4::Perspective(75.0f, 4.0 / 3.0, -0.1, -100.0);
			Matrix4 transform = Matrix4::Identitiy();
			transform *= Matrix4::LookAt(Vector3(eyeX, eyeY, eyeZ), Vector3(atX, atY, atZ), Vector3(0.0f, 1.0f, 0.0f));
			transform *= Matrix4::Translate(Vector3(3.0f, 1.0f, -5.0f));
			transform *= Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));
			transform *= Matrix4::Rotate(rot, Vector3(1.0f, 1.0f, 1.0f).NormalizeEquals());

			shader.SetUniformMatrix4("pr_matrix", proj);
			shader.SetUniformMatrix4("ml_matrix", transform);

			
			rot += 0.03f;

			
			glDrawArrays(GL_TRIANGLES, 0, 6);

			Window::Get()->OnUpdate();
		}
		return true;
	}
}