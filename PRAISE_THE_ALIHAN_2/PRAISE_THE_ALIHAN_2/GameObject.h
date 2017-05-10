#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//Created by: Joshua Green
//Collaboration with: 
#include <string>
#include <vector>

//Physics Headers
#include "vector.h"
#include "body.h"
#include "world.h"
#include "renderable2d.h"

#include <ode/ode.h>

using namespace std;

//GameObject class to keep track of game objects, may need to make the class abstract?




class GameObject {
private:

	

protected:
	//rudimentary method of tracking position until we link up on physics
	struct Position {
		double X;
		double Y;
		//add a vector in here maybe? Talk to Noah
	};

	Position Position;
	int Active; //is the object active in a scene? This could be used to turn something off when off screen, but turn it on when in range. 1 for yes 0 for no
	int Dynamic; //uses dynamic physics? 1 for yes 0 for no, could introduce another state like 2 for something that doesn't use physics at all, but is placed in the scene.
	int Visible; //is rendered? 1 for yes 0 for no, could introduce another state for hack magic <- joke

	string Name; //name of the object
	string Type; //a tag of the object, could be used to find all objects of a certain type, and apply an effect dynamically or something

	int ID;

public:

	Body* rigidBody;

	bool operator==(const GameObject& poop) const;

	GameObject(int id); //the constructors that follow should be self explanatory. 
	GameObject(int id, string strN); //strN for the Name of the object
	GameObject(int id, string strN, string strT);	//strT for the Tag
	GameObject(int id, string strN, string strT, double XPos, double YPos); //name tag and start coords
	GameObject(int id, string strN, double XPos, double YPos);//name and start coords
													  //we can add more constructors as needed. 

	GameObject(int id, string strN, double xPos, double yPos, int physics, int graphics, prototype::maths::vec4 ocolor, prototype::maths::vec2 osize);


	//~GameObject();

	double GetPosX();
	double GetPosY();
	void SetPosX(double newX);
	void SetPosY(double newY);

	string GetName();
	string GetType();
	void SetName(string newName);
	void SetType(string newType);

	int GetActive();
	int GetDynamic();
	int GetVisible();
	void SetActive(__int8 newAct);
	void SetDynamic(__int8 newDyna);
	void SetVisible(__int8 newVisi);

	float RenderPassX();
	float RenderPassY();

	//Physics Stuff
	bool PhysicsEnabled = false;

	void RegisterAsRigidBody(dWorldID worldID);
	void DeRegisterAsRigidBody(void);

	void setMass(double mass);
	double getMass(void);

	//void rotateX(double rotate);
	//void rotateY(double rotate);
	//Vector2 getRotate(void);

	void setLinearVelocity(Vector2 velocity);
	Vector2 getLinearVelocity(void);

	void setAngularVelocity(Vector2 velocity);
	Vector2 getAngularVelocity(void);

	void setCenterOfGravity(Vector2 center);
	Vector2 getCenterOfGravity(void);

	void addForce(Vector2 force);
	void addTorque(Vector2 torque);
	void addRelativeForce(Vector2 force);
	void addRelativeTorque(Vector2 torque);
	void addForceAtPosition(Vector2 force, Vector2 position);
	void addForceAtRelativePosition(Vector2 force, Vector2 position);
	void addRelativeForceAtPosition(Vector2 force, Vector2 position);
	void addRelativeForceAtRelativePosition(Vector2 force, Vector2 position);

	void setForce(Vector2 force);
	Vector2 getForce(void);
	void setTorque(Vector2 torque);
	Vector2 getTorque(void);

	void setDynamic(void);
	void setKinematic(void);
	bool isDynamic(void);
	bool isKinematic(void);

	Vector2 getRelativePointPosition(Vector2 point);
	Vector2 getRelativePointVelocity(Vector2 point);
	Vector2 getPointVelocity(Vector2 point);

	Vector2 getPositionRelativePoint(Vector2 point);

	Vector2 getVectorToWorld(Vector2 point);
	Vector2 getVectorFromWorld(Vector2 point);

	void enableBody(void);
	void disableBody(void);
	bool isEnabled(void);

	void setAutoDisable(bool flag);
	bool getAutoDisable(void);

	void setAutoDisableLinearThreshold(double threshold);
	double getAutoDisableLinearThreshold(void);

	void setAutoDisableAngularThreshold(double threshold);
	double getAutoDisableAngularThreshold(void);

	void setAutoDisableSteps(int steps);
	int getAutoDisableSteps(void);

	void setAutoDisableTime(double time);
	double getAutoDisableTime(void);

	void setAutoDisableAverageSamplesCount(unsigned int averageSamples);
	int getAutoDisableAverageSamplesCount(void);

	void setAutoDisableDefaults(void);

	void setMovedCallback(void(*callback));

	void setLinearDamping(double scale);
	double getLinearDamping(void);

	void setAngularDamping(double scale);
	double getAngularDamping(void);

	void setDamping(double linearScale, double angularScale);

	void setLinearDampingThreshold(double threshold);
	double getLinearDampingThreshold(void);

	void setAngularDampingThreshold(double threshold);
	double getAngularDampingThreshold(void);

	void setDampingDefaults(void);

	double getMaxAngularSpeed(void);
	void setMaxAngularSpeed(double maxSpeed);

	void setData(void* data);
	void* getData(void);

	void setFiniteRotationMode(bool flag);
	bool getFiniteRotationMode(void);

	void setFiniteRotationAxis(Vector2 axis);
	Vector2 getFiniteRotationAxis(void);

	int getNumberOfJoints(void);

	void setAffectedByGravity(bool flag);
	bool isAffectedByGravity(void);

	dWorldID getWorldID(void);

	prototype::graphics::Renderable2D* sprite = NULL;
	void initializeRenderable(prototype::maths::vec3 position, prototype::maths::vec2 size, prototype::maths::vec4 color, prototype::graphics::Shader& shader);
	void initializeRenderable(prototype::graphics::Shader& shader);

	prototype::maths::vec2 size;
	prototype::maths::vec4 color;



};

#endif