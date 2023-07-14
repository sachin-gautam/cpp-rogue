#pragma once
#include"Animation.h"
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<iostream>
#include<vector>
#include<ctime>
class Player
{
private:

	
	
	sf::Texture texture;
	Animation* playerAnimation;

	sf::Clock clock;
	float deltaTime;


	//private functions
	void initTextures();
	void initSprites();



public:
	int animateRow;
	sf::Sprite sprite;

	Player();
	virtual ~Player();


	//functions 

	void HandelMoment();

	void update();
	void render(sf::RenderTarget& target);
};

