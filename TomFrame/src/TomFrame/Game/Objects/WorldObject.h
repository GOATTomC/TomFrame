#pragma once
#include "../../Core.h"
#include <string>

//Forward declarations of sf used classed from sf namespace
namespace sf
{
	template<typename T>
	class Vector2;

	typedef Vector2<float> Vector2f;

	class RenderWindow;
	class Event;
}

#ifndef COLLISIONENUM
#define COLLISIONENUM

	enum CollisionType
	{
		Box = 0,
		Circle
	};

#endif // !COLLISIONENUM


namespace TomFrame
{
	class World;
	class DrawComponent;
	class TransformComponent;
	class PhysicsComponent;
	class WorldObject
	{
	public:
		//Default constructor of all WorldOjects
		/*Doesn't create a physic component*/
		TOMFRAME_API WorldObject(std::string name);
		/*Creates WorldObject with physicscomponent*/
		TOMFRAME_API WorldObject(std::string name, CollisionType collisionType);
		~WorldObject();

		/*Returns the DrawComponent attached to the WorldObject*/
		DrawComponent* GetDrawComponent() { return p_DrawComponent; }
		/*Returns the TransfromComponent attached to the WorldObject*/
		TransformComponent* GetTransformComponent() { return p_TransformComponent; }
		/*Returns the PhysicsComponent attached to the WorldObject*/
		PhysicsComponent* GetPhysicsComponent() { return p_PhysicsComponent; }
		/*Returns the world where the object is in*/
		World* GetWorld() { return p_World; }
		/*Sets the world where the object is in*/
		void SetWorld(World* world) { p_World = world; }
		/*Returns the name of the WorldObject*/
		TOMFRAME_API std::string GetName() { return m_Name; }
		/*Sets the DestroyState of the WorldObject*/
		void MarkIsBeingDestroyed() { m_IsBeingDestroyed = true; }
		/*Returns if the WorldObject is being Destroyed*/
		TOMFRAME_API bool GetIsBeingDestroyed() { return m_IsBeingDestroyed; }

		/*Initialize function that the game calls on creation of an object*/
		TOMFRAME_API void Initialise(sf::Vector2f spawnPosition, std::string spriteLocation);

		/*Gets called when the object is involved in a collision*/
		TOMFRAME_API virtual void OnCollisionEnter(WorldObject* other);


		/*Required update function for all inherited classes from this WorldObject*/
		virtual void Update(float deltaTime) = 0;

	private:
		/*The name of the WorldObject*/
		std::string m_Name;
		/*The world the WorldObject is in*/
		World* p_World = nullptr;

		bool m_IsBeingDestroyed = false;


		//Required components for every WorldObject
		DrawComponent* p_DrawComponent = nullptr;
		TransformComponent* p_TransformComponent = nullptr;
		PhysicsComponent* p_PhysicsComponent;
		
	};
}
