#include "WorldObject.h"
#include "../Components/DrawComponent.h"

TOMFRAME_API TomFrame::WorldObject::WorldObject(std::string name)
{
	m_Name = name;
	p_DrawComponent = new TomFrame::DrawComponent();
}

TomFrame::WorldObject::~WorldObject()
{
	delete p_DrawComponent;
}

