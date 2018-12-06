#pragma once
#include <vector>
#include "../Components/PhysicsComponent.h"

namespace TomFrame
{
	class WorldObject;

	class PhysicsManager
	{
	public:
		PhysicsManager();
		~PhysicsManager();

		/*Registers an object to the physicsManager*/
		void RegisterObject(WorldObject* object);
		/*Puts a WorldObject in to the deletion queue*/
		void DeleteObject(WorldObject* object);

		/*Updates all the physics*/
		void Update();


	private:
		/*Deqeues the qeued objects*/
		void DeqeueWorldObjects();
		/*Deletes the queued objects*/
		void DeleteObjects();

		/*Main Check Collision function decides how to check for collision*/
		void CheckCollision(CollisionType thisType, WorldObject* thisObject, CollisionType otherType, WorldObject* otherObject) const;

		/*Check for box collision between the two WorldObjects*/
		void CheckForBoxCollision(WorldObject* thisObject, WorldObject* otherObject) const;

		std::vector<WorldObject*> m_WorldObjects;
		std::vector<WorldObject*> m_QeuedObjects;
		std::vector<WorldObject*> m_QeuedDeleteObjects;
	};
}