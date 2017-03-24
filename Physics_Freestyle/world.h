#pragma once


#ifndef WORLD_H
#define WORLD_H

#include <ode/ode.h>
#include "vector.h"

class World
{
	private:
		dWorldID worldID;


	public:
			World(void);
			~World(void);

			dWorldID getWorldID(void);

		void set3DGravity(dReal x, dReal y, dReal z);
		void set3DGravity(Vector3 vector);
		//void set2DGravity(dReal x, dReal y);
		void getGravity(Vector3 gravity);

		void setAutoDisableBodies(bool flag);
		void setAutoDisableLinearThreshold(dReal linearThreshold);
		void setAutoDisableAngularThreshold(dReal angularThreshold);
		void setAutoDisableSteps(int steps);
		void setAutoDisableTime(dReal time);

		void convertImpulseToForce(dReal stepSize, dReal iX, dReal iY, dReal iZ, Vector3 force);

		void safeStepWorld(dReal stepSize);
		void quickStepWorld(dReal stepSize);

		void setQuickStepNumberIterations(int num);
		void setQuickStepOverRelaxation(int overRelaxation);

		void setLinearDamping(dReal scale);
		void setAngularDamping(dReal scale);

		void setLinearDampingThreshold(dReal threshold);
		void setAngularDampingThreshold(dReal threshold);

		void setMaxAngularSpeed(dReal maxSpeed);

		void setContactMaxCorrectingVelocity(dReal velocity);

		void setContactSurfaceLayer(dReal depth);

		
};


#endif