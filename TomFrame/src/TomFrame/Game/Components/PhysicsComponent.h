#pragma once
#include "../../Core.h"

enum CollisionType
{
	Box = 0,
	Circle
};

namespace TomFrame
{
	TOMFRAME_API class PhysicsComponent
	{
	public:
		PhysicsComponent(CollisionType collisionType);
		PhysicsComponent(CollisionType collisionType, int width, int height);
		PhysicsComponent(CollisionType collisionType, int radius);
		~PhysicsComponent();
	};
}