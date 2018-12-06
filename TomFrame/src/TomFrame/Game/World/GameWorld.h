#pragma once
#include "../../Core.h"
#include "World.h"
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../Objects/WorldObject.h"
#include "../../Debug/Logger.h"
#include "../Services/TextureManager.h"
#include "../Services/PhysicsManager.h"
#include "SFML/Graphics/RenderStates.hpp"
#include <SFML//Graphics/RenderWindow.hpp>

namespace TomFrame 
{

	class InputManager;

	class GameWorld : public World 
	{
	public:
		TOMFRAME_API GameWorld();


		~GameWorld()
		{
			delete p_TextureManager;
			delete p_InputManager;
			delete p_PhysicsManager;
		}

		void SetRenderWindow(sf::RenderWindow* window) { p_RenderWindow = window; }
		void SetInputManager(InputManager* inputManager);
		void SetWindowSettings(WindowSettings* windowSettings);

		/*Registers an object to this world so it can be updated*/
		virtual void RegisterObject(WorldObject* object) override
		{
			if (object == nullptr)
			{
				TomFrame::Debug::Logger::LogError("object is nullptr. FILE: GameWorld.cpp, LINE: 9");
				return;
			}
			m_QeuedWorldObject.push_back(object);
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

			//If WorldObject has a PhysicsComponent add it in the Physicloop
			if (object->GetPhysicsComponent() != nullptr)
			{
				//Add in physicLoop
				p_PhysicsManager->RegisterObject(object);
			}
		}

		/*Updates and draws all the registered objects*/
		void Update(float deltaTime);

		/*Put the queued WorldObjects into the game*/
		void DeqeueWorldObjects();

		/*Puts a WorldObject in a queue for deletion from game*/
		TOMFRAME_API void DestroyWorldObject(WorldObject* object) override;

		/*Returns the TextureManager of this world*/
		virtual TextureManager* GetTextureManager() { return p_TextureManager; }

		/*Returns the Input Manager of this world*/
		virtual InputManager* GetInputManager() { return p_InputManager; }

		/*Return the window settings of the application*/
		virtual WindowSettings* GetWindowSettings() { return p_WindowSettings; }

	private:
		void DeleteObjects();

		sf::RenderWindow* p_RenderWindow = nullptr;

		std::vector<WorldObject*> m_WorldObjects;
		//We store all in game spawned WorldObjects here until new frame
		std::vector<WorldObject*> m_QeuedWorldObject;
		//We store all object who need to be destroyed here for one frame
		std::vector<WorldObject*> m_QueueDeleteWorldObject;
		TextureManager* p_TextureManager;
		InputManager* p_InputManager = nullptr;
		WindowSettings* p_WindowSettings = nullptr;
		PhysicsManager* p_PhysicsManager = nullptr;
	};
}
