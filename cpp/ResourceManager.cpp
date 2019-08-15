#include "ResourceManager.h"
#include <iostream>


ResourceManager::ResourceManager()
{
	loadAllTextures();
}

void ResourceManager::loadAllTextures() {
	if (!playerTexture.loadFromFile("images/players/player.png"))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Texture: " << "images/players/player.png" << " loaded successfully" << std::endl;
	}

	if (!enemyTexture.loadFromFile("images/players/enemy.png"))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Texture: " << "images/players/enemy.png" << " loaded successfully" << std::endl;
	}
}

sf::Texture& ResourceManager::getPlayerTexture()
{
	return playerTexture;
}

sf::Texture& ResourceManager::getEnemyTexture()
{
	return enemyTexture;
}
