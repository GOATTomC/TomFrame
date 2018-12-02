#include "PhysicsComponent.h"
#include "DrawComponent.h"
#include "../Objects/WorldObject.h"

TomFrame::PhysicsComponent::PhysicsComponent(WorldObject* owner)
{
	p_Owner = owner;
	m_CollisionType = CollisionType::Box;
	m_CollisionSize = sf::Vector2f(0.0f, 0.0f);
}

TomFrame::PhysicsComponent::PhysicsComponent(WorldObject* owner, CollisionType collisionType, int radius)
{
	p_Owner = owner;
}

void TomFrame::PhysicsComponent::Initialize()
{
	m_CollisionSize = p_Owner->GetDrawComponent()->GetSpriteSize();
}

TomFrame::PhysicsComponent::PhysicsComponent(WorldObject* owner, CollisionType collisionType, int width, int height)
{
	p_Owner = owner;
}