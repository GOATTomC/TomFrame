#include "Meteor.h"

void Meteor::Update(float deltaTime)
{
	GetTransformComponent()->Move(sf::Vector2f(-100.0f, 0.0f) * deltaTime);
}  