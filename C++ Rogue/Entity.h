#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include<iostream>
#include<ctime>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float& dt,const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};




#endif
