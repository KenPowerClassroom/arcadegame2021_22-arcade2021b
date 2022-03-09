#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"

class BulletPool
{
private:
	sf::CircleShape bullets[MAX_BULLETS];
	sf::Texture texture;

public:
	BulletPool();
	void loadImage();
	void start();

	void fire(sf::Sprite t_player);

	void draw(sf::RenderWindow& t_window);
};

