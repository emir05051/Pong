#pragma once

#include "Bar.h"

class AI : public Bar
{
	
public:
	AI(bool isLeft, Window* window);

	void moveAI(Ball *ball); 
};

