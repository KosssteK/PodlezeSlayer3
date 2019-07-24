#include "Player.h"
#include <iostream>


Player::Player()
{
	getPlayerTexture(texture, "images/players/player.png");
	sprite.setTexture(texture);
	sprite.setOrigin(5, 5);
	sprite.setPosition(10,10);
}


Player::~Player()
{
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
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

void Player::getPlayerTexture(sf::Texture & texture, const char * mapName)
{
	if (!texture.loadFromFile(mapName))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Success" << std::endl;
	}
}
