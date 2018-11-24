#pragma once
#include <TomFrame.h>

class Airplane : public TomFrame::WorldObject
{
public:
	Airplane(std::string name) : TomFrame::WorldObject(name){}
	~Airplane();
};