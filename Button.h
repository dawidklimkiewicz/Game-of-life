#pragma once

#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#define FONT_PATH "Fonts/Roboto-Regular.ttf"

class Button
{
private:
	sf::RectangleShape rect;
	sf::Font font;
	sf::Text text;

public:

	Button(sf::Vector2f size = sf::Vector2f(100, 200), sf::Color color = sf::Color::Red
		, std::string text = "NULL", sf::Vector2f pos = sf::Vector2f(0, 0));

	void initFont();

	void setSize(int width, int height);
	void setSize(sf::Vector2f newSize);
	void setColor(sf::Color color);
	void setText(std::string text);
	void setTextColor(sf::Color color, sf::Color outline);
	void setFontSize(int size);
	void setPosition(int x, int y);
	void setPosition(sf::Vector2f newPos);

	sf::RectangleShape getButton();		//returns RectangleShape object
	bool isMouseOver(sf::Vector2f mousePos);
	void clicked();

	void renderButton(sf::RenderWindow *window);
};

