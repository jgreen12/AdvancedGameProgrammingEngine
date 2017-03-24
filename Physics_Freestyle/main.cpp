#include "main.h"

#include <stdio.h>

World* world;



int main(void)
{
	dInitODE();

	world = new World();

	Body* body = new Body(world->getWorldID());

	Vector3* force = new Vector3(10, 0, 0);
	Vector3* backForce = new Vector3(-5, 0, 0);

	body->addForce(*force);

	for(int i = 0; i < 1000; i++)
	{
		Vector3 current(body->getPosition());

		printf("Body Position: %f, %f, %f\n", current.getX(), current.getY(), current.getZ());

		world->safeStepWorld(1.3);
	}

	printf("\n\nNow other force\n\n");

	body->addForce(*backForce);

	for (int i = 0; i < 1000; i++)
	{
		Vector3 current(body->getPosition());

		printf("Body Position: %f, %f, %f\n", current.getX(), current.getY(), current.getZ());

		world->safeStepWorld(1.3);
	}


	while (1);

	
}