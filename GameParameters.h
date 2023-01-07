#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Font.h"


class GameParameters
{
private:
	

public:
	GameParameters();

	sf::VideoMode videoMode;
	sf::Vector2f mousePos;
	sf::Font font;

	bool optionsChanged;
	bool menuOpened;
	bool optionsOpened;
	bool gameOpened;

	float deltaTime;
	unsigned gameSize;
	int gameState;
	int randomSpawnChance;
	int chanceSpawnAround;
	int currentX;
	int currentY;
	std::vector<std::vector<Entity>> background;

	void initFont(sf::Text& txt);

	void readMousePos(sf::RenderWindow* window);
};
