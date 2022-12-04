#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameParameters.h"
#include "MenuLayout.h"


class Menu
{
private:

	GameParameters* gameParameters;
	MenuLayout menuLayout;

public:
	sf::RenderWindow* window;

	Menu(GameParameters* parameters, sf::RenderWindow *window);
	~Menu();

	bool isOpen();
	void update();
	void pollEvents();

	void render();
};

