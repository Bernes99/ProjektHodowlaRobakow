#pragma once



#include "Creature.h"
#include "Eggs.h"


class Worm : public Creature
{
private:
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

	bool hungerDie = false; //czy robak przymiera g�odem
	sf::Clock hungerTimer; //czas jaki robak przymiera glodem
	float maxHungerTime = 3; // maksymalny czas na g�odzie 

	std::vector <Eggs*>* eggs; ///wska�nik do przekazywania vektora jajek

protected:
	
	void checkerFixPosition();
	
public:
	
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
	Worm(int wormPosX,int wormPosY, std::vector <Eggs*>* egg);

	

	

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

	
	bool isMature();

	void layEggs(int i, int count);
};

