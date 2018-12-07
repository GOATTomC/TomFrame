#include "Bullet.h"
#include "TomFrame/Game/Components/TransfromComponent.h"
#include "TomFrame/WindowSettings.h"


void Bullet::Update(float deltaTime)
{
	
	GetTransformComponent()->Move(sf::Vector2f(400.0f, 0.0f) * deltaTime);

	//Destroy bullet when out of screen
	if (GetTransformComponent()->GetPosition().x > GetWorld()->GetWindowSettings()->GetScreenSize().Width)
	{
		GetWorld()->DestroyWorldObject(this);
	}

	TomFrame::Debug::Logger::Log(deltaTime);
}

