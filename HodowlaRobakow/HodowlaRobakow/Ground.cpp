#include "Ground.h"

Ground::Ground()
{
	ground.setSize(sf::Vector2f(64.0f, 20.f));
	ground.setOutlineThickness(1.f);
	ground.setOutlineColor(sf::Color(0, 102, 0, 255));
	ground.setFillColor(sf::Color::Green);
}

void Ground::setPosition(int x, int y)
{
	ground.setPosition(sf::Vector2f(x, y));
}

sf::RectangleShape Ground::getGround()
{
	return ground;
}

void Ground::eatFood()
{
	if (food>0)
	{
		food--;
	}
	
	if (food/maxFood < 0.25f)
	{
		ground.setFillColor(sf::Color::Red);
	}
	else if (food / maxFood < 0.50f)
	{
		ground.setFillColor(sf::Color(255, 127, 80));
	}
	else if (food / maxFood < 0.75f)
	{
		ground.setFillColor(sf::Color::Yellow);
	}
}

void Ground::restoreFood()
{
	if (food < maxFood)
	{
		food++;
	}

	if (food / maxFood >= 0.75f)
	{
		ground.setFillColor(sf::Color::Green);
		
	}
	else if (food / maxFood >= 0.50f)
	{
		ground.setFillColor(sf::Color::Yellow);
	}
	else if (food / maxFood >= 0.25f)
	{
		ground.setFillColor(sf::Color(255, 127, 80));
	}
}
