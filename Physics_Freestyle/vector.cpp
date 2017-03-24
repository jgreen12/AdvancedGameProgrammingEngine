#include "vector.h"

Vector3::Vector3(void)
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(dReal x, dReal y, dReal z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(const dReal* vector)
{
	try
	{
		this->x = vector[0];
		this->y = vector[1];
		this->z = vector[2];
	}
	catch (int exception)
	{
		Vector3();
	}
}

Vector3::~Vector3(void)
{

}

void Vector3::setValues(dReal x, dReal y, dReal z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::copyVector3(Vector3 vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

void Vector3::setX(dReal x)
{
	this->x = x;
}

void Vector3::setY(dReal y)
{
	this->y = y;
}

void Vector3::setZ(dReal z)
{
	this->z = z;
}

dReal Vector3::getMagnitude(void)
{
	return sqrt((x * x) + (y * y) + (z * z));
}

dReal Vector3::getX(void)
{
	return this->x;
}

dReal Vector3::getY(void)
{
	return this->y;
}

dReal Vector3::getZ(void)
{
	return this->z;
}

dReal* Vector3::convertToDVector(void)
{
	dVector3 result;

	result[0] = this->x;
	result[1] = this->y;
	result[2] = this->z;
	result[3] = 0;

	return result;
}

Vector3 Vector3::operator+(Vector3 that)
{
	Vector3 result;

	result.setX(this->x + that.x);
	result.setY(this->y + that.y);
	result.setZ(this->z + that.z);

	return result;
}

Vector3 Vector3::operator-(Vector3 that)
{
	Vector3 result;

	result.setX(this->x - that.x);
	result.setY(this->y - that.y);
	result.setZ(this->z - that.z);

	return result;
}

bool Vector3::operator<(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult < thatResult);
}

bool Vector3::operator>(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult > thatResult);
}

bool Vector3::operator<=(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult <= thatResult);
}

bool Vector3::operator>=(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult >= thatResult);
}

bool Vector3::operator==(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult == thatResult);
}

bool Vector3::operator!=(Vector3 that)
{
	dReal thatResult = that.getMagnitude();
	dReal thisResult = this->getMagnitude();

	return (thisResult != thatResult);
}