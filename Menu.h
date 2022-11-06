#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"

class Menu
{
private:

	sf::VideoMode videoMode;
	sf::Font font;	
	sf::Vector2f mousePos;
	sf::Text mouse;

	Button button {sf::Vector2f(200, 100), sf::Color::Black, "teST", sf::Vector2f(500, 500)};

public:
	sf::RenderWindow* window;

	Menu();
	~Menu();

	void update();
	void pollEvents();

	void initWindow();
	void initFont();
	void setVideoMode(int width, int height);
	
	sf::Vector2f getMousePos();

	void render();

	void printMousePos();
};

