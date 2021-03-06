#include "DrawComponent.h"
#include "../Objects/WorldObject.h"
#include "../../Debug/Logger.h"
#include "../World/World.h"
#include "../Services/TextureManager.h"
#include <SFML/Graphics.hpp>

TomFrame::DrawComponent::DrawComponent(WorldObject* owner)
{
	if (owner == nullptr)
	{
		TomFrame::Debug::Logger::LogError("owner is nullptr. FILE: DrawComponent.cpp, LINE: 9");
		return;
	}
	p_Owner = owner;

	p_CurrentSprite = new sf::Sprite();
	if (p_CurrentSprite == nullptr)
	{
		TomFrame::Debug::Logger::LogError("Sprite allocation failed. FILE: DrawComponent.cpp, LINE: 20");
		return;
	}
}

TomFrame::DrawComponent::~DrawComponent()
{

}

sf::Vector2f TomFrame::DrawComponent::GetSpriteSize()
{
	//TODO Add scale calculation for size

	sf::Vector2f size;
	size.x = p_CurrentSprite->getTexture()->getSize().x;
	size.y = p_CurrentSprite->getTexture()->getSize().y;
	return size;
}

void TomFrame::DrawComponent::SetSprite(std::string spriteLocation)
{
	if (p_Owner->GetWorld()->GetTextureManager()->GetTexture(spriteLocation) != nullptr)
	{
		p_CurrentSprite->setTexture(*p_Owner->GetWorld()->GetTextureManager()->GetTexture(spriteLocation));
	}
}

