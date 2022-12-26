#include "MenuLayout.h"

MenuLayout::~MenuLayout()
{
	for (auto btn : buttons) {
		delete btn;
	}
}

void MenuLayout::renderLayout(GameParameters* gameParameters, sf::RenderWindow* window)
{

	std::stringstream ss;
	ss << "GAME OF LIFE";
	gameParameters->initFont(txtTitle);
	txtTitle.setString(ss.str());
	txtTitle.setCharacterSize(50);
	txtTitle.setPosition((window->getSize().x / 2) - txtTitle.getGlobalBounds().width / 2, 60);
	window->draw(txtTitle);

	btnStart->setPosition(sf::Vector2f(((window->getSize().x) / 2) - BUTTON_SIZE.x / 2, 200));
	btnOptions->setPosition(sf::Vector2f(((window->getSize().x) / 2) - BUTTON_SIZE.x / 2, 320));
	btnExit->setPosition(sf::Vector2f(((window->getSize().x) / 2) - BUTTON_SIZE.x / 2, 440));


	for (auto btn : buttons) {
		btn->renderButton(window);
	}
}

void MenuLayout::buttonsClicked(GameParameters* gameParameters, sf::RenderWindow* window, sf::Event event)
{

	if (btnStart->isMouseOver(gameParameters->mousePos))
	{
		gameParameters->menuOpened = false;
		gameParameters->drawingScreenOpened = true;
		gameParameters->gameState = 1;
	}

	if (btnOptions->isMouseOver(gameParameters->mousePos))
	{
		gameParameters->menuOpened = false;
		gameParameters->optionsOpened = true;
		gameParameters->gameState = 3;
	}

	if (btnExit->isMouseOver(gameParameters->mousePos))
	{
		gameParameters->menuOpened = false;
		gameParameters->gameState = -1;
	}
}
