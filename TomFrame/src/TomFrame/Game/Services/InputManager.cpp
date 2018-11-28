#include "InputManager.h"
#include "../../Debug/Logger.h"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <algorithm>

TomFrame::InputManager::InputManager(sf::RenderWindow* window)
{
	if (window == nullptr)
	{
		TomFrame::Debug::Logger::LogError("window is nullptr. FILE: InputManager.cpp");
		return;
	}

	p_RenderWindow = window;
}

TomFrame::InputManager::~InputManager()
{

}

TOMFRAME_API bool TomFrame::InputManager::GetKeyDown(sf::Keyboard::Key key)
{
	//If the key is down
	if (sf::Keyboard::isKeyPressed(key))
	{
		//Check if currently pressed
		if (!IsCurrentlyPressed(key))
		{
			m_CurrentPressedObjects.push_back(key);
			//Say the key just got pressed
			return true;
		}
	}
	//The key is not being pressed
	else
	{
		//Check if we previously pressed it
		if (IsCurrentlyPressed(key))
		{
			//Remove it from the keys we are currently pressing
			m_CurrentPressedObjects.erase(std::remove(m_CurrentPressedObjects.begin(), m_CurrentPressedObjects.end(), key), m_CurrentPressedObjects.end());
		}
	}

	return false;
}

TOMFRAME_API bool TomFrame::InputManager::GetKeyUp(sf::Keyboard::Key key)
{
	//If the key is down
	if (sf::Keyboard::isKeyPressed(key))
	{
		//Check if currently pressed
		if (!IsCurrentlyPressed(key))
		{
			m_CurrentPressedObjects.push_back(key);
			//Say the key just got pressed
			return false;
		}
	}
	//The key is not being pressed
	else
	{
		//Check if we previously pressed it
		if (IsCurrentlyPressed(key))
		{
			//Remove it from the keys we are currently pressing
			m_CurrentPressedObjects.erase(std::remove(m_CurrentPressedObjects.begin(), m_CurrentPressedObjects.end(), key), m_CurrentPressedObjects.end());
			return true;
		}
	}

	return false;
}

TOMFRAME_API bool TomFrame::InputManager::GetKey(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}

bool TomFrame::InputManager::IsCurrentlyPressed(sf::Keyboard::Key key)
{
	if (std::find(m_CurrentPressedObjects.begin(), m_CurrentPressedObjects.end(), key) != m_CurrentPressedObjects.end())
	{
		//If the key is already being pressed
		return true;
	}

	return false;
}

