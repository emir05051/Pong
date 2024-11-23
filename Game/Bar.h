#pragma once
#include <SFML/Graphics.hpp>	
#include "Window.h"


class Bar
{
public:
	Bar(bool isLeft, Window *window); 
	sf::RectangleShape& getShape(); 

	sf::Vector2f getBarSize();

protected:
	sf::Color barColor; 
	sf::RectangleShape bar; 
	const sf::Vector2f barSize;
	
	Window *gameWindow;

	bool isLeft;

private:
	float barWidth = 25.0f;
	float barHeight = 150.0f;

	sf::Vector2f getPosition(bool isLeft, Window* window);
};

