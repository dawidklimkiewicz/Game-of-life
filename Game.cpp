#include "Game.h"
#include <iostream>

Game::Game(GameParameters* gameParameters)
{
	initWindow(gameParameters);
	createBackground(gameParameters);
	frame = 0;
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::gameUpdate(GameParameters* gameParameters)
{
	pollEvents();
	gameParameters->readMousePos(window);

	//create next generation after deltaTime
	if (clock.getElapsedTime().asSeconds() > gameParameters->deltaTime) {
		nextGeneration(gameParameters);
		clock.restart();
	}
	
}

void Game::initWindow(GameParameters* gameParameters)
{
	window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");

	window->setFramerateLimit(60);
}


void Game::createBackground(GameParameters* gameParameters)
{
	Entity entity;
	entity.setSize(sf::Vector2f(gameParameters->videoMode.width / (float)gameParameters->gameSize,
		gameParameters->videoMode.height / (float)gameParameters->gameSize));


	for (unsigned j = 0; j < gameParameters->gameSize; j ++)
	{
		std::vector<Entity> row;
		for (unsigned i = 0; i < gameParameters->gameSize; i ++)
		{
			entity.setPosition(sf::Vector2f(i * entity.getSize().x, j * entity.getSize().y));
			row.push_back(entity);
		}
		background.push_back(row);
	}
}


void Game::colorRandomEntities(GameParameters *gameParameters, sf::Color color)
{
	srand((unsigned)time(NULL));

	for (unsigned i = 1; i < gameParameters->gameSize - 1; i++) {
		for (unsigned j = 1; j < gameParameters->gameSize - 1; j++) {
			if ((rand() % 100) <= gameParameters->randomSpawnChance && !background[i][j].getIsAlive()) {
				background[i][j].setColor(color);
				background[i][j].setIsAlive(true);

				for (unsigned k = i - 1; k <= i + 1; k++) {
					for (unsigned l = j - 1; l <= j + 1; l++) {
						if ((rand() % 100) < gameParameters->chanceSpawnAround) {
							background[k][l].setColor(color);
							background[k][l].setIsAlive(true);
						}
					}
				}
			}
		}
	}
}

void Game::nextGeneration(GameParameters* gameParameters)
{
	std::vector<std::vector<Entity>> newBackground(background);	//copy of background

	for (unsigned i = 0; i < gameParameters->gameSize; i++)
	{
		for (unsigned j = 0; j < gameParameters->gameSize; j++)
		{
			int adjacent = countAliveAdjacent(gameParameters, i, j);

			if (background[i][j].getIsAlive() && (adjacent - 1 == 2 || adjacent - 1 == 3)) {
				continue;
			}

			else if (!background[i][j].getIsAlive() && adjacent == 3) {
				newBackground[i][j].setIsAlive(true);
				newBackground[i][j].setColor(sf::Color::Black);
			} 

			
			else {
				newBackground[i][j].setIsAlive(false);
				newBackground[i][j].setColor(sf::Color::White);
			}
		}
	}

	background = newBackground;
}

int Game::countAliveAdjacent(GameParameters* gameParameters, int i, int j)
{
	int count = 0;
	
	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			if (k < 0 || k >= gameParameters->gameSize || l < 0 || l >= gameParameters->gameSize)
				continue;
			
			if (background[k][l].getIsAlive()) 
				count++;
		}
	}

	return count;
}


void Game::render(GameParameters* gameParameters)
{
	window->clear(sf::Color::White);

	for (unsigned i = 0; i < gameParameters->gameSize; i++) {
		for (unsigned j = 0; j < gameParameters->gameSize; j++) {
			if (background[i][j].getIsAlive())
				window->draw(background[i][j].getRect());
		}
	}

	gameParameters->printMousePos(window);
	window->display();
}
