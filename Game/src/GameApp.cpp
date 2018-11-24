#include <TomFrame.h>
#include "Game/Airplane.h"

class Game : public TomFrame::Application 
{
public:
	Game() 
	{
		//Set the window settings here before booting it
		p_WindowSettings = new TomFrame::WindowSettings();
		p_WindowSettings->SetWindowText("Shooter");
		p_WindowSettings->SetScreenSize(800, 600);
		CreateGame();
	}

	~Game()
	{
		delete p_WindowSettings;
	}

	void CreateGame();
};

void Game::CreateGame()
{
	Airplane* airplane = new Airplane("Player Airplane");
}

TomFrame::Application* TomFrame::CreateApplication()
{
	return new Game();
}

