#include "Game.h"
#include <iostream>

Game::Game(GameParameters* parameters, sf::RenderWindow* window)
{
	gameParameters = parameters;
	this->window = window;
	generationCounter = 0;
	showGenerationCounter = false;
	paused = false;
	gameParameters->gameOpened = true;
}

Game::~Game()
{

}

void Game::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Enter)
				gameParameters->gameOpened = false;

			if (event.key.code == sf::Keyboard::Space)
				paused = !paused;

			if (event.key.code == sf::Keyboard::G)
				showGenerationCounter = !showGenerationCounter;
		}

	}
}

void Game::gameUpdate()
{
	pollEvents();
	gameParameters->readMousePos(window);

	//create next generation after deltaTime
	if (!paused && clock.getElapsedTime().asSeconds() > gameParameters->deltaTime) {
		nextGeneration();
		generationCounter++;
		clock.restart();
	}
	
}


bool Game::isOpen()
{
	return gameParameters->gameOpened;
}

void Game::nextGeneration()
{
	std::vector<std::vector<Entity>> newBackground(gameParameters->background);	//copy of background

	for (unsigned i = 0; i < gameParameters->gameSize; i++)
	{
		for (unsigned j = 0; j < gameParameters->gameSize; j++)
		{
			int adjacent = countAliveAdjacent(i, j);

			if (gameParameters->background[i][j].getIsAlive() && (adjacent - 1 == 2 || adjacent - 1 == 3)) {
				continue;
			}

			else if (!gameParameters->background[i][j].getIsAlive() && adjacent == 3) {
				newBackground[i][j].setIsAlive(true);
				newBackground[i][j].setColor(sf::Color::Black);
			} 

			
			else {
				newBackground[i][j].setIsAlive(false);
				newBackground[i][j].setColor(sf::Color::White);
			}
		}
	}

	gameParameters->background = newBackground;
}

int Game::countAliveAdjacent(int i, int j)
{
	int count = 0;
	
	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			if (k < 0 || k >= gameParameters->gameSize || l < 0 || l >= gameParameters->gameSize)
				continue;
			
			if (gameParameters->background[k][l].getIsAlive())
				count++;
		}
	}

	return count;
}


void Game::render()
{
	window->clear(sf::Color::White);

	for (unsigned i = 0; i < gameParameters->gameSize; i++) {
		for (unsigned j = 0; j < gameParameters->gameSize; j++) {
			if (gameParameters->background[i][j].getIsAlive())
				window->draw(gameParameters->background[i][j].getRect());
		}
	}

	if (showGenerationCounter) 
		renderGenerationCounter();

	window->display();
}

void Game::renderGenerationCounter()
{
	std::stringstream ss;
	ss.str("");
	ss << "Generation: " << generationCounter;
	sf::Text genText;
	gameParameters->initFont(genText);
	genText.setString(ss.str());
	genText.setPosition(10, window->getSize().y - genText.getGlobalBounds().height * 2);
	genText.setFillColor(sf::Color::White);
	genText.setOutlineColor(sf::Color::Black);
	genText.setOutlineThickness(1);
	window->draw(genText);
}
