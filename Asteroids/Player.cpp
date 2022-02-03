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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotateRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotateLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		acceleration();
	}
}

void Player::update(double dt)
{
	processInput();

	speed *= SPACE_RESISRANCE_I_GUESS;

	double newX = body.getPosition().x + (std::cos(prevRotation * DEG_TO_RAD) * speed * (dt / 1000));
	double newY = body.getPosition().y + (std::sin(prevRotation * DEG_TO_RAD) * speed * (dt / 1000));

	body.setPosition(newX, newY);
}

void Player::acceleration()
{
	speed += ACCELERATION;
	prevRotation = rotation;
	if (speed > MAX_SPEED)
	{
		speed = MAX_SPEED;
	}
}

void Player::rotateLeft()
{
	rotation -= ROTATE_SPEED;
	if (rotation < 0)
	{
		rotation += 360;
	}

	body.setRotation(rotation - ROTATE_OFFSET);
}

void Player::rotateRight()
{
	rotation += ROTATE_SPEED;
	if (rotation > 360)
	{
		rotation -= 360;
	}

	body.setRotation(rotation - ROTATE_OFFSET);
}

void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(body);
}
