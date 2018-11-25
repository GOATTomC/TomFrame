#include "GameWorld.h"
#include "../Objects/WorldObject.h"
#include "../../Debug/Logger.h"

void TomFrame::GameWorld::RegisterObject(WorldObject* object)
{
	if (object == nullptr)
	{
		TomFrame::Debug::Logger::LogError("object is nullptr. FILE: GameWorld.cpp, LINE: 9");
		return;
	}
	m_WorldObjects.push_back(object);
}

void TomFrame::GameWorld::Update()
{
	//Loop through all registered WorldObjects
	for (std::vector<TomFrame::WorldObject*>::iterator it = m_WorldObjects.begin(); it != m_WorldObjects.end(); it++)
	{
		(*it)->Update();
	}

}

