#include <TomFrame.h>
#include "Game/Airplane.h"

class Game : public TomFrame::Application 
{
public:
	Game(TomFrame::World* world) 
	{
		//Set the window settings here before booting it
		p_WindowSettings = new TomFrame::WindowSettings();
		p_WindowSettings->SetWindowText("Shooter");
		p_WindowSettings->SetScreenSize(800, 600);

		//Create all the objects the client wants at the start of the game
		CreateGame(world);
	}

	~Game()
	{
		delete p_WindowSettings;
	}

	/*Creates all the object the player wants at the start of the game*/
	void CreateGame(TomFrame::World* world);
};

void Game::CreateGame(TomFrame::World* world)
{
	Airplane* airplane = new Airplane("Player Airplane");
	//airplane->Initialise(sf::Vector2f(0.0f, 0.0f), "Airplane.txt");
	world->CreateAndRegister(airplane, "Images/Spaceship1Small.png", sf::Vector2f(0.0f, 0.0f));

	TomFrame::Debug::Logger::Log("Custom game created");
}

TomFrame::Application* TomFrame::CreateApplication(World* world)
{
	return new Game(world);
}

