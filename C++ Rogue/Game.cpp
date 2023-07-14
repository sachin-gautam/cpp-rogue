
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

Game:: Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Rouge C++");
	
}
void Game::init_window()
{

}
void Game::run()
{
		while (this->window->isOpen())
		{
			process_events();
			update();
			render();
		}

}

void Game::process_events()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();
	}
}
void Game::update()
{
}
void Game::render()
{
	this->window->clear();
	this->window->display();
}
