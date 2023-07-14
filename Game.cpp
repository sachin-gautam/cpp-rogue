#include "Game.h"
#include"player.h"
#include"Obstacle.h"
//private Functions

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initiVariables()
{
	this->window = nullptr;
	//Game Logic
	this->points = 0;
	this->health = 100;

	this->enemySpwanTimerMax = 1000.f;
	this->enemySpwanTimer = this->enemySpwanTimerMax;
	this->maxEnemies = 5;
	this->maxObs = 3;
}

void Game::initWindow()
{
	this->VideoMode.height = 720 ;
	this->VideoMode.width = 1280;

	this->window = new sf::RenderWindow(this->VideoMode, "CPP ROGUE", sf::Style::Default);
	this->window->setFramerateLimit(60);

}

void Game::initEnemies()
{
	satru = new Enemy(this->window);
}

void Game::initObstacle()
{
	badha = new Obstacle(this->window);
}

void Game::initfonts()
{
	if(! this->font.loadFromFile("assets/FFF_tusj.ttf"))
	{
		std::cout << " ERROR :FONTS NOT FOUND !" << std::endl;
	}
}

//    FONTS 
void Game::initTexts()
{
	// gui text init 
	this->guitext.setFont(this->font);
	this->guitext.setCharacterSize(35);
	this->guitext.setPosition(20, 20);
	this->guitext.setFillColor(sf::Color::Cyan);
}

Game::Game()
{
	this->initiVariables();
	this->initWindow();
	this->initEnemies();
	this->initPlayer();
	this->initObstacle();
	this->loadMap();
	//Fonts
	this->initfonts();
	this->initTexts();
}
Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->badha;
	delete this->satru;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//functions

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();

			break;
		
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->ev.key.code == sf::Keyboard::X)
			{
				for (int i = 0; i < this->satru->enemyArray.size();i++)
				{
					if (this->player->sprite.getGlobalBounds().intersects(this->satru->enemyArray[i].getGlobalBounds()))
					{
						satru->enemyArray.erase(this->satru->enemyArray.begin() + i);
						satru->animationArray.erase(this->satru->animationArray.begin() + i);
						this->points++;
						if (this->health != 0 && this->health <= 99)
							this->health++;
						else
							player->animateRow = 6;
					}
				}
			}
			break;
		}
	
	}
}

void Game::update()
{
	this->pollEvent();
	this->updateEnemies();
	this->updateObstacle();
	this->player->update();
	this->satru->update();
	this->badha->updateObs();
	this->updateText();
	
}
void Game::updateObstacle()
{
	sf::Vector2f playerPos = this->player->sprite.getPosition();
	//updating enemy timer for spwan
	if (!this->badha->obsArray.empty())
	{
		for (auto& a : this->badha->obsArray)
		{
			/*if (playerPos.x < a.getPosition().x)
			{
				//a.move(-1.f, 0.f);
			}
			else
			{
				//a.move(1.f, 0.f);
			}
			if (playerPos.y < a.getPosition().y)
			{
				//a.move(0.f, -1.f);
			}
			else
			{
				//a.move(0.f, 1.f);
			}
			*/
			if (playerPos.x == a.getPosition().x && playerPos.y == a.getPosition().y)
			{
				if (this->health == 0)
				{
					for (int i = 0;i < 1;i++)
					{
						player->animateRow = 6;
					}
					break;
				}
				else
					this->health--;
			}
		}
	}
}
void Game::render()
{
	//Renders the Game object 

	this->window->clear();
	
	//Draw game Object
	this->renderMap();
	this->mapCollision(this->window);
	this->badha->render(*this->window);
	this->satru->render(*this->window);
	this->player->render(*this->window);
	//FONTS

	this->renderGui(this->window);

	this->window->display();
}

void Game::updateEnemies()
{
	sf::Vector2f playerPos = this->player->sprite.getPosition();
	//updating enemy timer for spwan
	if (!this->satru->enemyArray.empty())
	{
		for (auto& a : this->satru->enemyArray)
		{
			if (playerPos.x < a.getPosition().x)
			{
				a.move(-1.f, 0.f);
			}
			else
			{
				a.move(1.f, 0.f);
			}
			if (playerPos.y < a.getPosition().y)
			{
				a.move(0.f, -1.f);
			}
			else
			{
				a.move(0.f, 1.f);
			}
		
			if (playerPos.x == a.getPosition().x && playerPos.y == a.getPosition().y)
			{
				if (this->health == 0)
				{
					for (int i = 0;i < 1;i++)
					{
						player->animateRow = 6;
					}
					break;
				}
				else
					this->health --;
			}
		}
	}
}

void Game::updateText()
{
	std::stringstream ss;
	ss << "HEALTH : " << this->health<<std::endl;
	ss << " KILLS : " << this->points;
	this->guitext.setString(ss.str());
	if (this->health == 0)
	{
		ss << " YOU DIED !!" << this-> health;
	}
}

//FONTS 
void Game::renderGui(sf::RenderTarget* target )
{
	target->draw(this->guitext);
}

void Game::loadMap()
{
	//map 
	this->tileSheetTexture.loadFromFile("assets/textures/level_1_dc.png");
	this->sprite.setTexture(this->tileSheetTexture);
	this->sprite.setScale(sf::Vector2f(2.f, 2.f));

	/*// obstacles
	this->obs.loadFromFile("assets/textures/coin.png");
	this->sprite1.setTexture(this->obs);
	this->sprite1.setScale(sf::Vector2f(2.f, 2.f));
	//this->obsAnimation = new Animation(&obs, sf::Vector2u(8, 7), 0.1f, false);
	*/
}

void Game::renderMap()
{
	this->window->draw(sprite);
	this->window->draw(sprite1);
}

void Game::mapCollision(const sf::RenderTarget* target)
{
	sf::FloatRect playerBounds = this->player->sprite.getGlobalBounds();
	//  LEFT 
	if (playerBounds.left < this->sprite.getGlobalBounds().left)
	{
		this->player->sprite.setPosition(this->sprite.getGlobalBounds().left , playerBounds.top);
	}
	
	//  RIGHT 
	else if (playerBounds.left + playerBounds.width > this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width)
	{
		this->player->sprite.setPosition(this->sprite.getGlobalBounds().width - playerBounds.width, playerBounds.top ) ;
	}
	else
	{

	}
	
	//  TOP 
	 if (playerBounds.top < this->sprite.getGlobalBounds().top)
	{
		this->player->sprite.setPosition(playerBounds.left, this->sprite.getGlobalBounds().top);
	}

	 // BOTTOM 
	else if (playerBounds.top + playerBounds.height +70 > this->sprite.getGlobalBounds().height + this->sprite.getGlobalBounds().top)
	{
		this->player->sprite.setPosition(playerBounds.left, this->sprite.getGlobalBounds().height - playerBounds.height-70);
	}
	else
	 {

	 }

}
