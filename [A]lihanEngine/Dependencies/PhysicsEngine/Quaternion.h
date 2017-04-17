#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include "vector.h"

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
