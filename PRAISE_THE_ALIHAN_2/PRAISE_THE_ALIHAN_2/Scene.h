#pragma once

#ifndef SCENE_H
#define SCENE_H

//created by: Joshua Green
#include <list>
#include <string>
#include "GameObject.h"

//Physics Headers
#include "vector.h"
#include "body.h"
#include "world.h"


#include <ode/ode.h>

using namespace std;

class Scene {
private:
	string SceneName;
	
	list<GameObject> fullListOfObjects;
	list<GameObject>::iterator fullBeginIter;

	World* physicsWorld;

protected:


public:
	Scene();
	void RemoveAllObjects();
	void AddObject(GameObject g);
	void UpdateObjects();
	void RemoveObject(GameObject g);

	int NumOfObjects;
	//Physics Stuff
	bool PhysicsEnabled = false;

	void RegisterAsWorld(void);
	void DeRegisterAsWorld(void);

	dWorldID getWorldID(void);

	void setGravity(double x, double y);
	void setGravity(Vector2 vector);
	Vector2 getGravity(void);

	void setAutoDisableBodies(bool flag);
	void setAutoDisableLinearThreshold(double linearThreshold);
	void setAutoDisableAngularThreshold(double angularThreshold);
	void setAutoDisableSteps(int steps);
	void setAutoDisableTime(double time);

	Vector2 convertImpulseToForce(double stepSize, Vector2 impulse);

	void safeStepWorld(double stepSize);
	void quickStepWorld(double stepSize);

	void setQuickStepNumberIterations(int num);
	void setQuickStepOverRelaxation(int overRelaxation);

	void setLinearDamping(double scale);
	void setAngularDamping(double scale);

	void setLinearDampingThreshold(double threshold);
	void setAngularDampingThreshold(double threshold);

	void setMaxAngularSpeed(double maxSpeed);

	void setContactMaxCorrectingVelocity(double velocity);

	void setContactSurfaceLayer(double depth);
};

#endif