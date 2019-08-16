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

	bool isAlreadyCreated(unsigned long enemyID);
	Player& getEnemy(unsigned long enemyID);
};

