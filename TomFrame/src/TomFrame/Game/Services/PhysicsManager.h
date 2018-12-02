#pragma once
#include <vector>

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

		/*Updates all the physics*/
		void Update();


	private:
		/*Deqeues the qeued objects*/
		void DeqeueWorldObjects();

		std::vector<WorldObject*> m_WorldObjects;
		std::vector<WorldObject*> m_QeuedObjects;
	};
}