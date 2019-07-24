#pragma once
#include <SFML/Graphics.hpp>
#include "EventsHandler.h"
#include "map/MapManager.h"
#include "player/PlayerManager.h"
#include "Camera.h"

class GameManager {

	sf::RenderWindow window;
	EventsHandler eventsHandler;

public:
	GameManager();
	void init();
	void update();
	void draw();

	bool isWindowOpen();
};