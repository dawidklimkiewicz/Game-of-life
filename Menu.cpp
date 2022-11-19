#include "Menu.h"


Menu::Menu()
{
	initWindow();
}

Menu::~Menu()
{
	delete this->window;

	for (auto btn : buttons) {
		delete btn;
	}

}

void Menu::update()
{
	printMousePos();
}

void Menu::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::MouseButtonPressed)
			buttonsClicked(event);	
	}
}


void Menu::initWindow()
{
	setVideoMode(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);

	window = new sf::RenderWindow(videoMode, "GAME OF LIFE");
	window->setFramerateLimit(60);

	gameSize = 90;
	deltaTime = 0.1;
	randomSpawnChance = 5;
	chanceSpawnAround = 25;
}

void Menu::initFont(sf::Text &txt)
{
	if (font.loadFromFile(FONT_PATH)) {
		txt.setString("NULL");
		txt.setFont(font);
		txt.setCharacterSize(32);
		txt.setFillColor(sf::Color::Black);
	}
	else std::cout << "ERROR: Game::initText() - font not loaded\n";
}

void Menu::setVideoMode(int width, int height)
{
	videoMode.width = width;
	videoMode.height = height;
}

sf::Vector2f Menu::getMousePos()
{
	return sf::Vector2f(mousePos);
}

unsigned Menu::getGameSize()
{
	return gameSize;
}

int Menu::getRandomSpawnChance()
{
	return randomSpawnChance;
}

int Menu::getChanceSpawnAround()
{
	return chanceSpawnAround;
}

float Menu::getDeltaTime()
{
	return deltaTime;
}


void Menu::render()
{
	window->clear(sf::Color::White);

	renderLayout();
	window->draw(mouse);

	window->display();
}

void Menu::renderLayout()
{
	std::stringstream ss;
	ss << "Size of the simulatinon (N x N): " << gameSize;
	initFont(txtGameSize);
	txtGameSize.setString(ss.str());
	txtGameSize.setPosition((window->getSize().x / 2) - txtGameSize.getGlobalBounds().width / 2, 50);
	window->draw(txtGameSize);

	ss.str("");
	ss << "Time between generations in seconds: " << deltaTime;
	initFont(txtDeltaTime);
	txtDeltaTime.setString(ss.str());
	txtDeltaTime.setPosition((window->getSize().x / 2) - txtDeltaTime.getGlobalBounds().width / 2, 200);
	window->draw(txtDeltaTime);

	ss.str("");
	ss << "Chance for a cell to spawn: " << randomSpawnChance << "%";
	initFont(txtRandomSpawnChance);
	txtRandomSpawnChance.setString(ss.str());
	txtRandomSpawnChance.setPosition((window->getSize().x / 2) - txtRandomSpawnChance.getGlobalBounds().width / 2, 350);
	window->draw(txtRandomSpawnChance);

	ss.str("");
	ss << "Chance to spawn a cell next to\n a randomly spawned cell: " << chanceSpawnAround << "%";
	initFont(txtChanceSpawnAround);
	txtChanceSpawnAround.setString(ss.str());
	txtChanceSpawnAround.setPosition((window->getSize().x / 2) - txtChanceSpawnAround.getGlobalBounds().width / 2, 500);
	window->draw(txtChanceSpawnAround);

	/*ss.str("");
	ss << "Show frame count";
	initFont(txtShowFrameCount);
	txtShowFrameCount.setString(ss.str());
	txtShowFrameCount.setPosition((window->getSize().x / 2) - txtShowFrameCount.getGlobalBounds().width / 2, 650);
	window->draw(txtShowFrameCount);*/



	for (auto btn : buttons) {
		btn->renderButton(window);
	}
}

void Menu::printMousePos()
{
	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);

	std::stringstream ss;
	initFont(mouse);
	mouse.setCharacterSize(30);
	ss << "Mouse pos: " << (int)mousePos.x << " " << (int)mousePos.y << '\n';
	mouse.setString(ss.str());
}


void Menu::buttonsClicked(sf::Event event)
{
	if (btnSizeMore->isMouseOver(mousePos))
		gameSize++;


	if (btnSizeMore2->isMouseOver(mousePos))
		gameSize += 10;

	if (btnSizeLess->isMouseOver(mousePos)) {
		gameSize--;
		if (gameSize < 10) gameSize = 10;
	}

	if (btnSizeLess2->isMouseOver(mousePos)) {
		gameSize -= 10;
		if (gameSize < 10) gameSize = 10;
	}


	if (btnDeltaTimeMore->isMouseOver(mousePos))
		deltaTime += 0.01;

	if (btnDeltaTimeMore2->isMouseOver(mousePos))
		deltaTime += 0.1;

	if (btnDeltaTimeLess->isMouseOver(mousePos)) {
		deltaTime -= 0.01;
		if (deltaTime < 0.01) deltaTime = 0.01;
	}

	if (btnDeltaTimeLess2->isMouseOver(mousePos)) {
		deltaTime -= 0.1;
		if (deltaTime < 0.01) deltaTime = 0.01;
	}



	if (btnChanceMore->isMouseOver(mousePos)) {
		randomSpawnChance++;
		if (randomSpawnChance > 100) randomSpawnChance = 100;
	}

	if (btnChanceMore2->isMouseOver(mousePos)) {
		randomSpawnChance += 10;
		if (randomSpawnChance > 100) randomSpawnChance = 100;
	}

	if (btnChanceLess->isMouseOver(mousePos)) {
		randomSpawnChance--;
		if (randomSpawnChance < 0) randomSpawnChance = 0;
	}

	if (btnChanceLess2->isMouseOver(mousePos)) {
		randomSpawnChance -= 10;
		if (randomSpawnChance < 0) randomSpawnChance = 0;
	}



	if (btnChanceAroundMore->isMouseOver(mousePos)) {
		chanceSpawnAround++;
		if (chanceSpawnAround > 100) chanceSpawnAround = 100;
	}

	if (btnChanceAroundMore2->isMouseOver(mousePos)) {
		chanceSpawnAround += 10;
		if (chanceSpawnAround > 100) chanceSpawnAround = 100;
	}

	if (btnChanceAroundLess->isMouseOver(mousePos)) {
		chanceSpawnAround--;
		if (chanceSpawnAround < 0) chanceSpawnAround = 0;
	}

	if (btnChanceAroundLess2->isMouseOver(mousePos)) {
		chanceSpawnAround -= 10;
		if (chanceSpawnAround < 0) chanceSpawnAround = 0;
	}



	if (btnNext->isMouseOver(mousePos))
		window->close();

}