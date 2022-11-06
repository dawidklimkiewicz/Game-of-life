#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"

#define FONT_PATH "Fonts/ComicNeue-Regular.ttf"
#define DEFAULT_SCREEN_WIDTH 1200
#define DEFAULT_SCREEN_HEIGHT 900
#define BUTTON_COLOR sf::Color(128, 128, 128)

class Menu
{
private:

	sf::VideoMode videoMode;
	sf::Vector2f mousePos;
	sf::Font font;
	sf::Text mouse;
	
	unsigned gameSize;
	sf::Text txtGameSize;
	Button btnSizeMore{ sf::Vector2f(100, 100), BUTTON_COLOR, "+1", sf::Vector2f(700, 175) };
	Button btnSizeMore2{ sf::Vector2f(100, 100), BUTTON_COLOR, "+10", sf::Vector2f(850, 175) };
	Button btnSizeLess{ sf::Vector2f(100, 100), BUTTON_COLOR, "-1", sf::Vector2f(250, 175) };
	Button btnSizeLess2{ sf::Vector2f(100, 100), BUTTON_COLOR, "-10", sf::Vector2f(400, 175) };

	float deltaTime;
	sf::Text txtDeltaTime;
	Button btnDeltaTimeMore{ sf::Vector2f(100, 100), BUTTON_COLOR, "+0.05", sf::Vector2f(700, 300) };
	Button btnDeltaTimeMore2{ sf::Vector2f(100, 100), BUTTON_COLOR, "+0.5", sf::Vector2f(850, 300) };
	Button btnDeltaTimeLess{ sf::Vector2f(100, 100), BUTTON_COLOR, "-0.05", sf::Vector2f(250, 300) };
	Button btnDeltaTimeLess2{ sf::Vector2f(100, 100), BUTTON_COLOR, "-0.5", sf::Vector2f(400, 300) };

	//vector dla przyciskow??
	

public:
	sf::RenderWindow* window;

	Menu();
	~Menu();

	void update();
	void pollEvents();

	void initWindow();
	void initFont(sf::Text &txt);
	void setVideoMode(int width, int height);
	
	sf::Vector2f getMousePos();

	void render();
	void renderLayout();

	void printMousePos();
};

