#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector.h"
/********************************************
Author: Noah Pena
Quaternion.h
Header file for creating a quaternion variable,
either with dReal, dReal and vector3, four
dReal variables, a single vector3, or dReal x,y,z.
********************************************/

class Quaternion : public Vector3
{
	private:
		dReal real;

	public:
		Quaternion(void);
		Quaternion(dReal real);
		Quaternion(dReal real, Vector3 vector);
		Quaternion(dReal real, dReal x, dReal y, dReal z);
		Quaternion(Vector3 vector);
		Quaternion(dReal x, dReal y, dReal z);
		~Quaternion(void);

		dReal getRealPart(void);
		void setRealPart(dReal real);

		dReal* convertToDQuaternion(void);
};

#endif // !QUATERNION_H
