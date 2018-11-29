#pragma once
#include <TomFrameObjects.h>

class Meteor : public TomFrame::WorldObject
{
public:
	Meteor(std::string name) : TomFrame::WorldObject(name) {}
	~Meteor();

	virtual void Update(float deltaTime) override;

};