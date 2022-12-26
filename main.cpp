#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Options.h"
#include "DrawingScreen.h"
#include "Menu.h"
#include "GameParameters.h"
#include "Icon.h"

int main()
{
	GameParameters *gameParameters = new GameParameters;
	sf::RenderWindow *window = new sf::RenderWindow(gameParameters->videoMode, "GAME OF LIFE");

	// ustawienie ikony
	sf::Image icon;
	icon.loadFromMemory(logo_png, logo_png_len);
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Menu menu(gameParameters, window);
	Options options(gameParameters, window);
	DrawingScreen drawing(gameParameters, window);
	drawing.colorRandomEntities();
	Game game(gameParameters, window);
	
	

	while (gameParameters->gameState >= 0)
	{
		if (gameParameters->gameState == 0)
		{
			while (menu.isOpen())
			{
				menu.update();
				menu.render();
			}
		}


		if (gameParameters->gameState == 3)
		{
			while (options.isOpen())
			{
				options.update();
				options.render();
			}
		}


		if (gameParameters->gameState == 1)
		{
			if (gameParameters->optionsChanged)
			{
				DrawingScreen drawing(gameParameters, window);
				gameParameters->drawingScreenOpened = true;

				drawing.colorRandomEntities();

				while (drawing.isOpen())
				{
					drawing.update();
					drawing.render();
				}

				gameParameters->optionsChanged = false;
			}
			else
			{
				while (drawing.isOpen())
				{
					drawing.update();
					drawing.render();
				}
			}

		}


		if (gameParameters->gameState == 2)
		{
			while (game.isOpen())
			{
				game.gameUpdate();
				game.render();
			}
		}
	}


	delete gameParameters;
	delete window;

	return 0;
}