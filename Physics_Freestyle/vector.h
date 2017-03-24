#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include <ode\ode.h>

class Vector3
{
	private:
		dReal x;
		dReal y;
		dReal z;
	
	public:
		Vector3(void);
		Vector3(const dReal* vector);
		Vector3(dReal x, dReal y, dReal z);
		~Vector3(void);

		void setValues(dReal x, dReal y, dReal z);
		void copyVector3(Vector3 vector);
		void setX(dReal x);
		void setY(dReal y);
		void setZ(dReal z);

		dReal getX(void);
		dReal getY(void);
		dReal getZ(void);

		dReal getMagnitude(void);

		dReal* convertToDVector(void);

		Vector3 operator +(Vector3);
		Vector3 operator -(Vector3);
		bool operator <(Vector3);
		bool operator >(Vector3);
		bool operator ==(Vector3);
		bool operator !=(Vector3);
		bool operator <=(Vector3);
		bool operator >=(Vector3);

};

#endif