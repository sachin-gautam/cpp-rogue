#include "Obstacle.h"

void Obstacle::updateObs()
{
	deltatime = clock.restart().asSeconds();

	if (!obsArray.empty()) {
		if (obsArray.size() < 3) {
			spawnObs(rand() % 2);
		}
		for (int i = 0; i < obsArray.size();i++) {
			animationArray[i].update(0, deltatime);
			obsArray[i].setTextureRect(animationArray[i].uvRect);
			//enemyArray[i].move(-2.f, 0.f);
			if (obsArray[i].getPosition().x < 0) {
				obsArray.erase(obsArray.begin() + i);
				animationArray.erase(animationArray.begin() + i);
			}
		}
	}
	else {
		spawnObs(rand() % 2+1);
	}
}


void Obstacle::initObs()
{
	obsA.loadFromFile("assets/textures/coin.png");
	obs.setScale(2.f, 2.f);
	//std::cout << "ERROR :: OBSTACLE not found" << std::endl;

	obsA1.loadFromFile("assets/textures/coin.png");
}

void Obstacle::spawnObs(int m)
{

	switch (m)
	{
	case 1:
		obs.setPosition(getPositionObs());
		obs.setTexture(this->obsA);
		obsAnimation = Animation(&obsA, sf::Vector2u(10, 1), 0.1, false);
		obsArray.push_back(obs);
		animationArray.push_back(obsAnimation);
		break;
	case 2:
		obs.setTexture(this->obsA1);
		obsAnimation = Animation(&obsA1, sf::Vector2u(10, 1), 0.1, false);
		obsArray.push_back(obs);
		animationArray.push_back(obsAnimation);
		break;
	default:
		break;
	}

}


sf::Vector2f Obstacle::getPositionObs()
{
	sf::Vector2f coords;
	bool safe = false;

	while (!safe) {
		coords.x = rand() % this->window->getSize().x;
		coords.y = rand() % this->window->getSize().y;
		safe = true;
	}
	return coords;
}

Obstacle::Obstacle(sf::RenderTarget* window)
{
	this->window = window;
	this->initObs();
}

Obstacle::~Obstacle()
{
}

void Obstacle::render(sf::RenderTarget& window)
{
	for (auto& o : obsArray) {
		window.draw(o);
	}
}
