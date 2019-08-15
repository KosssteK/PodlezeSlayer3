#pragma once
#include <SFML/Graphics.hpp>

class ResourceManager
{
	sf::Texture playerTexture;
	sf::Texture enemyTexture;

	ResourceManager();
	ResourceManager(const ResourceManager &);
public:
	static ResourceManager & getSingleton()
	{
		static ResourceManager singleton;
		return singleton;
	}

	void loadAllTextures();
	sf::Texture& getPlayerTexture();
	sf::Texture& getEnemyTexture();
};

