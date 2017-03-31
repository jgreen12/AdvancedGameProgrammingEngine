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


class Vector2
{
private:
	dReal x;
	dReal y;

public:
	Vector2(void);
	Vector2(const dReal* vector);
	Vector2(dReal x, dReal y);
	~Vector2(void);

	void setValues(dReal x, dReal y);
	void copyVector2(Vector2 vector);
	void setX(dReal x);
	void setY(dReal y);

	dReal getX(void);
	dReal getY(void);

	dReal getMagnitude(void);

	dReal* convertToDVector(void);


	Vector2 operator +(Vector2);
	Vector2 operator -(Vector2);
	bool operator <(Vector2);
	bool operator >(Vector2);
	bool operator ==(Vector2);
	bool operator !=(Vector2);
	bool operator <=(Vector2);
	bool operator >=(Vector2);
};

#endif