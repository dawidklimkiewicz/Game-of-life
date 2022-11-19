#include "DrawingScreen.h"

DrawingScreen::DrawingScreen(GameParameters* gameParameters)
{
	initWindow(gameParameters);
}

DrawingScreen::~DrawingScreen()
{
	delete window;
}

void DrawingScreen::update(GameParameters *gameParameters)
{
	gameParameters->readMousePos(window);
	pollEvents();
}

void DrawingScreen::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	window->setFramerateLimit(60);
}

void DrawingScreen::initWindow(GameParameters* gameParameters)
{
	window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");
	window->setFramerateLimit(60);
}


void DrawingScreen::render(GameParameters *gameParameters)
{
	window->clear(sf::Color::Blue);

	gameParameters->printMousePos(window);

	window->display();
}
