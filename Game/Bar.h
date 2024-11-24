#pragma once

#include "Window.h"

class Bar
{
public:

	Bar(bool isLeft, Window *window); 
	
	sf::RectangleShape& getShape(); 
	sf::Vector2f getBarSize();

	bool isLeft;
protected:
	sf::Color barColor; 
	sf::Vector2f barSize;
	sf::RectangleShape bar;
	
	Window *gameWindow = nullptr;

	
	bool isInWindow(sf::Vector2f position);
	void move(float x, float y);

private:
	sf::Vector2f getPosition(bool isLeft, Window* window);
};

