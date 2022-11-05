#include "Game.h"
#include <iostream>

Game::Game()
{
	initWindow();
	initText();
	createBackground();
	randomSpawnChance = 5;
	frame = 0;
}

Game::~Game()
{
	delete this->window;
}

void Game::gameUpdate()
{
	getMousePos();
	printMousePos();
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
	entity.setSize(10.f, 10.f);

	for (int i = 0; i < window->getSize().x; i += entity.getSize().x) {
		std::vector<Entity> row;
		for (int j = 0; j < window->getSize().y; j += entity.getSize().y) {
			entity.setPosition(sf::Vector2f(i, j));
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
	if (newValue > 100) newValue = 100;
	if (newValue < 0)	newValue = 0;

	randomSpawnChance = newValue;
}


void Game::getMousePos()
{
	// trzeba takie coœ zrobiæ ¿eby zmienia³o siê wraz ze zmian¹ rozmiaru okna

	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);
}


void Game::colorRandomEntities(sf::Color color)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < background.size(); i++) {
		for (int j = 0; j < background[i].size(); j++) {
			if ((rand() % 100) <= randomSpawnChance && !background[i][j].getIsAlive()) {
				background[i][j].setColor(color);
				background[i][j].setIsAlive(true);
			}	
		}
	}
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

	for (int i = 0; i < background.size(); i++) {
		for (int j = 0; j < background[i].size(); j++) {
			if (background[i][j].getIsAlive())
				window->draw(background[i][j].getRect());
		}
	}
	window->draw(text);

	window->display();
}
