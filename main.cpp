#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "DrawingScreen.h"
#include "GameParameters.h"

int main()
{
	GameParameters *gameParameters = new GameParameters;

	Menu menu(gameParameters);
	while (menu.window->isOpen())
	{
		menu.update(gameParameters);
		menu.render(gameParameters);
	}


	DrawingScreen drawing(gameParameters);
	drawing.colorRandomEntities(gameParameters);
	while (drawing.window->isOpen())
	{
		drawing.update(gameParameters);
		drawing.render(gameParameters);
	}


	Game game(gameParameters);

	while (game.window->isOpen())
	{
		game.gameUpdate(gameParameters);
		game.render(gameParameters);
	}

	delete gameParameters;
}