#pragma once
#include <TomFrameObjects.h>

class Bullet : public TomFrame::WorldObject
{
public: 
	Bullet(std::string name) : WorldObject(name) {}
	~Bullet();

	virtual void Update(float deltaTime) override;

};