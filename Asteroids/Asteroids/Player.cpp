#include "Player.h"

Player::Player()
{
	loadImages();
	initialise();
}

void Player::loadImages()
{
	if (!texture.loadFromFile("ASSETS/IMAGES/ship.png"))
	{
		std::cout << "error with font file file";
	}

	body.setTexture(texture);
	body.setOrigin(780, 759);
	body.setScale(0.035, 0.035);
}

void Player::initialise()
{
	body.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
