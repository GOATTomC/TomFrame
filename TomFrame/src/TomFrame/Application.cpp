#include "Application.h"
#include "WindowSettings.h"
#include "Game/World/GameWorld.h"
#include <SFML/Graphics.hpp>

namespace TomFrame {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run(GameWorld* world)
	{
		sf::RenderWindow window(sf::VideoMode(p_WindowSettings->GetScreenSize().Width, p_WindowSettings->GetScreenSize().Height), p_WindowSettings->GetWindowText());
		world->SetRenderWindow(&window);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			world->Update();
			window.display();
		}
	}

}
