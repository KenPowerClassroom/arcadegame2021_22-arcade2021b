#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Globals.h" 

#include"Player.h"
#include"BulletPool.h"

#include"Asteroids.h"
#include "Collision.h"

class Game
{
	sf::RenderWindow window;

public:
	sf::Font m_font;
	sf::Text m_message;

	Player player;
	BulletPool bulletPool;

	Asteroids asteroid;
	AsteroidMovement asteroidMovement;
	Collision collision;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
public:	
	Game();
	void	loadContent();
	void	run();
	void	update(sf::Time t_deltaTime);
	void	draw();
};