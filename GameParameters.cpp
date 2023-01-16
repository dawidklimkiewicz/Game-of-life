#include "GameParameters.h"

GameParameters::GameParameters()
{
	deltaTime = 0.1f;
	gameSize = 100;
	randomSpawnChance = 5;
	chanceSpawnAround = 25;

	videoMode.width = 900;
	videoMode.height = 900;
	gameState = 0;
	currentX = 0;
	currentY = 0;

	optionsChanged = false;
	menuOpened = false;
	optionsOpened = false;
	gameOpened = false;
}

void GameParameters::initFont(sf::Text& txt)
{
	if (font.loadFromMemory(&Roboto_Regular_ttf, Roboto_Regular_ttf_len)) {
		txt.setString("NULL");
		txt.setFont(font);
		txt.setCharacterSize(30);
		txt.setFillColor(sf::Color::Black);
	}
	else std::cout << "ERROR: Game::initText() - font not loaded\n";
}


void GameParameters::readMousePos(sf::RenderWindow *window)
{
	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);
}

