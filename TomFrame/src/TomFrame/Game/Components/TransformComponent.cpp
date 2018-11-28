#include "TransfromComponent.h"

TomFrame::TransformComponent::TransformComponent()
{

}

TomFrame::TransformComponent::~TransformComponent()
{

}

void TomFrame::TransformComponent::SetPosition(sf::Vector2f newPosition)
{
	m_CurrentPosition = newPosition;
}

void TomFrame::TransformComponent::Move(sf::Vector2f direction) 
{
	m_CurrentPosition += direction;
}

sf::Vector2f TomFrame::TransformComponent::GetPosition()
{
	return m_CurrentPosition;
}