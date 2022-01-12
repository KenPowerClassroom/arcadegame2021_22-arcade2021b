#pragma once

#include <SFML/Graphics.hpp>

class Asteroids
{
public:
	Asteroids();

	void initialise();
	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);


	sf::RenderWindow m_window;
	sf::Time m_time;
	sf::Sprite m_asteroidSprite;
	sf::Texture m_asteroidTexture;
	
};

