#include "Entity.h"


// SETTERS

void Entity::setColor(sf::Color newColor)
{
	rect.setFillColor(newColor);
}

void Entity::setIsAlive(bool newState)
{
	alive = newState;
}

void Entity::setSize(sf::Vector2f newSize)
{
	size = newSize;
	rect.setSize(newSize);
}

void Entity::setSize(float x, float y)
{
	size.x = x;
	size.y = y;
	rect.setSize(sf::Vector2f(x, y));
}

void Entity::setPosition(sf::Vector2f newPos)
{
	rect.setPosition(newPos);
}

void Entity::setPosition(float x, float y)
{
	rect.setPosition(sf::Vector2f(x, y));
}



//GETTERS

sf::Color Entity::getColor()
{
	return rect.getFillColor();
}

sf::Vector2f Entity::getSize()
{
	return size;
}

sf::RectangleShape Entity::getRect()
{
	return rect;
}

bool Entity::getIsAlive()
{
	return alive;
}
