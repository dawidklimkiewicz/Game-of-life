#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

#define FONT_PATH "Fonts/Roboto-Regular.ttf"

class GameParameters
{
private:
	

public:
	sf::VideoMode videoMode;
	sf::Vector2f mousePos;
	sf::Font font;
	sf::Text mousePosText;

	

	float deltaTime;
	unsigned gameSize;
	int randomSpawnChance;
	int chanceSpawnAround;
	std::vector<std::vector<Entity>> background;

	GameParameters();
	void initFont(sf::Text& txt);

	void setVideoMode();

	void readMousePos(sf::RenderWindow* window);
	void printMousePos(sf::RenderWindow* window);

};
