#include "PlayerManager.h"
#include <iostream>
#include "../NetworkManager.h"
#include <math.h>


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

void PlayerManager::registerNewPlayer(unsigned long newPlayerData, int inOrder)
{
	if (!isAlreadyCreated(newPlayerData)) {
		std::cout << "----->> New player created!" << std::endl;
		enemies.push_back(Player(newPlayerData, inOrder));
	}
}

void PlayerManager::setPlayerPosition(sf::Vector2f position)
{
	player.setPosition(position);
}

void PlayerManager::setPlayerRotation(float angle)
{
	player.setRotation(angle);
}

float PlayerManager::getPlayerRotation()
{
	return player.getRotation();
}

Player PlayerManager::getPlayer()
{
	return player;
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

void PlayerManager::checkHitCollision(sf::Vector2f mousePosition)
{
	for (int i = 0; i < enemies.size(); i++) {
		if (hitOccured(enemies[i], mousePosition)) {
			NetworkManager::getSingleton().sendUpdatedData(sf::Vector2f(0.0f, 0.0f), PlayerManager::getSingleton().getPlayerRotation(), enemies[i].getID());
			PlayerManager::getSingleton().eraseEnemy(enemies[i].getID());
		}
	}
}

bool PlayerManager::hitOccured(Player enemy, sf::Vector2f mousePosition)
{

	sf::Vector2f shotVec(mousePosition.x - player.getPlayerPosition().x, mousePosition.y - player.getPlayerPosition().y);
	sf::Vector2f playersVec(enemy.getPlayerPosition().x - player.getPlayerPosition().x, enemy.getPlayerPosition().y - player.getPlayerPosition().y);

	float dotProduct = shotVec.x * playersVec.x + shotVec.y * playersVec.y;

	float shotVecLength = sqrt(pow(shotVec.x, 2) + pow(shotVec.y, 2));
	float playersVecLength = sqrt(pow(playersVec.x, 2) + pow(playersVec.y, 2));

	sf::Vector2f proj = dotProduct / pow(shotVecLength, 2) * shotVec;
	float projLength = sqrt(pow(proj.x, 2) + pow(proj.y, 2));

	float lengthFromCenter = sqrt(pow(playersVecLength, 2) - pow(projLength, 2));

	return lengthFromCenter <= PlayerManager::getSingleton().getPlayer().getWidth() / 2 && dotProduct > 0;
}

void PlayerManager::eraseEnemy(unsigned long enemyID)
{
	if (NetworkManager::getSingleton().getPlayerID() == enemyID) {
		std::cout << "END GAME" << std::endl;
		NetworkManager::getSingleton().disconnect();
	}
	else {
		//Player *a = &enemies[getEnemyIndex(enemyID)];
		enemies.erase(enemies.begin() + getEnemyIndex(enemyID));
		std::cout << "ID: " << enemyID << " index: " << getEnemyIndex(enemyID) << std::endl;
		std::cout << "Size: " << enemies.size() << std::endl;
		//std::cout << "player: " << a->getID() << std::endl;
	}
}

int PlayerManager::getEnemyIndex(unsigned long enemyID)
{
	int enemyIndex = -1;
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].getID() == enemyID) {
			enemyIndex = i;
			break;
		}
	}
	return enemyIndex;
}

bool PlayerManager::isAlreadyCreated(unsigned long enemyID)
{
	return getEnemyIndex(enemyID) >= 0;
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
