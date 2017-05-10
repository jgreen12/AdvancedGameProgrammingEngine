#ifndef GAMEOBJECT
#define GAMEOBJECT

//#pragma warning (disable : 4996 3)



//Comment any functions or changes to function you make so that we can keep track of who did the additions, BitBucket does this, but Alihan won't know without the comments.

//Created by: Joshua Green
//Collaboration with: Noah Pena
//#include <string>
//#include <vector>

//Physics Headers
//#include "vector.h"
//#include "body.h"
//#include "world.h"

#include "GameObject.h"


//#include <ode/ode.h>

using namespace std;

//GameObject class to keep track of game objects, may need to make the class abstract?


//THIS WILL NEED AN OVERLOADED ASSIGNMENT OPERATOR FROM CHARLES PART
void GameObject::initializeRenderable(prototype::maths::vec3 position, prototype::maths::vec2 size, prototype::maths::vec4 color, prototype::graphics::Shader& shader) {
	sprite = new prototype::graphics::Renderable2D(position, size, color, shader);
}

void GameObject::initializeRenderable(prototype::graphics::Shader& shader) {
	sprite = new prototype::graphics::Renderable2D(prototype::maths::vec3 (GetPosX(), GetPosY(), 0), size, color, shader);
}
	

bool GameObject::operator== (const GameObject &g1) const {
	return this->ID == g1.ID;
}




float GameObject::RenderPassX() 
{
	return ((float)GetPosX());
}
float GameObject::RenderPassY() 
{
	return ((float)GetPosY());
}





int GameObject::GetActive() {
	return Active;
}
int GameObject::GetDynamic() {
	return Dynamic;
}
int GameObject::GetVisible() {
	return Visible;
}
void GameObject::SetActive(__int8 newAct) {
	Active = newAct;
}
void GameObject::SetDynamic(__int8 newDyna) {
	Dynamic = newDyna;
}
void GameObject::SetVisible(__int8 newVisi) {
	Visible = newVisi;
}
string GameObject::GetName() {
	return Name;
}
void GameObject::SetName(string newName) {
	Name = newName;
}
string GameObject::GetType() {
	return Type;
}
void GameObject::SetType(string newType) {
	Type = newType;
}



//Positional Getters and Setters, probably upgrade when integrated with Physics
double GameObject::GetPosX() {

	if (PhysicsEnabled)
	{
		return rigidBody->getPosition().getX();
	}
	else
	{
		return Position.X;
	}
}
double GameObject::GetPosY() 
{
	if (PhysicsEnabled)
	{
		return rigidBody->getPosition().getY();
	}
	else
	{
		return Position.Y;
	}
}
void GameObject::SetPosX(double newX) 
{
	if (PhysicsEnabled)
	{
		rigidBody->setPosition(Vector3(newX, GetPosY(), 0));
	}
	else
	{
		Position.X = newX;
	}
}
void GameObject::SetPosY(double newY) 
{
	if (PhysicsEnabled)
	{
		rigidBody->setPosition(Vector3(GetPosX(), newY, 0));
	}
	else
	{
		Position.Y = newY;
	}
}


//Physics Stuff
void GameObject::RegisterAsRigidBody(dWorldID worldID)
{
	rigidBody = new Body(worldID);
	rigidBody->setPosition(Vector3(GetPosX(), GetPosY(), 0));
	this->PhysicsEnabled = true;
	
}
void GameObject::DeRegisterAsRigidBody(void)
{
	delete rigidBody;
	this->PhysicsEnabled = false;
}

void GameObject::setMass(double mass)
{
	if (PhysicsEnabled)
	{
		rigidBody->setMass(mass);
	}
}
double GameObject::getMass(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getMass();
	}

	return -1;
}

//void GameObject::rotateX(double rotate)
//{
//	//eh
//}
//void GameObject::rotateY(double rotate)
//{
//	//eh
//}
//Vector2 GameObject::getRotate(void)
//{
//	//eh
//}

void GameObject::setLinearVelocity(Vector2 velocity)
{
	if (PhysicsEnabled)
	{
		rigidBody->setLinearVelocity(velocity.convertTo3Vector());
	}
}
Vector2 GameObject::getLinearVelocity(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		 return rigidBody->getLinearVelocity().convertTo2Vector();
	}

	return temp;
}

void GameObject::setAngularVelocity(Vector2 velocity)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAngularVelocity(velocity.convertTo3Vector());
	}
}
Vector2 GameObject::getAngularVelocity(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getAngularVelocity().convertTo2Vector();
	}

	return temp;
}

void GameObject::setCenterOfGravity(Vector2 center)
{
	if (PhysicsEnabled)
	{
		rigidBody->setCenterOfGravity(center.convertTo3Vector());
	}
}
Vector2 GameObject::getCenterOfGravity(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getCenterOfGravity().convertTo2Vector();
	}

	return temp;
}

