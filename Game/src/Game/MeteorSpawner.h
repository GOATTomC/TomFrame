#pragma once
#include <TomFrameObjects.h>

class MeteorSpawner : public TomFrame::WorldObject
{
public:
	MeteorSpawner(std::string name) : TomFrame::WorldObject(name) {}
	~MeteorSpawner();

	virtual void Update(float deltaTime) override;

private:
	float m_SpawnTimer = 4;
	float m_TimePassed = 0;

	const float SPAWNPOSITION_X = 200;

};