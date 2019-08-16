#pragma once
#include "Map.h"
#include "../player/Player.h"

class MapManager
{
	Map gameMap;

	MapManager();
	MapManager(const MapManager &);
public:
	static MapManager & getSingleton()
	{
		static MapManager singleton;
		return singleton;
	}

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	bool willColide(sf::Vector2f vector, Player player);
};

