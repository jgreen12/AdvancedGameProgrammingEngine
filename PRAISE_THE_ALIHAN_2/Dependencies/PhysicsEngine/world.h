#pragma once


#ifndef WORLD_H
#define WORLD_H

#include <ode/ode.h>
#include "vector.h"
#include "Space.h"

class World
{
	private:
		dWorldID worldID;
		Space* space;
		dJointGroupID groupID;
		dNearCallback* x;

		


	public:
			World(void);
			~World(void);
			
			dWorldID getWorldID(void);
			dSpaceID getSpaceID(void);

		void set3DGravity(dReal x, dReal y, dReal z);
		void set3DGravity(Vector3 vector);
		//void set2DGravity(dReal x, dReal y);
		Vector3 getGravity(void);

		void setAutoDisableBodies(bool flag);
		void setAutoDisableLinearThreshold(dReal linearThreshold);
		void setAutoDisableAngularThreshold(dReal angularThreshold);
		void setAutoDisableSteps(int steps);
		void setAutoDisableTime(dReal time);

		Vector3 convertImpulseToForce(dReal stepSize, Vector3 impulse);

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

		void physicsStateToFile(FILE* file);

		void setBasicCallback(dNearCallback* function);
		void basicCollisionCallback(void*, dGeomID, dGeomID);
		
};


#endif