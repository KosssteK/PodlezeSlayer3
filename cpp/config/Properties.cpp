#include "Properties.h"


Properties::Properties()
{
	gameName = "Podleze Slayer 3";
	windowResolution.x = 800;
	windowResolution.y = 600;
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
