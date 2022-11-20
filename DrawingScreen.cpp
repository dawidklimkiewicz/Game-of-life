#include "DrawingScreen.h"

DrawingScreen::DrawingScreen(GameParameters* gameParameters)
{
	initWindow(gameParameters);
	createBackground(gameParameters);
}


DrawingScreen::~DrawingScreen()
{
	delete window;
}


void DrawingScreen::update(GameParameters *gameParameters)
{
	pollEvents(gameParameters);
	gameParameters->readMousePos(window);
	colorAndErase(gameParameters);
}


void DrawingScreen::pollEvents(GameParameters* gameParameters)
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
		
	}
}


void DrawingScreen::colorAndErase(GameParameters* gameParameters)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		gameParameters->background[i][j].setColor(sf::Color::Black);
		gameParameters->background[i][j].setIsAlive(true);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		gameParameters->background[i][j].setIsAlive(false);
	}
}


void DrawingScreen::initWindow(GameParameters* gameParameters)
{
	window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");
}


void DrawingScreen::createBackground(GameParameters* gameParameters)
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


void DrawingScreen::colorRandomEntities(GameParameters* gameParameters, sf::Color color)
{
	srand((unsigned)time(NULL));

	for (unsigned i = 1; i < gameParameters->gameSize - 1; i++) {
		for (unsigned j = 1; j < gameParameters->gameSize - 1; j++) {
			if ((rand() % 100) < gameParameters->randomSpawnChance && !gameParameters->background[i][j].getIsAlive()) {
				gameParameters->background[i][j].setColor(color);
				gameParameters->background[i][j].setIsAlive(true);

				for (unsigned k = i - 1; k <= i + 1; k++) {
					for (unsigned l = j - 1; l <= j + 1; l++) {
						if ((rand() % 100) < gameParameters->chanceSpawnAround) {
							gameParameters->background[k][l].setColor(color);
							gameParameters->background[k][l].setIsAlive(true);
						}
					}
				}
			}
		}
	}
}


void DrawingScreen::render(GameParameters *gameParameters)
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
