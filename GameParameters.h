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

	bool optionsChanged;	// czy zrobiono zmiany w opcjach
							// jezeli nie to uklad pozostaje bez zmian
							// jezeli tak to trzeba stworzyc nowy uklad
	bool menuOpened;
	bool optionsOpened;
	bool drawingScreenOpened;
	bool gameOpened;

	float deltaTime;
	unsigned gameSize;
	int gameState;
	int randomSpawnChance;
	int chanceSpawnAround;
	std::vector<std::vector<Entity>> background;

	void initFont(sf::Text& txt);

	void readMousePos(sf::RenderWindow* window);
	void printMousePos(sf::RenderWindow* window);

};
