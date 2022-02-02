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
		randScale = rand() % 3;
		m_asteroidSprite[asteroidIndex].setScale(0.15 * randScale, 0.15 * randScale);
		m_asteroidSprite[asteroidIndex].setOrigin(80, 80);
		m_asteroidSprite[asteroidIndex].setPosition(-20, -20);

		randDirection[asteroidIndex].x = rand() % 10 - 5, randDirection[asteroidIndex].y = rand() % 10 -5;
		if (randDirection[asteroidIndex].x == 0)
		{
			randDirection[asteroidIndex].x = 1;
		}
		if (randDirection[asteroidIndex].y == 0)
		{
			randDirection[asteroidIndex].y = 1;
		}
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


//
// --------------------------------------------------------------------------------
//


AsteroidMovement::AsteroidMovement()
{

}

void AsteroidMovement::update(sf::Time t_deltaTime)
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

void AsteroidMovement::loopAsteroid(Asteroids& t_asteroids)
{
	for (int asteroidIndex = 0; asteroidIndex < t_asteroids.MAX_ASTEROIDS; asteroidIndex++)
	{
		// UP
		if (t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().y < - BOUNDRY - t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().height) // 250, 0
		{
			t_asteroids.m_asteroidSprite[asteroidIndex].setPosition(t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().x,
				SCREEN_HEIGHT + t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().height);
		}
		// DOWN
		if (t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().y > SCREEN_WIDTH + t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().height) // 250, 0
		{
			t_asteroids.m_asteroidSprite[asteroidIndex].setPosition(t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().x,
				0 - t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().height);
		}
		// RIGHT
		if (t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().x > SCREEN_WIDTH + BOUNDRY + t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().width) // 250, 0
		{
			t_asteroids.m_asteroidSprite[asteroidIndex].setPosition(0 - t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().width,
				t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().y);
		}
		// LEFT
		if (t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().x < -BOUNDRY - t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().width) // 250, 0
		{
			t_asteroids.m_asteroidSprite[asteroidIndex].setPosition(SCREEN_WIDTH + t_asteroids.m_asteroidSprite[asteroidIndex].getGlobalBounds().width,
				t_asteroids.m_asteroidSprite[asteroidIndex].getPosition().y);
		}
	}
}




