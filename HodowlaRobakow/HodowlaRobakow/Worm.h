#pragma once

#include <iostream>


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



class Worm
{
private:
	sf::Texture texture; // tekstura robaka
	sf::Sprite sprite; //obiekt robaka z tekstur�
	//sf::RectangleShape checker;//obiekt porzebny do sprawdzania kolizji z pod�og�
	
	int maxScale=2; // maksymalny rozmiar jaki moze urosn�� robak
	
	sf::Clock timer; // zegar odpowiedzialny za zatrzymywanie sie robak�w w miejscu
	float howLongStay = 2.0f; // jak d�ugo robak stoi w miejscu

	bool allowMove = true; // czy robak moze sie porusza�
	bool isPrevRight; ///czy robak poprzednio porusza� sie w prawo
	//sf::Time elapseTime;
	
	bool allowRandom = false; //czy pozwolic na losowanie pozycji
	float xMove; // wylosowana pozycja x do kt�rej porusza sie robak
	float prevX=0; // poprzedna wylosowana pozycja x
	float yMove; // wylosowana pozycja y do kt�rej porusza sie robak
	float prevY = 0;// poprzedna wylosowana pozycja y

	float speed = 100.f;/// predkosc poruszania sie robaka

protected:
	sf::Clock deathTime;// zegar odlczajacy do �meirci robaka
	float maxLifeTime = 120.f; //maxymalny czas zycia

	/// <summary>
	/// za�adowuje teksture i tworzy sprita
	/// </summary>
	/// <param name="path"> - scie�ka do tekstury</param>
	void loadSprite(std::string path);

	void checkerFixPosition();

	void setWormPosition(int positionX, int positionY);
public:
	int eaten = 3; // zjedzone jedzienie do nastepnego wzrostu
	sf::RectangleShape checker; //punkt odniesienie dla robaka
	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w kt�rym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int worldSizeX,int worldSizeY,float dt);
	
	
	Worm() = default;

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

	/// <summary>
	/// sprawdza ile czy robak nie przekroczy� swojej max dlugosci zycia
	/// jezeli zosta�o robakowi malo czasu zmienia jego kolor
	/// </summary>
	/// <returns> zwraca prawde jezeli robak przekroczy� max d�ugo�� zycia</returns>
	virtual bool wormDeath();

	
	bool isMature();
};

