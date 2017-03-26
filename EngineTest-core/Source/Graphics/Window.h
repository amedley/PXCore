#ifndef WINDOW_H
#define WINDOW_H

#include "../Debug.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace EngineTest
{
	namespace Graphics
	{

#define MAX_KEYS				1024
#define MAX_MOUSE_BUTTONS		32

		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;

			bool m_KeysDown[MAX_KEYS];
			bool m_KeysPressed[MAX_KEYS];
			bool m_KeysReleased[MAX_KEYS];
			bool m_MouseButtonsDown[MAX_MOUSE_BUTTONS];
			bool m_MouseButtonsPressed[MAX_MOUSE_BUTTONS];
			bool m_MouseButtonsReleased[MAX_MOUSE_BUTTONS];
			double m_MouseX, m_MouseY;
		public:
			Window(const char* title, int width, int height);
			~Window();
			void Clear() const;
			void OnUpdate();
			bool IsClosed() const;
			bool IsKeyDown(unsigned int key) const;
			bool IsKeyPressed(unsigned int key) const;
			bool IsKeyReleased(unsigned int key) const;
			bool IsMouseButtonDown(unsigned int button) const;
			bool IsMouseButtonPressed(unsigned int button) const;
			bool IsMouseButtonReleased(unsigned int button) const;

			void SetWidth(int width);
			void SetHeight(int height);

			inline int GetWidth() const { return m_Width; }
			inline int GetHeight() const { return m_Height; }
			inline double GetMouseX() const { return m_MouseX; }
			inline double GetMouseY() const { return m_MouseY; }
		private:
			bool Init();

			static void resize_callback(GLFWwindow* window, int width, int height);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}

#endif