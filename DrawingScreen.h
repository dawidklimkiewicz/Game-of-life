#pragma once

#include <sstream>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameParameters.h"


class DrawingScreen
{
private:
	sf::RenderWindow* window;
	GameParameters *gameParameters;

public:
	
	DrawingScreen(GameParameters* parameters, sf::RenderWindow* window);

	bool isOpen();
	void update();
	void pollEvents();
	void colorAndErase();		// lewy przycisk - dodanie pola, prawy - usuniecie

	void createBackground();
	void colorRandomEntities();
	
	void render();

};

