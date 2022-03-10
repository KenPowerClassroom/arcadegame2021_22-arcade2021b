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

	if (newPos.x < 0 || newPos.y < 0 || newPos.x>SCREEN_WIDTH || newPos.y>SCREEN_HEIGHT)
	{
		bullets[t_i].setPosition(BULLET_BAY, BULLET_BAY);
		fired[t_i] = false;
	}
	else
	{
		bullets[t_i].setPosition(newPos);
	}
}

bool BulletPool::fire(sf::Sprite t_player)
{
	if (fireDelay < 0)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!fired[i])
			{
				bullets[i].setPosition(t_player.getPosition());
				rotation[i] = t_player.getRotation() - ROTATE_OFFSET;
				fired[i] = true;

				fireDelay = BULLET_DELAY;
				return true;
			}
		}
	}
	return false;
}

void BulletPool::draw(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (fired[i])
		{
			t_window.draw(bullets[i]);
		}
	}
}
