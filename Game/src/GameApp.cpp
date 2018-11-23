#include <TomFrame.h>

class Game : public TomFrame::Application 
{
public:
	Game() 
	{
		//Set the window settings here before booting it
		p_WindowSettings = new TomFrame::WindowSettings();
		p_WindowSettings->SetWindowText("Shooter");
		p_WindowSettings->SetScreenSize(800, 600);
	}

	~Game()
	{
		delete p_WindowSettings;
	}
};

TomFrame::Application* TomFrame::CreateApplication()
{
	return new Game();
}