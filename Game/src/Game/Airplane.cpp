#include "Airplane.h"
#include "TomFrame/Game/Components/TransfromComponent.h"
#include "Bullet.h"
#include "TomFrame/Game/World/World.h"
#include "TomFrame/Game/Services/InputManager.h"



void Airplane::Update(float deltaTime)
{
	if (GetWorld()->GetInputManager()->GetKeyDown(sf::Keyboard::Space))
	{
		Shoot();
	}
}

void Airplane::Shoot()
{
	Bullet* bullet = new Bullet("Test Bullet");
	GetWorld()->CreateAndRegister(bullet, "Images/Bullet.png", GetTransformComponent()->GetPosition());
}
