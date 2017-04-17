
#include "Quaternion.h"

Quaternion::Quaternion(void) : Vector3()
{
	this->real = 0;

}

Quaternion::Quaternion(dReal real) : Vector3()
{
	this->real = 0;
}

Quaternion::Quaternion(dReal real, Vector3 vector) : Vector3(vector)
{
	this->real = real;
}

Quaternion::Quaternion(dReal real, dReal x, dReal y, dReal z) : Vector3(x, y, z)
{
	this->real = real;
}

Quaternion::Quaternion(Vector3 vector) : Vector3(vector)
{
	this->real = 0;
}

Quaternion::Quaternion(dReal x, dReal y, dReal z) : Vector3(x, y, z)
{
	this->real = 0;
}

Quaternion::~Quaternion(void)
{

}

dReal Quaternion::getRealPart(void)
{
	return this->real;
}

void Quaternion::setRealPart(dReal real)
{
	this->real = real;
}

dReal* Quaternion::convertToDQuaternion(void)
{
	dQuaternion result;

	result[0] = this->real;
	result[1] = this->getX();
	result[2] = this->getY();
	result[3] = this->getZ();

	return result;
}