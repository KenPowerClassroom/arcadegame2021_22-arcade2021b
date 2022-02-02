#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Globals.h" 
#include"Asteroids.h"

class Game
{
	sf::RenderWindow window;

public:
	sf::Font m_font;
	sf::Text m_message;

	Asteroids asteroid;
	AsteroidMovement asteroidMovement;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
public:	
	Game();
	void	loadContent();
	void	run();
	void	update(sf::Time t_deltaTime);
	void	draw();
};