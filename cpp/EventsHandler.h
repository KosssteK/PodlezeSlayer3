#pragma once
#include <SFML/Graphics.hpp>

class EventsHandler {

public:
	EventsHandler();
	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void handleKeyboardEvents(sf::Event & event);
	void handleMouseEvents(sf::Event & event);
};