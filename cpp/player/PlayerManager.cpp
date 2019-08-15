#include "PlayerManager.h"
#include <iostream>


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
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].draw(window);
		//std::cout << enemies[i].getPlayerPosition().x << std::endl;
	}
}

void PlayerManager::registerNewPlayer(unsigned long newPlayerData)
{
	std::cout << "----->> New player created!" << std::endl;
	//std::cout << newPlayerData << std::endl;
	Player newPlayer(newPlayerData);
	enemies.push_back(newPlayer);
}

void PlayerManager::updatePlayerPosition(sf::Vector2f direction)
{
	player.updatePosition(direction);
}

sf::Vector2f PlayerManager::getPlayerPosition()
{
	return player.getPlayerPosition();
}

void PlayerManager::disableMovement() {
	player.disableMovement();
}

Player& PlayerManager::getEnemy(unsigned long enemyID)
{
	int enemyIndex;
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].getID() == enemyID) {
			enemyIndex = i;
			break;
		}
	}

	return enemies[enemyIndex];
}
