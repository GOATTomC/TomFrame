#pragma once
#include <TomFrameObjects.h>

class Bullet : public TomFrame::WorldObject
{
public: 
	Bullet(std::string name) : WorldObject(name) {}
	Bullet(std::string name, CollisionType collisionType) : WorldObject(name, collisionType) {}
	~Bullet();

	virtual void Update(float deltaTime) override;

};