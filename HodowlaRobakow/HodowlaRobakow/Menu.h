#pragma once


#include "Button.h"


class Menu
{
private:

	/// <summary>
	/// inicjalizacja przycisk�w ca�ego menu
	/// </summary>
	void initButtons();
	
	
	Button set0[3] = {Button(),Button(),Button() }; // tablica przycisk�w pierwszego zerowej zmiennej gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania 

	/// <summary>
	/// sk�ada w sobie rysowanie tekstu oraz obszaru przycisku
	/// </summary>
	/// <param name="window">- okno na ktorym rysowane bed� przyciski</param>
	/// <param name="button">- rysowany przycisk</param>
	void drawButton(sf::RenderWindow* window, Button button);
	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisk�w 
	/// </summary>
	void initSet0();

public:
	
	Menu();
	
	/// <summary>
	/// jeszcze nwm
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - okno na ktorym rysowane bed� przyciski </param>
	void drawMenu(sf::RenderWindow* window);

};

