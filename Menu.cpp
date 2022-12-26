#include "Menu.h"

Menu::Menu(GameParameters* parameters, sf::RenderWindow* window)
{
	this->window = window;
	gameParameters = parameters;
	gameParameters->menuOpened = true;
}

bool Menu::isOpen()
{
	return gameParameters->menuOpened;
}

void Menu::update()
{
	pollEvents();
	gameParameters->readMousePos(window);
}

void Menu::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameParameters->gameState = -1;
			gameParameters->menuOpened = false;
			window->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
			menuLayout.buttonsClicked(gameParameters, window, event);

		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window->setView(sf::View(visibleArea));
		}
	}
}

void Menu::render()
{
	window->clear(sf::Color::White);

	menuLayout.renderLayout(gameParameters, window);

	window->display();
}
