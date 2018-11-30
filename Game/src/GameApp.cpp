#include <TomFrame.h>
#include "Game/Airplane.h"
#include "Game/MeteorSpawner.h"

class Game : public TomFrame::Application 
{
public:
	Game(TomFrame::World* world) 
	{
		//Set the window settings here before booting it
		p_WindowSettings = new TomFrame::WindowSettings();
		//Full window on screen resolution
		p_WindowSettings->SetWindowText("Shooter");
		p_WindowSettings->SetFullScreen(true);

		/*Uncomment this for custom resolution non full screen*/
		//p_WindowSettings->SetScreenSize(800, 600);
		//p_WindowSettings->SetFullScreen(false);

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
	//Create player
	Airplane* airplane = new Airplane("Player Airplane");
	world->CreateAndRegister(airplane, "Images/Spaceship1Small.png", sf::Vector2f(0.0f, 0.0f));

	MeteorSpawner* meteorSpawner = new MeteorSpawner("Meteor Spawner");
	world->CreateAndRegister(meteorSpawner, "", sf::Vector2f(0.0f, 0.0f));

	TomFrame::Debug::Logger::Log("Custom game created");
}

TomFrame::Application* TomFrame::CreateApplication(World* world)
{
	return new Game(world);
}

