#pragma once

#ifndef BODY_H
#define BODY_H

#include <ode\ode.h>
#include "vector.h"
#include "Matrix3.h"
#include "Quaternion.h"


enum Shape
{
	Sphere, Capsule, Cylinder, Box, Plane, Trimesh
};

class Body
{ 

	class Mass
	{
		private:
			dMass massStruct;

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

			
			//Trimesh shit I need to do

			//void adjustMass(dReal newMass);
			//void translateMass(Vector3 displaceVector);
			//void rotateMass(Matrix3 rotationMatrix);
			//void addMass(Mass otherMass);

	};

	private:
		dBodyID bodyID;
		dWorldID worldID;
		Mass* mass;
		dGeomID geomID;
		dSpaceID spaceID;
		Shape shape;

	public:
		Body(dWorldID worldID, dSpaceID spaceID);
		~Body(void);

		dBodyID getBodyID(void);

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

		Shape getShape(void);

		void createSphere(dReal radius);
		void setSphereRadius(dReal radius);
		dReal getSphereRadius(void);
		bool checkIfPointIsInSphere(dReal x, dReal y, dReal z);
		bool checkIfPointIsOnSphere(dReal x, dReal y, dReal z);
		bool checkIfPointIsOutOfSphere(dReal x, dReal y, dReal z);

		void createBox(dReal lengthX, dReal lengthY, dReal lengthZ);
		void setBoxLengths(dReal lengthX, dReal lengthY, dReal lengthZ);
		Vector3 getBoxLengths(void);
		bool checkIfPointIsInBox(dReal x, dReal y, dReal z);
		bool checkIfPointIsOnBox(dReal x, dReal y, dReal z);
		bool checkIfPointIsOutOfBox(dReal x, dReal y, dReal z);

		void createPlane(dReal a, dReal b, dReal c, dReal d);
		void setPlaneParams(dReal a, dReal b, dReal c, dReal d);
		Vector3 getPlaneNormalVector(void);
		dReal getPlaneDParam(void);
		bool checkIfPointIsInPlane(dReal x, dReal y, dReal z);
		bool checkIfPointIsOnPlane(dReal x, dReal y, dReal z);
		bool checkIfPointIsOutOfPlane(dReal x, dReal y, dReal z);

		void createCapsule(dReal radius, dReal length);
		void setCapsuleParams(dReal radius, dReal length);
		dReal getCapsuleRadius(void);
		dReal getCapsuleLength(void);
		bool checkIfPointIsInCapsule(dReal x, dReal y, dReal z);
		bool checkIfPointIsOnCapsule(dReal x, dReal y, dReal z);
		bool checkIfPointIsOutOfCapsule(dReal x, dReal y, dReal z);

		void createCylinder(dReal radius, dReal length);
		void setCylinderParams(dReal radius, dReal length);
		dReal getCylinderRadius(void);
		dReal getCylinderLength(void);
		bool checkIfPointIsInCylinder(dReal x, dReal y, dReal z);
		bool checkIfPointIsOnCylinder(dReal x, dReal y, dReal z);
		bool checkIfPointIsOutOfCylinder(dReal x, dReal y, dReal z);

		dWorldID getWorldID(void);

		
};


#endif