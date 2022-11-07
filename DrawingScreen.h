#pragma once

#include <sstream>

#include <SFML/Graphics.hpp>

#include "Button.h"

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"
#define DEFAULT_SCREEN_WIDTH 1200
#define DEFAULT_SCREEN_HEIGHT 900

class DrawingScreen
{
private:

	unsigned gameSize;

	sf::VideoMode videoMode;
	sf::Vector2f mousePos;
	sf::Font font;
	sf::Text txtMousePos;

public:
	sf::RenderWindow* window;

	DrawingScreen();
	~DrawingScreen();

	void update();
	void pollEvents();

	void initWindow();
	void initFont();
	void initText(sf::Text &text, std::string str = "NULL", unsigned size = 30, sf::Color color = sf::Color::Black);
	void setVideoMode();
	void setGameSize(unsigned size);

	void readMousePos();
	void printMousePos();
	
	void render();

};

