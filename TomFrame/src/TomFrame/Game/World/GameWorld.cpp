#include "GameWorld.h"
#include "../Objects/WorldObject.h"
#include "../Components/DrawComponent.h"
#include "../../Debug/Logger.h"
#include <SFML/Graphics.hpp>
#include "../Services/TextureManager.h"
#include "../Components/TransfromComponent.h"
#include "../Services/InputManager.h"
#include "../../WindowSettings.h"


TomFrame::GameWorld::GameWorld()
{
	p_TextureManager = new TextureManager();
	p_PhysicsManager = new PhysicsManager();
}

void TomFrame::GameWorld::SetInputManager(InputManager* inputManager)
{
	if (inputManager == nullptr)
	{
		TomFrame::Debug::Logger::LogError("inputManager is nullptr. FILE: GameWorld.cpp");
	}
	p_InputManager = inputManager;
}

void TomFrame::GameWorld::SetWindowSettings(WindowSettings* windowSettings)
{
	if (windowSettings == nullptr)
	{
		TomFrame::Debug::Logger::LogError("windowSettings is nullptr. FILE: GameWorld.cpp");
	}
	p_WindowSettings = windowSettings;
}

void TomFrame::GameWorld::Update(float deltaTime)
{

	//Loop through all registered WorldObjects
	for (std::vector<TomFrame::WorldObject*>::iterator it = m_WorldObjects.begin(); it != m_WorldObjects.end(); it++)
	{
		if ((*it)->GetIsBeingDestroyed())
		{
			continue;
		}
		//Call update function on WorldObject
		(*it)->Update(deltaTime);

		//Draw WorldObject if it has a sprite
		sf::Sprite* sprite = (*it)->GetDrawComponent()->GetCurrentSprite();
		if (sprite != nullptr)
		{
			sprite->setPosition((*it)->GetTransformComponent()->GetPosition());
			p_RenderWindow->draw(*sprite);
		}
	}

	//Update the physics
	p_PhysicsManager->Update();

	//Include queued objects into game
	DeqeueWorldObjects();
	//Delete queued objects from game
	DeleteObjects();
}

void TomFrame::GameWorld::DeqeueWorldObjects()
{
	//Loop through queued objects if it is not 0
	if (m_QeuedWorldObject.size() == 0)
	{
		//There are no queued objects return
		return;
	}

	for (std::vector<TomFrame::WorldObject*>::iterator it = m_QeuedWorldObject.begin(); it != m_QeuedWorldObject.end(); it++)
	{
		//Put queued object into registeredGameObjects
		m_WorldObjects.push_back(*it);
	}

	//Clear the queued list
	m_QeuedWorldObject.clear();
}

TOMFRAME_API void TomFrame::GameWorld::DestroyWorldObject(WorldObject * object)
{
	//Check if it is already being destroyed
	if (!m_QueueDeleteWorldObject.empty())
	{
		if (std::find(m_QueueDeleteWorldObject.begin(), m_QueueDeleteWorldObject.end(), object) != m_QueueDeleteWorldObject.end())
		{
			return;
		}
	}

	m_QueueDeleteWorldObject.push_back(object);
	p_PhysicsManager->DeleteObject(object);
	object->MarkIsBeingDestroyed();
}

void TomFrame::GameWorld::DeleteObjects()
{
	std::vector<TomFrame::WorldObject*>::reverse_iterator end = m_QueueDeleteWorldObject.rend();

	//Loop through all WorldObjects
	for (std::vector<TomFrame::WorldObject*>::reverse_iterator it = m_QueueDeleteWorldObject.rbegin(); it != end; it++) 
	{
		//Delete the object from the game loop
		std::remove(m_WorldObjects.begin(), m_WorldObjects.end(), *it);

		//Delete the object from memory
		delete *it;
	}

	//Clear the queued WorldObjects for deletion
	m_QueueDeleteWorldObject.clear();
}

//TODO DELETE ALL WORLDOBJECTS AFTER GAME END

