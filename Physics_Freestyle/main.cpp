#include "main.h"

#include <stdio.h>

World* world;

double verticies[] = {
	0, 0, 0,
	0, 4, 0,
	4, 4, 0,
	4, 0, 0
};


int main(void)
{
	dInitODE();

	world = new World();


	world->physicsStateToFile(stdout);

	world->set3DGravity(Vector3(0, -10, 0));

	world->physicsStateToFile(stdout);

	Body* body = new Body(world->getWorldID(), world->getSpaceID());
	Body* otherBody = new Body(world->getWorldID(), world->getSpaceID());

	body->setBoxLengths(100, 2, 0);
	otherBody->setBoxLengths(2, 2, 0);

	otherBody->setMass(100);

	printf("mass: %f\n", otherBody->getMass());

	body->setPosition(Vector3(0, 0, 0));
	otherBody->setPosition(Vector3(0, 10, 0));

	body->setAffectedByGravity(0);
	otherBody->setAffectedByGravity(1);

	Vector3* force = new Vector3(10, 0, 0);
	Vector3* backForce = new Vector3(-5, 0, 0);

	//body->addForce(*force);
	//-8551540
	for(int i = 0; i < 1000; i++)
	{
		Vector3 current(body->getPosition());
		Vector3 falling(otherBody->getPosition());
		

		printf("Body Position: %f, %f, %f\n", current.getX(), current.getY(), current.getZ());

		printf("Other Position: %f, %f, %f\n", falling.getX(), falling.getY(), falling.getZ());

		world->safeStepWorld((1.0/120.0));
	}

	world->physicsStateToFile(stdout);

	printf("\n\nNow other force\n\n");

	//body->addForce(*backForce);

	//for (int i = 0; i < 1000; i++)
	//{
	//	Vector3 current(body->getPosition());

	//	printf("Body Position: %f, %f, %f\n", current.getX(), current.getY(), current.getZ());

	//	world->safeStepWorld(1.3);
	//}


	while (1);

	
}