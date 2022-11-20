#pragma once

#include <sstream>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "GameParameters.h"


class DrawingScreen
{
private:

public:
	sf::RenderWindow* window;

	DrawingScreen(GameParameters* gameParameters);
	~DrawingScreen();

	void update(GameParameters* gameParameters);
	void pollEvents(GameParameters* gameParameters);
	void colorAndErase(GameParameters* gameParameters);

	void initWindow(GameParameters* gameParameters);
	void createBackground(GameParameters* gameParameters);
	void colorRandomEntities(GameParameters* gameParameters, sf::Color color = sf::Color::Black);
	
	void render(GameParameters* gameParameters);

};

