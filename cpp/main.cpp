#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.h"
#include "config/Properties.h"

int main()
{
	GameManager gameManager;
	
	gameManager.init();
	while (gameManager.isWindowOpen())
	{
		gameManager.update();
		gameManager.draw();
	}

	return 0;
}