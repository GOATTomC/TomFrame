#pragma once
#include "World.h"

namespace TomFrame 
{
	class GameWorld : public World 
	{
	public:
		/*Registers an object to this world so it can be updated*/
		virtual void RegisterObject() override;
	};
}
