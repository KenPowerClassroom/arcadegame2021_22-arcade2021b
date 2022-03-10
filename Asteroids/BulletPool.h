#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"

class BulletPool
{
private:
	sf::CircleShape bullets[MAX_BULLETS];
	int rotation[MAX_BULLETS];
	bool fired[MAX_BULLETS];
	sf::Texture texture;

	int fireDelay;

	const int SPEED = 10;
	const int ROTATE_OFFSET = 90;

public:
	BulletPool();
	void loadImage();
	void start();

	void update(int dt);
	void move(int t_i, int dt);

	void fire(sf::Sprite t_player);

	void draw(sf::RenderWindow& t_window);
};

