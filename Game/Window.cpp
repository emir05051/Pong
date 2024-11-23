#include "Window.h"

Window::Window(int width, int height)
	: window(sf::VideoMode(width, height), TITLE),
	window_width(width), window_height(width), TITLE("Pong Game")
{
}

Window::Window(int width, int height, std::string title)
	: window(sf::VideoMode(width, height), TITLE), 
	  window_width(width), window_height(width), TITLE(title)
{	
}

void Window::close()
{
	window.close();
}
void Window::handleEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case (sf::Keyboard::Escape):
				window.close();
				break;
			default:
				break;
			}
		}
	}
}
void Window::renderWindow(Player *player, AI *enemy, Ball *ball)
{
	window.clear();

	window.draw(player->getShape());
	window.draw(enemy);
	window.draw(ball->getShape());

	window.display();
}
bool Window::isOpen() const
{
	return window.isOpen();
}
int Window::getWindowsWidth() const
{
	return window_width; 
}
int Window::getWindowsHeight() const
{
	return window_height; 
}
float Window::getWindowPadding() const
{
	return padding;
}
sf::Vector2i Window::getMousePosition()
{
	return sf::Mouse::getPosition(window); 
}