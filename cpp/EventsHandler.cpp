#include "EventsHandler.h"
#include <iostream>
#include "player/PlayerManager.h"
#include "NetworkManager.h"
#include "map/MapManager.h"

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
		handleMouseEvents(event, window);
	}
}



void EventsHandler::draw(sf::RenderWindow & window)
{
}

void EventsHandler::handleKeyboardEvents(sf::Event & event)
{

	sf::Vector2f vector(0.0, 0.0);
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			proceedPlayerMovement(sf::Vector2f(-1.0, 0.0));
		}
		if (event.key.code == sf::Keyboard::D)
		{
			proceedPlayerMovement(sf::Vector2f(1.0, 0.0));
		}
		if (event.key.code == sf::Keyboard::W)
		{
			proceedPlayerMovement(sf::Vector2f(0.0, -1.0));
		}
		if (event.key.code == sf::Keyboard::S)
		{
			proceedPlayerMovement(sf::Vector2f(0.0, 1.0));
		}
	}

	if (event.type == sf::Event::KeyReleased) {

	}
}

void EventsHandler::handleMouseEvents(sf::Event & event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::MouseMoved) 
	{
		sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		sf::Vector2f playersPosition = PlayerManager::getSingleton().getPlayerPosition();
		float PI = 3.14;
		PlayerManager::getSingleton().setPlayerRotation(atan2(worldPos.y - playersPosition.y, worldPos.x - playersPosition.x) * 180 / PI);
	}
	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			std::cout << "mouseButton: " << event.key.code << std::endl;
		}
	}
}

void EventsHandler::proceedPlayerMovement(sf::Vector2f vector)
{
	if (!MapManager::getSingleton().willColide(vector, PlayerManager::getSingleton().getPlayer())) {
		PlayerManager::getSingleton().updatePlayerPosition(vector);
		NetworkManager::getSingleton().sendUpdatedData(vector);
	}
}
