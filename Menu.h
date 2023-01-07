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
	sf::RenderWindow* window;

public:

	Menu(GameParameters* parameters, sf::RenderWindow* window);

	bool isOpen();
	void update();
	void pollEvents();

	void render();
};

