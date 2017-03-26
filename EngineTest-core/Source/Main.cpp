#include "Debug.h"
#include "Graphics/Window.h"
#include "Math/Math.h"

int main()
{
	using namespace EngineTest;
	using namespace Graphics;
	using namespace Math;
	Window window("EngineTest!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	Vector4 a(3, 4, 5, 6);
	Vector4 b(3.0f, 4.0f, 5.0f, 6.0f);

	Matrix4 identity = Matrix4::Identitiy();
	Matrix4 position = Matrix4::Translation(Vector3(1.0f, 2.0f, 3.0f));
	Matrix4 rotation = Matrix4::Rotation(80.0f, Vector3(0.0f, 0.0f, 1.0f));
	Matrix4 scale = Matrix4::Scale(Vector3(2.0f, 2.0f, 2.0f));
	Matrix4 move = Matrix4::Translation(Vector3(10.0f, 5.0f, 2.0f));

	Matrix4 result = identity * position * rotation * scale * move;

	result.Log();

	while (!window.IsClosed())
	{
		window.Clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.OnUpdate();
	}

	return 0;
}