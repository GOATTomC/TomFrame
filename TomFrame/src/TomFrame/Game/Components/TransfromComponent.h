#pragma once
#include "SFML/System/Vector2.hpp"

namespace TomFrame
{
	class TransformComponent
	{
	public:
		TransformComponent();
		~TransformComponent();

		/*Sets a new position to the current position*/
		void SetPosition(sf::Vector2f newPosition);

		/*Moves the current position to a new position given the direction*/
		void Move(sf::Vector2f direction);

		/*Returns the current position of the owner*/
		sf::Vector2f GetPosition();

	private:
		sf::Vector2f m_CurrentPosition;
	};
}