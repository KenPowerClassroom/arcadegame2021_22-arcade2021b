#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include"Globals.h"

class Player
{
private:
	// Ship body
	sf::Sprite body;
	sf::Texture texture;

	double speed;
	int rotation;
	const int ROTATE_OFFSET = -90;

	const int ACCELERATION = 4;
	const int MAX_SPEED = 100;
	const int ROTATE_SPEED = 3;

public:
	//Constructor
	Player();
	void loadImages();

	void initialise();
	void processInput();
	void update(double dt);

	// Movement
	void acceleration();
	void rotateLeft();
	void rotateRight();

	void draw(sf::RenderWindow& t_window);
};

