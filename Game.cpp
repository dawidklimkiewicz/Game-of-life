#include "Game.h"
#include "Shapes.h"
#include <iostream>

Game::Game(GameParameters* parameters, sf::RenderWindow* window)
{
	gameParameters = parameters;
	this->window = window;

	generationCounter = 0;
	shapeSelected = -1;
	showGenerationCounter = false;
	paused = true;
	gameParameters->gameOpened = false;

	createBackground();
}

bool Game::isOpen()
{
	return gameParameters->gameOpened;
}

void Game::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameParameters->gameState = -1;
			gameParameters->gameOpened = false;
			window->close();
		}

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Backspace) {
				paused = true;
				gameParameters->gameOpened = false;
				gameParameters->menuOpened = true;
				gameParameters->gameState = 0;
			}

			if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
				paused = !paused;

			if (event.key.code == sf::Keyboard::G)
				showGenerationCounter = !showGenerationCounter;

		}

		// wczytanie numeru 0-9 jako -1 do 8 ze wzgledu na konstrukcje tablicy shapes

		if (event.type == sf::Event::TextEntered) {
			wchar_t ch = event.text.unicode - 48;
			if (ch >= 0 && ch <= 9) {
				shapeSelected = static_cast<int>(ch) - 1;
			}
		}


		// narysowanie ksztaltu bez przytrzymywania myszy

		if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left
			&& shapeSelected != -1) {

			int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
			int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

			for (int k = 0; k < shapeSize; k++) {
				for (int l = 0; l < shapeSize; l++) {
					if (shapes[shapeSelected][k][l]) {
						int x = wrap(i+k);
						int y = wrap(j+l);

						gameParameters->background[x][y].setIsAlive(true);
					}

				}
			}
		}

	}
}

void Game::update()
{
	pollEvents();
	gameParameters->readMousePos(window);
	colorAndErase();

	//create next generation after deltaTime
	if (!paused && clock.getElapsedTime().asSeconds() > gameParameters->deltaTime) {
		nextGeneration();
		generationCounter++;
		clock.restart();
	}
	
}

void Game::colorAndErase()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		unsigned int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		unsigned int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		if (i >= 0 && j >= 0 && i < gameParameters->gameSize && j < gameParameters->gameSize)
		{
			if (shapeSelected == -1) {
				gameParameters->background[i][j].setIsAlive(true);
			}
		}
			
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		unsigned int i = gameParameters->mousePos.y / gameParameters->background[0][0].getSize().y;
		unsigned int j = gameParameters->mousePos.x / gameParameters->background[0][0].getSize().x;

		if (i >= 0 && j >= 0 && i < gameParameters->gameSize && j < gameParameters->gameSize)
			gameParameters->background[i][j].setIsAlive(false);
	}

}


void Game::nextGeneration()
{
	std::vector<std::vector<Entity>> newBackground(gameParameters->background);	//copy background

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
			} 

			
			else {
				newBackground[i][j].setIsAlive(false);
			}
		}
	}

	gameParameters->background = newBackground;
}

int Game::wrap(int a)
{
	if (a < 0) {
		return gameParameters->gameSize + a;
	}

	if (a >= gameParameters->gameSize) {
		return a - gameParameters->gameSize;
	}

	else {
		return a;
	}
}

int Game::countAliveAdjacent(int i, int j)
{
	int count = 0;
	
	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			
			int x = wrap(k);
			int y = wrap(l);

			if (gameParameters->background[x][y].getIsAlive())
				count++;
		}
	}

	return count;
}

void Game::createBackground()
{
	// czyszczenie wektora na wypadek zmiany rozmiaru
	gameParameters->background.clear();

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

void Game::colorRandomEntities()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < gameParameters->gameSize; i++) {
		for (int j = 0; j < gameParameters->gameSize; j++) {
			if ((rand() % 100) < gameParameters->randomSpawnChance && !gameParameters->background[i][j].getIsAlive()) {
				gameParameters->background[i][j].setIsAlive(true);

				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if ((rand() % 100) < gameParameters->chanceSpawnAround) {

							int x = wrap(k);
							int y = wrap(l);
							gameParameters->background[x][y].setIsAlive(true);
						}
					}
				}
			}
		}
	}
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
