#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "DrawingScreen.h"
#include "GameParameters.h"

int main()
{
	GameParameters *gameParameters = new GameParameters;
	sf::RenderWindow *window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");


	if (gameParameters->gameState == 0)
	{
		Menu menu(gameParameters, window);
		while (menu.isOpen())
		{
			menu.update();
			menu.render();
		}
		gameParameters->gameState++;
	}


	if (gameParameters->gameState == 1)
	{
		DrawingScreen drawing(gameParameters, window);
		drawing.colorRandomEntities();

		while (drawing.isOpen())
		{
			drawing.update();
			drawing.render();
		}
		gameParameters->gameState++;
	}


	if (gameParameters->gameState == 2)
	{
		Game game(gameParameters, window);
		while (game.isOpen())
		{
			game.gameUpdate();
			game.render();
		}
		gameParameters->gameState++;
	}


	delete gameParameters;
	delete window;
}