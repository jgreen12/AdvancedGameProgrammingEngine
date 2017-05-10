
#include "Space.h"

Space::Space(void)
{
	//this->id = dSimpleSpaceCreate(this->id);

	this->space = new dHashSpace();



	//this->space = new dSimpleSpace();
}

Space::~Space(void)
{
	delete space;
	//dSpaceDestroy(this->id);
}

dSpaceID Space::getSpaceID(void)
{
	//return this->id;
	dSpaceID dafuq;

	dafuq = this->space->getSpace();
	return dafuq;
}