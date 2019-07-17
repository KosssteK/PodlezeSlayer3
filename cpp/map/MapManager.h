#pragma once
#include "Map.h"

class MapManager
{
	Map gameMap;

public:
	MapManager();
	~MapManager();

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
};

