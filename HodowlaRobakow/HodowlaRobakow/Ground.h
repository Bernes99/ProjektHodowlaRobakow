#pragma once

#include <SFML/Graphics.hpp>


class Ground
{
protected:
	sf::RectangleShape ground; /// kszta�t podloza
	float maxFood=2; /// max ilosc jedzenia na podlozu
	float food=maxFood; /// obecna ilosc jedzenia na podlozu
	//float restoreSpeed = 1;
	

public:
	/// <summary>
	/// konstruktor ground ustawiajacy kolor i rozmiar 
	/// </summary>
	Ground();

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
	bool eatFood();

	/// <summary>
	/// przywraca ilosc zywnosci na podlozu
	/// </summary>
	void restoreFood();


};

