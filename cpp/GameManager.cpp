#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::init(sf::RenderWindow &window)
{
	eventsHandler.init(window);
	playerCamera.init(window);

	mapManager.init(window);
	playerManager.init(window);
}

void GameManager::update(sf::RenderWindow &window)
{
	eventsHandler.update(window);
	playerCamera.update(window);

	mapManager.update(window);
	playerManager.update(window);
}

void GameManager::draw(sf::RenderWindow &window)
{
	window.clear();
	eventsHandler.draw(window);
	playerCamera.draw(window);

	mapManager.draw(window);
	playerManager.draw(window);
	
	window.display();
}
