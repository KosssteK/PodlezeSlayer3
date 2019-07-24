#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	sf::Texture texture;
	sf::Sprite sprite;
	float speed = 1;

	void getPlayerTexture(sf::Texture &texture, const char * mapName);
public:
	Player();
	~Player();

	void draw(sf::RenderWindow & window);
	void updatePosition(sf::Vector2f direction);
	sf::Vector2f getPlayerPosition();
};

