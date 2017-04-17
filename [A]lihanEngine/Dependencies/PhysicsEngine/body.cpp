#include "body.h"


Body::Mass::Mass(void)
{
	dMassSetZero(&this->massStruct);
}

Body::Mass::Mass(const dMass mass)
{
	this->massStruct = mass;
}

Body::Mass::~Mass(void)
{

}

void Body::Mass::setMass(dReal mass)
{
	dMassSetParameters(&this->massStruct, mass, this->massStruct.c[0], this->massStruct.c[1], this->massStruct.c[2], this->massStruct.I[0], this->massStruct.I[5], this->massStruct.I[10], this->massStruct.I[4], this->massStruct.I[8], this->massStruct.I[9]);
}

dReal Body::Mass::getMass(void)
{
	return this->massStruct.mass;
}

void Body::Mass::setCenterOfGravity(Vector3 vector)
{
	dMassSetParameters(&this->massStruct, this->massStruct.mass, vector.getX(), vector.getY(), vector.getZ(), this->massStruct.I[0], this->massStruct.I[5], this->massStruct.I[10], this->massStruct.I[4], this->massStruct.I[8], this->massStruct.I[9]);
}

Vector3 Body::Mass::getCenterOfGravity(void)
{
	const dReal* eh = this->massStruct.c;

	Vector3 result(eh);

	return result;
}

dReal* Body::Mass::getCenterOfGravityAsDVector(void)
{
	return this->massStruct.c;
}

void Body::Mass::setInertiaTensor(Matrix3 tensor)
{
	dMassSetParameters(&this->massStruct, this->massStruct.mass, this->massStruct.c[0], this->massStruct.c[1], this->massStruct.c[2], tensor.getAtPosition(0, 0), tensor.getAtPosition(1, 1), tensor.getAtPosition(2, 2), tensor.getAtPosition(0, 1), tensor.getAtPosition(0, 2), tensor.getAtPosition(1, 2));
}

Matrix3 Body::Mass::getInertiaTensor(void)
{
	const dReal* eh = this->massStruct.I;

	Matrix3 result(eh);

	return result;
}

dReal* Body::Mass::getInertiaTensorAsDMatrix(void)
{
	return this->massStruct.I;
}

dMass* Body::Mass::getMassStruct(void)
{
	return &this->massStruct;
}

Body::Body(dWorldID worldID)
{
	this->worldID = worldID;

	//Creates a body with default mass parameters
	//at position (0,0,0)
	this->bodyID = dBodyCreate(this->worldID);

	Vector3 basePosition;

	setPosition(basePosition);

}

Body::~Body(void)
{
	//Destroys a body but does not destroy attached joints
	//it leaves the joints in limbo
	dBodyDestroy(this->bodyID);
}


void Body::setPosition(Vector3 vector)
{
	dBodySetPosition(this->bodyID, vector.getX(), vector.getY(), vector.getZ());
}

Vector3 Body::getPosition(void)
{

	const dReal* position = dBodyGetPosition(this->bodyID);

	Vector3 result(position);

	return result;
}

void Body::setRotation(Matrix3 rotation)
{
	dBodySetRotation(this->bodyID, rotation.convertToDMatrix());
}

Matrix3 Body::getRotation(void)
{

	const dReal* rotation = dBodyGetRotation(this->bodyID);

	Matrix3 result(rotation);

	return result;

}

void Body::setQuaternion(Quaternion quaternion)
{
	dBodySetQuaternion(this->bodyID, quaternion.convertToDQuaternion());
}

Quaternion Body::getQuaternion(void)
{
	const dReal* quarternion = dBodyGetQuaternion(this->bodyID);

	Quaternion result(quarternion);

	return result;
}

void Body::setLinearVelocity(Vector3 velocity)
{
	dBodySetLinearVel(this->bodyID, velocity.getX(), velocity.getY(), velocity.getZ());
}

Vector3 Body::getLinearVelocity(void)
{
	const dReal* velocity = dBodyGetLinearVel(this->bodyID);

	Vector3 result(velocity);

	return result;
}

void Body::setAngularVelocity(Vector3 velocity)
{
	dBodySetAngularVel(this->bodyID, velocity.getX(), velocity.getY(), velocity.getZ());
}

Vector3 Body::getAngularVelocity(void)
{
	const dReal* velocity = dBodyGetAngularVel(this->bodyID);

	Vector3 result(velocity);

	return result;
}

void Body::setMass(dReal mass)
{
	this->mass.setMass(mass);
}

dReal Body::getMass(void)
{
	return this->mass.getMass();
}

void Body::setCenterOfGravity(Vector3 center)
{
	this->mass.setCenterOfGravity(center);
}

Vector3 Body::getCenterOfGravity(void)
{
	return this->mass.getCenterOfGravity();
}

