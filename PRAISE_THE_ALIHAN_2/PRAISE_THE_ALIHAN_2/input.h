#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <string>

namespace prototype {
	namespace graphics {

		class Input {
			private:
				Window *window;
			public:
				inline Input(Window *win) {
					window = win;
				}

				inline int getButton(std::string button) {
					if (button == "up")
						return window->isKeyPressed(GLFW_KEY_UP);
					if (button == "down")
						return window->isKeyPressed(GLFW_KEY_DOWN);
					if (button == "left")
						return window->isKeyPressed(GLFW_KEY_LEFT);
					if (button == "right")
						return window->isKeyPressed(GLFW_KEY_RIGHT);
					if (button == "jump")
						return window->isKeyPressed(GLFW_KEY_SPACE);
				}

				inline int getAxis(std::string axis) {
					if (axis == "horizontal")
						return window->isKeyPressed(GLFW_KEY_RIGHT) - window->isKeyPressed(GLFW_KEY_LEFT);
					if (axis == "vertical")
						return window->isKeyPressed(GLFW_KEY_UP) - window->isKeyPressed(GLFW_KEY_DOWN);

				}

				inline void Update() {

				};

		};
	}
}