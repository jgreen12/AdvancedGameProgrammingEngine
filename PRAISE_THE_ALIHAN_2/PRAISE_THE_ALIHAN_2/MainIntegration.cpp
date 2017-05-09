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
#include "../Dependencies/Debugger/Logger.h"

#include "Scene.h"
#include "GameObject.h"

#include <Windows.h>

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
using namespace std;


GameObject* PlayerObject;

bool physics_running = true;
Scene *s1;
prototype::graphics::Window* window;
//prototype::graphics::Shader* shader;

//huehuehuehuehuehue
//60 fps mofo

DWORD WINAPI Physics_Update(LPVOID vParam) {
	while ( physics_running ) {
		
		s1->safeStepWorld( (1.0/120.0) );
		

		Sleep(8);
	}
	return 0;
}


DWORD WINAPI Graphics_Udate(LPVOID vParam) {
	using namespace prototype;
	using namespace graphics;
	using namespace maths;

	window = new prototype::graphics::Window("Protoype Integration", 1280, 720);
	
	Shader shader("basic.vert", "basic.frag");
	shader.enable();
	mat4 ortho = mat4::orhtographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	
	for (s1->graphicsIter = s1->graphicsList.begin(); s1->graphicsIter != s1->graphicsList.end(); s1->graphicsIter++) {	//position,	SIZE oh wait no, he meant SCALE, COLOR
		(*(s1->graphicsIter))->initializeRenderable(prototype::maths::vec3((*(s1->graphicsIter))->RenderPassX(), (*(s1->graphicsIter))->RenderPassY(), 0), prototype::maths::vec2(4, 4), prototype::maths::vec4(1, 0, 1, 1), shader);
	}

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

		for (s1->graphicsIter = s1->graphicsList.begin(); s1->graphicsIter != s1->graphicsList.end(); s1->graphicsIter++) {
			(*(s1->graphicsIter))->sprite->update(prototype::maths::vec3((*(s1->graphicsIter))->RenderPassX(), (*(s1->graphicsIter))->RenderPassY(), 0));
			//cout << "Render Pass: " << s1->graphicsIter->RenderPassX() << " " << s1->graphicsIter->RenderPassY() << endl;
			//cout << "Get Pass: " << s1->graphicsIter->GetPosX() << " " << s1->graphicsIter->GetPosY() << endl;
			renderer.submit((*(s1->graphicsIter))->sprite);
		}
		
		
		renderer.flush();
		window->update();

		Sleep(16);
	}

	//testing purposes get rid of laters
	physics_running = false;
	return 0;

}




int main() 
{

	//Debugger Example Crap
	Logger eh("test.txt");
	
	/*__try
	{
		int z = 0;
		int x = 5;
		int t = x / z;
	}
	__except (eh.ExpFilter(GetExceptionInformation(), GetExceptionCode()))
	{

	}
	*/
	eh.OnOutput("Test");

	
	


	//this was the crash problem
	dInitODE();
	// ^^^^^^^

	s1 = new Scene();
	s1->RegisterAsWorld();
	s1->setLinearDamping(0);
	//s1->setGravity(Vector2(0, -10));

	GameObject g(s1->NumOfObjects++);
	
	s1->AddObject(g);
	g.SetPosX(5);
	g.SetPosY(5);
	g.RegisterAsRigidBody(s1->getWorldID()); 


	GameObject g2(s1->NumOfObjects++);
	s1->AddObject(g2);
	g2.SetPosX(5);
	g2.SetPosY(2);
	g2.RegisterAsRigidBody(s1->getWorldID());
	

	g.setLinearVelocity(Vector2(0, -1));
	//g.setLinearVelocity(Vector2(1, 1));
	//g.addForce(Vector2(5, 5));
	
	//cout << g.getLinearVelocity().getX();

	//(*(s1->fullBeginIter))->setLinearVelocity(Vector2(1, 1));

	for (s1->fullBeginIter = s1->fullListOfObjects.begin(); s1->fullBeginIter != s1->fullListOfObjects.end(); s1->fullBeginIter++) {
		//(*(s1->fullBeginIter))->setLinearVelocity(Vector2(1,1));
		//(*(s1->fullBeginIter))->addForce(Vector2(10,10));
		//(*(s1->fullBeginIter))->addRelativeForce(Vector2(10, 10));
		//cout << (*(s1->fullBeginIter))->getLinearVelocity().getX();
	}


	DWORD graphWord;	//graphics thread reference
	DWORD physWord;		//physics thread reference
	HANDLE gameHandles[2]; //handles for the thread handle
	gameHandles[0] = CreateThread(NULL, 0, Physics_Update, NULL, 0, &physWord);		//create the thread for physics
	gameHandles[1] = CreateThread(NULL, 0, Graphics_Udate, NULL, 0, &graphWord);	//create the thread for graphics
	
	WaitForMultipleObjects(2, gameHandles, TRUE, INFINITE);

	s1->RemoveAllObjects();
	delete s1;


	char junk;
	cin >> junk;
	
	return 0;
}