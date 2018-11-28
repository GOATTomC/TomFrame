#include "Bullet.h"
#include "TomFrame/Game/Components/TransfromComponent.h"


void Bullet::Update(float deltaTime)
{
	GetTransformComponent()->Move(sf::Vector2f(400.0f, 0.0f) * deltaTime);
}

