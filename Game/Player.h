#pragma once

#include "Bar.h"

class Player : public Bar
{
public:
	Player(bool isLeft, Window* window);
	void movePlayer(); 
};

