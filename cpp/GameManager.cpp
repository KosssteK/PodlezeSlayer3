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
	
	Camera::getSingleton().init(window);
	MapManager::getSingleton().init(window);
	PlayerManager::getSingleton().init(window);
}

void GameManager::update()
{
	eventsHandler.update(window);
	
	PlayerManager::getSingleton().update(window);
	Camera::getSingleton().update(window);
	MapManager::getSingleton().update(window);
}

void GameManager::draw()
{
	window.clear();
	eventsHandler.draw(window);
	
	Camera::getSingleton().draw(window);
	MapManager::getSingleton().draw(window);
	PlayerManager::getSingleton().draw(window);
	
	window.display();
}

bool GameManager::isWindowOpen()
{
	return window.isOpen();
}
