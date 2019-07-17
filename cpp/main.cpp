#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.h"
#include "config/Properties.h"

int main()
{
	sf::RenderWindow window(
		sf::VideoMode(
			Properties::getSingleton().getWindowResolution().x,
			Properties::getSingleton().getWindowResolution().y
		),
		Properties::getSingleton().getGameName()
	);
	GameManager gameManager;
	
	gameManager.init(window);
	window.setFramerateLimit(Properties::getSingleton().getFrameRate());
	while (window.isOpen())
	{
		gameManager.update(window);
		gameManager.draw(window);
	}

	return 0;
}