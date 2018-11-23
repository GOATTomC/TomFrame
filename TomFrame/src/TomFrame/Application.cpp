#include "Application.h"
#include "WindowSettings.h"
#include <SFML/Graphics.hpp>

namespace TomFrame {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		sf::RenderWindow window(sf::VideoMode(p_WindowSettings->GetScreenSize().Width, p_WindowSettings->GetScreenSize().Height), p_WindowSettings->GetWindowText());
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
	}

}
