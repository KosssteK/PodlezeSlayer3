#include "MapManager.h"
#include <iostream>
#include "../player/PlayerManager.h"

MapManager::MapManager()
{
}

void MapManager::init(sf::RenderWindow & window)
{
}

void MapManager::update(sf::RenderWindow & window)
{
	sf::Color pixelColor;
	sf::Vector2f playerPosition = PlayerManager::getSingleton().getPlayerPosition();
	pixelColor = gameMap.getPixelColor(playerPosition);

	std::cout << "Pixel color: " << pixelColor.r << ", " << pixelColor.g << std::endl;
}

void MapManager::draw(sf::RenderWindow & window)
{
	gameMap.draw(window);
}
