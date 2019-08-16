#include "ResourceManager.h"
#include <iostream>
#include "config/Properties.h"


ResourceManager::ResourceManager()
{
	loadAllTextures();
}

void ResourceManager::loadAllTextures() {
	if (!playerTexture.loadFromFile(Properties::getSingleton().getPlayerTextureName()))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Texture: " << Properties::getSingleton().getPlayerTextureName() << " loaded successfully" << std::endl;
	}

	if (!enemyTexture.loadFromFile(Properties::getSingleton().getEnemyTextureName()))
	{
		std::cout << "Error" << std::endl;
	}
	else {
		std::cout << "Texture: " << Properties::getSingleton().getEnemyTextureName() << " loaded successfully" << std::endl;
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
