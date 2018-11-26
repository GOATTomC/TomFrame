#include "WorldObject.h"
#include "../Components/DrawComponent.h"
#include "../Components/TransfromComponent.h"
#include "../../Debug/Logger.h"
#include <SFML/System/Vector2.hpp>

TOMFRAME_API TomFrame::WorldObject::WorldObject(std::string name)
{
	m_Name = name;
	p_DrawComponent = new TomFrame::DrawComponent(this);
	p_TransformComponent = new TomFrame::TransformComponent();
}

TomFrame::WorldObject::~WorldObject()
{
	delete p_DrawComponent;
	delete p_TransformComponent;
}

void TomFrame::WorldObject::Initialise(sf::Vector2f spawnPosition, std::string spriteLocation)
{
	if (p_TransformComponent == nullptr || p_DrawComponent == nullptr)
	{
		TomFrame::Debug::Logger::LogError("p_TransformComponent or p_DrawComponent = nullptr. FILE: WorldObject.cpp LINE: 23");
	}

	p_TransformComponent->SetPosition(spawnPosition);
	p_DrawComponent->SetSprite(spriteLocation);

	TomFrame::Debug::Logger::Log("Initialized WorldObject with the sprite: " + spriteLocation);
}

