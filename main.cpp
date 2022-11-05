#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game;
	game.setRandomSpawnChance(7);
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