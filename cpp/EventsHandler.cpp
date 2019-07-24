#include "EventsHandler.h"
#include <iostream>
#include "player/PlayerManager.h"

EventsHandler::EventsHandler()
{
}

void EventsHandler::init(sf::RenderWindow & window)
{
}

void EventsHandler::update(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		
		handleKeyboardEvents(event);
		handleMouseEvents(event);
	}
}



void EventsHandler::draw(sf::RenderWindow & window)
{
}

void EventsHandler::handleKeyboardEvents(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			PlayerManager::getSingleton().updatePlayerPosition(sf::Vector2f(-1.0, 0.0));
		}
		if (event.key.code == sf::Keyboard::D)
		{
			PlayerManager::getSingleton().updatePlayerPosition(sf::Vector2f(1.0, 0.0));
		}
		if (event.key.code == sf::Keyboard::W)
		{
			PlayerManager::getSingleton().updatePlayerPosition(sf::Vector2f(0.0, -1.0));
		}
		if (event.key.code == sf::Keyboard::S)
		{
			PlayerManager::getSingleton().updatePlayerPosition(sf::Vector2f(0.0, 1.0));
		}
	}
}

void EventsHandler::handleMouseEvents(sf::Event & event)
{
	if (event.type == sf::Event::MouseMoved) 
	{
		std::cout << "moved" << std::endl;
	}
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "mouseButton: " << event.key.code << std::endl;
		}
	}
}
