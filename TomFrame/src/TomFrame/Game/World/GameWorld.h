#pragma once
#include "World.h"

namespace TomFrame 
{
	class GameWorld : public World 
	{
	public:
		virtual void RegisterObject() override;
	};
}
