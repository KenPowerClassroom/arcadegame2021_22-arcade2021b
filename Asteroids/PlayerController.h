#pragma once
#include"Globals.h"
#include<iostream>

class PlayerController
{
private:
	float playerXpos;
	float playerYpos;

	double speed;
	int rotation;
	int prevRotation;

	const int ACCELERATION = 20;
	const int MAX_SPEED = 300;
	const int ROTATE_SPEED = 5;

public:
	PlayerController();
	void initialize();

	void update(double dt);

	// Movement
	void acceleration();
	void rotateLeft();
	void rotateRight();

	// Returns
	float returnXpos();
	float returnYpos();
	int returnRotation();
	int returnSpeed();
};

