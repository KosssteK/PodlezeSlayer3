#pragma once
#include <SFML/Graphics.hpp>
#include "EventsHandler.h"
#include "map/MapManager.h"
#include "player/PlayerManager.h"
#include "Camera.h"

class GameManager {

	EventsHandler eventsHandler;
	Camera playerCamera;
	MapManager mapManager;
	PlayerManager playerManager;

public:
	GameManager();
	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

};