#include "Airplane.h"
#include "TomFrame/Game/Components/TransfromComponent.h"



void Airplane::Update(sf::Event event, float deltaTime)
{
	//If plane moves down
	//TODO MOVE INPUT TO DLL INSTEAD OF HAVING TO LINK TO SFML FROM GAME DIR
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		GetTransformComponent()->Move(sf::Vector2f(0.0f, 200.0f) * deltaTime);
	}
	//If plane moves up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		GetTransformComponent()->Move(sf::Vector2f(0.0f, -200.0f) * deltaTime);
	}
}
