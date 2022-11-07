#include "DrawingScreen.h"

DrawingScreen::DrawingScreen()
{
	window = nullptr;
	initWindow();
	initFont();
}

DrawingScreen::~DrawingScreen()
{
	delete window;
}

void DrawingScreen::update()
{
	pollEvents();
	printMousePos();
	render();
}

void DrawingScreen::pollEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	window->setFramerateLimit(60);
}

void DrawingScreen::initWindow()
{
	setVideoMode();

	window = new sf::RenderWindow(videoMode, "GAME OF LIFE");
}

void DrawingScreen::setVideoMode()
{
	videoMode.width = DEFAULT_SCREEN_WIDTH;
	videoMode.height = DEFAULT_SCREEN_HEIGHT;
}

void DrawingScreen::setGameSize(unsigned size)
{
	gameSize = size;
}

void DrawingScreen::initFont()
{
	if (!font.loadFromFile(FONT_PATH))
		std::cout << "ERROR: DrawingScreen::initFont() failed to load a font\n";
}

void DrawingScreen::initText(sf::Text& text, std::string str, unsigned size, sf::Color color)
{
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
}

void DrawingScreen::readMousePos()
{
	sf::Vector2i tempPos = sf::Mouse::getPosition(*window);
	mousePos = window->mapPixelToCoords(tempPos);
}

void DrawingScreen::printMousePos()
{
	std::stringstream ss;
	ss << "Mouse pos: " << mousePos.x << " " << mousePos.y;
	initText(txtMousePos, ss.str(), 30, sf::Color::Green);
}

void DrawingScreen::render()
{
	window->clear(sf::Color::Blue);

	window->draw(txtMousePos);

	window->display();
}
