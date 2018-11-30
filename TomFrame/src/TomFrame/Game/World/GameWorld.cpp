#include "GameWorld.h"
#include "../Objects/WorldObject.h"
#include "../Components/DrawComponent.h"
#include "../../Debug/Logger.h"
#include <SFML/Graphics.hpp>
#include "../Services/TextureManager.h"
#include "../Components/TransfromComponent.h"
#include "../Services/InputManager.h"
#include "../../WindowSettings.h"


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

	//Include queued objects into game
	DeqeueWorldObjects();
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

//TODO DELETE ALL WORLDOBJECTS AFTER GAME END

