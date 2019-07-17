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
