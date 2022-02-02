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

public:
	//Constructor
	Player();
	void loadImages();
	void initialise();

	void draw(sf::RenderWindow& t_window);
};

