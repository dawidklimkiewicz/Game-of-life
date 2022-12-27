#pragma once

#include <sstream>
#include <vector>
#include <time.h>
#include <map>

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "GameParameters.h"

class Game
{
private:
	
	sf::Clock clock;
	GameParameters* gameParameters;

	int shapeSelected;
	int generationCounter;
	bool showGenerationCounter;
	bool paused;

public:
	sf::RenderWindow *window;

	Game(GameParameters* parameters, sf::RenderWindow* window);

	bool isOpen();
	void pollEvents();
	void update();
	void colorAndErase();


	void nextGeneration();
	int wrap(int a);
	int countAliveAdjacent(int i, int j);
	void createBackground();
	void colorRandomEntities();

	void render();
	void renderGenerationCounter();
};

