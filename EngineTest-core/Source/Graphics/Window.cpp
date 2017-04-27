#include "Window.h"

namespace EngineTest { namespace Graphics {
	Window::Window(const char* title, int width, int height)
	{

		m_Title = title;
		m_Width = width;
		m_Height = height;

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_KeysDown[i] = false;
			m_KeysPressed[i] = false;
			m_KeysReleased[i] = false;
		}
		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			m_MouseButtonsDown[i] = false;
			m_MouseButtonsPressed[i] = false;
			m_MouseButtonsReleased[i] = false;
		}
		m_MouseX = m_MouseY = 0.0f;

		if (!glfwInit())
		{
			ASSERT(false, "Failed to initialize GLFEW!");
			return;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			ASSERT(false, "There was a problem with glfwCreateWindow!");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, Window::resize_callback);
		glfwSetKeyCallback(m_Window, Window::key_callback);
		glfwSetMouseButtonCallback(m_Window, Window::mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, Window::cursor_position_callback);
		glfwSwapInterval(1);
		//glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		if (glewInit() != GLEW_OK)
		{
			ASSERT(false, "Could not initialize GLEW!");
			glfwTerminate();
			return;
		}
		LOG("GLEW initialized successfully! %s", (const char *)glGetString(GL_VERSION));

		glDepthMask(GL_TRUE);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);

		LOG("Window created successfully!");
	}
	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::OnUpdate()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			// Pressing and releasing should only be recognized for 1 frame
			m_KeysPressed[i] = false;
			m_KeysReleased[i] = false;
		}
		for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
		{
			// Pressing and releasing should only be recognized for 1 frame
			m_MouseButtonsPressed[i] = false;
			m_MouseButtonsReleased[i] = false;
		}
		m_LastMouseX = m_MouseX;
		m_LastMouseY = m_MouseY;
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::SetWidth(int width)
	{
		m_Width = width;
	}
	void Window::SetHeight(int height)
	{
		m_Height = height;
	}

	bool Window::IsClosed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}
	bool Window::IsKeyDown(unsigned int key) const
	{
		if (key >= MAX_KEYS)
			return false;
		return m_KeysDown[key];
	}
	bool Window::IsKeyPressed(unsigned int key) const
	{
		if (key >= MAX_KEYS)
			return false;
		return m_KeysPressed[key];
	}
	bool Window::IsKeyReleased(unsigned int key) const
	{
		if (key >= MAX_KEYS)
			return false;
		return m_KeysReleased[key];
	}
	bool Window::IsMouseButtonDown(unsigned int button) const
	{
		if (button >= MAX_MOUSE_BUTTONS)
			return false;
		return m_MouseButtonsDown[button];
	}
	bool Window::IsMouseButtonPressed(unsigned int button) const
	{
		if (button >= MAX_MOUSE_BUTTONS)
			return false;
		return m_MouseButtonsPressed[button];
	}
	bool Window::IsMouseButtonReleased(unsigned int button) const
	{
		if (button >= MAX_MOUSE_BUTTONS)
			return false;
		return m_MouseButtonsReleased[button];
	}
		
	void Window::resize_callback(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
		Window* windowRef = (Window*) glfwGetWindowUserPointer(window);
		windowRef->SetWidth(width);
		windowRef->SetHeight(height);
	}
	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* windowRef = (Window*) glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			windowRef->m_KeysDown[key] = true;
			windowRef->m_KeysPressed[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			windowRef->m_KeysDown[key] = false;
			windowRef->m_KeysReleased[key] = true;
		}
	}
	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* windowRef = (Window*)glfwGetWindowUserPointer(window);
		if (action == GLFW_PRESS)
		{
			windowRef->m_MouseButtonsDown[button] = true;
			windowRef->m_MouseButtonsPressed[button] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			windowRef->m_MouseButtonsDown[button] = false;
			windowRef->m_MouseButtonsReleased[button] = true;
		}
	}
	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* windowRef = (Window*)glfwGetWindowUserPointer(window);
		windowRef->m_MouseX = xpos;
		windowRef->m_MouseY = ypos;
		if (!windowRef->m_HasSetLastMousePositionOnce)
		{
			windowRef->m_LastMouseX = windowRef->m_MouseX;
			windowRef->m_LastMouseY = windowRef->m_MouseY;
			windowRef->m_HasSetLastMousePositionOnce = true;
		}
	}
}}