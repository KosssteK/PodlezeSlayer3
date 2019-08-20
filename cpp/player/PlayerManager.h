#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <enet/enet.h>
#include <vector>

class PlayerManager
{
	Player player;
	std::vector<Player> enemies;
	
	PlayerManager();
	PlayerManager(const PlayerManager &);
public:
	static PlayerManager & getSingleton()
	{
		static PlayerManager singleton;
		return singleton;
	}

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void registerNewPlayer(unsigned long newPlayerData, int inOrder);

	void setPlayerPosition(sf::Vector2f position);
	void setPlayerRotation(float angle);
	float getPlayerRotation();

	Player getPlayer();
	void updatePlayerPosition(sf::Vector2f direction);
	sf::Vector2f getPlayerPosition();
	void disableMovement();

	void checkHitCollision(sf::Vector2f mousePosition);
	bool hitOccured(Player enemy, sf::Vector2f mousePosition);
	void eraseEnemy(unsigned long enemyID);

	int getEnemyIndex(unsigned long enemyID);
	bool isAlreadyCreated(unsigned long enemyID);
	Player& getEnemy(unsigned long enemyID);
};

