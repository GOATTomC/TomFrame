#pragma once
#include <TomFrameObjects.h>

class MeteorSpawner : public TomFrame::WorldObject
{
public:
	MeteorSpawner(std::string name) : TomFrame::WorldObject(name) {}
	~MeteorSpawner();

	virtual void Update(float deltaTime) override;

};