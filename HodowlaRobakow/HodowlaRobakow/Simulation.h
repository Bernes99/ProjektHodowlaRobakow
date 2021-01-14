#pragma once

#include "Menu.h"
#include "World.h"
#define SIM_WINDOW_X 1024
#define SIM_WINDOW_Y 768
#define MENU_WINDOW_X 450
#define MENU_WINDOW_Y 600
#define SIZE_WINDOW_X 300
#define SIZE_WINDOW_Y 300

class Simulation
{
private:

	
	///okno symulacji
	sf::RenderWindow* window; 
	/// okno opcji 
	sf::RenderWindow* optionWindow; 
	/// fsml event
	sf::Event sfEvent; 

	///widok okna symulacji
	sf::View view; 
	///pozycja myszki na oknie opcji
	sf::Vector2i mouseViewPos; 
	/// pozycja myszki w oknie symulacji
	sf::Vector2i mouseSimViewPos; 

	/// wielko�� �wiata symulacji
	sf::Vector2i worldSize;

	///menu opcji
	Menu *menu; 
	/// �wiat symulacji
	World *world; 
	/// zmienne odzia�uj�ce na symulacje na bierz�co
	variable* data; 

	/// zegar delta time 
	sf::Clock dtClock; 
	/// deltaTime
	float dt; 


	/// <summary>
	/// tworz�cy okna �wiata i opcji, �aduje tez ikone, zmienne zmieniane z menu opcji oraz ustawia widok wy�wietlanej planszy
	/// </summary>
	void initWindow();


public:

	/// <summary>
	/// wywo�uje metode do inicjalizacji okien i �wiata
	/// </summary>
	Simulation();

	/// <summary>
	/// zwalnia wska�niki na oba okna symulacji oraz usuwa menu i zmienne zmieniane z tego menu
	/// </summary>
	virtual ~Simulation();

	

	/// <summary>
	/// aktualizowanie zdazen obsblugujacych grafike
	/// </summary>
	void updateSFMLEvents();

	/// <summary>
	/// uruchamianie programu
	/// </summary>
	void run();

	/// <summary>
	/// aktualizowanie ekranu
	/// </summary>
	void update();

	/// <summary>
	/// weswietlanie ekranu
	/// </summary>
	void render();

	/// <summary>
	/// aktualizuje zmienna dt o czas jaki jest potrzebny do wygenerowania klatki
	/// </summary>
	void updateDt();

	/// <summary>
	/// inicjowanie poierwszego okna symylacji do wyboru rozmiaru �wiata
	/// </summary>
	void worldSizeWindow();

};

