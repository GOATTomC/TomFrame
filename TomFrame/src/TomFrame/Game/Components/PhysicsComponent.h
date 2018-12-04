#pragma once
#include "../../Core.h"
#include <SFML/System/Vector2.hpp>

#ifndef COLLISIONENUM
#define COLLISIONENUM
	enum CollisionType
	{
		Box = 0,
		Circle
	};
#endif

namespace TomFrame
{

	class WorldObject;

	TOMFRAME_API class PhysicsComponent
	{
	public:
		/*Creates a physic component with box collision with the size of the sprite*/
		PhysicsComponent(WorldObject* owner);
		/*Creates a physic component with box collision with the given size*/
		PhysicsComponent(WorldObject* owner, CollisionType collisionType, int width, int height);
		/*Creates a physic component with circle collision with the given radius*/
		PhysicsComponent(WorldObject* owner, CollisionType collisionType, int radius);

		sf::Vector2f GetSize() { return m_CollisionSize; }

		void Initialize();
		~PhysicsComponent();



	private:
		CollisionType m_CollisionType;
		WorldObject* p_Owner = nullptr;

		//The size of the current collision box
		sf::Vector2f m_CollisionSize;
		//The radius of the current collision circle
		float m_CollisionRadius = 0.0f;
	};
}