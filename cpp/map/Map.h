#pragma once
#include "SFML/Graphics.hpp"
#include "../player/Player.h"


class Map
{
	sf::Texture texture;
	sf::Sprite sprite;

	void getMapTexture(sf::Texture &texture, const char * mapName);
public:
	Map();
	~Map();

	void draw(sf::RenderWindow &window);
	sf::Color getPixelColor(Player player, sf::Vector2f vector);
};

