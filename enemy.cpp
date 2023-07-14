#include "enemy.h"
#include"player.h"
void Enemy::update()
{
	deltatime = clock.restart().asSeconds();

	if (!enemyArray.empty()) {
		if (enemyArray.size() < 3) {
			spawnEnemy(rand() % 2);
		}
		for (int i = 0; i < enemyArray.size();i++) {
			animationArray[i].update(0, deltatime);
			enemyArray[i].setTextureRect(animationArray[i].uvRect);
			//enemyArray[i].move(-2.f, 0.f);
			if (enemyArray[i].getPosition().x < 0) {
				enemyArray.erase(enemyArray.begin() + i);
				animationArray.erase(animationArray.begin() + i);
			}
		}
	}
	else {
		spawnEnemy(rand()% 2+1);
	}
}
void Enemy::spawnEnemy(int n) {
	
	switch (n)
	{
	case 1:
		enemy.setPosition(getPosition());
		enemy.setTexture(this->enemyT);
		enemyAnimation = Animation(&enemyT, sf::Vector2u(8, 1), 0.1, false);
		enemyArray.push_back(enemy);
		animationArray.push_back(enemyAnimation);
		break;
	case 2:
		enemy.setPosition(getPosition());
		enemy.setTexture(this->enemyT1);
		enemyAnimation = Animation(&enemyT1, sf::Vector2u(16, 1), 0.1, false);
		enemyArray.push_back(enemy);
		animationArray.push_back(enemyAnimation);
		break;
	default:
		break;
	}
}
Enemy::Enemy()
{
}
void Enemy::initEnemy()
{
	enemyT.loadFromFile("assets/textures/animation1.png");
	enemy.setScale(2.f, 2.f);
	enemyT1.loadFromFile("assets/textures/ghost.png");
}




sf::Vector2f Enemy::getPosition()
{
	sf::Vector2f coords;
	bool safe =false;
	
	while (!safe) {
		coords.x = rand() % this->window->getSize().x;
		coords.y = rand() % this->window->getSize().y;
		safe = true;
	}
	return coords;
}

Enemy::Enemy(sf::RenderTarget* window)
{
	this->window = window;
	this->initEnemy();
}

Enemy::~Enemy()
{
}

void Enemy::render(sf::RenderTarget& window)
{
	for (auto& a : enemyArray) {
		window.draw(a);
	}
}
