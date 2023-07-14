#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
#include"Animation.h"
class Enemy
{
	sf::Texture enemyT;
	sf::Sprite enemy;
	sf::Texture enemyT1;
    public:
	sf::RenderTarget* window;
	Animation enemyAnimation;
	sf::Clock clock;
	float deltatime;
	std::vector<sf::Sprite> enemyArray;
	std::vector<Animation> animationArray;


	void update();
	void initEnemy();
	
	sf::Vector2f getPosition();
	void spawnEnemy(int);
	Enemy();
	Enemy(sf::RenderTarget * window);
	~Enemy();
	void render(sf::RenderTarget& window);

};

