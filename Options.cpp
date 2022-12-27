#include "Options.h"


Options::Options(GameParameters* parameters, sf::RenderWindow *window)
{
	this->window = window;
	gameParameters = parameters;
	gameParameters->optionsOpened = false;
}


bool Options::isOpen()
{
	return gameParameters->optionsOpened;
}


void Options::update()
{
	pollEvents();
	gameParameters->readMousePos(window);
}

void Options::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameParameters->gameState = -1;
			gameParameters->optionsOpened = false;
			window->close();
		}

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Backspace) {
				gameParameters->gameState = 0;
				gameParameters->optionsOpened = false;
				gameParameters->menuOpened = true;
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
			optionsLayout.buttonsClicked(gameParameters, window, event);

		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window->setView(sf::View(visibleArea));
		}
	}
}


void Options::render()
{
	window->clear(sf::Color::White);

	optionsLayout.renderLayout(gameParameters, window);

	window->display();
}

