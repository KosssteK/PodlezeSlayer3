#include "Player.h"
#include <iostream>
#include "../ResourceManager.h"
#include "../config/Properties.h"


Player::Player()
{
	sprite.setTexture(ResourceManager::getSingleton().getPlayerTexture());
	sprite.setOrigin(128 / 2, 128 / 2);
	sprite.setPosition(Properties::getSingleton().getStartingPosition(0, 0), Properties::getSingleton().getStartingPosition(0, 1));
	sprite.setScale(0.05, 0.05);
	playerID = 0;
}


Player::~Player()
{
}

Player::Player(unsigned long ID, int inOrder)
{
	sprite.setTexture(ResourceManager::getSingleton().getEnemyTexture());
	sprite.setOrigin(128 / 2, 128 / 2);
	sprite.setPosition(Properties::getSingleton().getStartingPosition(inOrder, 0), Properties::getSingleton().getStartingPosition(inOrder, 1));
	sprite.setScale(0.05, 0.05);
	playerID = ID;
}

float Player::getWidth()
{
	return ceil(128.0f * sprite.getScale().x);
}

float Player::getHeight()
{
	return ceil(128.0f * sprite.getScale().y);
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Player::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Player::setRotation(float angle)
{
	sprite.setRotation(angle);
}

float Player::getRotation()
{
	return sprite.getRotation();
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
