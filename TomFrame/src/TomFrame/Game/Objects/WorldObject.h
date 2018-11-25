#pragma once
#include "../../Core.h"
#include <string>

//Forward declarations of sf used classed from sf namespace
namespace sf
{
	template<typename T>
	class Vector2;

	typedef Vector2<float> Vector2f;
}

namespace TomFrame
{
	class World;
	class DrawComponent;
	class TransformComponent;
	class WorldObject
	{
	public:
		//Default constructor of all WorldOjects
		TOMFRAME_API WorldObject(std::string name);
		~WorldObject();

		/*Returns the DrawComponent attached to the WorldObject*/
		DrawComponent* GetDrawComponent() { return p_DrawComponent; }
		/*Returns the TransfromComponent attached to the WorldObject*/
		TransformComponent* GetTransformComponent() { return p_TransformComponent; }

		/*Initialize function that the game calls on creation of an object*/
		TOMFRAME_API void Initialise(sf::Vector2f spawnPosition, std::string spriteLocation);

		/*Required update function for all inherited classes from this WorldObject*/
		virtual void Update() = 0;

	private:
		/*The name of the WorldObject*/
		std::string m_Name;
		/*The world the WorldObject is in*/
		World* p_World = nullptr;


		//Required components for every WorldObject
		DrawComponent* p_DrawComponent = nullptr;
		TransformComponent* p_TransformComponent = nullptr;
	};
}
