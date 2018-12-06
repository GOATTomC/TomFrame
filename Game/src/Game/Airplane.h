#pragma once
#include <TomFrameObjects.h>

class Airplane : public TomFrame::WorldObject
{
public:
	Airplane(std::string name) : TomFrame::WorldObject(name){}
	Airplane(std::string name, CollisionType collisionType) : TomFrame::WorldObject(name, collisionType) {}
	~Airplane();

	
	/*Overrided Update function called by framework*/
	virtual void Update(float deltaTime) override;

	/*Overrides OnCollisionEnter function called by framework*/
	virtual void OnCollisionEnter(WorldObject* other) override;

private:
	void Shoot();

	const float SPEED = 100.0f;


};