void GameObject::addForce(Vector2 force)
{
	if (PhysicsEnabled)
	{
		rigidBody->addForce(force.convertTo3Vector());
	}
}
void GameObject::addTorque(Vector2 torque)
{
	if (PhysicsEnabled)
	{
		rigidBody->addTorque(torque.convertTo3Vector());
	}
}
void GameObject::addRelativeForce(Vector2 force)
{
	if (PhysicsEnabled)
	{
		rigidBody->addRelativeForce(force.convertTo3Vector());
	}
}
void GameObject::addRelativeTorque(Vector2 torque)
{
	if (PhysicsEnabled)
	{
		rigidBody->addRelativeTorque(torque.convertTo3Vector());
	}
}
void GameObject::addForceAtPosition(Vector2 force, Vector2 position)
{
	if (PhysicsEnabled)
	{
		rigidBody->addForceAtPosition(force.convertTo3Vector(), position.convertTo3Vector());
	}
}
void GameObject::addForceAtRelativePosition(Vector2 force, Vector2 position)
{
	if (PhysicsEnabled)
	{
		rigidBody->addForceAtRelativePosition(force.convertTo3Vector(), position.convertTo3Vector());
	}
}
void GameObject::addRelativeForceAtPosition(Vector2 force, Vector2 position)
{
	if (PhysicsEnabled)
	{
		rigidBody->addRelativeForceAtPosition(force.convertTo3Vector(), position.convertTo3Vector());
	}
}
void GameObject::addRelativeForceAtRelativePosition(Vector2 force, Vector2 position)
{
	if (PhysicsEnabled)
	{
		rigidBody->addRelativeForceAtRelativePosition(force.convertTo3Vector(), position.convertTo3Vector());
	}
}

void GameObject::setForce(Vector2 force)
{
	if (PhysicsEnabled)
	{
		rigidBody->setForce(force.convertTo3Vector());
	}
}
Vector2 GameObject::getForce(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getForce().convertTo2Vector();
	}

	return temp;
}
void GameObject::setTorque(Vector2 torque)
{
	if (PhysicsEnabled)
	{
		rigidBody->setTorque(torque.convertTo3Vector());
	}
}
Vector2 GameObject::getTorque(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getTorque().convertTo2Vector();
	}

	return temp;
}

void GameObject::setDynamic(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->setDynamic();
	}
}
void GameObject::setKinematic(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->setKinematic();
	}
}
bool GameObject::isDynamic(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->isDynamic();
	}

	return false;
}
bool GameObject::isKinematic(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->isKinematic();
	}

	return false;
}

Vector2 GameObject::getRelativePointPosition(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getRelativePointPosition(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}
Vector2 GameObject::getRelativePointVelocity(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getRelativePointVelocity(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}
Vector2 GameObject::getPointVelocity(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getPointVelocity(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}

Vector2 GameObject::getPositionRelativePoint(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getPositionRelativePoint(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}

Vector2 GameObject::getVectorToWorld(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getVectorToWorld(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}
Vector2 GameObject::getVectorFromWorld(Vector2 point)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getVectorFromWorld(point.convertTo3Vector()).convertTo2Vector();
	}

	return temp;
}

void GameObject::enableBody(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->enableBody();
	}
}
void GameObject::disableBody(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->disableBody();
	}
}
bool GameObject::isEnabled(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->isEnabled();
	}

	return false;
}

void GameObject::setAutoDisable(bool flag)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisable(flag);
	}
}
bool GameObject::getAutoDisable(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisable();
	}

	return false;
}

void GameObject::setAutoDisableLinearThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableLinearThreshold(threshold);
	}
}
double GameObject::getAutoDisableLinearThreshold(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisableLinearThreshold();
	}

	return -1;
}

void GameObject::setAutoDisableAngularThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableAngularThreshold(threshold);
	}
}
double GameObject::getAutoDisableAngularThreshold(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisableAngularThreshold();
	}

	return -1;
}

void GameObject::setAutoDisableSteps(int steps)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableSteps(steps);
	}
}
int GameObject::getAutoDisableSteps(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisableSteps();
	}

	return -1;
}

void GameObject::setAutoDisableTime(double time)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableTime(time);
	}
}
double GameObject::getAutoDisableTime(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisableTime();
	}

	return -1;
}

void GameObject::setAutoDisableAverageSamplesCount(unsigned int averageSamples)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableAverageSamplesCount(averageSamples);
	}
}
int GameObject::getAutoDisableAverageSamplesCount(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAutoDisableAverageSamplesCount();
	}

	return -1;
}

void GameObject::setAutoDisableDefaults(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAutoDisableDefaults();
	}
}

void GameObject::setMovedCallback(void(*callback))
{
	if (PhysicsEnabled)
	{
		rigidBody->setMovedCallback(callback);
	}
}

void GameObject::setLinearDamping(double scale)
{
	if (PhysicsEnabled)
	{
		rigidBody->setLinearDamping(scale);
	}
}
double GameObject::getLinearDamping(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getLinearDamping();
	}

	return -1;
}

