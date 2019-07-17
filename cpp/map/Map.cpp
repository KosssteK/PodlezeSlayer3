#include "Map.h"
#include <iostream>

Map::Map()
{
	getMapTexture(texture, "images/gameMap1.png");
	sprite.setTexture(texture);
	sprite.setPosition(0,0);
}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void Map::getMapTexture(sf::Texture &texture, const char * mapName)
{
	if (!texture.loadFromFile(mapName))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Success" << std::endl;
	}
}
