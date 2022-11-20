#include "Menu.h"


Menu::Menu(GameParameters* gameParameters)
{
	initWindow(gameParameters);
}

Menu::~Menu()
{
	delete this->window;
}

void Menu::update(GameParameters *gameParameters)
{
	pollEvents(gameParameters);
	gameParameters->readMousePos(window);
}

void Menu::pollEvents(GameParameters* gameParameters)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space)
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


void Menu::initWindow(GameParameters* gameParameters)
{
	window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");
	window->setFramerateLimit(60);
}


void Menu::render(GameParameters* gameParameters)
{
	window->clear(sf::Color::White);

	menuLayout.renderLayout(gameParameters, window);

	window->display();
}

