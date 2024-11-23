#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Bar.h"

class Ball
{
public: 
	Ball(float radius, Window *window); 

	void checkCollision(Bar *object);
	void move(); 

	sf::CircleShape &getShape(); 
private:
	float ballSpeedX = 0.05f;
	float ballSpeedY = 0.05f;
	float acceleration = 0.00001f; 
	float ballRadius; 

	sf::CircleShape ball; 
	Window *gameWindow; 

	void accelerate(); 
};
