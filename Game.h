#pragma once

#define FONT_PATH "Fonts/Roboto-Regular.ttf"

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

	int generationCounter;
	bool showGenerationCounter;
	bool paused;

public:
	sf::RenderWindow *window;

	Game(GameParameters* parameters, sf::RenderWindow* window);
	~Game();

	//updates state of the app

	void pollEvents();
	void gameUpdate();


	bool isOpen();
	void nextGeneration();		//next iteration of the simulation
	int countAliveAdjacent(int i, int j);

	void render();
	void renderGenerationCounter();
};

