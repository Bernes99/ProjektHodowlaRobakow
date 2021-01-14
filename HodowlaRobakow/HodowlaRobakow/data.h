#pragma once
struct variable
{
	/*World*/

	/// ilosc robak�w z 1 jajka 
	float countNewWorms = 2.f; 
	/// szybkosc odnawiania sie podloza
	float restoreFoodTime = 10.0f;
	/// co jaki czas spada najedzenie
	float hungerSpan = 2.f;  
	/// predkosc z jak jedz� robaki
	float eatSpeed = 1.f; 

	/*Worm*/

	/// maksymalny rozmiar jaki moze urosn�� robak
	float maxScale = 2.f; 
	/// % zycie gdy robak sie nie rozmanaz
	float notMature = 0.1f; 
	/// maksymalny czas na g�odzie 
	float maxHungerTime = 1.f; 
	///ile jajko bedzie sie wykluwa� 
	float eggIncubate = 10.f; 
	/// odstep pomi�dzy mozliwoscia kolejnego jajka
	float leyEggSpan = 3.f; 
	///maxymalny czas zycia
	float maxLifeTime = 120.f; 
	

	/*Ground*/

	/// max ilosc jedzenia na podlozu
	float maxFood = 100.f; 


	
};