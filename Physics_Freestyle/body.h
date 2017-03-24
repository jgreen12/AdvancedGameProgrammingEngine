#pragma once

#ifndef BODY_H
#define BODY_H

#include <ode\ode.h>
#include "vector.h"
#include "Matrix3.h"
#include "Quaternion.h"

enum Axis
{
	X_Axis, Y_Axis, Z_Axis
};

enum Shape
{
	Sphere, Capsule, Cylinder, Box, Trimesh, None
};

class Body
{ 

	class Mass
	{
		private:
			dMass massStruct;
			Shape shape;

		public:

			Mass(void);
			Mass(const dMass mass);
			~Mass(void);

			void setMass(dReal mass);
			dReal getMass(void);
			
			void setCenterOfGravity(Vector3 newCenter);
			Vector3 getCenterOfGravity(void);
			dReal* getCenterOfGravityAsDVector(void);

			void setInertiaTensor(Matrix3 newTensor);
			Matrix3 getInertiaTensor(void);
			dReal* getInertiaTensorAsDMatrix(void);

			dMass* getMassStruct(void);

			void setAsSphere(dReal density, dReal radius);
			void setAsSphereTotal(dReal totalMass, dReal radius);

			void setAsCapsule(dReal density, Axis axis, dReal radius, dReal length);
			void setAsCapsuleTotal(dReal totalMass, Axis axis, dReal radius, dReal length);

			void setAsCylinder(dReal density, Axis axis, dReal radius, dReal length);
			void setAsCylinderTotal(dReal totalMass, Axis axis, dReal radius, dReal length);

			void setAsBox(dReal density, dReal lengthAcrossX, dReal lengthAcrossY, dReal lengthAcrossZ);
			void setAsBoxTotal(dReal totalMass, dReal lengthAcrossX, dReal lengthAcrossY, dReal lengthAcrossZ);

			//Trimesh shit I need to do

			void adjustMass(dReal newMass);
			void translateMass(Vector3 displaceVector);
			void rotateMass(Matrix3 rotationMatrix);
			void addMass(Mass otherMass);

	};

	private:
		dBodyID bodyID;
		dWorldID worldID;
		Mass mass;

	public:
		Body(dWorldID worldID);
		~Body(void);

		void setPosition(Vector3 vector);
		Vector3 getPosition(void);

		void setRotation(Matrix3 rotation);
		Matrix3 getRotation(void);

		void setQuaternion(Quaternion quaternion);
		Quaternion getQuaternion(void);

		void setLinearVelocity(Vector3 velocity);
		Vector3 getLinearVelocity(void);

		void setAngularVelocity(Vector3 velocity);
		Vector3 getAngularVelocity(void);

		void setMass(dReal mass);
		dReal getMass(void);

		void setCenterOfGravity(Vector3 center);
		Vector3 getCenterOfGravity(void);

		void setInertiaTensor(Matrix3 inertaTensor);
		Matrix3 getInertiaTensor(void);

		void addForce(Vector3 force);
		void addTorque(Vector3 torque);
		void addRelativeForce(Vector3 force);
		void addRelativeTorque(Vector3 torque);
		void addForceAtPosition(Vector3 force, Vector3 position);
		void addForceAtRelativePosition(Vector3 force, Vector3 position);
		void addRelativeForceAtPosition(Vector3 force, Vector3 position);
		void addRelativeForceAtRelativePosition(Vector3 force, Vector3 position);

		void setForce(Vector3 force);
		Vector3 getForce(void);
		void setTorque(Vector3 torque);
		Vector3 getTorque(void);

		void setDynamic(void);
		void setKinematic(void);
		bool isDynamic(void);
		bool isKinematic(void);

		Vector3 getRelativePointPosition(Vector3 point);
		Vector3 getRelativePointVelocity(Vector3 point);
		Vector3 getPointVelocity(Vector3 point);

		Vector3 getPositionRelativePoint(Vector3 point);

		Vector3 getVectorToWorld(Vector3 point);
		Vector3 getVectorFromWorld(Vector3 point);

		void enableBody(void);
		void disableBody(void);
		bool isEnabled(void);

		void setAutoDisable(bool flag);
		bool getAutoDisable(void);

		void setAutoDisableLinearThreshold(dReal threshold);
		dReal getAutoDisableLinearThreshold(void);

		void setAutoDisableAngularThreshold(dReal threshold);
		dReal getAutoDisableAngularThreshold(void);

		void setAutoDisableSteps(int steps);
		int getAutoDisableSteps(void);

		void setAutoDisableTime(dReal time);
		dReal getAutoDisableTime(void);

		void setAutoDisableAverageSamplesCount(unsigned int averageSamples);
		int getAutoDisableAverageSamplesCount(void);

		void setAutoDisableDefaults(void);

		void setMovedCallback(void(*callback));

		void setLinearDamping(dReal scale);
		dReal getLinearDamping(void);

		void setAngularDamping(dReal scale);
		dReal getAngularDamping(void);

		void setDamping(dReal linearScale, dReal angularScale);

		void setLinearDampingThreshold(dReal threshold);
		dReal getLinearDampingThreshold(void);

		void setAngularDampingThreshold(dReal threshold);
		dReal getAngularDampingThreshold(void);

		void setDampingDefaults(void);

		dReal getMaxAngularSpeed(void);
		void setMaxAngularSpeed(dReal maxSpeed);

		void setData(void* data);
		void* getData(void);

		void setFiniteRotationMode(bool flag);
		bool getFiniteRotationMode(void);

		void setFiniteRotationAxis(Vector3 axis);
		Vector3 getFiniteRotationAxis(void);

		int getNumberOfJoints(void);
		//Joint crap I haven't done yet

		void setAffectedByGravity(bool flag);
		bool isAffectedByGravity(void);

		//Geom crap I haven't done yet

		dWorldID getWorldID(void);

		
};


#endif