void Body::setInertiaTensor(Matrix3 inertaTensor)
{
	this->mass.setInertiaTensor(inertaTensor);
}

Matrix3 Body::getInertiaTensor(void)
{
	return this->mass.getInertiaTensor();
}

void Body::addForce(Vector3 force)
{
	dBodyAddForce(this->bodyID, force.getX(), force.getY(), force.getZ());
}

void Body::addTorque(Vector3 torque)
{
	dBodyAddTorque(this->bodyID, torque.getX(), torque.getY(), torque.getZ());
}

void Body::addRelativeForce(Vector3 force)
{
	dBodyAddRelForce(this->bodyID, force.getX(), force.getY(), force.getZ());
}

void Body::addRelativeTorque(Vector3 torque)
{
	dBodyAddRelTorque(this->bodyID, torque.getX(), torque.getY(), torque.getZ());
}

void Body::addForceAtPosition(Vector3 force, Vector3 position)
{
	dBodyAddForceAtPos(this->bodyID, force.getX(), force.getY(), force.getZ(), position.getX(), position.getY(), position.getZ());
}

void Body::addForceAtRelativePosition(Vector3 force, Vector3 position)
{
	dBodyAddForceAtRelPos(this->bodyID, force.getX(), force.getY(), force.getZ(), position.getX(), position.getY(), position.getZ());
}

void Body::addRelativeForceAtPosition(Vector3 force, Vector3 position)
{
	dBodyAddRelForceAtPos(this->bodyID, force.getX(), force.getY(), force.getZ(), position.getX(), position.getY(), position.getZ());
}

void Body::addRelativeForceAtRelativePosition(Vector3 force, Vector3 position)
{
	dBodyAddRelForceAtRelPos(this->bodyID, force.getX(), force.getY(), force.getZ(), position.getX(), position.getY(), position.getZ());
}

void Body::setForce(Vector3 force)
{
	dBodySetForce(this->bodyID, force.getX(), force.getY(), force.getZ());
}

Vector3 Body::getForce(void)
{
	Vector3 force;
	const dReal* result;

	result = dBodyGetForce(this->bodyID);

	force.setX(result[0]);
	force.setY(result[1]);
	force.setZ(result[2]);

	return force;
}

void Body::setTorque(Vector3 torque)
{
	dBodySetTorque(this->bodyID, torque.getX(), torque.getY(), torque.getZ());
}

Vector3 Body::getTorque(void)
{
	Vector3 torque;
	const dReal* result;

	result = dBodyGetTorque(this->bodyID);

	torque.setX(result[0]);
	torque.setY(result[1]);
	torque.setZ(result[2]);

	return torque;
}

void Body::setDynamic(void)
{
	dBodySetDynamic(this->bodyID);
}

void Body::setKinematic(void)
{
	dBodySetKinematic(this->bodyID);
}

bool Body::isDynamic(void)
{
	return !dBodyIsKinematic(this->bodyID);
}

bool Body::isKinematic(void)
{
	return dBodyIsKinematic(this->bodyID);
}

