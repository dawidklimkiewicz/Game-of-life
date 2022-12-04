#include "DrawingScreen.h"

DrawingScreen::DrawingScreen(GameParameters* parameters, sf::RenderWindow* window)
{
	gameParameters = parameters;
	this->window = window;
	createBackground();
	gameParameters->drawingScreenOpened = true;
}


bool DrawingScreen::isOpen()
{
	return gameParameters->drawingScreenOpened;
}

void DrawingScreen::update()
{
	pollEvents();
	gameParameters->readMousePos(window);
	colorAndErase();
}


void DrawingScreen::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space)
				gameParameters->drawingScreenOpened = false;
		}
		
	}
}


void DrawingScreen::colorAndErase()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		gameParameters->background[i][j].setIsAlive(true);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		gameParameters->background[i][j].setIsAlive(false);
	}
}


void DrawingScreen::createBackground()
{
	Entity entity;
	entity.setSize(sf::Vector2f(window->getSize().x / (float)gameParameters->gameSize,
		window->getSize().y / (float)gameParameters->gameSize));


	for (unsigned j = 0; j < gameParameters->gameSize; j++)
	{
		std::vector<Entity> row;
		for (unsigned i = 0; i < gameParameters->gameSize; i++)
		{
			entity.setPosition(sf::Vector2f(i * entity.getSize().x, j * entity.getSize().y));
			row.push_back(entity);
		}
		gameParameters->background.push_back(row);
	}
}


void DrawingScreen::colorRandomEntities()
{
	srand((unsigned)time(NULL));

	for (unsigned i = 1; i < gameParameters->gameSize - 1; i++) {
		for (unsigned j = 1; j < gameParameters->gameSize - 1; j++) {
			if ((rand() % 100) < gameParameters->randomSpawnChance && !gameParameters->background[i][j].getIsAlive()) {
				gameParameters->background[i][j].setIsAlive(true);

				for (unsigned k = i - 1; k <= i + 1; k++) {
					for (unsigned l = j - 1; l <= j + 1; l++) {
						if ((rand() % 100) < gameParameters->chanceSpawnAround) {
							gameParameters->background[k][l].setIsAlive(true);
						}
					}
				}
			}
		}
	}
}


void DrawingScreen::render()
{
	window->clear(sf::Color::White);

	for (unsigned i = 0; i < gameParameters->gameSize; i++) {
		for (unsigned j = 0; j < gameParameters->gameSize; j++) {
			if (gameParameters->background[i][j].getIsAlive())
				window->draw(gameParameters->background[i][j].getRect());
		}
	}

	window->display();
}
