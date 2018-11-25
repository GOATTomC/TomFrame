#pragma once
#include "World.h"
#include <vector>

namespace TomFrame 
{
	class WorldObject;
	class GameWorld : public World 
	{
	public:
		/*Registers an object to this world so it can be updated*/
		virtual void RegisterObject(WorldObject* object) override;

		/*Updates and draws all the registered objects*/
		void Update();

	private:
		std::vector<WorldObject*> m_WorldObjects;
	};
}
