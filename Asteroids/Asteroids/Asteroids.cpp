#include "Asteroids.h"



Asteroids::Asteroids()
{
	initialise();
}

void Asteroids::initialise()
{
	m_asteroidTexture.loadFromFile("ASSETS\\IMAGES\\asteroid.png");
	
	
	m_asteroidSprite.setTexture(m_asteroidTexture);
	m_asteroidSprite.setPosition(200, 200);
	m_asteroidSprite.setScale(0.3, 0.3);
}

void Asteroids::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_asteroidSprite);
}

void Asteroids::update(sf::Time t_deltaTime)
{
}
