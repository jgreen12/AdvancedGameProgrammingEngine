#include "window.h"
#include <iostream>


namespace prototype {
	namespace graphics {


		void window_resize(GLFWwindow *window, int width, int height);

		Window::Window(const char *name, int width, int height) {
			m_title = name;
			m_width = width;
			m_height = height;
			if (!init()) {
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_buttons[i] = false;
			}
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to iniuialize GLFW" << std::endl;
				return false;
			}
			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);

			if (!m_window) {
				glfwTerminate();
				std::cout << "failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Glew didn't work" << std::endl;
				return false;
			}

			return true;
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::isKeyPressed(unsigned int keyCode) const {
			// LOG THIS AT SOME POINT
			if (keyCode >= MAX_KEYS)
				return false;
			return m_keys[keyCode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const {
			// LOG THIS AT SOME POINT
			if (button >= MAX_KEYS)
				return false;
			return m_buttons[button];
		}

		void Window::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL Error: " << error << std::endl;
			glfwPollEvents();
			//			glfwGetFramebufferSize(m_window, &m_width, &m_height);
			glfwSwapBuffers(m_window);


		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_window) == 1;
		}


		void window_resize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);

		}

		void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_buttons[button] = action != GLFW_RELEASE;
		}

		void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_keys[key] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}
