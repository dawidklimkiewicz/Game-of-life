#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "Options.h"
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
	Game game(gameParameters, window);
	game.colorRandomEntities();


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


		if (gameParameters->gameState == 1)
		{
			// stworz nowy obiekt Game jezeli dokonano zmian ustawien
			if (gameParameters->optionsChanged)
			{
				Game game(gameParameters, window);
				gameParameters->gameOpened = true;

				game.colorRandomEntities();

				while (game.isOpen())
				{
					game.update();
					game.render();
				}

				gameParameters->optionsChanged = false;
			}
			else
			{
				while (game.isOpen())
				{
					game.update();
					game.render();
				}
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
	}


	delete gameParameters;
	delete window;


	return 0;
}