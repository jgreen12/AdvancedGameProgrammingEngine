#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include <string>
/********************************************
Author: Charles Miller
input.h
Header file meant to find out if action buttons
(up, down, left, right and jump button) are pressed or not
according to set button string choices along with the axis
choice pressed or not.
********************************************/

namespace prototype {
	namespace graphics {

		class Input {
			private:
				
			public:
				Window *window;

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

					//added for physics functionality testing for Alihan testing
					if (button == "k") {
						return window->isKeyPressed(GLFW_KEY_K);
					}
					



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