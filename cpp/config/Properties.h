#pragma once
#include <SFML/Graphics.hpp>


class Properties
{
private:
	sf::Vector2i windowResolution;
	const char * gameName;

	Properties();
	Properties(const Properties &);
public:
	static Properties & getSingleton()
	{
		static Properties singleton;
		return singleton;
	}

	sf::Vector2i getWindowResolution();
	const char* getGameName();
	int getFrameRate();
	float getScreenRatio();
	float getViewSize();
	int getConnectTime();

	std::string getPlayerTextureName();
	std::string getEnemyTextureName();
};