#pragma once
#include <SFML/Graphics.hpp>

class Camera
{
	sf::View view;

	Camera();
	Camera(const Camera &);
public:
	static Camera & getSingleton()
	{
		static Camera singleton;
		return singleton;
	}

	void init(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setView(sf::Vector2f position, sf::Vector2f dimentions);
};

