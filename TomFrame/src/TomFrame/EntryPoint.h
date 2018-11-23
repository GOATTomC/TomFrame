#pragma once

#ifdef TF_PLATFORM_WINDOWS

extern TomFrame::Application* TomFrame::CreateApplication();

int main(int argc, char** argv)
{
	auto game = TomFrame::CreateApplication();
	game->Run();
	delete game;
	return 0;
}

#endif // TF_PLATFORM_WINDOWS
