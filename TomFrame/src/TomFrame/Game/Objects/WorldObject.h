#pragma once
#include "../../Core.h"
#include <string>

namespace TomFrame
{
	class World;
	class WorldObject
	{
	public:
		TOMFRAME_API WorldObject(std::string name);
		~WorldObject();

	private:
		std::string m_Name;
		World* p_World = nullptr;
	};
}
