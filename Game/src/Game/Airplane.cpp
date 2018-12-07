#include "Airplane.h"
#include "TomFrame/Game/Components/TransfromComponent.h"
#include "Bullet.h"
#include "TomFrame/Game/World/World.h"
#include "TomFrame/Game/Services/InputManager.h"



void Airplane::Update(float deltaTime)
{
	//Shoot
	if (GetWorld()->GetInputManager()->GetKeyDown(sf::Keyboard::Space))
	{
		Shoot();
	}

	//Moving
	if (GetWorld()->GetInputManager()->GetKey(sf::Keyboard::S))//Down
	{
		GetTransformComponent()->Move(sf::Vector2f(0.0f, SPEED) * deltaTime);
	}
	if (GetWorld()->GetInputManager()->GetKey(sf::Keyboard::W))//Up
	{
		GetTransformComponent()->Move(sf::Vector2f(0.0f, -SPEED) * deltaTime);
	}
}

void Airplane::OnCollisionEnter(WorldObject* other)
{
	TomFrame::Debug::Logger::Log("Has collision");
	if (other->GetName() == "Meteor")
	{
		GetWorld()->DestroyWorldObject(this);
	}
}

void Airplane::Shoot()
{
	Bullet* bullet = new Bullet("Test Bullet", CollisionType::Box);
	GetWorld()->CreateAndRegister(bullet, "Images/Bullet.png", GetTransformComponent()->GetPosition());
}
