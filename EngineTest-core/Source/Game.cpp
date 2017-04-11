#include "Game.h"
#include "Singletons.h"

namespace EngineTest
{
	using namespace Graphics;
	using namespace Math;
	using namespace Utils;

	Game::Game()
	{
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

		while (!Singletons::GetWindow()->IsClosed())
		{
			yaw -= (float)Singletons::GetWindow()->GetMouseDX() * 0.0025f;
			pitch -= (float)Singletons::GetWindow()->GetMouseDY() * 0.0025f;
			pitch = Clamp(pitch, -PI / 2.1f, PI / 2.1f);

			Quaternion orientation = Quaternion::RotationY(yaw) * Quaternion::RotationX(pitch);

			Vector3 cameraForward = Quaternion::Rotate(orientation, -Vector3::ZAxis()).Normalize();
			Vector3 cameraUp = Quaternion::Rotate(orientation, Vector3::YAxis()).Normalize();
			Vector3 cameraRight = Quaternion::Rotate(orientation, Vector3::XAxis()).Normalize();

			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_W))
			{
				position += cameraForward * speed;
			}
			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_S))
			{
				position -= cameraForward * speed;
			}
			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_D))
			{
				position += cameraRight * speed;
			}
			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_A))
			{
				position -= cameraRight * speed;
			}
			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_SPACE))
			{
				position += Vector3(0.0f, 1.0f, 0.0f) * speed;
			}
			if (Singletons::GetWindow()->IsKeyDown(GLFW_KEY_LEFT_CONTROL))
			{
				position -= Vector3(0.0f, 1.0f, 0.0f) * speed;
			}

			Singletons::GetWindow()->Clear();


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

			Singletons::GetWindow()->OnUpdate();
		}

	}
	Game::~Game()
	{
	}
}