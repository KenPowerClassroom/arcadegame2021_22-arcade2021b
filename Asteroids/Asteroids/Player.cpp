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
	speed = 50;
	body.setRotation(0);
	rotation = (body.getRotation() + ROTATE_OFFSET) ;
	body.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void Player::processInput()
{
}

void Player::update(double dt)
{
	double newX = body.getPosition().x + (std::cos(rotation * DEG_TO_RAD) * speed * (dt / 1000));
	double newY = body.getPosition().y + (std::sin(rotation * DEG_TO_RAD) * speed * (dt / 1000));

	body.setPosition(newX, newY);
}

void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
