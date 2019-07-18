#include "GameManager.h"
#include "config/Properties.h"

GameManager::GameManager()
	:window(sf::VideoMode(
		Properties::getSingleton().getWindowResolution().x,
		Properties::getSingleton().getWindowResolution().y
	),
		Properties::getSingleton().getGameName())
{
}

void GameManager::init()
{
	window.setFramerateLimit(Properties::getSingleton().getFrameRate());
	eventsHandler.init(window);
	playerCamera.init(window);

	mapManager.init(window);
	playerManager.init(window);
}

void GameManager::update()
{
	eventsHandler.update(window);
	playerCamera.update(window);

	mapManager.update(window);
	playerManager.update(window);
}

void GameManager::draw()
{
	window.clear();
	eventsHandler.draw(window);
	playerCamera.draw(window);

	mapManager.draw(window);
	playerManager.draw(window);
	
	window.display();
}

bool GameManager::isWindowOpen()
{
	return window.isOpen();
}
