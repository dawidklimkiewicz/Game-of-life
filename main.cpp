#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Menu.h"
#include "DrawingScreen.h"

int main()
{
	Menu menu;
	unsigned gameSize = 90;
	int randomSpawnChance = 5;
	int chanceSpawnAround = 25;
	float deltaTime = 0.1;

	while (menu.window->isOpen())
	{
		menu.pollEvents();
		menu.update();
		menu.render();

		gameSize = menu.getGameSize();
		randomSpawnChance = menu.getRandomSpawnChance();
		chanceSpawnAround = menu.getChanceSpawnAround();
		deltaTime = menu.getDeltaTime();

	}

	DrawingScreen drawing;

	while (drawing.window->isOpen())
	{
		drawing.update();
	}

	Game game(gameSize, gameSize);
	game.setRandomSpawnChance(randomSpawnChance);
	game.setChanceSpawnAround(chanceSpawnAround);
	game.setDeltaTime(deltaTime);
	game.colorRandomEntities();

	while (game.window->isOpen())
	{
		
		game.pollEvents();
		game.gameUpdate();
		game.render();
	}
}