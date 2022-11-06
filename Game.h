#pragma once

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"
#define DEFAULT_SCREEN_WIDTH 1200
#define DEFAULT_SCREEN_HEIGHT 900

#include <sstream>
#include <vector>
#include <time.h>
#include <map>

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Game
{
private:
	std::vector<std::vector<Entity>> background;
	sf::Text text;
	sf::Font font;

	sf::Clock clock;
	sf::VideoMode videoMode;
	sf::Vector2f mousePos;

	int frame;
	int randomSpawnChance;	//used in colorRandomEntities()
	int backgroundWidth;	//vector size based on screen and entity size
	int backgroundHeight;
	float deltaTime;
	

public:
	sf::RenderWindow *window;

	Game();
	~Game();

	//updates state of the app

	void gameUpdate();

	//init functions, to be called once at the start

	void initWindow();
	void initText();
	void createBackground();	//create a vector containing entities with their positions

	void setVideoMode(int x, int y);
	void setRandomSpawnChance(int newValue);

	void readMousePos();

	void colorRandomEntities(sf::Color color = sf::Color::Black);	//spawn random blobs of entities
	void nextGeneration();		//next iteration of the simulation
	int countAliveAdjacent(int i, int j);
	void printMousePos();
	void render();
};

