#pragma once

#include <SFML/Graphics.hpp>
#include "data.h"

class Ground
{
protected:
	/// kszta�t podloza
	sf::RectangleShape ground; 
	/// max ilosc jedzenia na podlozu
	float maxFood=100; 
	/// obecna ilosc jedzenia na podlozu
	float food=maxFood; 
	
	/// wska�nik na zmienne odzia�uj�ce na symulacje na bierz�co
	variable *data; 

public:
	/// <summary>
	/// konstruktor ground ustawiajacy kolor i rozmiar 
	/// </summary>
	Ground(variable* data);

	/// <summary>
	/// ustawia pozycje pojedynczego pod�oza
	/// </summary>
	/// <param name="x"> - wspolrzedne x </param>
	/// <param name="y"> - wspolrzedne y </param>
	void setPosition(int x, int y);

	/// <summary>
	/// zwraca kszta�t pod�oza
	/// </summary>
	/// <returns> - rysowalny prostokat </returns>
	sf::RectangleShape getGround();

	/// <summary>
	/// odejmuje ilo�� zywanosci na podlozu
	/// </summary>
	/// <returns> zwraca prawde jesli jest jedzenie</returns>
	bool eatFood(int wormFood);

	/// <summary>
	/// przywraca ilosc zywnosci na podlozu
	/// </summary>
	void restoreFood();

	/// <summary>
	/// aktualizuje zmienne odzia�uj�ce na symulacje na bierz�co
	/// </summary>
	void updateValues();
};

