#include "MapManager.h"
#include <iostream>

MapManager::MapManager()
{
}

void MapManager::init(sf::RenderWindow & window)
{
}

void MapManager::update(sf::RenderWindow & window)
{
	

}

void MapManager::draw(sf::RenderWindow & window)
{
	gameMap.draw(window);
}

bool MapManager::willColide(sf::Vector2f vector, Player player)
{
	bool willColide = false;

	sf::Color pixelColor;
	pixelColor = gameMap.getPixelColor(player, vector);
	if (pixelColor == sf::Color::Black) {
		willColide = true;
	}

	return willColide;
}
