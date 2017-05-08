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
		
		
		
		//PlayerObject->setLinearVelocity(Vector2(1, 1));
		
		
		//cout << PlayerObject->RenderPassX() << " " << PlayerObject->RenderPassY();
		
		
		
		s1->safeStepWorld( (1.0/120.0) );
		//cout << "PHYSICS UPDATE\n";

		//modify for physics use
		//sprite.update(vec3(window->isKeyPressed(GLFW_KEY_RIGHT) - window->isKeyPressed(GLFW_KEY_LEFT), window->isKeyPressed(GLFW_KEY_UP) - window->isKeyPressed(GLFW_KEY_DOWN), 0));





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
	/*window = new prototype::graphics::Window("Protoype Integration", 1280, 720);
	shader = new prototype::graphics::Shader("basic.vert", "basic.frag");*/
	mat4 ortho = mat4::orhtographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	//PlayerObject->initializeRenderable(prototype::maths::vec3(5, 5, 0), prototype::maths::vec2(4, 4), prototype::maths::vec4(1, 0, 1, 1), shader);

	//Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), *shader);
	//Renderable2D sprite(maths::vec3(7, 1, 0), maths::vec2(2,3), maths::vec4(.2f, 0, 1, 1), shader);
	
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

		//PlayerObject->setLinearVelocity(Vector2(1, 1));



		window->clear();
		window->getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 1280.0f), (float)(9.0f - y * 9.0f / 720.0f)));
		//this is testing!
		//PlayerObject->sprite->update(vec3(window->isKeyPressed(GLFW_KEY_RIGHT) - window->isKeyPressed(GLFW_KEY_LEFT), window->isKeyPressed(GLFW_KEY_UP) - window->isKeyPressed(GLFW_KEY_DOWN), 0));

		//renderer.submit(PlayerObject->sprite);
		


		/*for (s1->fullBeginIter = s1->fullListOfObjects.begin(); s1->fullBeginIter != s1->fullListOfObjects.end(); s1->fullBeginIter++) {
			s1->fullBeginIter->sprite->update(prototype::maths::vec3(s1->fullBeginIter->RenderPassX(), s1->fullBeginIter->RenderPassY(), 0));
		}*/
		for (s1->graphicsIter = s1->graphicsList.begin(); s1->graphicsIter != s1->graphicsList.end(); s1->graphicsIter++) {
			(*(s1->graphicsIter))->sprite->update(prototype::maths::vec3((*(s1->graphicsIter))->RenderPassX(), (*(s1->graphicsIter))->RenderPassY(), 0));
			//cout << "Render Pass: " << s1->graphicsIter->RenderPassX() << " " << s1->graphicsIter->RenderPassY() << endl;
			//cout << "Get Pass: " << s1->graphicsIter->GetPosX() << " " << s1->graphicsIter->GetPosY() << endl;
			renderer.submit((*(s1->graphicsIter))->sprite);
		}
		
		
		renderer.flush();
		window->update();
		//test get rid of later
		//cout << "GRAPHICS UPDATED\n";

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
	
	__try
	{
		int z = 0;
		int x = 5;
		int t = x / z;
	}
	__except (eh.ExpFilter(GetExceptionInformation(), GetExceptionCode()))
	{

	}

	eh.OnOutput("Test");

	
	


	//this was the crash problem
	dInitODE();
	// ^^^^^^^
	
	//shader = new prototype::graphics::Shader("basic.vert", "basic.frag");
	//shader->enable();

	s1 = new Scene();
	s1->RegisterAsWorld();
	s1->setLinearDamping(0);
	s1->setGravity(Vector2(0, -10));

	
	//GameObject g1(s1->NumOfObjects++);
	//PlayerObject = new GameObject(s1->NumOfObjects++);
	GameObject g(s1->NumOfObjects);
	g.SetPosX(10);
	g.SetPosY(80);
	s1->AddObject(g);
	g.RegisterAsRigidBody(s1->getWorldID()); //le broke
	//g.setLinearVelocity(Vector2(1, 1));
	g.addForce(Vector2(5, 5));
	
	cout << g.getLinearVelocity().getX();

	//(*(s1->fullBeginIter))->setLinearVelocity(Vector2(1, 1));

	for (s1->fullBeginIter = s1->fullListOfObjects.begin(); s1->fullBeginIter != s1->fullListOfObjects.end(); s1->fullBeginIter++) {
		//(*(s1->fullBeginIter))->setLinearVelocity(Vector2(1,1));
		(*(s1->fullBeginIter))->addForce(Vector2(10,10));
		//(*(s1->fullBeginIter))->addRelativeForce(Vector2(10, 10));
		cout << (*(s1->fullBeginIter))->getLinearVelocity().getX();
	}

	//g.SetPosX(9);
	//g.SetPosY(9);


	//Vector2 IMOUTSIDEHOWBOUTDAH (10, 10);
	//g.setLinearVelocity(IMOUTSIDEHOWBOUTDAH);

	/*PlayerObject = &g;
	
	PlayerObject->SetPosX(1);
	PlayerObject->SetPosY(1);
	*/
/*
	printf("g: %d %d\n", g.GetPosX(), g.GetPosY());
	printf("PO: %d %d\n", PlayerObject->GetPosX(), PlayerObject->GetPosY());)*/



	//PlayerObject->RegisterAsRigidBody(s1->getWorldID());


//	PlayerObject->initializeRenderable(prototype::maths::vec3(5, 5, 0), prototype::maths::vec2(4, 4), prototype::maths::vec4(1, 0, 1, 1), *shader);
	//*PlayerObject = g1; //global player reference

	/*GameObject rando1(s1->NumOfObjects++);
	s1->AddObject(rando1);
	rando1.RegisterAsRigidBody(s1->getWorldID());
	*/

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