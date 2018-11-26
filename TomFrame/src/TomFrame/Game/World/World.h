#pragma once
#include "../../Core.h"
#include <string>

//Forward declaration of sf namespace classes
namespace sf
{
	template<typename T>
	class Vector2;

	typedef Vector2<float> Vector2f;
}

namespace TomFrame 
{
	/*Interface for the client*/
	/*The client will never see what the dll is doing under the hood*/

	class WorldObject;
	class TOMFRAME_API World
	{
	public:

		virtual void RegisterObject(WorldObject* object) = 0;
		virtual void CreateAndRegister(WorldObject* object, std::string spritePath, sf::Vector2f spawnLocation) = 0;
	};

}