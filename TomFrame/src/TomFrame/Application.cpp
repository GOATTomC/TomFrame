#include "Application.h"
#include "WindowSettings.h"
#include "Game/World/GameWorld.h"
#include <SFML/Graphics.hpp>
#include "Debug/Logger.h"
#include "Game/Services/InputManager.h"
#include <ctime>

namespace TomFrame {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run(GameWorld* world)
	{
		sf::RenderWindow* window = nullptr;
		if (p_WindowSettings->GetFullScreen())
		{
			window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), p_WindowSettings->GetWindowText(), sf::Style::Fullscreen);
		}
		else
		{
			window = new sf::RenderWindow(sf::VideoMode(p_WindowSettings->GetScreenSize().Width, p_WindowSettings->GetScreenSize().Height), p_WindowSettings->GetWindowText());
		}
		world->SetRenderWindow(window);

		//Create the input manager
		TomFrame::InputManager* inputManager = new TomFrame::InputManager(window);
		world->SetInputManager(inputManager);

		//Calculate delta time
		sf::Clock deltaClock;

		//Set the random seed for the Random class
		srand(time(nullptr));


		while (window->isOpen())
		{
			sf::Time deltatime = deltaClock.restart();

			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
				//TODO ADD ALT + ENTER TOGGLE FOR FULLSCREEN
			}

			window->clear();
			world->Update(deltatime.asSeconds());
			window->display();
		}

		delete window;
	}

}
