#include "Menu.h"


Menu::Menu()
{
	initWindow();
	initFont();
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

		if (event.type == sf::Event::MouseMoved) {
			if (button.isMouseOver(mousePos)) {
				button.setColor(sf::Color::White);
			}
			else button.setColor(sf::Color::Black);
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (button.isMouseOver(mousePos))
				std::cout << "klik" << std::endl;
		}
	}
}

void Menu::initWindow()
{
	setVideoMode(1600, 900);

	window = new sf::RenderWindow(videoMode, "GAME OF LIFE");
	window->setFramerateLimit(60);
}

void Menu::initFont()
{
	/*if (!font.loadFromFile(FONT_PATH))
		std::cout << "ERROR: MENU::initText() - font not loaded\n";*/

	if (font.loadFromFile(FONT_PATH)) {
		mouse.setString("NULL");
		mouse.setFont(font);
		mouse.setCharacterSize(30);
		mouse.setFillColor(sf::Color::Black);
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
	window->clear(sf::Color::Cyan);
	button.renderButton(window);

	window->draw(mouse);

	window->display();
}

void Menu::printMousePos()
{
	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);

	std::stringstream ss;
	ss << "Mouse pos: " << (int)mousePos.x << " " << (int)mousePos.y << '\n';
	mouse.setString(ss.str());
}
