#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 3.f;
	this->attackCooldownMax = 20.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

//Private functions
void Player::initTexture()
{
	//Load a texture form a file
	if (!this->texture.loadFromFile("Textures/SpaceShip.png")) {
		std::cout << "ERROR::PLAYER::INITTEXTURES::COULD NOT LOAD TEXTURE FILE!" << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(0.1f, 0.1f);

	//Start position
	this->sprite.setPosition(400 - this->sprite.getGlobalBounds().width / 2.f, 600 - this->sprite.getGlobalBounds().height / 2.f);
}

//Const - Destru
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();

}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);

}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax){
		this->attackCooldown = 0.5f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 1.f;

}

//Functions
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
