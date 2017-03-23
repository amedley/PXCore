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
		class Window
		{
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			void setWidth(int width);
			void setHeight(int height);

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }
		private:
			bool init();
		};
		static Window *mainWindow;
	}
}

#endif