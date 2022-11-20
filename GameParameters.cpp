#include "GameParameters.h"

GameParameters::GameParameters()
{
	deltaTime = 0.1;
	gameSize = 90;
	randomSpawnChance = 5;
	chanceSpawnAround = 25;
	videoMode.width = 900;
	videoMode.height = 900;
}

void GameParameters::initFont(sf::Text& txt)
{
	if (font.loadFromFile(FONT_PATH)) {
		txt.setString("NULL");
		txt.setFont(font);
		txt.setCharacterSize(32);
		txt.setFillColor(sf::Color::Black);
	}
	else std::cout << "ERROR: Game::initText() - font not loaded\n";
}

void GameParameters::setVideoMode()
{
	videoMode.width = gameSize;
	videoMode.height = gameSize;
}

void GameParameters::readMousePos(sf::RenderWindow *window)
{

	// trzeba takie coœ zrobiæ ¿eby zmienia³o siê wraz ze zmian¹ rozmiaru okna

	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);
}

void GameParameters::printMousePos(sf::RenderWindow *window)
{
	std::stringstream ss;
	initFont(mousePosText);
	mousePosText.setCharacterSize(30);
	mousePosText.setFillColor(sf::Color::Green);

	ss << "Mouse pos: " << (int)mousePos.x << " " << (int)mousePos.y << '\n';
	mousePosText.setString(ss.str());

	window->draw(mousePosText);
}
