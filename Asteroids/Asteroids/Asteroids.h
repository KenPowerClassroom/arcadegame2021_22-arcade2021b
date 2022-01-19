#pragma once

#include <SFML/Graphics.hpp>

class Asteroids
{
public:
	Asteroids();

	void initialise();
	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

	static const int MAX_ASTEROIDS = 10;

	sf::RenderWindow m_window;
	sf::Time m_time;
	sf::Sprite m_asteroidSprite[MAX_ASTEROIDS];
	sf::Texture m_asteroidTexture;
	
	sf::Vector2f randDirection[MAX_ASTEROIDS];
}; 

class AsteroidMovement
{
public:
	AsteroidMovement();

	void moveAsteroid(Asteroids &t_asteroids);
};
