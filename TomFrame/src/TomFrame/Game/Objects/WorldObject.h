#pragma once
#include "../../Core.h"
#include <string>

namespace TomFrame
{
	class World;
	class WorldObject
	{
	public:
		//Default constructor of all WorldOjects
		TOMFRAME_API WorldObject(std::string name);
		~WorldObject();

	private:
		/*The name of the WorldObject*/
		std::string m_Name;
		/*The world the WorldObject is in*/
		World* p_World = nullptr;
	};
}
