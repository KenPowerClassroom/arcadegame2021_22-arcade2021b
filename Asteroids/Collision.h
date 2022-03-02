#pragma once
#include "Player.h"
#include "Asteroids.h"
#include "Globals.h"
class Collision
{
public:
	void playerAsteroidCollisionCheck(Player& t_player, Asteroids& t_asteroids);
};

