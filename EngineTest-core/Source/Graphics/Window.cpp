#include "Window.h"

namespace EngineTest
{
	namespace Graphics
	{
		void windowResized(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
				LOG("Failed to init window!");
			}
			mainWindow = this;
		}
		Window::~Window()
		{
			glfwTerminate();
			mainWindow = NULL;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				LOG("Failed to initialize GLFW!");
				return false;
			}
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				LOG("Failed to create GLFW window!");
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResized);

			if (glewInit() != GLEW_OK)
			{
				LOG("Could not initialize GLEW!");
				return false;
			}
			LOG((const char *)glGetString(GL_VERSION));

			return true;
		}

		void Window::setWidth(int width)
		{
			m_Width = width;
		}
		void Window::setHeight(int height)
		{
			m_Height = height;
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}
		void windowResized(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
			mainWindow->setWidth(width);
			mainWindow->setHeight(height);
		}
	}
}