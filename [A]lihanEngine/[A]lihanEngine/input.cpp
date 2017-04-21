#pragma once
/*#include <iostream>
#include <GL/glew.h>
#include "input.h"


#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace prototype {
	namespace input {

		bool Input::isKeyPressed(unsigned int keyCode) const {
			if (keyCode >= MAX_KEYS)
				return false;
			return m_keys[keyCode];
		}

		bool Input::isMouseButtonPressed(unsigned int button) const {
			if (button >= MAX_KEYS)
				return false;
			return m_buttons[button];
		}

		void Input::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}

		bool Input::init(GLFWwindow *m_window) {
			if (!glfwInit()) {
				std::cout << "Failed to iniuialize GLFW" << std::endl;
				return false;
			}
//			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

			if (!m_window) {
				glfwTerminate();
				std::cout << "failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
//			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Glew didn't work" << std::endl;
				return false;
			}
		}

	}
}*/