#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Creature
{
protected:
	sf::Texture texture; // tekstura robaka
	sf::Sprite sprite; //obiekt robaka z tekstur�

	sf::Clock deathTime;// zegar odlczajacy do �meirci robaka
	float maxLifeTime = 120.f; //maxymalny czas zycia

	

	/// <summary>
	/// za�adowuje teksture i tworzy sprita
	/// </summary>
	/// <param name="path"> - scie�ka do tekstury</param>
	void loadSprite(std::string path);

	void setWormPosition(int positionX, int positionY);

	void checkerFixPosition();


public:
	float eaten = 3.f; // zjedzone jedzienie do nastepnego wzrostu
	sf::RectangleShape checker; //punkt odniesienie dla robaka

	/// <summary>
	/// zwraca sprita robaka
	/// </summary>
	/// <returns>sprite robaka</returns>
	sf::Sprite* getCreature();

	/// <summary>
	/// zwraca checkera cztyli specjalny obiekt stworzony 
	/// pod robakiem do sprawdzzaania kolizji z podlog�
	/// </summary>
	/// <returns> zwraca obiekt prostok�ta 1 na 1 przeznaczony do sprawdzania</returns>
	sf::RectangleShape getChecker();
};

