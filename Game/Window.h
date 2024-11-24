#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Bar; 
class Ball;

class Window
{
public: 
	Window(int width, int height);
	Window(int width, int height, std::string title);
	~Window(); 

	void close(); 
	void handleEvents();
	void renderWindow(Bar* player, Bar* enemy, Ball* ball);

	bool isOpen() const; 

	int getWindowsWidth() const; 
	int getWindowsHeight() const; 

	float getWindowPadding() const;

	sf::Vector2i getMousePosition();
private: 
	const int window_width; 
	const int window_height;
	
	const float padding = 10.0f;

	std::string TITLE;

	sf::RenderWindow window;
};
