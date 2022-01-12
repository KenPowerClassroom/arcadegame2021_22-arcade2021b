#include "Asteroids.h"



Asteroids::Asteroids()
{
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
		m_asteroidSprite[asteroidIndex].setPosition(40 + asteroidIndex * 40, 40);
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
