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
		bullets[i].setRadius(10);
		bullets[i].setOrigin(5, 5);
		bullets[i].setFillColor(sf::Color::Red);
	}
}

void BulletPool::start()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].setPosition(BULLET_BAY, BULLET_BAY);
	}
}

void BulletPool::fire(sf::Sprite t_player)
{
	bullets[1].setPosition(t_player.getPosition());
}

void BulletPool::draw(sf::RenderWindow& t_window)
{
	t_window.draw(bullets[1]);
}
