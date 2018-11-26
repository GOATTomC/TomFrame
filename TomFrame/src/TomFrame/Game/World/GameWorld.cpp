#include "GameWorld.h"
#include "../Objects/WorldObject.h"
#include "../Components/DrawComponent.h"
#include "../../Debug/Logger.h"
#include <SFML/Graphics.hpp>
#include "../Services/TextureManager.h"
#include "../Components/TransfromComponent.h"

void TomFrame::GameWorld::Update()
{
	//Loop through all registered WorldObjects
	for (std::vector<TomFrame::WorldObject*>::iterator it = m_WorldObjects.begin(); it != m_WorldObjects.end(); it++)
	{
		//Call update function on WorldObject
		(*it)->Update();

		//Draw WorldObject if it has a sprite
		sf::Sprite* sprite = (*it)->GetDrawComponent()->GetCurrentSprite();
		if (sprite != nullptr)
		{
			sprite->setPosition((*it)->GetTransformComponent()->GetPosition());
			p_RenderWindow->draw(*sprite);
		}
	}

}

