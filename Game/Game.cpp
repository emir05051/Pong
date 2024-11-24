#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include "AI.h"

#include <iostream>
#include <windows.h>

int main()
{
    Game::Start();
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
        player.movePlayer();
        opponent.moveAI(&ball);

        ball.move(); 
        
        ball.checkCollision(&player);
        ball.checkCollision(&opponent);

        window.handleEvents();

        window.renderWindow(&player, &opponent, &ball);
    }
}

