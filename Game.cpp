#include "Game.h"
#include <iostream>

Game::Game()
{
	initWindow();
	initText();
	createBackground();
	deltaTime = 0.1;
	randomSpawnChance = 5;
	frame = 0;
}

Game::~Game()
{
	delete this->window;
}

void Game::gameUpdate()
{
	readMousePos();
	printMousePos();

	//create next generation after deltaTime
	if (clock.getElapsedTime().asSeconds() > deltaTime) {
		nextGeneration();
		clock.restart();
	}
	
}

void Game::initWindow()
{
	setVideoMode(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);

	window = new sf::RenderWindow(videoMode, "GAME OF LIFE",
		sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

	window->setFramerateLimit(60);
}


void Game::initText()
{
	if (font.loadFromFile(FONT_PATH)) {
		text.setString("NULL");
		text.setFont(font);
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::Green);
	}
	else std::cout << "ERROR: Game::initText() - font not loaded\n";
}


void Game::createBackground()
{
	Entity entity;
	entity.setSize(10.f);

	backgroundWidth = (int)window->getSize().x / (int)entity.getSize().x;
	backgroundHeight = (int)window->getSize().y / (int)entity.getSize().y;

	for (int j = 0; j < backgroundHeight; j ++) 
	{
		std::vector<Entity> row;
		for (int i = 0; i < backgroundWidth; i ++) 
		{
			entity.setPosition(sf::Vector2f(i * entity.getSize().x, j * entity.getSize().y));
			row.push_back(entity);
		}
		background.push_back(row);
	}
}

void Game::setVideoMode(int x, int y)
{
	videoMode.width = x;
	videoMode.height = y;
}

void Game::setRandomSpawnChance(int newValue)
{
	randomSpawnChance = newValue;
}


void Game::colorRandomEntities(sf::Color color)
{
	srand((unsigned)time(NULL));

	for (int i = 1; i < backgroundHeight - 1; i++) {
		for (int j = 1; j < backgroundWidth - 1; j++) {
			if ((rand() % 10000) <= randomSpawnChance && !background[i][j].getIsAlive()) {
				background[i][j].setColor(color);
				background[i][j].setIsAlive(true);

				for (int k = i - 1; k <= i + 1; k++) {
					for (int l = j - 1; l <= j + 1; l++) {
						if ((rand() % 100) <= 25) {
							background[k][l].setColor(color);
							background[k][l].setIsAlive(true);
						}
					}
				}
			}
		}
	}
}

void Game::nextGeneration()
{
	std::vector<std::vector<Entity>> newBackground(background);	//copy of background

	for (int i = 0; i < backgroundHeight; i++) 
	{
		for (int j = 0; j < backgroundWidth; j++) 
		{
			int adjacent = countAliveAdjacent(i, j);

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

int Game::countAliveAdjacent(int i, int j)
{
	int count = 0;
	
	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			if (k < 0 || k >= backgroundHeight || l < 0 || l >= backgroundWidth)
				continue;
			
			if (background[k][l].getIsAlive()) 
				count++;
		}
	}

	return count;
}

void Game::readMousePos()
{
	// trzeba takie coœ zrobiæ ¿eby zmienia³o siê wraz ze zmian¹ rozmiaru okna

	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);
}

void Game::printMousePos()
{
	std::stringstream ss;
	ss << "Mouse pos: " << (int)mousePos.x << " " << (int)mousePos.y << '\n'
		<< "Frame: " << frame++;
	text.setString(ss.str());
}

void Game::render()
{
	window->clear(sf::Color::White);

	for (int i = 0; i < backgroundHeight; i++) {
		for (int j = 0; j < backgroundWidth; j++) {
			if (background[i][j].getIsAlive())
				window->draw(background[i][j].getRect());
		}
	}

	window->draw(text);

	window->display();
}
