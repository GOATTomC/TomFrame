#include "PhysicsManager.h"
#include "../Objects/WorldObject.h"
#include "../../Debug/Logger.h"


TomFrame::PhysicsManager::PhysicsManager()
{

}

TomFrame::PhysicsManager::~PhysicsManager()
{

}

void TomFrame::PhysicsManager::RegisterObject(WorldObject * object)
{
	if (object == nullptr)
	{
		TomFrame::Debug::Logger::LogError("object is nullptr. FILE: PhysicsManager.cpp");
		return;
	}

 	m_QeuedObjects.push_back(object);
}

void TomFrame::PhysicsManager::DeqeueWorldObjects()
{
	//Loop through queued objects if it is not 0
	if (m_QeuedObjects.size() == 0)
	{
		//There are no queued objects return
		return;
	}

	for (std::vector<TomFrame::WorldObject*>::iterator it = m_QeuedObjects.begin(); it != m_QeuedObjects.end(); it++)
	{
		//Put queued object into registeredGameObjects
		m_WorldObjects.push_back(*it);
	}

	//Clear the queued list
	m_QeuedObjects.clear();
}

void TomFrame::PhysicsManager::Update()
{
	for (std::vector<TomFrame::WorldObject*>::iterator it = m_WorldObjects.begin(); it != m_WorldObjects.end(); it++)
	{
		//Check for collisions
	}

	DeqeueWorldObjects();
}

