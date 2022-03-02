#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"
#include"PlayerController.h"

class Player
{
private:
	// Ship body
	sf::Sprite body;
	sf::Texture texture;
	sf::Sprite livesSprites[MAX_LIVES];

	PlayerController controller;

	const int ROTATE_OFFSET = 90;
	int lives = 3;

public:
	//Constructor
	Player();
	void loadImages();
	sf::Sprite getSprite();
	void reduceLives();
	int getLives();

	// Basics
	void initialise();
	void processInput();
	void update(double dt);

	void draw(sf::RenderWindow& t_window);
};

