#include "Bar.h"
Bar::Bar(bool isLeft, Window *window) : barSize(barWidth, barHeight), bar(barSize)
{
	bar.setFillColor(barColor);
	bar.setPosition(getPosition(isLeft, window));
	gameWindow = window; 
}

sf::Vector2f Bar::getPosition(bool isLeft, Window *window)
{
	if (isLeft)
	{
		return sf::Vector2f( window->getWindowPadding(), window->getWindowsHeight() / 2.0f - barHeight / 2.0f ); 
	} 
	return sf::Vector2f( window->getWindowsWidth() - window->getWindowPadding() - barWidth , window->getWindowsHeight() / 2.0f - barHeight / 2.0f );
}

sf::Vector2f Bar::getBarSize()
{
	return barSize; 
}
sf::RectangleShape& Bar::getShape()
{
	return bar;
}