#pragma once
#include "../../Core.h"
#include <string>

namespace TomFrame
{
	class World;
	class DrawComponent;
	class WorldObject
	{
	public:
		//Default constructor of all WorldOjects
		TOMFRAME_API WorldObject(std::string name);
		~WorldObject();

		DrawComponent* GetDrawComponent() { return p_DrawComponent; }

		virtual void Update() = 0;

	private:
		/*The name of the WorldObject*/
		std::string m_Name;
		/*The world the WorldObject is in*/
		World* p_World = nullptr;


		//Required components for every WorldObject
		DrawComponent* p_DrawComponent = nullptr;
	};
}
