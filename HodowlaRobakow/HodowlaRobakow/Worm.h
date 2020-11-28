#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>


class Worm
{
private:
	sf::Texture texture; // tekstura robaka
	sf::Sprite sprite; //obiekt robaka z tekstur�
	//sf::RectangleShape checker;//obiekt porzebny do sprawdzania kolizji z pod�og�
	int maxScale=10; // maksymalny rozmiar jaki moze urosn�� robak

	sf::Clock timer;
	bool allowMove = true;
	//sf::Time elapseTime;
	
	/// <summary>
	/// za�adowuje teksture i tworzy sprita
	/// </summary>
	void loadSprite(); 

	bool allowRandom = false; //czy pozwolic na losowanie pozycji
	int xMove; // wylosowana pozycja x do kt�rej porusza sie robak

public:
	int eaten = 0; // zjedzone jedzienie do nastepnego wzrostu
	sf::RectangleShape checker;
	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w kt�rym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int windowSizeX);

	/// <summary>
	/// konstruktor robaka
	/// </summary>
	/// <param name="wormPosX">startowa pozycja x robaka</param>
	/// <param name="wormPosY">startowa pozycja y robaka</param>
	Worm(int wormPosX,int wormPosY);
	
	/// <summary>
	/// zwraca sprita robaka
	/// </summary>
	/// <returns>sprite robaka</returns>
	sf::Sprite getWorm();

	/// <summary>
	/// zwraca checkera cztyli specjalny obiekt stworzony 
	/// pod robakiem do sprawdzzaania kolizji z podlog�
	/// </summary>
	/// <returns> zwraca obiekt prostok�ta 1 na 1 przeznaczony do sprawdzania</returns>
	sf::RectangleShape getChecker();

	/// <summary>
	/// sprawdza czy robak zjad� dostatecznie duzo jedzenia
	/// a jesli tak to zwieksza jego rozmiar
	/// </summary>
	void reScale();

	/// <summary>
	/// ustawia maksymaln� skale do jakiej moze urosn�� robak
	/// </summary>
	/// <param name="maxScale"> - max skala robaka (liczba ca�kowita)</param>
	void setMaxScale(int maxScale);
};

