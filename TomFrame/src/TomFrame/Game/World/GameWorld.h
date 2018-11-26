#pragma once
#include "World.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../Objects/WorldObject.h"
#include "../../Debug/Logger.h"
#include "../Services/TextureManager.h"
#include "SFML/Graphics/RenderStates.hpp"
#include <SFML//Graphics/RenderWindow.hpp>

namespace TomFrame 
{

	class GameWorld : public World 
	{
	public:
		GameWorld()
		{
			p_TextureManager = new TextureManager();
		}

		~GameWorld()
		{
			delete p_TextureManager;
		}

		void SetRenderWindow(sf::RenderWindow* window) { p_RenderWindow = window; }

		/*Registers an object to this world so it can be updated*/
		virtual void RegisterObject(WorldObject* object) override
		{
			if (object == nullptr)
			{
				TomFrame::Debug::Logger::LogError("object is nullptr. FILE: GameWorld.cpp, LINE: 9");
				return;
			}
			m_WorldObjects.push_back(object);
		}

		/*Initializes an object and registers it to this world*/
		virtual void CreateAndRegister(WorldObject* object, std::string spritePath, sf::Vector2f spawnLocation)
		{
			if (object == nullptr)
			{
				TomFrame::Debug::Logger::LogError("object is nullptr. FILE: GameWorld.h, LINE: 29");
			}

			object->SetWorld(this);
			object->Initialise(spawnLocation, spritePath);
			RegisterObject(object);
		}

		/*Updates and draws all the registered objects*/
		void Update(sf::Event even, float deltaTime);

		/*Returns the TextureManager of this world*/
		virtual TextureManager* GetTextureManager() { return p_TextureManager; }

	private:
		sf::RenderWindow* p_RenderWindow = nullptr;

		std::vector<WorldObject*> m_WorldObjects;
		TextureManager* p_TextureManager;
	};
}
