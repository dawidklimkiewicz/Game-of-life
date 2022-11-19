#pragma once

#include <sstream>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameParameters.h"

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"
#define DEFAULT_SCREEN_WIDTH 1200
#define DEFAULT_SCREEN_HEIGHT 900

class DrawingScreen
{
private:

	sf::Font font;
	sf::Text txtMousePos;

public:
	sf::RenderWindow* window;

	DrawingScreen(GameParameters* gameParameters);
	~DrawingScreen();

	void update(GameParameters* gameParameters);
	void pollEvents();

	void initWindow(GameParameters* gameParameters);
	
	void render(GameParameters* gameParameters);

};