void GameObject::setAngularDamping(double scale)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAngularDamping(scale);
	}
}
double GameObject::getAngularDamping(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAngularDamping();
	}

	return -1;
}

void GameObject::setDamping(double linearScale, double angularScale)
{
	if (PhysicsEnabled)
	{
		rigidBody->setDamping(linearScale, angularScale);
	}
}

void GameObject::setLinearDampingThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		rigidBody->setLinearDampingThreshold(threshold);
	}
}
double GameObject::getLinearDampingThreshold(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getLinearDampingThreshold();
	}

	return -1;
}

void GameObject::setAngularDampingThreshold(double threshold)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAngularDampingThreshold(threshold);
	}
}
double GameObject::getAngularDampingThreshold(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getAngularDampingThreshold();
	}

	return -1;
}

void GameObject::setDampingDefaults(void)
{
	if (PhysicsEnabled)
	{
		rigidBody->setDampingDefaults();
	}
}

double GameObject::getMaxAngularSpeed(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getMaxAngularSpeed();
	}

	return -1;
}
void GameObject::setMaxAngularSpeed(double maxSpeed)
{
	if (PhysicsEnabled)
	{
		rigidBody->setMaxAngularSpeed(maxSpeed);
	}
}

void GameObject::setData(void* data)
{
	if (PhysicsEnabled)
	{
		rigidBody->setData(data);
	}
}
void* GameObject::getData(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getData();
	}
}

void GameObject::setFiniteRotationMode(bool flag)
{
	if (PhysicsEnabled)
	{
		rigidBody->setFiniteRotationMode(flag);
	}
}
bool GameObject::getFiniteRotationMode(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getFiniteRotationMode();
	}

	return false;
}

void GameObject::setFiniteRotationAxis(Vector2 axis)
{
	if (PhysicsEnabled)
	{
		rigidBody->setFiniteRotationAxis(axis.convertTo3Vector());
	}
}
Vector2 GameObject::getFiniteRotationAxis(void)
{
	Vector2 temp(0, 0);

	if (PhysicsEnabled)
	{
		return rigidBody->getFiniteRotationAxis().convertTo2Vector();
	}

	return temp;
}

int GameObject::getNumberOfJoints(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->getNumberOfJoints();
	}

	return -1;
}

void GameObject::setAffectedByGravity(bool flag)
{
	if (PhysicsEnabled)
	{
		rigidBody->setAffectedByGravity(flag);
	}
}
bool GameObject::isAffectedByGravity(void)
{
	if (PhysicsEnabled)
	{
		return rigidBody->isAffectedByGravity();
	}

	return false;
}

dWorldID GameObject::getWorldID(void)
{
	return rigidBody->getWorldID();
}



/*



.=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.
|                     ______                     |
|                  .-"      "-.                  |
|                 /            \                 |
|     _          |              |          _     |
|    ( \         |,  .-.  .-.  ,|         / )    |
|     > "=._     | )(__/  \__)( |     _.=" <     |
|    (_/"=._"=._ |/     /\     \| _.="_.="\_)    |
|           "=._"(_     ^^     _)"_.="           |
|               "=\__|IIIIII|__/="               |
|              _.="| \IIIIII/ |"=._              |
|    _     _.="_.="\          /"=._"=._     _    |
|   ( \_.="_.="     `--------`     "=._"=._/ )   |
|    > _.="                            "=._ <    |
|   (_/                                    \_)   |
|           jgs                                  |
'-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-='


          BE WARY YE WHO TREAD BELOW
      THAR BE CONSTRUCTORS IN THESE WATERS

All numerica values set to 1 by default, make new Constructor if needed
Position values set to 0 for an Origin Point,
Name and type
GameObject and unspecified
*/





//For all constructors we should discuss default states...
GameObject::GameObject(int id) {
	Name = "GameObject";
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;

	ID = id;
}


//Name constructor
GameObject::GameObject(int id, string strN) {
	Name = strN;
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;

	ID = id;
}
//Name and Type Constructor
GameObject::GameObject(int id, string strN, string strT) {
	Name = strN;
	Type = strT;
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;

	ID = id;
}

GameObject::GameObject(int id, string strN, string strT, double XPos, double YPos) {
	Name = strN;
	Type = strT;
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = XPos;
	Position.Y = YPos;

	ID = id;
}

GameObject::GameObject(int id, string strN, double XPos, double YPos) {
	Name = strN;
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = XPos;
	Position.Y = YPos;

	ID = id;
}

GameObject::GameObject(int id, string strN, double xPos, double yPos, int physics, int graphics, prototype::maths::vec4 ocolor, prototype::maths::vec2 osize) {
	ID = id;
	Name = strN;
	//SetPosX(xPos);
	//SetPosY(yPos);
	Position.X = xPos;
	Position.Y = yPos;
	Dynamic = physics;
	Visible = graphics;
	color = ocolor;
	size = osize;
	

}


#endif