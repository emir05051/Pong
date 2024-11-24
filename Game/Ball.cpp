#include "Ball.h"

Ball::Ball(float radius, Window* window) : ballRadius(radius), ball(radius)
{
	ball.setFillColor(sf::Color::Red);
	ball.setPosition(400.0f - radius, 300.0f - radius);
    gameWindow = window; 
}

void Ball::move()
{
    sf::Vector2f ballCurrentPosition = ball.getPosition();
    sf::Vector2f ballNewPosition(ballCurrentPosition.x + ballSpeedX, ballCurrentPosition.y + ballSpeedY);

    float width  = gameWindow->getWindowsWidth(); 
    float height = gameWindow->getWindowsHeight(); 

    if (ballNewPosition.x >= width  - ballRadius * 2 - 1 || ballNewPosition.x <= 0)
        ballSpeedX *= -1;
    if (ballNewPosition.y >= height - ballRadius * 2 - 1 || ballNewPosition.y <= 0)
        ballSpeedY *= -1;

    if ((ballNewPosition.x > 0 && ballNewPosition.x < width  - ballRadius * 2) &&
        (ballNewPosition.y > 0 && ballNewPosition.y < height - ballRadius * 2))
    {
        ball.setPosition(ballNewPosition.x, ballNewPosition.y);
    }
    accelerate(); 
}

sf::CircleShape& Ball::getShape()
{
    return ball;
}


void Ball::accelerate()
{
    if(ballSpeedX < maxSpeed)
        ballSpeedX *= 1 + acceleration;
    if (ballSpeedY < maxSpeed)
        ballSpeedY *= 1 + acceleration;
}

void Ball::checkCollision(Bar *object)
{
    sf::Vector2f ballPosition   = ball.getPosition(); 
    sf::Vector2f objectPosition = object->getShape().getPosition();

    bool isOnTheSameHeight = ballPosition.y >= (objectPosition.y - 10.0f) && ballPosition.y <= (objectPosition.y + object->getBarSize().y + 10.0f);
    bool isOnTheSameWidth;
    
    if (object->isLeft)
    {
        isOnTheSameWidth = ballPosition.x < objectPosition.x + object->getBarSize().x + 1.0f;
    }
    else 
    {
        isOnTheSameWidth = ballPosition.x > objectPosition.x - 1.0f;
    }

    if (isOnTheSameHeight && isOnTheSameWidth)
    {
        ballSpeedX *= -1;
        ballSpeedY *= (rand() % 2 == 0 ? -1 : 1);
    }
}
