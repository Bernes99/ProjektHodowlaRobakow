#pragma once


#include "Creature.h"
#include "Eggs.h"


class Worm : public Creature
{
private:

	/// maksymalny rozmiar jaki moze urosn�� robak
	int maxScale; 

	/// wska�nik na zmienne odzia�uj�ce na symulacje na bierz�co
	variable* data;  
	
	/// zegar odpowiedzialny za zatrzymywanie sie robak�w w miejscu
	sf::Clock timer; 
	/// jak d�ugo robak stoi w miejscu
	float howLongStay = 2.0f; 

	/// czy robak moze sie porusza�
	bool allowMove = true; 
	/// czy robak poprzednio porusza� sie w prawo
	bool isPrevRight; 
	
	///czy pozwolic na losowanie pozycji
	bool allowRandom = false; 
	/// wylosowana pozycja x do kt�rej porusza sie robak
	float xMove; 
	/// poprzedna wylosowana pozycja x
	float prevX=0; 
	/// wylosowana pozycja y do kt�rej porusza sie robak
	float yMove;
	/// poprzedna wylosowana pozycja y
	float prevY = 0;

	/// predkosc poruszania sie robaka
	float speed = 100.f;

	/// % zycie gdy robak sie nie rozmanaz
	float notMature; 

	/// czy robak przymiera g�odem
	bool hungerDie = false; 
	/// czas jaki robak przymiera glodem
	sf::Clock hungerTimer; 
	/// maksymalny czas na g�odzie 
	float maxHungerTime; 

	/// wska�nik do przekazywania vektora jajek
	std::vector <Eggs*>* eggs; 

	/// ile jajko bedzie sie wykluwa� 
	float eggIncubate; 

public:
	/// aktualnie zjedzone jedzenie
	float eaten=3.f; 
	/// zegar odpowiedzialny za czas sk�adania jaja
	sf::Clock leyEggTimer; 
	/// odstep pomi�dzy mozliwoscia kolejnego jajka
	float leyEggSpan; 


	/// <summary>
	/// poruszanie sie robaka
	/// </summary>
	/// <param name="windowSizeX">okno w kt�rym porusza sie robak(takie samo jak rysowanie)</param>
	void movment(int worldSizeX,int worldSizeY,float dt);
	
	/// <summary>
	/// konstruktor domyslny
	/// </summary>
	Worm() = default;

	/// <summary>
	/// konstruktor robaka
	/// </summary>
	/// <param name="wormPosX">startowa pozycja x robaka</param>
	/// <param name="wormPosY">startowa pozycja y robaka</param>
	Worm(int wormPosX,int wormPosY, std::vector <Eggs*>* egg, variable* data);


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
	bool wormDeath();

	/// <summary>
	/// sprawdza czy robak jest doros�y
	/// </summary>
	/// <returns> zwraca prawd� jezeli robak jest doras�y, fa�sz je�eli nie jest </returns>
	bool isMature();


	/// <summary>
	/// spawnuije jajko na pozycji robaka o ile czas od ostatniego jaja nie jest zbyt ma�y
	/// </summary>
	/// <param name="count"> - liczba robak�w z jednego jaja</param>
	void layEggs(int count);


	/// <summary>
	/// aktualizuje zmienne odzia�uj�ce na symulacje na bierz�co 
	/// </summary>
	void updateVariable();
};

