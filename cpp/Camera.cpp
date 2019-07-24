#include "Camera.h"
#include "config/Properties.h"
#include <iostream>
#include "player/PlayerManager.h"


Camera::Camera()
{
	setView(sf::Vector2f(0, 0), sf::Vector2f(
		(float)Properties::getSingleton().getViewSize() * (float)Properties::getSingleton().getScreenRatio(),
		(float)Properties::getSingleton().getViewSize()
	));
}

void Camera::init(sf::RenderWindow & window)
{
	window.setView(view);
}

void Camera::update(sf::RenderWindow & window)
{
	sf::Vector2f playerPosition = PlayerManager::getSingleton().getPlayerPosition();
	playerPosition.x -= (float)Properties::getSingleton().getViewSize() * (float)Properties::getSingleton().getScreenRatio() / 2;
	playerPosition.y -= (float)Properties::getSingleton().getViewSize() / 2;
	setView(playerPosition, sf::Vector2f(
		(float)Properties::getSingleton().getViewSize() * (float)Properties::getSingleton().getScreenRatio(),
		(float)Properties::getSingleton().getViewSize()));
	window.setView(view);
}

void Camera::draw(sf::RenderWindow & window)
{
}

void Camera::setView(sf::Vector2f position, sf::Vector2f dimentions)
{
	view.reset(sf::FloatRect(position.x, position.y, dimentions.x, dimentions.y));
}
