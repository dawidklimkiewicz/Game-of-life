#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"

int main()
{
	Menu menu;

	while (menu.window->isOpen())
	{
		
		menu.pollEvents();
		menu.update();
		menu.render();
	}

	Game game;
	game.setRandomSpawnChance(500);
	game.colorRandomEntities();

	while (game.window->isOpen())
	{
		sf::Event event;
		while (game.window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game.window->close();
		}

	
		game.gameUpdate();
		game.render();
	}
}