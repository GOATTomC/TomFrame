#include "PhysicsManager.h"
#include "../Objects/WorldObject.h"
#include "../Components/TransfromComponent.h"
#include "../../Debug/Logger.h"
#include <algorithm>

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

void TomFrame::PhysicsManager::DeleteObject(WorldObject * object)
{
	if (object == nullptr)
	{
		TomFrame::Debug::Logger::LogError("object is nullptr. FILE: PhysicsManager.cpp");
		return;
	}

	m_QeuedDeleteObjects.push_back(object);
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

void TomFrame::PhysicsManager::DeleteObjects()
{
	std::vector<TomFrame::WorldObject*>::reverse_iterator end = m_QeuedDeleteObjects.rend();

	//Loop through all WorldObjects
	for (std::vector<TomFrame::WorldObject*>::reverse_iterator it = m_QeuedDeleteObjects.rbegin(); it != end; it++)
	{
		//Delete the object from the game loop
		std::remove(m_WorldObjects.begin(), m_WorldObjects.end(), *it);
	}

	//Clear the queued WorldObjects for deletion
	m_QeuedDeleteObjects.clear();
}

void TomFrame::PhysicsManager::CheckCollision(CollisionType thisType, WorldObject * thisObject, CollisionType otherType, WorldObject * otherObject) const
{
	//If box collision check
	if (thisType == CollisionType::Box && otherType == CollisionType::Box)
	{
		CheckForBoxCollision(thisObject, otherObject);
	}
}

void TomFrame::PhysicsManager::CheckForBoxCollision(WorldObject * thisObject, WorldObject * otherObject) const
{
	//positions
	sf::Vector2f originObject1 = thisObject->GetTransformComponent()->GetPosition();
	sf::Vector2f originObject2 = otherObject->GetTransformComponent()->GetPosition();

	//sizes
	sf::Vector2f sizeObject1 = thisObject->GetPhysicsComponent()->GetSize();
	sf::Vector2f sizeObject2 = otherObject->GetPhysicsComponent()->GetSize();

	//Check for intersection
	if (
		((originObject2.x >= originObject1.x && originObject2.x <= originObject1.x + sizeObject1.x) && (originObject2.y >= originObject1.y && originObject2.y <= originObject1.y + sizeObject1.y))//Top left
		|| //OR
		((originObject2.x + sizeObject2.x >= originObject1.x && originObject2.x + sizeObject2.x <= originObject1.x + sizeObject1.x) && (originObject2.y >= originObject1.y && originObject2.y <= originObject1.y + sizeObject1.y)) //Top right
		|| //OR
		((originObject2.x >= originObject1.x && originObject2.x <= originObject1.x + sizeObject1.x) && (originObject2.y + sizeObject2.y >= originObject1.y && originObject2.y + sizeObject2.y <= originObject1.y + sizeObject1.y)) //Bottom left
		|| //OR
		((originObject2.x + sizeObject2.x >= originObject1.x && originObject2.x + sizeObject2.x <= originObject1.x + sizeObject1.x) && (originObject2.y + sizeObject2.y >= originObject1.y && originObject2.y + sizeObject2.y <= originObject1.y + sizeObject1.y)) //Bottom Right
		)
	{
		//Only notify this object because other object will have this check as well
		//Only on notidy because you'll end up with two otherwise
		
		thisObject->OnCollisionEnter(otherObject);
	}
	
}

void TomFrame::PhysicsManager::Update()
{
	//Get the end point already for performance
	std::vector<TomFrame::WorldObject*>::iterator endIt = m_WorldObjects.end();

	//Check for collisions
	for (std::vector<TomFrame::WorldObject*>::iterator it = m_WorldObjects.begin(); it != endIt; it++)
	{
		//Loop through all other WorldObjects
		for (std::vector<TomFrame::WorldObject*>::iterator other = m_WorldObjects.begin(); other != endIt; other++)
		{
			if (it != other)
			{
				CheckCollision((*it)->GetPhysicsComponent()->GetCollisionType(), (*it), (*other)->GetPhysicsComponent()->GetCollisionType(), (*other));
			}
		}
	}

	DeqeueWorldObjects();
	DeleteObjects();
}



