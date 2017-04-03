#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace prototype {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {
		private:
			int m_width, m_height;
			const char *m_title;
			GLFWwindow* m_window;
			bool m_closed;

			bool m_keys[MAX_KEYS];
			bool m_buttons[MAX_BUTTONS];
			double mx, my;


		public:
			Window(const char *name, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;

			inline int getWidth() const { return m_width; }
			inline int getHeight() const { return m_height; }

			bool isKeyPressed(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int buttonCode) const;
			void getMousePosition(double& x, double& y) const;//to be set to return Vector2 later
		private:
			bool init();
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
		};
}}