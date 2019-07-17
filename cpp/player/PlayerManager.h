#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class PlayerManager
{
	Player player;
	std::vector<Player> enemies;

public:
	PlayerManager();
	~PlayerManager();

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
};

