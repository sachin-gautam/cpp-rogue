#pragma once


#include"player.h"
#include"enemy.h"
#include<sstream>
#include"Obstacle.h"
class Game
{
private:

	//variables
	// window
	sf::RenderWindow* window;
	sf::VideoMode VideoMode;
	sf::Event ev;


	//player 
	Player* player;
	void initPlayer();
	Enemy* satru;
	Obstacle* badha;

	 
	//Game Logic
	unsigned points;
	int health;
	sf::Font font;
	sf::Text guitext;


	float enemySpwanTimer;
	float enemySpwanTimerMax;
	int maxEnemies;
	int maxObs;

	// map
	sf::Sprite sprite;
	sf::Sprite sprite1;


	//private functions
	void initiVariables();
	void initWindow();
	void initEnemies();
	

	//Obstacle
	void initObstacle();

	//FONTS 
	void initfonts();
	void initTexts();

	 
public:
	sf::Texture tileSheetTexture;
	//constructors and dectructors
	Game();
	virtual ~Game();

	//Accessor
	const bool running() const;


	// map functions 
	void loadMap();
	void renderMap();
	void mapCollision(const sf::RenderTarget* target);

	//functions
	//void spawnEnemy();
	void pollEvent();
	void update();
	void updateObstacle();
	void render();
	void updateEnemies();
	
	// render FONTS
	void updateText();
	void renderGui(sf::RenderTarget * target);
};

