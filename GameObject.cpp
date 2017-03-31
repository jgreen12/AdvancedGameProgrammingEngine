//Comment any functions or changes to function you make so that we can keep track of who did the additions, BitBucket does this, but Alihan won't know without the comments.

//Created by: Joshua Green
//Collaboration with: 
#include <string>
#include <vector>

//Physics Headers
#include "vector.h"
#include "body.h"
#include "world.h"

#include <ode/ode.h>

using namespace std;

//GameObject class to keep track of game objects, may need to make the class abstract?




class GameObject {
private:
	
	Body* rigidBody;

protected:
	//rudimentary method of tracking position until we link up on physics
	struct Position {
		double X;
		double Y;
		//add a vector in here maybe? Talk to Noah
	};

	Position Position;
	__int8 Active; //is the object active in a scene? This could be used to turn something off when off screen, but turn it on when in range. 1 for yes 0 for no
	__int8 Dynamic; //uses dynamic physics? 1 for yes 0 for no, could introduce another state like 2 for something that doesn't use physics at all, but is placed in the scene.
	__int8 Visible; //is rendered? 1 for yes 0 for no, could introduce another state for hack magic <- joke

	string Name; //name of the object
	string Type; //a tag of the object, could be used to find all objects of a certain type, and apply an effect dynamically or something

public:


	GameObject(); //the constructors that follow should be self explanatory. 
	GameObject(string strN); //strN for the Name of the object
	GameObject(string strN, string strT);	//strT for the Tag
	GameObject(string strN, string strT, double XPos, double YPos); //name tag and start coords
	GameObject(string strN, double XPos, double YPos);//name and start coords
	//we can add more constructors as needed. 
	~GameObject();

	double GetPosX();
    double GetPosY();
	void SetPosX(double newX);
	void SetPosY(double newY);

	string GetName();
	string GetType();
	void SetName(string newName);
	void SetType(string newType);

	__int8 GetActive();
	__int8 GetDynamic();
	__int8 GetVisible();
	void SetActive(__int8 newAct);
	void SetDynamic(__int8 newDyna);
	void SetVisible(__int8 newVisi);

	float RenderPassX();
	float RenderPassY();

	//Physics Stuff
	void RegisterAsRigidBody(World world);
	void DeRegisterAsRigidBody(void);

	void setMass(double mass);
	double getMass(void);

	void rotateX(double rotate);
	void rotateY(double rotate);
	double getRotateX(void);
	double getRotateY(void);

	void setLinearVelocity(double vx, double vy);
	void setLinearVelocityX(double vx);
	void setLinearVelocityY(double vy);
	double getLinearVelocityX(void);
	double getLinearVelocityY(void);

	void setAngularVelocity(double vx, double vy);
	void setAngularVelocityX(double vx);
	void setAngularVelocityY(double vy);
	double getAngularVelocityX(void);
	double getAngularVelocityY(void);

	void setCenterOfGravity(double gx, double gy);
	void setCenterOfGravityX(double gx);
	void setCenterOfGraivtyY(double gy);
	double getCenterOfGravityX(void);
	double getCenterOfGravityY(void);

	void addForce(double fx, double fy);
	void addTorque(double tx, double ty);
	void addRelativeForce(double fx, double fy);
	void addRelativeTorque(double tx, double ty);
	void addForceAtPosition(double fx, double fy, double x, double y);
	
	



};



float GameObject::RenderPassX() {
	float x = Position.X;
	return 	x;
}
float GameObject::RenderPassY() {
	float y = Position.Y;
	return y;
}





__int8 GameObject::GetActive() {
	return Active;
}
__int8 GameObject::GetDynamic() {
	return Dynamic;
}
__int8 GameObject::GetVisible() {
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
	return Position.X;
}
double GameObject::GetPosY() {
	return Position.Y;
}
void GameObject::SetPosX(double newX) {
	Position.X = newX;
}
void GameObject::SetPosY(double newY) {
	Position.Y = newY;
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
GameObject::GameObject() {
	Name = "GameObject";
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;
}


//Name constructor
GameObject::GameObject(string strN) {
	Name = strN;
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;
}
//Name and Type Constructor
GameObject::GameObject(string strN, string strT) {
	Name = strN;
	Type = strT;
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = 0;
	Position.Y = 0;
}

GameObject::GameObject(string strN, string strT, double XPos, double YPos) {
	Name = strN;
	Type = strT;
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = XPos;
	Position.Y = YPos;
}

GameObject::GameObject(string strN, double XPos, double YPos) {
	Name = strN;
	Type = "unspecified";
	Active = 1;
	Dynamic = 1;
	Visible = 1;

	Position.X = XPos;
	Position.Y = YPos;
}