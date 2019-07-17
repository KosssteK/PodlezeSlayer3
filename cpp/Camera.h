#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
	sf::View view;
public:
	Camera();
	~Camera();

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setView(sf::Vector2f position, sf::Vector2f dimentions);
};

