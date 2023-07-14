#include "player.h"

#include<iostream>
//private functions
void Player::initTextures()
{
	animateRow = 1;
	
	// Load a texture From File
	if(this->texture.loadFromFile("assets/textures/all.png"));
	{
		std::cout << "CPP ROUGE "<<std::endl;

	}
	this->playerAnimation = new Animation(&texture,sf::Vector2u(8,7),0.1f,false);

}

void Player::initSprites()
{

	// set the texture From File
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(150.f,150.f);
	
	//Resize the texture 
	this->sprite.setScale(1.7,1.7);

	
}

Player::Player()
{
	this->initTextures();
	this->initSprites();
}

Player::~Player()
{
}


//functions

void Player::HandelMoment()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		animateRow = 3;
		sprite.move(-2.f, 0.f);
		playerAnimation->updateUvRect(&texture);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			animateRow = 4;
			playerAnimation->updateUvRect(&texture);
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		animateRow = 2;
		sprite.move(2.f, 0.f);
		playerAnimation->updateUvRect(&texture);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			animateRow = 0;
			playerAnimation->updateUvRect(&texture);
		}
	
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		animateRow = 2;
		sprite.move(0.f, -2.f);
		playerAnimation->updateUvRect(&texture);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		animateRow = 2;
		sprite.move(0.f, 2.f);
		playerAnimation->updateUvRect(&texture);
	}
	// Attacks 

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		animateRow = 0;
		playerAnimation->updateUvRect(& texture);
	}
	
	else
	{
		playerAnimation->updateUvRect(&texture);
		animateRow = 1;
	}
	
}

void Player::update()
{
	deltaTime = clock.restart().asSeconds();
	playerAnimation->update(animateRow,deltaTime);

	this->sprite.setTextureRect(this->playerAnimation->uvRect);
	HandelMoment();


	//player coordination
	//std::cout << "player coord: " << this->sprite.getPosition().x<<" "<<this->sprite.getPosition().y<<std::endl;

	
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
