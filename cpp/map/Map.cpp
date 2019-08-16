#include "Map.h"
#include <iostream>
#include <math.h>

Map::Map()
{
	getMapTexture(texture, "images/gameMap2.png");
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
}


Map::~Map()
{
}

void Map::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

sf::Color Map::getPixelColor(Player player, sf::Vector2f vector)
{
	sf::Image imgMap = texture.copyToImage();
	return imgMap.getPixel(
		player.getPlayerPosition().x + (vector.x *player.getWidth() / 2),
		player.getPlayerPosition().y + (vector.y *player.getHeight() / 2) 
	);
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
