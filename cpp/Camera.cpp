#include "Camera.h"
#include "config/Properties.h"
#include <iostream>


Camera::Camera()
{
	float side = 60;
	setView(sf::Vector2f(0, 0), sf::Vector2f(
		(float)Properties::getSingleton().getViewSize() * (float)Properties::getSingleton().getScreenRatio(),
		(float)Properties::getSingleton().getViewSize()
	));
}


Camera::~Camera()
{
}

void Camera::init(sf::RenderWindow & window)
{
	window.setView(view);
}

void Camera::update(sf::RenderWindow & window)
{
}

void Camera::draw(sf::RenderWindow & window)
{
}

void Camera::setView(sf::Vector2f position, sf::Vector2f dimentions)
{
	view.reset(sf::FloatRect(position.x, position.y, dimentions.x, dimentions.y));
}
