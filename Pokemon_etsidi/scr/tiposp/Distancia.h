#pragma once

#include "Pokemon.h"
#include "Ataque.h"

class Distancia :
    public Pokemon
{

public:

	//Constructor para la clase Distancia, que inicializa la clase
	Distancia() = default;

	Distancia(string n, Bando b, Tipo tipo1, Tipo tipo2, Vector2D pos_t)
	{
		// No se pueden inicializar miembros heredados en la lista de inicialización
		//Arena
		ataque = new Rango(20.0, Vector2D{ 1.0, 0.0 }, Vector2D{ 0.0, 0.0 }, 0.5, 0.5);
		vida_max = 60.0;
		vida_actual = 60.0;
		velocidad = 0.2;
		dano = 20.0;
		cooldown = 5;
		Hitbox = { 2, 2 }; // Hitbox para prueba, hay que cambiarlo

		//Tablero
		nombre = n;
		equipo = b;
		tip1 = tipo1;
		tip2 = tipo2;
		pos_tab = pos_t;
		simbolo = 'D';

	}


};

