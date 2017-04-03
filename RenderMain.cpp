// Headers
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
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
#include <SFML/OpenGL.hpp>
#include <string>
#include <iostream>
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
//#include ".\GameObject.cpp"


// Shader sources
const GLchar* vertexSource =
"#version 400\n"
"in vec2 position;"
"in vec3 color;"
"in vec2 texcoord;"
"out vec3 Color;"
"out vec2 Texcoord;"
"void main() {"
"   Color = color;"
"   Texcoord = texcoord;"
"   gl_Position = vec4(position, 1.0, 1.0);"
"}";

const GLchar* fragmentSource =
"#version 400\n"
"in vec3 Color;"
"in vec2 Texcoord;"
"out vec4 outColor;"
"uniform sampler2D teximagePNG;"
"void main() {"
"   outColor = texture(teximagePNG, Texcoord);"
"}";


sf::Window window(sf::VideoMode(900, 700, 32), "Renderer", sf::Style::Titlebar | sf::Style::Default);

void ManageWindow()
{
	while (window.isOpen())
	{
		// Blue Background
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw a rectangle from the 2 triangles using 6 vertices
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		// Swap buffers
		window.display();
	}
}

int main()
{

	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();

	// Create Vertex Array Object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create a Vertex Buffer Object and copy the vertex data to it
	GLuint vbo;
	glGenBuffers(1, &vbo);

	GLfloat vertices[] = 
	{
//  Rectangle Position set to Origin		Color		           Texcoords (Texture in Rectangle Position)
		-0.5f,  0.5f,					1.0f, 0.0f, 0.0f,		0.0f, 0.0f, // Top-left
		0.5f,  0.5f,					0.0f, 1.0f, 0.0f,		1.0f, 0.0f, // Top-right
		0.5f, -0.5f,					0.0f, 0.0f, 1.0f,		1.0f, 1.0f, // Bottom-right
		-0.5f, -0.5f,					1.0f, 1.0f, 1.0f,		0.0f, 1.0f  // Bottom-left
	};

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Create an element array
	GLuint ebo;
	glGenBuffers(1, &ebo);

	// Do Not Touch!!! Keeps it in rectangle format
	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Specify the layout of the vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);

	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

	GLint texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*)(5 * sizeof(GLfloat)));



	// Load textures
	//GLuint textures[2];
	//glGenTextures(2, textures);


	sf::Image imagePNG;
	imagePNG.loadFromFile("nyancat.gif");

	//sf::Vector2i spriteSize(32, 32);
	
	
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE0, textures[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imagePNG.getSize().x, imagePNG.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagePNG.getPixelsPtr());
	
	//glUniform1i(glGetUniformLocation(shaderProgram, "teximagePNG"), 0);

	//glEnable(GL_TEXTURE_2D);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	ManageWindow();

	//glDeleteTextures(2, textures);

	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);

	glDeleteVertexArrays(1, &vao);

	return 0;
}

