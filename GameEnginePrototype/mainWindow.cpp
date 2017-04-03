
#include "src/graphics/window.h"

int main() {
	using namespace prototype;
	using namespace graphics;

	Window window("Prototype", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);



	while (!window.closed()) {
		window.clear();
//		glBegin(GL_QUADS);
		

		window.update();
	}

	return 0;
}