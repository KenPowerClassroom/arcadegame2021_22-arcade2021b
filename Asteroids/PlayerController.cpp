#include "PlayerController.h"

PlayerController::PlayerController()
{
	initialize();
}

void PlayerController::initialize()
{
	speed = 50;
	rotation = 0;

	playerXpos = SCREEN_WIDTH / 2;
	playerYpos = SCREEN_HEIGHT / 2;
}

void PlayerController::update(double dt)
{
	speed *= SPACE_RESISRANCE_I_GUESS;

	playerXpos += (std::cos(prevRotation * DEG_TO_RAD) * speed * (dt / 1000));
	playerYpos += (std::sin(prevRotation * DEG_TO_RAD) * speed * (dt / 1000));

	if (playerXpos < -10)
	{
		playerXpos = SCREEN_WIDTH;
	}
	else if (playerXpos > (SCREEN_WIDTH + 5))
	{
		playerXpos = 0;
	}
	if (playerYpos < -10)
	{
		playerYpos = SCREEN_HEIGHT;
	}
	else if (playerYpos > (SCREEN_HEIGHT + 5))
	{
		playerYpos = 0;
	}
}

void PlayerController::acceleration()
{
	speed += ACCELERATION;
	prevRotation = rotation;
	if (speed > MAX_SPEED)
	{
		speed = MAX_SPEED;
	}
}

void PlayerController::rotateLeft()
{
	rotation -= ROTATE_SPEED;
	if (rotation < 0)
	{
		rotation += 360;
	}
}

void PlayerController::rotateRight()
{
	rotation += ROTATE_SPEED;
	if (rotation > 360)
	{
		rotation -= 360;
	}
}

float PlayerController::returnXpos()
{
	return playerXpos;
}

float PlayerController::returnYpos()
{
	return playerYpos;
}

int PlayerController::returnRotation()
{
	return rotation;
}

int PlayerController::returnSpeed()
{
	return speed;
}
