#pragma once
#include "Ground.h"
#include <vector>

#include "Worm.h"
#include "Eggs.h"




class World
{
	///vektor vektr�w pod�o�a
	std::vector<std::vector<Ground*>> floor; 
	/// vektor robak�w
	std::vector <Worm*> worms; 
	/// wektor jajek
	std::vector <Eggs*> eggs; 
	
	/// vektor pomocniczy kt�ry przechowuje pod�o�a na kt�rych w danej klatce stoj� robaki 
	std::vector<Ground*> whereIsWorm; 

	/// wska�nik na zmienne odzia�uj�ce na symulacje na bierz�co
	variable* data; 

	/// zegar odpowiadajacy za za obliczannie przerwy miedzy jedzeniem przez robaka
	sf::Clock eatTimer; 

	/// zegar odpowiedzialny za odnawianie sie jedzneia na powierzchni
	sf::Clock groundTimer; 
	
	/// zegar odpowiedzialny za czas skladania jaja
	sf::Clock hungerTimer; 
	/// dost�p czasu w sekundach mi�dzy spadkiem najedzenia robaka
	float hungerSpan; 

	///predkosc z jak jedz� robaki
	float eatSpeed; 

	/// szybkosc odnawiania sie podloza
	float restoreFoodTime; 

	/// <summary>
	/// inicjalizuje pod�o�e symulacji
	/// </summary>
	void floorInit();

	/// <summary>
	/// inicjuje startowe robaki w symulacji
	/// </summary>
	void wormsInit();

	/// rozmiar x planszy symulacji
	int xWorldSize; 
	/// rozmiar y planszy symulacji
	int yWorldSize; 

	/// <summary>
	/// sprawdza ktr�rego fragmentu pod�ogi dotyka robak
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka w wektorze</param>
	/// <returns> - zwraca wska�nik na obiekt Ground</returns>
	Ground* checker(int wormNumber);

	/// <summary>
	/// zwi�ksza zmienna odpowiedzialna za ilosc pozywiena jaka zjadl robak
	/// oraz wywoluje funkcje zwiekszajaca jego rozmiar(o ile zjad� wystarczajaco)
	/// </summary>
	/// <param name="wormNumber"> - indeks robaka</param>
	/// <returns> - zwraca wska�nik na obiekt robaka</returns>
	Worm* foodEaten(int wormNumber);
protected:

	/// ilosc robak�w z 1 jajka
	int countNewWorms;  

public:

	/// <summary>
	/// konstruktor ustawiaj�cy do zmiennych rozmiar �wiata i zmiene dzia�aj�ce na symulacje oraz wywo�uje inicjalizacje terenu i robak�w
	/// </summary>
	/// <param name="worldSize"> - rozmiar �wiata jako vektor </param>
	/// <param name="data"> - wska�nik na strukture z zmiennymi oddzia�uj�cymi na bie��co ns symulacje</param>
	World(sf::Vector2i worldSize, variable* data);

	/// <summary>
	/// zwalnia wzkaxniki na podloze i robaki w wektorach
	/// </summary>
	~World();


	/// <summary>
	/// aktualizuje stan swiata
	/// </summary>
	void update();

	/// <summary>
	/// rysowanie swiata
	/// </summary>
	/// <param name="window">okno na kt�rym jest rysowanie</param>
	/// <param name="dt">delta time</param>
	void drawWorld(sf::RenderWindow* window,float dt);

	/// <summary>
	/// funkcja aktualizuje zmienne odzia�uj�ce na symulacje na bierz�co
	/// </summary>
	void updateVariable();
	
	/// <summary>
	/// sprawdza czy podana pozycja myszki zawiera sie w �wiecie symulacji
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	void isClicked(sf::Vector2i mousePos);
	
};

