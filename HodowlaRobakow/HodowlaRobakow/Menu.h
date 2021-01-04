#pragma once

#include "Button.h"
#include <vector>
#include "data.h"

class Menu
{
private:
	variable* data; /// wska�nik na zmienne odzia�uj�ce na symulacje na bierz�co 

	/// <summary>
	/// inicjalizacja przycisk�w ca�ego menu
	/// </summary>
	void initButtons();

	/// <summary>
	/// inicjalizacja przycisk�w nemy pierwszego okna s�u��cego do ustalenia rozmiaru �wiata symulacji
	/// </summary>
	void initWorldSizeButtons();
	
	int setsNumber = 11; /// liczba zestaw�w przycisk�w do zmiennych
	std::vector<std::vector<Button*>> sets;/// tablica przycisk�w zestaw�w przycisk�w gdzie indeks 0 to zmienna ,1 to przycisk zwiekszania, 2 przycisk zmniejszania, 3 teks kt�ry m�wi co to za zmienna
	Button *send; /// przycisk potwierdzenia wielko�ci �wiata w pierwszym oknie symulacji
	
	/// <summary>
	/// funkcaj inicjuje set 0 zmiennej przycisk�w 
	/// </summary>
	void initSet();

	/// <summary>
	/// inicjalizacja warto�ci domy�lnych przycisk�w
	/// </summary>
	void initValues(int i);

public:

	
	/// <summary>
	/// konstruktor do tworzenia menu w�a�ciwego
	/// </summary>
	Menu(variable* pData);

	/// <summary>
	/// konstruktor do tworzenia menu w pierwszym oknie
	/// </summary>
	Menu(variable* pData,bool worldSize);
	
	/// <summary>
	/// aktualizuje warto�ci zmiennych w strukturze data gdzie przechowywane s� aktualne warto�ci ustawionych zmiennych
	/// </summary>
	void update();

	/// <summary>
	/// funkcja rysuje przyciski na podanym oknie
	/// </summary>
	/// <param name="window"> - wska�nik na okno na ktorym rysowane bed� przyciski </param>
	void drawMenu(sf::RenderWindow* window);


	/// <summary>
	/// funkca rysuje przyciski pocz�tkowe na podanym oknie
	/// </summary>
	/// <param name="window"> - wska�nik na okno na ktorym rysowane bed� przyciski </param>
	void drawWorldSizeMenu(sf::RenderWindow* window);

	/// <summary>
	/// funkcja sprawdza czy zosta� klikni�ty przycisk do zmiany warto�ci
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	void isClicked(sf::Vector2i mousePos);

	/// <summary>
	/// funkcja sprawdza czy zosta� klikni�ty przycisk na menu pocz�tkowym
	/// </summary>
	/// <param name="mousePos"> - pozycja myszki na oknie </param>
	/// <param name="worldSize"> - wska�nik na sfml Vektor int�w przechowuj�cy rozmiar ustawionego �wiata </param>
	bool isClickedWorldSize(sf::Vector2i mousePos, sf::Vector2i *worldSize);

	
};

