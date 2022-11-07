#pragma once

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"
#define DEFAULT_SCREEN_WIDTH 900.0
#define DEFAULT_SCREEN_HEIGHT 900.0

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
	float randomSpawnChance;	//used in colorRandomEntities()
	float chanceSpawnAround;
	int backgroundWidth;	//vector size based on screen and entity size
	int backgroundHeight;
	float deltaTime;
	

public:
	sf::RenderWindow *window;

	Game(int width = 90, int height = 90);
	~Game();

	//updates state of the app

	void pollEvents();
	void gameUpdate();

	//init functions, to be called once at the start

	void initWindow();
	void initText();
	void createBackground();	//create a vector containing entities with their positions

	void setVideoMode(int x, int y);
	void setRandomSpawnChance(float newValue);
	void setChanceSpawnAround(float newValue);
	void setDeltaTime(float newValue);

	void readMousePos();

	void colorRandomEntities(sf::Color color = sf::Color::Black);	//spawn random blobs of entities
	void nextGeneration();		//next iteration of the simulation
	int countAliveAdjacent(int i, int j);
	void printMousePos();
	void render();
};

