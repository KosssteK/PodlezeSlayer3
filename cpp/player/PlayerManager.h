#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
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

	void updatePlayerPosition(sf::Vector2f direction);
	sf::Vector2f getPlayerPosition();
	void disableMovement();
};

