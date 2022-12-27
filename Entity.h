#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
private:
	bool alive;
	sf::RectangleShape rect;
	sf::Vector2f size;

public:

	Entity(sf::Color c = sf::Color::Black, sf::Vector2f s = sf::Vector2f(0.f, 0.f), bool a = false)
		:size(s), alive(a) {
		rect.setFillColor(c);
	}

	void setIsAlive(bool newState);
	void setSize(sf::Vector2f newSize);
	void setSize(float x);
	void setPosition(sf::Vector2f newPos);
	void setPosition(float x, float y);


	sf::Vector2f getSize();
	sf::RectangleShape getRect();
	bool getIsAlive();

};

