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
	sf::Clock respawnTimer;
	sf::Clock invincibilityTimer;

	PlayerController controller;

	const int ROTATE_OFFSET = 90;
	int lives = 3;
	bool dead = false;
	bool invincible = false; // for invincibility frames after reviving

public:
	//Constructor
	Player();
	void loadImages();
	sf::Sprite getSprite();
	void killPlayer();
	void respawn();
	int getLives();
	bool getLiving();
	bool getInvincible();

	// Basics
	void initialise();
	void processInput();
	void update(double dt);

	void draw(sf::RenderWindow& t_window);
};

