#include "Player.h"
#include <iostream>
Player::Player(bool isLeft, Window *window) : Bar(isLeft, window) 
{
	barColor = sf::Color::White; 
    bar.setFillColor(barColor);
}
void Player::movePlayer()
{
    sf::Vector2i mousePosition = gameWindow->getMousePosition();
    constexpr float barMoveSpeed = 0.1f;
    sf::Vector2f playerPosition = bar.getPosition();

    if (mousePosition.y > playerPosition.y + getBarSize().y / 2.0f)
    {
        move(playerPosition.x, playerPosition.y + barMoveSpeed);
    }
    else
    {
        move(playerPosition.x, playerPosition.y - barMoveSpeed); 
    }

}