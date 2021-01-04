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

	//zmienne
	sf::RenderWindow* window; ///okno symulacji
	sf::RenderWindow* optionWindow; /// okno opcji 
	sf::Event sfEvent; /// fsml event

	sf::View view; ///widok okna symulacji

	sf::Vector2i mouseViewPos; ///pozycja myszki na oknie opcji
	sf::Vector2i mouseSimViewPos; /// pozycja myszki w oknie symulacji

	sf::Vector2i worldSize; /// wielko�� �wiata symulacji


	Menu *menu; ///menu opcji
	World *world; /// �wiat symulacji
	variable* data; /// zmienne odzia�uj�ce na symulacje na bierz�co

	// delta time 
	sf::Clock dtClock; /// zegar delta time 
	float dt; /// deltaTime


	/// <summary>
	/// inicjalizacja obu okien
	/// </summary>
	void initWindow();


public:

	// kosntruktor / dekonstruktor
	Simulation();
	virtual ~Simulation();

	//funkcje

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

