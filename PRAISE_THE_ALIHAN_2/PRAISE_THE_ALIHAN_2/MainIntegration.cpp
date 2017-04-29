#include <iostream>
#include "window.h"
#include "maths.h"
#include "shader.h"
#include "buffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "renderer2d.h"
#include "renderable2d.h"
#include "simple2drenderer.h"

#include "Scene.h"
#include "GameObject.h"

#include <Windows.h>

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
using namespace std;




bool physics_running = true;
Scene *s1;
prototype::graphics::Window* window;


//huehuehuehuehuehue
//60 fps mofo

DWORD WINAPI Physics_Update(LPVOID vParam) {

	while ( physics_running ) {

		s1->safeStepWorld( (1.0/120.0) );
		cout << "PHYSICS UPDATE RREEEEEEEEE\n";
		Sleep(16);
	}

	
	return 0;
}




//fuck this shit
DWORD WINAPI Graphics_Udate(LPVOID vParam) {
	using namespace prototype;
	using namespace graphics;
	using namespace maths;

	//Window window("Protoype Integration", 1280, 720);
	window = new Window ("Protoype Integration", 1280, 720);
	
	mat4 ortho = mat4::orhtographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("basic.vert", "basic.frag");

	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	//Renderable2D sprite(maths::vec3(7, 1, 0), maths::vec2(2,3), maths::vec4(.2f, 0, 1, 1), shader);

	Simple2DRenderer renderer;

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("col", vec4(0.2f, 0.3f, 0.8f, 1.0f));



	//changed to global pointer, changed '.' to '->'


	//example framework change condition eventually.
	double x, y;
	while (!window->closed()) {
		
		window->clear();
		window->getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 1280.0f), (float)(9.0f - y * 9.0f / 720.0f)));




		//this is testing!
		sprite.update(vec3(window->isKeyPressed(GLFW_KEY_RIGHT) - window->isKeyPressed(GLFW_KEY_LEFT), window->isKeyPressed(GLFW_KEY_UP) - window->isKeyPressed(GLFW_KEY_DOWN), 0));




		renderer.submit(&sprite);
		renderer.flush();
		window->update();


		//test get rid of later
		cout << "GRAPHICS UPDATED WOOOOOOOO!\n";


		Sleep(16);
	}

	//testing purposes get rid of laters
	physics_running = false;
	
	return 0;
}












int main() {

	//this was the crash problem
	dInitODE();
	// ^^^^^^^





	s1 = new Scene();
	s1->RegisterAsWorld();

	GameObject g1(s1->NumOfObjects++);
	
	s1->AddObject(g1);
	g1.RegisterAsRigidBody(s1->getWorldID());
	





	DWORD graphWord;
	
	DWORD physWord;
	HANDLE gameHandles[2];

	gameHandles[0] = CreateThread(NULL, 0, Physics_Update, NULL, 0, &physWord);
	gameHandles[1] = CreateThread(NULL, 0, Graphics_Udate, NULL, 0, &graphWord);

	
	


	Sleep(100);
	
	WaitForMultipleObjects(2, gameHandles, TRUE, INFINITE);

	s1->RemoveAllObjects();
	delete s1;


	char junk;
	cin >> junk;
	
	return 0;
}