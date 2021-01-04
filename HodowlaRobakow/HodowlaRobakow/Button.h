#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Button : public sf::Drawable
{

private:
	sf::RectangleShape button; /// kaszat�t przycisku
	sf::Text text; /// tekst przycisku 
	sf::Font font; /// font przycisk
	float value=0; /// wartosc zmiennej

	
public:
	
	/// <summary>
	/// konstruktor �aduj�cy fonta
	/// </summary>
	Button();
	//~Button();

	/// <summary>
	/// ustawia przycisk jako przycisk dodawania
	/// </summary>
	void upButton();

	/// <summary>
	/// ustawia przycisk jako przycisk odejmowania
	/// </summary>
	void downButton();

	/// <summary>
	/// ustawia pozycje przycisku w oknie
	/// </summary>
	/// <param name="x">szeroko�� od lewej</param>
	/// <param name="y">wysokosc od g�ry</param>
	void setPosition(int x, int y);

	/// <summary>
	/// ustawia kolor t�a przycisku wed�ug schemat RGBA
	/// </summary>
	/// <param name="r">RED</param>
	/// <param name="g">GREAN</param>
	/// <param name="b">BLUE</param>
	/// <param name="a">ALPHA</param>
	void setColor(int r, int g, int b, int a);


	/// <summary>
	/// zwraca zmienna kszta�tu przycisku
	/// </summary>
	/// <returns>kszta�t prostok�ta </returns>
	sf::RectangleShape getButton();

	/// <summary>
	/// zwraca tekst przycisku
	/// </summary>
	/// <returns>tekst przycisku</returns>
	sf::Text getButtonText();

	/// <summary>
	/// ustawiwia pozycje tekstu wzgledem przycisku
	/// </summary>
	void setTextFixPosition();

	/// <summary>
	/// ustawia przycisk jako pole z wartosci� 
	/// </summary>
	void valueFild();

	/// <summary>
	/// metoda wirtualna pozwalajaca rysowa� przycisk bezpo�rednio jako obiekt klasy
	/// </summary>
	/// <param name="target"></param>
	/// <param name="states"></param>
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(button, states);
		target.draw(text, states);
	}

	/// <summary>
	/// ustawia podany tekst oraz domyslny kolor oraz wielko�� czcionki
	/// </summary>
	/// <param name="text"> - tekst jaki ma si� wy�wietla� </param>
	void nameFild(sf::String text);

	/// <summary>
	/// ustawia pozycje pola nazwy na ekranie
	/// </summary>
	/// <param name="x"> - pozycja x </param>
	/// <param name="y"> - pozycja y </param>
	void setNamePosition(int x, int y);

	/// <summary>
	/// zmienia warto�� zmiennej o podan� warto�� o ile nie przekracza podanych granic warto�ci
	/// </summary>
	/// <param name="i"> - o ile zmieni� warto��</param>
	/// <param name="downLimit"> - dolny milit warto�ci zmiennej </param>
	/// <param name="upLimit"> - g�rna granica warto�ci zmiennej </param>
	void increasValue(float i, float downLimit, float upLimit);

	/// <summary>
	/// ustawia warto�� zniennej na podan�
	/// </summary>
	/// <param name="i"> - warto�� na jak� ma byc zmieniona varto�� zmiennej</param>
	void setValue(float i);

	/// <summary>
	/// zwraca warto�� zmiennej na przycisku
	/// </summary>
	/// <returns> - warto�� zmiennej na przycisku</returns>
	float getValue();


	/// <summary>
	/// ustawia precyzje wy�wiatlania warto�ci i zwraca go jako string
	/// </summary>
	/// <param name="num"> - liczba jaka trzeba zaokr�gli� </param>
	/// <param name="precision"> do ilu liczb po przecinku chcesz zaokr�gli� </param>
	/// <returns> - zaokr�glony napis</returns>
	std::string precision(float num, int precision);


	/// <summary>
	/// ustawia rozmiar przycisku na podany rozmiar
	/// </summary>
	/// <param name="x"> - szeroko�� </param>
	/// <param name="y"> - wysoko�� </param>
	void setSize(float x, float y);
};



