#include "Collision.h"

void Collision::playerAsteroidCollisionCheck(Player& t_player, Asteroids& t_asteroids)
{
	for (int index = 0; index < MAX_ASTEROIDS; index++)
	{
		if (t_asteroids.m_asteroidSprite[index].getGlobalBounds().intersects(t_player.getSprite().getGlobalBounds()))
		{
			t_asteroids.destroyAsteroid(index);
			t_player.reduceLives();
		}
	}
}
