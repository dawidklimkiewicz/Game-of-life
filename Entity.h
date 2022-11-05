#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
private:
	bool alive;
	sf::RectangleShape rect;
	sf::Vector2f size;

public:

	//CONSTRUCTOR

	Entity(sf::Color c = sf::Color::White, sf::Vector2f s = sf::Vector2f(0.f, 0.f), bool a = false)
		:size(s), alive(a) {
		rect.setFillColor(c);
	}

	void setColor(sf::Color newColor);
	void setIsAlive(bool newState);
    
	//setters to avoid using entity.rect.

	void setSize(sf::Vector2f newSize);
	void setSize(float x, float y);
	void setPosition(sf::Vector2f newPos);
	void setPosition(float x, float y);

	//getters

	sf::Color getColor();
	sf::Vector2f getSize();
	sf::RectangleShape getRect();
	bool getIsAlive();

};

