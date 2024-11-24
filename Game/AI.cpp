#include "AI.h"
#include "Ball.h"
AI::AI(bool isLeft, Window* window) : Bar(isLeft, window)
{
	barColor = sf::Color::Red;
	bar.setFillColor(barColor);
}

void AI::moveAI(Ball* ball)
{
	constexpr float aiSpeed = 0.05f; 
	
	sf::Vector2f aiPosition = bar.getPosition(); 
	bool isBallAbove = ball->getShape().getPosition().y > aiPosition.y;

	move(aiPosition.x, aiPosition.y + (isBallAbove ? aiSpeed : -aiSpeed));
}