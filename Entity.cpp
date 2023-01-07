#include "Entity.h"



void Entity::setIsAlive(bool newState)
{
	alive = newState;
}

void Entity::setSize(sf::Vector2f newSize)
{
	size = newSize;
	rect.setSize(newSize);
}


void Entity::setPosition(sf::Vector2f newPos)
{
	rect.setPosition(newPos);
}

void Entity::setColor(sf::Color color)
{
	rect.setFillColor(color);
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
