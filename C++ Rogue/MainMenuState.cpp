#include "MainMenuState.h"

void MainMenuState::initKeyBinds()
{
	std::fstream ifs("config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initKeyBinds();
	this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{

}


void MainMenuState::endState()
{
	std::cout << "Ending Game State" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

}

void MainMenuState::update(const float& dt)
{
	this->updateInput(dt);

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
}