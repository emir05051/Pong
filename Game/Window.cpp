#include "Window.h"
#include "Ball.h"
#include "Bar.h"

Window::Window(int width, int height)
	: window(sf::VideoMode(width, height), TITLE, sf::Style::None),
	window_width(width), window_height(height), TITLE("Pong Game")
{
}

Window::Window(int width, int height, std::string title)
	: window(sf::VideoMode(width, height), TITLE), 
	  window_width(width), window_height(height), TITLE(title)
{	
}
Window::~Window()
{
	close();
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
void Window::renderWindow(Bar *player, Bar *enemy, Ball *ball)
{
	window.clear();

	window.draw(player->getShape());
	window.draw(enemy->getShape());
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