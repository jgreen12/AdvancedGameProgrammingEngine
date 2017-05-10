#include "world.h"


World::World(void)
{

	//Creates dWorld Object and returns its ID
	this->worldID = dWorldCreate();

	//ERP = Error Reduction Parameter
	//Value between 0 - 1 (default is .2)
	//
	//ERP essentially tries to correct differences in Joints between RigidBodies
	dWorldSetERP(this->worldID, .2);


	//CFM = Constraint Force Mixing
	//Value between (10^-9) - 1 (default is 10^-5)
	//
	//CFM determines world stability
	dWorldSetCFM(this->worldID, .00005);


	//Sets the defaults for Auto-Disable options
	setAutoDisableBodies(false);
	setAutoDisableLinearThreshold(0.01);
	setAutoDisableAngularThreshold(0.01);
	setAutoDisableSteps(10);
	setAutoDisableTime(0);

	this->space = new Space();
	
	
}

World::~World(void)
{
	//Destroys world object
	dWorldDestroy(this->worldID);

	delete this->space;
}

dSpaceID World::getSpaceID(void)
{
	return this->space->getSpaceID();
}

dWorldID World::getWorldID(void)
{
	return this->worldID;
}

void World::set3DGravity(dReal x, dReal y, dReal z)
{
	//Sets the world's gravity vector
	dWorldSetGravity(this->worldID, x, y, z);
}

void World::set3DGravity(Vector3 vector)
{
	dWorldSetGravity(this->worldID, vector.getX(), vector.getY(), vector.getZ());
}

//void World::set2DGravity(dReal x, dReal y)
//{
	//Sets the world's gravity vector
//	dWorldSetGravity(this->worldID, x, y, 0);
//}

Vector3 World::getGravity(void)
{
	dVector3 gravity;
	//Sets the supplied dVector3 as the world's current gravity vector
	dWorldGetGravity(this->worldID, gravity);

	return Vector3(gravity);
}

void World::setAutoDisableBodies(bool flag)
{
	//Sets the flag so that all new bodies created in this world start out as disabled
	dWorldSetAutoDisableFlag(this->worldID, flag);
}

void World::setAutoDisableLinearThreshold(dReal linearThreshold)
{
	//Sets the flag so that all bodies that are inactive and fall under the linear threshold are removed
	dWorldSetAutoDisableLinearThreshold(this->worldID, linearThreshold);
}

void World::setAutoDisableAngularThreshold(dReal angularThreshold)
{
	//Sets the flag so that all bodies that are inactive and fall under the angular threshold are removed
	dWorldSetAutoDisableAngularThreshold(this->worldID, angularThreshold);
}

void World::setAutoDisableSteps(int steps)
{
	//Sets the amount of simulation steps that are passed before a body becomes disabled
	dWorldSetAutoDisableSteps(this->worldID, steps);
}

void World::setAutoDisableTime(dReal time)
{
	//Sets the amount of simulation time that are passed before a body becomes disabled
	dWorldSetAutoDisableTime(this->worldID, time);
}

Vector3 World::convertImpulseToForce(dReal stepSize, Vector3 impulse)
{
	dVector3 resultForce;

	//Converts an Impulse Vector to a resulting Force Vector in this particular World
	dWorldImpulseToForce(this->worldID, stepSize, impulse.getX(), impulse.getY(), impulse.getZ(), resultForce);

	return Vector3(resultForce);
}

void World::safeStepWorld(dReal stepSize)
{
	//dWorldStep steps the world, but uses a "big matrix" method which causes less errors, but uses
	//a lot of memory.
	dWorldStep(this->worldID, stepSize);
}

void World::quickStepWorld(dReal stepSize)
{
	//dWorldQuickStep steps the world, but uses a faster method which works better on lower end systems,
	//but also can cause more errors. Some of these errors can be mitigated with ERP and CFM
	dWorldQuickStep(this->worldID, stepSize);
}

void World::setQuickStepNumberIterations(int number)
{
	//Sets the number of iterations performed per step (default is 20)
	dWorldSetQuickStepNumIterations(this->worldID, number);
}

void World::setQuickStepOverRelaxation(int overRelaxation)
{
	//Sets the Over Relaxation parameter from QuickStep's SOR algorithim (default is 1.3)
	dWorldSetQuickStepW(this->worldID, overRelaxation);
}

void World::setLinearDamping(dReal scale)
{
	//Sets the Linear Damping of the world (default is 0)
	dWorldSetLinearDamping(this->worldID, scale);
}

void World::setAngularDamping(dReal scale)
{
	//Sets the Angular Damping of the world (default is 0)
	dWorldSetAngularDamping(this->worldID, scale);
}

void World::setLinearDampingThreshold(dReal threshold)
{
	//Sets the Linear Damping Threshold (default is 0.01)
	dWorldSetLinearDampingThreshold(this->worldID, threshold);
}

void World::setAngularDampingThreshold(dReal threshold)
{
	//Sets the Angular Damping Threshold (default is 0.01)
	dWorldSetAngularDampingThreshold(this->worldID, threshold);
}

void World::setMaxAngularSpeed(dReal maxSpeed)
{
	//Sets the default maximum angular speed for new bodies (default is 0.01)
	dWorldSetMaxAngularSpeed(this->worldID, maxSpeed);
}

void World::setContactMaxCorrectingVelocity(dReal velocity)
{
	//Sets the maximum correcting velocity that bodies making contact
	//are allowed to generate (default is infinity [dInfinity])
	dWorldSetContactMaxCorrectingVel(this->worldID, velocity);
}

void World::setContactSurfaceLayer(dReal depth)
{
	//Sets the depth of the surface layer around all objects (default is 0)
	dWorldSetContactSurfaceLayer(this->worldID, depth);
}

void World::physicsStateToFile(FILE * file)
{
	dWorldExportDIF(this->worldID, file, "test");
}
