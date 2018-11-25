#pragma once
#include "../../Core.h"

namespace TomFrame 
{
	/*Interface for the client*/
	/*The client will never see what the dll is doing under the hood*/

	class WorldObject;
	class TOMFRAME_API World
	{
	public:

		virtual void RegisterObject(WorldObject* object) = 0;
	};
}