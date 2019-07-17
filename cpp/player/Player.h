#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	sf::Texture texture;
	sf::Sprite sprite;

	void getPlayerTexture(sf::Texture &texture, const char * mapName);
public:
	Player();
	~Player();

	void draw(sf::RenderWindow & window);
};

