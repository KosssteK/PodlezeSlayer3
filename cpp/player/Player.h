#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	sf::Texture texture;
	sf::Sprite sprite;
	float speed = 1;
	unsigned long playerID;

public:
	Player();
	~Player();
	Player(unsigned long ID);

	float getWidth();
	float getHeight();

	void draw(sf::RenderWindow & window);
	
	void setRotation(float angle);
	void updatePosition(sf::Vector2f direction);
	sf::Vector2f getPlayerPosition();
	void disableMovement();

	unsigned long getID();
};

