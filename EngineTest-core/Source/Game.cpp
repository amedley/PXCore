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
		Window::Get()->Init("EngineTest!", 1280, 720);
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

		
		GLuint vbo;

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, _color)));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(offsetof(Vertex, _position)));
		glEnableVertexAttribArray(1);

		
		Shader shader("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
		shader.Enable();

		float speed = 0.01f;
		Vector3 position(0.0f, 0.0f, 0.0f);

		float pitch = 0.0f;
		float yaw = 0.0f;

		shader.SetUniformMatrix4("pr_matrix", Matrix4::Perspective(65.0f, 16.0 / 9.0, 0.001, 1000.0));

		while (!Window::Get()->IsClosed())
		{
			yaw -= (float)Window::Get()->GetMouseDX() * 0.0025f;
			pitch -= (float)Window::Get()->GetMouseDY() * 0.0025f;
			pitch = Clamp(pitch, -PI / 2.1f, PI / 2.1f);

			Quaternion orientation = Quaternion::RotationY(yaw) * Quaternion::RotationX(pitch);

			Vector3 cameraForward = Quaternion::Rotate(orientation, -Vector3::ZAxis()).Normalize();
			Vector3 cameraUp = Quaternion::Rotate(orientation, Vector3::YAxis()).Normalize();
			Vector3 cameraRight = Quaternion::Rotate(orientation, Vector3::XAxis()).Normalize();

			if (Window::Get()->IsKeyDown(GLFW_KEY_W))
			{
				position += cameraForward * speed;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_S))
			{
				position -= cameraForward * speed;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_D))
			{
				position += cameraRight * speed;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_A))
			{
				position -= cameraRight * speed;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_SPACE))
			{
				position += Vector3(0.0f, 1.0f, 0.0f) * speed;
			}
			if (Window::Get()->IsKeyDown(GLFW_KEY_LEFT_CONTROL))
			{
				position -= Vector3(0.0f, 1.0f, 0.0f) * speed;
			}

			Window::Get()->Clear();


			//Matrix4 view = Matrix4::LookAt(position, position + cameraForward, cameraUp);
			Matrix4 view = Matrix4::Rotate(orientation.Conjugate()) * Matrix4::Translate(-position);
			Matrix4 model = Matrix4::Translate(Vector3(0.0f, 0.0f, -10.0f));
			model = model * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));

			Matrix4 transform = view * model;
			Vertex vertices[]
			{
				Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f),
				Vector3(-1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 0.0f, 0.0f, 1.0f),
				Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 1.0f, 0.0f, 1.0f),
				Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 1.0f, 0.0f, 1.0f),
				Vector3(+1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 1.0f, 1.0f, 1.0f),
				Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f)
			};
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			
			glDrawArrays(GL_TRIANGLES, 0, 6);

			Window::Get()->OnUpdate();
		}
		return true;
	}
}