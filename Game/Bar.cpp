#include "Bar.h"
Bar::Bar(bool isLeft, Window *window) 
	: barSize(25.0f, 150.0f), 
	  bar(sf::Vector2f(25.0f, 150.0f)),
	  gameWindow(window), 
	  isLeft(isLeft)
{
	
	bar.setPosition(getPosition(isLeft, window));
	
}

bool Bar::isInWindow(sf::Vector2f position)
{
	return 
		(position.y < gameWindow->getWindowsHeight() - getBarSize().y) && (position.y > 0) && 
		(position.x < gameWindow->getWindowsWidth()  - getBarSize().x) && (position.x > 0);
}

void Bar::move(float x, float y)
{
	sf::Vector2f playerNewPosition = sf::Vector2f(x, y);
	if (isInWindow(playerNewPosition))
		bar.setPosition(playerNewPosition.x, playerNewPosition.y);
}

sf::Vector2f Bar::getPosition(bool isLeft, Window *window)
{
	if (isLeft)
	{
		return sf::Vector2f( window->getWindowPadding(), window->getWindowsHeight() / 2.0f - barSize.y / 2.0f ); 
	} 
	return sf::Vector2f( window->getWindowsWidth() - window->getWindowPadding() - barSize.x , window->getWindowsHeight() / 2.0f - barSize.y / 2.0f );
}

sf::Vector2f Bar::getBarSize() 
{
	return barSize; 
}
sf::RectangleShape& Bar::getShape()
{
	return bar;
}