#pragma once
#include <TomFrameObjects.h>

class Meteor : public TomFrame::WorldObject
{
public:
	Meteor(std::string name) : TomFrame::WorldObject(name) {}
	Meteor(std::string name, CollisionType collisionType) : TomFrame::WorldObject(name, collisionType) {}
	~Meteor();

	virtual void Update(float deltaTime) override;
	virtual void OnCollisionEnter(WorldObject* other) override;

};