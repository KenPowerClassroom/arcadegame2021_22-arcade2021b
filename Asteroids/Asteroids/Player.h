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

public:
	//Constructor
	Player();
	void loadImages();

	void initialise();
	void processInput();
	void update(double dt);

	void draw(sf::RenderWindow& t_window);
};