Vector3 Body::getRelativePointPosition(Vector3 point)
{
	dVector3 result;

	dBodyGetRelPointPos(this->bodyID, point.getX(), point.getY(), point.getY(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

Vector3 Body::getRelativePointVelocity(Vector3 point)
{
	dVector3 result;

	dBodyGetRelPointVel(this->bodyID, point.getX(), point.getY(), point.getZ(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

Vector3 Body::getPointVelocity(Vector3 point)
{
	dVector3 result;

	dBodyGetPointVel(this->bodyID, point.getX(), point.getY(), point.getZ(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

Vector3 Body::getPositionRelativePoint(Vector3 point)
{
	dVector3 result;

	dBodyGetPosRelPoint(this->bodyID, point.getX(), point.getY(), point.getZ(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

Vector3 Body::getVectorToWorld(Vector3 point)
{
	dVector3 result;

	dBodyVectorToWorld(this->bodyID, point.getX(), point.getY(), point.getZ(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

Vector3 Body::getVectorFromWorld(Vector3 point)
{
	dVector3 result;

	dBodyVectorFromWorld(this->bodyID, point.getX(), point.getY(), point.getZ(), result);

	Vector3 resultant(result[0], result[1], result[2]);

	return resultant;
}

void Body::enableBody(void)
{
	dBodyEnable(this->bodyID);
}

void Body::disableBody(void)
{
	dBodyDisable(this->bodyID);
}

bool Body::isEnabled(void)
{
	return (dBodyIsEnabled(this->bodyID) == 1);
}

void Body::setAutoDisable(bool flag)
{
	int temp = (flag) ? 1 : 0;

	dBodySetAutoDisableFlag(this->bodyID, flag);
}

bool Body::getAutoDisable(void)
{
	int temp = dBodyGetAutoDisableFlag(this->bodyID);

	return (temp == 1);
}

void Body::setAutoDisableLinearThreshold(dReal threshold)
{
	dBodySetAutoDisableLinearThreshold(this->bodyID, threshold);
}

dReal Body::getAutoDisableLinearThreshold(void)
{
	return dBodyGetAutoDisableLinearThreshold(this->bodyID);
}

void Body::setAutoDisableAngularThreshold(dReal threshold)
{
	dBodySetAutoDisableAngularThreshold(this->bodyID, threshold);
}

dReal Body::getAutoDisableAngularThreshold(void)
{
	return dBodyGetAutoDisableAngularThreshold(this->bodyID);
}

void Body::setAutoDisableSteps(int steps)
{
	dBodySetAutoDisableSteps(this->bodyID, steps);
}

int Body::getAutoDisableSteps(void)
{
	return dBodyGetAutoDisableSteps(this->bodyID);
}

void Body::setAutoDisableTime(dReal time)
{
	dBodySetAutoDisableTime(this->bodyID, time);
}

dReal Body::getAutoDisableTime(void)
{
	return dBodyGetAutoDisableTime(this->bodyID);
}

void Body::setAutoDisableAverageSamplesCount(unsigned int averageSamples)
{
	dBodySetAutoDisableAverageSamplesCount(this->bodyID, averageSamples);
}

int Body::getAutoDisableAverageSamplesCount(void)
{
	return dBodyGetAutoDisableAverageSamplesCount(this->bodyID);
}

void Body::setAutoDisableDefaults(void)
{
	dBodySetAutoDisableDefaults(this->bodyID);
}

void Body::setMovedCallback(void(*callback))
{
	//TODO
	//dBodySetMovedCallback(this->bodyID, (void*)callback(this->bodyID));
}

void Body::setLinearDamping(dReal scale)
{
	dBodySetLinearDamping(this->bodyID, scale);
}

dReal Body::getLinearDamping(void)
{
	return dBodyGetLinearDamping(this->bodyID);
}

void Body::setAngularDamping(dReal scale)
{
	dBodySetAngularDamping(this->bodyID, scale);
}

dReal Body::getAngularDamping(void)
{
	return dBodyGetAngularDamping(this->bodyID);
}

void Body::setDamping(dReal linearScale, dReal angularScale)
{
	dBodySetDamping(this->bodyID, linearScale, angularScale);
}

void Body::setLinearDampingThreshold(dReal threshold)
{
	dBodySetLinearDampingThreshold(this->bodyID, threshold);
}

dReal Body::getLinearDampingThreshold(void)
{
	return dBodyGetLinearDampingThreshold(this->bodyID);
}

void Body::setAngularDampingThreshold(dReal threshold)
{
	dBodySetAngularDampingThreshold(this->bodyID, threshold);
}

dReal Body::getAngularDampingThreshold(void)
{
	return dBodyGetAngularDampingThreshold(this->bodyID);
}

void Body::setDampingDefaults(void)
{
	dBodySetDampingDefaults(this->bodyID);
}

void Body::setMaxAngularSpeed(dReal maxSpeed)
{
	dBodySetMaxAngularSpeed(this->bodyID, maxSpeed);
}

dReal Body::getMaxAngularSpeed(void)
{
	return dBodyGetMaxAngularSpeed(this->bodyID);
}

void Body::setData(void* data)
{
	dBodySetData(this->bodyID, data);
}

void* Body::getData(void)
{
	return dBodyGetData(this->bodyID);
}

void Body::setFiniteRotationMode(bool flag)
{
	int temp = (!flag) ? 1 : 0;

	dBodySetFiniteRotationMode(this->bodyID, temp);
}

bool Body::getFiniteRotationMode(void)
{
	int temp = dBodyGetFiniteRotationMode(this->bodyID);

	return (temp == 0);
}

void Body::setFiniteRotationAxis(Vector3 axis)
{
	dBodySetFiniteRotationAxis(this->bodyID, axis.getX(), axis.getY(), axis.getZ());
}

Vector3 Body::getFiniteRotationAxis(void)
{
	dReal* temp;

	dBodyGetFiniteRotationAxis(this->bodyID, temp);

	Vector3 result(temp[0], temp[1], temp[2]);

	return result;
}

int Body::getNumberOfJoints(void)
{
	return dBodyGetNumJoints(this->bodyID);
}

dWorldID Body::getWorldID(void)
{
	return dBodyGetWorld(this->bodyID);
}

void Body::setAffectedByGravity(bool flag)
{
	int temp = (flag) ? 1 : 0;

	dBodySetGravityMode(this->bodyID, temp);
}

bool Body::isAffectedByGravity(void)
{
	int temp = dBodyGetGravityMode(this->bodyID);

	return (temp == 1);
}





