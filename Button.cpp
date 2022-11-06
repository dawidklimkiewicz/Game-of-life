#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, std::string text, sf::Vector2f pos)
{
	initFont();

	setText(text);
	rect.setSize(size);
	rect.setOrigin(size / 2.f);
	rect.setFillColor(color);
	setPosition(pos);
}

void Button::initFont()
{
	if (font.loadFromFile(FONT_PATH)) {
		text.setString("NULL");
		text.setFont(font);
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
	}
	else std::cout << "ERROR: Game::initText() - font not loaded\n";
}

void Button::setSize(int width, int height)
{
	rect.setSize(sf::Vector2f(width, height));
}

void Button::setSize(sf::Vector2f newSize)
{
	rect.setSize(newSize);
}

void Button::setColor(sf::Color color)
{
	rect.setFillColor(color);
}

void Button::setText(std::string text)
{
	std::stringstream ss;
	ss << text;
	this->text.setString(ss.str());
}

void Button::setTextColor(sf::Color color, sf::Color outline=sf::Color::Black)
{
	text.setFillColor(color);
	text.setOutlineColor(outline);
}

void Button::setFontSize(int size)
{
	text.setCharacterSize(size);
}

void Button::setPosition(int x, int y)
{
	rect.setPosition(sf::Vector2f(x, y));
	text.setPosition((x + rect.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2),
		(y + rect.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2));
}

void Button::setPosition(sf::Vector2f newPos)
{
	rect.setPosition(newPos);
	text.setPosition(newPos.x - (text.getGlobalBounds().width / 2), 
		newPos.y - (text.getGlobalBounds().height));
}

sf::RectangleShape Button::getButton()
{
	return rect;
}

bool Button::isMouseOver(sf::Vector2f mousePos)
{
	if (mousePos.x > rect.getGlobalBounds().left &&
		mousePos.x < rect.getGlobalBounds().left + rect.getSize().x &&
		mousePos.y > rect.getGlobalBounds().top &&
		mousePos.y < rect.getGlobalBounds().top + rect.getSize().y)
		return true;

	else return false;
}

void Button::renderButton(sf::RenderWindow* window)
{
	window->draw(rect);
	window->draw(text);
}
