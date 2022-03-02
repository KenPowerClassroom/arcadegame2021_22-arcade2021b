#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"

class Asteroids
{
public:
	Asteroids();

	void initialise();
	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

	void destroyAsteroid(int asteroidIndex);

	sf::RenderWindow m_window;
	sf::Time m_time;
	sf::Sprite m_asteroidSprite[MAX_ASTEROIDS];
	sf::Texture m_asteroidTexture;
	
	sf::Vector2f randDirection[MAX_ASTEROIDS];
	int randScale;
}; 

class AsteroidMovement
{
public:
	AsteroidMovement();

	void moveAsteroid(Asteroids &t_asteroids);
	void loopAsteroid(Asteroids& t_asteroids);
	void update(sf::Time t_deltaTime);

};

