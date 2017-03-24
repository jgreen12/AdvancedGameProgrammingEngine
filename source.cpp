#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#define GLEW_STATIC
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glut/GL/glut.h>
//#include <ode/ode/ode.h>
//#include <sdl/SDL.h>
#include <SOIL.h>
#include <SFML/OpenGL.hpp>
#include <string>
#include <iostream>
//#include ".\GameObject.cpp"

GLuint initShader(const char* source, GLenum type)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, (const GLchar**)&source, NULL);
	glCompileShader(shader);

	GLint  compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		fprintf(stderr, "Failed to compile shader!\n");
		fprintf(stderr, "%s\n", source);

		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);


		char *infoLog = new char[maxLength];
		glGetShaderInfoLog(shader, maxLength, NULL, infoLog);

		std::cout << infoLog << std::endl;

		free(infoLog);

		exit(EXIT_FAILURE);
	}
	return shader;

}

// Create a GLSL program object from vertex and fragment shader strings
//
GLuint initShaders(const char* vertShaderSrc, const char *fragShaderSrc) {
	GLuint program = glCreateProgram();
	glAttachShader(program, initShader(vertShaderSrc, GL_VERTEX_SHADER));
	glAttachShader(program, initShader(fragShaderSrc, GL_FRAGMENT_SHADER));
	glLinkProgram(program);

	/* link  and error check */
	GLint  linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
		GLint  logSize = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logSize);

		char *infoLog = new char[logSize];
		glGetProgramInfoLog(program, logSize, NULL, infoLog);
		std::cout << infoLog << std::endl;
		free(infoLog);
		exit(EXIT_FAILURE);
	}
	else {
		// std::cout << "Shaders link successful!\n";
	}

	return program;
}

float colors[] = {
	1, 0, 0,
	0, 1, 0,
	0, 0, 1,
};

GLfloat texCoords[] = {
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
};

GLuint vbo = 0; GLuint vao = 0; GLuint shader_programme;

GLfloat vertices[] = {
	// Positions          // Colors           // Texture Coords
	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // Bottom Right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // Bottom Left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // Top Left 
};


void readGameObject()
{
	/*
	for(int i = 0; i < 9; i++)
	{
		texCoords[i] = ;
		colors[i] = ;
	}
	*/

	
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	int width, height;
	unsigned char* image = SOIL_load_image("w.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	
}

void init()
{
	readGameObject();

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords) + sizeof(colors), NULL, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(texCoords), texCoords);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(texCoords), sizeof(colors), colors);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"in vec3 vc; "
		"out vec3 color; "
		"void main () {"
		"  gl_Position = vec4 (vp, 1.0);"
		"  color = vc;"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"in vec3 color;"
		"out vec4 frag_color;"
		"void main () {"
		"  frag_color = vec4(color, 1.0);"
		"}";


	shader_programme = initShaders(vertex_shader, fragment_shader);
	glUseProgram(shader_programme);

	GLint vPosition = glGetAttribLocation(shader_programme, "vp");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

	GLint vColor = glGetAttribLocation(shader_programme, "vc");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, (void *) sizeof(texCoords));

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.000, 1.000, 1.0);
	glDepthFunc(GL_LESS);
}


int main() {
	// start GL context and O/S window using the GLFW helper library
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Renderer", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	/* OTHER STUFF GOES HERE NEXT */
	init();

	while (!glfwWindowShouldClose(window)) {
		// wipe the drawing surface clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// draw points 0-3 from the currently bound VAO with current in-use shader
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// update other events like input handling 
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers(window);
	}
	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}
