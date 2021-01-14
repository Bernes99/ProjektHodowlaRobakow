#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "data.h"


class Creature
{
protected:
	/// tekstura robaka
	sf::Texture texture; 
	///obiekt robaka z tekstur�
	sf::Sprite sprite; 

	/// zegar odlczajacy do �meirci robaka
	sf::Clock deathTime;
	/// maxymalny czas zycia
	float maxLifeTime = 120.f; 


	/// <summary>
	/// za�adowuje teksture i tworzy sprita
	/// </summary>
	/// <param name="path"> - scie�ka do tekstury</param>
	void loadSprite(std::string path);

	/// <summary>
	/// ustawia pozycje stworzenia na podan�
	/// </summary>
	/// <param name="positionX"> - pozycja x </param>
	/// <param name="positionY"> - pozycja y </param>
	void setWormPosition(int positionX, int positionY);

	/// <summary>
	/// ustawia poprawion� pozycje checkera
	/// </summary>
	void checkerFixPosition();


public:
	
	///punkt odniesienie dla robaka
	sf::RectangleShape checker; 

	/// <summary>
	/// zwraca sprita robaka
	/// </summary>
	/// <returns>sprite robaka</returns>
	sf::Sprite* getCreature();

	/// <summary>
	/// zwraca checkera czyli specjalny obiekt stworzony 
	/// pod robakiem do sprawdzaania kolizji z podlog�
	/// </summary>
	/// <returns> zwraca obiekt prostok�ta 1 na 1 przeznaczony do sprawdzania</returns>
	sf::RectangleShape getChecker();
};

