#include "Player.h"
#include <iostream>
#include "../ResourceManager.h"


Player::Player()
{
	sprite.setTexture(ResourceManager::getSingleton().getPlayerTexture());
	sprite.setOrigin(4,4);
	sprite.setPosition(10,10);

	playerID = 0;
}


Player::~Player()
{
}

Player::Player(unsigned long ID)
{
	sprite.setTexture(ResourceManager::getSingleton().getEnemyTexture());
	sprite.setOrigin(5, 5);
	sprite.setPosition(10, 10);
	playerID = ID;
}

float Player::getWidth()
{
	return 5.0f;
}

float Player::getHeight()
{
	return 5.0f;
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Player::setRotation(float angle)
{
	sprite.setRotation(angle);
}

void Player::updatePosition(sf::Vector2f direction)
{
	sf::Vector2f previousPosition = sprite.getPosition();
	sprite.setPosition(previousPosition.x + direction.x * speed, previousPosition.y + direction.y * speed);
}

sf::Vector2f Player::getPlayerPosition()
{
	return sprite.getPosition();
}

void Player::disableMovement()
{
	speed = 0;
}

unsigned long Player::getID()
{
	return playerID;
}
