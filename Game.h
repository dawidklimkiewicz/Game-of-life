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

	int generationCounter;
	bool showGenerationCounter;
	bool paused;

public:
	sf::RenderWindow *window;

	Game(GameParameters* gameParameters);
	~Game();

	//updates state of the app

	void pollEvents(GameParameters* gameParameters);
	void gameUpdate(GameParameters* gameParameters);

	//init functions, to be called once at the start

	void initWindow(GameParameters* gameParameters);

	void nextGeneration(GameParameters* gameParameters);		//next iteration of the simulation
	int countAliveAdjacent(GameParameters* gameParameters, int i, int j);

	void render(GameParameters* gameParameters);
	void renderGenerationCounter(GameParameters* gameParameters);
};

