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
	int prevRotation;
	const int ROTATE_OFFSET = -90;

	const int ACCELERATION = 20;
	const int MAX_SPEED = 300;
	const int ROTATE_SPEED = 5;

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

