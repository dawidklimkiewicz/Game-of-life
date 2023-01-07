#include "OptionsLayout.h"

OptionsLayout::~OptionsLayout()
{
	for (auto btn : buttons) {
		delete btn;
	}
}

void OptionsLayout::renderLayout(GameParameters* gameParameters, sf::RenderWindow* window)
{
	//ustawienie tekstu na ekranie

	std::stringstream ss;
	ss << "Size of the simulatinon (N x N): " << gameParameters->gameSize;
	gameParameters->initFont(txtGameSize);
	txtGameSize.setString(ss.str());
	txtGameSize.setPosition((window->getSize().x / 2) - txtGameSize.getGlobalBounds().width / 2, 50);
	window->draw(txtGameSize);

	ss.str("");
	ss << "Time between iterations in seconds: " << gameParameters->deltaTime;
	gameParameters->initFont(txtDeltaTime);
	txtDeltaTime.setString(ss.str());
	txtDeltaTime.setPosition((window->getSize().x / 2) - txtDeltaTime.getGlobalBounds().width / 2, 200);
	window->draw(txtDeltaTime);

	ss.str("");
	ss << "Chance of random cell placement: " << gameParameters->randomSpawnChance << "%";
	gameParameters->initFont(txtRandomSpawnChance);
	txtRandomSpawnChance.setString(ss.str());
	txtRandomSpawnChance.setPosition((window->getSize().x / 2) - txtRandomSpawnChance.getGlobalBounds().width / 2, 350);
	window->draw(txtRandomSpawnChance);

	ss.str("");
	ss << "Chance to place another cell nearby: " << gameParameters->chanceSpawnAround << "%";
	gameParameters->initFont(txtChanceSpawnAround);
	txtChanceSpawnAround.setString(ss.str());
	txtChanceSpawnAround.setPosition((window->getSize().x / 2) - txtChanceSpawnAround.getGlobalBounds().width / 2, 500);
	window->draw(txtChanceSpawnAround);


	//ustawienie przyciskow na ekranie

	btnSizeLess2->setPosition(sf::Vector2f((window->getSize().x - 485) / 2, 100));
	btnSizeLess->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 120 , 100));
	btnSizeMore->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 290, 100));
	btnSizeMore2->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 410, 100));

	btnDeltaTimeLess2->setPosition(sf::Vector2f((window->getSize().x - 485) / 2, 250));
	btnDeltaTimeLess->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 120, 250));
	btnDeltaTimeMore->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 290, 250));
	btnDeltaTimeMore2->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 410, 250));

	btnChanceLess2->setPosition(sf::Vector2f((window->getSize().x - 485) / 2, 400));
	btnChanceLess->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 120, 400));
	btnChanceMore->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 290, 400));
	btnChanceMore2->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 410, 400));

	btnChanceAroundLess2->setPosition(sf::Vector2f((window->getSize().x - 485) / 2, 550));
	btnChanceAroundLess->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 120, 550));
	btnChanceAroundMore->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 290, 550));
	btnChanceAroundMore2->setPosition(sf::Vector2f(((window->getSize().x - 485) / 2) + 410, 550));

	btnBack->setPosition(sf::Vector2f((window->getSize().x / 2) - btnBack->getButton().getGlobalBounds().width / 2, 725));

	for (auto btn : buttons) {
		btn->renderButton(window);
	}
}

void OptionsLayout::buttonsClicked(GameParameters* gameParameters, sf::RenderWindow *window, sf::Event event)
{
	//obsluga przyciskow do zmiany rozmiaru

	if (btnSizeMore->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->gameSize += 1;
	}


	if (btnSizeMore2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->gameSize += 10;
	}

	if (btnSizeLess->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->gameSize--;
		if (gameParameters->gameSize < 10) 
			gameParameters->gameSize = 10;
	}

	if (btnSizeLess2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->gameSize -= 10;
		if (gameParameters->gameSize < 10) 
			gameParameters->gameSize = 10;
	}


	// obsluga przyciskow do zmiany czasu

	if (btnDeltaTimeMore->isMouseOver(gameParameters->mousePos))
		gameParameters->deltaTime += 0.01f;

	if (btnDeltaTimeMore2->isMouseOver(gameParameters->mousePos))
		gameParameters->deltaTime += 0.1f;

	if (btnDeltaTimeLess->isMouseOver(gameParameters->mousePos)) {
		gameParameters->deltaTime -= 0.01f;
		if (gameParameters->deltaTime < 0.01) gameParameters->deltaTime = 0.01f;
	}

	if (btnDeltaTimeLess2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->deltaTime -= 0.1f;
		if (gameParameters->deltaTime < 0.01) gameParameters->deltaTime = 0.01f;
	}


	// obsluga przyciskwow do zmiany szansy

	if (btnChanceMore->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->randomSpawnChance++;
		if (gameParameters->randomSpawnChance > 100) gameParameters->randomSpawnChance = 100;
	}

	if (btnChanceMore2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->randomSpawnChance += 10;
		if (gameParameters->randomSpawnChance > 100) gameParameters->randomSpawnChance = 100;
	}

	if (btnChanceLess->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->randomSpawnChance--;
		if (gameParameters->randomSpawnChance < 0) gameParameters->randomSpawnChance = 0;
	}

	if (btnChanceLess2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->randomSpawnChance -= 10;
		if (gameParameters->randomSpawnChance < 0) gameParameters->randomSpawnChance = 0;
	}


	// obsluga przyciskwow do zmiany szansy dookola

	if (btnChanceAroundMore->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->chanceSpawnAround++;
		if (gameParameters->chanceSpawnAround > 100) gameParameters->chanceSpawnAround = 100;
	}

	if (btnChanceAroundMore2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->chanceSpawnAround += 10;
		if (gameParameters->chanceSpawnAround > 100) gameParameters->chanceSpawnAround = 100;
	}

	if (btnChanceAroundLess->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->chanceSpawnAround--;
		if (gameParameters->chanceSpawnAround < 0) gameParameters->chanceSpawnAround = 0;
	}

	if (btnChanceAroundLess2->isMouseOver(gameParameters->mousePos)) {
		gameParameters->optionsChanged = true;
		gameParameters->chanceSpawnAround -= 10;
		if (gameParameters->chanceSpawnAround < 0) gameParameters->chanceSpawnAround = 0;
	}



	if (btnBack->isMouseOver(gameParameters->mousePos))
	{
		gameParameters->optionsOpened = false;
		gameParameters->menuOpened = true;
		gameParameters->gameState = 0;
	}
}
