#pragma once
#include "enemy.h"
#include "Animation.h"
class Obstacle 

{

	sf::Texture obsA;
	sf::Sprite obs;
	sf::Texture obsA1;
public:
	sf::RenderTarget* window;
	Animation obsAnimation;
	std::vector<sf::Sprite> obsArray;
	std::vector<Animation> animationArray;
	sf::Clock clock;
	float deltatime;
	sf::Vector2f getPositionObs();

	Obstacle(sf::RenderTarget* window);
	~Obstacle();

	void initObs();
	void spawnObs(int);
	void render(sf::RenderTarget& window);
	void updateObs();
};

