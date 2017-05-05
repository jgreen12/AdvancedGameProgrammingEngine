#ifndef SCENE
#define SCENE

//documentation on Lists https://msdn.microsoft.com/en-us/library/802d66bt.aspx
//This is not complete by any means, I will flesh it out as we continue the merging process, this is just a starting point.


//created by: Joshua Green
//#include <list>
//#include <string>
//#include "GameObject.h"
#include "Scene.h"

//Physics Headers
//#include "vector.h"
//#include "body.h"
//#include "world.h"


//#include <ode/ode.h>

using namespace std;



void Scene::RegisterAsWorld(void)
{
	if (!PhysicsEnabled)
	{
		physicsWorld = new World();
		PhysicsEnabled = true;
	}
}

void Scene::DeRegisterAsWorld(void)
{
	if (PhysicsEnabled)
	{
		delete physicsWorld;
		PhysicsEnabled = false;
	}
}

dWorldID Scene::getWorldID(void)
{
	if (PhysicsEnabled)
	{
		return physicsWorld->getWorldID();
	}
}

void Scene::setGravity(Vector2 gravity)
{
	if (PhysicsEnabled)
	{
		physicsWorld->set3DGravity(gravity.convertTo3Vector());
	}
}

Vector2 Scene::getGravity(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		temp = physicsWorld->getGravity().convertTo2Vector();
		return temp;
	}

	return temp;
}

void Scene::setAutoDisableBodies(bool flag)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAutoDisableBodies(flag);
	}
}

void Scene::setAutoDisableLinearThreshold(double linearThreshold)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAutoDisableLinearThreshold(linearThreshold);
	}
}

void Scene::setAutoDisableAngularThreshold(double angularThreshold)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAutoDisableAngularThreshold(angularThreshold);
	}
}

void Scene::setAutoDisableSteps(int steps)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAutoDisableSteps(steps);
	}
}

void Scene::setAutoDisableTime(double time)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAutoDisableTime(time);
	}
}

Vector2 Scene::convertImpulseToForce(double stepSize, Vector2 impulse)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		temp = physicsWorld->convertImpulseToForce(stepSize, impulse.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}

void Scene::safeStepWorld(double stepSize)
{
	if (PhysicsEnabled)
	{
		physicsWorld->safeStepWorld(stepSize);
	}
}

void Scene::quickStepWorld(double stepSize)
{
	if (PhysicsEnabled)
	{
		physicsWorld->quickStepWorld(stepSize);
	}
}

void Scene::setQuickStepNumberIterations(int num)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setQuickStepNumberIterations(num);
	}
}

void Scene::setQuickStepOverRelaxation(int overRelaxation)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setQuickStepOverRelaxation(overRelaxation);
	}
}

void Scene::setLinearDamping(double scale)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setLinearDamping(scale);
	}
}

void Scene::setAngularDamping(double scale)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAngularDamping(scale);
	}
}

void Scene::setLinearDampingThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setLinearDampingThreshold(threshold);
	}
}

void Scene::setAngularDampingThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setAngularDampingThreshold(threshold);
	}
}

void Scene::setMaxAngularSpeed(double maxSpeed)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setMaxAngularSpeed(maxSpeed);
	}
}

void Scene::setContactMaxCorrectingVelocity(double velocity)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setContactMaxCorrectingVelocity(velocity);
	}
}

void Scene::setContactSurfaceLayer(double depth)
{
	if (PhysicsEnabled)
	{
		physicsWorld->setContactSurfaceLayer(depth);
	}
}


void Scene::RemoveObject(GameObject &g) {
	fullListOfObjects.remove(&g);
	if (g.GetVisible() == 1) {
		graphicsList.remove(&g);
	}
}

void Scene::UpdateObjects() {
	//should iterate through the list calling any update functions we define
}

void Scene::AddObject(GameObject &g) {
	//simple method to add the objects to the list
	fullListOfObjects.push_front(&g);
	if (g.GetVisible() == 1) {
		graphicsList.push_front(&g);
	}
}

void Scene::RemoveAllObjects() {
	//clears all objects from the list
	fullListOfObjects.clear();
	graphicsList.clear();
}




Scene::Scene() {
	SceneName = "New Scene";
	NumOfObjects = 0;
	fullBeginIter = fullListOfObjects.begin();
}

#endif