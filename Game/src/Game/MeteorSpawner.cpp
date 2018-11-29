#include "MeteorSpawner.h"
#include "Meteor.h"
#include "TomFrame/Game/World/World.h"


void MeteorSpawner::Update(float deltaTime)
{
	//Increment timer time
	m_TimePassed += deltaTime;

	//If timer is done
	if (m_TimePassed > m_SpawnTimer)
	{
		//Spawn meteor
		Meteor* meteor = new Meteor("Meteor");
		float randomY = TomFrame::Static::Random::GetRandom(0.0f, 500.0f);
		GetWorld()->CreateAndRegister(meteor, "Images/meteor.png", sf::Vector2f(0.0f, randomY));

		//Reset timer
		m_TimePassed = 0;
	}
}

