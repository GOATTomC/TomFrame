#pragma once
#include "../../Core.h"
#include "SFML/Window/Keyboard.hpp"
#include <vector>

namespace sf
{
	class RenderWindow;
}

namespace TomFrame
{
	class InputManager
	{
	public:

		//Constructor
		InputManager(sf::RenderWindow* window);
		~InputManager();

		//Checks if the given key has been pressed down
		TOMFRAME_API bool GetKeyDown(sf::Keyboard::Key key);

		/*Check if the given key is released*/
		TOMFRAME_API bool GetKeyUp(sf::Keyboard::Key key);

		/*Check if the given key is being pressed*/
		TOMFRAME_API bool GetKey(sf::Keyboard::Key key);

	private:
		sf::RenderWindow* p_RenderWindow = nullptr;
		std::vector<sf::Keyboard::Key> m_CurrentPressedObjects;

		/*Checks if the given key is currently already being pressed*/
		bool IsCurrentlyPressed(sf::Keyboard::Key key);
	};
}