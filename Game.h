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
	std::vector<std::vector<Entity>> background;

	sf::Clock clock;

	int frame;
	

public:
	sf::RenderWindow *window;

	Game(GameParameters* gameParameters);
	~Game();

	//updates state of the app

	void pollEvents();
	void gameUpdate(GameParameters* gameParameters);

	//init functions, to be called once at the start

	void initWindow(GameParameters* gameParameters);
	void createBackground(GameParameters* gameParameters);	//create a vector containing entities with their positions

	void colorRandomEntities(GameParameters* gameParameters, sf::Color color = sf::Color::Black);	//spawn random blobs of entities
	void nextGeneration(GameParameters* gameParameters);		//next iteration of the simulation
	int countAliveAdjacent(GameParameters* gameParameters, int i, int j);

	void render(GameParameters* gameParameters);
};

