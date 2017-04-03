#include "window.h"
#include "vec2.h"

int main() {
	using namespace prototype;
	using namespace graphics;
	using namespace maths;

	Window window("Prototype", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 2.0f);

	while (!window.closed()) {
		window.clear();
		std::cout << vector << std::endl;
#if 1

		glBegin(GL_QUADS);
		glVertex2f(-.5f, -.5f);
		glVertex2f(-.5f, .5f);
		glVertex2f(.5f, .5f);
		glVertex2f(.5f, -.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	return 0;
}