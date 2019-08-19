#include "Properties.h"
#include <fstream>
#include <iostream>


Properties::Properties()
{
	gameName = "Podleze Slayer 4";
	serverIP = "localhost";
	std::string line;
	std::ifstream settingsFile("settings.txt");
	if (settingsFile.is_open())
	{
		getline(settingsFile, line);
		windowResolution.x = stoi(line);

		getline(settingsFile, line);
		windowResolution.y = stoi(line);

		getline(settingsFile, line);
		serverPort = stoi(line);
		
		settingsFile.close();
	}
	else {
		std::cout << "there is no settings file!" << std::endl;
	}

}

sf::Vector2i Properties::getWindowResolution()
{
	return windowResolution;
}

const char * Properties::getGameName()
{
	return gameName;
}

int Properties::getFrameRate()
{
	return 60;
}

float Properties::getScreenRatio()
{
	return (float)windowResolution.x / (float)windowResolution.y;;
}

float Properties::getViewSize()
{
	return 60.0f;
}

int Properties::getConnectTime()
{
	return 100;
}

const char* Properties::getServerIP()
{
	return serverIP;
}

int Properties::getServerPort()
{
	return serverPort;
}

std::string Properties::getPlayerTextureName()
{
	return "images/players/player3.png";
}

std::string Properties::getEnemyTextureName()
{
	return "images/players/enemy3.png";
}

float Properties::getStartingPosition(int inOrder, int coordinate)
{
	int positions[4][2] = {
		   10,10,
		   10,243,
		   243,10,
		   243,243
	};
	return positions[inOrder][coordinate];
}


