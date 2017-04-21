/*#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace prototype {
	namespace input {
		class Input {
		private:
			bool m_keys[MAX_KEYS];
			bool m_buttons[MAX_BUTTONS];
			double mx, my;
		public:
			bool isKeyPressed(unsigned int keyCode) const;
			bool isMouseButtonPressed(unsigned int buttonCode) const;
			void getMousePosition(double& x, double& y) const;

		private:
			bool init(GLFWwindow *window);
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
		};
	}
}*/