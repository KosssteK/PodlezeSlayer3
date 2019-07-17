#pragma once
#include "SFML/Graphics.hpp"


class Map
{
	sf::Texture texture;
	sf::Sprite sprite;

	void getMapTexture(sf::Texture &texture, const char * mapName);
public:
	Map();
	~Map();

	void draw(sf::RenderWindow &window);
};

