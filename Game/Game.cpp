#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "AI.h"

#include <iostream>

int main()
{
    int width = 800; 
    int height = 600; 

    sf::RenderWindow window(sf::VideoMode(width, height), "Pong", sf::Style::None);

    const float barWidth  = 25.0f; 
    const float barHeight = 150.0f; 

    const float padding = 10;

    const float radius = 5;

    sf::RectangleShape player(sf::Vector2f(barWidth, barHeight));
    player.setFillColor(sf::Color::White);
    player.setPosition(padding, (height / 2.0f) - (barHeight / 2.0f));
    
    sf::RectangleShape enemy(sf::Vector2f(barWidth, barHeight));
    enemy.setFillColor(sf::Color::White);
    enemy.setPosition(width - barWidth - padding, (height / 2.0f) - (barHeight / 2.0f));
    
    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::Red); 
    ball.setPosition((width / 2.0f) - radius, (height / 2.0f) - radius);

    sf::RectangleShape debugShape(sf::Vector2f(50, 1));
    debugShape.setPosition(25, player.getPosition().y + barHeight / 2.0f);
    debugShape.setFillColor(sf::Color::Blue);
    
    float ballSpeedX = 0.05f;
    float ballSpeedY = 0.05f;

    while (window.isOpen())
    { 
        // player 






    }

    return 0;
}

void Game::Start()
{
    Window window(800, 600);
    Player player(true, &window);
    Ball   ball(5, &window);
    AI     opponent(false, &window);

    while (window.isOpen())
    {
        player.move();
        ball.move(); 
        window.handleEvents();

        window.renderWindow(&player, &opponent, &ball);
    }
}

