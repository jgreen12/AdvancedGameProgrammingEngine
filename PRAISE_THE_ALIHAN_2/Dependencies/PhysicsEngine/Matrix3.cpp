
#include "Matrix3.h"
/********************************************
Author: Noah Pena
Matrix3.cpp 
CPP file for Header file Matrix.h for setting up a matrix, with
positions in rows and column, either with
direct input, cross product, vector multiplication,
with vectors, or with using other matrices.
********************************************/


Matrix3::Matrix3(void)
{
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
	this->data[3] = 0;
	this->data[4] = 0;
	this->data[5] = 0;
	this->data[6] = 0;
	this->data[7] = 0;
	this->data[8] = 0;
}

Matrix3::Matrix3(const dReal* matrix)
{
	try
	{
		this->data[0] = matrix[0];
		this->data[1] = matrix[1];
		this->data[2] = matrix[2];
		this->data[3] = matrix[4];
		this->data[4] = matrix[5];
		this->data[5] = matrix[6];
		this->data[6] = matrix[8];
		this->data[7] = matrix[9];
		this->data[8] = matrix[10];
	}
	catch (int exception)
	{
		Matrix3();
	}
}


Matrix3::~Matrix3()
{

}

void Matrix3::setAtPosition(int row, int column, dReal data)
{
	this->data[row * 3 + column] = data;
}

dReal Matrix3::getAtPosition(int row, int column)
{
	return this->data[row * 3 + column];
}

void Matrix3::setRow(int row, Vector3 data)
{
	this->data[row * 3] = data.getX();
	this->data[row * 3 + 1] = data.getY();
	this->data[row * 3 + 2] = data.getZ();
}

void Matrix3::setRow(int row, dReal x, dReal y, dReal z)
{
	this->data[row * 3] = x;
	this->data[row * 3 + 1] = y;
	this->data[row * 3 + 2] = z;
}

Vector3 Matrix3::getRowAsVector(int row)
{
	Vector3 result;

	result.setX(this->data[row * 3]);
	result.setY(this->data[row * 3 + 1]);
	result.setZ(this->data[row * 3 + 2]);

	return result;
}

dReal* Matrix3::getRowAsArray(int row)
{
	dReal result[3];

	result[0] = this->data[row * 3];
	result[1] = this->data[row * 3 + 1];
	result[2] = this->data[row * 3 + 2];

	return result;
}

dReal* Matrix3::convertToDMatrix(void)
{
	dMatrix3 result;

	result[0] = this->data[0];
	result[1] = this->data[1];
	result[2] = this->data[2];
	result[3] = 0;
	result[4] = this->data[3];
	result[5] = this->data[4];
	result[6] = this->data[5];
	result[7] = 0;
	result[8] = this->data[6];
	result[9] = this->data[7];
	result[10] = this->data[8];
	result[11] = 0;

	return result;
}