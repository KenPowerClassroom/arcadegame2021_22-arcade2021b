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
	controller.initialize();

	body.setRotation(controller.returnRotation() + ROTATE_OFFSET);
	body.setPosition(controller.returnXpos(), controller.returnYpos());
}

void Player::processInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		controller.rotateRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		controller.rotateLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		controller.acceleration();
	}
}

void Player::update(double dt)
{
	processInput();
	controller.update(dt);

	body.setRotation(controller.returnRotation() + ROTATE_OFFSET);
	body.setPosition(controller.returnXpos(), controller.returnYpos());
}


void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
