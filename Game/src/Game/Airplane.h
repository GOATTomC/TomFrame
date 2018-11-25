#pragma once
#include <TomFrameObjects.h>

namespace TomFrame
{
	class WorldObject;
}

class Airplane : public TomFrame::WorldObject
{
public:
	Airplane(std::string name) : TomFrame::WorldObject(name){}
	~Airplane();

	
	/*Overrided Update function called by framework*/
	virtual void Update() override;

};