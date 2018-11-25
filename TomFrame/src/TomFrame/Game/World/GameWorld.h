#pragma once
#include "World.h"
#include <vector>
#include "../../Debug/Logger.h"

namespace TomFrame 
{
	class WorldObject;
	class GameWorld : public World 
	{
	public:
		/*Registers an object to this world so it can be updated*/
		virtual void RegisterObject(WorldObject* object) override
		{
			if (object == nullptr)
			{
				TomFrame::Debug::Logger::LogError("object is nullptr. FILE: GameWorld.cpp, LINE: 9");
				return;
			}
			m_WorldObjects.push_back(object);
		}

		/*Updates and draws all the registered objects*/
		void Update();

	private:
		std::vector<WorldObject*> m_WorldObjects;
	};
}
