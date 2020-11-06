#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Button
{

private:
	sf::RectangleShape button; // kaszat�t przycisku
	sf::Text text; //tekst przycisku 
	sf::Font font; // font przycisk
	int value=0; // wartosc zmiennej

	
public:
	
	Button();
	//~Button();

	/// <summary>
	/// ustawia przycisk jako przycisk dodawania
	/// </summary>
	void upButton();

	/// <summary>
	/// ustawia przycisk jako przycisk odejmowania
	/// </summary>
	void downButton();

	/// <summary>
	/// ustawia pozycje przycisku w oknie
	/// </summary>
	/// <param name="x">szeroko�� od lewej</param>
	/// <param name="y">wysokosc od g�ry</param>
	void setPosition(int x, int y);

	/// <summary>
	/// ustawia kolor t�a przycisku wed�ug schemat RGBA
	/// </summary>
	/// <param name="r">RED</param>
	/// <param name="g">GREAN</param>
	/// <param name="b">BLUE</param>
	/// <param name="a">ALPHA</param>
	void setColor(int r, int g, int b, int a);


	/// <summary>
	/// zwraca zmienna kszta�tu przycisku
	/// </summary>
	/// <returns>kszta�t prostok�ta </returns>
	sf::RectangleShape getButton();

	/// <summary>
	/// zwraca tekst przycisku
	/// </summary>
	/// <returns>tekst przycisku</returns>
	sf::Text getButtonText();

	/// <summary>
	/// ustawiwia pozycje tekstu wzgledem przycisku
	/// </summary>
	void setTextPosition();

	/// <summary>
	/// ustawia przycisk jako pole z wartosci� 
	/// </summary>
	void valueFild();

};



