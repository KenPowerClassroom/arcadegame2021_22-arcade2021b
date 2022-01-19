#include "Asteroids.h"
#include <iostream>

Asteroids::Asteroids()
{
	srand(time(NULL));
	initialise();
}

void Asteroids::initialise()
{
	m_asteroidTexture.loadFromFile("ASSETS\\IMAGES\\asteroid.png");
	
	for (int asteroidIndex = 0; asteroidIndex < MAX_ASTEROIDS; asteroidIndex++)
	{
		m_asteroidSprite[asteroidIndex].setTexture(m_asteroidTexture);
		m_asteroidSprite[asteroidIndex].setScale(0.3, 0.3);
		m_asteroidSprite[asteroidIndex].setOrigin(80, 80);
		m_asteroidSprite[asteroidIndex].setPosition(200 + asteroidIndex * 40, 300);
		randDirection[asteroidIndex].x = rand() % 10 - 5, randDirection[asteroidIndex].y = rand() % 10 -5;
	}
	
}

void Asteroids::draw(sf::RenderWindow& t_window)
{
	for (int asteroidIndex = 0; asteroidIndex < MAX_ASTEROIDS; asteroidIndex++)
	{
		t_window.draw(m_asteroidSprite[asteroidIndex]);
	}
}

void Asteroids::update(sf::Time t_deltaTime)
{

}

AsteroidMovement::AsteroidMovement()
{
}

void AsteroidMovement::moveAsteroid(Asteroids &t_asteroids)
{
	for (int asteroidIndex = 0; asteroidIndex < t_asteroids.MAX_ASTEROIDS; asteroidIndex++)
	{
		t_asteroids.m_asteroidSprite[asteroidIndex].move(t_asteroids.randDirection[asteroidIndex].x,
														 t_asteroids.randDirection[asteroidIndex].y);
	}
}
