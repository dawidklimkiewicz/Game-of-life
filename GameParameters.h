#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Font.h"

//#define FONT_PATH "Fonts/Roboto-Regular.ttf"

class GameParameters
{
private:
	

public:
	GameParameters();

	sf::VideoMode videoMode;
	sf::Vector2f mousePos;
	sf::Font font;
	sf::Text mousePosText;

	bool menuOpened;
	bool drawingScreenOpened;
	bool gameOpened;

	float deltaTime;
	unsigned gameSize;
	unsigned gameState;
	int randomSpawnChance;
	int chanceSpawnAround;
	std::vector<std::vector<Entity>> background;

	void initFont(sf::Text& txt);

	void readMousePos(sf::RenderWindow* window);
	void printMousePos(sf::RenderWindow* window);

};
