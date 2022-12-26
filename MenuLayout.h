#pragma once

#include "GameParameters.h"
#include "Button.h"

#define BUTTON_COLOR sf::Color(128, 128, 128)
#define BUTTON_SIZE sf::Vector2f(250, 75)

class MenuLayout
{
private:

	sf::Text txtTitle;
	Button* btnStart = new Button{ BUTTON_SIZE, BUTTON_COLOR, "START", sf::Vector2f(0, 0) };
	Button* btnOptions = new Button{ BUTTON_SIZE, BUTTON_COLOR, "OPTIONS", sf::Vector2f(0, 0) };
	Button* btnExit = new Button{ BUTTON_SIZE, BUTTON_COLOR, "EXIT", sf::Vector2f(0, 0) };

	std::vector<Button*> buttons = { btnStart, btnOptions, btnExit };

public:

	~MenuLayout();

	void renderLayout(GameParameters* gameParameters, sf::RenderWindow* window);
	void buttonsClicked(GameParameters* gameParameters, sf::RenderWindow* window, sf::Event event);
};

