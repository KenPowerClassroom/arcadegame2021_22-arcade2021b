#include "BulletPool.h"

BulletPool::BulletPool()
{

	loadImage();
	start();
}

void BulletPool::loadImage()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].setRadius(7);
		bullets[i].setOrigin(3,3);
		bullets[i].setFillColor(sf::Color::Red);
	}
}

void BulletPool::start()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].setPosition(BULLET_BAY, BULLET_BAY);
		fired[i] = false;
	}
	fireDelay = -1;
}

void BulletPool::update(int dt)
{
	fireDelay--;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (fired[i])
		{
			move(i,dt);
		}
	}
}

void BulletPool::move(int t_i, int dt)
{
	sf::Vector2f newPos = bullets[t_i].getPosition();
	newPos.x += (std::cos(rotation[t_i] * DEG_TO_RAD) * SPEED);
	newPos.y += (std::sin(rotation[t_i] * DEG_TO_RAD) * SPEED);
	bullets[t_i].setPosition(newPos);
}

void BulletPool::fire(sf::Sprite t_player)
{
	if (fireDelay < 0)
	{
		bullets[1].setPosition(t_player.getPosition());
		rotation[1] = t_player.getRotation() - ROTATE_OFFSET;
		fired[1] = true;

		fireDelay = BULLET_DELAY;
	}
}

void BulletPool::draw(sf::RenderWindow& t_window)
{
	t_window.draw(bullets[1]);
}
