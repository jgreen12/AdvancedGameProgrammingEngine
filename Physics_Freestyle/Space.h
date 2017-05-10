#pragma once

#ifndef SPACE_H
#define SPACE_H

#include <ode/ode.h>

class Space
{
	private:
		//dSpaceID id;
		dHashSpace* space;


	public:
		Space(void);
		~Space(void);

		dSpaceID getSpaceID(void);

};

#endif