#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameParameters.h"
#include "MenuLayout.h"


class Menu
{
private:

	MenuLayout menuLayout;
	

public:
	sf::RenderWindow* window;

	Menu(GameParameters* gameParameters);
	~Menu();

	void update(GameParameters *gameParameters);
	void pollEvents(GameParameters* gameParameters);

	void initWindow(GameParameters* gameParameters);


	void render(GameParameters* gameParameters);
};

