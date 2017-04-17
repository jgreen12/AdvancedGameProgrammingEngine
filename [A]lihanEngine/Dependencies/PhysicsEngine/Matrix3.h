#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <ode/ode.h>
#include "vector.h"

class Matrix3
{
	private:
		dReal data[9];

	public:
		Matrix3();
		Matrix3(const dReal* matrix);
		~Matrix3();

		void setAtPosition(int row, int column, dReal data);
		dReal getAtPosition(int row, int column);

		void setRow(int row, Vector3 vector);
		void setRow(int row, dReal x, dReal y, dReal z);
		dReal* getRowAsArray(int row);
		Vector3 getRowAsVector(int row);

		dReal* convertToDMatrix(void);
};


#endif