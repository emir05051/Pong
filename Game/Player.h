#pragma once
#include <SFML/Graphics.hpp>
#include "Bar.h"
class Player : public Bar
{
public:
	Player(bool isLeft, Window* window);
	void move(); 
};

