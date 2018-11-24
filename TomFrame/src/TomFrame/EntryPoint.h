#pragma once
#include "Game/World/GameWorld.h"

#ifdef TF_PLATFORM_WINDOWS

extern TomFrame::Application* TomFrame::CreateApplication(World* world);

int main(int argc, char** argv)
{
	TomFrame::GameWorld* world = new TomFrame::GameWorld();
	auto game = TomFrame::CreateApplication(world);
	game->Run();
	delete game;
	return 0;
}

#endif // TF_PLATFORM_WINDOWS
