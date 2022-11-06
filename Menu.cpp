#include "Menu.h"


Menu::Menu()
{
	initWindow();
	initFont(mouse);
	gameSize = 15;
}

Menu::~Menu()
{
	delete this->window;
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

		if (event.type == sf::Event::MouseButtonPressed) {
			if (btnSizeMore.isMouseOver(mousePos))
				std::cout << "klik" << std::endl;
		}
	}
}

void Menu::initWindow()
{
	setVideoMode(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);

	window = new sf::RenderWindow(videoMode, "GAME OF LIFE");
	window->setFramerateLimit(60);
}

void Menu::initFont(sf::Text &txt)
{
	if (font.loadFromFile(FONT_PATH)) {
		txt.setString("NULL");
		txt.setFont(font);
		txt.setCharacterSize(48);
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
	txtGameSize.setPosition((window->getSize().x / 2) - txtGameSize.getGlobalBounds().width / 2, 100);

	window->draw(txtGameSize);
	btnSizeMore.renderButton(window);
	btnSizeMore2.renderButton(window);
	btnSizeLess.renderButton(window);
	btnSizeLess2.renderButton(window);

	ss.str("");
	ss << "Time between generations in seconds: " << deltaTime;
	initFont(txtDeltaTime);

	btnDeltaTimeMore.renderButton(window);
	btnDeltaTimeMore2.renderButton(window);
	btnDeltaTimeLess.renderButton(window);
	btnDeltaTimeLess2.renderButton(window);
}

void Menu::printMousePos()
{
	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);

	std::stringstream ss;
	ss << "Mouse pos: " << (int)mousePos.x << " " << (int)mousePos.y << '\n';
	mouse.setString(ss.str());
}
