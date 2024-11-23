#include "Player.h"
Player::Player(bool isLeft, Window *window) : Bar(isLeft, window) 
{
	barColor = sf::Color::White; 
}
void Player::move()
{
    sf::Vector2i mousePosition = gameWindow->getMousePosition();

    constexpr float barMoveSpeed = 0.1f;
    sf::Vector2f playerPosition = bar.getPosition();


    if (mousePosition.y > playerPosition.y + getBarSize().y / 2.0f)
    {
        float playerNewPosition = playerPosition.y + barMoveSpeed;
        if (playerNewPosition < gameWindow->getWindowsHeight() - getBarSize().y)
            bar.setPosition(playerPosition.x, playerNewPosition);
    }
    else
    {
        float playerNewPosition = playerPosition.y - barMoveSpeed;
        if (playerNewPosition > 0)
            bar.setPosition(playerPosition.x, playerNewPosition);
    }

}