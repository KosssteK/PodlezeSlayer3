#pragma once
#include <SFML/Graphics.hpp>


class Properties
{
private:
	sf::Vector2i windowResolution;
	const char * gameName;
	const char * serverIP;
	int serverPort;

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

	const char* getServerIP();
	int getServerPort();
	std::string getPlayerTextureName();
	std::string getEnemyTextureName();
	float getStartingPosition(int inOrder, int coordinate);
};