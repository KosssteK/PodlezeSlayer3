#include "PlayerManager.h"



PlayerManager::PlayerManager()
{
}

void PlayerManager::init(sf::RenderWindow & window)
{
}

void PlayerManager::update(sf::RenderWindow & window)
{
	
}

void PlayerManager::draw(sf::RenderWindow & window)
{
	player.draw(window);
}

void PlayerManager::updatePlayerPosition(sf::Vector2f direction)
{
	player.updatePosition(direction);
}

sf::Vector2f PlayerManager::getPlayerPosition()
{
	return player.getPlayerPosition();
}
